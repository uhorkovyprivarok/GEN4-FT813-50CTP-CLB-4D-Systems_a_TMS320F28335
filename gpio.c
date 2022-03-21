/*
 * gpio.c
 *
 *  Created on: Dec 14, 2021
 *      Author:
 */

#include "gpio.h"

void gpio_init(void){

    EALLOW;

    SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1; // enable clocks for inputs

    GpioCtrlRegs.GPADIR.bit.GPIO17 = 0; // GPIO17 is PB1
    GpioCtrlRegs.GPAPUD.bit.GPIO17 = 0; // enable pull-up for GPIO17
    GpioCtrlRegs.GPAQSEL2.bit.GPIO17 = 2; // qualification using 6 samples

    GpioCtrlRegs.GPADIR.bit.GPIO27 = 0; // GPIO27 is PB2
    GpioCtrlRegs.GPAPUD.bit.GPIO27 = 0; // enable pull-up for GPIO27
    GpioCtrlRegs.GPAQSEL2.bit.GPIO27 = 2; // qualification using 6 samples

    GpioCtrlRegs.GPADIR.bit.GPIO31 = 1; // GPIO31 output is LD2
    GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1; // GPIO31 output is LD3

    EDIS;
}
