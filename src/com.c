/*==================[inclusions]=============================================*/

#include "sapi.h"              // <= sAPI header

/*==================[macros and definitions]=================================*/
#define rxBuffSize 100
/*==================[internal data declaration]==============================*/
static char myRx[rxBuffSize];
static char *myRdRxBuffPtr;
static char *myWrRxBuffPtr;
static uint16_t lineCounter=0;

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/
void onRx( void *noUsado )
{
   char c = uartRxRead( UART_USB );
   if(myWrRxBuffPtr>=myRdRxBuffPtr)
      if(myWrRxBuffPtr-myRdRxBuffPtr==sizeof(myRx))
         return;
   else
      if(myRdRxBuffPtr-myWrRxBuffPtr==sizeof(myRx))
         return;
      
   *myWrRxBuffPtr=c;
   if(myWrRxBuffPtr<&myRx[sizeof(myRx)-1])
      myWrRxBuffPtr++;
   else
      myWrRxBuffPtr=myRx;

   if(c==0x0D)
      lineCounter++;
}

/*==================[external functions definition]==========================*/
void getLine(char *ptr){
   *ptr=0;
   if(lineCounter==0)
      return;
   uint8_t x;
   
   while(*myRdRxBuffPtr!=0x0D)
   {
      *ptr=*myRdRxBuffPtr;
      ptr++;
      myRdRxBuffPtr++;
   }
   
   lineCounter--;
   *ptr=0x00;
   myRdRxBuffPtr++;
}

void comRxInit(void)
{
   /* Inicializar la UART_USB junto con las interrupciones de Tx y Rx */
   uartConfig(UART_USB, 115200);     
   // Seteo un callback al evento de recepcion y habilito su interrupcion
   uartCallbackSet(UART_USB, UART_RECEIVE, onRx, NULL);
   // Habilito todas las interrupciones de UART_USB
   uartInterrupt(UART_USB, true);
   
   myRdRxBuffPtr=myRx;
   myWrRxBuffPtr=myRx;
}
