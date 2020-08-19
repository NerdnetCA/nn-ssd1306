


#include "nn-ssd1306.h"

void RixOled::init() {
    const uint8_t* inittab = oled_init_data;
    //Wire.beginTransmission(SSD1306_IICADDR);
    //Wire.write(0x80);
    for(uint8_t i=0; i<sizeof(oled_init_data); i++) {
        writeCommandByte(inittab[i]);
        //Wire.write(inittab[i]);
    }
    //Wire.endTransmission();
    this->addr_mode = SSD1306VAL_HORIZONTAL_ADDR;
    setPageRange(0,7);
    setColRange(0,127);
    //setAddrModePage();
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
    Wire.write(0x40);
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
    setColRange(0,127);
    setPageRange(0,7);
    setCol(0);
    for(j=0; j<8; j++) {
        setPage(j);
        //writeCommandByte(SSD1306_SETSTARTLINE | j);
        Wire.beginTransmission(SSD1306_IICADDR);
        Wire.write(0x40);
        for(i=0; i<128; i++) {
            Wire.write(0x00);
        }
        Wire.endTransmission();
    }
}

void RixOled::_update_mode() {
    writeCommandByte(SSD1306_MEMORYMODE);
    writeCommandByte(this->addr_mode);
}

void RixOled::blit(uint8_t size) {
    unsigned char i;
    for(i=0;i<size;i++) writeDataByte(0xFF);
}

void RixOled::test(uint8_t p, uint8_t c) {
    unsigned char i;
    setPageRange(p,p);
    setPage(p);
    if(c>120) c=120;
    setColRange(c,c+7);
    setCol(c);
    for(i=0; i<8; i++) {
        writeDataByte(0xFF);
    }
}

RixOled rixoled;
