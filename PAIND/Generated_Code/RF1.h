/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : RF1.h
**     Project     : PAIND
**     Processor   : MKL25Z128VLK4
**     Component   : nRF24L01
**     Version     : Component 01.086, Driver 01.00, CPU db: 3.00.000
**     Repository  : My Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-10-11, 15:54, # CodeGen: 37
**     Abstract    :
**         This component implements a driver for the Nordic Semiconductor nRF24L01 2.4 GHz transceiver.
**     Settings    :
**          Component name                                 : RF1
**          Wait                                           : WAIT1
**          CE Pin                                         : CE
**          CSN Pin                                        : CSN
**          Software SPI                                   : Disabled
**          Hardware SPI                                   : Enabled
**            SPI                                          : SM1
**          Switch Bus                                     : Disabled
**          Application Event Handler                      : RADIO_OnInterrupt
**          IRQ Pin                                        : Disabled
**     Contents    :
**         ConfigureSPI               - void RF1_ConfigureSPI(void);
**         WriteRegister              - void RF1_WriteRegister(uint8_t reg, uint8_t val);
**         ReadRegister               - uint8_t RF1_ReadRegister(uint8_t reg);
**         ReadRegisterData           - void RF1_ReadRegisterData(uint8_t reg, uint8_t *buf, uint8_t bufSize);
**         WriteRegisterData          - void RF1_WriteRegisterData(byte reg, uint8_t *buf, uint8_t bufSize);
**         WriteRead                  - uint8_t RF1_WriteRead(uint8_t val);
**         Write                      - void RF1_Write(uint8_t val);
**         GetStatus                  - uint8_t RF1_GetStatus(void);
**         GetStatusClrIRQ            - uint8_t RF1_GetStatusClrIRQ(void);
**         ResetStatusIRQ             - void RF1_ResetStatusIRQ(uint8_t flags);
**         TxPayload                  - void RF1_TxPayload(uint8_t *payload, uint8_t payloadSize);
**         RxPayload                  - void RF1_RxPayload(uint8_t *payload, uint8_t payloadSize);
**         StopRxTx                   - void RF1_StopRxTx(void);
**         StartRxTx                  - void RF1_StartRxTx(void);
**         EnableAutoAck              - uint8_t RF1_EnableAutoAck(uint8_t pipes);
**         SetStaticPipePayload       - uint8_t RF1_SetStaticPipePayload(uint8_t pipe, uint8_t payloadBytes);
**         EnableDynamicPayloadLength - uint8_t RF1_EnableDynamicPayloadLength(uint8_t pipeMask);
**         WriteFeature               - uint8_t RF1_WriteFeature(uint8_t featureMask);
**         ReadFeature                - uint8_t RF1_ReadFeature(uint8_t *featureMask);
**         ReadNofRxPayload           - uint8_t RF1_ReadNofRxPayload(uint8_t *nof);
**         ReadObserveTxRegister      - uint8_t RF1_ReadObserveTxRegister(uint8_t *nofLoss, uint8_t *nofRetransmitted);
**         ReadReceivedPowerDetector  - uint8_t RF1_ReadReceivedPowerDetector(uint8_t *rpd);
**         SetChannel                 - uint8_t RF1_SetChannel(uint8_t channel);
**         GetChannel                 - uint8_t RF1_GetChannel(uint8_t *channel);
**         ConstantCarrierWave        - uint8_t RF1_ConstantCarrierWave(bool turnOn);
**         SetOutputPower             - uint8_t RF1_SetOutputPower(int8_t power);
**         GetOutputPower             - uint8_t RF1_GetOutputPower(int8_t *power);
**         SetDataRate                - uint8_t RF1_SetDataRate(uint16_t rate);
**         GetDataRate                - uint8_t RF1_GetDataRate(uint16_t *rate);
**         GetFifoStatus              - uint8_t RF1_GetFifoStatus(uint8_t *status);
**         PollInterrupt              - void RF1_PollInterrupt(void);
**         Deinit                     - void RF1_Deinit(void);
**         Init                       - void RF1_Init(void);
**
**     License   : Open Source (LGPL)
**     Copyright : Erich Styger, 2013-2014, all rights reserved.
**     Web       : www.mcuoneclipse.com
**     This an open source software implementing a driver using Processor Expert.
**     This is a free software and is opened for education, research and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file RF1.h
** @version 01.00
** @brief
**         This component implements a driver for the Nordic Semiconductor nRF24L01 2.4 GHz transceiver.
*/         
/*!
**  @addtogroup RF1_module RF1 module documentation
**  @{
*/         

#ifndef __RF1_H
#define __RF1_H

