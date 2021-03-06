
/*
File:   pwm.c

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


#include "pwm.h"
#include "mcc_generated_files/include/port.h"

#define PC0 0

easypwm_irq_cb_t easyPWM_L_cb = NULL;
easypwm_irq_cb_t easyPWM_H_cb = NULL;

void easyPWM_init(sysclk_div clk){

	TCA0.SPLIT.CTRLD = 1 << TCA_SPLIT_SPLITM_bp; /* Split Mode : enabled */

//	TCA0.SPLIT.CTRLB = 0 << TCA_SPLIT_HCMP0EN_bp	/* High Compare 0 Enable: disabled */
//	                 | 0 << TCA_SPLIT_HCMP1EN_bp	/* High Compare 1 Enable: enabled */
//	                 | 0 << TCA_SPLIT_HCMP2EN_bp	/* High Compare 2 Enable: disabled */
//	                 | 0 << TCA_SPLIT_LCMP0EN_bp	/* Low Compare 0 Enable: disabled */
//	                 | 0 << TCA_SPLIT_LCMP1EN_bp	/* Low Compare 1 Enable: disabled */
//	                 | 0 << TCA_SPLIT_LCMP2EN_bp;	/* Low Compare 2 Enable: disabled */


//	TCA0.SPLIT.CTRLC = 0 << TCA_SPLIT_HCMP0OV_bp	/* High Compare 0 Output Value: disabled */
//	                 | 0 << TCA_SPLIT_HCMP1OV_bp	/* High Compare 1 Output Value: disabled */
//	                 | 0 << TCA_SPLIT_HCMP2OV_bp	/* High Compare 2 Output Value: disabled */
//	                 | 0 << TCA_SPLIT_LCMP0OV_bp	/* Low Compare 0 Output Value: disabled */
//	                 | 0 << TCA_SPLIT_LCMP1OV_bp	/* Low Compare 1 Output Value: disabled */
//	                 | 0 << TCA_SPLIT_LCMP2OV_bp;	/* Low Compare 2 Output Value: disabled */


//	TCA0.SPLIT.HCMP0 = 0x0; /* Compare value of channel 0: 0x0 */
//	TCA0.SPLIT.HCMP1 = 0x0; /* Compare value of channel 1: 0x0 */
//	TCA0.SPLIT.HCMP2 = 0x0; /* Compare value of channel 2: 0x0 */

//	TCA0.SPLIT.HCNT = 0x0; /*  High-byte Timer Counter Register: 0x0 */
//	TCA0.SPLIT.HPER = 0xff; /*  High-byte Period Register: 0xff */

//	TCA0.SPLIT.LCMP0 = 0x0; /* Compare value Channel 0: 0x0 */
//	TCA0.SPLIT.LCMP1 = 0x0; /* Compare value Channel 1: 0x0 */
//	TCA0.SPLIT.LCMP2 = 0x0; /* Compare value Channel 2: 0x0 */

//	TCA0.SPLIT.LCNT = 0x0; /* Low-byte Timer Counter Register: 0x0 */
//	TCA0.SPLIT.LPER = 0xff; /*  Low-byte Timer Period Register: 0xff */
	
//	TCA0.SPLIT.DBGCTRL = 0 << TCA_SINGLE_DBGRUN_bp; /* Debug Run: disabled */

//	TCA0.SPLIT.INTCTRL = 0 << TCA_SPLIT_HUNF_bp		/*High Underflow Interrupt Enable: disabled */
//	                   | 0 << TCA_SPLIT_LCMP0_bp	/* Low Compare 0 Interrupt Enable: disabled */
//	                   | 0 << TCA_SPLIT_LCMP1_bp	/* Low Compare 1 Interrupt Enable: disabled */
//	                   | 0 << TCA_SPLIT_LCMP2_bp	/* Low Compare 2 Interrupt Enable: disabled */
//	                   | 0 << TCA_SPLIT_LUNF_bp;	/* Low Underflow Interrupt Enable: disabled */

	TCA0.SPLIT.CTRLA = clk	                 /* System Clock */
	            | 1 << TCA_SPLIT_ENABLE_bp;  /* Module Enable: enabled */
}

void easyPWM_enable_DebugRun(void){
	TCA0.SPLIT.DBGCTRL = 1 << TCA_SINGLE_DBGRUN_bp; /* Debug Run: disabled */
}

void easyPWM_disable_DebugRun(void){
	TCA0.SPLIT.DBGCTRL = 0 << TCA_SINGLE_DBGRUN_bp; /* Debug Run: disabled */
}

void easyPWM_enable(void){
	TCA0.SPLIT.CTRLA |= TCA_SPLIT_ENABLE_bm;
}

void easyPWM_disable(void){
	TCA0.SPLIT.CTRLA &= ~TCA_SPLIT_ENABLE_bm;
}

void easyPWM_enable_output_ch0(void){
	TCA0.SPLIT.CTRLB |= (1 << TCA_SPLIT_LCMP0EN_bp);
}

void easyPWM_disable_output_ch0(void){
	TCA0.SPLIT.CTRLB &= ~(1 << TCA_SPLIT_LCMP0EN_bp);
}

