/**
 * @file pinout.h
 * @author Michał Kos
 * @brief A header file with pinout description
 * @version 0.1
 * @date 2023-03-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PINOUT_HH
#define PINOUT_HH

// Boot
#define BOOT_BUTTON 0

// Leds
#define ESP_LED 5U
#define STATUS_LED 2U

// SPI
#define SPI_MISO 19U
#define SPI_MOSI 23U
#define SPI_SCK 18U

// UART
#define UART2_RX 16U
#define UART2_TX 17U

// Direct analog measurements
#define PRESSURE_MEASURE 35U
#define PRESSURE_ADC_CHANNEL 7U
#define VOLTAGE_MEASURE 39U
#define VOLTAGE_ADC_CHANNEL 3U
#define THERM_VENT_ADC 34U
#define THERM_VENT_ADC_CHANNEL 6U
#define THERM_SOLENOID_ADC 33U
#define THERM_SOLENOID_ADC_CHANNEL 5U

// Servo
#define SERVO_PWM_PIN 21U
#define SERVO_LIMIT_CLOSED 25U
#define SERVO_LIMIT_OPENED 26U
#define SERVO_POT_PIN 36U
#define POT_ADC_CHANNEL 0U

// Solenoid
#define SOLENOID_PIN 22U

// Thermocouples
#define THERMOCOUPLE_CS1 27U
#define THERMOCOUPLE_CS2 32U

// Flash memory
#define FLASH_CS 4U

#endif // PINOUT_HH