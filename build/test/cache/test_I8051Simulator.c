#include "build/temp/_test_I8051Simulator.c"
#include "src/_testHelper.h"
#include "src/I8051Simulator.h"
#include "C:/Ruby25-x64/lib/ruby/gems/2.5.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"




extern uint8_t ram[];

extern uint8_t sfr[];



void setUp(void){}



void tearDown(void){}





void test_condition_for_address_0xfa_to_DIRECT_ADDRESSING_contains_data_0x76_expect_address_0xfa_points_to_data_0x76_at_SFR_DIRECT_ADDRESSING(void)

{





  sfr[0xfa] = 0;





  writeToRam(0xfa, DIRECT_ADDRESSING, 0x76);



  UnityAssertEqualNumber((UNITY_INT)((0x76)), (UNITY_INT)((sfr[0xfa])), (

 ((void *)0)

 ), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_INT);



}

void test_condition_for_address_0xfd_to_DIRECT_ADDRESSING_contains_data_0x65_expect_address_0xfd_points_to_data_0x65_at_SFR_DIRECT_ADDRESSING(void)

{





  sfr[0xfd] = 0;





  writeToRam(0xfd, DIRECT_ADDRESSING, 0x65);



  UnityAssertEqualNumber((UNITY_INT)((0x65)), (UNITY_INT)((sfr[0xfd])), (

 ((void *)0)

 ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);



}

void test_condition_for_address_0x9b_to_INDIRECT_ADDRESSING_contains_data_0x69_expect_address_0x9b_points_to_data_0x69_at_SRAM_INDIRECT_ADDRESSING(void)

{



  ram[0x9b] = 0;





  writeToRam(0x9b, INDIRECT_ADDRESSING, 0x69);



  UnityAssertEqualNumber((UNITY_INT)((0x69)), (UNITY_INT)((ram[0x9b])), (

 ((void *)0)

 ), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_INT);



}

void test_condition_for_address_0x85_to_INDIRECT_ADDRESSING_contains_data_0x88_expect_address_0x85_points_to_data_0x88_at_SRAM_INDIRECT_ADDRESSING(void)

{



  ram[0x85] = 0;





  writeToRam(0x85, INDIRECT_ADDRESSING, 0x88);



  UnityAssertEqualNumber((UNITY_INT)((0x88)), (UNITY_INT)((ram[0x85])), (

 ((void *)0)

 ), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_INT);



}



void test_condition_for_address_0x11_to_DIRECT_ADDRESSING_contains_data_0x43_expect_address_0x11_points_to_data_0x43_at_RAM_DIRECT_ADDRESSING(void)

{



  ram[0x11] = 0;





  writeToRam(0x11, DIRECT_ADDRESSING, 0x43);



  UnityAssertEqualNumber((UNITY_INT)((0x43)), (UNITY_INT)((ram[0x11])), (

 ((void *)0)

 ), (UNITY_UINT)(69), UNITY_DISPLAY_STYLE_INT);



}

void test_condition_for_address_0x35_to_DIRECT_ADDRESSING_contains_data_0x78_expect_address_0x35_points_to_data_0x78_at_RAM_DIRECT_ADDRESSING(void)

{



  ram[0x35] = 0;





  writeToRam(0x35, DIRECT_ADDRESSING, 0x78);



  UnityAssertEqualNumber((UNITY_INT)((0x78)), (UNITY_INT)((ram[0x35])), (

 ((void *)0)

 ), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_INT);



}

void test_condition_for_address_0x7e_to_INDIRECT_ADDRESSING_contains_data_0x55_expect_address_0x7e_points_to_data_0x55_at_RAM_INDIRECT_ADDRESSING(void)

{



  ram[0x7e] = 0;





  writeToRam(0x7e, DIRECT_ADDRESSING, 0x55);



  UnityAssertEqualNumber((UNITY_INT)((0x55)), (UNITY_INT)((ram[0x7e])), (

 ((void *)0)

 ), (UNITY_UINT)(91), UNITY_DISPLAY_STYLE_INT);



}

void test_condition_for_address_0x6a_to_INDIRECT_ADDRESSING_contains_data_0x9a_expect_address_0x6a_points_to_data_0x9a_at_RAM_INDIRECT_ADDRESSING(void)

{



  ram[0x6a] = 0;





  writeToRam(0x6a, DIRECT_ADDRESSING, 0x9a);



  UnityAssertEqualNumber((UNITY_INT)((0x9a)), (UNITY_INT)((ram[0x6a])), (

 ((void *)0)

 ), (UNITY_UINT)(102), UNITY_DISPLAY_STYLE_INT);



}





void test_condition_for_address_0xff_read_mode_DIRECT_ADDRESSING_of_SFR_expect_to_read_address_0xff_from_SFR_DIRECT_ADDRESSING(void)

{

  int dataRead;



  sfr[0xff] = 0x98;

  ram[0xff] = 0;





  dataRead = readFromRam(0xff, DIRECT_ADDRESSING);



  UnityAssertEqualNumber((UNITY_INT)((0x98)), (UNITY_INT)((dataRead)), (

 ((void *)0)

 ), (UNITY_UINT)(117), UNITY_DISPLAY_STYLE_INT);

}

void test_condition_for_address_0x88_read_mode_INDIRECT_ADDRESSING_of_SRAM_expect_to_read_address_0x88_from_SRAM_INDIRECT_ADDRESSING(void)

{

  int dataRead;



  ram[0x88] = 0x64;

  sfr[0x88] = 0;





  dataRead = readFromRam(0x88, INDIRECT_ADDRESSING);



  UnityAssertEqualNumber((UNITY_INT)((0x64)), (UNITY_INT)((dataRead)), (

 ((void *)0)

 ), (UNITY_UINT)(129), UNITY_DISPLAY_STYLE_INT);

}

void test_condition_for_address_0x42_read_mode_DIRECT_ADDRESSING_of_RAM_expect_to_read_address_0x42_from_RAM_DIRECT_ADDRESSING(void)

{

  int dataRead;



  ram[0x42] = 0x71;





  dataRead = readFromRam(0x42, DIRECT_ADDRESSING);



  UnityAssertEqualNumber((UNITY_INT)((0x71)), (UNITY_INT)((dataRead)), (

 ((void *)0)

 ), (UNITY_UINT)(140), UNITY_DISPLAY_STYLE_INT);

}

void test_condition_for_address_0x38_read_mode_INDIRECT_ADDRESSING_of_RAM_expect_to_read_address_0x38_from_RAM_INDIRECT_ADDRESSING(void)

{

  int dataRead;



  ram[0x38] = 0x65;





  dataRead = readFromRam(0x38, INDIRECT_ADDRESSING);



  UnityAssertEqualNumber((UNITY_INT)((0x65)), (UNITY_INT)((dataRead)), (

 ((void *)0)

 ), (UNITY_UINT)(151), UNITY_DISPLAY_STYLE_INT);

}





void test_R3_access_given_register_select_bank2_expect_access_address_0x13_of_bank2(void)

{



    ram[0x03] = 0x12;

    ram[0x0b] = 0x50;

    ram[0x13] = 0x30;

    ram[0x1b] = 0x20;



    sfr[0xe0] = 0x00;

    sfr[0xd0] = 2 << 3;

    ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (3)] = 0x26;



    UnityAssertEqualNumber((UNITY_INT)((0x26)), (UNITY_INT)((ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (3)])), (

   ((void *)0)

   ), (UNITY_UINT)(167), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x12)), (UNITY_INT)((ram[0x03])), (

   ((void *)0)

   ), (UNITY_UINT)(168), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x50)), (UNITY_INT)((ram[0x0b])), (

   ((void *)0)

   ), (UNITY_UINT)(169), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x26)), (UNITY_INT)((ram[0x13])), (

   ((void *)0)

   ), (UNITY_UINT)(170), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x20)), (UNITY_INT)((ram[0x1b])), (

   ((void *)0)

   ), (UNITY_UINT)(171), UNITY_DISPLAY_STYLE_INT);

}



