#define sensorPower 7
#define sensorPin A1

 // Define max value we consider soil 'wet'
 // Define min value we consider soil 'dry'

void setup() {
	pinMode(sensorPower, OUTPUT);
	// Initially keep the sensor OFF
	digitalWrite(sensorPower, LOW);
	
	Serial.begin(9600);
}

void loop() {
	//get the reading from the function below and print it
	Serial.print("Analog output: ");
	Serial.println(readSensor());
    int moisture = readSensor();
  
	Particle.publish("Moisture", String(moisture), PRIVATE);
	delay(1000);
}

int readSensor() {
	digitalWrite(sensorPower, HIGH);	// Turn the sensor ON
	delay(10);							// Allow power to settle
	int val = analogRead(sensorPin);	// Read the analog value form sensor
	digitalWrite(sensorPower, LOW);		// Turn the sensor OFF
	return val;							// Return analog moisture value
}