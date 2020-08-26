#include "unity.h"
#include "I8051Simulator.h"
#include "_testHelper.h"


extern uint8_t ram[];
extern uint8_t sfr[];

void setUp(void){}

void tearDown(void){}

/*---------------------------TEST writeToRam function---------------------------*/
void test_condition_for_address_0xfa_to_DIRECT_ADDRESSING_contains_data_0x76_expect_address_0xfa_points_to_data_0x76_at_SFR_DIRECT_ADDRESSING(void) 
{
  //setup 0xfa bottom RAM address set value is 0
  sfr[0xfa] = 0;
  //call functon to test the mode
  //         address   AccessMode      data
  writeToMemory(0xfa, DIRECT_ADDRESSING, 0x76);
  //code output test
  TEST_ASSERT_EQUAL(0x76, sfr[0xfa]);
  
}
void test_condition_for_address_0x9b_to_INDIRECT_ADDRESSING_contains_data_0x69_expect_address_0x9b_points_to_data_0x69_at_SRAM_INDIRECT_ADDRESSING(void) 
{
  //setup 0x9b bottom RAM address set value is 0
  ram[0x9b] = 0;
  //call functon to test the mode
  //        address   AccessMode      data
  writeToMemory(0x9b, INDIRECT_ADDRESSING, 0x69);
  //code output test
  TEST_ASSERT_EQUAL(0x69, ram[0x9b]);
}
void test_condition_for_address_0x11_to_DIRECT_ADDRESSING_contains_data_0x43_expect_address_0x11_points_to_data_0x43_at_RAM_DIRECT_ADDRESSING(void) 
{
  //setup 0x11 bottom RAM address set value is 0
  ram[0x11] = 0;
  //call functon to test the mode
  //        address   AccessMode      data
  writeToMemory(0x11, DIRECT_ADDRESSING, 0x43);
  //code output test
  TEST_ASSERT_EQUAL(0x43, ram[0x11]);
}
void test_condition_for_address_0x7e_to_INDIRECT_ADDRESSING_contains_data_0x55_expect_address_0x7e_points_to_data_0x55_at_RAM_INDIRECT_ADDRESSING(void) 
{
  //setup 0x7e bottom RAM address set value is 0
  ram[0x7e] = 0;
  //call functon to test the mode
  //        address   AccessMode      data
  writeToMemory(0x7e, DIRECT_ADDRESSING, 0x55);
  //code output test
  TEST_ASSERT_EQUAL(0x55, ram[0x7e]);
}

/*---------------------------TEST readFromRam function------------------------------*/
void test_condition_for_address_0xff_read_mode_DIRECT_ADDRESSING_of_SFR_expect_to_read_address_0xff_from_SFR_DIRECT_ADDRESSING(void)
{
  int dataRead = 0;
  //setup RAM address to be read
  sfr[0xff] = 0x98;
  ram[0xff] = 0;
  //call function to test mode 
  //                    address    AccessMode
  dataRead = readFromMemory(0xff, DIRECT_ADDRESSING);
  //code output test
  TEST_ASSERT_EQUAL(0x98, dataRead); 
}

void test_condition_for_address_0x88_read_mode_INDIRECT_ADDRESSING_of_SRAM_expect_to_read_address_0x88_from_SRAM_INDIRECT_ADDRESSING(void)
{
  int dataRead = 0;
  //setup RAM address to be read
  ram[0x88] = 0x64;
  sfr[0x88] = 0;
  //call function to test mode 
  //                    address     mode
  dataRead = readFromMemory(0x88, INDIRECT_ADDRESSING);
  //code output test
  TEST_ASSERT_EQUAL(0x64, dataRead); 
}

void test_condition_for_address_0x42_read_mode_DIRECT_ADDRESSING_of_RAM_expect_to_read_address_0x42_from_RAM_DIRECT_ADDRESSING(void)
{
  int dataRead = 0;
  //setup RAM address to be read
  ram[0x42] = 0x71;
  //call function to test mode 
  //                     address     mode
  dataRead = readFromMemory(0x42, DIRECT_ADDRESSING);
  //code output test
  TEST_ASSERT_EQUAL(0x71, dataRead); 
}

