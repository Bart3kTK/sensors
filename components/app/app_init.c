#include "app_init.h"
#include "hardware.h"
#include <stdbool.h>
#include "freertos/FreeRTOS.h"
#define TAG  "TANWA_SENSORS_APP_INIT"

// #define TEMPERATURA jest_pi3\.
void config_app()
{
    if(hardware_init() == true)
    {
        ESP_LOGI(TAG, "sensors init done");
    }
         
    else 
    {
        ESP_LOGE(TAG, "sensors init error"); 
    }
        

    Hardware_Manager_t* hardwareInstance = NULL;

    if(hardware_get_instance(&hardwareInstance) == true)
    {
        ESP_LOGI(TAG, "hardware instance is available"); 
    }
        
    else
    {
        ESP_LOGE(TAG, "hardware get instance error");
    }
        

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

void app_init()
{
    config_app();
}





