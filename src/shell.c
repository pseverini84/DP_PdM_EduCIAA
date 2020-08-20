#include <stdio.h>
#include "shell.h"
#include "string.h"
#include "com.h"
/*==================[macros and definitions]=================================*/
#define debugDP
#define maxCommandLength 10
/*==================[internal data declaration]==============================*/
static const char command[][maxCommandLength]={"\0","mode -a\0","mode -d\0","restart\0"};  
/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
shellCmd_t searchCmd(void){
   int x;
   shellCmd_t com;
   char myCmd[maxCommandLength];
   getLine(myCmd);
   #ifdef debugDP
   if(*myCmd)
      printf("Line: %s \r\n", myCmd);
   #endif
   for(x=0;x<4;x++)
      if(!strcmp(command[x],myCmd))
         return com+x;
}

void shellInit(void)
{
   comRxInit();
}


