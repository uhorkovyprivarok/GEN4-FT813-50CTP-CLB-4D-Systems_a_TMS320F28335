

/**
 * main.c
 */

#include <DSP2833x_Device.h>
#include "F28335_DeviceBasic.h"
#include "mcu.h"
#include "gpio.h"
#include "interrupts.h"
#include "spi_func.h"





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

    //mcu_initSpia(500000); // set to 500 kHz
    mcu_initSpia(1000000); // set to 1000 kHz

    //intr_initInterrupts();


    EVE_init();

    EVE_cmd_dl(CMD_DLSTART);
    EVE_cmd_dl(DL_CLEAR_RGB | 0x000000UL);
    EVE_cmd_dl(DL_CLEAR | CLR_COL | CLR_STN | CLR_TAG);
    EVE_cmd_text((EVE_HSIZE/2), 50, 28, EVE_OPT_CENTER, "Hello there...");
    EVE_cmd_dl(DL_DISPLAY);
    EVE_cmd_dl(CMD_SWAP);
    EVE_execute_cmd();


   while(1)
    {

    }



	return 0;
}
