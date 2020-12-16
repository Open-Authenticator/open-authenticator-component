#include "oa_power.h"

static const char* TAG_POWER = "load_switch";

/**
 * @brief stores the state of load switch
 * 
 */
static int load_switch_state = 0;

esp_err_t init_load_switch()
{
    gpio_config_t io_conf;
    // bit mask for the pins, each bit maps to a GPIO 
    io_conf.pin_bit_mask = 1ULL << LOAD_SWITCH;
    // set gpio mode to input
    io_conf.mode = GPIO_MODE_OUTPUT;
    // enable pull up resistors
    io_conf.pull_up_en = 0;
    // disable pull down resistors
    io_conf.pull_down_en = 1;
    // disable gpio interrupts
    io_conf.intr_type = GPIO_INTR_DISABLE;
    // detailed description can be found at https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/gpio.html#_CPPv413gpio_config_t

    esp_err_t err = gpio_config(&io_conf);
    if (err == ESP_OK)
    {
        ESP_LOGI(TAG_POWER, "enabled load switch");
        load_switch_state = 1;
    }
    else
    {
        ESP_LOGE(TAG_POWER, "error: %s", esp_err_to_name(err));
        load_switch_state = 0;
    }

    return err;
}

int activate_load_switch()
{
    return gpio_set_level((gpio_num_t)LOAD_SWITCH, 1);
}

int deactivate_load_switch()
{
    return gpio_set_level((gpio_num_t)LOAD_SWITCH, 0);
}

int read_state_load_switch()
{
    return load_switch_state;
}
