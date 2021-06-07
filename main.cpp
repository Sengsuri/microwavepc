#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "hardware/dma.h"
#include "hardware/pio.h"
#include "hardware/spi.h"
#include "hardware/flash.h"
#include "hardware/gpio.h"
#include "hardware/regs/addressmap.h"
#include "hardware/structs/xip_ctrl.h"
#include "bsp/board.h"
#include "tusb.h"
#include "Display.h"

//TODO: set these pins
#define DISPLAY_1 1 //cs pins for the spi displays
#define DISPLAY_2 2
#define DC 3            //data command pin for spi. only need one
#define ACTION_SIZE 136 //the size of each action in bits
#define FILE_START 0    //where the start of actions are in flash

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

enum Buttons
{
    null = -1,
    BakedPotato,
    Popcorn,
    Pizza,
    Beverage,
    FrozenDinner,
    Reheat,
    One,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Clock,
    Zero,
    Add30Sec,
    PowerLevel,
    TimeCook,
    KitchenTimer,
    TimeDefrost,
    WeightDefrost,
    StopClear
}; //Buttons for the keypad

Display display1;
Display display2;

//keypad settings/actions will be stored in an array

struct Action
{
    //each action is 192 bits
    //the last 7 bytes are empty/reserved
    u_int8_t rgbEffect; //one byte
    u_int32_t rgb1;     //fours bytes, only need 3
    u_int32_t rgb2;
    //eight bytes
    u_int64_t keyboardMacro; //0 byte are modifiers(ctrl, shift, etc), bytes 1-6 are keys, the last 2 bytes are blank
};

