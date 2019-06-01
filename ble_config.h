#ifndef BLE_CONFIG_H
#define BLE_CONFIG_H

#include <stdint.h>

#include "ble_nus.h"
#include "ble_conn_params.h"
#include "ble_advertising.h"
#include "bsp.h"

#define DEVICE_NAME                     "Nordic_UART"                               /**< Name of device. Will be included in the advertising data. */
#define NUS_SERVICE_UUID_TYPE           BLE_UUID_TYPE_VENDOR_BEGIN                  /**< UUID type for the Nordic UART Service (vendor specific). */

void assert_nrf_callback(uint16_t line_num, const uint8_t * p_file_name);

void gap_params_init(void);

//void nus_data_handler(ble_nus_t * p_nus, uint8_t * p_data, uint16_t length);
    
void services_init(void);

void on_conn_params_evt(ble_conn_params_evt_t * p_evt);
void conn_params_error_handler(uint32_t nrf_error);

void conn_params_init(void);

void on_adv_evt(ble_adv_evt_t ble_adv_evt);
void on_ble_evt(ble_evt_t * p_ble_evt);
void ble_evt_dispatch(ble_evt_t * p_ble_evt);

void ble_stack_init(void);
void bsp_event_handler(bsp_event_t event);
void advertising_init(void);


#endif
