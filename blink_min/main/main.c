#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
 
#define LED_GPIO 4   // LED en GPIO4
 
void app_main(void) {
    // Configurar GPIO4 como salida
    gpio_config_t io = {
        .pin_bit_mask = 1ULL << LED_GPIO,
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = 0,
        .pull_down_en = 0,
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&io);
 
    // Bucle principal
    while (1) {
        gpio_set_level(LED_GPIO, 1);             // LED ON
        vTaskDelay(2000 / portTICK_PERIOD_MS);    // 500 ms
 
        gpio_set_level(LED_GPIO, 0);             // LED OFF
        vTaskDelay(2000 / portTICK_PERIOD_MS);    // 500 ms
    }
}