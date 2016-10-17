/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : WAIT1.h
**     Project     : PAIND
**     Processor   : MKL25Z128VLK4
**     Component   : Wait
**     Version     : Component 01.067, Driver 01.00, CPU db: 3.00.000
**     Repository  : My Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-10-13, 09:56, # CodeGen: 52
**     Abstract    :
**          Implements busy waiting routines.
**     Settings    :
**          Component name                                 : WAIT1
**          Manual Clock Values                            : Disabled
**          Delay100usFunction                             : Delay100US
**          RTOS                                           : Disabled
**          Watchdog                                       : Disabled
**     Contents    :
**         Wait10Cycles   - void WAIT1_Wait10Cycles(void);
**         Wait100Cycles  - void WAIT1_Wait100Cycles(void);
**         WaitCycles     - void WAIT1_WaitCycles(uint16_t cycles);
**         WaitLongCycles - void WAIT1_WaitLongCycles(uint32_t cycles);
**         Waitms         - void WAIT1_Waitms(uint16_t ms);
**         Waitus         - void WAIT1_Waitus(uint16_t us);
**         Waitns         - void WAIT1_Waitns(uint16_t ns);
**         WaitOSms       - void WAIT1_WaitOSms(void);
**
**     License   : Open Source (LGPL)
**     Copyright : Erich Styger, 2013-2015, all rights reserved.
**     Web       : www.mcuoneclipse.com
**     This an open source software implementing waiting routines using Processor Expert.
**     This is a free software and is opened for education,  research  and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file WAIT1.h
** @version 01.00
** @brief
**          Implements busy waiting routines.
*/         
/*!
**  @addtogroup WAIT1_module WAIT1 module documentation
**  @{
*/         

#ifndef __WAIT1_H
#define __WAIT1_H

/* MODULE WAIT1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "Cpu.h"
/* include RTOS header files */
#include "FreeRTOS.h" /* for vTaskDelay() */
#include "task.h"

#ifdef __cplusplus
extern "C" {
#endif


#define WAIT1_INSTR_CLOCK_HZ       CPU_CORE_CLK_HZ /* for Kinetis, use core clock as base for instruction execution */
#define WAIT1_NofCyclesMs(ms, hz)  ((ms)*((hz)/1000)) /* calculates the needed cycles based on bus clock frequency */
#define WAIT1_NofCyclesUs(us, hz)  ((us)*(((hz)/1000)/1000)) /* calculates the needed cycles based on bus clock frequency */
#define WAIT1_NofCyclesNs(ns, hz)  (((ns)*(((hz)/1000)/1000))/1000) /* calculates the needed cycles based on bus clock frequency */


#define WAIT1_WAIT_C(cycles) \
     ( (cycles)<=10 ? \
          WAIT1_Wait10Cycles() \
        : WAIT1_WaitCycles((uint16_t)cycles) \
      )                                      /*!< wait for some cycles */


void WAIT1_Wait10Cycles(void);
/*
** ===================================================================
**     Method      :  WAIT1_Wait10Cycles (component Wait)
**     Description :
**         Wait for 10 CPU cycles.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void WAIT1_Wait100Cycles(void);
/*
** ===================================================================
**     Method      :  WAIT1_Wait100Cycles (component Wait)
**     Description :
**         Wait for 100 CPU cycles.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void WAIT1_WaitCycles(uint16_t cycles);
/*
** ===================================================================
**     Method      :  WAIT1_WaitCycles (component Wait)
**     Description :
**         Wait for a specified number of CPU cycles (16bit data type).
**     Parameters  :
**         NAME            - DESCRIPTION
**         cycles          - The number of cycles to wait.
**     Returns     : Nothing
** ===================================================================
*/

void WAIT1_Waitms(uint16_t ms);
/*
** ===================================================================
**     Method      :  WAIT1_Waitms (component Wait)
**     Description :
**         Wait for a specified time in milliseconds.
**     Parameters  :
**         NAME            - DESCRIPTION
**         ms              - How many milliseconds the function has to
**                           wait
**     Returns     : Nothing
** ===================================================================
*/

/* we are having a static clock configuration: implement as macro/inlined version */
#define WAIT1_Waitus(us)  \
        /*lint -save -e(505,506,522) Constant value Boolean, Redundant left argument to comma. */\
       (  ((WAIT1_NofCyclesUs((us),WAIT1_INSTR_CLOCK_HZ)==0)||(us)==0) ? \
          (void)0 : \
          ( ((us)/1000)==0 ? (void)0 : WAIT1_Waitms((uint16_t)((us)/1000))) \
          , (WAIT1_NofCyclesUs(((us)%1000), WAIT1_INSTR_CLOCK_HZ)==0) ? (void)0 : \
            WAIT1_WAIT_C(WAIT1_NofCyclesUs(((us)%1000), WAIT1_INSTR_CLOCK_HZ)) \
       /*lint -restore */\
       )
/*
** ===================================================================
**     Method      :  WAIT1_Waitus (component Wait)
**     Description :
**         Wait for a specified time in microseconds.
**     Parameters  :
**         NAME            - DESCRIPTION
**         us              - How many microseconds the function has to
**                           wait
**     Returns     : Nothing
** ===================================================================
*/

/* we are having a static clock configuration: implement as macro/inlined version */
#define WAIT1_Waitns(ns)  \
        /*lint -save -e(505,506,522) Constant value Boolean, Redundant left argument to comma. */\
       (  ((WAIT1_NofCyclesNs((ns), WAIT1_INSTR_CLOCK_HZ)==0)||(ns)==0) ? \
          (void)0 : \
          WAIT1_Waitus((ns)/1000) \
          , (WAIT1_NofCyclesNs((ns)%1000, WAIT1_INSTR_CLOCK_HZ)==0) ? \
              (void)0 : \
              WAIT1_WAIT_C(WAIT1_NofCyclesNs(((ns)%1000), WAIT1_INSTR_CLOCK_HZ)) \
       /*lint -restore */\
       )
/*
** ===================================================================
**     Method      :  WAIT1_Waitns (component Wait)
**     Description :
**         Wait for a specified time in nano seconds.
**     Parameters  :
**         NAME            - DESCRIPTION
**         ns              - How many ns the function has to wait
**     Returns     : Nothing
** ===================================================================
*/

#define WAIT1_WaitOSms(ms) \
  vTaskDelay(ms/portTICK_PERIOD_MS)
/*
** ===================================================================
**     Method      :  WAIT1_WaitOSms (component Wait)
**     Description :
**         If an RTOS is enabled, this routine will use a non-blocking
**         wait method. Otherwise it will do a busy/blocking wait.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#ifdef __cplusplus
}  /* extern "C" */
#endif

void WAIT1_WaitLongCycles(uint32_t cycles);
/*
** ===================================================================
**     Method      :  WAIT1_WaitLongCycles (component Wait)
**     Description :
**         Wait for a specified number of CPU cycles (32bit data type).
**     Parameters  :
**         NAME            - DESCRIPTION
**         cycles          - The number of cycles to wait.
**     Returns     : Nothing
** ===================================================================
*/

/* END WAIT1. */

#endif
/* ifndef __WAIT1_H */
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
