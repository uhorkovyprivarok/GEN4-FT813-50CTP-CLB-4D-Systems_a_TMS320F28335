

/**
 * main.c
 */

#include <DSP2833x_Device.h>
#include "F28335_DeviceBasic.h"
#include "mcu.h"
#include "gpio.h"
#include "interrupts.h"
#include "spi_func.h"



// blblbllbla

// OPYTAJ SA:   kolko je DELAY_US(1)


#include "EVE_commands.h"
#include "EVE_config.h"
#include "EVE_target.h"
#include "EVE.h"

/* some pre-definded colors
#define RED     0xff0000UL
#define ORANGE  0xffa500UL
#define GREEN   0x00ff00UL
#define BLUE    0x0000ffUL
#define BLUE_1  0x5dade2L
#define YELLOW  0xffff00UL
#define PINK    0xff00ffUL
#define PURPLE  0x800080UL
#define WHITE   0xffffffUL
#define BLACK   0x000000UL
*/


int main(void)
{
    // initialize mcu clocks
    DeviceInitialization();

    // init gpio
    gpio_init();

    // initialize SPI-A to 100 kBaud/s = 100 kHz
   // mcu_initSpia(100000);
    mcu_initSpia(500000); // 500kHz

    //intr_initInterrupts();

    //CLK_PHASE = 1;
    //CLKPOLARITY = 0;

    EVE_init();

/*
    EVE_cmd_dl(CMD_DLSTART); // tells EVE to start a new display-list
    EVE_cmd_dl(DL_CLEAR_RGB | 0xFFFFFF); // sets the background color
    EVE_cmd_dl(DL_CLEAR | CLR_COL | CLR_STN | CLR_TAG);
    EVE_color_rgb(0x0);
    EVE_cmd_text(5, 15, 28, 0, "Hello there!");
    EVE_cmd_dl(DL_DISPLAY); // put in the display list to mark its end
    EVE_cmd_dl(CMD_SWAP); // tell EVE to use the new display list
    while (EVE_busy());
*/


/*    int y = 0;
    int x = (0 & 0xFF) << 8;;
    char gayy[] = {"MCU_SPI_CLK_Freq(<11MHz);"};

    //spi_sendChar("C");
    while(1)
    {
        spi_sendData(gayy, 20);
    }
*/


/*    while(1)
    {
        if (PB2_PRESSED)
            {
            LD3_ON;
            LD2_ON;
            }
        else
            {
            LD2_OFF;
            LD3_OFF;
            }


    }
*/


	return 0;
}
