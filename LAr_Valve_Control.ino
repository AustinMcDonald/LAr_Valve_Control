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
unsigned long Last_time = 1;
unsigned long TimeSinceFill  = 1;

const unsigned long OneMinuet = 60000;  //the value is a number of milliseconds
const unsigned long TenMinuet = 600000;  //the value is a number of milliseconds
const unsigned long FortyMinuet = 2400000;  //the value is a number of milliseconds


bool is_valve_open = false;

float SensVal = 0;
String incoming = "";   // for incoming serial string data

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
  Arduno_time = millis(); // current time
  TimeSinceFill = Arduno_time - Last_time;
  
  SensVal = Sens.Measure();
  Serial.print("Sensor Valuel: ");
  Serial.println(SensVal);
  delay(50);

  
  incoming = Commander.Check_Serial();
  Serial.println(incoming);

  // main function
  if (incoming == "start/n")
  {
    if ( (SensVal > 25) && (TimeSinceFill>FortyMinuet) )
    {
      is_valve_open = true;
      Serial.print("Starting a fill [time]: ");
      Serial.println(Arduno_time);
      Last_time = Arduno_time;
      Moto.Open_Valve();
      delay(TenMinuets);
      is_valve_open = false;
      Moto.Close_Valve();
    }
  
  }
  // open valve
  if else (incoming == "open/n")
  {
    if (!is_valve_open)
    {
      is_valve_open = true;
      Serial.print("Opening valve [time]: ");
      Serial.println(Arduno_time);
      Moto.Open_Valve();
    }
  }
  // close valve
  if else (incoming == "close/n")
  {
    if (is_valve_open)
    {
      is_valve_open = false;
      Serial.print("Closing valve [time]: ");
      Serial.println(Arduno_time);
      Moto.Close_Valve();
    }
  }
  
  
  else 
  {
    delay(50);
  }
  
}

//  currentMillis = millis();  //get the current "time" (actually the number of milliseconds since the program started)
//  if (currentMillis - startMillis >= period)  //test whether the period has elapsed
