/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : SM2.h
**     Project     : PAIND
**     Processor   : MKL25Z128VLK4
**     Component   : SPIMaster_LDD
**     Version     : Component 01.111, Driver 01.02, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-10-11, 15:57, # CodeGen: 38
**     Abstract    :
**         This component "SPIMaster_LDD" implements MASTER part of synchronous
**         serial master-slave communication.
**     Settings    :
**          Component name                                 : SM2
**          Device                                         : SPI1
**          Interrupt service/event                        : Enabled
**            Input interrupt                              : INT_SPI1
**            Input interrupt priority                     : medium priority
**            Output interrupt                             : INT_SPI1
**            Output interrupt priority                    : medium priority
**          Settings                                       : 
**            Input pin                                    : Enabled
**              Pin                                        : PTE1/SPI1_MOSI/UART1_RX/SPI1_MISO/I2C1_SCL
**              Pin signal                                 : 
**            Output pin                                   : Enabled
**              Pin                                        : PTE3/SPI1_MISO/SPI1_MOSI
**              Pin signal                                 : 
**            Clock pin                                    : 
**              Pin                                        : PTE2/SPI1_SCK
**              Pin signal                                 : 
**            Chip select list                             : 1
**              Chip select 0                              : 
**                Pin                                      : PTE4/SPI1_PCS0
**                Pin signal                               : 
**                Active level                             : Low
**            Attribute set list                           : 1
**              Attribute set 0                            : 
**                Width                                    : 8 bits
**                MSB first                                : yes
**                Clock polarity                           : Low
**                Clock phase                              : Capture on leading edge
**                Parity                                   : None
**                Chip select toggling                     : yes
**                Clock rate index                         : 0
**            Clock rate                                   : 375 kHz
**            HW input buffer size                         : 1
**            HW input watermark                           : 1
**            Receiver DMA                                 : Disabled
**            HW output buffer size                        : 1
**            HW output watermark                          : 1
**            Transmitter DMA                              : Disabled
**          Initialization                                 : 
**            Initial chip select                          : 0
**            Initial attribute set                        : 0
**            Enabled in init. code                        : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnBlockSent                                : Enabled
**              OnBlockReceived                            : Enabled
**              OnError                                    : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init         - LDD_TDeviceData* SM2_Init(LDD_TUserData *UserDataPtr);
**         SendBlock    - LDD_TError SM2_SendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         ReceiveBlock - LDD_TError SM2_ReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
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
** @file SM2.h
** @version 01.02
** @brief
**         This component "SPIMaster_LDD" implements MASTER part of synchronous
**         serial master-slave communication.
*/         
/*!
**  @addtogroup SM2_module SM2 module documentation
**  @{
*/         

#ifndef __SM2_H
#define __SM2_H

/* MODULE SM2. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "Cpu.h"
#include "SPI_PDD.h"

#ifdef __cplusplus
extern "C" {
#endif 


/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define SM2_PRPH_BASE_ADDRESS  0x40077000U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define SM2_Init_METHOD_ENABLED        /*!< Init method of the component SM2 is enabled (generated) */
#define SM2_SendBlock_METHOD_ENABLED   /*!< SendBlock method of the component SM2 is enabled (generated) */
#define SM2_ReceiveBlock_METHOD_ENABLED /*!< ReceiveBlock method of the component SM2 is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */
#define SM2_OnBlockSent_EVENT_ENABLED  /*!< OnBlockSent event of the component SM2 is enabled (generated) */
#define SM2_OnBlockReceived_EVENT_ENABLED /*!< OnBlockReceived event of the component SM2 is enabled (generated) */

#define SM2_CHIP_SELECT_COUNT 1U       /*!< Number of chip selects */
#define SM2_CONFIGURATION_COUNT 1U     /*!< Number of predefined configurations */

/*
** ===================================================================
**     Method      :  SM2_Init (component SPIMaster_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc.
**         If the "Enable in init. code" is set to "yes" value then the
**         device is also enabled(see the description of the Enable()
**         method). In this case the Enable() method is not necessary
**         and needn't to be generated. 
**         This method can be called only once. Before the second call
**         of Init() the Deinit() must be called first.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Device data structure pointer.
*/
/* ===================================================================*/
LDD_TDeviceData* SM2_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  SM2_ReceiveBlock (component SPIMaster_LDD)
*/
/*!
**     @brief
**         This method specifies the number of data to receive. The
**         method returns ERR_BUSY until the specified number of
**         characters is received. The method [CancelBlockReception]
**         can be used to cancel a running receive operation. If a
**         receive operation is not in progress (the method was not
**         called or a previous operation has already finished) all
**         received characters will be lost without any notification.
**         To prevent the loss of data call the method immediately
**         after the last receive operation has finished (e.g. from the
**         [OnBlockReceived] event). This method finishes immediately
**         after calling it - it doesn't wait the end of data reception.
**         Use event [OnBlockReceived] to check the end of data
**         reception or method GetReceivedDataNum to check the state of
**         receiving.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         BufferPtr       - Pointer to A buffer where
**                           received characters will be stored.
**     @param
**         Size            - Size of the block
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_DISABLED - Component is disabled
**                           ERR_BUSY - The previous receive request is
**                           pending
*/
/* ===================================================================*/
LDD_TError SM2_ReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, uint16_t Size);

/*
** ===================================================================
**     Method      :  SM2_SendBlock (component SPIMaster_LDD)
*/
/*!
**     @brief
**         Sends a block of characters. The method returns ERR_BUSY
**         when the previous block transmission is not completed. The
**         method [CancelBlockTransmission] can be used to cancel a
**         transmit operation. This method finishes immediately after
**         calling it - it doesn't wait the end of data transmission.
**         Use event [OnBlockSent] to check the end of data
**         transmission or method GetSentDataNum to check the state of
**         sending.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         BufferPtr       - Pointer to the block of data
**                           to send.
**     @param
**         Size            - Number of characters in the buffer.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_DISABLED - Component is disabled
**                           ERR_BUSY - The previous transmit request is
**                           pending
*/
/* ===================================================================*/
LDD_TError SM2_SendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, uint16_t Size);

/*
** ===================================================================
**     Method      :  SM2_Interrupt (component SPIMaster_LDD)
**
**     Description :
**         The ISR function handling the device receive/transmit 
**         interrupt.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/* {FreeRTOS RTOS Adapter} ISR function prototype */
PE_ISR(SM2_Interrupt);

/* END SM2. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif
/* ifndef __SM2_H */
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