/* MODULE RF1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "WAIT1.h"
#include "CE1.h"
#include "CSN1.h"
#include "SM1.h"

#include "Cpu.h"


#define RF1_IRQ_PIN_ENABLED   0
  /*!< no IRQ pin or not enabled */

/* if having multiple users on the SPI bus, enable bus sharing/switching */
  #define RF1_SWITCH_BUS   0
  #define RF1_BAUD_RATE_MODE   0 /* dummy */

/* Memory Map - register address defines */
#define RF1_CONFIG      0x00 /* CONFIG register */

#define RF1_EN_AA       0x01 /* EN_AA register: configures auto-acknowledge per pipe */
  /* EN_AA register bitwise definitions */
  /* masks for auto acknowledge per pipe */
  #define RF1_EN_AA_RESERVED      0xC0
  #define RF1_EN_AA_ENAA_ALL      0x3F
  #define RF1_EN_AA_ENAA_P5       0x20
  #define RF1_EN_AA_ENAA_P4       0x10
  #define RF1_EN_AA_ENAA_P3       0x08
  #define RF1_EN_AA_ENAA_P2       0x04
  #define RF1_EN_AA_ENAA_P1       0x02
  #define RF1_EN_AA_ENAA_P0       0x01
  #define RF1_EN_AA_ENAA_NONE     0x00

#define RF1_EN_RXADDR   0x02 /* EN_RXADDR register */
#define RF1_SETUP_AW    0x03 /* SETUP_AW register */
#define RF1_SETUP_RETR  0x04

#define RF1_RF_CH       0x05 /* Channel register, valid channels from 0x0 to 0x7F */
  /* RF_CH register bitwise definitions */
  #define RF1_RF_CH_RESERVED    0x80

#define RF1_RF_SETUP    0x06 /* RF_SETUP register */
  /* RF_SETUP register bits: */
  #define RF1_RF_SETUP_CONT_WAVE      (1<<7) /* Enables continuous carrier transmit when high. */
  #define RF1_RF_SETUP_PLL_LOCK       (1<<4) /* Force PLL lock signal. Only used in test */

  #define RF1_RF_SETUP_RF_DR_MASK     (RF1_RF_SETUP_RF_DR_LOW|RF1_RF_SETUP_RF_DR_HIGH) /* xx: mask bits */
  #define RF1_RF_SETUP_RF_DR_LOW      (1<<5) /* Set RF Data Rate to 250kbps. See RF_DR_HIGH for encoding. */
  #define RF1_RF_SETUP_RF_DR_HIGH     (1<<3) /* Select between the high speed data rates. */
  #define RF1_RF_SETUP_RF_DR_1000     (0) /* RF_DR_LOW|RF_DR_HIGH: 00 */
  #define RF1_RF_SETUP_RF_DR_2000     (RF1_RF_SETUP_RF_DR_HIGH) /* RF_DR_LOW|RF_DR_HIGH: 01 */
  #define RF1_RF_SETUP_RF_DR_250      (RF1_RF_SETUP_RF_DR_LOW)  /* RF_DR_LOW|RF_DR_HIGH: 10 */

  #define RF1_RF_SETUP_RF_PWR_MASK    (3<<1) /* xx: mask bits */
  #define RF1_RF_SETUP_RF_PWR_18      (0<<1) /* 00: -18dBm */
  #define RF1_RF_SETUP_RF_PWR_12      (1<<1) /* 01: -12dBm */
  #define RF1_RF_SETUP_RF_PWR_10      (2<<1) /* 10: -10dBm */
  #define RF1_RF_SETUP_RF_PWR_0       (3<<1) /* 11: 0dBm, default */

#define RF1_STATUS      0x07
  /* STATUS register bits */
  #define RF1_STATUS_RESERVED                    0x80   /* bit 1xxx xxxx: This bit is reserved */
  #define RF1_STATUS_RX_DR                       0x40   /* bit x1xx xxxx: Data ready RX FIFO interrupt. Asserted when new data arrives RX FIFO */
  #define RF1_STATUS_TX_DS                       0x20   /* bit xx1x xxxx: Data sent TX FIFO interrupt. Asserted when packet transmitted on TX. */
  #define RF1_STATUS_MAX_RT                      0x10   /* bit xxx1 xxxx: maximum number of TX retransmit interrupts */
  #define RF1_STATUS_RX_P_NO                     0x0E
  #define RF1_STATUS_RX_P_NO_RX_FIFO_EMPTY       0x0E
  #define RF1_STATUS_RX_P_NO_UNUSED              0x0C
  #define RF1_STATUS_RX_P_NO_5                   0x0A
  #define RF1_STATUS_RX_P_NO_4                   0x08
  #define RF1_STATUS_RX_P_NO_3                   0x06
  #define RF1_STATUS_RX_P_NO_2                   0x04
  #define RF1_STATUS_RX_P_NO_1                   0x02
  #define RF1_STATUS_RX_P_NO_0                   0x00   /* bit xxxx 111x: pipe number for payload */
  #define RF1_STATUS_TX_FULL                     0x01   /* bit xxxx xxx1: if bit set, then TX FIFO is full */


