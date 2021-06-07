#include "Display.h"
int cs;
    //sends commands/data to a single display
    void _sendCmd(u_int8_t command)
    {
        gpio_put(DC, 0);
        gpio_put(cs, 0);
        spi_write_blocking(spi0, &command, 8);
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

/*ERROR MAP:
TDA = time data(there's an error with the time, either bufsize or the size of the data itself)
*/
