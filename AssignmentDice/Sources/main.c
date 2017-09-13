/* ###################################################################
 **     Filename    : main.c
 **     Project     : AssignmentDice
 **     Processor   : MK20DX128VLH5
 **     Version     : Driver 01.01
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2017-09-13, 13:17, # CodeGen: 0
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
#include "SW1.h"
#include "BitIoLdd1.h"
#include "LED3.h"
#include "BitIoLdd2.h"
#include "LED2.h"
#include "BitIoLdd3.h"
#include "LED1.h"
#include "BitIoLdd4.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
#include "stddef.h"
#include <stdbool.h>
#include "string.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void setLED(int number) {
	switch (number) {
	case 0: //1
		LED3_PutVal(FALSE);
		LED2_PutVal(FALSE);
		LED1_PutVal(FALSE);
		break;
	case 1: //2
		LED3_PutVal(FALSE);
		LED2_PutVal(FALSE);
		LED1_PutVal(TRUE);
		break;
	case 2: //3
		LED3_PutVal(FALSE);
		LED2_PutVal(TRUE);
		LED1_PutVal(FALSE);
		break;
	case 3: //4
		LED3_PutVal(FALSE);
		LED2_PutVal(TRUE);
		LED1_PutVal(TRUE);
		break;
	case 4: //5
		LED3_PutVal(TRUE);
		LED2_PutVal(FALSE);
		LED1_PutVal(FALSE);
		break;
	case 5: //6
		LED3_PutVal(TRUE);
		LED2_PutVal(FALSE);
		LED1_PutVal(TRUE);
		break;
	case 6: //off
		LED3_PutVal(TRUE);
		LED2_PutVal(TRUE);
		LED1_PutVal(FALSE);
		break;
	}
}

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
	/* Write your local variable definition here */

	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialization.                    ***/

	/* Write your code here */
	/* For example: for(;;) { } */
	int counter = 0;
	int dice = 0;
	for (;;) {

		if (SW1_GetVal() == 1) {
			setLED(rand() % 6 + 1);
			for (int i = 0; i < 10000000; i++) {
			}
		} else {
			setLED(dice++);
			if (dice >= 6) {
				dice = 0;

			}
			for (int i = 0; i < 1000000; i++){}

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
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
 ** @}
 */
/*
 ** ###################################################################
 **
 **     This file was created by Processor Expert 10.5 [05.21]
 **     for the Freescale Kinetis series of microcontrollers.
 **
 ** ###################################################################
 */
