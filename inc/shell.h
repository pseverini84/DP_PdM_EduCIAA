typedef enum{noCmd, modeA, modeD, restart} shellCmd_t;//posibles comandos del sistema
shellCmd_t searchCmd(void);//funcion que busca un comando, si lo encuentra lo devuelve como return.
void shellInit(void);