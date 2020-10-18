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

#include "mcc_generated_files/application_manager.h"
#include "mcc_generated_files/include/port.h"
#include "pwm.h"

#define PD3 3	// blue led (WIFI)
#define PD4 4	// pwm pin on mikroBUS header

int main(void)
{
    application_init();
    PORTD_set_pin_dir(PD3, PORT_DIR_OUT);
	PORTD_set_pin_level(PD3, false);
	PORTMUX.TCAROUTEA |= (PORTMUX_TCA00_bm | PORTMUX_TCA01_bm);

	PORTD_set_pin_dir(PD4, PORT_DIR_OUT);
	PORTD_set_pin_level(PD4, false);
	PORTMUX.TCAROUTEA |= (PORTMUX_TCA00_bm | PORTMUX_TCA01_bm);


	/* Replace with your application code */
	easyPWM_init(SYSCLK_DIV_64);
	easyPWM_load_duty_cycle_ch3(0x80);
	easyPWM_load_duty_cycle_ch4(0x80);
	easyPWM_enable_output_ch3();
	easyPWM_enable_output_ch4();
	uint16_t duty_cycle = 0x00;
  
    while (1)
   { 
      runScheduler();  
      	for (int i=0; i<1000; i++)
		for (int j=0; j<100; j++);
		easyPWM_load_duty_cycle_ch3(duty_cycle);
		easyPWM_load_duty_cycle_ch4(duty_cycle);
		duty_cycle += 0x10;
   }
   
   return 0;
}
