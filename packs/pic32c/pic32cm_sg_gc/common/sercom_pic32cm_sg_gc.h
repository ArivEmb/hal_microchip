/*
 * Copyright (c) 2026 Microchip Technology Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file sercom_pic32cm_sg_gc.h
 * @brief Generic SERCOM register macros for PIC32CM_SG_GC family.
 *
 * This file provides macros to abstract register and bitfield access for the
 * SERCOM USART and SPI peripherals on the Microchip PIC32CM_SG_GC family of
 * devices. These macros are intended for use in the SERCOM UART G1 and SPI G1
 * drivers.
 *
 */

#ifndef MICROCHIP_COMMON_SERCOM_PIC32CM_SG_GC_H_
#define MICROCHIP_COMMON_SERCOM_PIC32CM_SG_GC_H_

/**
 * @brief Get the base address of the USART register block.
 *
 * This macro returns the base address of the USART registers for the given
 * SERCOM instance. The @p is_clock_external parameter is included for
 * compatibility with unified driver code, but is not used for this device
 * family.
 *
 * @param regs Pointer to the SERCOM register structure.
 * @param is_clock_external Boolean indicating if the clock is external (not
 * used).
 * @return Pointer to the USART register block.
 */
#define UART_GET_BASE_ADDR(regs, is_clock_external) (&((regs)->USART))

/*SERCOM_USART_CTRLA*/
#define SERCOM_USART_CTRLA_FORM_USART_FRAME_WITH_PARITY                        \
  SERCOM_USART_CTRLA_FORM_USARTP
#define SERCOM_USART_CTRLA_FORM_USART_FRAME_NO_PARITY                          \
  SERCOM_USART_CTRLA_FORM_USARTP
#define SERCOM_USART_CTRLA_MODE_USART_EXT SERCOM_USART_CTRLA_MODE_EXTCLK
#define SERCOM_USART_CTRLA_MODE_USART_INT SERCOM_USART_CTRLA_MODE_INTCLK

/*SERCOM_USART_CTRLB*/
#define SERCOM_USART_CTRLB_CHSIZE_5_BIT SERCOM_USART_CTRLB_CHSIZE_5BITS
#define SERCOM_USART_CTRLB_CHSIZE_6_BIT SERCOM_USART_CTRLB_CHSIZE_6BITS
#define SERCOM_USART_CTRLB_CHSIZE_7_BIT SERCOM_USART_CTRLB_CHSIZE_7BITS
#define SERCOM_USART_CTRLB_CHSIZE_8_BIT SERCOM_USART_CTRLB_CHSIZE_8BITS
#define SERCOM_USART_CTRLB_CHSIZE_9_BIT SERCOM_USART_CTRLB_CHSIZE_9BITS

/**
 * @brief Get the base address of the SPI register block.
 *
 * This family has a single SPI register block in the SERCOM union rather than
 * separate SPIM and SPIS blocks, so host and client mode share the addresses
 * and @p is_client selects nothing. It is still consumed: the driver computes
 * that argument for no other purpose, and discarding it makes the variable
 * unused, which fails a -Werror build.
 *
 * @param regs Pointer to the SERCOM register structure.
 * @param is_client Boolean indicating client mode (not used).
 * @return Pointer to the SPI register block.
 */
#define SPI_GET_BASE_ADDR(regs, is_client) ((void)(is_client), &((regs)->SPI))

/*SERCOM_SPI_CTRLA*/
#define SERCOM_SPI_CTRLA_MODE_SPI_MASTER SERCOM_SPI_CTRLA_MODE_MASTER
#define SERCOM_SPI_CTRLA_MODE_SPI_SLAVE SERCOM_SPI_CTRLA_MODE_SLAVE
#define SERCOM_SPI_CTRLA_CPOL_IDLE_LOW SERCOM_SPI_CTRLA_CPOL(0)
#define SERCOM_SPI_CTRLA_CPOL_IDLE_HIGH SERCOM_SPI_CTRLA_CPOL(1)
#define SERCOM_SPI_CTRLA_DIPO_MUX0 SERCOM_SPI_CTRLA_DIPO_PAD0
#define SERCOM_SPI_CTRLA_DOPO_MUX0 SERCOM_SPI_CTRLA_DOPO_PAD0

/*SERCOM_SPI_CTRLB*/
#define SERCOM_SPI_CTRLB_CHSIZE_8_BIT SERCOM_SPI_CTRLB_CHSIZE_8BITS

#endif /* MICROCHIP_COMMON_SERCOM_PIC32CM_SG_GC_H_ */
