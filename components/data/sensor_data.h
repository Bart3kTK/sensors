#ifndef PWRINSPACE_SENSOR_DATA
#define PWRINSPACE_SENSOR_DATA

typedef struct {
    float firstSensorData;
    float secondSensorData;
} mesurmentsToTanwa;

SemaphoreHandle_t sensor_data_mutex;
mesurmentsToTanwa sensor_data;

void update_data(mesurmentsToTanwa *sesnorsDataToTanwa);
mesurmentsToTanwa read_data(void);
void data_init(void);


#endif