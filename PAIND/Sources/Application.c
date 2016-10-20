/*
 * Application.c
 *
 *  Created on: 29.09.2016
 *      Author: manuelwittmer
 */
#include "Application.h"				
#include "Huft_L.h"
#include "Huft_R.h"
#include "Knie_L.h"
#include "Knie_R.h"

#include "WAIT1.h"
#include "ROT.h"
#include "GRUN.h"
#include "BLAU.h"

#include "FRTOS1.h"
#include "Shell.h"
#include "Ultrasonic.h"

static void Measure(void) {
  uint16_t us, cm;
  uint8_t buf[8];

  us = US_Measure_us();
  UTIL1_Num16uToStrFormatted(buf, sizeof(buf), us, ' ', 5);

  cm = US_usToCentimeters(us, 22);
  UTIL1_Num16uToStrFormatted(buf, sizeof(buf), cm, ' ', 5);

  ROT_Put(cm<10); /* red LED if object closer than 10 cm */
}

static portTASK_FUNCTION(Task1, pvParameters) {
  (void)pvParameters; /* parameter not used */

  for(;;) {
	Measure();
	WAIT1_Waitms(1000);
	BLAU_Neg();
	FRTOS1_vTaskDelay(1000/portTICK_RATE_MS);
  }
}

void APP_Run(void){
	SHELL_Init();
	US_Init();
	ROT_Off();
	GRUN_Off();
	BLAU_Off();
	if (FRTOS1_xTaskCreate(
		Task1,  /* pointer to the task */
		"Task1", /* task name for kernel awareness debugging */
		configMINIMAL_STACK_SIZE, /* task stack size */
		(void*)NULL, /* optional task startup argument */
		tskIDLE_PRIORITY,  /* initial priority */
		(xTaskHandle*)NULL /* optional task handle to create */
	  ) != pdPASS) {
	/*lint -e527 */
	for(;;){}; /* error! probably out of memory */
	/*lint +e527 */
	}
	FRTOS1_vTaskStartScheduler();

	for(;;) {

	   Huft_L_SetPos(255);
	   Huft_R_SetPos(170);

	   Knie_L_SetPos(100);
	   Knie_R_SetPos(255);

	   Bein_L_SetPos(140);
	   Bein_R_SetPos(70);
	}
}
