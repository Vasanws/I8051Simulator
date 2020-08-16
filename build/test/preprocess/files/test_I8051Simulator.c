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

 ), (UNITY_UINT)(22), UNITY_DISPLAY_STYLE_INT);



}



void test_condition_for_address_0x11_to_DIRECT_ADDRESSING_contains_data_0x43_expect_address_0x11_points_to_data_0x43_at_RAM_DIRECT_ADDRESSING(void)

{



  ram[0x11] = 0;





  writeToRam(0x11, DIRECT_ADDRESSING, 0x43);



  UnityAssertEqualNumber((UNITY_INT)((0x43)), (UNITY_INT)((ram[0x11])), (

 ((void *)0)

 ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_INT);



}

void test_condition_for_address_0x9b_to_INDIRECT_ADDRESSING_contains_data_0x69_expect_address_0x9b_points_to_data_0x69_at_SRAM_INDIRECT_ADDRESSING(void)

{



  ram[0x9b] = 0;





  writeToRam(0x9b, INDIRECT_ADDRESSING, 0x69);



  UnityAssertEqualNumber((UNITY_INT)((0x69)), (UNITY_INT)((ram[0x9b])), (

 ((void *)0)

 ), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_INT);



}



void test_condition_for_address_0x7e_to_INDIRECT_ADDRESSING_contains_data_0x55_expect_address_0x7e_points_to_data_0x55_at_RAM_INDIRECT_ADDRESSING(void)

{



  ram[0x7e] = 0;





  writeToRam(0x7e, DIRECT_ADDRESSING, 0x55);



  UnityAssertEqualNumber((UNITY_INT)((0x55)), (UNITY_INT)((ram[0x7e])), (

 ((void *)0)

 ), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_INT);



}

void test_condition_for_address_0xff_read_mode_DIRECT_ADDRESSING_of_SFR_expect_to_read_address_0xff_from_SFR_DIRECT_ADDRESSING(void)

{

  int dataRead;



  sfr[0xff] = 0x98;

  ram[0xff] = 0;





  dataRead = readFromRam(0xff, DIRECT_ADDRESSING);



  UnityAssertEqualNumber((UNITY_INT)((0x98)), (UNITY_INT)((dataRead)), (

 ((void *)0)

 ), (UNITY_UINT)(70), UNITY_DISPLAY_STYLE_INT);

}

void test_condition_for_address_0x88_read_mode_INDIRECT_ADDRESSING_of_SRAM_expect_to_read_address_0x88_from_SRAM_INDIRECT_ADDRESSING(void)

{

  int dataRead;



  ram[0x88] = 0x64;

  sfr[0x88] = 0;





  dataRead = readFromRam(0x88, INDIRECT_ADDRESSING);



  UnityAssertEqualNumber((UNITY_INT)((0x64)), (UNITY_INT)((dataRead)), (

 ((void *)0)

 ), (UNITY_UINT)(82), UNITY_DISPLAY_STYLE_INT);

}

void test_condition_for_address_0x42_read_mode_DIRECT_ADDRESSING_of_RAM_expect_to_read_address_0x42_from_RAM_DIRECT_ADDRESSING(void)

{

  int dataRead;



  ram[0x42] = 0x71;





  dataRead = readFromRam(0x42, DIRECT_ADDRESSING);



  UnityAssertEqualNumber((UNITY_INT)((0x71)), (UNITY_INT)((dataRead)), (

 ((void *)0)

 ), (UNITY_UINT)(93), UNITY_DISPLAY_STYLE_INT);

}

void test_condition_for_address_0x38_read_mode_INDIRECT_ADDRESSING_of_RAM_expect_to_read_address_0x38_from_RAM_INDIRECT_ADDRESSING(void)

{

  int dataRead;



  ram[0x38] = 0x65;





  dataRead = readFromRam(0x38, INDIRECT_ADDRESSING);



  UnityAssertEqualNumber((UNITY_INT)((0x65)), (UNITY_INT)((dataRead)), (

 ((void *)0)

 ), (UNITY_UINT)(104), UNITY_DISPLAY_STYLE_INT);

}



void test_mov_given_25H_expect_MOV_25H_from_R3_Bank2_to_acc(void)

{



    uint8_t machineCode[] = {0xeb,0xe8, 0x13};



    sfr[0xe0] = 0x25;

    ram[0x13] = 0x25;



    sfr[0xd0] = 2 << 3;



    do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x167A]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



    executeInstruction();



    UnityAssertEqualNumber((UNITY_INT)((0x25)), (UNITY_INT)((sfr[0xe0])), (

   ((void *)0)

   ), (UNITY_UINT)(121), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x25)), (UNITY_INT)((ram[0x13])), (

   ((void *)0)

   ), (UNITY_UINT)(122), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT64)((0x167A + 1)), (UNITY_INT64)((pc)), (

   ((void *)0)

   ), (UNITY_UINT)(123), UNITY_DISPLAY_STYLE_HEX64);

}
