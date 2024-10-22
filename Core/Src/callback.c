//
// Created by 26279 on 24-10-2.
//
#include "can.h"
#include "main.h"
#include "tim.h"
#include <stdio.h>
#include <string.h>
#include"dma.h"

// void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
//     if(htim->Instance == htim6.Instance) {
//         HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin);
//     }
// }

// CAN_RxHeaderTypeDef rxHeader={514,0,0,0,8};
// uint8_t rxData[8];
// uint8_t TxMAilBox;;
// uint32_t Speed;
//
// uint32_t GetSpeed(uint8_t speedH,uint8_t speedL) {
//     return ((speedH << 8) + speedL);
// }

// void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan) {
//     if(hcan->Instance == hcan1.Instance) {
//         HAL_StatusTypeDef status;
//         //status=HAL_CAN_GetRxMessage(hcan,CAN_RX_FIFO0,&rxHeader,rxData);
//         CAN_RxHeaderTypeDef rxHeader = {512,0,0,0,8};
//         // Speed = GetSpeed(rxData[2],rxData[3]);
//         // memset(rxData,0,sizeof(rxData));
//         // if(Speed >= 1000) rxData[3] = 0;
//         // else rxData[3] = 112;
//         rxData[3] = 50;
//         status=HAL_CAN_AddTxMessage(hcan,&rxHeader,rxData,&TxMAilBox);
//     }
// }
//int a = 0;
/*void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if (GPIO_Pin == KEY_Pin) {
        if(1) {
            HAL_TIM_PWM_Start_IT(&htim1, TIM_CHANNEL_1);
           // a = 1;
        }
        else {
            HAL_TIM_PWM_Stop_IT(&htim1, TIM_CHANNEL_1);
						//a = 0;
        }
    }
}*/

RC_ctl_type dbus_rx_data,a;
float ans,k;
float linear(uint16_t channel_data) {
    k = 2.0 / 1320.0;
    ans =  (channel_data - 1024) * k;
    return ans;
}
float temp[4];
void explain_data() {
     dbus_rx_data.channel_.pre_channel[0] = (dbus_rx_data.RC.rx_data_[0] | (dbus_rx_data.RC.rx_data_[1] << 8)) & 0x07FF;
     dbus_rx_data.channel_.pre_channel[1] = ((dbus_rx_data.RC.rx_data_[1] >> 3) | (dbus_rx_data.RC.rx_data_[2] << 5)) & 0x07FF;
     dbus_rx_data.channel_.pre_channel[2] = ((dbus_rx_data.RC.rx_data_[2] >> 6) | (dbus_rx_data.RC.rx_data_[3] << 2) | (dbus_rx_data.RC.rx_data_[4] << 10)) & 0x07FF;
     dbus_rx_data.channel_.pre_channel[3] = ((dbus_rx_data.RC.rx_data_[4] >> 1) | (dbus_rx_data.RC.rx_data_[5] << 7)) & 0x07FF;
    for(int i = 0; i < 4; i++) {
        dbus_rx_data.channel_.channel[i] = linear(dbus_rx_data.channel_.pre_channel[i]);
        temp[i] = dbus_rx_data.channel_.channel[i];
    }
 }

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    uint8_t i;
    if (huart->Instance == USART6) {
        HAL_UART_Transmit_IT(huart, &i, sizeof(i));
        HAL_UART_Receive_IT(huart, &i, sizeof(i));
    }
    if(huart->Instance == USART1) {
        HAL_UART_Receive_DMA(huart, dbus_rx_data.RC.rx_buf_, sizeof(dbus_rx_data.RC.rx_buf_));
        for(int i = 0;i < 18; i++) {
            dbus_rx_data.RC.rx_data_[i] = dbus_rx_data.RC.rx_buf_[i];
        }
        explain_data();
    }
}