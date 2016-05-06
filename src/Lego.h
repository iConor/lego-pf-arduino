#ifndef Lego_h
#define Lego_h

#if defined(ARDUINO) && ARDUINO >= 100
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#define ADDR_DEF  0x0
#define ADDR_EXT  0x1

#define CH1  0x0
#define CH2  0x1
#define CH3  0x2
#define CH4  0x3

#define BRK_A     0x0
#define INC_A     0x1
#define DEC_A     0x2
//#define NOT_USED  0x3
#define TGL_B     0x4
// #define NOT_USED  0x5
// #define TGL_ADR   0x6
// #define ALN_TGL   0x7
// #define RESERVED  0x8

#define FLT  0x0
#define FWD  0x5
#define REV  0xA
#define BRK  0xF

#define PWM    0x0
#define CSTID  0x1
#define RED    0x0
#define BLUE   0x1

#define PWM_FLT   0x0
#define PWM_FWD1  0x1
#define PWM_FWD2  0x2
#define PWM_FWD3  0x3
#define PWM_FWD4  0x4
#define PWM_FWD5  0x5
#define PWM_FWD6  0x6
#define PWM_FWD7  0x7
#define PWM_BRK   0x8
#define PWM_REV7  0x9
#define PWM_REV6  0xA
#define PWM_REV5  0xB
#define PWM_REV4  0xC
#define PWM_REV3  0xD
#define PWM_REV2  0xE
#define PWM_REV1  0xF

#define TGL_FWD   0x0
#define TGL_DIR   0x1
#define NINC_PWM  0x2
#define NDEC_PWM  0x3
#define INC_PWM   0x4
#define DEC_PWM   0x5
#define FWD_TIME  0x6
#define REV_TIME  0x7
#define TGL_FWRV  0x8
#define CLR_C1    0x9
#define SET_C1    0xA
#define TGL_C1    0xB
#define CLR_C2    0xC
#define SET_C2    0xD
#define TGL_C2    0xE
#define TGL_REV   0xF


class Lego
{
  public:
    Lego();
    void begin(int pin, int ch=0, int addr=0);
    void writeExtended(int function);
    void writeComboDirect(int red, int blue);
    void writeSingle(int mode, int output, int data);
    void writeComboPWM(int red, int blue);
  private:
    int _pin;
    int _ch;
    int _addr;
    int _payload[4];
    int write(int[] payload);
    int lrc(int[] payload);
};

#endif
