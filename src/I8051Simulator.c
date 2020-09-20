#include "I8051Simulator.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


ExecuteInstruction I8051ExecutionTable[256] = {
  [0x74] = movDataToA,
  [0xe2] = movXAddrToA,movXAddrToA,
  [0xe5] = mov,
  [0xe6] = mov, mov,
  [0xe8] = mov, mov, mov, mov, mov, mov, mov, mov,
  [0x78] = movDataToReg,movDataToReg,movDataToReg,movDataToReg,
           movDataToReg,movDataToReg,movDataToReg,movDataToReg,
  [0xa8] = movDirToReg,movDirToReg,movDirToReg,movDirToReg,
           movDirToReg,movDirToReg,movDirToReg,movDirToReg,
  [0xf8] = movAToReg,movAToReg,movAToReg,movAToReg,
           movAToReg,movAToReg,movAToReg,movAToReg,
  [0x75] = movDataToDir,
  [0x85] = movDirToDir,
  [0x86] = movAddrToDir, movAddrToDir,
  [0x88] = movRegToDir,movRegToDir,movRegToDir,movRegToDir,
           movRegToDir,movRegToDir,movRegToDir,movRegToDir,
  [0xf5] = movAToDir,
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
  [0x03] = rrA,
  [0x13] = rrcA,
  [0x23] = rlA,
  [0x33] = rlcA,
  [0x84] = divAB,
  [0xa4] = mulAB, 
  [0xc4] = swapA,
  [0xe4] = clrA,
  [0xf4] = cplA,
  [0x62] = xrlAToDir,
  [0x63] = xrlDataToDir,
  [0x64] = xrlDataToA,
  [0x65] = xrlDirToA,
  [0x66] = xrlAddrToA,xrlAddrToA,
  [0x68] = xrlRegToA, xrlRegToA, xrlRegToA, xrlRegToA, 
           xrlRegToA, xrlRegToA, xrlRegToA, xrlRegToA,
  [0x24] = addDataToA,
  [0x25] = addDirToA,
  [0x26] = addAddrToA,addAddrToA,
  [0x28] = addRegToA, addRegToA, addRegToA, addRegToA,
           addRegToA, addRegToA, addRegToA, addRegToA,
  [0x34] = addCDataToA,
  [0x35] = addCDirToA,
  [0x36] = addCAddrToA,addCAddrToA,
  [0x38] = addCRegToA,addCRegToA,addCRegToA,addCRegToA,
           addCRegToA,addCRegToA,addCRegToA,addCRegToA,
  [0x94] = subbDataToA,
  [0x95] = subbDirToA,
  [0x96] = subbAddrToA, subbAddrToA,
  [0x98] = subbRegToA,subbRegToA,subbRegToA,subbRegToA,
           subbRegToA,subbRegToA,subbRegToA,subbRegToA,
  [0x42] = orlAToDir,
  [0x43] = orlDataToDir,
  [0x44] = orlDataToA,
  [0x45] = orlDirToA,
  [0x46] = orlAddrToA,orlAddrToA,
  [0x48] = orlRegToA,orlRegToA,orlRegToA,orlRegToA,
           orlRegToA,orlRegToA,orlRegToA,orlRegToA,
  [0x52] = anlAToDir,
  [0x53] = anlDataToDir,
  [0x54] = anlDataToA, 
  [0x55] = anlDirToA,
  [0x56] = anlAddrToA, anlAddrToA, 
  [0x58] = anlRegtoA,anlRegtoA,anlRegtoA,anlRegtoA,
           anlRegtoA,anlRegtoA,anlRegtoA,anlRegtoA,
  [0x10] = ljmp,
  [0x40] = jc,
  [0x50] = jnc,
  [0x60] = jz,
  [0x70] = jnz,
  [0x80] = sjmp, 
  [0xd4] = daA,
  
  
};

// initialize Program Counter to 0
uint16_t pc = 0;

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

// External RAM
uint8_t xram[0x10000];

// codeMemory
uint8_t codeMemory[0x10000]; //64KB


void executeInstruction()
{
  uint8_t *codePtr = &codeMemory[pc];
  ExecuteInstruction executor = I8051ExecutionTable[codePtr[0]];
  executor();
}

// writeToMemory
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

// readFromMemory
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

// readFromXternalMemory
uint8_t readFromXternalMemory(int address, AccessMode mode)
{
  if(address > 127) {
    if(mode == INDIRECT_ADDRESSING)
      return xram[address];
  } 
}

