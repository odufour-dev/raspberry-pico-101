#include "pico_led.h"

void pico_led_init(void){
    stdio_init_all();
    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed");
    }
}

void pico_set_led(bool led_on){
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, led_on);
}
