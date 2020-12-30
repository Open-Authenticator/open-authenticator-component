#include "oa_battery.h"

const static char *TAG_ADC = "ADC";
static esp_adc_cal_characteristics_t adc_chars;

esp_err_t config_adc1()
{
    // Configure ADC to 12 bit width
    adc1_config_width(ADC_WIDTH_BIT_12);
    
    // Configure ADC to 11dB attenuation
    adc1_config_channel_atten(ADC_CHANNEL_0, ADC_ATTEN_DB_11);
    adc1_config_channel_atten(ADC_CHANNEL_3, ADC_ATTEN_DB_11);
    adc1_config_channel_atten(ADC_CHANNEL_6, ADC_ATTEN_DB_11);
    adc1_config_channel_atten(ADC_CHANNEL_7, ADC_ATTEN_DB_11);

    ESP_LOGI(TAG_ADC, "Configured ADC_1 to 12 Bit and 11dB attenuation");

    return ESP_OK;
}

esp_err_t characterize_adc1()
{
    esp_adc_cal_value_t val_type = esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, DEFAULT_VREF, &adc_chars);
       
    if (val_type == ESP_ADC_CAL_VAL_EFUSE_TP) 
	{   
        ESP_LOGI(TAG_ADC, "eFuse Two Point: Supported");
        ESP_LOGI(TAG_ADC, "Characterized using Two Point Value");
    } 
    else if (val_type == ESP_ADC_CAL_VAL_EFUSE_VREF) 
    {   
        ESP_LOGI(TAG_ADC, "eFuse Vref: Supported");
        ESP_LOGI(TAG_ADC, "Characterized using eFuse Vref");
    } 
    else 
    {
        ESP_LOGI(TAG_ADC, "Characterized using Default Vref");
    }
    return ESP_OK;
}

float battery_percentage()
{
    return 2*((float)esp_adc_cal_raw_to_voltage(adc1_get_raw(ADC1_CHANNEL_7), &adc_chars))/1000;
}
