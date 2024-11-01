#ifndef PWRINSPACE_SENSOR_DATA
#define PWRINSPACE_SENSOR_DATA

#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

#include "esp_log.h"
#include <stdbool.h>

typedef struct {
    float firstSensorData;
    float secondSensorData;
} mesurmentsToTanwa;

SemaphoreHandle_t sensor_data_mutex;
mesurmentsToTanwa sensor_data;

void update_data(mesurmentsToTanwa *sesnorsDataToTanwa);
mesurmentsToTanwa read_data(void);
bool data_init(void);


#endif