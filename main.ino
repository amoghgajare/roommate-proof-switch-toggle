/*

Connections:
LDR --> One leg to Vcc and the other to both analog pin 0 and to the GND via 100K resistor

*/
#include <Servo.h>
#define _DEBUG 1
#define defaultRetires 3
#define LDR_THRESHOLD 400
#define LDRsensorPin A0   // select the input pin for ldr
#define servoPin 9
#define servoPosUp 0
#define servoPosDown 180
int sensorValue = 0;  // variable to store the value coming from the sensor

Servo myservo;


void setup() {
  pinMode(3, OUTPUT); //pin connected to the Servo
  myservo.attach(servoPin);

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
bool toggle = ldr(LDR_THRESHOLD);
if(toggle){
  if(cnt==120){

  servoToggle(defaultRetires);

  }
delay(2000);
cnt = cnt + 2;
}
else{
  cnt=0;
  servoToggle(defaultRetires);
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
sensorValue = analogRead(LDRsensorPin);   

#ifdef _DEBUG 
Serial.println(sensorValue); //prints the values coming from the sensor on the screen
#endif
delay(100);  
return (sensorValue>threshold); 

}

void servoToggle(int retires = 3){
  for(int i=0; i<retires; i++){
    position_servo(servoPosUp);
    delay(15);
    if(~ldr(LDR_THRESHOLD)){
      #ifdef _DEBUG
        Serial.println("Light Turned off, switch position was up, not trying again");
      #endif
      return;
    }
    position_servo(servoPosDown);
    delay(15);
    if(~ldr(servoPosDown)){
      #ifdef _DEBUG
        Serial.println("Light Turned off, switch position was down, not trying again");
      #endif
      return;
    }
  }
  #ifdef _DEBUG
    Serial.println("Could not Switch light off");
  #endif

}

void position_servo(int angle){
  myservo.write(angle);
  delay(15);
}