/* ###################################################################
 **     Filename    : main.c
 **     Project     : Lab4
 **     Processor   : MK20DX128VLH5
 **     Version     : Driver 01.01
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2017-08-25, 17:31, # CodeGen: 0
 **     Abstract    :
 **         Main module.
 **         This module contains user's application code.
 **     Settings    :
 **     Contents    :
 **         No public methods
 **
 ** ###################################################################*/
/*!
 ** @file main.c
 ** @version 01.01
 ** @brief
 **         Main module.
 **         This module contains user's application code.
 */
/*!
 **  @addtogroup main_module main module documentation
 **  @{
 */
/* MODULE main */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "GreenLED.h"
#include "BitIoLdd1.h"
#include "RedLED.h"
#include "BitIoLdd2.h"
#include "BlueLED.h"
#include "BitIoLdd3.h"
#include "AS1.h"
#include "ASerialLdd1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
#include <string.h>

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
	/* Write your local variable definition here */
	byte c, err;
	char str = "Not Computable";
	int i;

	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialization.                    ***/

	/* Write your code here */
	for (;;) {

		do {
			err = AS1_RecvChar(&c);
		} while (err != ERR_OK);
		if (c == 'r') {
			RedLED_SetVal();
		} else if (c == 'g') {
			GreenLED_SetVal();
		} else if (c == 'b') {
			BlueLED_SetVal();
		} else {
			void send_string(char *str) {
				size_t len;
				len = strlen(str);
				for (i = 0; i < len; i++) {
					err = AS1_SendChar(str[i]);
					{
					}
					do {
						err = AS1_SendChar(str[i]);
					} while (err != ERR_OK);
				}
			}
		}
	}

}

/*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
