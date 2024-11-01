/**
 * @file config.h
 * @author Michał Kos
 * @brief A header with configuration of system and peripherals
 * @version 0.1
 * @date 2023-03-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef CONFIG_HH
#define CONFIG_HH

/**************************  VALVE SYSTEM  ************************************/

// #define MAIN_VALVE
#define VENT_VALVE

/**************************  ESP-NOW TEMPLATE  ********************************/

#define TEMPLATE_CMD
// #define TEMPLATE_FLASH

/**************************  RETURN STATUS  ***********************************/

#define RET_SUCCESS 0x00
#define RET_FAILURE 0x01

/**************************  COMMUNICATION  ***********************************/

/**************************  UART  ********************************************/

#define ROSALIA_UART_PORT_NUM 2
#define ROSALIA_UART_BAUD_RATE 115200
#define ROSALIA_UART_BUF_SIZE 1024

/************************** SERVO SETTINGS  ***********************************/

#define SERVO_MIN_PULSEWIDTH_US 500   // Minimum pulse width in microsecond
#define SERVO_MAX_PULSEWIDTH_US 2500  // Maximum pulse width in microsecond
#define SERVO_MIN_ANGLE 0             // Minimum angle
#define SERVO_MAX_ANGLE 180           // Maximum angle
#define SERVO_FREQUENCY_HZ 1000000  // frequency of the pwm signal for the servo
#define SERVO_TIMEBASE_PERIOD 20000  // 20000 ticks, 20ms

#define DEFAULT_POS_ANGLE 90  // angle of the default position for this servo

/**************************  VALVE SETTINGS  **********************************/

#define VALVE_CLOSE_POSITION 115U
#define VALVE_OPEN_POSITION 1U

#define POT_VALVE_OPEN_VALUE 0U
#define POT_VALVE_CLOSE_VALUE 860U

#define CLOSE_STATE 0U
#define OPEN_STATE 1U
#define BETWEEN_STATE 2U

/**************************  SENSORS SETTINGS  ********************************/

/**************************  VOLTAGE MEASUREMENT  *****************************/

#define VOL_REF 3.3
// voltage divider multiplier: R1 = 33k : R2 = 8.6k
#define DIV_MULTIPLIER_VOL 5.1216

/**************************  PRESSURE MEASUREMENT  ****************************/

// voltage divider
#define PRESSURE_R1 15000.0
#define PRESSURE_R2 30000.0
// pressure value at which the vent valve will automatically open
#define PRESSURE_MAX_SAFE 60
#define PRESSURE_RELEASE_TIME 200  // time of the automatic pressure vent

/**************************  THERMISTOR MEASUREMENT  **************************/

// resistor for a voltage divider with a termistor
#define TERMISTOR_RES_VALUE 22000.0
// Thermistor coefficients
#define THERMISTOR_A 0.001129148
#define THERMISTOR_B 0.000234125
#define THERMISTOR_C 0.0000000876741

#endif  // CONIFG_HH
