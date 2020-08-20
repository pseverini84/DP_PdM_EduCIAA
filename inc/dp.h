typedef enum{
	sysInit,
	sysReady,
	sysArmed,
	sysDisarmed,
   sysError,
}sysStates_t;

void systemInit(void);
void systemStatePoll(void);
sysStates_t systemStateChange(sysStates_t newState);

