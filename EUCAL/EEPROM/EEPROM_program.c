#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "EEPROM_private.h"
#include "EEPROM_config.h"
#include "EEPROM_interface.h"
#include "../../MCAL/I2C/I2C_interface.h"

void EUEEPROM_voidEEPROMInit (void)
{
	/* Initialize I2c As Master */
	MI2C_voidMasterInit();
}
void EUEEPROM_voidEEPROMWriteData (u16 copy_u16Address , u8 copy_u8Data)
{
			
	/* local Variable holds The Result From The Equation that Calculate the Required Address Location */
	u16 local_u16Address;
	/* Send Start Condition */
	MI2C_enuSendStartCondition();
	/* Calculate The Address */
	local_u16Address =  ((EEPROM_ADDRESS) | ((copy_u16Address >> 8 ) & (7))) ;
	/* Send EEPROM Address With Write Operation */
	MI2C_enuSendSlaveAddWithWrite((u8)local_u16Address);
	/* Send The Required Location */
	MI2C_enuMasterSendDataByte((u8) copy_u16Address );
	/* Send Data The Required Location */
	MI2C_enuMasterSendDataByte(copy_u8Data);
	/* Send Stop Condition*/
	MI2C_voidSendStopCondition();

}
u8 	 EUEEPROM_u8EEPROMReadData	  (u16 copy_u16Address)
{
	/* local Variable holds The Result From The Equation that Calculate the Required Address Location */
	u16 local_u16Address ;
	/* local Variable holds The Received Data */
	u8 local_u8ReturnData ;
	/* Send Start Condition */
	MI2C_enuSendStartCondition();
	/* Calculate The Address */
	local_u16Address =  ((EEPROM_ADDRESS) | ((copy_u16Address >> 8 ) & (7))) ;
	/* Send EEPROM Address With Write Operation */
	MI2C_enuSendSlaveAddWithWrite((u8)local_u16Address);
	/* Send The Required Location */
	MI2C_enuMasterSendDataByte((u8) copy_u16Address );
	/* Send Repeated Start Condition */
	MI2C_enuSendRepeatedStartCondition();
	/* Send EEPROM Address With Read Operation */
	MI2C_enuSendSlaveAddWithRead((u8)local_u16Address);
	/* Return The Received Data */
	MI2C_enuMasterReadDataByte(&local_u8ReturnData);
	/* Send Stop Condition*/
	MI2C_voidSendStopCondition();
	/* Return */
	return local_u8ReturnData ;
}