#define RF1_OBSERVE_TX  0x08
#define RF1_RPD         0x09 /* Received Power Detector */
#define RF1_RX_ADDR_P0  0x0A
#define RF1_RX_ADDR_P1  0x0B
#define RF1_RX_ADDR_P2  0x0C
#define RF1_RX_ADDR_P3  0x0D
#define RF1_RX_ADDR_P4  0x0E
#define RF1_RX_ADDR_P5  0x0F
#define RF1_TX_ADDR     0x10
#define RF1_RX_PW_P0    0x11 /* register to set static RX payload on pipe 0, 0 to 32 bytes */
#define RF1_RX_PW_P1    0x12 /* register to set static RX payload on pipe 1, 0 to 32 bytes */
#define RF1_RX_PW_P2    0x13 /* register to set static RX payload on pipe 2, 0 to 32 bytes */
#define RF1_RX_PW_P3    0x14 /* register to set static RX payload on pipe 3, 0 to 32 bytes */
#define RF1_RX_PW_P4    0x15 /* register to set static RX payload on pipe 4, 0 to 32 bytes */
#define RF1_RX_PW_P5    0x16 /* register to set static RX payload on pipe 5, 0 to 32 bytes */

#define RF1_FIFO_STATUS 0x17 /* FIFO status register */
  /* FIFO_STATUS register bits */
  #define RF1_FIFO_STATUS_RESERVED  (0x8C) /* reserved bits */
  #define RF1_FIFO_STATUS_TX_REUSE  (1<<6)
  #define RF1_FIFO_STATUS_TX_FULL   (1<<5)
  #define RF1_FIFO_STATUS_TX_EMPTY  (1<<4)
  #define RF1_FIFO_STATUS_RX_FULL   (1<<1)
  #define RF1_FIFO_STATUS_RX_EMPTY  (1<<0)

#define RF1_DYNPD       0x1C /* enable dynamic payload length */
  /* DYNPD register bits: */
  #define RF1_DYNPD_DPL_P0  (1<<0) /* enable DPL for pipe 0 */
  #define RF1_DYNPD_DPL_P1  (1<<1) /* enable DPL for pipe 1 */
  #define RF1_DYNPD_DPL_P2  (1<<2) /* enable DPL for pipe 2 */
  #define RF1_DYNPD_DPL_P3  (1<<3) /* enable DPL for pipe 3 */
  #define RF1_DYNPD_DPL_P4  (1<<4) /* enable DPL for pipe 4 */
  #define RF1_DYNPD_DPL_P5  (1<<5) /* enable DPL for pipe 5 */
#define RF1_FEATURE     0x1D /* feature register */
  /* FEATURE register bits: */
  #define RF1_FEATURE_EN_DPL       (1<<2) /* enables dynamic payload length */
  #define RF1_FEATURE_EN_ACK_PAY   (1<<1) /* enables payload with ACK */
  #define RF1_FEATURE_EN_DYN_PAY   (1<<0) /* enables the W_TX_PAYLOAD_NOACK command */

/* Bit Mnemonics */
/* CONFIG Register Bits */
#define RF1_MASK_RX_DR  (1<<6)  /* Mask interrupt caused by RX_DR: 1: interrupt masked. 0: interrupt enabled */
#define RF1_MASK_TX_DS  (1<<5)  /* Mask interrupt caused by TX_DS: 1: interrupt masked. 0: interrupt enabled */
#define RF1_MASK_MAX_RT (1<<4)  /* Mask interrupt caused by MAX_RT. 1: interrupt not reflected on IRQ pin. 0: reflect MAX_RT as active low interrupt on IRQ pin */
#define RF1_EN_CRC      (1<<3)  /* Enable CRC. Forced high if on of the bits in EN_AA is high */
#define RF1_CRCO        (1<<2)  /* CRC encoding scheme, 0: 1 byte, 1: 2 bytes */
#define RF1_PWR_UP      (1<<1)  /* 1: Power up, 0: Power down */
#define RF1_PRIM_RX     (1<<0)  /* 1: PRX, 0: PTX */
#define RF1_PRIM_TX     (0)     /* 0: PTX */

