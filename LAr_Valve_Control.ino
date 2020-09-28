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
  
  incoming = Commander.Check_Serial();
  Serial.println(incoming);

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
