/*
 * EEPROM.c
 *
 * Created: 04/10/2021 08:52:50 م
 * Author : Mohamed El-Kholy
 */ 

#include "APP/APP.h"

#include <util/delay.h>
int main(void)
{
	/* Initialize The Application */
    APP_voidAPPInit();

    while (1) 
    {
		/* Update The Application */
		APP_voidAPPUpdate();
    }
}

