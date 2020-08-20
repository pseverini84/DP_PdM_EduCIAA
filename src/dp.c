#include "sapi.h"
#include "dp.h"
#include "led.h"
/*==================[inclusions]=============================================*/
#define debugDP
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/
typedef struct{
   sysStates_t state;
   sysStates_t nextState;
   bool_t ready;
}myState_t;
static myState_t myState;
/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
void systemInit(void){
   myState.state=sysInit;
   myState.nextState=sysReady;
   myState.ready=FALSE;
}

sysStates_t systemStateChange(sysStates_t newState){
   myState.nextState=newState;
}

void systemStatePoll(void){
   switch(myState.state){
      case sysInit:
         if(myState.ready==FALSE)
         {
            #ifdef debugDP
               printf("sysInit\r\n");
            #endif
            ledDo(led_green,off);
            ledDo(led_red,off);
            ledDo(led_yellow,off);
            myState.ready=TRUE;
         }
         else
         {
            myState.ready=FALSE;
            myState.state=sysReady;
         }   
         break;
      case sysReady:
         if(myState.ready==FALSE)
         {
            #ifdef debugDP
               printf("sysReady\r\n");
            #endif
            ledDo(led_green,on);
            myState.ready=TRUE;
         }
         else
         {
            if(myState.nextState==sysArmed)
            {
               myState.state=myState.nextState;
               myState.ready=FALSE;
            }
         }   
         break;
      case sysArmed:
         if(myState.ready==FALSE)
         {
            #ifdef debugDP
               printf("sysArmed\r\n");
            #endif
            ledDo(led_yellow,on);
            myState.ready=TRUE; 
         }
         else
         {
            if(myState.nextState==sysDisarmed)
            {
               myState.state=myState.nextState;
               myState.ready=FALSE;
            }
         }   
         break;
      case sysDisarmed:
         if(myState.ready==FALSE)
         {
            #ifdef debugDP
               printf("sysDisarmed\r\n");
            #endif
            ledDo(led_yellow,off);
            myState.ready=TRUE; 
         }
         else
         {
            if(myState.nextState==sysArmed)
            {
               myState.state=myState.nextState;
               myState.ready=FALSE;
            }
         }   
         break;
      case sysError:
         if(myState.ready==FALSE)
         {
            #ifdef debugDP
               printf("sysError\r\n");
            #endif
            ledDo(led_green,off);
            ledDo(led_red,on);
            ledDo(led_yellow,off);
            myState.ready=TRUE; 
         }
         else
         {
            if(myState.nextState==sysInit)
            {
               myState.state=myState.nextState;
               myState.ready=FALSE;
            }
         }   
         break;
   }
}
