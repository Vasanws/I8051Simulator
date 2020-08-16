#include "unity.h"
#include "I8051Simulator.h"
#include "_testHelper.h"


extern uint8_t ram[];
extern uint8_t sfr[];

void setUp(void){}

void tearDown(void){}

void test_condition_for_address_0xfa_to_DIRECT_ADDRESSING_contains_data_0x76_expect_address_0xfa_points_to_data_0x76_at_SFR_DIRECT_ADDRESSING(void) 
{
  
  //setup 0xfa bottom RAM address set value is 0
  sfr[0xfa] = 0;
  //call functon to test the mode
  //         address   AccessMode      data
  writeToRam(0xfa, DIRECT_ADDRESSING, 0x76);
  //Test function
  TEST_ASSERT_EQUAL(0x76, sfr[0xfa]);
  
}

void test_condition_for_address_0x11_to_DIRECT_ADDRESSING_contains_data_0x43_expect_address_0x11_points_to_data_0x43_at_RAM_DIRECT_ADDRESSING(void) 
{
  //setup 0x11 bottom RAM address set value is 0
  ram[0x11] = 0;
  //call functon to test the mode
  //        address   AccessMode      data
  writeToRam(0x11, DIRECT_ADDRESSING, 0x43);
  //Test function
  TEST_ASSERT_EQUAL(0x43, ram[0x11]);
  
}
void test_condition_for_address_0x9b_to_INDIRECT_ADDRESSING_contains_data_0x69_expect_address_0x9b_points_to_data_0x69_at_SRAM_INDIRECT_ADDRESSING(void) 
{
  //setup 0x9b bottom RAM address set value is 0
  ram[0x9b] = 0;
  //call functon to test the mode
  //        address   AccessMode      data
  writeToRam(0x9b, INDIRECT_ADDRESSING, 0x69);
  //Test function
  TEST_ASSERT_EQUAL(0x69, ram[0x9b]);
  
}

void test_condition_for_address_0x7e_to_INDIRECT_ADDRESSING_contains_data_0x55_expect_address_0x7e_points_to_data_0x55_at_RAM_INDIRECT_ADDRESSING(void) 
{
  //setup 0x7e bottom RAM address set value is 0
  ram[0x7e] = 0;
  //call functon to test the mode
  //        address   AccessMode      data
  writeToRam(0x7e, DIRECT_ADDRESSING, 0x55);
  //Test function
  TEST_ASSERT_EQUAL(0x55, ram[0x7e]);
  
}
void test_condition_for_address_0xff_read_mode_DIRECT_ADDRESSING_of_SFR_expect_to_read_address_0xff_from_SFR_DIRECT_ADDRESSING(void)
{
  int dataRead;
  //setup RAM address to be read
  sfr[0xff] = 0x98;
  ram[0xff] = 0;
  //call function to test mode 
  //                    address    AccessMode
  dataRead = readFromRam(0xff, DIRECT_ADDRESSING);
  //Test function
  TEST_ASSERT_EQUAL(0x98, dataRead); 
}
void test_condition_for_address_0x88_read_mode_INDIRECT_ADDRESSING_of_SRAM_expect_to_read_address_0x88_from_SRAM_INDIRECT_ADDRESSING(void)
{
  int dataRead;
  //setup RAM address to be read
  ram[0x88] = 0x64;
  sfr[0x88] = 0;
  //call function to test mode 
  //         address     mode
  dataRead = readFromRam(0x88, INDIRECT_ADDRESSING);
  //Test function
  TEST_ASSERT_EQUAL(0x64, dataRead); 
}
void test_condition_for_address_0x42_read_mode_DIRECT_ADDRESSING_of_RAM_expect_to_read_address_0x42_from_RAM_DIRECT_ADDRESSING(void)
{
  int dataRead;
  //setup RAM address to be read
  ram[0x42] = 0x71;
  //call function to test mode 
  //         address     mode
  dataRead = readFromRam(0x42, DIRECT_ADDRESSING);
  //Test function
  TEST_ASSERT_EQUAL(0x71, dataRead); 
}
void test_condition_for_address_0x38_read_mode_INDIRECT_ADDRESSING_of_RAM_expect_to_read_address_0x38_from_RAM_INDIRECT_ADDRESSING(void)
{
  int dataRead;
  //setup RAM address to be read
  ram[0x38] = 0x65;
  //call function to test mode 
  //         address     mode
  dataRead = readFromRam(0x38, INDIRECT_ADDRESSING);
  //Test function
  TEST_ASSERT_EQUAL(0x65, dataRead); 
}

