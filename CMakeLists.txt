set(srcs src/oa_battery.c src/oa_power.c src/oa_switches.c)

idf_component_register(SRCS "${srcs}"
INCLUDE_DIRS "include"
REQUIRES driver efuse esp32 esp_adc_cal esp_common esp_event 
esp_rom freertos heap log soc spiffs)