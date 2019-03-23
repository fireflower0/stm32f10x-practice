#ifndef __STM32F10x_CONF_H
#define __STM32F10x_CONF_H

/* Uncomment the line below to enable peripheral header file inclusion */
/* #include "stm32f10x_adc.h"    // A-Dコンバータ */
/* #include "stm32f10x_bkp.h"    // バックアプ機能 */
/* #include "stm32f10x_can.h" */
/* #include "stm32f10x_cec.h"    // CEC通信機能 */
/* #include "stm32f10x_crc.h"    // CRC機能 */
/* #include "stm32f10x_dac.h"    // D-Aコンバータ */
/* #include "stm32f10x_dbgmcu.h" */
/* #include "stm32f10x_dma.h"    // DMA */
/* #include "stm32f10x_exti.h"   // 外部割り込み */
/* #include "stm32f10x_flash.h"  // フラッシュ・メモリ */
/* #include "stm32f10x_fsmc.h" */
#include "stm32f10x_gpio.h"   // GPIO
/* #include "stm32f10x_i2c.h"    // I2C */
/* #include "stm32f10x_iwdg.h"   // Independent watchdog */
/* #include "stm32f10x_pwr.h"    // 電源制御 */
#include "stm32f10x_rcc.h"    // RCC
/* #include "stm32f10x_rtc.h"    // RTC */
/* #include "stm32f10x_sdio.h" */
/* #include "stm32f10x_spi.h"    // SPI */
/* #include "stm32f10x_tim.h"    // タイマー */
/* #include "stm32f10x_usart.h"  // シリアル通信 */
/* #include "stm32f10x_wwdg.h"   // Window watchdog */
/* #include "misc.h" */
/* High level functions for NVIC and SysTick (add-on to CMSIS functions) */

// no asserts
#define assert_param(expr) ((void)0)

#endif
