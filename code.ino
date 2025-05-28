/*
  LiquidCrystal Library - scrollDisplayLeft() and scrollDisplayRight()

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD and uses the
 scrollDisplayLeft() and scrollDisplayRight() methods to scroll
 the text.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalScroll

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en1 = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int en2 = 10;
const int en3 = 9;
const int en4 = 8;
const String my_string = "(>.<)";
int counter = 0;
LiquidCrystal lcd1(rs, en1, d4, d5, d6, d7);
LiquidCrystal lcd2(rs, en2, d4, d5, d6, d7);
LiquidCrystal lcd3(rs, en3, d4, d5, d6, d7);
LiquidCrystal lcd4(rs, en4, d4, d5, d6, d7);
// byte smiley[8] = {
//   B00000,  // Row 0 (top)
//   B10001,  // Row 1
//   B00000,  // Row 2
//   B00000,  // Row 3
//   B10001,  // Row 4
//   B01110,  // Row 5
//   B00000,  // Row 6
// };         // Row 7 is implicitly all 0s


void printToDisplay(String a, int c, int r, LiquidCrystal lcd){
  lcd.noDisplay();
  lcd.clear();
  lcd.setCursor(c, r);
  lcd.print(a);
  lcd.display();
}

void hide(String a, int r,LiquidCrystal lcd, int dir){
  lcd.noDisplay();
  lcd.clear();
  lcd.setCursor(0, r);
  if(dir>0){
    lcd.setCursor(0, r);
    lcd.print(a);
    for(int i=0; i< a.length();i++){
      lcd.scrollDisplayLeft();
    }
  }else{
    lcd.setCursor(16-a.length(), r);
    lcd.print(a);
    for(int i=0; i< a.length();i++){
      lcd.scrollDisplayRight();
    }
  }
  
  lcd.display();
}
void setup() {
  // set up the LCD's number of collumns and rows:
  lcd1.begin(16, 2);
  lcd2.begin(16, 2);
  lcd3.begin(16, 2);
  lcd4.begin(16, 2);
  // Print a message to the LCD.
  //lcd1.print("HELLO");
  printToDisplay("chase",0,1,lcd1);
  //printToDisplay("0721",6,0,lcd2);
  hide("0721",0,lcd2,1);
  //lcd2.print("0721");
  lcd3.print("0d00");
  lcd4.print("James");
  delay(1000);  
}

void loop() {
  // scroll 13 positions (string length) to the left
  // to move it offscreen left:
  hide(my_string,0,lcd1,1);
  hide(my_string,0,lcd2,1);
  hide(my_string,1,lcd3,-1);
  hide(my_string,1,lcd4,-1);

  for(int i=0;i<16+my_string.length();i++){
    lcd1.scrollDisplayRight();
    delay(200);
  }
  for(int i=0;i<16+my_string.length();i++){
    lcd2.scrollDisplayRight();
    delay(200);
  }
  hide(my_string,1,lcd1,1);
  hide(my_string,1,lcd2,1);
  for(int i=0;i<16+my_string.length();i++){
    lcd1.scrollDisplayRight();
    delay(200);
  }
  for(int i=0;i<16+my_string.length();i++){
    lcd2.scrollDisplayRight();
    delay(200);
  }

  for(int i=0;i<16+my_string.length();i++){
    lcd3.scrollDisplayLeft();
    delay(200);
  }
  for(int i=0;i<16+my_string.length();i++){
    lcd4.scrollDisplayLeft();
    delay(200);
  }
  hide(my_string,0,lcd3,-1);
  hide(my_string,0,lcd4,-1);
  for(int i=0;i<16+my_string.length();i++){
    lcd3.scrollDisplayLeft();
    delay(200);
  }
  for(int i=0;i<16+my_string.length();i++){
    lcd4.scrollDisplayLeft();
    delay(200);
  }

  

  // delay at the end of the full loop:
  delay(1000);

}


