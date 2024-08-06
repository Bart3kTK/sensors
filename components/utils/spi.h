#ifndef SPI_SIMPLE_H
#define SPI_SIMPLE_H

#include "driver/spi_master.h"

typedef struct {
    spi_bus_config_t spi_bus;
    spi_host_device_t spi_host;
} SPI_cfg;

bool SPI_init(SPI_cfg *spi, spi_host_device_t host, uint8_t mosi, uint8_t miso, uint8_t sck);

// bool SPI_1_read(uint8_t cs_pin, uint8_t *data, size_t len);

// bool SPI_1_write(uint8_t cs_pin, uint8_t *data, size_t len);

#endif