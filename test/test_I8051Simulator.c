#include "unity.h"
#include "I8051Simulator.h"
#include "_testHelper.h"


extern uint8_t ram[];
extern uint8_t sfr[];

void setUp(void){}

void tearDown(void){}

/*---------------------------TEST writeToRam function---------------------------*/
void test_given_address_0xfa_is_DIRECT_ADDRESSING_mode_data_0x76_in_SFR_expect_data_0x76_write_to_address_0xfa_mode_DIRECT_ADDRESSING_in_SFR(void) 
{
  //setup 0xfa top RAM address set value is 0
  sfr[0xfa] = 0;
  //call functon to test the mode
  //           address   AccessMode      data
  writeToMemory(0xfa, DIRECT_ADDRESSING, 0x76);
  //code output test
  TEST_ASSERT_EQUAL(0x76, sfr[0xfa]);
  
}
void test_given_address_0x9b_is_INDIRECT_ADDRESSING_mode_data_0x69_top_SRAM_expect_data_0x69_write_to_address_0x9b_mode_INDIRECT_ADDRESSING_in_top_SRAM(void) 
{
  //setup 0x9b top RAM address set value is 0
  ram[0x9b] = 0;
  //call functon to test the mode
  //            address   AccessMode      data
  writeToMemory(0x9b, INDIRECT_ADDRESSING, 0x69);
  //code output test
  TEST_ASSERT_EQUAL(0x69, ram[0x9b]);
}
void test_given_address_0x11_is_DIRECT_ADDRESSING_data_0x43_bottom_RAM_expect_data_0x43_write_to_address_0x11_mode_DIRECT_ADDRESSING_in_bottom_RAM(void) 
{
  //setup 0x11 bottom RAM address set value is 0
  ram[0x11] = 0;
  //call functon to test the mode
  //          address   AccessMode      data
  writeToMemory(0x11, DIRECT_ADDRESSING, 0x43);
  //code output test
  TEST_ASSERT_EQUAL(0x43, ram[0x11]);
}
void test_given_address_0x7e_to_INDIRECT_ADDRESSING_mode_data_0x55_bottom_RAM_expect_data_0x55_write_to_address_0x7e_mode_INDIRECT_ADDRESSING_in_bottom_RAM(void) 
{
  //setup 0x7e bottom RAM address set value is 0
  ram[0x7e] = 0;
  //call functon to test the mode
  //           address   AccessMode      data
  writeToMemory(0x7e, INDIRECT_ADDRESSING, 0x55);
  //code output test
  TEST_ASSERT_EQUAL(0x55, ram[0x7e]);
}

/*---------------------------TEST readFromRam function------------------------------*/
void test_given_address_0xff_readmode_DIRECT_ADDRESSING_of_SFR_expect_to_read_address_0xff_from_SFR_mode_DIRECT_ADDRESSING(void)
{
  int dataRead = 0;
  //setup RAM address to be read
  sfr[0xff] = 0x98;
  ram[0xff] = 0;
  //call function to test mode 
  //                        address    AccessMode
  dataRead = readFromMemory(0xff, DIRECT_ADDRESSING);
  //code output test
  TEST_ASSERT_EQUAL(0x98, dataRead); 
}

void test_given_address_0x88_read_mode_INDIRECT_ADDRESSING_of_SRAM_expect_to_read_address_0x88_from_SRAM_mode_INDIRECT_ADDRESSING(void)
{
  int dataRead = 0;
  //setup RAM address to be read
  ram[0x88] = 0x64;
  sfr[0x88] = 0;
  //call function to test mode 
  //                        address     mode
  dataRead = readFromMemory(0x88, INDIRECT_ADDRESSING);
  //code output test
  TEST_ASSERT_EQUAL(0x64, dataRead); 
}

void test_given_address_0x42_read_mode_DIRECT_ADDRESSING_of_RAM_expect_to_read_address_0x42_from_RAM_mode_DIRECT_ADDRESSING(void)
{
  int dataRead = 0;
  //setup RAM address to be read
  ram[0x42] = 0x71;
  //call function to test mode 
  //                        address     mode
  dataRead = readFromMemory(0x42, DIRECT_ADDRESSING);
  //code output test
  TEST_ASSERT_EQUAL(0x71, dataRead); 
}

void test_given_address_0x38_read_mode_INDIRECT_ADDRESSING_of_RAM_expect_to_read_address_0x38_from_RAM_mode_INDIRECT_ADDRESSING(void)
{
  int dataRead = 0;
  //setup RAM address to be read
  ram[0x38] = 0x65;
  //call function to test mode 
  //                        address     mode
  dataRead = readFromMemory(0x38, INDIRECT_ADDRESSING);
  //code output test
  TEST_ASSERT_EQUAL(0x65, dataRead); 
}

/*-------------------------Test BANK selection--------------------*/
void test_R3_access_given_register_select_bank2_expect_access_address_0x13_of_bank2(void)
{
    //test all bank setup
    ram[0x03] = 0x12;     //R3 of bank 0
    ram[0x0b] = 0x50;     //R3 of bank 1
    ram[0x13] = 0x30;     //R3 of bank 2
    ram[0x1b] = 0x20;     //R3 of bank 3
    //acc is 0
    acc = 0x00;
    //select bank 10 => bank 2 of R3
    psw = 2 << 3;
    //assign replacement value
    r(3) = 0x26;
    //code output test
    TEST_ASSERT_EQUAL(0x26, r(3));
    TEST_ASSERT_EQUAL(0x12,ram[0x03]);      
    TEST_ASSERT_EQUAL(0x50, ram[0x0b]);
    TEST_ASSERT_EQUAL(0x26, ram[0x13]);
    TEST_ASSERT_EQUAL(0x20, ram[0x1b]);
}

void test_R6_access_given_register_select_bank3_expect_access_address_0x1e_of_bank3(void)
{
    //test all bank setup
    ram[0x06] = 0x5a;     //R6 of bank 0
    ram[0x0e] = 0x3d;     //R6 of bank 1
    ram[0x16] = 0x62;     //R6 of bank 2
    ram[0x1e] = 0x2f;     //R6 of bank 3
    //acc is 0
    acc = 0x00;
    //select bank 11 => bank 3 of R6
    psw = 3 << 3;
    //assign replacement value
    r(6) = 0x6b;
    //code ouput test
    TEST_ASSERT_EQUAL(0x6b, r(6));
    TEST_ASSERT_EQUAL(0x5a, ram[0x06]);
    TEST_ASSERT_EQUAL(0x3d, ram[0x0e]);
    TEST_ASSERT_EQUAL(0x62, ram[0x16]);
    TEST_ASSERT_EQUAL(0x6b, ram[0x1e]);
}

/*------------------------OPERAND TEST---------------------------*/

