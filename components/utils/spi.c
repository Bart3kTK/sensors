#include "spi.h"

#include "esp_log.h"

static const char *TAG = "SPI";

bool SPI_init(SPI_cfg *spi, spi_host_device_t host, uint8_t mosi, uint8_t miso, uint8_t sck) {
    esp_err_t ret;
    spi->spi_bus.mosi_io_num = mosi;
    spi->spi_bus.miso_io_num = miso;
    spi->spi_bus.sclk_io_num = sck;
    spi->spi_bus.quadwp_io_num = -1;
    spi->spi_bus.quadhd_io_num = -1;
    spi->spi_bus.max_transfer_sz = 0; //4092;
    spi->spi_host = host;

    ret = spi_bus_initialize(spi->spi_host, &spi->spi_bus, 0);
    if(ret == ESP_OK){
        ESP_LOGI(TAG, "SPI bus initialized");
    } else {
        ESP_LOGE(TAG, "SPI bus initialization failed");
        return false;
    }
    return ret;
}

// bool SPI_transmit(uint8_t *tx_data, size_t tx_len, uint8_t *rx_data, size_t rx_len) {
//     esp_err_t ret;
//     spi_transaction_t spi_transaction;
//     memset(&spi_transaction, 0, sizeof(spi_transaction_t));

//     spi_transaction.flags = SPI_TRANS_USE_RXDATA;
//     spi_transaction.length = 8;
//     spi_transaction.tx_buffer = tx_data;
//     ret = spi_device_transmit(spi_handle, &spi_transaction);

//     return ret == ESP_OK ? true : false;
// }
