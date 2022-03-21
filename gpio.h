/*
 * gpio.h
 *
 *  Created on: Dec 14, 2021
 *      Author:
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <DSP2833x_Device.h>

#define LD2_ON GpioDataRegs.GPACLEAR.bit.GPIO31 = 1
#define LD2_OFF GpioDataRegs.GPASET.bit.GPIO31 = 1
#define LD2_TOGGLE GpioDataRegs.GPATOGGLE.bit.GPIO31 = 1

#define LD3_ON GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1
#define LD3_OFF GpioDataRegs.GPBSET.bit.GPIO34 = 1
#define LD3_TOGGLE GpioDataRegs.GPBTOGGLE.bit.GPIO34 = 1

#define PB1 GpioDataRegs.GPADAT.bit.GPIO21
#define PB1_PRESSED (GpioDataRegs.GPADAT.bit.GPIO21 == 0)

#define PB2 GpioDataRegs.GPADAT.bit.GPIO27
#define PB2_PRESSED (GpioDataRegs.GPADAT.bit.GPIO27 == 0)

void gpio_init(void);

#endif /* GPIO_H_ */
