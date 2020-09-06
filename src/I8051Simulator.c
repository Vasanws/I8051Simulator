#include "I8051Simulator.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


ExecuteInstruction I8051ExecutionTable[256] = {
  [0x74] = movDataToAcc,
  [0xe5] = mov,
  [0xe6] = mov, mov,
  [0xe8] = mov, mov, mov, mov, mov, mov, mov, mov,
  [0x78] = movDataToReg,movDataToReg,movDataToReg,movDataToReg,
           movDataToReg,movDataToReg,movDataToReg,movDataToReg,
  [0xa8] = movDirToReg,movDirToReg,movDirToReg,movDirToReg,
           movDirToReg,movDirToReg,movDirToReg,movDirToReg,
  [0xf8] = movAccToReg,movAccToReg,movAccToReg,movAccToReg,
           movAccToReg,movAccToReg,movAccToReg,movAccToReg,
  [0x75] = movDataToDir,
  [0x85] = movDirToDir,
  [0x86] = movAddrToDir, movAddrToDir,
  [0x88] = movRegToDir,movRegToDir,movRegToDir,movRegToDir,
           movRegToDir,movRegToDir,movRegToDir,movRegToDir,
  [0xf5] = movAccToDir,
  [0x77] = movDataToAddr, movDataToAddr,
  [0xf6] = movAToAddr, movAToAddr,
  [0xa6] = movDirToAddr, movDirToAddr,
  [0x90] = movDataTodptr,
  [0x04] = incA, 
  [0x05] = incDir,
  [0x06] = incAddr, incAddr,
  [0x08] = incReg, incReg, incReg, incReg,
           incReg, incReg, incReg, incReg,
  [0x14] = decA,
  [0x15] = decDir, 
  [0x16] = decAddr, decAddr,
  [0x18] = decReg, decReg, decReg, decReg, 
           decReg, decReg, decReg, decReg,
  [0x00] = nop,
  [0xc4] = swapA,
  [0xe4] = clrA,
  [0xf4] = cplA,
  [0x68] = xrlReg, xrlReg, xrlReg, xrlReg, 
           xrlReg, xrlReg, xrlReg, xrlReg,
  [0x24] = addDataToA,
  [0x25] = addDirToA,
  [0x26] = addAddrToA,addAddrToA,
  [0x28] = addRegToA, addRegToA, addRegToA, addRegToA,
           addRegToA, addRegToA, addRegToA, addRegToA,
  [0x94] = subbDataToA,
  [0x95] = subbDirToA,
  [0x96] = subbAddrToA, subbAddrToA,
  [0x98] = subbRegToA,subbRegToA,subbRegToA,subbRegToA,
           subbRegToA,subbRegToA,subbRegToA,subbRegToA,
  [0x52] = anlAToDir,
  [0x53] = anlDataToDir,
  [0x54] = anlDataToA, 
  [0x55] = anlDirToA,
  [0x56] = anlAddrToA, anlAddrToA, 
  [0x58] = anlRegtoA,anlRegtoA,anlRegtoA,anlRegtoA,
           anlRegtoA,anlRegtoA,anlRegtoA,anlRegtoA,
  
   

};

//initialize Program Counter to 0
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

//sum function 
uint8_t sum(uint32_t val1, uint32_t val2)
{
  uint32_t val3 = val1 + val2;
  psw = psw & 0x7f;
  psw = ((val3 >> 1) & 0x80) | psw;
  return (uint8_t)val3;
}

//subtract function 
uint8_t substract(uint32_t val1, uint32_t val2)
{
  uint32_t val3 = val1 - val2;
  psw = psw & 0x7f;
  psw = ((val3 >> 1) & 0x80) | psw;
  return (uint8_t)val3;
}

//handle overflow function
void handleOverFlow(uint32_t val1, uint32_t val2, uint32_t result)
{
  psw = psw & 0xfb;
  psw = ((val1 & 0x80) & (val2 & 0x80) & (~result & 0x80) 
        | (~val1 & 0x80) & (~val2 & 0x80) & (result & 0x80)) >> 5
        | psw;
}

