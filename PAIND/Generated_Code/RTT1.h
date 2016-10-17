/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : RTT1.h
**     Project     : PAIND
**     Processor   : MKL25Z128VLK4
**     Component   : SeggerRTT
**     Version     : Component 01.064, Driver 01.00, CPU db: 3.00.000
**     Repository  : My Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-10-13, 09:56, # CodeGen: 52
**     Abstract    :
**
**     Settings    :
**          Component name                                 : RTT1
**          Version                                        : V2.26
**          Number of Up Channels                          : 2
**          Number of Down Channels                        : 2
**          Max Blocked Interrupt Level                    : 3
**          Channel 0                                      : Enabled
**            Name                                         : "Terminal"
**            Up Buffer Size (Tx)                          : 512
**            Down Buffer Size (Rx)                        : 64
**            Up Buffer Mode                               : Skip (Default)
**            Down Buffer Mode                             : Skip (Default)
**            Blocking Send                                : Enabled
**              Timeout (ms)                               : 5
**              Wait                                       : WAIT1
**              Wait Time (ms)                             : 1
**            Printf Buffer Size                           : 64
**          Kinetis SDK                                    : KSDK1
**     Contents    :
**         Read             - int RTT1_Read(unsigned BufferIndex, const char* pBuffer, unsigned NumBytes);
**         Write            - int RTT1_Write(unsigned BufferIndex, char* pBuffer, unsigned BufferSize);
**         WriteString      - unsigned RTT1_WriteString(unsigned BufferIndex, const char* s);
**         GetKey           - dword RTT1_GetKey(void);
**         WaitKey          - long RTT1_WaitKey(void);
**         HasKey           - long RTT1_HasKey(void);
**         SetTerminal      - int RTT1_SetTerminal(char TerminalId);
**         TerminalOut      - int RTT1_TerminalOut(char TerminalId, const char* s);
**         ConfigUpBuffer   - int RTT1_ConfigUpBuffer(unsigned BufferIndex, const char* sName, char*...
**         ConfigDownBuffer - int RTT1_ConfigDownBuffer(unsigned BufferIndex, const char* sName, char*...
**         RecvChar         - uint8_t RTT1_RecvChar(uint8_t *c);
**         SendChar         - uint8_t RTT1_SendChar(uint8_t ch);
**         GetCharsInRxBuf  - uint16_t RTT1_GetCharsInRxBuf(void);
**         StdIOKeyPressed  - bool RTT1_StdIOKeyPressed(void);
**         StdIOReadChar    - void RTT1_StdIOReadChar(uint8_t *c);
**         StdIOSendChar    - void RTT1_StdIOSendChar(uint8_t ch);
**         Init             - void RTT1_Init(void);
**
**     (c) Copyright Segger, 2015
**     http      : www.segger.com
** ###################################################################*/
/*!
** @file RTT1.h
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup RTT1_module RTT1 module documentation
**  @{
*/         

#ifndef __RTT1_H
#define __RTT1_H

/* MODULE RTT1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "WAIT1.h"
#include "KSDK1.h"

#include "Cpu.h"
#include "SEGGER_RTT.h"


#define RTT1_RTT_CHANNEL_0_ENABLED   1  /* 0: channel disabled, 1: channel enabled */


#define RTT1_Read(BufferIndex, pBuffer, NumBytes) \
  SEGGER_RTT_Read(BufferIndex, pBuffer, NumBytes)

/*
** ===================================================================
**     Method      :  RTT1_Read (component SeggerRTT)
**     Description :
**         Read from buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**         BufferIndex     - Buffer/channel to be used.
**                           0 for terminal.
**       * pBuffer         - Pointer to buffer
**         BufferSize      - Number of bytes to write
**     Returns     :
**         ---             - Number of bytes that have been read
** ===================================================================
*/

#define RTT1_Write(BufferIndex, pBuffer, BufferSize) \
  SEGGER_RTT_Write(BufferIndex, pBuffer, BufferSize)

/*
** ===================================================================
**     Method      :  RTT1_Write (component SeggerRTT)
**     Description :
**         Write to buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**         BufferIndex     - Buffer/channel to be used.
**                           0 for terminal.
**       * pBuffer         - Pointer to buffer
**         BufferSize      - Size of buffer
**     Returns     :
**         ---             - Number of bytes which have been written to
**                           the up buffer
** ===================================================================
*/

#define RTT1_WriteString(BufferIndex, s) \
  SEGGER_RTT_WriteString(BufferIndex, s)

/*
** ===================================================================
**     Method      :  RTT1_WriteString (component SeggerRTT)
**     Description :
**         Write to buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**         BufferIndex     - Buffer/channel to be used.
**                           0 for terminal.
**       * s               - Pointer to 
**     Returns     :
**         ---             - Number of bytes which have been stored in
**                           the "Up"-buffer.
** ===================================================================
*/

#define RTT1_GetKey() \
  SEGGER_RTT_GetKey()

/*
** ===================================================================
**     Method      :  RTT1_GetKey (component SeggerRTT)
**     Description :
**         Returns a character/key
**     Parameters  : None
**     Returns     :
**         ---             - character code
** ===================================================================
*/

#define RTT1_WaitKey() \
  SEGGER_RTT_WaitKey()

/*
** ===================================================================
**     Method      :  RTT1_WaitKey (component SeggerRTT)
**     Description :
**         Waits for a key and returns it.
**     Parameters  : None
**     Returns     :
**         ---             - >=0    Character which has been read.
** ===================================================================
*/

#define RTT1_HasKey() \
  SEGGER_RTT_HasKey()

/*
** ===================================================================
**     Method      :  RTT1_HasKey (component SeggerRTT)
**     Description :
**         Checks if at least one character for reading is available in
**         the SEGGER RTT buffer
**     Parameters  : None
**     Returns     :
**         ---             - 0: No characters are available to read; 1:
**                           At least one character is available.
** ===================================================================
*/

bool RTT1_StdIOKeyPressed(void);
/*
** ===================================================================
**     Method      :  RTT1_StdIOKeyPressed (component SeggerRTT)
**     Description :
**         StdIO handler for Shell
**     Parameters  : None
**     Returns     :
**         ---             - True if there are characters in teh input
**                           buffer
** ===================================================================
*/

void RTT1_StdIOReadChar(uint8_t *c);
/*
** ===================================================================
**     Method      :  RTT1_StdIOReadChar (component SeggerRTT)
**     Description :
**         StdIO Handler for reading a character. It returns a zero
**         byte if there is no character in input buffer.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * c               - Pointer to where to store the received
**                           character
**     Returns     : Nothing
** ===================================================================
*/

void RTT1_StdIOSendChar(uint8_t ch);
/*
** ===================================================================
**     Method      :  RTT1_StdIOSendChar (component SeggerRTT)
**     Description :
**         StdIO handler to sends a character.
**     Parameters  :
**         NAME            - DESCRIPTION
**         ch              - Character to send
**     Returns     : Nothing
** ===================================================================
*/

uint8_t RTT1_RecvChar(uint8_t *c);
/*
** ===================================================================
**     Method      :  RTT1_RecvChar (component SeggerRTT)
**     Description :
**         Receives a character from channel 0. Returns ERR_RXEMPTY if
**         no character available
**     Parameters  :
**         NAME            - DESCRIPTION
**       * c               - Pointer to where to store the received
**                           character
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t RTT1_SendChar(uint8_t ch);
/*
** ===================================================================
**     Method      :  RTT1_SendChar (component SeggerRTT)
**     Description :
**         Sends a character to channel 0.
**     Parameters  :
**         NAME            - DESCRIPTION
**         ch              - Character to send
**     Returns     :
**         ---             - Error code. ERR_OK if character has been
**                           sent, ERR_TXFULL otherwise.
** ===================================================================
*/

#define RTT1_GetCharsInRxBuf() \
  SEGGER_RTT_HasKey()

/*
** ===================================================================
**     Method      :  RTT1_GetCharsInRxBuf (component SeggerRTT)
**     Description :
**         Returns the number of characters in the receive buffer.
**     Parameters  : None
**     Returns     :
**         ---             - Number of characters in the input buffer,
**                           zero for none available.
** ===================================================================
*/

void RTT1_Init(void);

/*
** ===================================================================
**     Method      :  RTT1_Init (component SeggerRTT)
**     Description :
**         Initializes the RTT Control Block.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define RTT1_TerminalOut(TerminalId, s) \
  SEGGER_RTT_TerminalOut(TerminalId, s)

/*
** ===================================================================
**     Method      :  RTT1_TerminalOut (component SeggerRTT)
**     Description :
**         Writes a string to the given terminal without changing the
**         terminal for channel 0.
**     Parameters  :
**         NAME            - DESCRIPTION
**         TerminalId      - TerminalId, 0..15
**       * s               - Pointer to string
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define RTT1_SetTerminal(TerminalId) \
  SEGGER_RTT_SetTerminal(TerminalId)

/*
** ===================================================================
**     Method      :  RTT1_SetTerminal (component SeggerRTT)
**     Description :
**          Sets the terminal to be used for output on channel 0.
**     Parameters  :
**         NAME            - DESCRIPTION
**         TerminalId      - Terminal ID, 0..15
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define RTT1_ConfigUpBuffer(BufferIndex, sName, pBuffer, BufferSize, Flags) \
  SEGGER_RTT_ConfigUpBuffer(BufferIndex, sName, pBuffer, BufferSize, Flags)

/*
** ===================================================================
**     Method      :  RTT1_ConfigUpBuffer (component SeggerRTT)
**     Description :
**         Configures the Up (device to host) buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**         BufferIndex     - Buffer index
**         sName           - Buffer name
**       * pBuffer         - Pointer to buffer
**         intBufferSize   - Size of buffer in bytes
**         Flags           - SEGGER_RTT_MODE_NO_BLOCK_SKIP,
**                           SEGGER_RTT_MODE_NO_BLOCK_TRIM or
**                           SEGGER_RTT_MODE_BLOCK_IF_FIFO_FULL
**     Returns     :
**         ---             - Error code, >=0 OK, <0 Error
** ===================================================================
*/

#define RTT1_ConfigDownBuffer(BufferIndex, sName, pBuffer, BufferSize, Flags) \
  SEGGER_RTT_ConfigDownBuffer(BufferIndex, sName, pBuffer, BufferSize, Flags)

/*
** ===================================================================
**     Method      :  RTT1_ConfigDownBuffer (component SeggerRTT)
**     Description :
**         Configures the Down (host to device) buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**         BufferIndex     - Buffer index
**         sName           - Buffer name
**       * pBuffer         - Pointer to buffer
**         intBufferSize   - Size of buffer in bytes
**         Flags           - SEGGER_RTT_MODE_NO_BLOCK_SKIP,
**                           SEGGER_RTT_MODE_NO_BLOCK_TRIM or
**                           SEGGER_RTT_MODE_BLOCK_IF_FIFO_FULL
**     Returns     :
**         ---             - Error code, >=0 OK, <0 Error
** ===================================================================
*/

/* END RTT1. */

#endif
/* ifndef __RTT1_H */
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
