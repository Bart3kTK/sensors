#include "app_init.h"
#include "esp_log.h"

static const char *TAG = "TANWA_TEMPERATURE";

void app_main(void) {

    ESP_LOGI(TAG, "### TANWA TEMP SENSORS APP INIT ###");

    app_init();

    ESP_LOGI(TAG, "### TANWA TEMP SENSORS APP END ###");

}
