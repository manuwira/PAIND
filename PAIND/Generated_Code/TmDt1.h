/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : TmDt1.h
**     Project     : PAIND
**     Processor   : MKL25Z128VLK4
**     Component   : TimeDate
**     Version     : Component 02.111, Driver 01.00, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-10-13, 10:05, # CodeGen: 55
**     Abstract    :
**         This component "TimeDate" implements real time and date.
**         The component requires a periodic interrupt generator: timer
**         compare or reload register or timer-overflow interrupt
**         (of free running counter). User can select precision of
**         selected timer.
**         The component supports also alarm with event OnAlarm.
**     Settings    :
**          Component name                                 : TmDt1
**          Periodic interrupt source                      : LPTMR0_CMR
**          Counter                                        : LPTMR0_CNR
**          Interrupt service/event                        : Enabled
**            Interrupt                                    : INT_LPTMR0
**            Interrupt priority                           : medium priority
**          Resolution                                     : 10 ms
**          Component uses entire timer                    : no
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Time                                         : 00:00:00
**            Date                                         : 2008-01-01
**          CPU clock/speed selection                      : 
**            High speed mode                              : This component enabled
**            Low speed mode                               : This component disabled
**            Slow speed mode                              : This component disabled
**          Referenced components                          : 
**            TimeDate_LDD                                 : TimeDate_LDD
**     Contents    :
**         SetTime - byte TmDt1_SetTime(byte Hour, byte Min, byte Sec, byte Sec100);
**         GetTime - byte TmDt1_GetTime(TIMEREC *Time);
**         SetDate - byte TmDt1_SetDate(word Year, byte Month, byte Day);
**         GetDate - byte TmDt1_GetDate(DATEREC *Date);
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file TmDt1.h
** @version 01.00
** @brief
**         This component "TimeDate" implements real time and date.
**         The component requires a periodic interrupt generator: timer
**         compare or reload register or timer-overflow interrupt
**         (of free running counter). User can select precision of
**         selected timer.
**         The component supports also alarm with event OnAlarm.
*/         
/*!
**  @addtogroup TmDt1_module TmDt1 module documentation
**  @{
*/         

#ifndef __TmDt1_H
#define __TmDt1_H

/* MODULE TmDt1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "TimeDateLdd1.h"

#include "Cpu.h"
#include <limits.h>


#ifndef __BWUserType_TIMEREC
#define __BWUserType_TIMEREC
  typedef struct { /* It contains actual number of hours, minutes, seconds and hundreths of seconds. */
    byte Hour; /* hours (0 - 23) */
    byte Min; /* minutes (0 - 59) */
    byte Sec; /* seconds (0 - 59) */
    byte Sec100; /* hundredths of seconds (0 - h99) */
  } TIMEREC;
#endif
#ifndef __BWUserType_DATEREC
#define __BWUserType_DATEREC
  typedef struct { /* It contains actual year, month, and day description. */
    word Year; /* years (1998 - 2099) */
    byte Month; /* months (1 - 12) */
    byte Day; /* days (0 - 6) */
  } DATEREC;
#endif

/*
** ===================================================================
**     Method      :  TmDt1_SetTime (component TimeDate)
**     Description :
**         This method sets a new actual time.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Hour            - Hours (0 - 23)
**         Min             - Minutes (0 - 59)
**         Sec             - Seconds (0 - 59)
**         Sec100          - Hundredths of seconds (0 - 99)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte TmDt1_SetTime(byte Hour,byte Min,byte Sec,byte Sec100);

/*
** ===================================================================
**     Method      :  TmDt1_GetTime (component TimeDate)
**     Description :
**         This method returns current time.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Time            - Pointer to the structure TIMEREC. It
**                           contains actual number of hours, minutes,
**                           seconds and hundredths of seconds.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte TmDt1_GetTime(TIMEREC *Time);

/*
** ===================================================================
**     Method      :  TmDt1_SetDate (component TimeDate)
**     Description :
**         This method sets a new actual date. See limitations at the
**         page <General Info>.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Year            - Years (16-bit unsigned integer)
**         Month           - Months (8-bit unsigned integer)
**         Day             - Days (8-bit unsigned integer)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte TmDt1_SetDate(word Year,byte Month,byte Day);

/*
** ===================================================================
**     Method      :  TmDt1_GetDate (component TimeDate)
**     Description :
**         This method returns current date.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Date            - Pointer to the structure DATEREC. It
**                           contains actual year, month, and day
**                           description.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte TmDt1_GetDate(DATEREC *Date);

/* END TmDt1. */

#endif 
/* ifndef __TmDt1_H */
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
