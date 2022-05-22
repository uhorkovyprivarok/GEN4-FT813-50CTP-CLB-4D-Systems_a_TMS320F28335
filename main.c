/**
 * main.c
 */

#include <DSP2833x_Device.h>
#include "F28335_DeviceBasic.h"
#include "mcu.h"
#include "gpio.h"
#include "EVE_commands.h"
#include "EVE_config.h"
#include "EVE_target.h"
#include "EVE.h"


int main(void)
{
    // initialize mcu clocks
    DeviceInitialization();

    // init gpio
    gpio_init();

    // init SPI
    mcu_initSpia(1000000); // set to 1000 kHz

    // init EVE
    EVE_init();

    EVE_cmd_dl(CMD_DLSTART);							// start 
    EVE_cmd_dl(DL_CLEAR_RGB | 0x000000UL);					// set black color 
    EVE_cmd_dl(DL_CLEAR | CLR_COL | CLR_STN | CLR_TAG);				// clear all
    EVE_cmd_text((EVE_HSIZE/2), 50, 28, EVE_OPT_CENTER, "Hello there...");	// write text
    EVE_cmd_dl(DL_DISPLAY);							// end
    EVE_cmd_dl(CMD_SWAP);							// swap screen
    EVE_execute_cmd();								// execute 

	return 0;
}
