// Motor include
#include "Sensor_Control.h"
#define SensPin 7

// Arduino specific includes
#include <Arduino.h>



//====================================================
float Sensor_Control::Check_Serial()
{
    raw = analogRead(SensPin);
    buffer = raw * Vin;
    Vout = (buffer)/1024.0;
    buffer = (Vin/Vout) - 1;
    R2= R1 * buffer;
    return R2;
}