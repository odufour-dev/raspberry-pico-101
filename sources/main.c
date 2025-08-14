
#include "pico/stdlib.h"

#define LED_DELAY_MS 2000

static void pico_led_init(void){
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN,GPIO_OUT);
}

void pico_set_led(bool led_on){
    gpio_put(PICO_DEFAULT_LED_PIN, led_on);
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