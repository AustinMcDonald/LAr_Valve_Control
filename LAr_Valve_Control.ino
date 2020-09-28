#define Pulse 9
#define Dir 8
#define ENG 12

#define SensPin 7

#include "Motor_Control.h"
#include "Sensor_Control.h"
#include "Commands.h"

Motor_Control Moto  = Motor_Control();
Sensor_Control Sens = Sensor_Control();
Commands Commander = Commands();

int counter = 0;
unsigned long Arduno_time;
unsigned long Last_time;
const unsigned long OneMinuet = 60000;  //the value is a number of milliseconds

bool Valve_Status = false;

int incomingByte = 0; // for incoming serial data

float SensVal = 0;

String incoming = "";   // for incoming serial string data
//String readString;



void setup()
{
  Serial.begin(9600);
  pinMode(Pulse,OUTPUT);
  pinMode(Dir,OUTPUT);
  pinMode(ENG,OUTPUT);
  digitalWrite(Dir,LOW);
  digitalWrite(ENG,LOW);
}

void loop()
{
  //Moto.Set_Seconds_Per_Turn(5); // set seconds per turn Default is 5
  Moto.Set_Seconds_Per_Turn(5); // this is pretty fast
  //Moto.Set_Steps_Per_Turn(400) this depends on the controller
  
  incomingByte = Commander.Check_Serial();
//  incomingByte = Serial.read();

//  while (Serial.available()) 
//  {
//    delay(2);  //delay to allow byte to arrive in input buffer
//    char c = Serial.read();
//    readString += c;
//  }
//  
//  if (readString.length() >0) 
//  {
//    Serial.println(readString);
//    readString="";
//  }
  
//  if (incomingByte > 100)
//  {
//    Moto.TEST_MOTOR();
//    Arduno_time = millis();
//    counter+=1;
//    
//    Serial.print("Counter = ");
//    Serial.println(counter);
//    Serial.print("Time = ");
//    Serial.println(Arduno_time); 
//    Serial.print("Time = ");
//    Serial.println(Arduno_time - OneMinuet);    
//  }
//  else 
//  {
//    Serial.print("Waiting ...");
//    delay(1000);
//  }

  //Serial.println(readCommand());
  Serial.println(incomingByte);
  if (incomingByte > 10)
  {
    SensVal = Sens.Read_Value();
    Serial.print("SensVal: ");
    Serial.println(SensVal);
    delay(500);   
  }
  else 
  {
    //Serial.println("Waiting ...");
    delay(500);
  }

 
  
}


//  currentMillis = millis();  //get the current "time" (actually the number of milliseconds since the program started)
//  if (currentMillis - startMillis >= period)  //test whether the period has elapsed
