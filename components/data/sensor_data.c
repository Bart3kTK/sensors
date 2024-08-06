
#include "sensor_data.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

#define TAG "SENSOR_DATA"

bool data_init(void)
{
    sensor_data_mutex = NULL;
    sensor_data_mutex = xSemaphoreCreateMutex();
    if (sensor_data_mutex == NULL)
    {
        ESP.LOGE(TAG, "mutex init error")
        return false;
    }
    return true;
}

mesurmentsToTanwa read_data(void)
{
    mesurmentsToTanwa new_data = {0.0, 0.0};
    if(xSemaphoreTake(sensor_data_mutex, portMAX_DELAY) == pdTRUE)
    {
        new_data.firstSensorData = sensor_data.firstSensorData;
        new_data.secondSensorData = sensor_data.secondSensorData;
        xSemaphoreGive(sensor_data_mutex);

    }
    return new_data;
}

void update_data(mesurmentsToTanwa *sesnorsDataToTanwa)
{
    if(xSemaphoreTake(sensor_data_mutex, portMAX_DELAY) == pdTRUE)
    {
        sensor_data.firstSensorData = sesnorsDataToTanwa->firstSensorData;
        sensor_data.secondSensorData = sesnorsDataToTanwa->secondSensorData;
        xSemaphoreGive(sensor_data_mutex);

    } 
}