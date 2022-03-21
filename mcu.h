/*
 * mcu.h
 *
 *  Created on: Dec 14, 2021
 *      Author:
 */

#ifndef MCU_H_
#define MCU_H_

#include <DSP2833x_Device.h>

#define MCU_LSPCLK 37500000

void mcu_initSpia(unsigned long Baudrate);

#endif /* MCU_H_ */
