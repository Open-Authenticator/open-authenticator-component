#ifndef OA_POWER_H
#define OA_POWER_H

#include "oa_pin_defs.h"

#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_err.h"
#include "oa_pin_defs.h"

/**
 * @brief Initialise the gpio which controls load switch, pin shouldn't be left floating so, pulldown resistor will be enabled
 * 
 * @return esp_err_t returns ESP_OK if gpio's initialised, else it returns ESP_ERR_INVALID_ARG 
 */
esp_err_t init_load_switch();

/**
 * @brief Activates the load switch and thus powering on the OLED and RTC connected to it. Load switch is active high
 * 
 * @return int returns the state of the load switch
 */
int activate_load_switch();

/**
 * @brief Deactivates the load switch and thus powering off the OLED and RTC connected to it.
 * 
 * @return int returns the state of the load switch
 */
int deactivate_load_switch();

/**
 * @brief Reads the state of load switch
 * 
 * @return int returns the value of the static variable load_switch_state
 */
int read_state_load_switch();
#endif