#define RF1_ERX_P5      5
#define RF1_ERX_P4      4
#define RF1_ERX_P3      3
#define RF1_ERX_P2      2
#define RF1_ERX_P1      1
#define RF1_ERX_P0      0
#define RF1_AW          0
#define RF1_ARD         4
#define RF1_ARC         0
#define RF1_PLL_LOCK    4
#define RF1_RF_DR_HIGH  3
#define RF1_RF_DR_LOW   5
#define RF1_RF_PWR      1
#define RF1_LNA_HCURR   0
#define RF1_RX_DR       6
#define RF1_TX_DS       5
#define RF1_MAX_RT      4
#define RF1_RX_P_NO     1
#define RF1_TX_FULL     0
#define RF1_PLOS_CNT    4
#define RF1_ARC_CNT     0
#define RF1_TX_REUSE    6
#define RF1_FIFO_FULL   5
#define RF1_TX_EMPTY    4
#define RF1_RX_FULL     1
#define RF1_RX_EMPTY    0

/* Command Name Mnemonics (Instructions) */
#define RF1_R_REGISTER           0x00 /* read register command, the address is encoded into the command (000A AAAA) */
#define RF1_W_REGISTER           0x20 /* write register command, the address is encoded into the command (001A AAAA) */
#define RF1_REGISTER_MASK        0x1F /* mask used for R_REGISTER and W_REGISTER commands */
#define RF1_R_RX_PAYLOAD         0x61 /* read RX payload command */
#define RF1_W_TX_PAYLOAD         0xA0 /* write TX payload command */
#define RF1_FLUSH_TX             0xE1 /* flush TX FIFO command */
#define RF1_FLUSH_RX             0xE2 /* flush RX FIFO command */
#define RF1_REUSE_TX_PL          0xE3 /* reuse last transmitted payload command */
#define RF1_R_RX_PL_WID          0x60 /* read RX payload width for the top R_RX_PAYLOAD in the RX FIFO */
#define RF1_W_ACK_PAYLOAD        0xA8 /* used in RX mode. Write payload to be transmitted with ACK packet to pipe (1010 1PPP) */
#define RF1_W_TX_PAYLOAD_NO_ACK  0xB0 /* used in TX mode. Disable AUTOACK on this specific packet */
#define RF1_NOP                  0xFF /* no operation command, used for reading STATUS register */

#define RF1_CONFIG_DEFAULT_VAL         0x08
#define RF1_EN_AA_DEFAULT_VAL          0x3F
#define RF1_EN_RXADDR_DEFAULT_VAL      0x03
#define RF1_SETUP_AW_DEFAULT_VAL       0x03
#define RF1_SETUP_RETR_DEFAULT_VAL     0x03
#define RF1_RF_CH_DEFAULT_VAL          0x02
#define RF1_RF_SETUP_DEFAULT_VAL       0x0F
#define RF1_STATUS_DEFAULT_VAL         0x0E
#define RF1_OBSERVE_TX_DEFAULT_VAL     0x00
#define RF1_CD_DEFAULT_VAL             0x00
#define RF1_RX_ADDR_P0_B0_DEFAULT_VAL  0xE7
#define RF1_RX_ADDR_P0_B1_DEFAULT_VAL  0xE7
#define RF1_RX_ADDR_P0_B2_DEFAULT_VAL  0xE7
#define RF1_RX_ADDR_P0_B3_DEFAULT_VAL  0xE7
#define RF1_RX_ADDR_P0_B4_DEFAULT_VAL  0xE7
#define RF1_RX_ADDR_P1_B0_DEFAULT_VAL  0xC2
#define RF1_RX_ADDR_P1_B1_DEFAULT_VAL  0xC2
#define RF1_RX_ADDR_P1_B2_DEFAULT_VAL  0xC2
#define RF1_RX_ADDR_P1_B3_DEFAULT_VAL  0xC2
#define RF1_RX_ADDR_P1_B4_DEFAULT_VAL  0xC2
#define RF1_RX_ADDR_P2_DEFAULT_VAL     0xC3
#define RF1_RX_ADDR_P3_DEFAULT_VAL     0xC4
#define RF1_RX_ADDR_P4_DEFAULT_VAL     0xC5
#define RF1_RX_ADDR_P5_DEFAULT_VAL     0xC6
#define RF1_TX_ADDR_B0_DEFAULT_VAL     0xE7
#define RF1_TX_ADDR_B1_DEFAULT_VAL     0xE7
#define RF1_TX_ADDR_B2_DEFAULT_VAL     0xE7
#define RF1_TX_ADDR_B3_DEFAULT_VAL     0xE7
#define RF1_TX_ADDR_B4_DEFAULT_VAL     0xE7
#define RF1_RX_PW_P0_DEFAULT_VAL       0x00
#define RF1_RX_PW_P1_DEFAULT_VAL       0x00
#define RF1_RX_PW_P2_DEFAULT_VAL       0x00
#define RF1_RX_PW_P3_DEFAULT_VAL       0x00
#define RF1_RX_PW_P4_DEFAULT_VAL       0x00
#define RF1_RX_PW_P5_DEFAULT_VAL       0x00
#define RF1_FIFO_STATUS_DEFAULT_VAL    0x11

