/*
  This code is a prototype of showing a date and 
  an increasing time on an LCD used in conjunction 
  with an arduino UNO. Long long is used used since the 
  Arduino UNO int type has a range of -32,768 to 32,767.
  Based upon my calculations using the max long long
  value of 9223372036854775807 the amount of time it 
  would take for the seconds to overflow is 
  ~292,471,208,677 years so hopefully overflow won't be
  an issue.
  
 */
 
#include <LiquidCrystal.h>

#define MAX_SECONDS  60
#define MAX_MINUTES  60
#define MAX_HOURS    24
#define SECS_PER_MIN 60
#define SECS_PER_HR  3600

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
long initialMinutes = 0;
long initialHours   = 0;
long initMinsToSecs = initialMinutes * SECS_PER_MIN;
long initMinsToHrs  = initialHours * SECS_PER_HR;

void setup() {
  lcd.clear();
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("12/15/2012");
}

void loop() {
  // Seconds since start plus initial time given.
  long long seconds = (long long)(( initialMinutes * SECS_PER_MIN ) + ( initialHours * SECS_PER_HR ) + ( millis() / 1000 ));
  long minutes = ( seconds / SECS_PER_MIN ) % MAX_MINUTES;
  long hours = ( seconds / SECS_PER_HR ) % MAX_HOURS;
  
  // Set the cursor to column 0, line 1
  lcd.setCursor(0, 1);
  
  // Print hrs:mins
  if(hours < 10){
    // Leading zero
    lcd.print("0");
    lcd.print(hours);
  }
  else{
    lcd.print(hours);
  }
  
  lcd.print(":");
  
  if(minutes < 10){
    // Leading zero
    lcd.print("0");
    lcd.print(minutes);
  }
  else{
    lcd.print(minutes);
  }
  
}

