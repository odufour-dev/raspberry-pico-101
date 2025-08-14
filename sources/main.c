
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

#define LED_DELAY_MS 2000

static void pico_led_init(void){
    stdio_init_all();
    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed");
        return -1;
    }
}

void pico_set_led(bool led_on){
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, led_on);
}

int main(int argc, char* argv[]){

    (void)argc;
    (void)argv;

    pico_led_init();
    while(true){
        pico_set_led(true);
        sleep_ms(LED_DELAY_MS);
        pico_set_led(false);
        sleep_ms(LED_DELAY_MS);
    }

}