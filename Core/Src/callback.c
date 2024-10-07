//
// Created by 26279 on 24-10-2.
//
#include "main.h"
#include "tim.h"

//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    //if(htim->Instance == htim6.Instance) {
      //  HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin);
    //}
//}
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
/*void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    uint8_t i;
    if (huart->Instance == USART6) {
        HAL_UART_Transmit_IT(huart, &i, sizeof(i));
        HAL_UART_Receive_IT(huart, &i, sizeof(i));
    }
}*/