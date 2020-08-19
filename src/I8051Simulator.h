#ifndef I8051SIMULATOR_H
#define I8051SIMULATOR_H
#include <stdint.h>


typedef enum {
  DIRECT_ADDRESSING,
  INDIRECT_ADDRESSING,
}AccessMode;

#define acc   sfr[0xe0]
#define psw   sfr[0xd0]
#define r(n)  ram[((psw >> 3) & 0x03) * 8 + (n)]

     
extern uint8_t ram[];
extern uint8_t sfr[];
extern uint8_t xram[];
extern uint8_t codeMemory[];
extern int pc;

typedef void(*ExecuteInstruction)(void);

void writeToRam(int address, AccessMode mode, uint8_t data);
uint8_t readFromRam(int address, AccessMode mode);

void executeInstruction();
void mov();
void movD();
void movAddr();
void clrA();
void incA();
void incR();
void decA();

#endif // I8051SIMULATOR_H


/*psw
76543210
...10...

......10 * 8 = 16*/