#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 RTC;

const int buttonPin = 6;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status

int weekDay;
int currentHour;
int currentMinute;

void setup()
{
  pinMode(buttonPin, OUTPUT);

  Serial.begin(57600);
    Wire.begin();
    RTC.begin();
 
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }     
 // RTC.adjust(DateTime(__DATE__, __TIME__));
}


void loop()
{
	DateTime now = RTC.now();

	weekDay = now.dayOfWeek();
	currentHour = now.hour();
	currentMinute = now.minute();
  	Serial.println(weekDay);
  	Serial.println(currentHour);
  	Serial.println(currentMinute);
	switch (weekDay) 
	{
	    case 1:
        Serial.println("Mandag");
	    if (currentHour>=9 && currentHour<15)
	    {
	      digitalWrite(buttonPin, HIGH);
	    }
	    else
	      digitalWrite(buttonPin, LOW);
	    break;
	    
	    case 2:
        Serial.println("Tirsdag");
	    if (currentHour>=9 && currentHour<15)
	    {
	      digitalWrite(buttonPin, HIGH);
	    }
	    else
	      digitalWrite(buttonPin, LOW);
	    break;
	    
	    case 3:
        Serial.println("Tirsdag");
	    if (currentHour>=10 && currentHour<14)
	    {
	      digitalWrite(buttonPin, HIGH);
	    }
	    else
	      digitalWrite(buttonPin, LOW);
	    break;
	    
	    case 4:
        Serial.println("Torsdag");
	    if (currentHour>=9 && currentHour<17)
	      {
	        digitalWrite(buttonPin, HIGH);
	      }
	    else
	      digitalWrite(buttonPin, LOW);
	    break;
	    
	    case 5:
      	Serial.println("Fredag");
	      if (currentHour>=9 && currentHour<15)
	    {
	      digitalWrite(buttonPin, HIGH);
	    }
	    else
	      digitalWrite(buttonPin, LOW);
	    break;  

	    default: 
	    digitalWrite(buttonPin, LOW);
	}
}
