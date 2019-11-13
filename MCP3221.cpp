/******************************************************************************
MCP3221.cpp
Library for MCP3221 ADC
Bobby Schulz @ Northern Widget LLC & UMN
11/13/2019

MCP3221 is a 12 bit high speed SAR ADC

"Simplicity is prerquisite for reliability"
-Edsger W. Dijkstra

Distributed as-is; no warranty is given.
******************************************************************************/

#include <Arduino.h>
#include <MCP3221.h>
#include <Wire.h>


MCP3221::MCP3221(int _ADR)
{
  ADR = _ADR; 
  Wire.begin();  
}

MCP3221::MCP3221(void)  
{
  ADR = 0x4D; //Use 0x4D as Address by default  
  Wire.begin();  
}

int MCP3221::Begin(int _ADR) //Initialize the system in 1x gain, with 12 bit resolution, continuious conversions
{
  ADR = _ADR; //Allow for ADR to be set in begin statment as well
  return Begin();
}

int MCP3221::Begin(void) //Initialize the system in 1x gain, with 12 bit resolution, continuious conversions
{
  Wire.beginTransmission(ADR);
  return Wire.endTransmission(); //Return I2C status 
}

//Returns the bit value from the conversion, from 0 to 2^n
uint16_t MCP3221::GetVoltageRaw() {
  uint8_t Data[2];

  Wire.requestFrom(ADR, 2);
  
  if(Wire.available() == 2) //Get data bytes
  {
    Data[0] = Wire.read();
    Data[1] = Wire.read();
  }

  uint16_t RawADC = 0; 
  RawADC = ((Data[0] & 0x0F) << 8) + Data[1];

  return RawADC;  //return raw result
}

//Returns float voltage value in volts
float MCP3221::GetVoltage(float VRef) {
  uint16_t Raw = GetVoltageRaw(); //Get the raw bits, pass on stale value flag

  return (float(Raw)*VRef)/4096.0;  //Return converted value 
}







