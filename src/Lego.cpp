#if defined(ARDUINO) && ARDUINO >= 100
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include "Lego.h"

/*
 *  Empty Constructor
 */
Lego::Lego()
{

}

/*
 *  Sets the IR transmit pin number, channel number and address space.
 */
int Lego::begin(int pin, int ch=0, int addr=0)
{
  _pin = pin;
  _ch = ch & 0x3;
  _addr = addr & 0x8;
}

/*
 *  Transmits a single Extended Mode function.
 */
int Lego::writeExtended(int function)
{
  _payload[0] = _ch;
  _payload[1] = _addr;
  _payload[2] = function & 0xF;
  _payload[3] = lrc(payload);

  return write(payload);
}
/*
 *  Transmits a pair of commands using Combo Direct Mode.
 */
int Lego::writeComboDirect(int red, int blue)
{
  _payload[0] = _ch;
  _payload[1] = _addr | 0x1;
  _payload[2] = (blue & 0xC) | (red & 0x3);
  _payload[3] = lrc(payload);

  return write(payload);
}

/*
 *  Transmits a command using Single Output Mode.
 */
int Lego::writeSingle(int mode, int output, int data)
{
  _payload[0] = _ch;
  _payload[1] = _addr | 0x4 | (mode & 0x2) | (output & 0x1);
  _payload[2] = data & 0xF;
  _payload[3] = lrc(payload);

  return write(payload);
}

/*
 *  Transmits a pair of commands using Combo PWM Mode.
 */
int Lego::writeComboPWM(int red, int blue)
{
  _payload[0] = _addr | 0x4 | _ch;
  _payload[1] = blue & 0xF;
  _payload[2] = red & 0xF;
  _payload[3] = lrc(payload);

  return write(payload);
}

/*
 *  Transmits the 16-bit payload provided by mode-specific functions.
 */
int write(int[] payload)
{
  return 1;
}

/*
 *  Returns the payload's value for the "Longitudinal Redundancy Check".
 */
int lrc(int[] payload)
{
  return payload[0] ^ payload[1] ^ payload[2];
}
