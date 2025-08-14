#ifndef PICO_LED__
#define PICO_LED__

#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

void pico_led_init(void);
void pico_set_led(bool led_on);

#endif
