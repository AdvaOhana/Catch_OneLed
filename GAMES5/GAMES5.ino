#define redLed 2

bool IsLedOn;
unsigned long randomNum, currTime;
unsigned long lastTime;
void LedOn(){
  digitalWrite(redLed,HIGH);
}
void LedOff(){
  digitalWrite(redLed,LOW);
}

void setup() {
  Serial.begin(9600);;
  pinMode(redLed,OUTPUT);
  randomSeed(analogRead(A1));
  randomNum= random(1000,3000);
}


void loop() {
currTime= millis();

if(currTime - lastTime >= randomNum){
  lastTime= currTime;
  IsLedOn = !IsLedOn;
  digitalWrite(redLed, IsLedOn);
  Serial.println(randomNum);
  randomNum= random(1000,3000);
}

}
