/**
 * main.c generico para nuevo proyecto.
 *
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

int main() {

    /* Inicializa el standard input/output de la pico */
    stdio_init_all();
    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4);
    const float conversion_factor = 3.3f / (1 << 12);
   


    while (true) { 
     
      uint16_t result = adc_read();
      float t= 27 - (result * conversion_factor - 0.706)/0.001721;
      printf("Raw value: 0x%03x, voltage: %.2f V, la temperatura es: %.2f\n", result, result * conversion_factor,t);
       sleep_ms(500);
    }
    return 0;
}