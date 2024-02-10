/*

Connections:
LDR --> One leg to Vcc and the other to both analog pin 0 and to the GND via 100K resistor

*/

#define _DEBUG 0
int sensorPin = A0;   // select the input pin for ldr
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  pinMode(3, OUTPUT); //pin connected to the Servo
  Serial.begin(9600); //sets serial port for communication
}

void loop() {
  // read the value from the sensor:
  
#ifdef _DEBUG 

#endif  

}

bool ldr(int threshold){
sensorValue = analogRead(sensorPin);   

#ifdef _DEBUG 
Serial.println(sensorValue); //prints the values coming from the sensor on the screen
#endif
delay(100);  
return (sensorValue>threshold); 

}
