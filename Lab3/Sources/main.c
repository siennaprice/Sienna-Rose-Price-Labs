#include "MK20D5.h"
#include <stdbool.h>


//integers
	int i;
	int j;
	int k;
	int counter;

int spin(i,j,k){
		for (counter = 0; counter < 1000000; counter++) {
			i = 0;

			for (counter = 0; counter < 1000000; counter++) {
				i = 1;

				for (counter = 0; counter < 1000000; counter++) {
					j = 0;

					for (counter = 0; counter < 1000000; counter++) {
						j = 1;
						for (counter = 0; counter < 1000000; counter++) {
							k = 0;

							for (counter = 0; counter < 1000000; counter++) {
								k = 1;
							}

						}
					}
				}
			}
		}
		return(0);
}

int main(void)
{
	//Clocking the port control module
	// Enable the clock for the port control module
	SIM_SCGC5 |= 0x3e000;

	//CODE BEGINS HERE

	//Initialising the LED's
	//select GPIO mode
	PORTC_PCR3 = 0x100; //red
	PORTD_PCR4 = 0x100; //green
	PORTA_PCR2 = 0x100; //blue

	//Setting data direction register to outputs
	GPIOC_PDDR = (1 << 3);
	GPIOD_PDDR = (1 << 4);
	GPIOA_PDDR = (1 << 2);

int i;
int j;
int k;

	set_LED(i,j,k){
		if (i = 1) {
			GPIOC_PDOR = 0;
		}
		else (i = 0); {
			GPIOC_PDOR = (1 << 3);
		}
		if (j = 1) {
			GPIOC_PDOR = 0;
		}
		else (j = 0); {
			GPIOD_PDOR = (1 << 4);
		}

		if (k = 1) {
			GPIOA_PDOR = 0;
		}
		else (k = 0); {
			GPIOA_PDOR = (1 << 2);
		}

	}

	////////////////////////////////////////////////////////////////////////////////
	// EOF
	////////////////////////////////////////////////////////////////////////////////

	/* Never leave main */
	return 0;
}
////////////////////////////////////////////////////////////////////////////////
// EOF
///////////////////////////////////////////////////////////////////////////////