void test_condition_for_address_0x38_read_mode_INDIRECT_ADDRESSING_of_RAM_expect_to_read_address_0x38_from_RAM_INDIRECT_ADDRESSING(void)
{
  int dataRead = 0;
  //setup RAM address to be read
  ram[0x38] = 0x65;
  //call function to test mode 
  //                    address     mode
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
void test_mov_given_25H_expect_MOV_25H_from_R3_Bank2_to_acc(void)
{ 
    //setup test fixture
    uint8_t machineCode[] = {0xeb};
    //Acc empty 
    acc = 0;
    //setup test
    ram[0x13] = 0x25;     //assign val 25H to R3 bank 2, 25H = 37
    //set psw 10 (Bank2) bits of D4 & D3
    psw = 2 << 3;        //shift left 3 times          
    //codeMemory
    copyCodeToCodeMemory(machineCode, pc = 0x167A);
    //run code under test
    executeInstruction();
    //code output test
    TEST_ASSERT_EQUAL(0x25, ram[0x13]); 
    TEST_ASSERT_EQUAL(0x25, acc);
    TEST_ASSERT_EQUAL_PTR(0x167A + 1, pc);    //test program counter
}

// MOV A,0FH
void test_mov_given_value_1CH_location_0FH_expect_MOV_0FH_value_direct_to_acc(void)
{
  //setup test fixture
  uint8_t machineCode[] = {0xe5,0x0f};
  //acc set 0 
  acc = 0;
  //setup ram 
  ram[0x0f] = 0x1c;
  //codeMemory 
  copyCodeToCodeMemory(machineCode, pc = 0x145C);
  //run code under test 
  executeInstruction();
  //code output test 
  TEST_ASSERT_EQUAL(0x1c, ram[0x0f]);
  TEST_ASSERT_EQUAL(0x1c, acc);
  TEST_ASSERT_EQUAL_PTR(0x145C + 2, pc);
}

// MOV A,@R1
void test_mov_given_address_of_R1_value_21H_expect_address_of_R1_value_21H_to_acc(void)
{ 
    //setup test fixture
    uint8_t machineCode[] = {0xe7}; //@R1
    //acc is 0 
    acc = 0;  
    //assign val 0x21(33) to RAM location
    ram[0x89] = 0x21;
    sfr[0x89] = 0;
    //set psw 01 (Bank1) bit to 4&3
    psw = 1 << 3;        //shift left 1 time
    //test setup calling the address 
    r(1) = 0x89;
    //codeMemory
    copyCodeToCodeMemory(machineCode, pc = 0x1200);
    //run code under test
    executeInstruction();
    //code output test
    TEST_ASSERT_EQUAL(0x21, acc);
    TEST_ASSERT_EQUAL(0x89, r(1));
    TEST_ASSERT_EQUAL_PTR(0x1200 + 1, pc);   
}

// MOV A,#22H
void test_mov_A_hash22H_given_22H_to_acc_expect_22H_direct_to_acc(void)
{ 
    //test setup fixture
    uint8_t machineCode[] = {0x74, 0x22};
    //set acc empty
    acc = 0x00;        
    //copyMemory
    copyCodeToCodeMemory(machineCode, pc = 0x1100);
    //run code under test
    executeInstruction();
    //code output test
    TEST_ASSERT_EQUAL(0x22, acc);              //22H(34) to acc
    TEST_ASSERT_EQUAL_PTR(0x1100 + 2, pc);     //test program counter
}

// MOV R3,A
void test_mov_R3_A_given_99H_in_acc_expect_99H_from_A_to_R3(void)
{ 
    //test setup fixture
    uint8_t machineCode[] = {0xfb};
    //set acc empty
    acc = 0x99;
    //set psw 10(bank2) bit D4 & D3 
    psw = 2 << 3;
    //assign acc to R3 of bank 2
    ram[0x13] = 0;
    //copyMemory
    copyCodeToCodeMemory(machineCode, pc = 0x66A);
    //run code under test
    executeInstruction();
    //code output test
    TEST_ASSERT_EQUAL(0x99, ram[0x13]);        //R3 contains 99H
    TEST_ASSERT_EQUAL(0x99, acc);              
    TEST_ASSERT_EQUAL_PTR(0x66A + 1, pc);     //test program counter
}

// MOV R4,04H 
void test_mov_R4_04H_given_44H_in_address_04H_expect_44H_from_04H_to_R4(void)
{ 
    //test setup fixture
    uint8_t machineCode[] = {0xac,0x04};
    //set acc empty
    acc = 0;
    //set psw 01(bank1) bit D4 & D3 
    psw = 1 << 3;
    //assign acc to R3 of bank 2
    ram[0x0c] = 0;
    //assign address 04H value 44H
    ram[0x04] = 0x44;
    //copyMemory
    copyCodeToCodeMemory(machineCode, pc = 0x66A);
    //run code under test
    executeInstruction();
    //code output test
    TEST_ASSERT_EQUAL(0x44, ram[0x0c]);        
    TEST_ASSERT_EQUAL(0, acc);              
    TEST_ASSERT_EQUAL_PTR(0x66A + 2, pc);     //test program counter
}

// MOV R6,#77H
void test_mov_R6_hash77H_expect_hash77H_to_R6(void)
{ 
    //test setup fixture
    uint8_t machineCode[] = {0x7e,0x77};
    //set acc empty
    acc = 0;
    //set psw 10(bank2) bit D4 & D3 
    psw = 2 << 3;
    //assign acc to R3 of bank 2
    ram[0x16] = 0;
    //copyMemory
    copyCodeToCodeMemory(machineCode, pc = 0x66A);
    //run code under test
    executeInstruction();
    //code output test
    TEST_ASSERT_EQUAL(0x77, ram[0x16]);        
    TEST_ASSERT_EQUAL(0, acc);              
    TEST_ASSERT_EQUAL_PTR(0x66A + 2, pc);     //test program counter
}

// MOV 10H,A 
void test_mov_address_of_10H_A_expect_value_of_A_54H_direct_to_address_10H(void)
{ 
    //test setup fixture
    uint8_t machineCode[] = {0xf5,0x10};
    //set acc empty
    acc = 0x54;
    //direct RAM address
    ram[0x10] = 0;
    //copyMemory
    copyCodeToCodeMemory(machineCode, pc = 0x66A);
    //run code under test
    executeInstruction();
    //code output test
    TEST_ASSERT_EQUAL(0x54, ram[0x10]);       //test fail "Expected 84 was 0"
    TEST_ASSERT_EQUAL_PTR(0x66A + 2, pc);     //test program counter
}
// CLR A
void test_given_value_22H_to_acc_expect_CLR_value_in_acc(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0xe4};
  //add value to acc
  acc = 0x22;
  //codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x0980);
  //run code under test 
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL(0x00, acc);
  TEST_ASSERT_EQUAL_PTR(0x0980 + 1, pc);
}

