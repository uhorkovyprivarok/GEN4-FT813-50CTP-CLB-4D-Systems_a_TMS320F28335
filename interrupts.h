/*
 * interrupts.h
 *
 *  Created on: Dec 14, 2021
 *      Author:
 */

#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include <DSP2833x_Device.h>

void intr_initInterrupts(void);
interrupt void intr_SpiaRcv(void);

#endif /* INTERRUPTS_H_ */
