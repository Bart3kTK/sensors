#ifndef PWRINSPACE_SENSOR_APP
#define PWRINSPACE_SENSOR_APP

typedef struct {
    uint8_t Initialized;

    // Communication interfaces
    SPI_cfg mSPI;

    // ADCs
    adc_oneshot_unit_handle_t mADC_1;
    adc_cali_handle_t mADC_1_cali; //pressure tego uzywa
    bool mADC_1_cali_enabled

    // Pressure sensors
    Pressure_Sensor_t mPressure_1;
    Pressure_Sensor_t mPressure_2;


    // Temp sensors
    max31856_cfg thermocouple_1;
    max31856_cfg thermocouple_2;
} Hardware_Manager_t;



#endif