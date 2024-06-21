#define redLed 2

bool IsLedOn;
unsigned long randomNum;
unsigned long lastTime;
void LedOn() {
  digitalWrite(redLed, HIGH);
  IsLedOn = true;
  lastTime = millis();
}
void LedOff() {
  digitalWrite(redLed, LOW);
  IsLedOn = false;
  lastTime = millis();
}
void getRandom() {
  int val = analogRead(A0);
  if(val<=341){
    randomNum = random(200,1000);
  } else if (val >= 342 && val <= 682){
    randomNum = random(1000,2000);
  } else randomNum = random(3000,5000);

}

void setup() {
  Serial.begin(9600);
  pinMode(redLed, OUTPUT);
  randomSeed(analogRead(A1));
  getRandom();
}

void loop() {
  if (millis() - lastTime >= randomNum) {
    IsLedOn ? LedOff() : LedOn();
    getRandom();
  }
}