// MOV A,R3
void test_MOV_A_R3_given_R3_value_25H_expect_value_R3_25H_mov_to_A(void)
{ 
  //setup test fixture
  uint8_t machineCode[] = {0xeb};
  //setup acc to 0
  acc = 0;
  //setup test
  ram[0x13] = 0x25;     
  //set psw 10 (Bank2) bits of D4 & D3 shift left 3 times
  psw = 2 << 3;               
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0100);
  //run code under test
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL(0x25, ram[0x13]); 
  TEST_ASSERT_EQUAL(0x25, acc);
  TEST_ASSERT_EQUAL_PTR(0x0100 + 1, pc);    
}

// MOV A,0FH
void test_MOV_0FH_A_given_0FH_value_1CH_expect_value_of_location_0FH_mov_to_A(void)
{
  //setup test fixture
  uint8_t machineCode[] = {0xe5,0x0f};
  //setup acc to 0
  acc = 0;
  //setup ram 
  ram[0x0f] = 0x1c;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0102);
  //run code under test 
  executeInstruction();
  //code output test 
  TEST_ASSERT_EQUAL(0x1c, ram[0x0f]);
  TEST_ASSERT_EQUAL(0x1c, acc);
  TEST_ASSERT_EQUAL_PTR(0x0102 + 2, pc);
}

// MOV A,@R1
void test_MOV_addressR1_A_given_addressR1_value_21H_expect_value_of_addressR1_mov_to_A(void)
{ 
  //setup test fixture
  uint8_t machineCode[] = {0xe7}; 
  //setup acc to 0
  acc = 0;  
  //assign val 0x21(33) to RAM location
  ram[0x89] = 0x21;
  sfr[0x89] = 0;
  //set psw 01 (Bank1) bits of D4 & D3 shift left 3 times
  psw = 1 << 3;       
  //test setup calling the address 
  r(1) = 0x89;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0103);
  //run code under test
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL(0x21, acc);
  TEST_ASSERT_EQUAL(0x89, r(1));
  TEST_ASSERT_EQUAL_PTR(0x0103 + 1, pc);   
}

// MOV A,#22H
void test_MOV_hash22H_A_given_data_hash22H_expect_hash22_mov_to_A(void)
{ 
  //test setup fixture
  uint8_t machineCode[] = {0x74, 0x22};
  //setup acc to 0
  acc = 0;        
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0104);
  //run code under test
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL(0x22, acc);              
  TEST_ASSERT_EQUAL_PTR(0x0104 + 2, pc);     
}

// MOV R3,A
void test_MOV_A_R3_given_A_value_99H_expect_value_of_A_mov_to_R3(void)
{ 
  //test setup fixture
  uint8_t machineCode[] = {0xfb};
  //setup acc a value
  acc = 0x99;
  //set psw 10 (Bank2) bits D4 & D3 shift left 3 times
  psw = 2 << 3;
  //assign acc to R3 of bank 2
  ram[0x13] = 0;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0105);
  //run code under test
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL(0x99, ram[0x13]);    
  TEST_ASSERT_EQUAL(0x99, acc);              
  TEST_ASSERT_EQUAL_PTR(0x0105 + 1, pc);  
}

// MOV R4,04H 
void test_MOV_04H_R4_given_04H_value_44H_expect_value_of_location_04H_mov_to_R4(void)
{ 
  //test setup fixture
  uint8_t machineCode[] = {0xac,0x04};
  //setup acc to 0 
  acc = 0;
  //set psw 01 (Bank1) bits D4 & D3 shift left 3 times 
  psw = 1 << 3;
  //assign acc to R3 of bank 2
  ram[0x0c] = 0;
  //assign address 04H value 44H
  ram[0x04] = 0x44;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0106);
  //run code under test
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL(0x44, ram[0x0c]);        
  TEST_ASSERT_EQUAL(0, acc);              
  TEST_ASSERT_EQUAL_PTR(0x0106 + 2, pc);     
}

// MOV R6,#77H
void test_MOV_hash77H_R6_given_data_hash77H_expect_data_mov_to_R6(void)
{ 
  //test setup fixture
  uint8_t machineCode[] = {0x7e,0x77};
  //setup acc to 0
  acc = 0;
  //set psw 10 (Bank2) bits D4 & D3 shift left 3 times
  psw = 2 << 3;
  //assign acc to R3 of bank 2
  ram[0x16] = 0;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0107);
  //run code under test
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL(0x77, ram[0x16]);        
  TEST_ASSERT_EQUAL(0, acc);              
  TEST_ASSERT_EQUAL_PTR(0x0107 + 2, pc);    
}

// MOV 12H,A 
void test_MOV_12H_A_given_A_value_54H_expect_value_of_A_mov_to_location_12H(void)
{ 
  //test setup fixture
  uint8_t machineCode[] = {0xf5,0x12};
  //setup acc a value
  acc = 0x54;
  //setup ram location
  ram[0x12] = 0;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0108);
  //run  code under test 
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL(0x54, acc);
  TEST_ASSERT_EQUAL(0x54, ram[0x12]);
  TEST_ASSERT_EQUAL_PTR(0x0108 + 2, pc);
}

// MOV 11H, R5
void test_MOV_11H_R5_given_R5_value_66H_expect_value_of_R5_mov_to_location_11H(void)
{
  //test setup fixture 
  uint8_t machineCode[] = {0x8d,0x11};
  //setup acc to 0 
  acc = 0;
  //set psw 01 (Bank1) bits D4 & D3 shift left 3 times
  psw = 1 << 3;
  //assign value in R5
  ram[0x0d] = 0x66;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0109);
  //run code under test 
  executeInstruction();
  //code output test 
  TEST_ASSERT_EQUAL(0, acc);
  TEST_ASSERT_EQUAL(0x66, ram[0x0d]);
  TEST_ASSERT_EQUAL(0x66, ram[0x11]);
  TEST_ASSERT_EQUAL_PTR(0x0109 + 2, pc);
}

// MOV 18H,1AH
void test_MOV_18H_1AH_given_1AH_value_56H_expect_value_of_location_1AH_mov_to_location_18H(void)
{
  //test setup fixture 
  uint8_t machineCode[] = {0x85, 0x1a, 0x18};
  //setup acc to 0 
  acc = 0;
  //setup data into location 1AH
  ram[0x1a] = 0x56;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0110);
  //run code under test 
  executeInstruction();
  //code output test 
  TEST_ASSERT_EQUAL(0, acc);
  TEST_ASSERT_EQUAL(0x56, ram[0x18]);
  TEST_ASSERT_EQUAL_PTR(0x0110 + 2, pc);  
}

