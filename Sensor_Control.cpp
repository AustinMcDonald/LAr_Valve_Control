// Motor include
#include "Sensor_Control.h"
#define SensPin 7

// Arduino specific includes
#include <Arduino.h>

//====================================================
float Sensor_Control::Read_Value()
{
    raw = analogRead(SensPin);
    buffer = raw * Vin;
    Vout = (buffer)/1024.0;
    buffer = (Vin/Vout) - 1;
    R2= R1 * buffer;
    return R2;
}

//====================================================
float Sensor_Control::Measure()
{
    int count = 0;
    float Value = 0.0;
    for (int i=0; i<10; i++)
    {
        count += 1;
        Value += Read_Value();
        delay(100);
    }
    Value /= count;
    return Value;
}