/* CONFIG register bitwise definitions */
#define RF1_CONFIG_RESERVED     0x80
#define RF1_CONFIG_MASK_RX_DR   0x40
#define RF1_CONFIG_MASK_TX_DS   0x20
#define RF1_CONFIG_MASK_MAX_RT  0x10
#define RF1_CONFIG_EN_CRC       0x08
#define RF1_CONFIG_CRCO         0x04
#define RF1_CONFIG_PWR_UP       0x02
#define RF1_CONFIG_PRIM_RX      0x01

/* EN_RXADDR register bitwise definitions */
#define RF1_EN_RXADDR_RESERVED  0xC0
#define RF1_EN_RXADDR_ERX_ALL   0x3F
#define RF1_EN_RXADDR_ERX_P5    0x20
#define RF1_EN_RXADDR_ERX_P4    0x10
#define RF1_EN_RXADDR_ERX_P3    0x08
#define RF1_EN_RXADDR_ERX_P2    0x04
#define RF1_EN_RXADDR_ERX_P1    0x02
#define RF1_EN_RXADDR_ERX_P0    0x01
#define RF1_EN_RXADDR_ERX_NONE  0x00

/* SETUP_AW register bitwise definitions */
#define RF1_SETUP_AW_RESERVED 0xFC
#define RF1_SETUP_AW          0x03
#define RF1_SETUP_AW_5BYTES   0x03
#define RF1_SETUP_AW_4BYTES   0x02
#define RF1_SETUP_AW_3BYTES   0x01
#define RF1_SETUP_AW_ILLEGAL  0x00

/* SETUP_RETR register bitwise definitions */
#define RF1_SETUP_RETR_ARD        0xF0
#define RF1_SETUP_RETR_ARD_4000   0xF0 /* 4400 us retry delay */
#define RF1_SETUP_RETR_ARD_3750   0xE0 /* 3750 us retry delay */
#define RF1_SETUP_RETR_ARD_3500   0xD0 /* 3500 us retry delay */
#define RF1_SETUP_RETR_ARD_3250   0xC0 /* 3250 us retry delay */
#define RF1_SETUP_RETR_ARD_3000   0xB0 /* 3000 us retry delay */
#define RF1_SETUP_RETR_ARD_2750   0xA0 /* 2750 us retry delay */
#define RF1_SETUP_RETR_ARD_2500   0x90 /* 2500 us retry delay */
#define RF1_SETUP_RETR_ARD_2250   0x80 /* 2250 us retry delay */
#define RF1_SETUP_RETR_ARD_2000   0x70 /* 2000 us retry delay */
#define RF1_SETUP_RETR_ARD_1750   0x60 /* 1750 us retry delay */
#define RF1_SETUP_RETR_ARD_1500   0x50 /* 1500 us retry delay */
#define RF1_SETUP_RETR_ARD_1250   0x40 /* 1250 us retry delay */
#define RF1_SETUP_RETR_ARD_1000   0x30 /* 1000 us retry delay */
#define RF1_SETUP_RETR_ARD_750    0x20 /* 750 us retry delay */
#define RF1_SETUP_RETR_ARD_500    0x10 /* 500 us retry delay */
#define RF1_SETUP_RETR_ARD_250    0x00 /* 250 us retry delay */
#define RF1_SETUP_RETR_ARC        0x0F
#define RF1_SETUP_RETR_ARC_15     0x0F /* 15 retry count */
#define RF1_SETUP_RETR_ARC_14     0x0E /* 14 retry count */
#define RF1_SETUP_RETR_ARC_13     0x0D /* 13 retry count */
#define RF1_SETUP_RETR_ARC_12     0x0C /* 12 retry count */
#define RF1_SETUP_RETR_ARC_11     0x0B /* 11 retry count */
#define RF1_SETUP_RETR_ARC_10     0x0A /* 10 retry count */
#define RF1_SETUP_RETR_ARC_9      0x09 /* 9 retry count */
#define RF1_SETUP_RETR_ARC_8      0x08 /* 8 retry count */
#define RF1_SETUP_RETR_ARC_7      0x07 /* 7 retry count */
#define RF1_SETUP_RETR_ARC_6      0x06 /* 6 retry count */
#define RF1_SETUP_RETR_ARC_5      0x05 /* 5 retry count */
#define RF1_SETUP_RETR_ARC_4      0x04 /* 4 retry count */
#define RF1_SETUP_RETR_ARC_3      0x03 /* 3 retry count */
#define RF1_SETUP_RETR_ARC_2      0x02 /* 2 retry count */
#define RF1_SETUP_RETR_ARC_1      0x01 /* 1 retry count */
#define RF1_SETUP_RETR_ARC_0      0x00 /* 0 retry count, retry disabled */

