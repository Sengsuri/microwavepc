#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "hardware/pio.h"
#include "hardware/spi.h"
#include "hardware/flash.h"
#include "bsp/board.h"
#include "tusb.h"

//TODO: set these pins
#define DISPLAY_1 1 //cs pins for the spi displays
#define DISPLAY_2 2
#define DC 3 //data command pin for spi. only need one

enum usbMode
{
    NONE = -1,
    STARTSAVING,
    TIME,
    GETSETTINGS,
    KEYPAD,
    RGBCOLOR,
    RGBEFFECT,
    KEYBOARD
};

enum usbMode _usbMode = NONE;

Display display1;
Display display2;

//keypad settings/actions will be stored in a map

//second core
void Core1()
{
    //this core will handle the keypad inputs and display

    bool pause = false;

    //------init display stuff-------------
    gpio_init(25);
    gpio_init(DC);

    gpio_set_dir(DC, GPIO_OUT);
    gpio_set_dir(25, GPIO_OUT);

    spi_init(spi0, 6666666);

    gpio_set_function(PICO_DEFAULT_SPI_RX_PIN, GPIO_FUNC_SPI);
    gpio_set_function(PICO_DEFAULT_SPI_SCK_PIN, GPIO_FUNC_SPI);
    gpio_set_function(PICO_DEFAULT_SPI_TX_PIN, GPIO_FUNC_SPI);

    display1 = Display(DISPLAY_1);
    display2 = Display(DISPLAY_2);

    display1.Init();
    display2.Init();
    //---------------------------------------------------

    while (1)
    {
        while (!pause)
        {

            //the pause flag
            if (multicore_fifo_rvalid)
            {
                pause = multicore_fifo_pop_blocking();
            }
        }
        pause = multicore_fifo_pop_blocking(); //blocks the code until there is data in the fifo, after that it does the main loop
    }
}

//main core
int main(void)
{
    //this core will handle the rgb, USB input/output and flash I/O
    stdio_init_all();

    multicore_launch_core1(Core1); //launches the first core

    board_init();
    tusb_init();

    while (1)
    {
        tud_task();
    }
}

//invoked when data recieved
void tud_hid_set_report_cb(uint8_t itf, uint8_t report_id, hid_report_type_t report_type, uint8_t const *buffer, uint16_t bufsize)
{
    tud_hid_report(0, buffer, bufsize); //the pico echos the report to tell the host that it received the data
    char buf = (char)buffer;

    switch (buf)
    {
    case 0x01: //startsaving
        _usbMode = STARTSAVING;
        break;
    case 0x02: //stopsaving
        _usbMode = NONE;
        break;
    case 0x03: //time data
        _usbMode = TIME;
        break;
    case 0x04: //get settings from ram, which is from flash
        _usbMode = GETSETTINGS;
        break;
    case 0x05: //the keyboard data
        _usbMode = KEYBOARD;
        break;
    case 0x06:
        _usbMode = KEYPAD;
    case 0x07:
        _usbMode = RGBCOLOR;
        break;
    case 0x08:
        _usbMode = RGBEFFECT;
        break;
    default: //if it goes here then it is some sort of data
        UsbDataHandler(_usbMode, buffer, bufsize);
        break;
    }
}

//handles raw usb data
void UsbDataHandler(usbMode _usbMode, uint8_t const *buf, uint16_t bufsize)
{
    switch (_usbMode)
    {
    case STARTSAVING:
        break;
    case TIME:
        //time data will be sent in 2 bytes. the first byte will be hour, the second byte will be minutes
        if (bufsize = 16) //this makes sure the data is 2 bytes before moving on
        {
            u_int16_t value = (u_int16_t)buf;
            uint8_t hour = value & 0xFF;
            u_int8_t minute = value >> 8;
            display1.DrawNumber(hour);
            display2.DrawNumber(minute);
        }
        else
        {
            display1.DrawError();
            display2.DrawError("TDA");
        }
        break;
    case GETSETTINGS:
        break;
    case KEYPAD:
        break;
    case RGBCOLOR:
        //data recieved here should be 24 bits/3 bytes
        break;
    case RGBEFFECT:
        break;
    case KEYBOARD:
        break;
    }
}

class Display
{
public:
    int cs;

    Display(int csPin)
    {
        cs = csPin;
    }

    //sends commands/data to a single display
    void _sendCmd(u_int8_t command)
    {
        const u_int8_t *c = (const u_int8_t *)command; //casts the data into a char pointer thingy
        gpio_put(DC, 0);
        gpio_put(cs, 0);
        spi_write_blocking(spi0, c, 8);
        gpio_put(cs, 1);
    }

    //inits a bunch of stuff for displays, including gpio mode
    void Init()
    {
        gpio_init(cs);
        gpio_set_dir(cs, GPIO_OUT);
        _sendCmd(0xAE); //Display Off
        _sendCmd(0x81); //Set contrast for color A
        _sendCmd(0x91); //145
        _sendCmd(0x82); //Set contrast for color B
        _sendCmd(0x50); //80
        _sendCmd(0x83); //Set contrast for color C
        _sendCmd(0x7D); //125
        _sendCmd(0x87); //master current control
        _sendCmd(0x06); //6
        _sendCmd(0x8A); //Set Second Pre-change Speed For ColorA
        _sendCmd(0x64); //100
        _sendCmd(0x8B); //Set Second Pre-change Speed For ColorB
        _sendCmd(0x78); //120
        _sendCmd(0x8C); //Set Second Pre-change Speed For ColorC
        _sendCmd(0x64); //100
        _sendCmd(0xA0); //set remap & data format
        _sendCmd(0x72); //0x72
        _sendCmd(0xA1); //Set display Start Line
        _sendCmd(0x0);
        _sendCmd(0xA2); //Set display offset
        _sendCmd(0x0);
        _sendCmd(0xA4); //Set display mode
        _sendCmd(0xA8); //Set multiplex ratio
        _sendCmd(0x3F);
        _sendCmd(0xAD); //Set master configuration
        _sendCmd(0x8E);
        _sendCmd(0xB0); //Set Power Save Mode
        _sendCmd(0x00); //0x00
        _sendCmd(0xB1); //phase 1 and 2 period adjustment
        _sendCmd(0x31); //0x31
        _sendCmd(0xB3); //display clock divider/oscillator frequency
        _sendCmd(0xF0);
        _sendCmd(0xBB); //Set Pre-Change Level
        _sendCmd(0x3A);
        _sendCmd(0xBE); //Set vcomH
        _sendCmd(0x3E);
        _sendCmd(0x2E); //disable scrolling
        _sendCmd(0xAF); //set display on
    }

    //inits the fonts for the displays and throws them in ram somewhere
    void InitDisplayFonts()
    {
    }

    //draws a string to the display....somehow....
    void DrawString(char string[], int size)
    {
        //set up fonts
        //get the string data
    }

    //draws a pixel to the display
    void DrawPixel(u_int16_t x, u_int16_t y, u_int16_t color)
    {
    }

    //easy method that draws the time
    void DrawNumber(u_int8_t number)
    {
    }

    //draws an error
    void DrawError()
    {
    }

    //draws the code for the error
    void DrawError(char code[])
    {
    }
};

/*ERROR MAP:
TDA = time data(there's an error with the time, either bufsize or the size of the data itself)
*/
