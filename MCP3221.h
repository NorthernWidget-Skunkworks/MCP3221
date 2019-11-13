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

#ifndef MCP3221_h
#define MCP3221_h

#include "Arduino.h"

class MCP3221
{
  public:

    MCP3221(int _ADR);
    MCP3221(void);

    int Begin(int _ADR);
    
    int Begin(void);

    uint16_t GetVoltageRaw(); 

    float GetVoltage(float VRef = 3.3); //Assume 3.3v ref by default

  private:
    int ADR;
};

#endif