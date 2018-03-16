#ifndef _SERIAL_PORT_H
#define _SERIAL_PORT_H

 /* SER_ReadByte: Reads a byte from the Serial Port Input FIFO
* /param [OUT] pu8ReadByte: Pointer of memory where the read byte will be stored
* /retval bool_t : [TRUE: A byte was read from serial port FIFO]
* [FALSE: No data was read*/
bool_t SER_ReadByte(uint8_t * pu8ReadByte);


/* SER_WriteByte: writes a byte to the serial port output FIFO
* param [IN] u8Byte: Byte to write to the port */
void SER_WriteByte(uint8_t u8Byte);


#endif