/* OBSERVE_TX register bitwise definitions */
#define RF1_OBSERVE_TX_PLOS_CNT   0xF0
#define RF1_OBSERVE_TX_ARC_CNT    0x0F

/* CD register bitwise definitions for nRF24L01 */
//#define RF1_CD_RESERVED   0xFE
//#define RF1_CD_CD         0x01

/* RPD register bitwise definitions for nRF24L01+ */
#define RF1_RPD_RESERVED    0xFE
#define RF1_RPD_RPD         0x01

/* RX_PW_P0 register bitwise definitions */
#define RF1_RX_PW_P0_RESERVED 0xC0

/* RX_PW_P0 register bitwise definitions */
#define RF1_RX_PW_P0_RESERVED 0xC0

/* RX_PW_P1 register bitwise definitions */
#define RF1_RX_PW_P1_RESERVED 0xC0

/* RX_PW_P2 register bitwise definitions */
#define RF1_RX_PW_P2_RESERVED 0xC0

/* RX_PW_P3 register bitwise definitions */
#define RF1_RX_PW_P3_RESERVED 0xC0

/* RX_PW_P4 register bitwise definitions */
#define RF1_RX_PW_P4_RESERVED 0xC0

/* RX_PW_P5 register bitwise definitions */
#define RF1_RX_PW_P5_RESERVED 0xC0



void RF1_Init(void);
/*
** ===================================================================
**     Method      :  RF1_Init (component nRF24L01)
**     Description :
**         Initialization method
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void RF1_WriteRegister(uint8_t reg, uint8_t val);
/*
** ===================================================================
**     Method      :  RF1_WriteRegister (component nRF24L01)
**     Description :
**         Write a register value to the transceiver
**     Parameters  :
**         NAME            - DESCRIPTION
**         reg             - Register address to write
**         val             - Value to write
**     Returns     : Nothing
** ===================================================================
*/

uint8_t RF1_ReadRegister(uint8_t reg);
/*
** ===================================================================
**     Method      :  RF1_ReadRegister (component nRF24L01)
**     Description :
**         Reads a register from the transceiver
**     Parameters  :
**         NAME            - DESCRIPTION
**         reg             - Register address
**     Returns     :
**         ---             - value read
** ===================================================================
*/

void RF1_ReadRegisterData(uint8_t reg, uint8_t *buf, uint8_t bufSize);
/*
** ===================================================================
**     Method      :  RF1_ReadRegisterData (component nRF24L01)
**     Description :
**         Read multiple bytes from the bus.
**     Parameters  :
**         NAME            - DESCRIPTION
**         reg             - Register address
**       * buf             - Pointer to buffer where to store the values
**         bufSize         - Size of the destination buffer
**     Returns     : Nothing
** ===================================================================
*/

void RF1_WriteRegisterData(byte reg, uint8_t *buf, uint8_t bufSize);
/*
** ===================================================================
**     Method      :  RF1_WriteRegisterData (component nRF24L01)
**     Description :
**         Write multiple bytes to the bus.
**     Parameters  :
**         NAME            - DESCRIPTION
**         reg             - Register address
**       * buf             - Pointer to data buffer to write
**         bufSize         - Size of buffer in bytes
**     Returns     : Nothing
** ===================================================================
*/

uint8_t RF1_WriteRead(uint8_t val);
/*
** ===================================================================
**     Method      :  RF1_WriteRead (component nRF24L01)
**     Description :
**         Writes a byte and reads back one byte
**     Parameters  :
**         NAME            - DESCRIPTION
**         val             - Value to write to the bus
**     Returns     :
**         ---             - Value read from the bus
** ===================================================================
*/

void RF1_Write(uint8_t val);
/*
** ===================================================================
**     Method      :  RF1_Write (component nRF24L01)
**     Description :
**         Writes a byte to the bus, without returning the byte read.
**     Parameters  :
**         NAME            - DESCRIPTION
**         val             - Value to write
**     Returns     : Nothing
** ===================================================================
*/

uint8_t RF1_GetStatus(void);
/*
** ===================================================================
**     Method      :  RF1_GetStatus (component nRF24L01)
**     Description :
**         Returns the device status byte
**     Parameters  : None
**     Returns     :
**         ---             - status byte
** ===================================================================
*/

