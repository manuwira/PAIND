/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : Knie_R.c
**     Project     : PAIND
**     Processor   : MKL25Z128VLK4
**     Component   : Servo
**     Version     : Component 01.066, Driver 01.00, CPU db: 3.00.000
**     Repository  : My Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-10-13, 09:56, # CodeGen: 52
**     Abstract    :
**
This component implements a driver for hobby servos.
**     Settings    :
**          Component name                                 : Knie_R
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
**         SetPWMDutyUs - void Knie_R_SetPWMDutyUs(word dutyUs);
**         SetPos       - void Knie_R_SetPos(byte pos);
**         PWMusToPos8  - byte Knie_R_PWMusToPos8(word us);
**         Init         - void Knie_R_Init(void);
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
** @file Knie_R.c
** @version 01.00
** @brief
**
This component implements a driver for hobby servos.
*/         
/*!
**  @addtogroup Knie_R_module Knie_R module documentation
**  @{
*/         

/* MODULE Knie_R. */

#include "Knie_R.h"
#define Knie_R_MIN_PWM_US          900 /*!< minimal duty cycle for servo */
#define Knie_R_MAX_PWM_US          2100 /*!< maximal duty cycle for servo */
#define Knie_R_INIT_PWM_US         1500 /*!< initial PWM duty */
#define Knie_R_PWM_PERIOD_US       20000 /*!< PWM period in micro seconds, typically 20'000 us (50 Hz) */
#define Knie_R_PWM_RANGE_US        (Knie_R_MAX_PWM_US-Knie_R_MIN_PWM_US) /*!< PWM range in micro seconds */
#define Knie_R_POS8_TO_PWM(pos)    (uint16_t)(Knie_R_MIN_PWM_US+(((pos)*(uint32_t)Knie_R_PWM_RANGE_US)/255)) /*!< Position to PWM transformation */
#define Knie_R_PWM_TO_POS8(pwm)    (uint16_t)((((uint32_t)(pwm)-Knie_R_MIN_PWM_US)*255/Knie_R_PWM_RANGE_US)) /*!< PWM to position transformation */
#define Knie_R_SHELL_NAME_STR      "Knie_R" /*!< Name used for servo in shell */

/* inverted PWM: if set to 1, then a duty value of 0xffff means signal is all time low, where 0x0000 means signal is high all time */
#define Knie_R_INVERTED_PWM   1

typedef struct Knie_R_ServoDescTag {
  uint16_t currPWMus; /* current duty in microseconds */
} Knie_R_ServoDesc;

/*! \brief Descriptor about the status of the servo */
static Knie_R_ServoDesc Servo;

/* Internal method prototypes */
static void DoSteps(void);

/*
** ===================================================================
**     Method      :  Knie_R_SetPWMDutyUs (component Servo)
**     Description :
**         Sets the servo PWM duty cycle in micro seconds (us)
**     Parameters  :
**         NAME            - DESCRIPTION
**         dutyUs          - Duty cycle in microseconds
**     Returns     : Nothing
** ===================================================================
*/
void Knie_R_SetPWMDutyUs(word dutyUs)
{
  /* write new duty cycle */
#if Knie_R_INVERTED_PWM
  Pwm4_SetDutyUS(Knie_R_PWM_PERIOD_US-dutyUs); /* need to invert duty cycle */
#else
  Pwm4_SetDutyUS(dutyUs);
#endif
  Servo.currPWMus = (uint16_t)dutyUs; /* update current duty cycle value */
}

/*
** ===================================================================
**     Method      :  Knie_R_SetPos (component Servo)
**     Description :
**         Sets the servo position
**     Parameters  :
**         NAME            - DESCRIPTION
**         pos             - Position to be used
**     Returns     : Nothing
** ===================================================================
*/
void Knie_R_SetPos(byte pos)
{
  Knie_R_SetPWMDutyUs((uint16_t)Knie_R_POS8_TO_PWM(pos));
}

/*
** ===================================================================
**     Method      :  Knie_R_Init (component Servo)
**     Description :
**         Moves the serve to its initialization position.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Knie_R_Init(void)
{
  Knie_R_SetPWMDutyUs(Knie_R_INIT_PWM_US); /* set servo to initial duty ratio */
}

/*
** ===================================================================
**     Method      :  Knie_R_PWMusToPos8 (component Servo)
**     Description :
**         Transforms a micro-second PWM time into 8bit position
**     Parameters  :
**         NAME            - DESCRIPTION
**         us              - us PWM time
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
byte Knie_R_PWMusToPos8(word us)
{
  uint16_t pos, time;

  pos = Knie_R_PWM_TO_POS8(us);
  time = Knie_R_POS8_TO_PWM(pos);
  if (time<us) {
    return (byte)(pos+1); /* add rounding */
  } else {
    return (byte)pos;
  }
}

/* END Knie_R. */

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
