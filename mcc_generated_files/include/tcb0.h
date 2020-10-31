/**
  @Company
    Microchip Technology Inc.

  @Description
    This Source file provides APIs.
    Generation Information :
    Driver Version    :   1.0.0
*/
/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/


#ifndef TCB0_H_INCLUDED
#define TCB0_H_INCLUDED

#include "../utils/compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

/* 8-bit PWM API's */  
typedef void (*pwm_irq_cb_t)(void);
#define TCB0_PWM_INTERRUPT_CB_RATE 0
typedef uint8_t TCB0_pwm_register_t;
void TCB0_PWM_Enable(void);
void TCB0_PWM_Disable(void);
void TCB0_load_counter(TCB0_pwm_register_t counter_value);
void TCB0_load_top(TCB0_pwm_register_t top_value);
void TCB0_load_duty_cycle(TCB0_pwm_register_t duty_value);
void TCB0_register_callback(pwm_irq_cb_t function);
/* end of 8-bit PWM API's */
int8_t TCB0_Initialize();
void TCB0_EnableCaptInterrupt(void);
void TCB0_DisableCaptInterrupt(void);
uint16_t TCB0_ReadTimer(void);
void TCB0_WriteTimer(uint16_t timerVal);
void TCB0_ClearCaptInterruptFlag(void);
bool TCB0_IsCaptInterruptEnabled();

#ifdef __cplusplus
}
#endif

#endif /* TCB0_H_INCLUDED */