//second core
void Core1()
{
    //this core will handle the keypad inputs and display and reading from flash

    Action *keypadMap[23];

    gpio_init(25); //led (i think)
    //------init display stuff-------------

    gpio_init(DC);

    gpio_set_dir(DC, GPIO_OUT);
    gpio_set_dir(25, GPIO_OUT);

    //spi gpio pins are sck = 18, tx = 19, rx = 16, CSn = 17
    spi_init(spi0, 6666666);

    gpio_set_function(PICO_DEFAULT_SPI_RX_PIN, GPIO_FUNC_SPI);
    gpio_set_function(PICO_DEFAULT_SPI_SCK_PIN, GPIO_FUNC_SPI);
    gpio_set_function(PICO_DEFAULT_SPI_TX_PIN, GPIO_FUNC_SPI);

    display1 = Display(DISPLAY_1);
    display2 = Display(DISPLAY_2);

    display1.Init();
    display2.Init();
    //---------------------------------------------------
    //-------init keypad--------------------------------
    /*
    the array will be setup in this order
    baked potato = 0
    popcorn = 1
    pizza = 2
    beverage = 3
    frozen dinner = 4
    etc......
    */

    for (int i = 1; i <= 5; i++)
    {
        gpio_init(i);
        gpio_set_dir(i, GPIO_OUT);
        gpio_put(i, 0);
    }
    for (int i = 6; i <= 10; i++)
    {
        gpio_init(i);
        gpio_set_dir(i, GPIO_IN);
    }
    //-----------------------------------------------------

    //------dma and stream init---------------------------

    GetData(keypadMap);

    //-----------------------------------------------------

    while (1)
    {

        for (int o = 1; o <= 5; o++) //Out pins
        {
            gpio_put(o, 1);
            for (int i = 6; i <= 10; i++) //in pins

            {
                if (gpio_get(i) != 0)
                {
                    Buttons button = GetKeypad(o, i);
                    switch (button)
                    { //send usb data to fifo, other core handles the usb
                    }
                }
            }
            gpio_put(o, 0);
        }

        //if the other core needs data then this core gets sends the data through fifo, stopping the other functions

        if (multicore_fifo_rvalid())
        {
            u_int32_t request = multicore_fifo_pop_blocking(); //the type of request

            switch (request)
            {
            case 1: //get the save data
                while (true)
                {
                    //read from the dma
                    //send the data through fifo
                }
                break;
            }
        }
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

        if (multicore_fifo_rvalid)
        {
            u_int32_t data = multicore_fifo_pop_blocking();
            if (data > 15)
            { //if the data is not dataType
            }
            else
            {
                switch (data)
                {
                case 1:
                    break;

                default:
                    break;
                }
            }
            u_int32_t usbData = multicore_fifo_pop_blocking();
        }
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
        //this will send one action per usb packet
        break;
    case KEYPAD:
        //the keypad
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

//gets the keypad data from flash and puts it into ram
void GetData(Action *keypadMap[])
{
    //24 bytes for each command
    //stream from flash to dma?
    //then get the data from the dma somehow?

    //each action is 192 bits, or six 32 bit chunks
    u_int32_t buf[count_of(keypadMap) * 6];

    //start the stream thingy
    while (!(xip_ctrl_hw->stat & XIP_STAT_FIFO_EMPTY))
        (void)xip_ctrl_hw->stream_fifo;           //actual stream thing I think?
    xip_ctrl_hw->stream_addr = (uint32_t)&buf[0]; //the address of the thing in flash
    xip_ctrl_hw->stream_ctr = count_of(buf);

    int dma_chan = dma_claim_unused_channel(true);

    dma_channel_config cfg = dma_channel_get_default_config(dma_chan);

    channel_config_set_transfer_data_size(&cfg, DMA_SIZE_32);
    channel_config_set_read_increment(&cfg, false);
    channel_config_set_write_increment(&cfg, true);
    channel_config_set_dreq(&cfg, DREQ_XIP_STREAM);
    dma_channel_configure(
        dma_chan,
        &cfg,
        (void *)keypadMap,
        (const void *)XIP_AUX_BASE,
        count_of(keypadMap),
        true);

    //this is here for safety reasons. don't wanna access an array that has no data
    dma_channel_wait_for_finish_blocking(true);

    //convert buf to action data that's mostly useful
    for (int i = 0; i <= count_of(buf); i++)
    {
    }
}

//saves data from ram into flash
void FlashData()
{
}

//handles when a button is pressed. should only be used by core1
void ActionHandler(Buttons button, Action *keypadMap)
{

    uint32_t *sendData[16]; //data to be sent

    uint8_t *dataType = 0b00000000; //first message will be the type of data being sent (0b is a binary literal)
    //if the data is greater than 16 it's not a dataType

    if (keypadMap[button].rgbEffect != 0) //if there is an rgbeffect
    {
        *dataType = *dataType | 0b00000001;
    }
    if (keypadMap[button].keyboardMacro != 0) //if there is a keyboard macro (including multiple keypresses)
    {
        *dataType = *dataType | 0b00000010;
        //dissect the keyboard macro flash data and turn it into data usb can read
    }
}

//gets the keypad button and returns the enum value
Buttons GetKeypad(int outPin, int inPin)
{
    Buttons buttons[5]; //the possible buttons that can be on if the outPin is on

    switch (outPin)
    {
    case 1:
        buttons[0] = BakedPotato;
        buttons[1] = Reheat;
        buttons[2] = WeightDefrost;
        buttons[3] = Six;
        buttons[4] = Eight;
        break;
    case 2:
        buttons[0] = FrozenDinner;
        buttons[1] = TimeDefrost;
        buttons[2] = Three;
        buttons[3] = Nine;
        buttons[4] = null;
        break;
    case 3:
        buttons[0] = Beverage;
        buttons[1] = Add30Sec;
        buttons[2] = KitchenTimer;
        buttons[3] = Five;
        buttons[4] = StopClear;
        break;
    case 4:
        buttons[0] = Popcorn;
        buttons[1] = TimeCook;
        buttons[2] = Two;
        buttons[3] = Four;
        buttons[4] = Zero;
        break;
    case 5:
        buttons[0] = Pizza;
        buttons[1] = PowerLevel;
        buttons[2] = One;
        buttons[3] = Seven;
        buttons[4] = Clock;
        break;
    }
    //(possible inPins are 6-10 inclusive)
    return buttons[inPin - 6];
}
