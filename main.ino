/*

Connections:
LDR --> One leg to Vcc and the other to both analog pin 0 and to the GND via 100K resistor

*/

#define _DEBUG 1
int sensorPin = A0;   // select the input pin for ldr
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  pinMode(3, OUTPUT); //pin connected to the Servo

  #ifdef _DEBUG 
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, 0);
  #endif

  Serial.begin(9600); //sets serial port for communication
}

void loop() {
  // read the value from the sensor:
int cnt = 0;
while(cnt <= 120){
bool toggle = ldr(400);
if(toggle){
  if(cnt==120){

  servoToggle();

  }
delay(2000);
cnt = cnt + 2;
}
else{
  cnt=0;
  servoToggle();
  break;
}
}
#ifdef _DEBUG 
if(toggle){
digitalWrite(LED_BUILTIN, 1);
}
else{
   digitalWrite(LED_BUILTIN, 0); 
}
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
