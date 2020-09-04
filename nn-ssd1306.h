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


static const DATAMEM uint8_t oled_init_data[] = {
    SSD1306_DISPLAYOFF,
    SSD1306_SETCONTRAST, SSD1306VAL_CONTRAST,      // contrast value to 0x7F according to datasheet
    SSD1306_NORMALDISPLAY,
    SSD1306_DEACTIVATE_SCROLL,
    SSD1306_MEMORYMODE, SSD1306VAL_HORIZONTAL_ADDR,
    SSD1306_COMSCANDEC,             // Scan from 127 to 0 (Reverse scan)
    SSD1306_SETSTARTLINE | 0x00,    // First line to start scanning from
    SSD1306_SEGREMAP,               // Use reverse mapping. 0x00 - is normal mapping
    SSD1306_SETMULTIPLEX, SSD1306VAL_64LINE,
    SSD1306_SETDISPLAYOFFSET, 0x00, // no offset
    SSD1306_SETDISPLAYCLOCKDIV, SSD1306VAL_CLOCKDIV,  // set to default ratio/osc frequency
    SSD1306_SETPRECHARGE, 0x22,     // switch precharge to 0x22 // 0xF1
    SSD1306_SETCOMPINS, 0x12,       // set divide ratio
    SSD1306_SETVCOMDETECT, 0x20,    // vcom deselect to 0x20 // 0x40
    SSD1306_CHARGEPUMP, SSD1306VAL_CHARGEPUMP_ON,       // Enable charge pump
    SSD1306_HVA_SETPAGE, 0x00, 0x07,
    SSD1306_HVA_SETCOL, 0x00, 0x7F,
    SSD1306_DISPLAYALLON_RESUME,
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
