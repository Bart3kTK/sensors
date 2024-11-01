idf_component_register(SRC_DIRS "."
                    INCLUDE_DIRS "."
                    REQUIRES driver esp_adc hardware soc sensors utils )

target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-format" "-Wall" "-Werror")
