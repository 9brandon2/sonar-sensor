// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distanceCM;
int distanceIN;
int count;

void setup() {
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    Serial.begin(9600); // Starts the serial communication
}
void loop() {
    delayMicroseconds(10000);
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distanceCM= duration*0.034/2;
    distanceIN= duration*0.0133/2;

    // Always print
//    Serial.print("DistanceIN: ");
//    Serial.println(distanceIN);
//    
    // Check if distance is within 25 inches
    if (distanceIN < 60){
      count += 1;
      // Remove false positives
      if (count > 4){
      // Prints the distance on the Serial Monitor
        Serial.print("DistanceIN: ");
        Serial.println(distanceIN);
      }
    }
    else {
      count = 0;
    }
    
}