void RF1_ResetStatusIRQ(uint8_t flags);
/*
** ===================================================================
**     Method      :  RF1_ResetStatusIRQ (component nRF24L01)
**     Description :
**         Reset the given flags mask of status bits
**     Parameters  :
**         NAME            - DESCRIPTION
**         flags           - Flags, one or more of
**                           RF24_STATUS_RX_DR, RF24_STATUS_TX_DS,
**                           RF24_STATUS_MAX_RT
**     Returns     : Nothing
** ===================================================================
*/

void RF1_TxPayload(uint8_t *payload, uint8_t payloadSize);
/*
** ===================================================================
**     Method      :  RF1_TxPayload (component nRF24L01)
**     Description :
**         Send the payload to the Tx FIFO and send it
**     Parameters  :
**         NAME            - DESCRIPTION
**       * payload         - Pointer to buffer with payload to
**                           send
**         payloadSize     - Size of payload buffer
**     Returns     : Nothing
** ===================================================================
*/

void RF1_RxPayload(uint8_t *payload, uint8_t payloadSize);
/*
** ===================================================================
**     Method      :  RF1_RxPayload (component nRF24L01)
**     Description :
**         Receive the Rx payload from the FIFO and stores it in a
**         buffer.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * payload         - Pointer to the payload buffer
**         payloadSize     - Size of the payload buffer
**     Returns     : Nothing
** ===================================================================
*/

void RF1_StopRxTx(void);
/*
** ===================================================================
**     Method      :  RF1_StopRxTx (component nRF24L01)
**     Description :
**         Stops sending or receiving (sets CE pin to LOW).
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void RF1_StartRxTx(void);
/*
** ===================================================================
**     Method      :  RF1_StartRxTx (component nRF24L01)
**     Description :
**         Starts sending or receiving (sets CE pin to HIGH).
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

uint8_t RF1_SetChannel(uint8_t channel);
/*
** ===================================================================
**     Method      :  RF1_SetChannel (component nRF24L01)
**     Description :
**         Sets the radio channel (RF_CH register).
**     Parameters  :
**         NAME            - DESCRIPTION
**         channel         - Channel number, valid channel
**                           numbers are 0x0 to 0x7F
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t RF1_EnableAutoAck(uint8_t pipes);
/*
** ===================================================================
**     Method      :  RF1_EnableAutoAck (component nRF24L01)
**     Description :
**         Enables Auto-Acknowledgment for the given pipe(s) (RF_EN_AA
**         register).
**     Parameters  :
**         NAME            - DESCRIPTION
**         pipes           - mask of pipes to be enabled (ENAA_P0
**                           to ENAA_P5)
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t RF1_ReadNofRxPayload(uint8_t *nof);
/*
** ===================================================================
**     Method      :  RF1_ReadNofRxPayload (component nRF24L01)
**     Description :
**         Returns the number of received payload bytes for the top
**         R_RX_PAYLOAD in the RX FIFO
**     Parameters  :
**         NAME            - DESCRIPTION
**       * nof             - Pointer to where to store the number of
**                           bytes. A return value of 0 means that the
**                           pipe is not used, and if the value is >32
**                           then the data is not valid.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t RF1_SetStaticPipePayload(uint8_t pipe, uint8_t payloadBytes);
/*
** ===================================================================
**     Method      :  RF1_SetStaticPipePayload (component nRF24L01)
**     Description :
**         Specifies the static payload for a pipe.
**     Parameters  :
**         NAME            - DESCRIPTION
**         pipe            - Pipe number, 0 to 5
**         payloadBytes    - Number of payload pipes
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t RF1_EnableDynamicPayloadLength(uint8_t pipeMask);
/*
** ===================================================================
**     Method      :  RF1_EnableDynamicPayloadLength (component nRF24L01)
**     Description :
**         Enables dynamic payload length for the give pipes
**     Parameters  :
**         NAME            - DESCRIPTION
**         pipeMask        - Mask of pipes, with 1 for pipe 0,
**                           2 for pipe 1, 4 for pipe 2 and so on.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t RF1_WriteFeature(uint8_t featureMask);
/*
** ===================================================================
**     Method      :  RF1_WriteFeature (component nRF24L01)
**     Description :
**         Writes the FEATURE register
**     Parameters  :
**         NAME            - DESCRIPTION
**         featureMask     - Mask of FEATURE, e.g.
**                           FEATURE_EN_DPL
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t RF1_ReadFeature(uint8_t *featureMask);
/*
** ===================================================================
**     Method      :  RF1_ReadFeature (component nRF24L01)
**     Description :
**         Reads the FEATURE register
**     Parameters  :
**         NAME            - DESCRIPTION
**       * featureMask     - Pointer to value of
**                           FEATURE register
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t RF1_ReadObserveTxRegister(uint8_t *nofLoss, uint8_t *nofRetransmitted);
/*
** ===================================================================
**     Method      :  RF1_ReadObserveTxRegister (component nRF24L01)
**     Description :
**         Reads the OBSERVE_TX register to return the count of loss
**         packets and count of retransmitted packets.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * nofLoss         - Pointer to number of lost packets
**       * nofRetransmitted - Pointer to
**                           number of retransmitted packets
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t RF1_ReadReceivedPowerDetector(uint8_t *rpd);
/*
** ===================================================================
**     Method      :  RF1_ReadReceivedPowerDetector (component nRF24L01)
**     Description :
**         Reads the RPD (Received Power Detector) register. 
**     Parameters  :
**         NAME            - DESCRIPTION
**       * rpd             - Pointer to RPD bit. Bit is one for
**                           received power levels above -64 dBm, zero
**                           for less than -64 dBm.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t RF1_GetChannel(uint8_t *channel);
/*
** ===================================================================
**     Method      :  RF1_GetChannel (component nRF24L01)
**     Description :
**         Returns the radio channel (RF_CH register).
**     Parameters  :
**         NAME            - DESCRIPTION
**       * channel         - Pointer to where to store the
**                           channel number.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t RF1_ConstantCarrierWave(bool turnOn);
/*
** ===================================================================
**     Method      :  RF1_ConstantCarrierWave (component nRF24L01)
**     Description :
**         Put the transceiver into contant carrier wave output for
**         testing. The output power of a radio is a critical factor
**         for achieving wanted range. Output power is also the first
**         test
**     Parameters  :
**         NAME            - DESCRIPTION
**         turnOn          - Set to true to start constant
**                           carrier wave, false to stop it.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t RF1_SetOutputPower(int8_t power);
/*
** ===================================================================
**     Method      :  RF1_SetOutputPower (component nRF24L01)
**     Description :
**         Sets the output power
**     Parameters  :
**         NAME            - DESCRIPTION
**         power           - Ouput power in dBm, either 0, -10, -12
**                           or -18
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t RF1_GetOutputPower(int8_t *power);
/*
** ===================================================================
**     Method      :  RF1_GetOutputPower (component nRF24L01)
**     Description :
**         Returns the current output power
**     Parameters  :
**         NAME            - DESCRIPTION
**       * power           - Pointer to where to store the value.
**                           Returns the output power in dBm
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t RF1_GetStatusClrIRQ(void);
/*
** ===================================================================
**     Method      :  RF1_GetStatusClrIRQ (component nRF24L01)
**     Description :
**         Returns the device status byte and clears any IRQ bits in
**         the status register.
**     Parameters  : None
**     Returns     :
**         ---             - status byte
** ===================================================================
*/