void test_mov_given_25H_expect_MOV_25H_from_R3_Bank2_to_acc(void)
{ 
    //setup test fixture
    uint8_t machineCode[] = {0xeb,0xe8, 0x13};
    //Acc empty 
    acc = 0;
    ram[0x13] = 0x25;     //assign val 25H to R3 bank 2, 25H = 37
    //set psw 10 (Bank2) bits of D4 & D3
    psw = 2 << 3;        //shift left 3 times          
    //codeMemory
    copyCodeToCodeMemory(machineCode, pc = 0x167A);
    //run code under test
    executeInstruction();
    //code output test
    TEST_ASSERT_EQUAL(0x25, acc);             //ceedling error at line 121 expected 37 was 0
                                              //mov() function in the debugger shows the 1st if condition enter the 1st statement
                                              //shows that acc = r(*codePtr & 7); (*codePtr & 7) in the watches shows the val is 3 int.
                                              //to translate in simple C; acc = r(3);
                                              //test fail where acc does not contains val 25H/37 as ASM MOV A,R3 even the test is set.
    TEST_ASSERT_EQUAL(0x25, ram[0x13]);
    TEST_ASSERT_EQUAL_PTR(0x167A + 1, pc);    //test program counter
}

/*void test_mov_given_22H_to_acc_expect_22H_direct_to_acc(void)
{ 
    uint8_t machineCode[] = {0x74,0x22};
    
    //direct value to Acc
    acc = 0x00;        
    
    //copyMemory
    copyCodeToCodeMemory(machineCode, pc = 0x1100);
    
    //run code under test
    executeInstruction();
    
    //code output test
    TEST_ASSERT_EQUAL(0x22, acc);              //test acc direct value
    TEST_ASSERT_EQUAL_PTR(0x1100 + 2, pc);     //test program counter
    
    
}*/
/*void test_mov_given_addrees_of_21H_expect_address_of_21H_to_acc(void)
{ 

    //setup test fixture
    uint8_t machineCode[] = {0xe6,0xe7};
    
    ram[0x93] = 0x21;    //assign val to R1 Bank 1 into ram pointer  0x21 = 33
    
    //Acc empty 
    acc = 0x00;   
    
    //set psw 01 (Bank1) bit to 4&3
    psw = 1 << 3;        //shift left 1 time
    
    //test setup 
    r(1) = 0x93;

    //codeMemory
    copyCodeToCodeMemory(machineCode, pc = 0x1200);
    
    //run code under test
    //executeInstruction();

    //code output test
    TEST_ASSERT_EQUAL(0x21, acc);             //test acc value
    TEST_ASSERT_EQUAL(0x93, r(1));            //test register R1 value
    TEST_ASSERT_EQUAL_PTR(0x1200 + 2, pc);    //test program counter
    
    
}*/

/*void test_R3_access_given_register_select_2_expect_access_address_0x13(void)
{
    //test setup
    ram[0x03] = 0x12;     //R3 of bank 0
    ram[0x0b] = 0x50;     //R3 of bank 1
    ram[0x13] = 0x30;     //R3 of bank 2
    ram[0x1b] = 0x20;     //R3 of bank 3
    
    acc = 0x00;
    psw = 2 << 3;
    r(3) = 0x26;
    
    TEST_ASSERT_EQUAL(0x26, r(3));
    TEST_ASSERT_EQUAL(0x12,ram[0x03]);      
    TEST_ASSERT_EQUAL(0x50, ram[0x0b]);
    TEST_ASSERT_EQUAL(0x26, ram[0x13]);
    TEST_ASSERT_EQUAL(0x20, ram[0x1b]);
}*/

/*void test_R4_access_given_register_select_1_expect_access_address_0x0C(void)
{
  //test setup
  ram[0x04] = 0x56;   //R4 of bank 0
  ram[0x0c] = 0x57;   //R4 of bank 1
  ram[0x14] = 0x58;   //R4 of bank 2
  ram[0x1c] = 0x59;   //R4 of bank 3
  Acc = 0x00;
  psw = 1 << 3;
   r(4) = 0xfa
  TEST_ASSERT_EQUAL(0x57, r4);
  TEST_ASSERT_EQUAL(0xfa,ram[0x1c]);
  TEST_ASSERT_EQUAL(0x57, ram[0x04]);
  TEST_ASSERT_EQUAL(0x57, ram[0x14]);
  TEST_ASSERT_EQUAL(0x57, ram[0x0c]);
}

void test_R4_access_given_register_select_3_expect_access_address_0x0C(void)
{
  //test setup
  ram[0x04] = 0x56;   //R4 of bank 0
  ram[0x0c] = 0x57;   //R4 of bank 1
  ram[0x14] = 0x58;   //R4 of bank 2
  ram[0x1c] = 0x59;   //R4 of bank 3
  Acc = 0x00;
  psw = 3 << 3;
   r(4) = 0xfa
  TEST_ASSERT_EQUAL(0x57, r4);
  TEST_ASSERT_EQUAL(0x59,ram[0x1c]);
  TEST_ASSERT_EQUAL(0x57, ram[0x04]);
  TEST_ASSERT_EQUAL(0x57, ram[0x14]);
  TEST_ASSERT_EQUAL(0xfa, ram[0x0c]);
}
*/
  