void test_R6_access_given_register_select_bank3_expect_access_address_0x1e_of_bank3(void)

{



    ram[0x06] = 0x5a;

    ram[0x0e] = 0x3d;

    ram[0x16] = 0x62;

    ram[0x1e] = 0x2f;



    sfr[0xe0] = 0x00;

    sfr[0xd0] = 3 << 3;

    ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (6)] = 0x6b;



    UnityAssertEqualNumber((UNITY_INT)((0x6b)), (UNITY_INT)((ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (6)])), (

   ((void *)0)

   ), (UNITY_UINT)(186), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x5a)), (UNITY_INT)((ram[0x06])), (

   ((void *)0)

   ), (UNITY_UINT)(187), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x3d)), (UNITY_INT)((ram[0x0e])), (

   ((void *)0)

   ), (UNITY_UINT)(188), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x62)), (UNITY_INT)((ram[0x16])), (

   ((void *)0)

   ), (UNITY_UINT)(189), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x6b)), (UNITY_INT)((ram[0x1e])), (

   ((void *)0)

   ), (UNITY_UINT)(190), UNITY_DISPLAY_STYLE_INT);

}









void test_mov_given_25H_expect_MOV_25H_from_R3_Bank2_to_acc(void)

{



    uint8_t machineCode[] = {0xeb};



    sfr[0xe0] = 0;



    ram[0x13] = 0x25;



    sfr[0xd0] = 2 << 3;



    do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x167A]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



    executeInstruction();



    UnityAssertEqualNumber((UNITY_INT)((0x25)), (UNITY_INT)((ram[0x13])), (

   ((void *)0)

   ), (UNITY_UINT)(211), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x25)), (UNITY_INT)((sfr[0xe0])), (

   ((void *)0)

   ), (UNITY_UINT)(212), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT64)((0x167A + 1)), (UNITY_INT64)((pc)), (

   ((void *)0)

   ), (UNITY_UINT)(213), UNITY_DISPLAY_STYLE_HEX64);

}

