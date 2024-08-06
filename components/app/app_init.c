#include "app_init.h"
#include "hardware.h"
#include <stdbool.h>

static const char *TAG = "TANWA_SENSORS_APP_INIT";

// #define TEMPERATURA jest_pijana_no_i_buja_sie_po_klubach
void config_app()
{
    if(hardware_init() == true)
        ESP_LOG(TAG, "sensors init done"); 
    else 
        ESP_LOGR(TAG, "sensors init error"); 

    Hardware_Manager_t* hardwareInstance = NULL;

    if(hardware_get_instance(&hardwareInstance) == true)
        ESP_LOG(TAG, "hardware instance is available"); 
    else
        ESP_LOGE(TAG, "hardware get instance error");

// #ifdef TEMPERATURA
//generalnie w hardware mozna by bylo podzielic hardware_init() na 
//3 funkcje do init hardware
//1.common part
//2.temp sensors init
//3.pressure sensors init
//wiec prosze o feedback :D
//i wtedy ifdefy byly by tutaj a nie tam
// #endif


//teraz widze ze tu jakis  vTaskDelete(NULL); ma byc
//ale to poczytam jeszcze
}

void app_tasks();





