#ifndef PWRINSPACE_SENSOR_APP
#define PWRINSPACE_SENSOR_APP

#include <stdbool.h>
#include "max31856.h"
#include "pressure_sensor.h"
#include "spi.h"
#include "esp_adc/adc_cali.h"
#include "esp_adc/adc_cali_scheme.h"
#include "esp_adc/adc_oneshot.h"


typedef struct {
    uint8_t Initialized;

    // Communication interfaces
    SPI_cfg mSPI;

    // ADCs
    adc_oneshot_unit_handle_t mADC_1;
    adc_cali_handle_t mADC_1_cali; 
    bool mADC_1_cali_enabled;

    // Pressure sensors
    Pressure_Sensor_t mPressure_1;
    Pressure_Sensor_t mPressure_2;

    // Temp sensors
    max31856_cfg thermocouple_1;
    max31856_cfg thermocouple_2;

} Hardware_Manager_t;


bool hardware_get_instance(Hardware_Manager_t **InstancePtr);
bool hardware_init();
static bool adc_calibration_init();


#endif