//Data Pointer
void dataPointer(uint8_t val1, uint8_t val2)
{
  DPH = val1;
  DPL = val2;
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

void movDataToAcc()
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
  uint8_t *codePtr = &codeMemory[pc]; 
  writeToMemory(codePtr[1], DIRECT_ADDRESSING, acc);
  pc += 2;
}

void movRegToDir()
{
  uint8_t *codePtr = &codeMemory[pc];
  writeToMemory(codePtr[1], DIRECT_ADDRESSING, r(*codePtr & 7));
  pc += 2;
}

void movDirToDir()
{
  uint8_t *codePtr = &codeMemory[pc];
  int dataRead = readFromMemory(codePtr[1], DIRECT_ADDRESSING);
  writeToMemory(codePtr[2], DIRECT_ADDRESSING, dataRead);
  pc += 2;
}

void movAddrToDir()
{
  uint8_t *codePtr = &codeMemory[pc];
  int readData = readFromMemory(r(codePtr[0] & 1), INDIRECT_ADDRESSING);
  writeToMemory(codePtr[1], DIRECT_ADDRESSING, readData);
  pc += 2;
}

void movDataToDir()
{
  uint8_t *codePtr = &codeMemory[pc];
  writeToMemory(codePtr[1], DIRECT_ADDRESSING, codePtr[2]);
  pc += 2;
}

void movAToAddr()
{
  uint8_t *codePtr = &codeMemory[pc];
  int readData = readFromMemory(r(codePtr[0] & 1), INDIRECT_ADDRESSING);
  writeToMemory(readData, INDIRECT_ADDRESSING, acc);
  pc += 1;
}

void movDirToAddr()
{
  uint8_t *codePtr = &codeMemory[pc];
  int readData = readFromMemory(r(codePtr[0] & 1), INDIRECT_ADDRESSING);
  int dataLocation = readFromMemory(codePtr[1], DIRECT_ADDRESSING);
  writeToMemory(readData, INDIRECT_ADDRESSING, dataLocation);
  pc += 2;
}

void movDataToAddr()
{
  uint8_t *codePtr = &codeMemory[pc];
  int readData = readFromMemory(r(codePtr[0] & 1), INDIRECT_ADDRESSING);
  writeToMemory(readData, INDIRECT_ADDRESSING, codePtr[1]);
  pc += 2;
}

