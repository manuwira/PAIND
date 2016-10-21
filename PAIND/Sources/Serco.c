/*
 * Serco.c

 *
 *  Created on: 21.10.2016
 *      Author: manuelwittmer
 */

#include "Huft_L.h"
#include "Huft_R.h"
#include "Knie_L.h"
#include "Knie_R.h"
#include "Knie_R.h"

#include "WAIT1.h"

#include "Application.h"
#include "FRTOS1.h"

static void ServoTask(void *pvParameters){
	for(;;){
	}
}


void SERVO_Init(void){
  if (FRTOS1_xTaskCreate(ServoTask, "Servo", configMINIMAL_STACK_SIZE+100, NULL, tskIDLE_PRIORITY+1, NULL) != pdPASS) {
    for(;;){} /* error */
  }
}


void SERVO_Deinit(void){
}