// MOV 1BH,@R1
void test_MOV_1BH_addressR1_given_addressR1_value_22H_expect_value_of_addressR1_mov_to_location_1BH(void)
{
  //setup test fixture
  uint8_t machineCode[] = {0x87,0x1b}; 
  //setup acc to 0
  acc = 0;  
  //assign value 0x22(34) to RAM location
  ram[0x87] = 0x22;
  sfr[0x87] = 0;
  //set psw 01 (Bank1) bits D4 & D3 shift left 3 times
  psw = 1 << 3;        
  //test setup calling the address 
  r(1) = 0x87;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0111);
  //run code under test
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL(0, acc);
  TEST_ASSERT_EQUAL(0x87, r(1));
  TEST_ASSERT_EQUAL_PTR(0x0111 + 2, pc);   
}

// MOV 10H,#91H
void test_MOV_10H_hash91H_given_data_hash91_expect_data_mov_to_location_10H(void)
{
  //test setup fixture 
  uint8_t machineCode[] = {0x75, 0x10, 0x91};
  //setup acc to 0 
  acc = 0;
  //setup data into location 1AH
  ram[0x10] = 0x91;
  //copy codeMemory 
  copyCodeToCodeMemory(machineCode, pc = 0x0112);
  //run code under test 
  executeInstruction();
  //code output test 
  TEST_ASSERT_EQUAL(0, acc);
  TEST_ASSERT_EQUAL(0x91, ram[0x10]);
  TEST_ASSERT_EQUAL_PTR(0x0112 + 2, pc); 
}

// MOV @R1,A
void test_MOV_addressR1_A_given_A_value_77H_expect_value_of_A_mov_to_addressR1(void)
{
  //setup test fixture
  uint8_t machineCode[] = {0xf7}; 
  //setup acc a value
  acc = 0x77;  
  //RAM location
  ram[0x91] = 0;
  sfr[0x91] = 0;
  //set psw 00 (Bank0) bits D4 & D3 shift left 3 times
  psw = 0 << 3;        
  //test setup calling the address 
  r(1) = 0x91;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0113);
  //run code under test
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL(0x77, acc);
  TEST_ASSERT_EQUAL(0x91, r(1));
  TEST_ASSERT_EQUAL_PTR(0x0113 + 1, pc);   
}

// MOV @R1,1FH
void test_MOV_addressR1_1FH_given_1FH_value_78H_expect_value_of_location_1FH_mov_to_addressR1(void)
{
  //setup test fixture
  uint8_t machineCode[] = {0xa7, 0x1f}; 
  //setup acc to 0
  acc = 0;  
  //assign value to location 1FH
  ram[0x1f] = 0x78;
  //RAM location
  ram[0x85] = 0;
  sfr[0x85] = 0;
  //set psw 00 (Bank0) bits D4 & D3 shift left 3 times
  psw = 0 << 3;        
  //test setup calling the address 
  r(1) = 0x85;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0114);
  //run code under test
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL(0, acc);
  TEST_ASSERT_EQUAL(0x85, r(1));
  TEST_ASSERT_EQUAL_PTR(0x0114 + 2, pc);   
}

// MOV @R1,#66H
void test_MOV_addressR1_hash66H_given_data_hash66H_expect_data_mov_to_addressR1(void)
{
  //setup test fixture
  uint8_t machineCode[] = {0x77, 0x66}; 
  //setup acc to 0
  acc = 0;  
  //RAM location
  ram[0x9b] = 0;
  sfr[0x9b] = 0;
  //set psw 00 (Bank0) bits D4 & D3 shift left 3 times
  psw = 0 << 3;        
  //test setup calling the address 
  r(1) = 0x9b;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0115);
  //run code under test
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL(0, acc);
  TEST_ASSERT_EQUAL(0x9b, r(1));
  TEST_ASSERT_EQUAL_PTR(0x0115 + 2, pc);   
}
// MOV DPTR, #1234H
void test_MOV_DPTR_hash1234H_given_data_hash1234H_expect_data_mov_to_DPTR_DH_hold_12H_and_DPL_hold_34H(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x90, 0x12, 0x34};
  //setup acc to 0 
  acc = 0;
  //setup DPH and DPL to 0 
  DPH = 0;
  DPL = 0;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0116);
  //run code under test 
  executeInstruction();
  //code output test 
  TEST_ASSERT_EQUAL_INT8(0x12, DPH);
  TEST_ASSERT_EQUAL_INT8(0x34, DPL);
  TEST_ASSERT_EQUAL_PTR(0, acc);
  TEST_ASSERT_EQUAL_PTR(0x0116 + 3, pc);
}

// MOVX A,@R1 
void test_MOVX_A_addressR1_given_addressR1_value_76H_expect_value_addressR1_external_RAM_mov_to_A(void)
{
  //setup test fixture
  uint8_t machineCode[] = {0xe3}; 
  //setup acc to 0
  acc = 0;  
  //assign value to XRAM location
  xram[0x99] = 0x76;
  ram[0x99] = 0;
  sfr[0x99] = 0;
  //set psw 01 (Bank1) bits of D4 & D3 shift left 3 times
  psw = 1 << 3;       
  //test setup calling the address 
  xr(1) = 0x99;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0117);
  //run code under test
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL_HEX8(0x76, acc);
  TEST_ASSERT_EQUAL(0x99, xr(1));
  TEST_ASSERT_EQUAL_PTR(0x0117 + 1, pc);
}

// INC R6
void test_INC_R6_given_R6_value_45H_expect_value_of_R6_plus1_to_46H(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x0e};
  //setup acc to 0 
  acc = 0;
  //set psw 11 (Bank3) bits D4 & D3 shift left 3 times
  psw = 3 << 3;
  //R6
  ram[0x1e] = 0x45;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0301);
  //run code under test 
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL(0, acc);
  TEST_ASSERT_EQUAL(0x46, ram[0x1e]);
  TEST_ASSERT_EQUAL_PTR(0x0301 + 1, pc);
}

// INC 17H
void test_INC_17H_given_17H_value_54H_expect_value_of_location_17H_plus1_to_55H(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x05, 0x17};
  //setup acc to 0
  acc = 0;
  //set up direct ram 
  ram[0x17] = 0x54;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0302);
  //run code under test 
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL(0, acc);
  TEST_ASSERT_EQUAL(0x55, ram[0x17]);
  TEST_ASSERT_EQUAL_PTR(0x0302 + 2, pc);
}

// INC @R1
void test_INC_addressR1_given_addressR1_value_67H_expect_value_of_addressR1_plus1_to_68H(void)
{
  //setup test fixture
   uint8_t machineCode[] = {0x07}; //@R1
  //set acc to 0
  acc = 0;  
  //RAM location
  ram[0x88] = 0x67;
  sfr[0x88] = 0;
  //set psw 01 (Bank1) bit to 4&3
  psw = 1 << 3;        
  //test setup calling the address 
  r(1) = 0x88;
  //codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0303);
  //run code under test
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL(0, acc);
  TEST_ASSERT_EQUAL(0x88, r(1));
  TEST_ASSERT_EQUAL_PTR(0x0303 + 1, pc); 
}

