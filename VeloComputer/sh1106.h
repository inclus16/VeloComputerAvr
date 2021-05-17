/**
  ******************************************************************************
  * @file    sh1106.h
  * @author  Waveshare Team
  * @version 
  * @date    21-June-2017
  * @brief   This file includes the OLED driver for SH1106 display moudle
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, WAVESHARE SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  ******************************************************************************
  */
  
#ifndef _SH1106_H_
#define _SH1106_H_

#ifndef F_CPU
#define F_CPU 20000000UL
#endif

#include <avr/pgmspace.h>

#define WIDTH   128
#define HEIGHT   64
#define NUM_PAGE  8

#define OLED_RST  5
#define OLED_DC   6
#define OLED_CS  7
void SH1106_begin();
void SH1106_display();
void SH1106_clear();
void SH1106_pixel(int x,int y,char color);
void SH1106_char(uint8_t x, uint8_t y, uint8_t acsii, uint8_t size, uint8_t mode);
void SH1106_string(uint8_t x, uint8_t y, const char *pString, uint8_t Size, uint8_t Mode);
void SPIWrite(uint8_t *buffer, int bufferLength);
void command(uint8_t cmd);


#endif