void movDataTodptr()
{
  uint8_t *codePtr = &codeMemory[pc];
  dataPointer(codePtr[1], codePtr[2]);
  pc += 3;
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

void incReg() 
{
  uint8_t *codePtr = &codeMemory[pc];
  r(*codePtr & 7) += 1;
  pc += 1;
}

void incDir()
{
  uint8_t *codePtr = &codeMemory[pc];
  int incData = readFromMemory(codePtr[1], DIRECT_ADDRESSING);
  incData += 1;
  writeToMemory(codePtr[1], DIRECT_ADDRESSING, incData);
  pc += 2;
}

void incAddr()
{
  uint8_t *codePtr = &codeMemory[pc];
  int incAddrData = readFromMemory(r(codePtr[0] & 1), INDIRECT_ADDRESSING);
  incAddrData += 1;
  writeToMemory(codePtr[1], DIRECT_ADDRESSING, incAddrData);
  pc += 1;
}

void decA()
{
  uint8_t *codePtr = &codeMemory[pc];
  acc -= 1;
  pc += 1; 
}

void decReg()
{
  uint8_t *codePtr = &codeMemory[pc];
  r(*codePtr & 7) -= 1;
  pc += 1;
}

void decDir()
{
  uint8_t *codePtr = &codeMemory[pc];
  int decData = readFromMemory(codePtr[1], DIRECT_ADDRESSING);
  decData -= 1;
  writeToMemory(codePtr[1], DIRECT_ADDRESSING, decData);
  pc += 2; 
}

void decAddr()
{
  uint8_t *codePtr = &codeMemory[pc];
  int decAddrData = readFromMemory(r(codePtr[0] & 1), INDIRECT_ADDRESSING);
  decAddrData -= 1;
  writeToMemory(codePtr[1], DIRECT_ADDRESSING, decAddrData);
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

void xrlReg()
{
  uint8_t *codePtr = &codeMemory[pc];
  acc = (acc ^ (r(*codePtr & 7)));
  pc += 1;
}

void addRegToA()
{
  uint8_t *codePtr = &codeMemory[pc];
  int result = sum(acc, r(*codePtr & 7));
  handleOverFlow(acc, r(*codePtr & 7), result);
  acc = result;
  pc += 1;
}

void addDirToA()
{
  uint8_t *codePtr = &codeMemory[pc];
  int dataLocation = readFromMemory(codePtr[1], DIRECT_ADDRESSING);
  int result = sum(acc, dataLocation);
  handleOverFlow(acc, dataLocation, result);  
  acc = result;
  pc += 2;
}

void addDataToA()
{
  uint8_t *codePtr = &codeMemory[pc];
  int result = sum(acc, codePtr[1]);
  handleOverFlow(acc, codePtr[1], result);
  acc = result;
  pc += 2;
}

void addAddrToA()
{
  uint8_t *codePtr = &codeMemory[pc];
  int readData = readFromMemory(r(codePtr[0] & 1), INDIRECT_ADDRESSING);
  int result = sum(acc, readData);
  handleOverFlow(acc, readData, result);
  acc = result;
  pc += 1;
}

void subbRegToA()
{
  uint8_t *codePtr = &codeMemory[pc];
  int result = substract(acc, status.CY + r(*codePtr & 7));
  handleOverFlow(acc, -(status.CY + r(*codePtr & 7)), result);
  acc = result;
  pc += 1;
}

void subbDirToA()
{
  uint8_t *codePtr = &codeMemory[pc];
  int dataLocation = readFromMemory(codePtr[1], DIRECT_ADDRESSING);
  int result = substract(acc, status.CY + dataLocation);
  handleOverFlow(acc, -(status.CY + dataLocation), result);
  acc = result;
  pc += 2; 
}

void subbDataToA()
{
  uint8_t *codePtr = &codeMemory[pc];
  int result = substract(acc, status.CY + codePtr[1]);
  handleOverFlow(acc, -(status.CY + codePtr[1]), result);
  acc = result;
  pc += 2;
}

void subbAddrToA()
{
  uint8_t *codePtr = &codeMemory[pc];
  int readData = readFromMemory(r(codePtr[0] & 1), INDIRECT_ADDRESSING);
  int result = substract(acc, status.CY + readData);
  handleOverFlow(acc, -(status.CY + readData), result);
  acc = result;
  pc += 1;
}

void anlRegtoA()
{
  uint8_t *codePtr = &codeMemory[pc];
  acc = acc & r(*codePtr & 7);
  pc += 1; 
}

void anlDirToA()
{
  uint8_t *codePtr = &codeMemory[pc];
  int dataLocation = readFromMemory(codePtr[1], DIRECT_ADDRESSING);
  acc = acc & dataLocation;
  pc += 2;
}

void anlDataToA()
{
  uint8_t *codePtr = &codeMemory[pc];
  acc = acc & codePtr[1];
  pc += 2;
}

void anlAddrToA()
{
  uint8_t *codePtr = &codeMemory[pc];
  int readData = readFromMemory(r(codePtr[0] & 1), INDIRECT_ADDRESSING);
  acc = acc & readData;
  pc += 1;
}
void anlAToDir()
{
  uint8_t *codePtr = &codeMemory[pc];
  int dataLocation = readFromMemory(codePtr[1], DIRECT_ADDRESSING);
  dataLocation = dataLocation & acc;
  writeToMemory(codePtr[1], DIRECT_ADDRESSING, dataLocation);
  pc += 2;
}

void anlDataToDir()
{
  uint8_t *codePtr = &codeMemory[pc];
  int dataLocation = readFromMemory(codePtr[1], DIRECT_ADDRESSING);
  dataLocation = dataLocation & codePtr[2];
  writeToMemory(codePtr[1], DIRECT_ADDRESSING, dataLocation);
  pc += 3;
}
