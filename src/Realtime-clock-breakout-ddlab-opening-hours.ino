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

//Åbningstider:
int mandag[2]={9,15};
int tirsdag[2]={9,17};
int onsdag[2]={10,14};
int torsdag[2]={12,17};
int fredag[2]={11,15};

void loop()
{
	DateTime now = RTC.now();

	weekDay = now.dayOfTheWeek();
	currentHour = now.hour();
	currentMinute = now.minute();
  	Serial.println(weekDay);
  	Serial.println(currentHour);
  	Serial.println(currentMinute);
	switch (weekDay)
	{
	    case 1:
        Serial.println("Mandag");
	    if (currentHour>=mandag[0] && currentHour<mandag[1])
	    {
	      digitalWrite(buttonPin, HIGH);
	    }
	    else
	      digitalWrite(buttonPin, LOW);
	    break;

	    case 2:
        Serial.println("Tirsdag");
	    if (currentHour>=tirsdag[0] && currentHour<tirsdag[1])
	    {
	      digitalWrite(buttonPin, HIGH);
	    }
	    else
	      digitalWrite(buttonPin, LOW);
	    break;

	    case 3:
        Serial.println("Onsdag");
	    if (currentHour>=onsdag[0] && currentHour<onsdag[1])
	    {
	      digitalWrite(buttonPin, HIGH);
	    }
	    else
	      digitalWrite(buttonPin, LOW);
	    break;

	    case 4:
        Serial.println("Torsdag");
	    if (currentHour>=torsdag[0] && currentHour<torsdag[1])
	      {
	        digitalWrite(buttonPin, HIGH);
	      }
	    else
	      digitalWrite(buttonPin, LOW);
	    break;

	    case 5:
      	Serial.println("Fredag");
	      if (currentHour>=fredag[0] && currentHour<fredag[1])
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