// DEC A
void test_DEC_A_given_A_value_65H_expect_value_of_A_MINUS1_to_64H(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x14};
  //setup acc a value
  acc = 0x65;
  //copy codeMemory 
  copyCodeToCodeMemory(machineCode, pc = 0x0304);
  //run code under test 
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL_HEX8(0x64, acc);
  TEST_ASSERT_EQUAL_PTR(0x304 + 1, pc);
}

// DEC R5
void test_DEC_R5_given_R5_value_55H_expect_value_of_R5_MINUS1_to_54H(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x1d};
  //setup acc to 0
  acc = 0;
  //set psw 10 (Bank2) bits D4 & D3 shift left 3 times 
  psw = 2 << 3;
  //R5
  ram[0x15] = 0x55;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0305);
  //run code under test 
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL_HEX8(0x54, ram[0x15]);
  TEST_ASSERT_EQUAL_PTR(0x0305 + 1, pc);
}

// DEC 16H
void test_INC_16H_given_16H_value_44H_expect_value_of_location_16H_MINUS1_to_43H(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x15, 0x16};
  //setup acc to 0
  acc = 0;
  //set up direct ram 
  ram[0x16] = 0x44;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0306);
  //run code under test 
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL_HEX8(0x43, ram[0x16]);
  TEST_ASSERT_EQUAL_PTR(0x0306 + 2, pc);
}

// DEC @R1
void test_DEC_addressR1_given_addressR1_value_72H_expect_value_of_addressR1_MINUS1_to_76H(void)
{
  //setup test fixture
   uint8_t machineCode[] = {0x17}; //@R1
  //setup acc to 0
  acc = 0;  
  //RAM location
  ram[0x91] = 0x72;
  sfr[0x91] = 0;
  //set psw 01 (Bank1) bits D4 & D3 shift left 3 times
  psw = 2 << 3;        
  //test setup calling the address 
  r(1) = 0x91;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0307);
  //run code under test
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL_HEX8(0x91, r(1));
  TEST_ASSERT_EQUAL_PTR(0x0307 + 1, pc); 
}

// CLR A
void test_CLR_A_given_A_value_22H_expect_value_of_A_is_clear(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0xe4};
  //setup acc a value
  acc = 0x22;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0200);
  //run code under test 
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL(0x00, acc);
  TEST_ASSERT_EQUAL_PTR(0x0200 + 1, pc);
}

// NOP
void test_NOP_to_perform_a_skip(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x00};
  //setup acc value to 0
  acc = 0;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0201);
  //run code under test
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL(0, acc);
  TEST_ASSERT_EQUAL_PTR(0x0201 + 1, pc);
}

// SWAP A 
void test_SWAP_A_given_A_value_6BH_expect_value_of_A_swap_to_B6H_to_A(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0xc4};
  //setup acc a value
  acc = 0x6b;
  //copy codeMemory 
  copyCodeToCodeMemory(machineCode, pc = 0x0202);
  //run code under test 
  executeInstruction();
  //code output test 
  TEST_ASSERT_EQUAL(0xb6, acc);
  TEST_ASSERT_EQUAL_PTR(0x0202 + 1, pc);    
}

/*
 acc = 22H => 0010 0011
 complement acc (~1)
        0010 0011
               ~1
     -------------
        1101 1100
 acc = DCH => 1101 1100 
*/
// CPL A 
void test_CPL_A_given_A_value_23H_expect_value_of_A_compliment_to_DCH(void) 
{
  //test setup fixture
  uint8_t machineCode[] = {0xf4};
  //setup acc a value
  acc = 0x23;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0203);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL(0xdc, acc);
  TEST_ASSERT_EQUAL_PTR(0x0203 + 1, pc);
}

// RL A 
void test_RL_A_given_A_value_E6H_expect_value_A_rotate_left_73H(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x23};
  //setup acc a value
  acc = 0xe6;
  //setup CY to 0 
  status.CY = 0;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0204);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL(0xcd, acc);
  TEST_ASSERT_EQUAL(0, status.CY);
  TEST_ASSERT_EQUAL_PTR(0x0204 + 1, pc);  
}

// RLC A 
void test_RLC_A_given_A_value_E6H_expect_value_A_rotate_left_B9H_with_carry_set(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x33};
  //setup acc a value
  acc = 0xe6;
  //setup of CY to 0 
  status.CY = 0;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0206);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL(0xcc, acc);
  TEST_ASSERT_EQUAL(1, status.CY);
  TEST_ASSERT_EQUAL_PTR(0x0206 + 1, pc);  
}

// RLC A
void test_RLC_A_given_A_value_F4H_expect_value_A_rotate_left_E9H_with_carry_set(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x33};
  //setup acc a value
  acc = 0xf4;
  //setup of CY to 1 
  status.CY = 1;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0207);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL(0xe9, acc);
  TEST_ASSERT_EQUAL(1, status.CY);
  TEST_ASSERT_EQUAL_PTR(0x0207 + 1, pc);  
}

// RR A 
void test_RR_A_given_A_value_59H_expect_value_A_rotate_right_ACH(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x03};
  //setup acc a value
  acc = 0x59;
  //setup CY to 0 
  status.CY = 0;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0205);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL(0xac, acc);
  TEST_ASSERT_EQUAL(0, status.CY);
  TEST_ASSERT_EQUAL_PTR(0x0205 + 1, pc); 
}

// RRC A 
void test_RRC_A_given_A_value_D6H_expect_value_A_rotate_right_6BH_with_carry_set(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x13};
  //setup acc a value
  acc = 0xd6;
  //setup of CY to 0 
  status.CY = 0;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0208);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL(0x6b, acc);
  TEST_ASSERT_EQUAL(0, status.CY);
  TEST_ASSERT_EQUAL_PTR(0x0208 + 1, pc); 
}

// RRC A
void test_RRC_A_given_A_value_C4H_expect_value_A_rotate_right_H_with_carry_set(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x13};
  //setup acc a value
  acc = 0xC4;
  //setup of CY to 1 
  status.CY = 1;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0209);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL(0xe2, acc);
  TEST_ASSERT_EQUAL(0, status.CY);
  TEST_ASSERT_EQUAL_PTR(0x0209 + 1, pc); 
}

// MUL AB 
// A = 54H, B = A3H
// A * B = 357CH
void test_MUL_A_B_given_A_value_54H_and_B_value_A3H_expect_values_A_multiply_B_product_357CH(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0xa4};
  //setup acc a value
  acc = 0x54;
  //setup B a value
  B = 0xa3;
  //setup CY to 1 
  status.CY = 1;
  //setup OV to 0 
  status.OV = 0;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0210);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_INT8(0x7c, acc);
  TEST_ASSERT_EQUAL_INT8(0x35, B);
  TEST_ASSERT_EQUAL(0, status.CY);
  TEST_ASSERT_EQUAL(1, status.OV);
  TEST_ASSERT_EQUAL_PTR(0x0210 + 1, pc);
}

