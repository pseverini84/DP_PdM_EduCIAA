typedef enum{
	on,
	off,
	toggle,
}ledAction_t;

typedef enum{
	led_yellow,
	led_red,
	led_green,
}ledColor_t;
void ledDo(ledColor_t which, ledAction_t what);
