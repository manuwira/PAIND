/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : SYS1.h
**     Project     : PAIND
**     Processor   : MKL25Z128VLK4
**     Component   : SeggerSystemView
**     Version     : Component 01.034, Driver 01.00, CPU db: 3.00.000
**     Repository  : My Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-10-05, 19:28, # CodeGen: 22
**     Abstract    :
**
**     Settings    :
**          Component name                                 : SYS1
**          Version                                        : V2.30
**          Application Name                               : "FRDM INTRO FS2015"
**          Device Name                                    : "Cortex-M0+"
**          RAM Base                                       : 0x20000000
**          ID Base                                        : 0x10000000
**          ID Shift                                       : 2
**          Number of tasks                                : 8
**          RTT Channel                                    : 
**            Segger RTT                                   : RTT1
**            Name                                         : "SysView"
**            Channel Index                                : 1
**            Buffer size                                  : 1024
**     Contents    :
**         Init           - void SYS1_Init(void);
**         OnUserStart    - void SYS1_OnUserStart(unsigned UserId);
**         OnUserStop     - void SYS1_OnUserStop(unsigned UserId);
**         RecordEnterISR - void SYS1_RecordEnterISR(void);
**         RecordExitISR  - void SYS1_RecordExitISR(void);
**         Print          - void SYS1_Print(const char *s);
**         PrintfHost     - void SYS1_PrintfHost(const char *s, ...);
**         PrintfTarget   - void SYS1_PrintfTarget(const char *s, ...);
**         Warn           - void SYS1_Warn(const char *s);
**         WarnfHost      - void SYS1_WarnfHost(const char *s, ...);
**         WarnfTarget    - void SYS1_WarnfTarget(const char *s, ...);
**         Error          - void SYS1_Error(const char *s);
**         ErrorfHost     - void SYS1_ErrorfHost(const char *s, ...);
**         ErrorfTarget   - void SYS1_ErrorfTarget(const char *s, ...);
**
**     (c) Copyright Segger, 2016
**     http      : www.segger.com
** ###################################################################*/
/*!
** @file SYS1.h
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup SYS1_module SYS1 module documentation
**  @{
*/         

#ifndef __SYS1_H
#define __SYS1_H

/* MODULE SYS1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "RTT1.h"

#include "Cpu.h"
#include "SEGGER_SYSVIEW.h"




void SYS1_Init(void);
/*
** ===================================================================
**     Method      :  SYS1_Init (component SeggerSystemView)
**     Description :
**         Driver Initialization
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_OnUserStart(UserId) \
  SEGGER_SYSVIEW_OnUserStart(UserId)

/*
** ===================================================================
**     Method      :  SYS1_OnUserStart (component SeggerSystemView)
**     Description :
**         Send a user event start, such as start of a subroutine for
**         profiling.
**     Parameters  :
**         NAME            - DESCRIPTION
**         UserId          - User defined ID for the event
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_OnUserStop(UserId) \
  SEGGER_SYSVIEW_OnUserStop(UserId)

/*
** ===================================================================
**     Method      :  SYS1_OnUserStop (component SeggerSystemView)
**     Description :
**         Send a user event stop, such as return of a subroutine for
**         profiling.
**     Parameters  :
**         NAME            - DESCRIPTION
**         UserId          - User defined ID for the event
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_RecordEnterISR() \
  SEGGER_SYSVIEW_RecordEnterISR()
/*
** ===================================================================
**     Method      :  SYS1_RecordEnterISR (component SeggerSystemView)
**     Description :
**         Records the enter of an ISR. Place this call at the
**         beginning of the interrupt service routine.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_RecordExitISR() \
  SEGGER_SYSVIEW_RecordExitISR()
/*
** ===================================================================
**     Method      :  SYS1_RecordExitISR (component SeggerSystemView)
**     Description :
**         Records the end of the ISR. Call this function at the end of
**         the ISR to be recorded.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_Print(s) \
  SEGGER_SYSVIEW_Print(s)
/*
** ===================================================================
**     Method      :  SYS1_Print (component SeggerSystemView)
**     Description :
**         Prints a string to the host
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_Warn(s) \
  SEGGER_SYSVIEW_Warn(s)
/*
** ===================================================================
**     Method      :  SYS1_Warn (component SeggerSystemView)
**     Description :
**         Prints a warning string to the host
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_Error(s) \
  SEGGER_SYSVIEW_Error(s)
/*
** ===================================================================
**     Method      :  SYS1_Error (component SeggerSystemView)
**     Description :
**         Prints an error string to the host
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_PrintfHost    SEGGER_SYSVIEW_PrintfHost
/*
** ===================================================================
**     Method      :  SYS1_PrintfHost (component SeggerSystemView)
**     Description :
**         Prints a string using printf() to the host which is
**         processed on the host
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_PrintfTarget   SEGGER_SYSVIEW_PrintfTarget
/*
** ===================================================================
**     Method      :  SYS1_PrintfTarget (component SeggerSystemView)
**     Description :
**         Prints a string using printf() to the host which is
**         processed target
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_WarnfHost  SEGGER_SYSVIEW_WarnfHost
/*
** ===================================================================
**     Method      :  SYS1_WarnfHost (component SeggerSystemView)
**     Description :
**         Prints a warning string using printf() to the host which is
**         processed on the host
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_WarnfTarget   SEGGER_SYSVIEW_WarnfTarget
/*
** ===================================================================
**     Method      :  SYS1_WarnfTarget (component SeggerSystemView)
**     Description :
**         Prints a warning string using printf() to the host which is
**         processed on the target
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_ErrorfHost   SEGGER_SYSVIEW_ErrorfHost
/*
** ===================================================================
**     Method      :  SYS1_ErrorfHost (component SeggerSystemView)
**     Description :
**         Prints an error string using printf() to the host which is
**         processed on the host
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

#define SYS1_ErrorfTarget   SEGGER_SYSVIEW_ErrorfTarget
/*
** ===================================================================
**     Method      :  SYS1_ErrorfTarget (component SeggerSystemView)
**     Description :
**         Prints an error string using printf() to the host which is
**         processed on the target
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

/* END SYS1. */

#endif
/* ifndef __SYS1_H */
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
