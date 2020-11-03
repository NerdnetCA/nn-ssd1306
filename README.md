# nn-ssd1306

Arduino driver library for SSD1306 .96" OLED display.

This is intended as a reference and testing implementation. The code is not dense, so don't
be afraid to read it and adapt it to your needs.

Usage:

```
#include <Wire.h>
#include <nn-ssd1306.h>

void setup() {
    Wire.begin()
    rixoled.init();
    
    rixoled.clear();
    rixoled.moveTo(0,0);
    rixoled.blitString("Hello,");
    rixoled.moveTo(1,0);
    rixoled.blitString("World");
}

```
