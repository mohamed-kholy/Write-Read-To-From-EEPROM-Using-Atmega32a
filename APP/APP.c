/*
 * APP.c
 *
 * Created: 04/10/2021 08:54:05 م
 *  Author: Mohamed El-Kholy
 */ 
#include "APP.h"
#include <util/delay.h>
#define F_CPU	8000000UL


/* global Variable Holds The Received Data From EEPROM */
u8  global_u8ReceivedData ;
/* global Array holds The Received String From USART */
u8  global_u8StrArr[10];
/* global Array holds the location Address of the EEPROM */
u8  global_u8AddArr[16];
/* global Array holds The incoming Data That will be stored in EEPROM */
u8  global_u8DataArr[10];
/* global Variable holds The Integer Value of the EEPROM Location Address */
u16 global_u16Address;
/* global Variable that holds the Data Value After Converted form String to integer */
u8 global_u8Data ;

void APP_voidAPPInit(void)
{
	/* Initialize EEPROM */
	EUEEPROM_voidEEPROMInit();
	/* Initialize USART */
	MUSART_voidUsartInit();

}

void APP_voidAPPUpdate(void)
{
	/* Receive The Data from USART */
	MUSART_u8UsartReceiveString(global_u8StrArr);
	/* If USART Received "WRITE" */
	if (strcmp(global_u8StrArr,"WRITE")==0)
	{	
		APP_voidWrite();
	}
	/* If USART Received "READ" */
	else if (strcmp(global_u8StrArr,"READ")==0)
	{
		 APP_voidRead();
	}
	else 
	{
		APP_voidError();
	}
}

void APP_voidWrite(void)
{
	/* Send String Through USART */
	MUSART_voidUsartSendString("Enter The Location Address : ");
	/* Receive The Location */
	MUSART_u8UsartReceiveString(global_u8AddArr);
	/* Convert The Incoming location into Integer */
	global_u16Address = atoi(global_u8AddArr);
	/* Send String */
	MUSART_voidUsartSendString("Enter The Data  : ");
	/* receive The Data That Will be Stored In EEPROM */
	MUSART_u8UsartReceiveString(global_u8DataArr);
	/* convert The received Data array to Integer */
	global_u8Data = atoi(global_u8DataArr);
	/* Send String */
	MUSART_voidUsartSendString("Data Stored Successfully");
	/* Write The Data To EEPROM */
	EUEEPROM_voidEEPROMWriteData(global_u16Address,global_u8Data);
	/* Send New Line */
	MUSART_voidUsartSendChar('\r');
}

void APP_voidRead(void)
{
	/* Send String */
	MUSART_voidUsartSendString("Enter The Location Address : ");
	/* Receive The Location */
	MUSART_u8UsartReceiveString(global_u8AddArr);
	/* Convert The incoming Location from String into integer */
	global_u16Address = atoi(global_u8AddArr);
	/* Read The Data From EEPROM */
	global_u8ReceivedData = EUEEPROM_u8EEPROMReadData(global_u16Address);
	/* convert The Received Data to Array to Send Through USART */
	itoa(global_u8ReceivedData,global_u8DataArr,10);
	/* Send String */
	MUSART_voidUsartSendString("This Location Has Value =  ");
	/* Display The data */
	MUSART_voidUsartSendString(global_u8DataArr);
	/* Send New Line */
	MUSART_voidUsartSendChar('\r');
	
}
void APP_voidError(void)
{
	/* Send String */
	MUSART_voidUsartSendString("I Can't Understand ");
	/* Send New Line */
	MUSART_voidUsartSendChar('\r');
	
}