// DIV AB 
// A = FBH, B = 12H
// A / B = 0D11H
void test_DIV_AB_given_A_value_FBH_and_B_value_12H_expect_values_A_divide_B_product_result_0D11H(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x84};
  //setup acc a value 
  acc = 0xfb;
  //setup B a value 
  B = 0x12;
  //setup CY to 1 
  status.CY = 1;
  //setup OV to 1 
  status.OV = 1;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0211);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_HEX8(0x0d, acc);
  TEST_ASSERT_EQUAL_HEX8(0x11, B);
  TEST_ASSERT_EQUAL(0, status.CY);
  TEST_ASSERT_EQUAL(0, status.OV);
  TEST_ASSERT_EQUAL_PTR(0x0211 + 1, pc);
}

// XRL A,R2
void test_XRL_A_R2_given_R2_value_15H_and_A_value_24H_expect_value_of_R2_XOR_A(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x6a};
  //setup acc a value
  acc = 0x24;
  //set R2 10 (Bank2) bits D4 & D3 shift left 3 times
  psw = 2 << 3;
  //assign value in R2 
  ram[0x12] = 0x15;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0001);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL(0x31, acc);
  TEST_ASSERT_EQUAL_PTR(0x0001 + 1, pc);
}

// XRL A,12H
void test_XRL_A_12H_given_12H_value_15H_and_A_value_24H_expect_values_of_location_12H_XOR_A(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x65, 0x12};
  //setup acc a value
  acc = 0x24;
  //assign value in R2 
  ram[0x12] = 0x15;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0002);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL(0x31, acc);
  TEST_ASSERT_EQUAL_PTR(0x0002 + 2, pc);
}

// XRL A,#15H
void test_XRL_A_hash15H_given_A_value_0x24_expect_value_of_A_XOR_hash15H(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x64, 0x15};
  //setup acc a value
  acc = 0x24;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0003);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL(0x31, acc);
  TEST_ASSERT_EQUAL_PTR(0x0003 + 2, pc);
}

// XRL A,@R0
void test_XRL_A_addressR0_given_A_value_24H_and_addressR0_value_15H_expect_values_of_addressR0_XOR_A(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x66};
  //setup acc a value
  acc = 0x24;
  //RAM location 
  ram[0xd6] = 0x15;
  sfr[0xd6] = 0;
  //set R0 10 (Bank2) bits D4 & D3 shift left 3 times
  psw = 2 << 3;
  //test setup calling the address 
  r(0) = 0xd6;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0004);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_INT8(0x31, acc);
  TEST_ASSERT_EQUAL(0xd6, r(0));
  TEST_ASSERT_EQUAL_PTR(0x0004 + 1, pc);
}

// XRL 14H,A 
void test_XRL_14H_A_given_A_value_15H_and_location_14H_value_24H_expect_values_A_XOR_location_14H(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x62, 0x14};
  //setup acc a value
  acc = 0x15;
  //assign value to location 14H
  ram[0x14] = 0x24;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0005);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL(0x15, acc);
  TEST_ASSERT_EQUAL(0x31, ram[0x14]);
  TEST_ASSERT_EQUAL_PTR(0x0005 + 2, pc); 
}

// XRL 13H,#15H
void test_XRL_13H_hash15H_given_13H_value_24H_expect_value_of_location_13H_XOR_hash15H(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x63,0x13,0x15};
  //setup acc to 0
  acc = 0;
  //setup a value to location 13H
  ram[0x13] = 0x24;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0006);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL(0x31, ram[0x13]);
  TEST_ASSERT_EQUAL_PTR(0x0006 + 3, pc);
}

// ADD A,R3 
void test_ADD_A_R3_given_R3_value_4_and_A_value_126_expect_value_R3_add_A_equal_plus130(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x2b};
  //setup acc a value
  acc = 126;
  //set R2 10 (Bank2) bits D4 & D3 shift left 3 times
  psw = 2 << 3;
  //set OV to 0 
  status.OV = 0;
  //assign a value to R3
  ram[0x13] = 4;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0500);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_INT8(130, acc);      
  TEST_ASSERT_EQUAL(1, status.OV);
  TEST_ASSERT_EQUAL_PTR(0x0500 + 1, pc);
}

// ADD A,14H 
void test_ADD_A_14H_given_A_value_plus126_and_14H_plus1_expect_value_of_location_14H_value_add_A_equal_plus127(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x25, 0x14};
  //setup acc a value
  acc = 126;
  //set OV to 0 
  status.OV = 1;
  //setup ram location a value
  ram[0x14] = 1;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0501);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_INT8(127, acc);      
  TEST_ASSERT_EQUAL(0, status.OV);
  TEST_ASSERT_EQUAL_PTR(0x0501 + 2, pc);
}

// ADD A,85
void test_ADD_A_given_data_plus85_and_A_plus126_expect_data_add_A_equal_plus211(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x24, 85};
  //setup acc a value
  acc = 126;
  //set OV to 0 
  status.OV = 0;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0502);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_INT8(211, acc);      
  TEST_ASSERT_EQUAL(1, status.OV);
  TEST_ASSERT_EQUAL_PTR(0x0502 + 2, pc);
}

// ADD A,@R0
void test_ADD_A_addressR0_given_addressR0_value_plus34_and_A_plus55_expect_addressR0_add_A_equal_89(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x26};
  //setup acc a value
  acc = 55;
  //set OV to 1
  status.OV = 1;
  //RAM location 
  ram[0xd4] = 34;
  sfr[0xd4] = 0;
  //set R0 10 (Bank2) bits D4 & D3 shift left 3 times
  psw = 2 << 3;
  //test setup calling the address 
  r(0) = 0xd4;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0503);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_INT8(89, acc);
  TEST_ASSERT_EQUAL(0, status.OV);
  TEST_ASSERT_EQUAL(0xd4, r(0));
  TEST_ASSERT_EQUAL_PTR(0x503 + 1, pc);
}

// ADDC A,R4
void test_ADDC_A_R4_given_A_value_C3H_R4_value_AAH_expect_values_A_plus_R4_where_CY_and_OV_set_1_AC_0_result_6EH_CY_1_OV_1_AC_0(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x3c};
  //setup acc a value
  acc = 0xc3;
  //setup CY to 1
  status.CY = 1;
  //setup OV to 0 
  status.OV = 0;
  //setup AC t0 0 
  status.AC = 0;
  //set R4 10 (Bank2) bits D4 & D3 shift left 3 times
  psw = 2 << 3;
  //assign a value to R4
  ram[0x14] = 0xaa;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0509);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_HEX8(0x6e, acc);
  TEST_ASSERT_EQUAL(0, status.AC);
  TEST_ASSERT_EQUAL(1, status.OV);
  TEST_ASSERT_EQUAL(1, status.CY);
  TEST_ASSERT_EQUAL_PTR(0x0509 + 1, pc); 
}

