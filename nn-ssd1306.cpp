


#include "nn-ssd1306.h"

#ifndef __AVR__
void RixOled::init() {
    const uint8_t* inittab = oled_init_data;
    for(uint8_t i=0; i<sizeof(oled_init_data); i++) {
        writeCommandByte(inittab[i]);
    }
    this->addr_mode = SSD1306VAL_HORIZONTAL_ADDR;
    setAddrModeVertical();
}
#endif

#ifdef __AVR__
void RixOled::init() {
    const uint8_t* inittab = oled_init_data;
    for(uint8_t i=0; i<init_data_len; i++) {
        writeCommandByte(pgm_read_byte(&inittab[i]));
    }
    this->addr_mode = SSD1306VAL_HORIZONTAL_ADDR;
    setAddrModeVertical();
}
#endif

void RixOled::setDisplayOn(bool on) {
    if(on) {
        writeCommandByte(SSD1306_DISPLAYON);
    } else {
        writeCommandByte(SSD1306_DISPLAYOFF);        
    }
}

void RixOled::setNormalDisplay() {
    writeCommandByte(SSD1306_NORMALDISPLAY);
}

void RixOled::setInverseDisplay() {
    writeCommandByte(SSD1306_INVERTDISPLAY);
}

void RixOled::setAddrModeHorizontal() {
    this->addr_mode = SSD1306VAL_HORIZONTAL_ADDR;
    _update_mode();
}

void RixOled::setAddrModeVertical() {
    this->addr_mode = SSD1306VAL_VERTICAL_ADDR;
    _update_mode();
}

void RixOled::setAddrModePage() {
    this->addr_mode = SSD1306VAL_PAGE_ADDR;
    _update_mode();
}

void RixOled::setPageRange(uint8_t p1, uint8_t p2) {
    writeCommandByte(0x22);
    writeCommandByte(p1);
    writeCommandByte(p2);
}

void RixOled::setPage(uint8_t p1) {
    writeCommandByte(SSD1306_PA_SETPAGE | (p1 & 0x07));
}

void RixOled::setColRange(uint8_t c1, uint8_t c2) {
    writeCommandByte(0x21);
    writeCommandByte(c1);
    writeCommandByte(c2);
}

void RixOled::setCol(uint8_t c1) {
    c1 = c1&0x7F;
    writeCommandByte(c1 & 0x0F);
    writeCommandByte(((c1>>4)&0x0F) | 0x10);
}

void RixOled::writeDataByte(uint8_t data) {
    Wire.beginTransmission(SSD1306_IICADDR);
    Wire.write(0xC0);
    Wire.write(data);
    Wire.endTransmission();    
}

void RixOled::writeCommandByte(uint8_t command) {
    Wire.beginTransmission(SSD1306_IICADDR);
    Wire.write(0x80);
    Wire.write(command);
    Wire.endTransmission();
}

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

void RixOled::moveTo(uint8_t row, uint8_t col) {
    if(row < 0) row=0;
    if(col < 0) col=0;
    if(row >= MAXROW) row=MAXROW-1;
    if(col >= MAXCOL) col=MAXCOL-1;
    this->col_c = col;
    this->row_c = row;
}

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
        blit(fdat++);
#endif
    }
}

void RixOled::blitString(char * s) {
    uint8_t i = 0;
    while(*s != '\0' && i<MAXCOL) {
        blitGlyph(*s++);
        i++;
        if(this->col_c < MAXCOL)
            this->col_c++;
    }
}

void RixOled::_update_mode() {
    writeCommandByte(SSD1306_MEMORYMODE);
    writeCommandByte(this->addr_mode);
}

void RixOled::blit(uint8_t data) {
    writeDataByte(data);
}

RixOled rixoled;
