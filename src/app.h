#ifndef _APP_H_
#define _APP_H_


/* APP_ReadVoltage: Returns the current voltage in the line
* /retval u16Voltage: Voltage in 10mV units.
* i.e: if function returns
* 12345, voltage is 123.45V */
uint16_t APP_ReadVoltage(void);


/* APP_ReadCurrent: Returns the current in the line
*
* /retval u16Current: Current in 10mA units.
* i.e: if function returns
* 789, current is 7.89A*/
uint16_t APP_ReadCurrent(void);

#endif