// ADDC A,R4
void test_ADDC_A_R4_given_A_value_55H_R4_value_2H_expect_values_A_plus_R4_where_CY_0_AC_0_OV_0_result_57H(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x3c};
  //setup acc a value
  acc = 0x55;
  //setup CY 
  status.CY = 0;
  //setup OV 
  status.OV = 0;
  //setup AC  
  status.AC = 0;
  //set R4 10 (Bank2) bits D4 & D3 shift left 3 times
  psw = 2 << 3;
  //assign a value to R4
  ram[0x14] = 0x02;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0510);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_HEX8(0x57, acc);
  TEST_ASSERT_EQUAL(0, status.AC);
  TEST_ASSERT_EQUAL(0, status.OV);
  TEST_ASSERT_EQUAL(0, status.CY);
  TEST_ASSERT_EQUAL_PTR(0x0510 + 1, pc); 
}

// ADDC A,11H 
void test_ADDC_A_11H_given_location11H_value_B2H_and_A_value_DDH_expect_values_A_plus_location11H_CY_1_OV_0_AC_0_result_90H_CY_1(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x35, 0x11};
  //setup acc a value
  acc = 0xdd;
  //setup RAM location 
  ram[0x11] = 0xb2;
  //setup CY 
  status.CY = 1;
  //setup OV
  status.OV = 0;
  //setup AC 
  status.AC = 0;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0511);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_HEX8(0x90, acc);
  TEST_ASSERT_EQUAL(0, status.AC);
  TEST_ASSERT_EQUAL(0, status.OV);
  TEST_ASSERT_EQUAL(1, status.CY);
  TEST_ASSERT_EQUAL_PTR(0x0511 + 2, pc);  
}

// ADDC A, #CCH
void test_ADDC_A_hashCCH_given_A_value_77H_expect_values_A_plus_hashCCH_CY_1_OV_0_AC_0_result_44H_CY_1_AC_1(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x34, 0xcc};
  //setup acc a value
  acc = 0x77;
  //setup CY 
  status.CY = 1;
  //setup OV
  status.OV = 0;
  //setup AC 
  status.AC = 0;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0512);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_HEX8(0x44, acc);
  TEST_ASSERT_EQUAL(1, status.AC);
  TEST_ASSERT_EQUAL(0, status.OV);
  TEST_ASSERT_EQUAL(1, status.CY);
  TEST_ASSERT_EQUAL_PTR(0x0512 + 2, pc);
}

// ADDC A,@R1 
void test_ADDC_A_addressR1_given_addressR1_value_ADH_and_A_value_89H_expect_values_addressR1_plus_A_CY_1_OV_0_AC_0_result_37H_CY_1_OV_1_AC_1(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x37};
  //setup acc a value
  acc = 0x89;
  //RAM location 
  ram[0xa5] = 0xad;
  sfr[0xa5] = 0;
  //setup CY
  status.CY = 1;
  //setup OV
  status.OV = 0;
  //setup AC 
  status.AC = 0;
  //set R1 10 (Bank2) bits D4 & D3 shift left 3 times
  psw = 2 << 3;
  //test setup calling the address 
  r(1) = 0xa5;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0513);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_HEX8(0x37, acc);
  TEST_ASSERT_EQUAL(1, status.AC);
  TEST_ASSERT_EQUAL(1, status.OV);
  TEST_ASSERT_EQUAL(1, status.CY);
  TEST_ASSERT_EQUAL(0xa5, r(1));
  TEST_ASSERT_EQUAL_PTR(0x513 + 1, pc); 
}


/* A = -127-0-(-3) = -124
// 127 => 0111 1111
//        1000 0000
//               +1
//-----------------
//        1000 0001  
// 3 => 0000 0011
//      1111 1100
//             +1
//---------------
//      1111 1101 
// 
//      1000 0001
//    - 1111 1101
//---------------
//      1000 0100 
//      0111 1011
//             +1
//----------------
//      0111 1111
*/
// SUBB A, R2 
void test_SUBB_A_R2_given_R2_value_minus3_and_A_value_minus127_and_CY_0_expect_value_A_minus_CY_minus_R2_new_value_A_minus124(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x9a};
  //setup acc a value
  acc = -127;
  //set R2 10 (Bank2) bits D4 & D3 shift left 3 times
  psw = 2 << 3;
  //set CY to 0 
  status.CY = 0;
  //set OV to 1 
  status.OV = 1;
  //assign value to R3 4H = 4
  ram[0x12] = -3;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0504);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_INT8(-124, acc);      
  TEST_ASSERT_EQUAL(0, status.OV);
  TEST_ASSERT_EQUAL(1, status.CY);
  TEST_ASSERT_EQUAL_PTR(0x0504 + 1, pc);
}

// A = -110-(1+41) = -151
/* 110 => 0110 1110
     1's  1001 0001
        +         1 (2's)
      -------------
          1001 0010
*/
// SUBB A, R3 
void test_SUBB_A_R2_given_R3_value_40_and_A_value_minus110_and_CY_1_expect_value_A_minus_CY_minus_R3_new_value_A_minus151(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x9b};
  //assign value to acc
  acc = -110;
  //set R3 10 (Bank2) bits D4 & D3 shift left 3 times
  psw = 2 << 3;
  //CY is 1
  status.CY = 1;
  //set OV to 0 
  status.OV = 0;
  //assign value to R3 4H = 4
  ram[0x13] = 40;
  //copy codeMemory 
  copyCodeToCodeMemory(machineCode, pc = 0x0505);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_INT8(-151, acc);      
  TEST_ASSERT_EQUAL(1, status.OV);
  TEST_ASSERT_EQUAL(0, status.CY);
  TEST_ASSERT_EQUAL_PTR(0x0505 + 1, pc);
}

// SUBB A,15H  
void test_SUBB_A_15H_given_15H_value_plus30_and_A_value_minus90_and_CY_1_expect_values_A_minus_CY_minus_location_15H_new_value_A_minus121(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x95, 0x15};
  //setup acc a value
  acc = -90;
  //set CY to 1
  status.CY = 1;
  //set OV to 0 
  status.OV = 1;
  //assign value location 15H
  ram[0x15] = 30;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0506);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_INT8(-121, acc);      
  TEST_ASSERT_EQUAL(0, status.OV);
  TEST_ASSERT_EQUAL(0, status.CY);
  TEST_ASSERT_EQUAL_PTR(0x0506 + 2, pc);
}

// SUBB A,21
void test_SUBB_A_21_given_A_value_plus119_and_CY_1_expect_value_of_A_minus_CY_1_minus_21_new_value_A_plus97(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x94, 21};
  //setup acc a value
  acc = 119;
  //set CY to 1
  status.CY = 1;
  //set OV to 0 
  status.OV = 1;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0507);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_INT8(97, acc);      
  TEST_ASSERT_EQUAL(0, status.OV);
  TEST_ASSERT_EQUAL(0, status.CY);
  TEST_ASSERT_EQUAL_PTR(0x0507 + 2, pc);
}

