#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"//функции задержки
#include "nrf_gpio.h"//драйвер gpio

#define LED0 (18)//в скобках номер пина
#define LED1 (19)//пины подключены к светодиодам
#define LED2 (20)//на плате BE400
#define LED3 (21)
#define LED4 (22)
 
 int main(void)
{
  //Выводы на выход
  nrf_gpio_cfg_output(LED0);
  nrf_gpio_cfg_output(LED1);
  nrf_gpio_cfg_output(LED2);
  nrf_gpio_cfg_output(LED3);
  nrf_gpio_cfg_output(LED4);
  
  while(true)
  {
    nrf_gpio_pin_clear(LED0);
    nrf_gpio_pin_set(LED1);
		nrf_gpio_pin_clear(LED2);
    nrf_gpio_pin_set(LED3);
		nrf_gpio_pin_clear(LED4);
    
    nrf_delay_ms(500);
   
    nrf_gpio_pin_set(LED0);
		nrf_gpio_pin_clear(LED1);
		nrf_gpio_pin_set(LED2);
		nrf_gpio_pin_clear(LED3);
		nrf_gpio_pin_set(LED4);
    
    nrf_delay_ms(500);
  }
}
