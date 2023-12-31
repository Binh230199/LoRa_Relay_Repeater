/*
 * lora.h
 *
 *  Created on: Mar 6, 2023
 *      Author: Hoang Van Binh (gmail: binhhv.23.1.99@gmail.com)
 */

#ifndef LORA_H_
#define LORA_H_

#include <stdbool.h>
#include <stdint.h>

#include "wlv_def.h"

/**
 * @brief LORA_ModeTypeDef
 *
 */
typedef enum
{
	LORA_MODE_SLEEP,
	LORA_MODE_STANDBY,
	LORA_MODE_FSTX,
	LORA_MODE_TX,
	LORA_MODE_RSRX,
	LORA_MODE_RXCONTINUOUS,
	LORA_MODE_RXSINGLE,
	LORA_MODE_CAD,
	LORA_MODE_LORA,
	LORA_MODE_RESET = 0xF8U
} LORA_ModeTypeDef;

/**
 * @brief LORA_SpredFactTypeDef
 *
 */
typedef enum
{
	LORA_SF_6 = 0x06U,
	LORA_SF_7,
	LORA_SF_8,
	LORA_SF_9,
	LORA_SF_10,
	LORA_SF_11,
	LORA_SF_12,
} LORA_SpredFactTypeDef;

/**
 * @brief LORA_SigBandTypeDef
 *
 */
typedef enum
{
	LORA_BW_7D8,
	LORA_BW_10D4,
	LORA_BW_15D6,
	LORA_BW_20D8,
	LORA_BW_31D25,
	LORA_BW_41D7,
	LORA_BW_62D5,
	LORA_BW_125,
	LORA_BW_250,
	LORA_BW_500,
} LORA_SigBandTypeDef;

/**
 * @brief LORA_ErrCodRateTypeDef
 *
 */
typedef enum
{
	LORA_CR_45 = 0x01U,
	LORA_CR_46 = 0x02U,
	LORA_CR_47 = 0x03U,
	LORA_CR_48 = 0x04U,
} LORA_ErrCodRateTypeDef;

/**
 * @brief LORA_PowerTxTypeDef
 *
 */
typedef enum
{
	LORA_PW_2dBm,
	LORA_PW_3dBm,
	LORA_PW_4dBm,
	LORA_PW_5dBm,
	LORA_PW_6dBm,
	LORA_PW_7dBm,
	LORA_PW_8dBm,
	LORA_PW_9dBm,
	LORA_PW_10dBm,
	LORA_PW_11dBm,
	LORA_PW_12dBm,
	LORA_PW_13dBm,
	LORA_PW_14dBm,
	LORA_PW_15dBm,
	LORA_PW_16dBm,
	LORA_PW_17dBm,
} LORA_PowerTxTypeDef;

/**
 * @brief LORA_LNATypeDef
 *
 */
typedef enum
{
	LORA_LNA_G1 = 0x01U,
	LORA_LNA_G2 = 0x02U,
	LORA_LNA_G3 = 0x03U,
	LORA_LNA_G4 = 0x04U,
	LORA_LNA_G5 = 0x05U,
	LORA_LNA_G6 = 0x06U,
} LORA_LNATypeDef;

/**
 * @brief LORA_CADStatusTypeDef
 *
 */
typedef enum
{
	LORA_CAD_DETECT = 0x00U,
	LORA_CAD_UNDETECT = 0x01U,
	LORA_CAD_ERROR = 0x02U
} LORA_CADStatusTypeDef;

/**
 * @brief LORA_HandleTypeDef handle structure definition
 *
 */
typedef struct lora
{
	uint32_t freq;
	LORA_SpredFactTypeDef SF;
	LORA_SigBandTypeDef BW;
	LORA_ErrCodRateTypeDef CR;
	LORA_PowerTxTypeDef ptx;
	LORA_LNATypeDef LNA;
	LORA_ModeTypeDef mode;
	uint16_t preamble;
	THT_StatusTypeDef (*init)(struct lora *const me);
	THT_StatusTypeDef (*transmit)(struct lora *const me, const uint8_t *pBuffer, uint16_t size, uint32_t timeout);
	THT_StatusTypeDef (*receive)(struct lora *const me, uint8_t *pBuffer, uint16_t size, uint32_t timeout);
	THT_StatusTypeDef (*startReceiveIT)(struct lora *const me);
	THT_StatusTypeDef (*receiveIT)(struct lora *const me, uint8_t *pBuffer, uint16_t size);
	THT_StatusTypeDef (*shutdown)(struct lora *const me);
	int16_t (*getRSSI)(struct lora *const me);
} LORA_HandleTypeDef;

typedef THT_StatusTypeDef (*loraInit)(struct lora *const me);
typedef THT_StatusTypeDef (*loraTransmit)(struct lora *const me, const uint8_t *pBuffer, uint16_t size, uint32_t timeout);
typedef THT_StatusTypeDef (*loraReceive)(struct lora *const me, uint8_t *pBuffer, uint16_t size, uint32_t timeout);
typedef THT_StatusTypeDef (*loraStartReceiveOnIRQ)(struct lora *const me);
typedef THT_StatusTypeDef (*loraReceiveOnIRQ)(struct lora *const me, uint8_t *pBuffer, uint16_t size);
typedef THT_StatusTypeDef (*loraShutdown)(struct lora *const me);
typedef int16_t (*loraGetRSSI)(struct lora *const me);

THT_StatusTypeDef LORA_init(LORA_HandleTypeDef *const me);
THT_StatusTypeDef LORA_receivePolling(LORA_HandleTypeDef *const me, uint8_t *pBuffer, uint16_t size, uint32_t timeout);
THT_StatusTypeDef LORA_startReceiveIT(LORA_HandleTypeDef *const me);
THT_StatusTypeDef LORA_receiveIT(LORA_HandleTypeDef *const me, uint8_t *pBuffer, uint16_t size);
THT_StatusTypeDef LORA_transmit(LORA_HandleTypeDef *const me, const uint8_t *pBuffer, uint16_t size, uint32_t timeout);
THT_StatusTypeDef LORA_shutdown(LORA_HandleTypeDef *const me);
int16_t LORA_getRSSI(LORA_HandleTypeDef *const me);

#endif /* LORA_H_ */