// INC A
void test_given_value_to_acc_value_7CH_expect_value_to_increment_plus1_to_7DH(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x04};
  //setup acc 
  acc = 0x7c;
  //copyCode 
  copyCodeToCodeMemory(machineCode, pc = 0x0999);
  //run code under test 
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL(0x7d, acc);
  TEST_ASSERT_EQUAL_PTR(0x999 + 1, pc);
}

// DEC A
void test_given_value_to_acc_value_65H_expect_value_to_decrement_MINUS1_to_64H(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x14};
  //setup acc 
  acc = 0x65;
  //copyCode 
  copyCodeToCodeMemory(machineCode, pc = 0x0799);
  //run code under test 
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL(0x64, acc);
  TEST_ASSERT_EQUAL_PTR(0x799 + 1, pc);
}

// INC R6
void test_given_value_45H_to_R6_bank3_expect_value_to_increment_to_46H_in_R6(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x0e};
  //acc setup 
  acc = 0;
  //set psw 11 (bank3) bits D4 & D3 
  psw = 3 << 3;
  //assign value to R6 
  ram[0x1e] = 0x45;
  //copyCode 
  copyCodeToCodeMemory(machineCode, pc = 0x7806);
  //run code under test 
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL(0, acc);
  TEST_ASSERT_EQUAL(0x46, ram[0x1e]);
  TEST_ASSERT_EQUAL_PTR(0x7806 + 1, pc);
}

// INC R5
void test_given_value_66H_to_R5_bank1_expect_value_to_increment_to_67H_in_R5(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x0d};
  //acc setup 
  acc = 0;
  //set psw 01 (bank3) bits D4 & D3 
  psw = 1 << 3;
  //assign value to R5 
  ram[0x0d] = 0x66;
  //copyCode 
  copyCodeToCodeMemory(machineCode, pc = 0x7817);
  //run code under test 
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL(0, acc);
  TEST_ASSERT_EQUAL(0x67, ram[0x0d]);
  TEST_ASSERT_EQUAL_PTR(0x7817 + 1, pc);
}

// NOP
void test_NOP_to_skip_expect_NOP_to_skip_or_do_(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x00};
  //acc setup 
  acc = 0;
  //copy code
  copyCodeToCodeMemory(machineCode, pc = 0x567);
  //run code under test
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL(0, acc);
  TEST_ASSERT_EQUAL_PTR(0x567 + 1, pc);
}

// SWAP A 
void test_SWAP_A_give_value_6BH_expect_SWAP_A_B6H_in_acc(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0xc4};
  //assign acc with value 6BH(107)
  acc = 0x6b;
  //copy code 
  copyCodeToCodeMemory(machineCode, pc = 0x324);
  //run code under test 
  executeInstruction();
  //code output test 
  TEST_ASSERT_EQUAL(0xb6, acc);
  TEST_ASSERT_EQUAL_PTR(0x324 + 1, pc);    
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
void test_given_value_23H_to_acc_expect_23H_complement_become_DCH_in_acc(void) 
{
  //test setup fixture
  uint8_t machineCode[] = {0xf4};
  //assign value 23H to acc 
  acc = 0x23;
  //copy code 
  copyCodeToCodeMemory(machineCode, pc = 0x222);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL(0xdc, acc);
  TEST_ASSERT_EQUAL_PTR(0x222 + 1, pc);
}


  