void test_mov_given_22H_to_acc_expect_22H_direct_to_acc(void)

{

    uint8_t machineCode[] = {0x74, 0x22};





    sfr[0xe0] = 0x00;



    do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x1100]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



    executeInstruction();



    UnityAssertEqualNumber((UNITY_INT)((0x22)), (UNITY_INT)((sfr[0xe0])), (

   ((void *)0)

   ), (UNITY_UINT)(255), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT64)((0x1100 + 2)), (UNITY_INT64)((pc)), (

   ((void *)0)

   ), (UNITY_UINT)(256), UNITY_DISPLAY_STYLE_HEX64);

}





void test_given_value_22H_to_acc_expect_CLR_value_in_acc(void)

{

  uint8_t machineCode[] = {0xe4};





  sfr[0xe0] = 0x22;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0980]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x00)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(271), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0980 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(272), UNITY_DISPLAY_STYLE_HEX64);

}





void test_given_value_to_acc_value_7CH_expect_value_to_increment_plus1_to_7DH(void)

{

  uint8_t machineCode[] = {0x04};





  sfr[0xe0] = 0x7c;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0999]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x7d)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(287), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x999 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(288), UNITY_DISPLAY_STYLE_HEX64);



}





void test_given_value_to_acc_value_65H_expect_value_to_decrement_MINUS1_to_64H(void)

{

  uint8_t machineCode[] = {0x14};





  sfr[0xe0] = 0x65;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0799]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x64)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(304), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x799 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(305), UNITY_DISPLAY_STYLE_HEX64);

}