// SUBB A,@R0 
void test_SUBB_A_addressR0_given_addressR0_value_plus126_and_A_value_minus40_CY_1_expect_value_of_A_minus_CY_1_minus_addressR0_new_value_minus167(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x96};
  //setup acc a value
  acc = -40;
  //set CY to 1
  status.CY = 1;
  //set OV to 0
  status.OV = 0;
  //RAM location 
  ram[0xd5] = 126;
  sfr[0xd5] = 0;
  //set R0 10 (Bank2) bits D4 & D3 shift left 3 times
  psw = 2 << 3;
  //test setup calling the address 
  r(0) = 0xd5;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0508);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL(1, status.OV);
  TEST_ASSERT_EQUAL(0, status.CY);
  TEST_ASSERT_EQUAL(0xd5, r(0));
  TEST_ASSERT_EQUAL_PTR(0x508 + 1, pc);
}

// ANL A,R3
void test_ANL_A_R3_given_R3_55H_and_A_C3H_expect_values_R3_logicalAND_A(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x5b};
  //assign acc a value 
  acc = 0xc3;
  //set R3 10(bank2) bitwise D3 & D4 
  psw = 2 << 3;
  //assign value in R2 
  ram[0x13] = 0x55;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0600);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_HEX8(0x41, acc);
  TEST_ASSERT_EQUAL_PTR(0x0600 + 1, pc);
}

// ANL A,14H
void test_ANL_A_14H_given_A_4FH_and_location_14H_value_62H_expect_values_location_14H_logicalAND_A(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x55, 0x14};
  //assign acc a value 
  acc = 0x4f;
  //assign value to location 14H
  ram[0x14] = 0x62;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0601);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_HEX8(0x42, acc);
  TEST_ASSERT_EQUAL_PTR(0x0601 + 2, pc);
}

// ANL A,#55H
void test_ANL_A_hash3AH_given_data_hash3AH_and_A_value_C3H_expect_values_hash3AH_logicalAND_A(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x54, 0x3a};
  //assign acc a value 
  acc = 0x6e;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0602);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_HEX8(0x2a, acc);
  TEST_ASSERT_EQUAL_PTR(0x0602 + 2, pc);
}

// ANL A,@R0
void test_ANL_A_addressR0_given_addressR0_value_63H_and_A_value_21H_expect_values_of_addressR0_logicalAND_A(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x56};
  //setup acc a value
  acc = 0x21;
  //RAM location 
  ram[0xe4] = 0x63;
  sfr[0xe4] = 0;
  //set R0 10 (Bank2) bits D4 & D3 shift left 3 times
  psw = 2 << 3;
  //test setup calling the address 
  r(0) = 0xe4;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0603);
  //run code under test 
  executeInstruction();
  //code test output
  TEST_ASSERT_EQUAL_HEX8(0x21,acc);
  TEST_ASSERT_EQUAL(0xe4, r(0));
  TEST_ASSERT_EQUAL_PTR(0x603 + 1, pc);
}
// ANL 1CH,A
void test_1CH_A_given_A_value_65H_and_location_1CH_79H_expect_values_A_logicalAND_location_1CH(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x52, 0x1c};
  //setup acc a value 
  acc = 0x65;
  //assign value to location 1CH
  ram[0x1c] = 0x79;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0604);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_HEX8(0x61, ram[0x1c]);
  TEST_ASSERT_EQUAL_PTR(0x0604 + 2, pc);
}

// ANL 1DH,#C3H
void test_1DH_hash55H_given_1DH_value_C3H_expect_hash55H_logicalAND_location_1DH(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x53, 0x1d, 0x63};
  //setup acc to 0 
  acc = 0;
  //assign value to location 1DH 
  ram[0x1d] = 0x21;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0605);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_HEX8(0x21, ram[0x1d]);
  TEST_ASSERT_EQUAL_PTR(0x0605 + 3, pc);
}

// ORL A,R5
void test_ORL_A_R5_given_R5_value_44H_and_A_value_56H_expect_values_R5_logicalOR_A(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x4d};
  //assign acc a value 
  acc = 0x56;
  //set R3 10(bank2) bitwise D3 & D4 
  psw = 2 << 3;
  //assign value in R2 
  ram[0x15] = 0x44;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0700);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_HEX8(0x56, acc);
  TEST_ASSERT_EQUAL_PTR(0x0700 + 1, pc);
}

// ORL A,16H
void test_ORL_A_16H_given_location_16H_value_AAH_and_A_value_74H_expect_values_of_location_16H_logicalOR_A(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x45, 0x16};
  //assign acc a value 
  acc = 0x74;
  //assign value to location 14H
  ram[0x16] = 0xaa;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0701);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_HEX8(0xfe, acc);
  TEST_ASSERT_EQUAL_PTR(0x0701 + 2, pc); 
}

// ORL A,#88H
void test_ORL_A_hash88H_given_A_value_C3H_expect_value_hash88H_logicalOR_A(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x44, 0x88};
  //assign acc a value 
  acc = 0x99;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0702);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_HEX8(0x99, acc);
  TEST_ASSERT_EQUAL_PTR(0x0702 + 2, pc); 
}

// ORL A,@R0
void test_ORL_A_addressR0_given_addressR0_value_55H_and_A_value_27H_expect_values_of_addressR0_logicalOR_A(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x46};
  //setup acc a value
  acc = 0x27;
  //RAM location 
  ram[0xe8] = 0x77;
  sfr[0xe8] = 0;
  //set R0 10 (Bank2) bits D4 & D3 shift left 3 times
  psw = 2 << 3;
  //test setup calling the address 
  r(0) = 0xe8;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0703);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_HEX8(0x77, acc);
  TEST_ASSERT_EQUAL(0xe8, r(0));
  TEST_ASSERT_EQUAL_PTR(0x703 + 1, pc);
}

// ORL 1AH,A
void test_1AH_A_given_A_value_10H_and_location_1AH_5BH_expect_values_A_logicalOR_location_1CH(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x42, 0x1a};
  //setup acc a value 
  acc = 0x10;
  //assign value to location 1CH
  ram[0x1a] = 0x5b;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0704);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_HEX8(0x5b, ram[0x1a]);
  TEST_ASSERT_EQUAL_PTR(0x0704 + 2, pc);
}

// ORL 11H,#FBH
void test_11H_hashFBH_given_location_11H_value_ACH_expect_hashFBH_logicalOR_location_11H(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x43, 0x11, 0xfb};
  //setup acc to 0 
  acc = 0;
  //assign value to location 1DH 
  ram[0x11] = 0xac;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0705);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_HEX8(0xff, ram[0x11]);
  TEST_ASSERT_EQUAL_PTR(0x0705 + 3, pc);
}

