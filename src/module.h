#ifndef _MODULE_H_
#define _MODULE_H_


typedef enum{false, true} bool_t;

extern const uint8_t BCK_SPACE_CHAR;
extern const uint8_t NEW_LINE_CHAR ;
extern const uint8_t CARRIAGE_RTRN ;
extern const uint8_t MAX_BUFF_LEN  ;
extern const uint8_t MIN_BUFF_IDX  ;


/* Parameter: cmd_in is a pointer to a buffer to store 
*  the user input data (command)
*  Returns: The length of the data readed
*/
uint8_t command_read(char *cmd_in);


/* Check if the command entered by the user is a valid command
*  Parameter: cmd is a pointer to a buffer where data input is stored
*  Returns: true if the command input by user is a valid command, false otherwise
*  Valid commands: 
					+ "read voltage"
					+ "read current"
					+ carriage return "\r"
*/
bool_t cmd_validation(char *cmd);


/* Builds a string with data in an user readable format
*  Parameters:
*				+ value:   an integer with current or voltage data
*				+ cmd:     a pointer to the command string
*				+ out_str: a pointer to the string that is to be send
*  Returns: Nothing
*/
void build_rtn_str(uint16_t value, const char *cmd, char *out_str);


/* 
*  Parameters: out_str is a pointer to the formated buffer that is to be send
*  Returns: Nothing
*/
void send_info(const char *out_str);


#endif
























































// Sábado por la mañana
// Junto al lago en pereira
// entre la 6ta y la 7ma calle 25  #25-59


