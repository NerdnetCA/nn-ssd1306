# nn-ssd1306

Arduino driver library for SSD1306 .96" OLED display, with I2C interface.

This is intended as a reference and testing implementation, not for production use.
In other words, you're meant to use this code to help get to an understanding of how the
SSD1306 device works, and how you can implement driver code 
that is specific to YOUR production requirement.

The code is not dense, and it's Creative Commons licensed. Feel feel free to use or modify.

NOTE: The scrolling features of this device are not implemented.

Usage:

```
#include <Wire.h>
#include <nn-ssd1306.h>

SSD_IIC ssd;

void setup() {
    Wire.begin()
    ssd.init(SSDLINES_64);
    
    ssd.clear();
    ssd.moveTo(0,0);
    ssd.blitString("Hello,");  // to "blit" is to copy a block of data, typically
                               // from main memory to video memory
    ssd.moveTo(1,0);
    ssd.blitString("World");
}

```
