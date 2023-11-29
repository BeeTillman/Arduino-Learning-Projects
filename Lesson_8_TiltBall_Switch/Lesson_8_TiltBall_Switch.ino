// Pin Variables
int ledPin = 8;
int tiltPin = 10;


void setup() {
  // put your setup code here, to run once:
  // Pin Set Up
  pinMode(ledPin, OUTPUT);
  pinMode(tiltPin, INPUT_PULLUP);

  // Ensure LED (& Potential Buzzer are off)
  digitalWrite(ledPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(tiltPin) == HIGH){
    digitalWrite(ledPin, HIGH);
  }

  if(digitalRead(tiltPin) == LOW){
    digitalWrite(ledPin, LOW);
  }
}
