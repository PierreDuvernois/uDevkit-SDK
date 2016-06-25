/**
 * @file uart.h
 * @author Sebastien CAUX (sebcaux)
 * @copyright Robotips 2016
 *
 * @date April 13, 2016, 11:49 AM
 *
 * @brief Uart support for rtprog
 */

#ifndef UART_H
#define UART_H

#include "driver/device.h"

#define UART_BIT_PARITY_NONE 0
#define UART_BIT_PARITY_EVEN 1
#define UART_BIT_PARITY_ODD 2

// ====== device assignation ======
rt_dev_t uart_getFreeDevice();
void uart_releaseDevice(rt_dev_t device);

// ==== device enable/disable =====
int uart_enable(rt_dev_t device);
int uart_disable(rt_dev_t device);

// ======== device settings =======
int uart_setBaudSpeed(rt_dev_t device, uint32_t baudSpeed);
uint32_t uart_baudSpeed(rt_dev_t device);
uint32_t uart_effectiveBaudSpeed(rt_dev_t device);

int uart_setBitConfig(rt_dev_t device, uint8_t bitLenght,
                                      uint8_t bitParity,
                                      uint8_t bitStop);
uint8_t uart_bitLenght(rt_dev_t device);
uint8_t uart_bitParity(rt_dev_t device);
uint8_t uart_bitStop(rt_dev_t device);

// ========= device write ========
int uart_putc(rt_dev_t device, const char c);
int uart_putw(rt_dev_t device, const uint16_t word);

ssize_t uart_write(rt_dev_t device, const char *data, size_t size);
int uart_flush(rt_dev_t device);

// ========= device read =========
char uart_getc(rt_dev_t device);
uint16_t uart_getw(rt_dev_t device);
uint8_t uart_datardy(rt_dev_t device);
ssize_t uart_read(rt_dev_t device, char *data, size_t size_max);

#if defined(ARCHI_dspic33ep) || defined(ARCHI_dspic33fj)
#include "uart_dspic.h"
#else
#error "Unsupported ARCHI"
#endif

#endif // UART_H
