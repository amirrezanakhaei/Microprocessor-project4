int trig = 11;
int echo = 12;
int led = 3;

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = (duration / 2) * 0.0343;

  Serial.println(distance);

  if(distance > 30) {
    analogWrite(led, 0);  
  }
  else {
    int brightness = map(distance, 30, 4, 20, 255);
    brightness = constrain(brightness, 20, 255);
    analogWrite(led, brightness);
  }

  delay(50);
}
