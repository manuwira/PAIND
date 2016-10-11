/*
 * Application.c
 *
 *  Created on: 29.09.2016
 *      Author: manuelwittmer
 */
#include "Huft_L.h"
#include "Huft_R.h"
#include "Knie_L.h"
#include "Knie_R.h"

#include "WAIT1.h"

void APP_Run(void){
	uint16_t pos;



	for(;;) {

	   Huft_L_SetPos(255);
	   Huft_R_SetPos(170);

	   Knie_L_SetPos(100);
	   Knie_R_SetPos(255);

	   Bein_L_SetPos(140);
	   Bein_R_SetPos(70);



	  }
}
