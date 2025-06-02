/*
  LiquidCrystal Library - scrollDisplayLeft() and scrollDisplayRight()

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD and uses the
 scrollDisplayLeft() and scrollDisplayRight() methods to scroll
 the text.

 This sketch prints "(>.<)" on displays, and scroll the string from one display to
 the other.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11,10,9,8
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

  This sketch is written by Chase Chen for Westview AP Physics C Final Arudino project

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

void printToDisplay(String a, int c, int r, LiquidCrystal lcd){
  /*
    This function print the string to the display without saving the previous string.
    Args:
      String a :  a string to display
      int c: the column position
      int r: the row position
      LiquidCrystal lcd: the lcd object
  */
  lcd.noDisplay();
  lcd.clear();
  lcd.setCursor(c, r);
  lcd.print(a);
  lcd.display();
}

void hide(String a, int r,LiquidCrystal lcd, int dir){
  /*
    This funciton hide the string to the left or to the right of the display
    Args:
      String a: the string to display
      int r: the row input
      LIquidCrystal lcd: lcd object
      int dir: direciton of hiding, either left or right, (+ or -)
  */
  
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
  
  // Print a message to the LCD for initialization and testing.
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
  // to move it offscreen left:
  hide(my_string,0,lcd1,1);
  hide(my_string,0,lcd2,1);
  // reverse hide location for lcd 3 and 4 due to mounting
  hide(my_string,1,lcd3,-1);
  hide(my_string,1,lcd4,-1);

  // move from the first lcd row 0(top left)
  for(int i=0;i<16+my_string.length();i++){
    lcd1.scrollDisplayRight();
    delay(200);
  }

  // move from the second lcd row 0(top right)
  for(int i=0;i<16+my_string.length();i++){
    lcd2.scrollDisplayRight();
    delay(200);
  }
  
  // hide string on row 1
  hide(my_string,1,lcd1,1);
  hide(my_string,1,lcd2,1);

  // move from the first lcd row 1
  for(int i=0;i<16+my_string.length();i++){
    lcd1.scrollDisplayRight();
    delay(200);
  }

  //move from the second lcd row 1
  for(int i=0;i<16+my_string.length();i++){
    lcd2.scrollDisplayRight();
    delay(200);
  }

  // move from the third lcd row 1
  for(int i=0;i<16+my_string.length();i++){
    lcd3.scrollDisplayLeft();
    delay(200);
  }

  // move from the forth lcd row 1
  for(int i=0;i<16+my_string.length();i++){
    lcd4.scrollDisplayLeft();
    delay(200);
  }

  // get ready for the second row
  hide(my_string,0,lcd3,-1);
  hide(my_string,0,lcd4,-1);

  // move from the third lcd row 0
  for(int i=0;i<16+my_string.length();i++){
    lcd3.scrollDisplayLeft();
    delay(200);
  }

  // move from the fourth lcd row 0
  for(int i=0;i<16+my_string.length();i++){
    lcd4.scrollDisplayLeft();
    delay(200);
  }
  
  // delay at the end of the full loop:
  delay(1000);

}


