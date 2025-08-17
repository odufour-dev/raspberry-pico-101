
#include "pico/stdlib.h"

#include "pico_led.h"

#define LED_DELAY_MS 2000

int main(int argc, char* argv[]){

    (void)argc;
    (void)argv;

    printf("Initialize PICO\n");
    pico_led_init();
    while(true){
        printf("LED 'on'\n");
        pico_set_led(true);
        sleep_ms(LED_DELAY_MS);
        printf("LED 'off'\n");
        pico_set_led(false);
        sleep_ms(LED_DELAY_MS);
    }

}