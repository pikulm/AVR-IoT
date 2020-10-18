
/*
 * File:   pwm.c
 * Author: magdalenapikul
 *
 * Created on October 18, 2020, 6:33 PM
 */


#include "pwm.h"

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
	TCA0.SPLIT.HCMP1 = duty_value;
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