// SJMP 70 
void test_SJMP_70_expect_relative_address_jump_to_2003H(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x80, 70};
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x2003);
  //run code under test 
  executeInstruction();
  //code test output
  TEST_ASSERT_EQUAL_UINT16(0x2003 + 70 + 2, pc);
}

// SJMP -60 
void test_SJMP_minus60_expect_relative_address_jump_to_2003H(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x80, -60};
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x2004);
  //run code under test 
  executeInstruction();
  //code test output
  TEST_ASSERT_EQUAL_UINT16(0x2004 + (-60) + 2, pc);
}

// LJMP 1234H
void test_LJMP_1234H_expect_1234H_LJMP_to_location_23H(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x10, 0x12, 0x34};
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x2005);
  //run code under test 
  executeInstruction();
  //code test output
  TEST_ASSERT_EQUAL_UINT16(0x1234,pc);
}

// JZ 10
void test_JZ_10_expect_not_JMP_when_acc_is_not_0(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x60, 10};
  //setup acc a value 
  acc = 0x01;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x2006);
  //run code under test 
  executeInstruction();
  TEST_ASSERT_EQUAL(1, acc);
  TEST_ASSERT_EQUAL_UINT16(0x2006 + 2, pc);
}

// JZ 10
void test_JZ_10_expect_JMP_when_acc_is_0(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x60, 10};
  //setup acc a value 
  acc = 0x00;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x2007);
  //run code under test 
  executeInstruction();
  TEST_ASSERT_EQUAL(0, acc);
  TEST_ASSERT_EQUAL_UINT16(0x2007 + 10 + 2, pc);
}

// JNZ 40
void test_JNZ_40_expect_no_JMP_when_acc_is_not_zero(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x70, 40};
  //setup acc a value 
  acc = 0x00;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x2008);
  //run code under test 
  executeInstruction();
  TEST_ASSERT_EQUAL(0, acc);
  TEST_ASSERT_EQUAL_UINT16(0x2008 + 2, pc);
}

// JNZ 40
void test_JNZ_40_expect_JMP_when_acc_is_not_zero(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x70, 40};
  //setup acc a value 
  acc = 0x23;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x2009);
  //run code under test 
  executeInstruction();
  TEST_ASSERT_EQUAL(0x23, acc);
  TEST_ASSERT_EQUAL_UINT16(0x2009 + 40 + 2, pc);
}

// JNC 30
void test_JNC_30_expect_no_JMP_when_carry_is_set(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x50, 30};
  //setup carry to 1 
  status.CY = 1;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x2010);
  //run code under test 
  executeInstruction();
  TEST_ASSERT_EQUAL(1, status.CY);
  TEST_ASSERT_EQUAL_UINT16(0x2010 + 2, pc);
}

// JNC 30
void test_JNC_30_expect_JMP_when_carry_is_not_set(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x50, 30};
  //setup carry to 1 
  status.CY = 0;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x2011);
  //run code under test 
  executeInstruction();
  TEST_ASSERT_EQUAL(0, status.CY);
  TEST_ASSERT_EQUAL_UINT16(0x2011 + 30 + 2, pc);
}

// JC 44
void test_JNC_44_expect_JMP_when_carry_is_set(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x40, 44};
  //setup carry to 1 
  status.CY = 1;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x2012);
  //run code under test 
  executeInstruction();
  TEST_ASSERT_EQUAL(1, status.CY);
  TEST_ASSERT_EQUAL_UINT16(0x2012 + 44 + 2, pc);
}

// JC 44
void test_JNC_44_expect_not_JMP_when_carry_is_not_set(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x40, 44};
  //setup carry to 1 
  status.CY = 0;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x2012);
  //run code under test 
  executeInstruction();
  TEST_ASSERT_EQUAL(0, status.CY);
  TEST_ASSERT_EQUAL_UINT16(0x2012 + 2, pc);
}

// DA A 
void test_DA_A_given_A_value_34H_and_data_37H_expect_value_A_plus_data_37H_is_71H(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x24,0x37,   // ADD A,#37H
                           0xd4};       // DA A
  //setup acc a value 
  acc = 0x34;
  //setup AC to 0 
  status.AC = 0;
  //setup CY to 0 
  status.CY = 0;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x5000);
  //run code under test 
  executeInstruction();               // ADD A,#37H
  executeInstruction();               // DA A
  //code test output 
  TEST_ASSERT_EQUAL_HEX8(0x71, acc);
  TEST_ASSERT_EQUAL(0, status.AC);
  TEST_ASSERT_EQUAL(0, status.CY);
  TEST_ASSERT_EQUAL_PTR(0x5000 + 3, pc);
}

// DA A 
void test_DA_A_given_A_value_28H_and_data_29H_expect_value_A_plus_data_29H_is_57H(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x24,0x29,   // ADD A,#29H
                           0xd4};       // DA A
  //setup acc a value 
  acc = 0x28;
  //setup AC to 0 
  status.AC = 1;
  //setup CY to 0 
  status.CY = 0;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x5001);
  //run code under test 
  executeInstruction();               // ADD A,#29H
  executeInstruction();               // DA A
  //code test output 
  TEST_ASSERT_EQUAL_HEX8(0x57, acc);
  TEST_ASSERT_EQUAL(1, status.AC);
  TEST_ASSERT_EQUAL(0, status.CY);
  TEST_ASSERT_EQUAL_PTR(0x5001 + 3, pc);
}

// DA A 
void test_DA_A_given_A_value_44H_and_data_64H_expect_value_A_plus_data_64H_is_108H(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x24,0x64,   // ADD A,#44H
                           0xd4};       // DA A
  //setup acc a value 
  acc = 0x44;
  //setup AC to 0 
  status.AC = 0;
  //setup CY to 0 
  status.CY = 1;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x5002);
  //run code under test 
  executeInstruction();               // ADD A,#29H
  executeInstruction();               // DA A
  //code test output 
  TEST_ASSERT_EQUAL_HEX8(0x108, acc);
  TEST_ASSERT_EQUAL(0, status.AC);
  TEST_ASSERT_EQUAL(1, status.CY);
  TEST_ASSERT_EQUAL_PTR(0x5002 + 3, pc);
}

// DA A 
void test_DA_A_given_A_value_49H_and_data_68H_expect_value_A_plus_data_68H_is_117H(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x24,0x68,   // ADD A,#44H
                           0xd4};       // DA A
  //setup acc a value 
  acc = 0x49;
  //setup AC to 0 
  status.AC = 1;
  //setup CY to 0 
  status.CY = 1;
  //copy codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x5003);
  //run code under test 
  executeInstruction();               // ADD A,#29H
  executeInstruction();               // DA A
  //code test output 
  TEST_ASSERT_EQUAL_HEX8(0x117, acc);
  TEST_ASSERT_EQUAL(1, status.AC);
  TEST_ASSERT_EQUAL(1, status.CY);
  TEST_ASSERT_EQUAL_PTR(0x5003 + 3, pc);
}