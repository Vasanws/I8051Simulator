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

// MOV 12H,A 
void test_mov_12H_A_expect_value_of_A_hash54H_direct_to_location_12H(void)
{ 
    //test setup fixture
    uint8_t machineCode[] = {0xf5,0x12};
    //assign value to acc 
    acc = 0x54;
    //setup ram location
    ram[0x12] = 0;
    //copy code 
    copyCodeToCodeMemory(machineCode, pc = 0x2222);
    //run  code under test 
    executeInstruction();
    //code output test
    TEST_ASSERT_EQUAL(0x54, acc);
    TEST_ASSERT_EQUAL(0x54, ram[0x12]);
    TEST_ASSERT_EQUAL_PTR(0x2222 + 2, pc);
}

// MOV 11H, R5
void test_mov_11H_R5_expect_R5_move_to_location_11H(void)
{
  //test setup fixture 
   uint8_t machineCode[] = {0x8d,0x11};
   //setup acc to 0 
   acc = 0;
   //select bank for R5 
   psw = 1 << 3;
   //assign value in R5
   ram[0x0d] = 0x66;
   //copy code 
   copyCodeToCodeMemory(machineCode, pc = 0x2234);
   //run code under test 
   executeInstruction();
   //code output test 
   TEST_ASSERT_EQUAL(0, acc);
   TEST_ASSERT_EQUAL(0x66, ram[0x0d]);
   TEST_ASSERT_EQUAL(0x66, ram[0x11]);
   TEST_ASSERT_EQUAL_PTR(0x2234 + 2, pc);
}

// MOV 18H,1AH
void test_mov_18H_1AH_expect_location_of_1AH_move_to_location_18H(void)
{
  //test setup fixture 
  uint8_t machineCode[] = {0x85, 0x1a, 0x18};
  //setup acc to 0 
  acc = 0;
  //setup data into location 1AH
  ram[0x1a] = 0x56;
  //copy code 
  copyCodeToCodeMemory(machineCode, pc = 0x2534);
  //run code under test 
  executeInstruction();
  //code output test 
  TEST_ASSERT_EQUAL(0, acc);
  TEST_ASSERT_EQUAL(0x56, ram[0x18]);
  TEST_ASSERT_EQUAL_PTR(0x2534 + 2, pc);  
}

// MOV 1BH,@R1
void test_mov_1BH_addressR1_expect_addressR1_mov_to_location_1BH(void)
{
    //setup test fixture
    uint8_t machineCode[] = {0x87,0x1b}; //@R1
    //acc is 0 
    acc = 0;  
    //assign val 0x22(34) to RAM location
    ram[0x87] = 0x22;
    sfr[0x87] = 0;
    //set psw 01 (Bank1) bit to 4&3
    psw = 1 << 3;        
    //test setup calling the address 
    r(1) = 0x87;
    //codeMemory
    copyCodeToCodeMemory(machineCode, pc = 0x1299);
    //run code under test
    executeInstruction();
    //code output test
    TEST_ASSERT_EQUAL(0, acc);
    TEST_ASSERT_EQUAL(0x87, r(1));
    TEST_ASSERT_EQUAL_PTR(0x1299 + 2, pc);   
}

// MOV 10H,#91
void test_mov_10H_hash91_expect_hash91_move_to_location_10H(void)
{
  //test setup fixture 
  uint8_t machineCode[] = {0x75, 0x10, 0x91};
  //setup acc to 0 
  acc = 0;
  //setup data into location 1AH
  ram[0x10] = 0x91;
  //copy code 
  copyCodeToCodeMemory(machineCode, pc = 0x2034);
  //run code under test 
  executeInstruction();
  //code output test 
  TEST_ASSERT_EQUAL(0, acc);
  TEST_ASSERT_EQUAL(0x91, ram[0x10]);
  TEST_ASSERT_EQUAL_PTR(0x2034 + 2, pc); 
}

// MOV @R1,A
/*void test_mov_addressR1_Acc_expect_Acc_mov_to_addressR1(void)
{
    //setup test fixture
    uint8_t machineCode[] = {0xf7}; //@R1
    //assign value 77H to acc
    acc = 0x77;  
    //RAM location
    ram[0x91] = 0;
    sfr[0x91] = 0;
    //set psw 00 (Bank0) bit to 4&3
    psw = 0 << 3;        
    //test setup calling the address 
    r(1) = 0x91;
    //codeMemory
    copyCodeToCodeMemory(machineCode, pc = 0x1499);
    //run code under test
    executeInstruction();
    //code output test
    TEST_ASSERT_EQUAL(0x77, acc);
    TEST_ASSERT_EQUAL(0x77, r(1));
    TEST_ASSERT_EQUAL_PTR(0x1499 + 1, pc);   
}*/

