/*
 * APP.h
 *
 * Created: 04/10/2021 08:54:16 م
 *  Author: Mohamed El-Kholy
 */ 


#ifndef APP_H_
#define APP_H_

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../EUCAL/EEPROM/EEPROM_interface.h"
#include "../MCAL/I2C/I2C_interface.h"
#include "../MCAL/USART/UART_interface.h"
#include <string.h>
#include <stdlib.h>

void APP_voidAPPInit(void);
void APP_voidAPPUpdate(void);
void APP_voidRead(void);
void APP_voidWrite(void);
void APP_voidError(void);




#endif /* APP_H_ */