// sum function 
uint8_t sum(uint32_t val1, uint32_t val2)
{
  uint32_t val3 = val1 + val2;
  uint32_t val4 = ((val1 & 0x0f) + (val2 & 0x0f));
  psw = psw & 0x7f;
  psw = ((val3 >> 1) & 0x80) | psw;
  psw = ((val4 << 2 ) & 0x40) | psw;
  return (uint8_t)(val3);
}

// subtract function 
uint8_t substract(uint32_t val1, uint32_t val2)
{
  uint32_t val3 = val1 - val2;
  psw = psw & 0x7f;
  psw = ((val3 >> 1) & 0x80) | psw;
  return (uint8_t)val3;
}

// handle overflow function
void handleOverFlow(uint32_t val1, uint32_t val2, uint32_t result)
{
  psw = psw & 0xfb;
  psw = ((val1 & 0x80) & (val2 & 0x80) & (~result & 0x80) 
        | (~val1 & 0x80) & (~val2 & 0x80) & (result & 0x80)) >> 5
        | psw;
}

// Data Pointer
void dataPointer(uint8_t val1, uint8_t val2)
{
  DPH = val1;
  DPL = val2;
}

// Decimal-Adjust Acc 
uint8_t decimalAdjust(uint32_t val1)
{
  uint32_t val3 = (val1 & 0x0f);
  uint32_t val4 = (val1 & 0xf0);
  if(val3 > 9 | status.AC == 1) {
    val3 += 6;
  }
  if(val4 > 0x90 | status.CY == 1){
    val4 += 0x60;
  }
  if(val4 & 0x100) {
    status.CY = 1;
  }
  return (uint8_t)(val3 + val4);
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

void movDataToA()
{
  uint8_t *codePtr = &codeMemory[pc];
  acc = codePtr[1];
  pc += 2;
}

void movAToReg()
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

void movAToDir()
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

void movXAddrToA()
{
  uint8_t *codePtr = &codeMemory[pc];
  int xternalData = xr(codePtr[0] & 1);
  acc = readFromXternalMemory(xternalData, INDIRECT_ADDRESSING);
  pc += 1;
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

void xrlDataToA()
{
  uint8_t *codePtr = &codeMemory[pc];
  acc = acc ^ codePtr[1];
  pc += 2;
}

void xrlDirToA()
{
  uint8_t *codePtr = &codeMemory[pc];
  int dataLocation = readFromMemory(codePtr[1], DIRECT_ADDRESSING);
  acc = acc ^ dataLocation;
  pc += 2;  
}

void xrlRegToA()
{
  uint8_t *codePtr = &codeMemory[pc];
  acc = (acc ^ (r(*codePtr & 7)));
  pc += 1;
}

void xrlAddrToA()
{
  uint8_t *codePtr = &codeMemory[pc];
  int readData = readFromMemory(r(codePtr[0] & 1), INDIRECT_ADDRESSING);
  acc = acc ^ readData;
  pc += 1;
}

void xrlAToDir()
{
  uint8_t *codePtr = &codeMemory[pc]; 
  int dataLocation = readFromMemory(codePtr[1], DIRECT_ADDRESSING);
  dataLocation = dataLocation ^ acc;
  writeToMemory(codePtr[1], DIRECT_ADDRESSING, dataLocation); 
  pc += 2;
}

void xrlDataToDir()
{
  uint8_t *codePtr = &codeMemory[pc];
  int dataLocation = readFromMemory(codePtr[1], DIRECT_ADDRESSING);
  dataLocation = dataLocation ^ codePtr[2];
  writeToMemory(codePtr[1], DIRECT_ADDRESSING, dataLocation); 
  pc += 3;
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

void addCRegToA()
{
  uint8_t *codePtr = &codeMemory[pc];
  int regR = r(*codePtr & 7); 
  int result = sum(acc, regR);
  handleOverFlow(acc, regR, result);
  acc = result + status.CY;
  pc += 1;
}

void addCDirToA()
{
  uint8_t *codePtr = &codeMemory[pc];
  int readData = readFromMemory(codePtr[1], DIRECT_ADDRESSING);
  int result = sum(acc, readData);
  handleOverFlow(acc, readData, result);
  acc = result + status.CY;
  pc += 2;
}

void addCDataToA()
{
  uint8_t *codePtr = &codeMemory[pc];
  int result = sum(acc, codePtr[1]);
  handleOverFlow(acc, codePtr[1], result);
  acc = result + status.CY;
  pc += 2;
}

void addCAddrToA()
{
  uint8_t *codePtr = &codeMemory[pc];
  int addrData = r(codePtr[0] & 1);
  int readData = readFromMemory(addrData, INDIRECT_ADDRESSING);
  int result = sum(acc, readData);
  handleOverFlow(acc, readData, result);
  acc = result + status.CY; 
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

void orlRegToA()
{
  uint8_t *codePtr = &codeMemory[pc];
  acc = acc | r(*codePtr & 7);
  pc += 1; 
}
void orlDirToA()
{
  uint8_t *codePtr = &codeMemory[pc];
  int dataLocation = readFromMemory(codePtr[1], DIRECT_ADDRESSING);
  acc = acc | dataLocation;
  pc += 2;
}

void orlDataToA()
{
  uint8_t *codePtr = &codeMemory[pc];
  acc = acc | codePtr[1];
  pc += 2;
}

void orlAddrToA()
{
  uint8_t *codePtr = &codeMemory[pc];
  int readData = readFromMemory(r(codePtr[0] & 1), INDIRECT_ADDRESSING);
  acc = acc | readData;
  pc += 1;
}

void orlAToDir()
{
  uint8_t *codePtr = &codeMemory[pc];
  int dataLocation = readFromMemory(codePtr[1], DIRECT_ADDRESSING);
  dataLocation = dataLocation | acc;
  writeToMemory(codePtr[1], DIRECT_ADDRESSING, dataLocation);
  pc += 2;
}

void orlDataToDir()
{
  uint8_t *codePtr = &codeMemory[pc];
  int dataLocation = readFromMemory(codePtr[1], DIRECT_ADDRESSING);
  dataLocation = dataLocation | codePtr[2];
  writeToMemory(codePtr[1], DIRECT_ADDRESSING, dataLocation);
  pc += 3;
}

void divAB()
{
  uint16_t result;
  uint8_t *codePtr = &codeMemory[pc];
  result = (uint16_t)acc / B;
  B = acc % B;
  acc = (uint8_t)result;
  status.OV = 0;
  status.CY = 0;
  pc += 1;
}

void mulAB()
{
  uint16_t result;
  uint8_t *codePtr = &codeMemory[pc];
  result = (uint16_t)acc * B;
  acc = (uint8_t)result;
  B = (uint8_t)(result >> 8);
  status.CY = 0;
  status.OV = 1;
  pc += 1;
}

// acc << n | acc >> 8(bit)-n
void rlA()
{
  uint8_t result;
  uint8_t *codePtr = &codeMemory[pc];
  acc = acc << 1 | acc >> 8-1;
  pc += 1;
}

void rlcA()
{
  uint8_t result;
  uint8_t *codePtr = &codeMemory[pc];
  int storeFlag = status.CY;
  status.CY = (acc & 0x80) >> 7;
  acc = acc << 1 | storeFlag;
  pc += 1;
}

void rrA()
{
  uint8_t result;
  uint8_t *codePtr = &codeMemory[pc];
  acc = acc >> 1 | acc << 8-1;
  pc += 1;
}

void rrcA()
{
  uint8_t result;
  uint8_t *codePtr = &codeMemory[pc];
  int storeFlag = status.CY;
  status.CY = acc & 0x01;
  acc = acc >> 1 | (storeFlag << 7);
  pc += 1;
}

void sjmp()
{
  int8_t *codePtr = &codeMemory[pc];
  pc = pc + codePtr[1] + 2;
}

void ljmp()
{
  int8_t *codePtr = &codeMemory[pc];
  pc = (codePtr[1] << 8) | codePtr[2];
}

void jz()
{
  int8_t *codePtr = &codeMemory[pc];
  if(acc == 0) {
    pc = pc + 2 + codePtr[1];
  }else {
    pc += 2;
  }
}

void jnz()
{
  int8_t *codePtr = &codeMemory[pc];
  if(acc != 0) {
    pc = pc + 2 + codePtr[1];
  }else {
    pc += 2;
  }
}

void jnc()
{
  int8_t *codePtr = &codeMemory[pc];
  if(status.CY == 0) {
    pc = pc + 2 + codePtr[1];
  }else {
    pc += 2;
  }
}

void jc()
{
  int8_t *codePtr = &codeMemory[pc];
  if(status.CY == 1) {
    pc = pc + 2 + codePtr[1];
  }else {
    pc += 2;
  }
}

void daA()
{
  int8_t *codePtr = &codeMemory[pc];
  acc = decimalAdjust(acc);
  pc += 1;
}
