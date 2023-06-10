/*
 * lora.c
 *
 *  Created on: Mar 7, 2023
 *      Author: Hoang Van Binh (gmail: binhhv.23.1.99@gmail.com)
 */

#include "lora.h"

/**
 * @brief LoRa initialize
 *
 * @param me [in] A pointer to LORA_HandleTypeDef structure
 * @return THT_StatusTypeDef
 */
THT_StatusTypeDef LORA_init(LORA_HandleTypeDef *const me)
{
	if (me == NULL)
	{
		return THT_ERROR;
	}
	return (*me->init)(me);
}

/**
 * @brief LoRa send packet
 *
 * @param me [in] A pointer to LORA_HandleTypeDef structure
 * @param pBuffer [in] A pointer to buffer stored data
 * @param size [in] The size of buffer
 * @param timeout [in] Timeout
 * @return THT_StatusTypeDef
 */
THT_StatusTypeDef LORA_transmit(LORA_HandleTypeDef *const me, const uint8_t *pBuffer, uint16_t size, uint32_t timeout)
{
	if (me == NULL || pBuffer == NULL)
	{
		return THT_ERROR;
	}

	return (*me->transmit)(me, pBuffer, size, timeout);
}

/**
 * @brief LoRa receive packed polling mode
 *
 * @param me [in] A pointer to LORA_HandleTypeDef structure
 * @param pBuffer
 * @param size
 * @param timeout
 * @return THT_StatusTypeDef
 */
THT_StatusTypeDef LORA_receivePolling(LORA_HandleTypeDef *const me, uint8_t *pBuffer, uint16_t size, uint32_t timeout)
{
	if (me == NULL || pBuffer == NULL)
	{
		return THT_ERROR;
	}

	return (*me->receive)(me, pBuffer, size, timeout);
}

/**
 * @brief LoRa packet start receive interrupt mode
 *
 * @param me [in] A pointer to LORA_HandleTypeDef structure
 * @return THT_StatusTypeDef
 */
THT_StatusTypeDef LORA_startReceiveIT(LORA_HandleTypeDef *const me)
{
	if (me == NULL)
	{
		return THT_ERROR;
	}

	return (*me->startReceiveIT)(me);
}

/**
 * @brief LoRa receive packet in interrupt mode
 *
 * @param me [in] A pointer to LORA_HandleTypeDef structure
 * @param pBuffer [out] A pointer to buffer used to store data
 * @param size [in] The size of buffer
 * @return THT_StatusTypeDef
 */
THT_StatusTypeDef LORA_receiveIT(LORA_HandleTypeDef *const me, uint8_t *pBuffer, uint16_t size)
{
	if (me == NULL || pBuffer == NULL)
	{
		return THT_ERROR;
	}

	return (*me->receiveIT)(me, pBuffer, size);
}

/**
 * @brief Shutdown LoRa
 *
 * @param me [in] A pointer to LORA_HandleTypeDef structure
 * @return THT_StatusTypeDef
 */
THT_StatusTypeDef LORA_shutdown(LORA_HandleTypeDef *const me)
{
	if (me == NULL)
	{
		return THT_ERROR;
	}
	return (*me->shutdown)(me);
}

/**
 * @brief get packet RSSI
 *
 * @param me [in] A pointer to LORA_HandleTypeDef structure
 * @return int16_t
 */
int16_t LORA_getRSSI(LORA_HandleTypeDef *const me)
{
	if (me == NULL)
	{
		return THT_ERROR;
	}
	return (*me->getRSSI)(me);
}
