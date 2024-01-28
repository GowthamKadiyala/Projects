#define soundbuzzer 3
#define LEDlampRed 13
int sound = 500;
const int piezoPin = A0;
int set = 0;
int cycle = 0;
int timer = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  pinMode(soundbuzzer, OUTPUT);
  pinMode(LEDlampRed, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(piezoPin);

    if(sensorValue == 1023){
    set += 1;
  }
  if(set >= 2){
    cycle += 1;
    set = 0;
  }

  if(cycle >= 2){
    tone(soundbuzzer, sound);
    timer += 1;
    digitalWrite(LEDlampRed, HIGH);
  }
  if (timer >= 15){
    noTone(soundbuzzer);
    timer = 0;
    cycle = 0;
    Serial.println("Shake Detected!");
    Serial.println("     ");
  }
    delay(100);
}
