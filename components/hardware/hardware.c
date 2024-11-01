#include <stdbool.h>
#include <stdint.h>
#include "hardware.h"


#define TAG "TANWA_SENSORS_HARDWARE"


// #define TEMPERATURA jest_pijana_no_i_buja_sie_po_klubach

static Hardware_Manager_t HardwareInstance;

static bool adc_calibration_init() {
  adc_cali_handle_t handle = NULL;
  esp_err_t ret = ESP_FAIL;
  bool calibrated = false;

  if (!calibrated) {
    ESP_LOGI(TAG, "calibration scheme version is %s", "Line Fitting");
    adc_cali_line_fitting_config_t cali_config = {
        .unit_id = ADC_UNIT_1,
        .atten = ADC_ATTEN_PRESSURE,
        .bitwidth = ADC_BITWIDTH_DEFAULT,
    };
    ret = adc_cali_create_scheme_line_fitting(&cali_config, &handle);
    if (ret == ESP_OK) {
      calibrated = true;
    }
  }

  HardwareInstance.mADC_1_cali = handle;
  if (ret == ESP_OK) {
    ESP_LOGI(TAG, "Calibration Success");
  } else if (ret == ESP_ERR_NOT_SUPPORTED || !calibrated) {
    ESP_LOGW(TAG, "eFuse not burnt, skip software calibration");
  } else {
    ESP_LOGE(TAG, "Invalid arg or no memory");
  }

  return calibrated;
}

bool hardware_get_instance(Hardware_Manager_t **InstancePtr) {
  if (HardwareInstance.Initialized != 1) {
    ESP_LOGE(TAG, "Couldn't get hardware instance - not initialized");
    InstancePtr = NULL;
    return false;
  }
  *InstancePtr = &HardwareInstance;
  return true;
}



bool hardware_init()
{
    // ### COMMUNICATION INIT ###
    SPI_init(&HardwareInstance.mSPI, VSPI_HOST, SPI_MOSI, SPI_MISO, SPI_SCK);
    // ### ADC1 INIT ###
    adc_oneshot_unit_init_cfg_t adc_init_config_1 = {
        .unit_id = ADC_UNIT_1,
    };
    ESP_ERROR_CHECK(
        adc_oneshot_new_unit(&adc_init_config_1, &HardwareInstance.mADC_1));
    HardwareInstance.mADC_1_cali_enabled = adc_calibration_init();
    // ### THERMOCOUPLES INIT ###
    #ifdef TEMPERATURA

        ESP_LOGI(TAG, "Thermocouple initialization...");
        max31856_init(&HardwareInstance.thermocouple_1, THERMOCOUPLE_CS1); 
        max31856_init(&HardwareInstance.thermocouple_2, THERMOCOUPLE_CS2);
        ESP_LOGI(TAG, "Thermocouple set type...");
        thermocouple_set_type(&HardwareInstance.thermocouple_1, MAX31856_TCTYPE_K);
        thermocouple_set_type(&HardwareInstance.thermocouple_2, MAX31856_TCTYPE_K);
        ESP_LOGI(TAG, "Thermocouple read fault...");
        thermocouple_read_fault(&HardwareInstance.thermocouple_1, true);
        thermocouple_read_fault(&HardwareInstance.thermocouple_2, true);
    #else
        HardwareInstance.mPressure_1 = (Pressure_Sensor_t)PRESSURE_SENSOR_INIT(
        PRESSURE_ADC_CHANNEL, &HardwareInstance.mADC_1,
        &HardwareInstance.mADC_1_cali, HardwareInstance.mADC_1_cali_enabled);

        HardwareInstance.mPressure_2 = (Pressure_Sensor_t)PRESSURE_SENSOR_INIT(
        PRESSURE_ADC_CHANNEL, &HardwareInstance.mADC_1,
        &HardwareInstance.mADC_1_cali, HardwareInstance.mADC_1_cali_enabled);
        
        ESP_LOGI(TAG, "Pressure sensors initialization...");
        pressure_sensor_init(&HardwareInstance.mPressure_1);
        pressure_sensor_init(&HardwareInstance.mPressure_2);

    #endif
  // ### SET INITIALIZED FLAG ###
  HardwareInstance.Initialized = 1;
  return true;
}