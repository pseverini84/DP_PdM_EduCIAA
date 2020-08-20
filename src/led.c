/*==================[inclusions]=============================================*/
#include "led.h"
#include "sapi.h"
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
void ledDo(ledColor_t which, ledAction_t what){
	static bool_t actualState[3]={OFF,OFF,OFF};

	switch(what){
		case on:
			actualState[which]=ON;
			break;
		case off:
			actualState[which]=OFF;
			break;
		case toggle:
			actualState[which]=!actualState[which];
			break;
	}
	gpioWrite(LED1,actualState[0]);
	gpioWrite(LED2,actualState[1]);
	gpioWrite(LED3,actualState[2]);
}