// MOV DPTR, #1234H
void test_MOV_DPTR_hash1234_given_hash1234_expect_DPH_hold_hash12H_DPL_hold_hash34H()
{
  //test setup fixture
  uint8_t machineCode[] = {0x90, 0x12, 0x34};
  //acc to 0 
  acc = 0;
  //set DPH and DPL to 0 
  DPH = 0;
  DPL = 0;
  //codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x987);
  //run code under test 
  executeInstruction();
  //code output test 
  TEST_ASSERT_EQUAL_INT8(0x12, DPH);
  TEST_ASSERT_EQUAL_INT8(0x34, DPL);
  TEST_ASSERT_EQUAL_PTR(0, acc);
  TEST_ASSERT_EQUAL_PTR(0x987 + 3, pc);
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

// INC R6
void test_INC_R6_expected_value_in_R6_inc(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x0e};
  //acc setup 
  acc = 0;
  //set psw 11 (bank3) bits D4 & D3 
  psw = 3 << 3;
  //R6
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

// INC 17H
void test_INC_17H_expected_hash45_increment_to_hash46_in_location_17H(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x05, 0x17};
  //acc setup 
  acc = 0;
  //set up direct ram 
  ram[0x17] = 0x45;
  //copyCode 
  copyCodeToCodeMemory(machineCode, pc = 0x7816);
  //run code under test 
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL(0, acc);
  TEST_ASSERT_EQUAL(0x46, ram[0x17]);
  TEST_ASSERT_EQUAL_PTR(0x7816 + 2, pc);
}

// INC @R1
/*void test_inc_addressR1_expect_value_in_addressR1_plus1(void)
{
  //setup test fixture
   uint8_t machineCode[] = {0x07}; //@R1
  //assign value 77H to acc
  acc = 0;  
  //RAM location
  ram[0x88] = 0x67;
  sfr[0x88] = 0;
  //set psw 01 (Bank1) bit to 4&3
  psw = 1 << 3;        
  //test setup calling the address 
  r(1) = 0x88;
  //codeMemory
  copyCodeToCodeMemory(machineCode, pc = 0x7826);
  //run code under test
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL(0, acc);
  TEST_ASSERT_EQUAL(0x68, r(1));
  TEST_ASSERT_EQUAL_PTR(0x7826 + 1, pc); 
}*/

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

// DEC R5
void test_DEC_R5_expected_value_in_R5_decrement(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x1d};
  //acc setup 
  acc = 0;
  //set psw 10 (bank2) bits D4 & D3 
  psw = 2 << 3;
  //R6
  ram[0x15] = 0x55;
  //copyCode 
  copyCodeToCodeMemory(machineCode, pc = 0x0789);
  //run code under test 
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL(0, acc);
  TEST_ASSERT_EQUAL(0x54, ram[0x15]);
  TEST_ASSERT_EQUAL_PTR(0x0789 + 1, pc);
}

// DEC 16H
void test_INC_16H_expected_hash44_decrement_to_hash43_in_location_16H(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x15, 0x16};
  //acc setup 
  acc = 0;
  //set up direct ram 
  ram[0x16] = 0x44;
  //copyCode 
  copyCodeToCodeMemory(machineCode, pc = 0x7811);
  //run code under test 
  executeInstruction();
  //code output test
  TEST_ASSERT_EQUAL(0, acc);
  TEST_ASSERT_EQUAL(0x43, ram[0x16]);
  TEST_ASSERT_EQUAL_PTR(0x7811 + 2, pc);
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

// XRL A,R2
void test_XRL_Acc_R2_expect_R2_XRL_Acc(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x6a};
  //assign acc a value 
  acc = 0x24;
  //set R2 10(bank2) bitwise D3 & D4 
  psw = 2 << 3;
  //assign value in R2 
  ram[0x12] = 0x15;
  //copy code 
  copyCodeToCodeMemory(machineCode, pc = 0x111);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL(0x31, acc);
  TEST_ASSERT_EQUAL_PTR(0x111 + 1, pc);
}

// ADD A,R3 
void test_add_Acc_R3_expect_R3_value_add_to_Acc(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x2b};
  //assign value to acc 7EH = 126
  acc = 126;
  //select bank2 R3 
  psw = 2 << 3;
  //set OV to 0 
  status.OV = 0;
  //assign value to R3 4H = 4
  ram[0x13] = 4;
  //copy code 
  copyCodeToCodeMemory(machineCode, pc = 0x123);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_INT8(130, acc);      //7EH + 4H = 82H
                                     //82H => 130
                                     //2's complement => -126
  TEST_ASSERT_EQUAL(1, status.OV);
  TEST_ASSERT_EQUAL_PTR(0x123 + 1, pc);
}

