/*
 * mcu.c
 *
 *  Created on: Dec 14, 2021
 *      Author:
 */

#ifndef MCU_C_
#define MCU_C_

#include "mcu.h"

void mcu_initSpia(unsigned long Baudrate){

    EALLOW;

    // GPIO config
    GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 1; // GPIO16 -> SPISIMOA a.k.a. SPI A MOSI - Master out, slave in
    GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 1; // GPIO17 -> SPISOMIA a.k.a. SPI A MISO - Master in, slave out
    GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 1; // GPIO18 -> SPICLKA a.k.a. SPI A CLK - Clock out
    //GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 1; // GPIO19 -> !SPISTEA a.k.a. SPI A CS - Chip select
    GpioCtrlRegs.GPADIR.bit.GPIO19 = 1;

    // enable clocks for SPI module
    SysCtrlRegs.PCLKCR0.bit.SPIAENCLK = 1;

    EDIS;

    // general settings
    SpiaRegs.SPICCR.bit.SPICHAR = 7; // 8bit character
    SpiaRegs.SPICTL.bit.MASTER_SLAVE = 1; // MCU is master
    SpiaRegs.SPIPRI.bit.FREE = 1; // free run during emulation suspend

    // clocking
    SpiaRegs.SPICTL.bit.CLK_PHASE = 0; // clock phase
    SpiaRegs.SPICCR.bit.CLKPOLARITY = 1; // clock polarity
    SpiaRegs.SPIBRR = MCU_LSPCLK/Baudrate - 1;

    // fifo
    SpiaRegs.SPIFFTX.bit.SPIFFENA = 1; // enable FIFO
    SpiaRegs.SPIFFRX.bit.RXFFIL = 2; // FIFO set to 2 words
    SpiaRegs.SPIFFRX.bit.RXFFIENA = 1; // enable fifo receive interrupts
    SpiaRegs.SPIFFRX.bit.RXFIFORESET = 1; // enable receive FIFO operation

    // enables
    SpiaRegs.SPICTL.bit.TALK = 1; // enable transmit
    SpiaRegs.SPICCR.bit.SPISWRESET = 1; // bring out SPI from reset state

}

#endif /* MCU_C_ */
