/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : Huft_L.h
**     Project     : PAIND
**     Processor   : MKL25Z128VLK4
**     Component   : Servo
**     Version     : Component 01.066, Driver 01.00, CPU db: 3.00.000
**     Repository  : My Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-10-11, 15:54, # CodeGen: 37
**     Abstract    :
**
This component implements a driver for hobby servos.
**     Settings    :
**          Component name                                 : Huft_L
**          Inverted PWM                                   : yes
**          Init PWM (us)                                  : 1500
**          Min Pos PWM (us)                               : 900
**          Max Pos PWM (us)                               : 2100
**          PWM Period (us)                                : 20000
**          System                                         : 
**            Timed Move                                   : Disabled
**            Shell                                        : Disabled
**            PWM                                          : PWM
**          CPU clock/speed selection                      : 
**            High speed mode                              : This component enabled
**            Low speed mode                               : This component disabled
**            Slow speed mode                              : This component disabled
**     Contents    :
**         SetPWMDutyUs - void Huft_L_SetPWMDutyUs(word dutyUs);
**         SetPos       - void Huft_L_SetPos(byte pos);
**         PWMusToPos8  - byte Huft_L_PWMusToPos8(word us);
**         Init         - void Huft_L_Init(void);
**
**     License   :  Open Source (LGPL)
**     Copyright : (c) Copyright Erich Styger, 2013, all right reserved.
**     This an open source software implementing a driver for the 
**     Servo Motors using Processor Expert.
**     This is a free software and is opened for education,  research 
**     and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for
**       personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file Huft_L.h
** @version 01.00
** @brief
**
This component implements a driver for hobby servos.
*/         
/*!
**  @addtogroup Huft_L_module Huft_L module documentation
**  @{
*/         

#ifndef __Huft_L_H
#define __Huft_L_H

/* MODULE Huft_L. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "Pwm1.h"

#include "Cpu.h"


#define Huft_L_PARSE_COMMAND_ENABLED  0 /* set to 1 if method ParseCommand() is present, 0 otherwise */


void Huft_L_SetPos(byte pos);
/*
** ===================================================================
**     Method      :  Huft_L_SetPos (component Servo)
**     Description :
**         Sets the servo position
**     Parameters  :
**         NAME            - DESCRIPTION
**         pos             - Position to be used
**     Returns     : Nothing
** ===================================================================
*/

void Huft_L_SetPWMDutyUs(word dutyUs);
/*
** ===================================================================
**     Method      :  Huft_L_SetPWMDutyUs (component Servo)
**     Description :
**         Sets the servo PWM duty cycle in micro seconds (us)
**     Parameters  :
**         NAME            - DESCRIPTION
**         dutyUs          - Duty cycle in microseconds
**     Returns     : Nothing
** ===================================================================
*/

void Huft_L_Init(void);
/*
** ===================================================================
**     Method      :  Huft_L_Init (component Servo)
**     Description :
**         Moves the serve to its initialization position.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

byte Huft_L_PWMusToPos8(word us);
/*
** ===================================================================
**     Method      :  Huft_L_PWMusToPos8 (component Servo)
**     Description :
**         Transforms a micro-second PWM time into 8bit position
**     Parameters  :
**         NAME            - DESCRIPTION
**         us              - us PWM time
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

/* END Huft_L. */

#endif
/* ifndef __Huft_L_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
