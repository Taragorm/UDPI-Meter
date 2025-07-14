#include <Arduino.h>
#include <defs.h>

const uint32_t PumpFreq = 100000UL;
const uint16_t PumpPeriod = (F_CPU/(PumpFreq*2))-1;
//----------------------------------------------------------------------------
constexpr float gain(uint8_t bits)
{
  float f=1.0;
  if(bits & Gain::A1G1) f*=11;
  if(bits & Gain::A1G2) f*=101;
  if(bits & Gain::A2G1) f*=11;
  if(bits & Gain::A2G2) f*=101;
  return f;
}
//----------------------------------------------------------------------------
/**
 * Scaling factor to convert raw counts to mV
 */
constexpr float scale(uint8_t bits)
{
  return Adcmv*gain(bits)/AdcMax;
}
//----------------------------------------------------------------------------
#define GAIN(_b) _b, gain(_b), scale(_b) 

const struct Gains
{
  char repr[8]; 
  uint8_t pins;
  float gain;
  float scale;
} gains_[] =
{
  { "x1",   GAIN(Gain::x1) },
  { "x10",  GAIN(Gain::x10) },
  { "x100", GAIN(Gain::x100) },
  { "x1k",  GAIN(Gain::x1k) },
  { "x10k", GAIN(Gain::x10k) }
};

const int GainsCount = 5;
//----------------------------------------------------------------------------
void setup() 
{
  pinModeFast(Pin::A1G1,OUTPUT);
  pinModeFast(Pin::A2G1,OUTPUT);
  pinModeFast(Pin::A1G2,OUTPUT);
  pinModeFast(Pin::A2G2,OUTPUT);
  pinModeFast(Pin::OffsetTest,OUTPUT);
  pinModeFast(Pin::PUMP,OUTPUT);
  pinModeFast(Pin::RST,INPUT_PULLUP);

  Serial.begin(115200);

  TCA0.SINGLE.CTRLA = 1; // enable, x1 div
  TCA0.SINGLE.CTRLB = TCA_SINGLE_CMP0_bm
                      | TCA_SINGLE_WGMODE_enum::TCA_SINGLE_WGMODE_FRQ_gc;
  TCA0.SINGLE.CMP1  = PumpPeriod;
  PORTMUX.TCAROUTEA = PORTMUX_TCA01_bm; // WO1 alt, PB4
}
//----------------------------------------------------------------------------
void loop() 
{

}
//----------------------------------------------------------------------------
