#include <IRremote.hpp>
#include "pitches.h"
#include <Servo.h>
#define IR_RECEIVE_PIN 2
#define BUZZER_PIN 9
#define SERVO_PIN 9

Servo servo;
void setup()
{
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
  servo.attach(SERVO_PIN);
}

boolean switchStatus;

void loop() {
  if (IrReceiver.decode()) {
      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // Print "old" raw data
      // USE NEW 3.x FUNCTIONS
      IrReceiver.printIRResultShort(&Serial); // Print complete received data in one line
      IrReceiver.printIRSendUsage(&Serial);   // Print the statement required to send this data
      if (switchStatus){
        tone(BUZZER_PIN, NOTE_B4, 250);
        servo.write(180);
        switchStatus = false;
      } else {
        tone(BUZZER_PIN, NOTE_B6, 250);
        servo.write(0);
        switchStatus = true;
      }
      delay(2000);
      IrReceiver.resume(); // Enable receiving of the next value
  }
}