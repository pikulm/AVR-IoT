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


#include "../include/tcb2.h"

/**
 * \brief Initialize tcb interface
 *
 * \return Initialization status.
 */
pwm_irq_cb_t TCB2_pwm_cb= NULL;

ISR(TCB2_INT_vect)
{
	static volatile uint8_t callback_count = 0;

	// Clear the interrupt flag
	TCB2.INTFLAGS = TCB_CAPT_bm;

	// callback function - called every 0 passes
	if ((++callback_count >= TCB2_PWM_INTERRUPT_CB_RATE) && (TCB2_PWM_INTERRUPT_CB_RATE != 0)) {
		if (TCB2_pwm_cb!= NULL) {
			TCB2_pwm_cb();
		}
	}
}

/**
 * \brief Initialize TCB interface
 */
int8_t TCB2_Initialize()
{
    //Compare or Capture
    TCB2.CCMP = 0xFF;

    //Count
    TCB2.CNT = 0x00;

    //ASYNC disabled; CCMPINIT disabled; CCMPEN enabled; CNTMODE PWM8; 
    TCB2.CTRLB = 0x17;

    //DBGRUN disabled; 
    TCB2.DBGCTRL = 0x00;

    //FILTER disabled; EDGE disabled; CAPTEI disabled; 
    TCB2.EVCTRL = 0x00;

    //CAPT disabled; 
    TCB2.INTCTRL = 0x00;

    //CAPT disabled; 
    TCB2.INTFLAGS = 0x00;

    //Temporary Value
    TCB2.TEMP = 0x00;

    //RUNSTDBY disabled; SYNCUPD disabled; CLKSEL CLKDIV2; ENABLE enabled; 
    TCB2.CTRLA = 0x03;

    return 0;
}

void TCB2_WriteTimer(uint16_t timerVal)
{
	TCB2.CNT=timerVal;
}

uint16_t TCB2_ReadTimer(void)
{
	uint16_t readVal;

	readVal = TCB2.CNT;

	return readVal;
}

void TCB2_EnableCaptInterrupt(void)
{
	TCB2.INTCTRL |= TCB_CAPT_bm; /* Capture or Timeout: enabled */
}

void TCB2_DisableCaptInterrupt(void)
{
	TCB2.INTCTRL &= ~TCB_CAPT_bm; /* Capture or Timeout: disabled */

}

inline void TCB2_ClearCaptInterruptFlag(void)
{
	TCB2.INTFLAGS &= ~TCB_CAPT_bm;

}

inline bool TCB2_IsCaptInterruptEnabled(void)
{
        return ((TCB2.INTCTRL & TCB_CAPT_bm) > 0);
}

/* 8-bit PWM API's */      
void TCB2_PWM_Enable(void)
{
    TCB2.CTRLA |= TCB_ENABLE_bm;
}

void TCB2_PWM_Disable(void)
{
    TCB2.CTRLA &= ~TCB_ENABLE_bm;
}

void TCB2_load_counter(TCB2_pwm_register_t counter_value)
{
    TCB2.CNT = counter_value;
}

void TCB2_load_top(TCB2_pwm_register_t top_value)
{
    TCB2.CCMPL = top_value;
}

void TCB2_load_duty_cycle(TCB2_pwm_register_t duty_value)
{
	TCB2.CTRLA &= ~TCB_ENABLE_bm;
	TCB2.CCMPH = duty_value;
	TCB2.CNT   = 0;
	TCB2.CTRLA |= TCB_ENABLE_bm;
}

void TCB2_register_callback(pwm_irq_cb_t function)
{
	TCB2_pwm_cb= function;
}

