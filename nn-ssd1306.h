/**
 * Arduino SSD1306 OLED Driver Library
 *
 * Colin R. Hahn
 * 2020
 */

#ifndef NNSSD1306
#define NNSSD1306

#include "Arduino.h"
#include <Wire.h>

#define SSD1306_IICADDR         0x3C

#ifndef __AVR__
#define DATAMEM
#endif
#ifdef __AVR__
#define DATAMEM PROGMEM
#endif

#include "hackfont.h"

#define MAXROW	4
#define MAXCOL  12

/** Set Lower Column Start Address for Page Addressing Mode. */
#define SSD1306_SETLOWCOLUMN        0x00
/** Set Higher Column Start Address for Page Addressing Mode. */
#define SSD1306_SETHIGHCOLUMN       0x10
/** Set Memory Addressing Mode. */
#define SSD1306_MEMORYMODE          0x20
/** Set display RAM display start line register from 0 - 63. */
#define SSD1306_SETSTARTLINE        0x40
/** Set Display Contrast to one of 256 steps. */
#define SSD1306_SETCONTRAST         0x81
/** Enable or disable charge pump.  Follow with 0X14 enable, 0X10 disable. */
#define SSD1306_CHARGEPUMP          0x8D
/** Set Segment Re-map between data column and the segment driver. */
#define SSD1306_SEGNOREMAP          0xA0
#define SSD1306_SEGREMAP            0XA1
/** Resume display from GRAM content. */
#define SSD1306_DISPLAYALLON_RESUME 0xA4
/** Force display on regardless of GRAM content. */
#define SSD1306_DISPLAYALLON        0xA5
/** Set Normal Display. */
#define SSD1306_NORMALDISPLAY       0xA6
/** Set Inverse Display. */
#define SSD1306_INVERTDISPLAY       0xA7
/** Set Multiplex Ratio from 16 to 63. */
#define SSD1306_SETMULTIPLEX        0xA8
/** Set Display off. */
#define SSD1306_DISPLAYOFF          0xAE
/** Set Display on. */
#define SSD1306_DISPLAYON           0xAF
/**Set GDDRAM Page Start Address. */
#define SSD1306_SETSTARTPAGE        0XB0
/** Set COM output scan direction normal. */
#define SSD1306_COMSCANINC          0xC0
/** Set COM output scan direction reversed. */
#define SSD1306_COMSCANDEC          0xC8
/** Set Display Offset. */
#define SSD1306_SETDISPLAYOFFSET    0xD3
/** Sets COM signals pin configuration to match the OLED panel layout. */
#define SSD1306_SETCOMPINS          0xDA
/** This command adjusts the VCOMH regulator output. */
#define SSD1306_SETVCOMDETECT       0xDB
/** Set Display Clock Divide Ratio/ Oscillator Frequency. */
#define SSD1306_SETDISPLAYCLOCKDIV  0xD5
/** Set Pre-charge Period */
#define SSD1306_SETPRECHARGE        0xD9
/** Deactivate scroll */
#define SSD1306_DEACTIVATE_SCROLL   0x2E
/** No Operation Command. */
#define SSD1306_NOP                 0XE3


#define SSD1306VAL_CONTRAST         0x7F
#define SSD1306VAL_CLOCKDIV         0x80
#define SSD1306VAL_32LINE           0x1F
#define SSD1306VAL_64LINE           0x3F

#define SSD1306VAL_CHARGEPUMP_ON    0x14
#define SSD1306VAL_CHARGEPUMP_OFF   0x10

#define SSD1306VAL_HORIZONTAL_ADDR  0x00
#define SSD1306VAL_VERTICAL_ADDR    0x01
#define SSD1306VAL_PAGE_ADDR        0x02

#define SSD1306_HVA_SETPAGE         0x22
#define SSD1306_HVA_SETCOL          0x21

#define SSD1306_PA_SETPAGE          0xB0

// SSD1306 initialization command block.
// This is sent to the screen in the init() method.
static const DATAMEM uint8_t oled_init_data[] = {
    // Step one, turn display off, so we don't see "fireworks" during init
    SSD1306_DISPLAYOFF,
    // Set contrast to 0x7F - apparently this is the datasheet-recommended value.
    SSD1306_SETCONTRAST, SSD1306VAL_CONTRAST,
    // Normal display, not inversed.
    SSD1306_NORMALDISPLAY,
    // Make sure scrolling is off.
    SSD1306_DEACTIVATE_SCROLL,
    // Because of how I've constructed my font data, I use vertical mode
    SSD1306_MEMORYMODE, SSD1306VAL_VERTICAL_ADDR,
    // Set start line to zero - update this value for vertical scrolling
    SSD1306_SETSTARTLINE | 0x00,
    // "reverse scan" and "segremap" allow flipping the display orientation.
    SSD1306_COMSCANDEC,
    SSD1306_SEGREMAP,
    // 128x64 pixel display - 64 lines.
    SSD1306_SETMULTIPLEX, SSD1306VAL_64LINE,
    // I don't know what this does.
    SSD1306_SETDISPLAYOFFSET, 0x00,
    // Apparently datasheet recommended. I don't know if a 32-line display needs a 
    // different setting.
    SSD1306_SETDISPLAYCLOCKDIV, SSD1306VAL_CLOCKDIV,
    // Always set to 0x22 for the I2C-based units.
    // 0xF1 is the other option, if a high-volts external vcc pin is present  ?
    // The alternative is charge pump mode.
    SSD1306_SETPRECHARGE, 0x22,
    SSD1306_CHARGEPUMP, SSD1306VAL_CHARGEPUMP_ON,
    // Only works with 0x12, dunno anything about this setting.
    SSD1306_SETCOMPINS, 0x12,       // set divide ratio
    // Only works with 0x20. Again, I dunno.
    SSD1306_SETVCOMDETECT, 0x20,
    // Set page and column ranges to full display.
    // Setting to reduced range clips rendering, but seemingly NOT reliably.
    SSD1306_HVA_SETPAGE, 0x00, 0x07,
    SSD1306_HVA_SETCOL, 0x00, 0x7F,
    // ALLON_RESUME is necessary, again for unknown reason.
    SSD1306_DISPLAYALLON_RESUME,
    // And finally, turn the display back on.
    SSD1306_DISPLAYON,
};
static const int init_data_len = sizeof(oled_init_data);

class RixOled
{
public:
    void init(void);
    void setDisplayOn(bool on);
    void setNormalDisplay(void);
    void setInverseDisplay(void);
    void setAddrModeHorizontal(void);
    void setAddrModeVertical(void);
    void setAddrModePage(void);
    
    void setPageRange(uint8_t p1, uint8_t p2);
    void setPage(uint8_t p1);
    void setColRange(uint8_t c1, uint8_t c2);
    void setCol(uint8_t c1);

    void moveTo(uint8_t row, uint8_t col);
    
    void clear(void);
    void blit(uint8_t data);
    void blitGlyph(uint8_t glyph);
    void blitString(char *s);

private:
    void writeCommandByte(uint8_t command);
    void writeDataByte(uint8_t data);
    
    void _update_mode(void);

    uint8_t addr_mode;
    uint8_t row_c;
    uint8_t col_c;
};

extern RixOled rixoled;



#endif
