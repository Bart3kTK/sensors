idf_component_register(SRC_DIRS "."
                    INCLUDE_DIRS "."
                    REQUIRES esp_timer freertos esp_adc data esp_now utils sensors )

target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-format" "-Wall" "-Werror")
