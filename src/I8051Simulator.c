#include "I8051Simulator.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


ExecuteInstruction I8051ExecutionTable[256] = {
  [0x74] = mov,
  [0xe8] = mov, mov, mov, mov, mov, mov, mov,
  [0xe5] = mov,
  [0xe6] = mov, mov, 
};

int pc = 0;
/*
  *lower half of RAM is accessible through indirect accessing mode or
  *direct accessing mode. Whereas, the top half of RAM is only accessible
  *through indirect addressing mode
*/
uint8_t ram[256];

/*
  *bottom half cannot be used. only top half can be used.
  *and only can be access through direct accessing mode.
*/
uint8_t sfr[256];

//External RAM
uint8_t xram[0x10000];

//codeMemory
uint8_t codeMemory[0x10000]; //64KB


void executeInstruction()
{
  uint8_t *codePtr = &codeMemory[pc];
  ExecuteInstruction executor = I8051ExecutionTable[codePtr[1]];
  executor();
}

void writeToRam(int address, AccessMode mode, uint8_t data) 
{ 
  if(address > 127) {
    mode = (DIRECT_ADDRESSING);
    sfr[address] = data;  
  }else {
    mode = (DIRECT_ADDRESSING | INDIRECT_ADDRESSING);
    ram[address] = data;
  }
  if(address > 127) {
    mode = INDIRECT_ADDRESSING;
    ram[address] = data;
  }
}

uint8_t readFromRam(int address, AccessMode mode)
{
  if(sfr[address]) {
    mode = DIRECT_ADDRESSING;
  }else
    if(ram[address]) {
      mode = (DIRECT_ADDRESSING | INDIRECT_ADDRESSING);
    } 
}

/*
 * 0xeb = 1110 1rrr
 * bit number 3 of 0xeb
 * identify condition 0xeb either 1 or 0

   xxxx1xxx
 & 00001000
-----------
   00001000  (!= 0) 
   
if (codePtr & 8)

    xxxxxrrr
   &00000111 
  -----------
    00000111   7 decimal

  direct address
  MOV 30H, A 
  
*/
void mov()
{
  uint8_t *codePtr = &codeMemory[pc];
 
  if (codePtr[0] & (1 << 3) ) {
    acc = r(*codePtr & 7);
  }else {
    if (codePtr[0] & (1 << 1)) {
      acc = readFromRam(codePtr[1], DIRECT_ADDRESSING);
    }else {
      acc = readFromRam(r(codePtr[0] & 1),INDIRECT_ADDRESSING);
    } 
  }
  pc += 1;
}



