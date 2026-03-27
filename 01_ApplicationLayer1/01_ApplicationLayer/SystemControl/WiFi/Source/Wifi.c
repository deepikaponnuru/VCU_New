 #include "Wifi_Int.h"
//  laxmi chougala
//hii
//hello

static Esp_State_E Esp_State = ESP_WAIT_HEADER1;

uint8_t Esp_DataBuf[ESP_MAX_DATA];
uint8_t Esp_DataLen = 0;
uint8_t PacketReady = 0;
uint8_t Esp_Cmd;
static uint8_t dataIndex = 0;

volatile Esp_PacketStatus_E Esp_PktStatus;

void Esp_Reset(void)
{
    Esp_State = ESP_WAIT_HEADER1;
    dataIndex = 0;
    Esp_DataLen = 0;
}


Esp_PacketStatus_E Esp_ParseByte(uint8_t byte)
{
    switch(Esp_State)
    {
       
        case ESP_WAIT_HEADER1:
            if (byte == ESP_HEADER1)
            {
                Esp_State = ESP_WAIT_HEADER2;
            }
            return Esp_PktIncomplete;

        case ESP_WAIT_HEADER2:
            if (byte == ESP_HEADER2)
            {
                Esp_State = ESP_WAIT_CMD;
            }
            else
            {
                Esp_Reset();
                return Esp_PktInvalid;
            }
            return Esp_PktIncomplete;

        case ESP_WAIT_CMD:
            Esp_Cmd = byte;
            Esp_State = ESP_WAIT_LEN;
            return Esp_PktIncomplete;

     
        case ESP_WAIT_LEN:
            if (byte == 0)
            {
                Esp_State = ESP_WAIT_CRC;
                return Esp_PktIncomplete;
            }
            else
            {
                dataIndex = 0;
                Esp_State = ESP_WAIT_DATA;
            }

            Esp_DataLen = byte + 1;

            if (Esp_DataLen > ESP_MAX_DATA)
            {
                Esp_Reset();
                return Esp_PktInvalid;
            }

            return Esp_PktIncomplete;

        case ESP_WAIT_DATA:

            Esp_DataBuf[dataIndex++] = byte;

            if (dataIndex == Esp_DataLen)
            {
                if (byte == Esp_CrcValue)   
                {
                    Esp_State = ESP_WAIT_FOOTER;
                }
                else
                {
                    Esp_Reset();
                    return Esp_PktInvalid;
                }
            }

            if (dataIndex < Esp_DataLen)
            {
                if (byte == ESP_FOOTER)   
                {
                    Esp_Reset();
                    return Esp_PktInvalid;
                }
            }

            return Esp_PktIncomplete;

        case ESP_WAIT_CRC:

            if (byte != Esp_CrcValue)
            {
                Esp_Reset();
                return Esp_PktInvalid;
            }

            Esp_State = ESP_WAIT_FOOTER;
            return Esp_PktIncomplete;

        case ESP_WAIT_FOOTER:
            if (byte == ESP_FOOTER)
            {
                Uart_Response(Esp_Cmd);
                Esp_Reset();
                return Esp_PktValid;
            }
            else
            {
                Esp_Reset();
                return Esp_PktInvalid;
            }

        default:
            Esp_Reset();
            return Esp_PktInvalid;
    }
}









// Esp_PacketStatus_E Esp_ParseByte(uint8_t byte)
// {
//     switch(Esp_State)
//     {
//         case ESP_WAIT_HEADER1:

//             if(byte == ESP_HEADER1)
//             {
//                 Esp_State = ESP_WAIT_HEADER2;
//             }

//         break;  

//         case ESP_WAIT_HEADER2:

//             if(byte == ESP_HEADER2)
//             {
//                 Esp_State = ESP_WAIT_CMD;
//             }
//             else
//             {
//                 Esp_Reset();
//                 return Esp_PktIncomplete;
//             }

//         break;

//         case ESP_WAIT_CMD:

//             Esp_Cmd = byte;
//             Esp_State = ESP_WAIT_LEN;
//             return Esp_PktIncomplete;

//         break;

//         case ESP_WAIT_LEN:
//             if(byte == 0)
//             {
//                 Esp_State = ESP_WAIT_CRC;
//             }
//             else
//             {
//                 dataIndex = 0;
//                 Esp_State = ESP_WAIT_DATA;
//             }
//             Esp_DataLen = byte;

//         break;

//         case ESP_WAIT_DATA:

//             Esp_DataBuf[dataIndex++] = byte;

//             if(dataIndex >= Esp_DataLen)
//             {
//                 Esp_State = ESP_WAIT_CRC;
//             }
//             if (dataIndex == Esp_DataLen)
//             {
//                 if(byte == Esp_CrcValue)
//                 {
//                     Esp_State = ESP_WAIT_FOOTER;
//                 }
//                 else
//                 {
//                     Esp_Reset();
                   
//                 }

//             }
//             if(dataIndex < Esp_DataLen)
//             {
//                 if(byte == ESP_WAIT_FOOTER)
//                 {
//                     Esp_Reset();
//                      return Esp_PktIncomplete;
                    
//                 }
//             }

//             Esp_DataBuf[dataIndex++] = byte;

//     if(dataIndex == Esp_DataLen)
//     {
//         Esp_State = ESP_WAIT_CRC;
//         return Esp_PktValid;
//     }
//     else 
//     {
//         return Esp_PktInvalid;
//     }

    

//         break;

//         case ESP_WAIT_CRC:

//             Esp_State = ESP_WAIT_FOOTER;

//         break;

//         case ESP_WAIT_FOOTER:

//             if(byte == ESP_FOOTER)
//             { 
//                 Uart_Response(Esp_Cmd);
//                 //PacketReady = 1;
//             }

//             Esp_Reset();

//         break;

//         default:
//             Esp_Reset();

//         break;
//     }
// }
