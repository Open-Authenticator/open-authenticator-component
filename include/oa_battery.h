#ifndef OA_BATTERY_H
#define OA_BATTERY_H

#include "freertos/FreeRTOS.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"
#include "esp_log.h"
#include "esp_err.h"
#include "oa_pin_defs.h"

#define DEFAULT_VREF    1100       

/**
 * @brief This array contains voltage values at various battery capacity. Values generated from battery's datasheet
 * 
 */
const static float voltage_vs_capacity[] = {4.15, 2.75};

/**
 * @brief Configure width and attenuation of ADC 1
 * 
 * @return esp_err_t - returns ESP_OK if 11dB attenuation and 12 bit width configured to ADC 1, else it returns ESP_ERR_INVALID_ARG.  
 */
esp_err_t config_adc1();

/**
 * @brief Characterize ADC 1 using either Vref or Two Point
 * 
 * @return esp_err_t 
 **/
esp_err_t characterize_adc1();

/**
 * @brief This function computes the battery percentage, by interpolating based on the battery discharge curve
 * 
 * @return int Returns the battery percentage
 */
float battery_percentage();

#endif