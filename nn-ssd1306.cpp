/**
 * nn-ssd1306.cpp
 * by NerdnetCA
 * 
 * Minimalist ssd1306 OLED driver library for Arduino.
 * Designed 128x64 model only!!  See .h file for information
 * on adapting to 128x32 model.
 * 
 * 
 */

#include "nn-ssd1306.h"

/** Initialize display, SAMD version.
 * For achitectures able to address program memory directly,
 * such as SAMD21
 * 
 * NOTE: This probably isn't robust. I have only AVR and SAMD devices
 * for testing. Use of this code on any other hardware may summon the Devil.
 * 
 */
#ifndef __AVR__
void RixOled::init() {
    const uint8_t* inittab = oled_init_data;
    for(uint8_t i=0; i<sizeof(oled_init_data); i++) {
        writeCommandByte(inittab[i]);
    }
    this->addr_mode = SSD1306VAL_VERTICAL_ADDR;
}
#endif


/** Initialize display, AVR version.
 * For AVR architectures such as Arduino Nano
 *
 */
#ifdef __AVR__
void RixOled::init() {
    const uint8_t* inittab = oled_init_data;
    for(uint8_t i=0; i<init_data_len; i++) {
        writeCommandByte(pgm_read_byte(&inittab[i]));
    }
    this->addr_mode = SSD1306VAL_VERTICAL_ADDR;
}
#endif


/** Turn display on (or off)
 */
void RixOled::setDisplayOn(bool on) {
    if(on) {
        writeCommandByte(SSD1306_DISPLAYON);
    } else {
        writeCommandByte(SSD1306_DISPLAYOFF);        
    }
}

/** Set to normal display mode.
 * 
 */
void RixOled::setNormalDisplay() {
    writeCommandByte(SSD1306_NORMALDISPLAY);
}

/** Set inverse display. (reverse pixel values)
 */
void RixOled::setInverseDisplay() {
    writeCommandByte(SSD1306_INVERTDISPLAY);
}

/** Horizontal addressing mode - Data is written to the
 * display in a left to right fashion, advancing the page (row)
 * after the end of row is passed.
 */
void RixOled::setAddrModeHorizontal() {
    this->addr_mode = SSD1306VAL_HORIZONTAL_ADDR;
    _update_mode();
}

/** Vertical addressing mode - consecutive data bytes are
 * written top to bottom, advancing the column after the
 * last row is written.  This is a convenient mode for
 * rendering the 16 pixel high font.
 */
void RixOled::setAddrModeVertical() {
    this->addr_mode = SSD1306VAL_VERTICAL_ADDR;
    _update_mode();
}

/** Paged addressing mode is like Horizontal, but doesn't
 * advance the page.
 */
void RixOled::setAddrModePage() {
    this->addr_mode = SSD1306VAL_PAGE_ADDR;
    _update_mode();
}

/** Restrict the page (row) range.
 * We use this to restrict rendering to 2 rows, providing
 * the ability to write 20 consecutive bytes of character
 * bitmap without having to update "cursor" position.
 */
void RixOled::setPageRange(uint8_t p1, uint8_t p2) {
    writeCommandByte(0x22);
    writeCommandByte(p1);
    writeCommandByte(p2);
}

/** The set page command is supposed to be for paged
 * addressing mode, but this command seems to interact
 * weirdly with other modes.  I don't fully understand
 * how this works.
 */
void RixOled::setPage(uint8_t p1) {
    writeCommandByte(SSD1306_PA_SETPAGE | (p1 & 0x07));
}

/** Restrict column rendering range. Similar to page range.
 */
void RixOled::setColRange(uint8_t c1, uint8_t c2) {
    writeCommandByte(0x21);
    writeCommandByte(c1);
    writeCommandByte(c2);
}

/** Set column - again this appears to be for paged addressing
 * mode, but it isn't fully clear how this affects other modes.
 */
void RixOled::setCol(uint8_t c1) {
    c1 = c1&0x7F;
    writeCommandByte(c1 & 0x0F);
    writeCommandByte(((c1>>4)&0x0F) | 0x10);
}

/** Write one byte to the display. This corresponds to
 * 8 pixels of one column, in one page. LSB at top.
 * For internal use.
 */
void RixOled::writeDataByte(uint8_t data) {
    Wire.beginTransmission(SSD1306_IICADDR);
    Wire.write(0xC0);
    Wire.write(data);
    Wire.endTransmission();    
}

/** Write one command byte to the display. For internal use.
 */
void RixOled::writeCommandByte(uint8_t command) {
    Wire.beginTransmission(SSD1306_IICADDR);
    Wire.write(0x80);
    Wire.write(command);
    Wire.endTransmission();
}

/** Clear the entire display. This will reset the page
 * and column ranges, but makes no contract for the final
 * cursor position.
 */
void RixOled::clear() {
    unsigned char i,j;
    setDisplayOn(false);
    setColRange(0,127);
    setPageRange(0,7);
    for(j=0; j<8; j++) {
        for(i=0; i<128; i++) {
            writeDataByte(0x00);
        }
    }
    setDisplayOn(true);
}

/** Set character position.  row: 0-7  col: 0-127
 * This is not the same as the display's understanding
 * of cursor position, and DOES NOT update automatically
 * after write.  In other words, if you write text to the
 * display without updating via moveTo, your text will
 * overwrite previous position.
 */
void RixOled::moveTo(uint8_t row, uint8_t col) {
    if(row < 0) row=0;
    if(col < 0) col=0;
    if(row >= MAXROW) row=MAXROW-1;
    if(col >= MAXCOL) col=MAXCOL-1;
    this->col_c = col;
    this->row_c = row;
}

/** Blindly write one byte to the display.
 */
void RixOled::blit(uint8_t data) {
    writeDataByte(data);
}


/** Blit (copy) a single glyph (character) to the display, 
 * at the character position established by moveTo().
 * 
 * I use blit() to achieve this, which writes one data byte at a time.
 * This isn't efficient, but writing multiple bytes seems to break
 * on some controllers
 */
void RixOled::blitGlyph(uint8_t glyph) {
    uint8_t row, col, i;
    row = this->row_c*2;
    col = this->col_c*10;
    const uint8_t *fdat;

    setPageRange(row, row+1);
    setColRange(col, col+GLYPHWIDTH);
    setPage(row);
    setCol(col);
    fdat = font_data[glyph];
    for(i=0; i<20; i++) {
#ifdef __AVR__
        blit(pgm_read_byte(fdat++));
#endif
#ifndef __AVR__
        blit(*fdat++);
#endif
    }
}

/** Blit (copy) an entire string (12 chars max)
 * to the display, at the character position.
 */
void RixOled::blitString(char * s) {
    uint8_t i = 0;
    while(*s != '\0' && i<MAXCOL) {
        blitGlyph(*s++);
        i++;
        if(this->col_c < MAXCOL)
            this->col_c++;
    }
}

// Internal.
void RixOled::_update_mode() {
    writeCommandByte(SSD1306_MEMORYMODE);
    writeCommandByte(this->addr_mode);
}


RixOled rixoled;
