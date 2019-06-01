#include <stdbool.h>
#include <stdint.h>

#include "nrf_delay.h"//функции задержки
#include "nrf_gpio.h"//драйвер gpio
#include "pstorage.h"
#include "app_pwm.h"
#include "app_timer.h"
#include "ble_nus.h"

#include "main.h"
#include "ble_config.h"


APP_PWM_INSTANCE( PWM1, 1); // Create the instance "PWM1" using TIMER1.


void nus_data_handler(ble_nus_t * p_nus, uint8_t * p_data, uint16_t length)
{   
    switch(p_data[0])
    {
        case '1':
        {
            nrf_gpio_pin_toggle(LED1);
            app_pwm_disable(&PWM1);
        }break;
//        case '2': nrf_gpio_pin_toggle(LED_2); break;
        case '3':
        {
            app_pwm_enable(&PWM1);
            app_pwm_channel_duty_set(&PWM1, 0, 15);
            nrf_gpio_pin_toggle(LED1);
        }break;
//        case '4': nrf_gpio_pin_toggle(LED_4); break;
    }
}


int main(void)
{
    ret_code_t err_code;
    
    pstorage_init();
    nrf_gpio_cfg_output(LED0);
    nrf_gpio_cfg_output(LED1);
          
    // Initialize.
    APP_TIMER_INIT(APP_TIMER_PRESCALER, APP_TIMER_OP_QUEUE_SIZE, false);
    
    ble_stack_init();
    gap_params_init();
    services_init();
    advertising_init();
    conn_params_init();
    
    err_code = ble_advertising_start(BLE_ADV_MODE_FAST);
    APP_ERROR_CHECK(err_code);

    //------------ PWM Config ---------------------
    /* 1-channel PWM, 200Hz, output on DK LED pins. */
    app_pwm_config_t pwm1_cfg = APP_PWM_DEFAULT_CONFIG_1CH(1000, MCTRL);
    /* Switch the polarity of the second channel. */
    pwm1_cfg.pin_polarity[0] = APP_PWM_POLARITY_ACTIVE_HIGH;
    
    /* Initialize and enable PWM. */
    err_code = app_pwm_init(&PWM1,&pwm1_cfg, NULL);
    APP_ERROR_CHECK(err_code);
//    app_pwm_enable(&PWM1);
//    
//    uint32_t value = 15;
//    app_pwm_channel_duty_set(&PWM1, 0, value);
    //--------------------------------------------    
    
    nrf_gpio_pin_toggle(LED0); 
    
    while(1)
    {
        nrf_gpio_pin_toggle(LED0);
        nrf_delay_ms(250);
    }
}
