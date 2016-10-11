/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : GRUN.c
**     Project     : PAIND
**     Processor   : MKL25Z128VLK4
**     Component   : LED
**     Version     : Component 01.066, Driver 01.00, CPU db: 3.00.000
**     Repository  : My Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-10-05, 19:45, # CodeGen: 26
**     Abstract    :
**          This component implements a universal driver for a single LED.
**     Settings    :
**          Component name                                 : GRUN
**          Turned On with initialization                  : yes
**          HW Interface                                   : 
**            Anode on port side, HIGH is ON               : no
**            On/Off                                       : Enabled
**              Pin                                        : LEDpin
**            PWM                                          : Disabled
**          Shell                                          : Disabled
**     Contents    :
**         Init       - void GRUN_Init(void);
**         Deinit     - void GRUN_Deinit(void);
**         On         - void GRUN_On(void);
**         Off        - void GRUN_Off(void);
**         Neg        - void GRUN_Neg(void);
**         Get        - uint8_t GRUN_Get(void);
**         Put        - void GRUN_Put(uint8_t val);
**         SetRatio16 - void GRUN_SetRatio16(uint16_t ratio);
**
**     License   : Open Source (LGPL)
**     Copyright : Erich Styger, 2013-2015, all rights reserved.
**     Web       : www.mcuoneclipse.com
**     This an open source software implementing a driver using Processor Expert.
**     This is a free software and is opened for education, research and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file GRUN.c
** @version 01.00
** @brief
**          This component implements a universal driver for a single LED.
*/         
/*!
**  @addtogroup GRUN_module GRUN module documentation
**  @{
*/         

/* MODULE GRUN. */

#include "GRUN.h"

/*
** ===================================================================
**     Method      :  GRUN_On (component LED)
**     Description :
**         This turns the LED on.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void GRUN_On(void)
{
  *** This method is implemented as macro in the header file
}
*/

/*
** ===================================================================
**     Method      :  GRUN_Off (component LED)
**     Description :
**         This turns the LED off.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void GRUN_Off(void)
{
  *** This method is implemented as macro in the header file
}
*/

/*
** ===================================================================
**     Method      :  GRUN_Neg (component LED)
**     Description :
**         This negates/toggles the LED
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void GRUN_Neg(void)
{
  *** This method is implemented as macro in the header file
}
*/

/*
** ===================================================================
**     Method      :  GRUN_Get (component LED)
**     Description :
**         This returns logical 1 in case the LED is on, 0 otherwise.
**     Parameters  : None
**     Returns     :
**         ---             - Status of the LED (on or off)
** ===================================================================
*/
/*
uint8_t GRUN_Get(void)
{
  *** This method is implemented as macro in the header file
}
*/

/*
** ===================================================================
**     Method      :  GRUN_Init (component LED)
**     Description :
**         Performs the LED driver initialization.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void GRUN_Init(void)
{
  *** This method is implemented as macro in the header file
}
*/

/*
** ===================================================================
**     Method      :  GRUN_Put (component LED)
**     Description :
**         Turns the LED on or off.
**     Parameters  :
**         NAME            - DESCRIPTION
**         val             - value to define if the LED has to be on or
**                           off.
**     Returns     : Nothing
** ===================================================================
*/
/*
void GRUN_Put(uint8_t val)
{
  *** This method is implemented as macro in the header file
}
*/

/*
** ===================================================================
**     Method      :  GRUN_Deinit (component LED)
**     Description :
**         Deinitializes the driver
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void GRUN_Deinit(void)
{
}

/*
** ===================================================================
**     Method      :  GRUN_SetRatio16 (component LED)
**     Description :
**         Method to specify the duty cycle. If using a PWM pin, this
**         means the duty cycle is set. For On/off pins, values smaller
**         0x7FFF means off, while values greater means on.
**     Parameters  :
**         NAME            - DESCRIPTION
**         ratio           - Ratio value, where 0 means 'off' and
**                           0xffff means 'on'
**     Returns     : Nothing
** ===================================================================
*/
void GRUN_SetRatio16(uint16_t ratio)
{
  /* on/off LED: binary on or off */
  if (ratio<(0xffff/2)) {
    GRUN_Off();
  } else {
    GRUN_On();
  }
}

/* END GRUN. */

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