// ADD A,14H 
void test_ADD_A_14H_given_A_plus126_and_14H_plus1_expect_14H_value_add_to_Acc_value_plus127(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x25, 0x14};
  //assign value to acc 126
  acc = 126;
  //set OV to 0 
  status.OV = 1;
  //assign value to R3 4H = 4
  ram[0x14] = 1;
  //copy code 
  copyCodeToCodeMemory(machineCode, pc = 0x124);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_INT8(127, acc);      
  TEST_ASSERT_EQUAL(0, status.OV);
  TEST_ASSERT_EQUAL_PTR(0x124 + 2, pc);
}

// ADD A,85
void test_ADD_A_hash55_given_A_plus126_and_85_expect_85_add_Acc_value_181_with_overflow(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x24, 85};
  //assign value to acc 126
  acc = 126;
  //set OV to 0 
  status.OV = 0;
  //copy code 
  copyCodeToCodeMemory(machineCode, pc = 0x125);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_INT8(211, acc);      
  TEST_ASSERT_EQUAL(1, status.OV);
  TEST_ASSERT_EQUAL_PTR(0x125 + 2, pc);
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
void test_SUBB_A_R2_expect_R2_value_minus_to_Acc(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x9a};
  //assign value to acc
  acc = -127;
  //select bank2 R2 
  psw = 2 << 3;
  //CY is 0 
  status.CY = 0;
  //set OV to 1 
  status.OV = 1;
  //assign value to R3 4H = 4
  ram[0x12] = -3;
  //copy code 
  copyCodeToCodeMemory(machineCode, pc = 0x130);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_INT8(-124, acc);  // -124 (-7C)    
  TEST_ASSERT_EQUAL(0, status.OV);
  TEST_ASSERT_EQUAL(1, status.CY);
  TEST_ASSERT_EQUAL_PTR(0x130 + 1, pc);
}


// A = -110-(1+41) = -151
/* 110 => 0110 1110
     1's  1001 0001
        +         1 (2's)
      -------------
          1001 0010
*/
// SUBB A, R2 
void test_SUBB_A_R2_given_A_minus110_R2_40_CY_1_expect_minus151_in_Acc(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x9a};
  //assign value to acc
  acc = -110;
  //select bank2 R2 
  psw = 2 << 3;
  //CY is 1
  status.CY = 1;
  //set OV to 0 
  status.OV = 0;
  //assign value to R3 4H = 4
  ram[0x12] = 40;
  //copy code 
  copyCodeToCodeMemory(machineCode, pc = 0x131);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_INT8(-151, acc);      
  TEST_ASSERT_EQUAL(1, status.OV);
  TEST_ASSERT_EQUAL(0, status.CY);
  TEST_ASSERT_EQUAL_PTR(0x131 + 1, pc);
}

// SUBB A,15H  
void test_SUBB_A_15H_given_A_minus90_location_15H_30_CY_1_expect_minus121_in_Acc(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x95, 0x15};
  //assign value to acc
  acc = -90;
  //CY is 1
  status.CY = 1;
  //set OV to 0 
  status.OV = 1;
  //assign value location 15H
  ram[0x15] = 30;
  //copy code 
  copyCodeToCodeMemory(machineCode, pc = 0x132);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_INT8(-121, acc);      
  TEST_ASSERT_EQUAL(0, status.OV);
  TEST_ASSERT_EQUAL(0, status.CY);
  TEST_ASSERT_EQUAL_PTR(0x132 + 2, pc);
}

// SUBB A,21
void test_SUBB_A_given_A_119_minus_21_CY_1_OV_1_expect_98_in_Acc(void)
{
  //test setup fixture
  uint8_t machineCode[] = {0x94, 21};
  //assign value to acc
  acc = 119;
  //CY is 1
  status.CY = 1;
  //set OV to 0 
  status.OV = 1;
  //copy code 
  copyCodeToCodeMemory(machineCode, pc = 0x133);
  //run code under test 
  executeInstruction();
  //code test output 
  TEST_ASSERT_EQUAL_INT8(98, acc);      
  TEST_ASSERT_EQUAL(0, status.OV);
  TEST_ASSERT_EQUAL(0, status.CY);
  TEST_ASSERT_EQUAL_PTR(0x133 + 2, pc);
}


