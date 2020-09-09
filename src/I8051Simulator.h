#ifndef I8051SIMULATOR_H
#define I8051SIMULATOR_H
#include <stdint.h>


typedef enum {
  DIRECT_ADDRESSING,
  INDIRECT_ADDRESSING,
}AccessMode;

typedef struct Status Status;
struct Status {
  uint8_t P : 1;
  uint8_t reserved : 1;
  uint8_t OV : 1;
  uint8_t RS : 2;
  uint8_t F0 : 1;
  uint8_t AC : 1;
  uint8_t CY : 1;
};

#define acc      sfr[0xe0]
#define psw      sfr[0xd0]
#define status   (*(Status*)&sfr[0xd0])
#define B        sfr[0xf0]
#define r(n)     ram[((psw >> 3) & 0x03) * 8 + (n)]
#define DPH      sfr[0x83]
#define DPL      sfr[0x82]

     
extern uint8_t ram[];
extern uint8_t sfr[];
extern uint8_t xram[];
extern uint8_t codeMemory[];
extern uint16_t pc;

typedef void(*ExecuteInstruction)(void);

void writeToMemory(int address, AccessMode mode, uint8_t data);
uint8_t readFromMemory(int address, AccessMode mode);
uint8_t sum(uint32_t val1, uint32_t val2);
uint8_t substract(uint32_t val1, uint32_t val2);
void handleOverFlow(uint32_t val1, uint32_t val2, uint32_t result);

void executeInstruction();
void mov();
void movDataToA();
void movAToReg();
void movDirToReg();
void movDataToReg();
void movAToDir();
void movRegToDir();
void movDirToDir();
void movAddrToDir();
void movDataToDir();
void movAToAddr();
void movDirToAddr();
void movDataToAddr();
void movDataTodptr();
void clrA();
void incA();
void incReg();
void incDir();
void incAddr();
void decA();
void decReg();
void decDir();
void decAddr();
void nop();
void rrA();
void rrcA();
void rlA();
void rlcA();
void mulAB();
void swapA();
void cplA();
void xrlAToDir();
void xrlDataToDir();
void xrlDataToA();
void xrlDirToA();
void xrlAddrToA();
void xrlRegToA();
void addRegToA();
void addDirToA();
void addDataToA();
void addAddrToA();
void subbRegToA();
void subbDirToA();
void subbDataToA();
void subbAddrToA();
void orlAToDir();
void orlDataToDir();
void orlDataToA();
void orlAddrToA();
void orlDirToA();
void orlRegToA();
void anlRegtoA();
void anlDirToA();
void anlAddrToA();
void anlDataToA();
void anlAToDir();
void anlDataToDir();
void sjmp();
void ljmp();
void jz();
void jnz();
void jnc();
void jc();
#endif // I8051SIMULATOR_H
