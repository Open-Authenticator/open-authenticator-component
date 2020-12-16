#include "oa_switches.h"

static const char* TAG_SWITCHES = "switches";
static int init_switches_flag = 0;

esp_err_t init_switches()
{
    gpio_config_t io_conf;
    // bit mask for the pins, each bit maps to a GPIO 
    io_conf.pin_bit_mask = ((1ULL<<SWITCH_UP) | (1ULL<<SWITCH_DOWN) | (1ULL<<SWITCH_SELECT));
    // set gpio mode to input
    io_conf.mode = GPIO_MODE_INPUT;
    // enable pull up resistors
    io_conf.pull_up_en = 1;
    // disable pull down resistors
    io_conf.pull_down_en = 0;
    // disable gpio interrupts
    io_conf.intr_type = GPIO_INTR_DISABLE;
    // detailed description can be found at https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/gpio.html#_CPPv413gpio_config_t

    esp_err_t err = gpio_config(&io_conf);
    if (err == ESP_OK)
    {
        ESP_LOGI(TAG_SWITCHES, "enabled switches");
        init_switches_flag = 1;
    }
    else
    {
        ESP_LOGE(TAG_SWITCHES, "error: %s", esp_err_to_name(err));
        init_switches_flag = 0;
    }

    return err;
}

int read_switch(int switch_id)
{
    if (init_switches_flag)
    {
        return !gpio_get_level((gpio_num_t)switch_id);
    }
    else
    {
        ESP_LOGE(TAG_SWITCHES, "error: switches not enabled, call enable_switches() before reading switches");
        return 0;
    }
}
