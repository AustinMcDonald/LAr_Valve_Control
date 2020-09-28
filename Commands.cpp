// Motor include
#include "Commands.h"

// Arduino specific includes
#include <Arduino.h>



//====================================================
std::string Commands::Check_Serial()
{
    while (Serial.available()) 
    {
        delay(2);  //delay to allow byte to arrive in input buffer
        char c = Serial.read();
        readString += c;
    }
    
    if (readString.length() >0) 
    {
        Serial.println(readString);
        readString="";
    }
    return readString
}