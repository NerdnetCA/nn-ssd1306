/** oledtest
 * 
 * by NerdnetCA
 * 
 * Example usage for nn-ssd1306 library
 * 
 * 
 */

#include <nn-ssd1306.h>

void setup() {
  // Start I2C and set to 400khz
  // If updates are small and/or infrequent, 100khz can be plenty fast enough.
  Wire.begin();
  Wire.setClock(400000L);

  // Start OLED driver, this will send the init sequence to the screen.
  // Out-of-box, the screen should light up with random bits at this point, but
  // not if it is still holding a cleared buffer internally - which it seems
  // to be able to do for hours.
  rixoled.init();

  // Wait a second before clearing screen, so we can see the noise, if any.
  delay(1000);
  rixoled.clear();

  // Move to row 0, column 3
  rixoled.moveTo(0,3);
  // And draw, "Hello"
  rixoled.blitString("Mello");

  // Ooops, I accidentally put "Mello"...
  rixoled.blitString("H");

  // Next line
  rixoled.moveTo(1,0);
  // Write a string that is one character too long
  rixoled.blitString("Whirlyworld--");

  delay(1000);
  
  // Erase that hyphen
  rixoled.moveTo(1,11);
  rixoled.blitString(" ");

  
}

void loop() {
  delay(100000);
}
