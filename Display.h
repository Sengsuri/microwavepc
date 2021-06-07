#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"

#define DC 3

class Display
{
public:
    Display(int cs)
    {
    }

    void _sendCmd(u_int8_t command);
    void Init();
    void InitDisplayFonts();
    void DrawString(char string[], int size);
    void DrawPixel(u_int16_t x, u_int16_t y, u_int16_t color);
    void DrawNumber(u_int8_t number);
    void DrawError();
    void DrawError(char code[]);
};