/*
File:   pwm.h

Created on October 18, 2020, 6:33 PM

MIT License

Copyright (c) 2019 mahmood-ul-hassan

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */


#ifndef PWM_H_
#define PWM_H_

#ifdef __cplusplus
extern "C" {
#endif
    
#include "mcc_generated_files/utils/compiler.h"
#include "mcc_generated_files/include/tcb2.h"

typedef uint8_t sysclk_div;
typedef void (*easypwm_irq_cb_t)(void);

#define EASYPWM_INTERRUPT_CB_RATE 0
#define PD4 4	// pwm pin on mikroBUS header

enum {
	SYSCLK_DIV_1	= TCA_SPLIT_CLKSEL_DIV1_gc,		// SYSCLK / 1
	SYSCLK_DIV_2	= TCA_SPLIT_CLKSEL_DIV2_gc,		// SYSCLK / 2
	SYSCLK_DIV_4	= TCA_SPLIT_CLKSEL_DIV4_gc,		// SYSCLK / 4
	SYSCLK_DIV_8	= TCA_SPLIT_CLKSEL_DIV8_gc,		// SYSCLK / 8
	SYSCLK_DIV_16	= TCA_SPLIT_CLKSEL_DIV16_gc,	// SYSCLK / 16
	SYSCLK_DIV_64	= TCA_SPLIT_CLKSEL_DIV64_gc,	// SYSCLK / 64
	SYSCLK_DIV_256	= TCA_SPLIT_CLKSEL_DIV256_gc,	// SYSCLK / 256
	SYSCLK_DIV_1024	= TCA_SPLIT_CLKSEL_DIV1024_gc,	// SYSCLK / 1024
};

// initialize TCA in split mode with clk clock
void easyPWM_init(sysclk_div clk);

void easyPWM_enable(void);
void easyPWM_disable(void);

void easyPWM_enable_DebugRun(void);
void easyPWM_disable_DebugRun(void);

void easyPWM_enable_output_ch0(void);
void easyPWM_disable_output_ch0(void);

void easyPWM_enable_output_ch1(void);
void easyPWM_disable_output_ch1(void);

void easyPWM_enable_output_ch2(void);
void easyPWM_disable_output_ch2(void);

void easyPWM_enable_output_ch3(void);
void easyPWM_disable_output_ch3(void);

void easyPWM_enable_output_ch4(void);
void easyPWM_disable_output_ch4(void);

void easyPWM_enable_output_ch5(void);
void easyPWM_disable_output_ch5(void);

void easyPWM_L_counter(uint8_t counter_value);
void easyPWM_H_counter(uint8_t counter_value);

void easyPWM_L_top(uint8_t top_value);
void easyPWM_H_top(uint8_t top_value);

void easyPWM_load_duty_cycle_ch0(uint8_t duty_value);
void easyPWM_load_duty_cycle_ch1(uint8_t duty_value);
void easyPWM_load_duty_cycle_ch2(uint8_t duty_value);
void easyPWM_load_duty_cycle_ch3(uint8_t duty_value);
void easyPWM_load_duty_cycle_ch4(uint8_t duty_value);
void easyPWM_load_duty_cycle_ch5(uint8_t duty_value);

void easyPWM_register_callback(easypwm_irq_cb_t f);

void PWM_TCB2_load_duty_cycle(uint8_t tcb2_duty_value);
void PWM_TCB2_enable_output(void);
void PWM_TCB2_disable_output(void);





#ifdef __cplusplus
}
#endif

#endif /* PWM_H_ */