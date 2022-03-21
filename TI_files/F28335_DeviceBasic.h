/*
 * F28335_DeviceBasic.h
 *
 *  Created on: Dec 14, 2021
 *      Author:
 */

#ifndef TI_FILES_F28335_DEVICEBASIC_H_
#define TI_FILES_F28335_DEVICEBASIC_H_

void DeviceInitialization(void);
void InitFlash(void);

extern void DSP28x_usDelay(long LoopCount);
#define CPU_RATE 6.67L //!< Sets CPU rate for DELAY_US macro.
#define DELAY_US(A)  DSP28x_usDelay(((((long double) A * 1000.0L) / (long double)CPU_RATE) - 9.0L) / 5.0L) //!< Sets CPU rate for DELAY_US macro.

#endif /* TI_FILES_F28335_DEVICEBASIC_H_ */
