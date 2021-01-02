#define trigPin 10
#define echoPin 13
#define led 11
float duration, distance;
void setup() {
  Serial.begin (115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  int count;
}
void loop() {
   
  // Write a pulse to the HC-SR04 Trigger Pin and measure the response from the HC-SR04 Echo Pin
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);
  
  // Determine distance from duration and use 343 metres per second as speed of sound
  
  distance = (duration / 2) * 0.0343;
  
  // Send results to Serial Monitor
 
  if (distance < 183 && distance > 0) {
     Serial.println(distance);
     digitalWrite(led, HIGH);
     int count = count + 1; // Add to the total number of times that the sensor detects an individual within six feet.
  }
else {
  Serial.println(0);
  digitalWrite(led, LOW);
}
delay(100);
  }
