/*
 * interrupts.c
 *
 *  Created on: Dec 14, 2021
 *      Author:
 */

#include <DSP2833x_Device.h>
#include "interrupts.h"

void intr_initInterrupts(void){

    // globally disable interrupts
    DINT;

    // clear flags
    IFR = 0x0;
    PieCtrlRegs.PIEACK.all = 0xFFFF;

    // route interrupts
    EALLOW;
    PieVectTable.SPIRXINTA = &intr_SpiaRcv;
    EDIS;

    // enable interrupts
    PieCtrlRegs.PIEIER6.bit.INTx1 = 1; // enable interrupt INT6.1 - SPIRXINTA
    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;
    IER |= 0x20;
    EINT;

}

// interrupt 6.1 - SPIRXINTA
interrupt void intr_SpiaRcv(void){

    // code

    // clear flags
    SpiaRegs.SPIFFRX.bit.RXFFINTCLR = 1;
    PieCtrlRegs.PIEACK.bit.ACK6 = 1;
}
