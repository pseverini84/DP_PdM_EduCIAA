 /*==================[inclusions]=============================================*/
#include "sapi.h"              // <= sAPI header
#include "dp.h"
#include "shell.h"
#include "string.h"
/*==================[macros and definitions]=================================*/
#define debugDP
/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
int main(void){

   /* ------------- INICIALIZACIONES ------------- */

   /* Inicializar la placa */
   boardConfig();
   
   systemInit();
   shellInit();
   

   while(TRUE) {
      
      switch(searchCmd())
      {
         case noCmd:
            break;
         case modeA:
            systemStateChange(sysArmed);
            break;
         case modeD:
            systemStateChange(sysDisarmed);
            break;
         case restart:
            systemStateChange(sysInit);
            break;
      }      
      systemStatePoll();
   }
   return 0 ;
}

/*==================[end of file]============================================*/
