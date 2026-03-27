#ifndef WIFI_EXT_H_
#define WIFI_EXT_H_

#include "driverlib.h"
#include "device.h"

typedef enum
{
    ESP_WAIT_HEADER1,
    ESP_WAIT_HEADER2,
    ESP_WAIT_CMD,
    ESP_WAIT_LEN,
    ESP_WAIT_DATA,
    ESP_WAIT_CRC,
    ESP_WAIT_FOOTER
}Esp_State_E;

typedef enum
{
    Esp_PktInvalid=0,
    Esp_PktIncomplete,
    Esp_PktValid
} Esp_PacketStatus_E;

extern volatile Esp_PacketStatus_E Esp_PktStatus; 

Esp_PacketStatus_E Esp_ParseByte(uint8_t byte);
void Esp_Reset(void);

#endif