void easyPWM_enable_output_ch1(void){
	TCA0.SPLIT.CTRLB |= (1 << TCA_SPLIT_LCMP1EN_bp);
}

void easyPWM_disable_output_ch1(void){
	TCA0.SPLIT.CTRLB &= ~(1 << TCA_SPLIT_LCMP1EN_bp);
}

void easyPWM_enable_output_ch2(void){
	TCA0.SPLIT.CTRLB |= (1 << TCA_SPLIT_LCMP2EN_bp);
}

void easyPWM_disable_output_ch2(void){
	TCA0.SPLIT.CTRLB &= ~(1 << TCA_SPLIT_LCMP2EN_bp);
}

void easyPWM_enable_output_ch3(void){
	TCA0.SPLIT.CTRLB |= (1 << TCA_SPLIT_HCMP0EN_bp);
}

void easyPWM_disable_output_ch3(void){
	TCA0.SPLIT.CTRLB &= ~(1 << TCA_SPLIT_HCMP0EN_bp);
}

void easyPWM_enable_output_ch4(void){
	TCA0.SPLIT.CTRLB |= (1 << TCA_SPLIT_HCMP1EN_bp);
}

void easyPWM_disable_output_ch4(void){
	TCA0.SPLIT.CTRLB &= ~(1 << TCA_SPLIT_HCMP1EN_bp);
}

void easyPWM_enable_output_ch5(void){
	TCA0.SPLIT.CTRLB |= (1 << TCA_SPLIT_HCMP2EN_bp);
}

void easyPWM_disable_output_ch5(void){
	TCA0.SPLIT.CTRLB &= ~(1 << TCA_SPLIT_HCMP2EN_bp);
}

void easyPWM_L_counter(uint8_t counter_value){
	TCA0.SPLIT.LCNT = counter_value;
}

void easyPWM_H_counter(uint8_t counter_value){
	TCA0.SPLIT.HCNT = counter_value;
}

void easyPWM_L_top(uint8_t top_value){
	TCA0.SPLIT.LPER = top_value;
}

void easyPWM_H_top(uint8_t top_value){
	TCA0.SPLIT.HPER = top_value;
}

void easyPWM_load_duty_cycle_ch0(uint8_t duty_value){
	TCA0.SPLIT.LCMP0 = duty_value;
}

void easyPWM_load_duty_cycle_ch1(uint8_t duty_value){
	TCA0.SPLIT.LCMP1 = duty_value;
}

void easyPWM_load_duty_cycle_ch2(uint8_t duty_value){
	TCA0.SPLIT.LCMP2 = duty_value;
}

void easyPWM_load_duty_cycle_ch3(uint8_t duty_value){
	TCA0.SPLIT.HCMP0 = duty_value;
}

void easyPWM_load_duty_cycle_ch4(uint8_t duty_value){
        if (duty_value == 0xFF){
        easyPWM_disable_output_ch4();
        easyPWM_disable();
        PORTD_set_pin_level(PD4, true);
    }
    else {
        easyPWM_enable_output_ch4();
        easyPWM_disable();
        TCA0.SPLIT.HCMP1 = duty_value;
        easyPWM_enable();
    }
}

void easyPWM_load_duty_cycle_ch5(uint8_t duty_value){
	TCA0.SPLIT.HCMP2 = duty_value;
}

void easyPWM_register_callback(easypwm_irq_cb_t f)
{
	easyPWM_L_cb = f;
	easyPWM_H_cb = f;
}

ISR(TCA0_LUNF_vect)
{
	static volatile uint8_t callback_count = 0;

	// Clear the interrupt flag
	TCA0.SPLIT.INTFLAGS = TCA_SPLIT_LUNF_bp;

	// callback function - called every 0 passes
	if ((++callback_count >= EASYPWM_INTERRUPT_CB_RATE) && (EASYPWM_INTERRUPT_CB_RATE != 0)) {
		if (easyPWM_L_cb != NULL) {
			easyPWM_L_cb();
		}
	}
}

ISR(TCA0_HUNF_vect)
{
	static volatile uint8_t callback_count = 0;

	// Clear the interrupt flag
	TCA0.SPLIT.INTFLAGS = TCA_SPLIT_HUNF_bp;

	// callback function - called every 0 passes
	if ((++callback_count >= EASYPWM_INTERRUPT_CB_RATE) && (EASYPWM_INTERRUPT_CB_RATE != 0)) {
		if (easyPWM_H_cb != NULL) {
			easyPWM_H_cb();
		}
	}
}

void PWM_TCB2_load_duty_cycle(uint8_t tcb2_duty_value){
    if (tcb2_duty_value == 0xFF){
        PWM_TCB2_disable_output();
        TCB2_PWM_Disable();
        PORTC_set_pin_level(PC0, true);
    }
    else {
        PWM_TCB2_enable_output();
        TCB2_PWM_Disable();
        TCB2_load_top(0xFF);
        TCB2_load_duty_cycle(tcb2_duty_value);
        TCB2_load_counter(0x00);
        TCB2_PWM_Enable();
    }
}

void PWM_TCB2_enable_output(void){
    TCB2.CTRLB |= TCB_CCMPEN_bm;
}

void PWM_TCB2_disable_output(void){
    TCB2.CTRLB &= ~TCB_CCMPEN_bm;
}