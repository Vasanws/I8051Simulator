#include "I8051Simulator.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


ExecuteInstruction I8051ExecutionTable[256] = {
  [0x74] = movImmediateDataToAcc,
  [0xe8] = mov, mov, mov, mov, mov, mov, mov,
  [0xe5] = mov,
  [0xe6] = mov, mov, 
  [0xf8] = movAccToReg,movAccToReg,movAccToReg,movAccToReg,
           movAccToReg,movAccToReg,movAccToReg,movAccToReg,
  [0xa8] = movDirToReg,movDirToReg,movDirToReg,movDirToReg,
           movDirToReg,movDirToReg,movDirToReg,movDirToReg,
  [0x78] = movDataToReg,movDataToReg,movDataToReg,movDataToReg,
           movDataToReg,movDataToReg,movDataToReg,movDataToReg,
  [0xf5] = movAccToDir,
  [0xe4] = clrA,
  [0x04] = incA, 
  [0x08] = incR, incR, incR, incR, incR, incR, incR, 
  [0x14] = decA,
  [0x00] = nop,
  [0xc4] = swapA,
  [0xf4] = cplA,
  
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
  ExecuteInstruction executor = I8051ExecutionTable[codePtr[0]];
  executor();
}
//writeToMemory
void writeToMemory(int address, AccessMode mode, uint8_t data) 
{ 
  if(address > 127) {
    if(mode == DIRECT_ADDRESSING)
      sfr[address] = data;
    else if(mode == INDIRECT_ADDRESSING)
      ram[address] = data;
  }else {
    ram[address] = data;
  }
   
}
//readFromMemory
uint8_t readFromMemory(int address, AccessMode mode)
{
  if(address > 127) {
    if(mode == DIRECT_ADDRESSING)
      return sfr[address];
    else if(mode == INDIRECT_ADDRESSING)
      return ram[address];
  }else {
    return ram[address];
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

    xxxxxrrr (mask)
   &00000111 
  -----------
    00000111   7 decimal

  direct address
  MOV 30H, A 
  0x0f
*/
void mov()
{
  uint8_t *codePtr = &codeMemory[pc];
  
  if (codePtr[0] & (1 << 3)) {
    acc = r(*codePtr & 7);
  } else {
    if (codePtr[0] == 0xe5) {
      acc = readFromMemory(codePtr[1], DIRECT_ADDRESSING);
      pc += 2;
      return;
    }else {
      acc = readFromMemory(r(codePtr[0] & 1), INDIRECT_ADDRESSING); 
    } 
  }
  pc += 1;
}
void movImmediateDataToAcc()
{
  uint8_t *codePtr = &codeMemory[pc];
  acc = codePtr[1];
  pc += 2;
}
void movAccToReg()
{
  uint8_t *codePtr = &codeMemory[pc];
  r(*codePtr & 7) = acc;
  pc += 1;
}
void movDirToReg()
{
  uint8_t *codePtr = &codeMemory[pc];
  r(*codePtr & 7) = readFromMemory(codePtr[1], DIRECT_ADDRESSING);
  pc += 2;
}
void movDataToReg()
{
  uint8_t *codePtr = &codeMemory[pc];
   r(*codePtr & 7) = codePtr[1];
   pc += 2;
}
void movAccToDir()
{
  uint8_t *codePtr = &codeMemory[pc];   //*codePtr contains the code 0xf5
  int directData = readFromMemory(codePtr[1], DIRECT_ADDRESSING); //codePtr[1] contains the value 0x54(84) and read 
                                                                  //DIRECT_ADDRESSING
  directData = acc;
  pc += 2;
}
void clrA() 
{
  uint8_t *codePtr = &codeMemory[pc];
  acc = 0;
  pc += 1;
}

void incA()
{
  uint8_t *codePtr = &codeMemory[pc];
  acc += 1;
  pc += 1; 
}
void decA()
{
  uint8_t *codePtr = &codeMemory[pc];
  acc -= 1;
  pc += 1; 
}
void incR() 
{
  uint8_t *codePtr = &codeMemory[pc];
  r(*codePtr & 7) += 1;
  pc += 1;
}
void nop()
{
  uint8_t *codePtr = &codeMemory[pc];
  pc += 1;
}
/*
 acc = 6B => 0110 1011
      (acc) << 4
      01101011
 0110 10110000
        OR
       (acc) >> 4
       01101011
       00000110 1011
    
 acc = B6 => 1011 0110

*/
void swapA() 
{
  uint8_t *codePtr = &codeMemory[pc];
  acc = ((acc) << 4 | (acc) >> 4);
  pc += 1;
}
void cplA()
{
  uint8_t *codePtr = &codeMemory[pc];
  acc = (~acc);
  pc += 1;
}