void RF1_PollInterrupt(void);
/*
** ===================================================================
**     Method      :  RF1_PollInterrupt (component nRF24L01)
**     Description :
**         If there is no interrupt line available, this method polls
**         the device to check if there is an interrupt. If 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void RF1_Deinit(void);
/*
** ===================================================================
**     Method      :  RF1_Deinit (component nRF24L01)
**     Description :
**         Driver deinitialization
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

uint8_t RF1_SetDataRate(uint16_t rate);
/*
** ===================================================================
**     Method      :  RF1_SetDataRate (component nRF24L01)
**     Description :
**         Sets the data rate
**     Parameters  :
**         NAME            - DESCRIPTION
**         rate            - Data rate, either 250, 1000 or 2000
**                           (kbps)
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t RF1_GetDataRate(uint16_t *rate);
/*
** ===================================================================
**     Method      :  RF1_GetDataRate (component nRF24L01)
**     Description :
**         Returns the current data rate
**     Parameters  :
**         NAME            - DESCRIPTION
**       * rate            - Pointer to where to store the value.
**                           Returns the data rate, either 250, 1000 or
**                           2000 (kbps)
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t RF1_GetFifoStatus(uint8_t *status);
/*
** ===================================================================
**     Method      :  RF1_GetFifoStatus (component nRF24L01)
**     Description :
**         Returns the FIFO_STATUS register value
**     Parameters  :
**         NAME            - DESCRIPTION
**       * status          - Pointer to where to store the FIFO
**                           status value.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

void RF1_ConfigureSPI(void);
/*
** ===================================================================
**     Method      :  RF1_ConfigureSPI (component nRF24L01)
**     Description :
**         Configures the SPI bus
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END RF1. */

#endif
/* ifndef __RF1_H */
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
