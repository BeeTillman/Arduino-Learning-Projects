int ledPin = 5;
int btnOnPin = 9;
int btnOffPin = 8;

void setup() {
  // put your setup code here, to run once
  pinMode(ledPin, OUTPUT);
  pinMode(btnOnPin, INPUT_PULLUP);
  pinMode(btnOffPin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(btnOnPin) == LOW){
    digitalWrite(ledPin, HIGH);
  }

  if (digitalRead(btnOffPin) == LOW){
    digitalWrite(ledPin, LOW);
  }
}
