// VFD.cpp, vacuum fluroescent example for Samsung HCS-12SS59T, V0.9 171112 qrt@qland.de

//#include <Arduino.h>

#include "VFD.h"

void setup()
{
	//pinMode(Pin_RED_LED13, OUTPUT);
	//digitalWrite(Pin_RED_LED13, HIGH);
  pinMode(LED_BUILTIN, OUTPUT);
	Serial.begin(9600);
//	Vfd.init();

//	Vfd.write("QRT@QLAND_DE * ABCDEFGHIJKLMNOPQRSTUVWXYZ * 0123456789 * ");		// display 
	//Vfd.scroll(20);																// scroll left  (+) 20 * 0.01 chars per second*/
}																				//        right (-)
																				//        stop  (0)
void loop()
{
																// scroll left  (+) 20 * 0.01 chars per second
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}
