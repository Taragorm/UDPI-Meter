#ifndef _DEFS_H
#define _DEFS_H
#include <Arduino.h>
#include <stdint.h>

namespace Pin
{
    const uint8_t  A1G1         = PIN_PA1;
    const uint8_t  A1G2         = PIN_PA2;
    const uint8_t  A2G1         = PIN_PA3;
    const uint8_t  A2G2         = PIN_PA4;
    const uint8_t  OffsetTest   = PIN_PA5;
    const uint8_t  Sel0R1       = PIN_PA6;
    const uint8_t  VT3V         = PIN_PA7;
    const uint8_t  PUMP         = PIN_PB4;
    const uint8_t  TPWR         = PIN_PA4;
    const uint8_t  RST          = PIN_PC1;
    const uint8_t  ANALOG       = PIN_PC2;
    const uint8_t  VTARGET      = PIN_PC3;

}


namespace Gain
{
    const uint8_t  A1G1         = 2;
    const uint8_t  A1G2         = 4;
    const uint8_t  A2G1         = 8;
    const uint8_t  A2G2         = 16;

    const uint8_t  Mask         = (0xf<<1);

    const uint8_t  x1           = 0;
    const uint8_t  x10          = A1G1;
    const uint8_t  x100         = A1G2;
    const uint8_t  x1k          = A1G2|A2G1;
    const uint8_t  x10k         = A1G2|A2G2;

}

const uint16_t AdcMax = 4095;
const uint16_t Adcmv = 1024;


#endif
