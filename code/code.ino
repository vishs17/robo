
const int motor1Pin1 = 2;
const int motor1Pin2 = 3;
const int motor2Pin1 = 4;
const int motor2Pin2 = 5;


const int irSensor1Pin = 6;
const int irSensor2Pin = 7;
const int irSensor3Pin = 8;


const int trigPin = 9;
const int echoPin = 10;

const int redPin = 11;
const int greenPin = 12;
const int bluePin = 13;

void setup() {
 
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  
  
  pinMode(irSensor1Pin, INPUT);
  pinMode(irSensor2Pin, INPUT);
  pinMode(irSensor3Pin, INPUT);

  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
 
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
 
  Serial.begin(9600);
}

void loop() {
 
  int ir1Value = digitalRead(irSensor1Pin);
  int ir2Value = digitalRead(irSensor2Pin);
  int ir3Value = digitalRead(irSensor3Pin);
  
  
  if (ir1Value == LOW && ir2Value == LOW && ir3Value == HIGH) {
    // Stop motors if white color detected
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    // Print white detected message
    Serial.println("White detected");
  } else {
   
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    // Print black detected message
    Serial.println("Black detected");
  }
  
 
  long duration, distance;
  
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
 
  duration = pulseIn(echoPin, HIGH);
  

  distance = duration * 0.034 / 2;
  

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  

  if (distance < 10) {
    Serial.println("Object Found");
   
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
  } else if (distance < 12){
  
   
    Serial.println("Object Found");
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH );
  } 
  else  if (distance < 15){
    Serial.println("Object Found");
    // Change RGB LED color to brown when no object is detected
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);
  }


  else {
    Serial.println("No Object");
    // Change RGB LED color to green when no object is detected
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }
  // Delay for stability (adjust as needed)
  delay(200);
}
