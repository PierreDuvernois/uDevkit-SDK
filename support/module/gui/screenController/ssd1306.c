/**
 * @file ssd1306.c
 * @author Sebastien CAUX (sebcaux)
 * @copyright Robotips 2017
 *
 * @date March 25, 2017, 16:20 PM
 *
 * @brief ssd1306 support driver
 */

#include "board.h"
#include "screenController.h"

#include <archi.h>

#include <driver/i2c.h>
#include <string.h>

uint8_t ssd1306_pixels[128 * 64 / 8];

rt_dev_t i2c_screenbus;

void gui_ctrl_write_command(uint8_t cmd)
{
    i2c_writereg(i2c_screenbus, OLED_I2C_ADDR, 0, cmd, 0);
}

void gui_ctrl_write_data(uint16_t data)
{
    i2c_writereg(i2c_screenbus, OLED_I2C_ADDR, 0x40, data, 0);
}

void gui_ctrl_update()
{
    uint16_t i;
    uint8_t *pix;

    gui_ctrl_write_command(0x21);
	gui_ctrl_write_command(0); // column
	gui_ctrl_write_command(127); // column

	gui_ctrl_write_command(0x22);
	gui_ctrl_write_command(0); // page
	gui_ctrl_write_command(7); // page

    pix = ssd1306_pixels;
    for(i=0; i<128; i++)
    {
        i2c_writeregs(i2c_screenbus, OLED_I2C_ADDR, 0x40, pix, 8, 0);
        pix += 8;
    }
}

void gui_ctrl_init(rt_dev_t dev)
{
    uint16_t j;

    i2c_screenbus = dev;

  #ifdef OLED_RST
    OLED_RST = 0;
    for(j=0; j<20; j++) for(i=0; i<65000; i++);
    OLED_RST = 1;
    for(j=0; j<50; j++) for(i=0; i<65000; i++);
  #endif

    gui_ctrl_write_command(0xAE); // display off
    gui_ctrl_write_command(0xD5); // clock div
    gui_ctrl_write_command(0x80); // ratio
    gui_ctrl_write_command(0xA8); // multiplex
    gui_ctrl_write_command(63);   // height - 1
    gui_ctrl_write_command(0xD3); // dysplay ofset
    gui_ctrl_write_command(0);    // ofset
    gui_ctrl_write_command(0x40); // start line = 0
    gui_ctrl_write_command(0x8D); // charge pump
    gui_ctrl_write_command(0x14); // charge pump
    gui_ctrl_write_command(0x20);
    gui_ctrl_write_command(0x0);
    gui_ctrl_write_command(0xA1);
    gui_ctrl_write_command(0xC8);

    gui_ctrl_write_command(0xDA);
    gui_ctrl_write_command(0x12);
    gui_ctrl_write_command(0x81);
    gui_ctrl_write_command(0xCF);
    gui_ctrl_write_command(0xD9);
    gui_ctrl_write_command(0xF1);
    gui_ctrl_write_command(0xDB);
    gui_ctrl_write_command(0x40);
    gui_ctrl_write_command(0xA4);
    gui_ctrl_write_command(0xA6);

    gui_ctrl_write_command(0x2E);
    gui_ctrl_write_command(0xAF);

    // clear screen
    memset(ssd1306_pixels, 0, 128 * 64 / 8);
    ssd1306_pixels[64] = 0xFF;
    gui_ctrl_update();
}

void gui_ctrl_setRectScreen(uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{
	gui_ctrl_write_command(0x21);
	gui_ctrl_write_command(0);      // column
	gui_ctrl_write_command(127);    // column

	gui_ctrl_write_command(0x22);
	gui_ctrl_write_command(0);      // page
	gui_ctrl_write_command(7);      // page
}

void gui_ctrl_setPos(uint16_t x, uint16_t y)
{
	gui_ctrl_write_command(0x21);
	gui_ctrl_write_command(0);      // column
	gui_ctrl_write_command(127);    // column

	gui_ctrl_write_command(0x22);
	gui_ctrl_write_command(0);      // page
	gui_ctrl_write_command(7);      // page
}

void gui_ctrl_drawPoint(uint16_t x, uint16_t y, uint16_t color)
{
    uint8_t *pix;
    int id;

    if(x > 127 || y > 64)
        return;

    id = ((y & 0xF8) << 4);
    id += x;
    pix = ssd1306_pixels + id;

    *pix |= 1 << (y & 0x07);
}

