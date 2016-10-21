/*
 * Pins.c
 *
 *  Created on: 21.10.2016
 *      Author: manuelwittmer
 */
#include "WAIT1.h"
#include "Application.h"
#include "FRTOS1.h"

#include "ROT.h"
#include "GRUN.h"
#include "BLAU.h"

#include "Buzzer.h"
#include "Switch_A.h"
#include "Switch_B.h"
#include "ANALOG_IN.h"


static uint16_t value;

static void PinsTask(void *pvParameters){
	ROT_Off();
	GRUN_Off();
	BLAU_Off();
	for(;;){
		(void)ANALOG_IN_Measure(TRUE);
		(void)ANALOG_IN_GetValue16(&value);

	}
}


void PINS_Init(void){
  if (FRTOS1_xTaskCreate(PinsTask, "Pins", configMINIMAL_STACK_SIZE+100, NULL, tskIDLE_PRIORITY+1, NULL) != pdPASS) {
    for(;;){} /* error */
  }
}


void PINS_Deinit(void){
}
