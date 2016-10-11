/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : Huft_L.c
**     Project     : PAIND
**     Processor   : MKL25Z128VLK4
**     Component   : Servo
**     Version     : Component 01.066, Driver 01.00, CPU db: 3.00.000
**     Repository  : My Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-10-05, 11:49, # CodeGen: 9
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
** @file Huft_L.c
** @version 01.00
** @brief
**
This component implements a driver for hobby servos.
*/         
/*!
**  @addtogroup Huft_L_module Huft_L module documentation
**  @{
*/         

/* MODULE Huft_L. */

#include "Huft_L.h"
#define Huft_L_MIN_PWM_US          900 /*!< minimal duty cycle for servo */
#define Huft_L_MAX_PWM_US          2100 /*!< maximal duty cycle for servo */
#define Huft_L_INIT_PWM_US         1500 /*!< initial PWM duty */
#define Huft_L_PWM_PERIOD_US       20000 /*!< PWM period in micro seconds, typically 20'000 us (50 Hz) */
#define Huft_L_PWM_RANGE_US        (Huft_L_MAX_PWM_US-Huft_L_MIN_PWM_US) /*!< PWM range in micro seconds */
#define Huft_L_POS8_TO_PWM(pos)    (uint16_t)(Huft_L_MIN_PWM_US+(((pos)*(uint32_t)Huft_L_PWM_RANGE_US)/255)) /*!< Position to PWM transformation */
#define Huft_L_PWM_TO_POS8(pwm)    (uint16_t)((((uint32_t)(pwm)-Huft_L_MIN_PWM_US)*255/Huft_L_PWM_RANGE_US)) /*!< PWM to position transformation */
#define Huft_L_SHELL_NAME_STR      "Huft_L" /*!< Name used for servo in shell */

/* inverted PWM: if set to 1, then a duty value of 0xffff means signal is all time low, where 0x0000 means signal is high all time */
#define Huft_L_INVERTED_PWM   1

typedef struct Huft_L_ServoDescTag {
  uint16_t currPWMus; /* current duty in microseconds */
} Huft_L_ServoDesc;

/*! \brief Descriptor about the status of the servo */
static Huft_L_ServoDesc Servo;

/* Internal method prototypes */
static void DoSteps(void);

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
void Huft_L_SetPWMDutyUs(word dutyUs)
{
  /* write new duty cycle */
#if Huft_L_INVERTED_PWM
  Pwm1_SetDutyUS(Huft_L_PWM_PERIOD_US-dutyUs); /* need to invert duty cycle */
#else
  Pwm1_SetDutyUS(dutyUs);
#endif
  Servo.currPWMus = (uint16_t)dutyUs; /* update current duty cycle value */
}

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
void Huft_L_SetPos(byte pos)
{
  Huft_L_SetPWMDutyUs((uint16_t)Huft_L_POS8_TO_PWM(pos));
}

/*
** ===================================================================
**     Method      :  Huft_L_Init (component Servo)
**     Description :
**         Moves the serve to its initialization position.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Huft_L_Init(void)
{
  Huft_L_SetPWMDutyUs(Huft_L_INIT_PWM_US); /* set servo to initial duty ratio */
}

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
byte Huft_L_PWMusToPos8(word us)
{
  uint16_t pos, time;

  pos = Huft_L_PWM_TO_POS8(us);
  time = Huft_L_POS8_TO_PWM(pos);
  if (time<us) {
    return (byte)(pos+1); /* add rounding */
  } else {
    return (byte)pos;
  }
}

/* END Huft_L. */

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
