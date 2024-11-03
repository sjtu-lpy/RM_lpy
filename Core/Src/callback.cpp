//
// Created by 26279 on 24-10-2.
//
#include <spi.h>

#include "can.h"
#include "main.h"
#include "tim.h"
#include <stdio.h>
#include <string.h>
#include"dma.h"
#include "PID.h"

// void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
//     if(htim->Instance == htim6.Instance) {
//         HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin);
//     }
// }
//
// CAN_RxHeaderTypeDef rxHeader={516,0,0,0,8};
// uint8_t rxData[8],txData[8];
// uint32_t TxMAilBox;
// float Speed;
// float kp,kd,ki,set_speed,pp;
// PID pid(kp,ki,kd,2000.0,1000.0);
//
// int16_t GetSpeed(uint8_t speedH,uint8_t speedL) {
//     return (int16_t)((speedH << 8) | speedL);
// }
//
// void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan) {
//     if(hcan->Instance == hcan1.Instance) {
//         HAL_StatusTypeDef status;
//         status=HAL_CAN_GetRxMessage(hcan,CAN_RX_FIFO0,&rxHeader,rxData);
//         CAN_TxHeaderTypeDef txHeader = {512,0,0,0,8};
//         Speed = GetSpeed(rxData[2],rxData[3]);
//         memset(txData,0,sizeof(txData));
//         pp = pid.calculate(set_speed,Speed);
//         if(pp > 255) {
//             txData[7] = 255;
//             txData[6] = ((int)(pp - 255) >> 8);
//         }
//         else {
//             txData[7] = pp;
//         }
//         status=HAL_CAN_AddTxMessage(hcan,&txHeader,txData,&TxMAilBox);
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

// RC_ctl_type dbus_rx_data,a;
// float ans,k;
// float linear(uint16_t channel_data) {
//     k = 2.0 / 1320.0;
//     ans =  (channel_data - 1024) * k;
//     return ans;
// }
// float temp[4];
// void explain_data() {
//      dbus_rx_data.channel_.pre_channel[0] = (dbus_rx_data.RC.rx_data_[0] | (dbus_rx_data.RC.rx_data_[1] << 8)) & 0x07FF;
//      dbus_rx_data.channel_.pre_channel[1] = ((dbus_rx_data.RC.rx_data_[1] >> 3) | (dbus_rx_data.RC.rx_data_[2] << 5)) & 0x07FF;
//      dbus_rx_data.channel_.pre_channel[2] = ((dbus_rx_data.RC.rx_data_[2] >> 6) | (dbus_rx_data.RC.rx_data_[3] << 2) | (dbus_rx_data.RC.rx_data_[4] << 10)) & 0x07FF;
//      dbus_rx_data.channel_.pre_channel[3] = ((dbus_rx_data.RC.rx_data_[4] >> 1) | (dbus_rx_data.RC.rx_data_[5] << 7)) & 0x07FF;
//     for(int i = 0; i < 4; i++) {
//         dbus_rx_data.channel_.channel[i] = linear(dbus_rx_data.channel_.pre_channel[i]);
//         temp[i] = dbus_rx_data.channel_.channel[i];
//     }
//  }
//
// void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
//     uint8_t i;
//     if (huart->Instance == USART6) {
//         HAL_UART_Transmit_IT(huart, &i, sizeof(i));
//         HAL_UART_Receive_IT(huart, &i, sizeof(i));
//     }
//     if(huart->Instance == USART1) {
//         //HAL_UART_Receive_DMA(huart, dbus_rx_data.RC.rx_buf_, sizeof(dbus_rx_data.RC.rx_buf_));
//         for(int i = 0;i < 18; i++) {
//             dbus_rx_data.RC.rx_data_[i] = dbus_rx_data.RC.rx_buf_[i];
//         }
//         explain_data();
//     }
// }

