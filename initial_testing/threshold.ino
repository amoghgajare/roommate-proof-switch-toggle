/*

Connections:
LDR --> One leg to Vcc and the other to both analog pin 0 and to the GND via 2K resistor

Result - We get 400+ value as output when staircase light is on, around 100 when room and washroom lights are 
turned on but staircase lights are off

*/

int sensorPin = A0;   // select the input pin for ldr
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  pinMode(2, OUTPUT); //pin connected to the relay
  Serial.begin(9600); //sets serial port for communication
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);    
  Serial.println(sensorValue); //prints the values coming from the sensor on the screen
  
  delay(100);                  
}
