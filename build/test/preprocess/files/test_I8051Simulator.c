#include "build/temp/_test_I8051Simulator.c"
#include "src/_testHelper.h"
#include "src/I8051Simulator.h"
#include "C:/Ruby25-x64/lib/ruby/gems/2.5.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"




extern uint8_t ram[];

extern uint8_t sfr[];



void setUp(void){}



void tearDown(void){}





void test_given_address_0xfa_is_DIRECT_ADDRESSING_mode_data_0x76_in_SFR_expect_data_0x76_write_to_address_0xfa_mode_DIRECT_ADDRESSING_in_SFR(void)

{



  sfr[0xfa] = 0;





  writeToMemory(0xfa, DIRECT_ADDRESSING, 0x76);



  UnityAssertEqualNumber((UNITY_INT)((0x76)), (UNITY_INT)((sfr[0xfa])), (

 ((void *)0)

 ), (UNITY_UINT)(22), UNITY_DISPLAY_STYLE_INT);



}

void test_given_address_0x9b_is_INDIRECT_ADDRESSING_mode_data_0x69_top_SRAM_expect_data_0x69_write_to_address_0x9b_mode_INDIRECT_ADDRESSING_in_top_SRAM(void)

{



  ram[0x9b] = 0;





  writeToMemory(0x9b, INDIRECT_ADDRESSING, 0x69);



  UnityAssertEqualNumber((UNITY_INT)((0x69)), (UNITY_INT)((ram[0x9b])), (

 ((void *)0)

 ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_INT);

}

void test_given_address_0x11_is_DIRECT_ADDRESSING_data_0x43_bottom_RAM_expect_data_0x43_write_to_address_0x11_mode_DIRECT_ADDRESSING_in_bottom_RAM(void)

{



  ram[0x11] = 0;





  writeToMemory(0x11, DIRECT_ADDRESSING, 0x43);



  UnityAssertEqualNumber((UNITY_INT)((0x43)), (UNITY_INT)((ram[0x11])), (

 ((void *)0)

 ), (UNITY_UINT)(43), UNITY_DISPLAY_STYLE_INT);

}

void test_given_address_0x7e_to_INDIRECT_ADDRESSING_mode_data_0x55_bottom_RAM_expect_data_0x55_write_to_address_0x7e_mode_INDIRECT_ADDRESSING_in_bottom_RAM(void)

{



  ram[0x7e] = 0;





  writeToMemory(0x7e, INDIRECT_ADDRESSING, 0x55);



  UnityAssertEqualNumber((UNITY_INT)((0x55)), (UNITY_INT)((ram[0x7e])), (

 ((void *)0)

 ), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_INT);

}





void test_given_address_0xff_readmode_DIRECT_ADDRESSING_of_SFR_expect_to_read_address_0xff_from_SFR_mode_DIRECT_ADDRESSING(void)

{

  int dataRead = 0;



  sfr[0xff] = 0x98;

  ram[0xff] = 0;





  dataRead = readFromMemory(0xff, DIRECT_ADDRESSING);



  UnityAssertEqualNumber((UNITY_INT)((0x98)), (UNITY_INT)((dataRead)), (

 ((void *)0)

 ), (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_INT);

}



void test_given_address_0x88_read_mode_INDIRECT_ADDRESSING_of_SRAM_expect_to_read_address_0x88_from_SRAM_mode_INDIRECT_ADDRESSING(void)

{

  int dataRead = 0;



  ram[0x88] = 0x64;

  sfr[0x88] = 0;





  dataRead = readFromMemory(0x88, INDIRECT_ADDRESSING);



  UnityAssertEqualNumber((UNITY_INT)((0x64)), (UNITY_INT)((dataRead)), (

 ((void *)0)

 ), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_INT);

}



void test_given_address_0x42_read_mode_DIRECT_ADDRESSING_of_RAM_expect_to_read_address_0x42_from_RAM_mode_DIRECT_ADDRESSING(void)

{

  int dataRead = 0;



  ram[0x42] = 0x71;





  dataRead = readFromMemory(0x42, DIRECT_ADDRESSING);



  UnityAssertEqualNumber((UNITY_INT)((0x71)), (UNITY_INT)((dataRead)), (

 ((void *)0)

 ), (UNITY_UINT)(92), UNITY_DISPLAY_STYLE_INT);

}



void test_given_address_0x38_read_mode_INDIRECT_ADDRESSING_of_RAM_expect_to_read_address_0x38_from_RAM_mode_INDIRECT_ADDRESSING(void)

{

  int dataRead = 0;



  ram[0x38] = 0x65;





  dataRead = readFromMemory(0x38, INDIRECT_ADDRESSING);



  UnityAssertEqualNumber((UNITY_INT)((0x65)), (UNITY_INT)((dataRead)), (

 ((void *)0)

 ), (UNITY_UINT)(104), UNITY_DISPLAY_STYLE_INT);

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

   ), (UNITY_UINT)(122), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x12)), (UNITY_INT)((ram[0x03])), (

   ((void *)0)

   ), (UNITY_UINT)(123), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x50)), (UNITY_INT)((ram[0x0b])), (

   ((void *)0)

   ), (UNITY_UINT)(124), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x26)), (UNITY_INT)((ram[0x13])), (

   ((void *)0)

   ), (UNITY_UINT)(125), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x20)), (UNITY_INT)((ram[0x1b])), (

   ((void *)0)

   ), (UNITY_UINT)(126), UNITY_DISPLAY_STYLE_INT);

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

   ), (UNITY_UINT)(143), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x5a)), (UNITY_INT)((ram[0x06])), (

   ((void *)0)

   ), (UNITY_UINT)(144), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x3d)), (UNITY_INT)((ram[0x0e])), (

   ((void *)0)

   ), (UNITY_UINT)(145), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x62)), (UNITY_INT)((ram[0x16])), (

   ((void *)0)

   ), (UNITY_UINT)(146), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x6b)), (UNITY_INT)((ram[0x1e])), (

   ((void *)0)

   ), (UNITY_UINT)(147), UNITY_DISPLAY_STYLE_INT);

}









void test_MOV_A_R3_given_R3_value_25H_expect_value_R3_25H_mov_to_A(void)

{



  uint8_t machineCode[] = {0xeb};



  sfr[0xe0] = 0;



  ram[0x13] = 0x25;



  sfr[0xd0] = 2 << 3;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0100]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x25)), (UNITY_INT)((ram[0x13])), (

 ((void *)0)

 ), (UNITY_UINT)(168), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x25)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(169), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0100 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(170), UNITY_DISPLAY_STYLE_HEX64);

}





void test_MOV_0FH_A_given_0FH_value_1CH_expect_value_of_location_0FH_mov_to_A(void)

{



  uint8_t machineCode[] = {0xe5,0x0f};



  sfr[0xe0] = 0;



  ram[0x0f] = 0x1c;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0102]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x1c)), (UNITY_INT)((ram[0x0f])), (

 ((void *)0)

 ), (UNITY_UINT)(187), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x1c)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(188), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0102 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(189), UNITY_DISPLAY_STYLE_HEX64);

}





void test_MOV_addressR1_A_given_addressR1_value_21H_expect_value_of_addressR1_mov_to_A(void)

{



  uint8_t machineCode[] = {0xe7};



  sfr[0xe0] = 0;



  ram[0x89] = 0x21;

  sfr[0x89] = 0;



  sfr[0xd0] = 1 << 3;



  ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (1)] = 0x89;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0103]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x21)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(211), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x89)), (UNITY_INT)((ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (1)])), (

 ((void *)0)

 ), (UNITY_UINT)(212), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0103 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(213), UNITY_DISPLAY_STYLE_HEX64);

}





void test_MOV_hash22H_A_given_data_hash22H_expect_hash22_mov_to_A(void)

{



  uint8_t machineCode[] = {0x74, 0x22};



  sfr[0xe0] = 0;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0104]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x22)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(228), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0104 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(229), UNITY_DISPLAY_STYLE_HEX64);

}





void test_MOV_A_R3_given_A_value_99H_expect_value_of_A_mov_to_R3(void)

{



  uint8_t machineCode[] = {0xfb};



  sfr[0xe0] = 0x99;



  sfr[0xd0] = 2 << 3;



  ram[0x13] = 0;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0105]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x99)), (UNITY_INT)((ram[0x13])), (

 ((void *)0)

 ), (UNITY_UINT)(248), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x99)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(249), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0105 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(250), UNITY_DISPLAY_STYLE_HEX64);

}





void test_MOV_04H_R4_given_04H_value_44H_expect_value_of_location_04H_mov_to_R4(void)

{



  uint8_t machineCode[] = {0xac,0x04};



  sfr[0xe0] = 0;



  sfr[0xd0] = 1 << 3;



  ram[0x0c] = 0;



  ram[0x04] = 0x44;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0106]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x44)), (UNITY_INT)((ram[0x0c])), (

 ((void *)0)

 ), (UNITY_UINT)(271), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(272), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0106 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(273), UNITY_DISPLAY_STYLE_HEX64);

}





void test_MOV_hash77H_R6_given_data_hash77H_expect_data_mov_to_R6(void)

{



  uint8_t machineCode[] = {0x7e,0x77};



  sfr[0xe0] = 0;



  sfr[0xd0] = 2 << 3;



  ram[0x16] = 0;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0107]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x77)), (UNITY_INT)((ram[0x16])), (

 ((void *)0)

 ), (UNITY_UINT)(292), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(293), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0107 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(294), UNITY_DISPLAY_STYLE_HEX64);

}





void test_MOV_12H_A_given_A_value_54H_expect_value_of_A_mov_to_location_12H(void)

{



  uint8_t machineCode[] = {0xf5,0x12};



  sfr[0xe0] = 0x54;



  ram[0x12] = 0;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0108]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x54)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(311), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x54)), (UNITY_INT)((ram[0x12])), (

 ((void *)0)

 ), (UNITY_UINT)(312), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0108 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(313), UNITY_DISPLAY_STYLE_HEX64);

}





void test_MOV_11H_R5_given_R5_value_66H_expect_value_of_R5_mov_to_location_11H(void)

{



  uint8_t machineCode[] = {0x8d,0x11};



  sfr[0xe0] = 0;



  sfr[0xd0] = 1 << 3;



  ram[0x0d] = 0x66;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0109]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(332), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x66)), (UNITY_INT)((ram[0x0d])), (

 ((void *)0)

 ), (UNITY_UINT)(333), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x66)), (UNITY_INT)((ram[0x11])), (

 ((void *)0)

 ), (UNITY_UINT)(334), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0109 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(335), UNITY_DISPLAY_STYLE_HEX64);

}





void test_MOV_18H_1AH_given_1AH_value_56H_expect_value_of_location_1AH_mov_to_location_18H(void)

{



  uint8_t machineCode[] = {0x85, 0x1a, 0x18};



  sfr[0xe0] = 0;



  ram[0x1a] = 0x56;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0110]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(352), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x56)), (UNITY_INT)((ram[0x18])), (

 ((void *)0)

 ), (UNITY_UINT)(353), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0110 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(354), UNITY_DISPLAY_STYLE_HEX64);

}





void test_MOV_1BH_addressR1_given_addressR1_value_22H_expect_value_of_addressR1_mov_to_location_1BH(void)

{



  uint8_t machineCode[] = {0x87,0x1b};



  sfr[0xe0] = 0;



  ram[0x87] = 0x22;

  sfr[0x87] = 0;



  sfr[0xd0] = 1 << 3;



  ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (1)] = 0x87;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0111]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(376), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x87)), (UNITY_INT)((ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (1)])), (

 ((void *)0)

 ), (UNITY_UINT)(377), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0111 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(378), UNITY_DISPLAY_STYLE_HEX64);

}





void test_MOV_10H_hash91H_given_data_hash91_expect_data_mov_to_location_10H(void)

{



  uint8_t machineCode[] = {0x75, 0x10, 0x91};



  sfr[0xe0] = 0;



  ram[0x10] = 0x91;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0112]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(395), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x91)), (UNITY_INT)((ram[0x10])), (

 ((void *)0)

 ), (UNITY_UINT)(396), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0112 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(397), UNITY_DISPLAY_STYLE_HEX64);

}





void test_MOV_addressR1_A_given_A_value_77H_expect_value_of_A_mov_to_addressR1(void)

{



  uint8_t machineCode[] = {0xf7};



  sfr[0xe0] = 0x77;



  ram[0x91] = 0;

  sfr[0x91] = 0;



  sfr[0xd0] = 0 << 3;



  ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (1)] = 0x91;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0113]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x77)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(419), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x91)), (UNITY_INT)((ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (1)])), (

 ((void *)0)

 ), (UNITY_UINT)(420), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0113 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(421), UNITY_DISPLAY_STYLE_HEX64);

}





void test_MOV_addressR1_1FH_given_1FH_value_78H_expect_value_of_location_1FH_mov_to_addressR1(void)

{



  uint8_t machineCode[] = {0xa7, 0x1f};



  sfr[0xe0] = 0;



  ram[0x1f] = 0x78;



  ram[0x85] = 0;

  sfr[0x85] = 0;



  sfr[0xd0] = 0 << 3;



  ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (1)] = 0x85;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0114]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(445), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x85)), (UNITY_INT)((ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (1)])), (

 ((void *)0)

 ), (UNITY_UINT)(446), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0114 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(447), UNITY_DISPLAY_STYLE_HEX64);

}





void test_MOV_addressR1_hash66H_given_data_hash66H_expect_data_mov_to_addressR1(void)

{



  uint8_t machineCode[] = {0x77, 0x66};



  sfr[0xe0] = 0;



  ram[0x9b] = 0;

  sfr[0x9b] = 0;



  sfr[0xd0] = 0 << 3;



  ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (1)] = 0x9b;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0115]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(469), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x9b)), (UNITY_INT)((ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (1)])), (

 ((void *)0)

 ), (UNITY_UINT)(470), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0115 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(471), UNITY_DISPLAY_STYLE_HEX64);

}



void test_MOV_DPTR_hash1234H_given_data_hash1234H_expect_data_mov_to_DPTR_DH_hold_12H_and_DPL_hold_34H(void)

{



  uint8_t machineCode[] = {0x90, 0x12, 0x34};



  sfr[0xe0] = 0;



  sfr[0x83] = 0;

  sfr[0x82] = 0;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0116]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x12)), (UNITY_INT)(UNITY_INT8 )((sfr[0x83])), (

 ((void *)0)

 ), (UNITY_UINT)(488), UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x34)), (UNITY_INT)(UNITY_INT8 )((sfr[0x82])), (

 ((void *)0)

 ), (UNITY_UINT)(489), UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((UNITY_INT64)((0)), (UNITY_INT64)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(490), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((0x0116 + 3)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(491), UNITY_DISPLAY_STYLE_HEX64);

}





void test_MOVX_A_addressR1_given_addressR1_value_76H_expect_value_addressR1_external_RAM_mov_to_A(void)

{



  uint8_t machineCode[] = {0xe3};



  sfr[0xe0] = 0;



  xram[0x99] = 0x76;

  ram[0x99] = 0;

  sfr[0x99] = 0;



  sfr[0xd0] = 1 << 3;



  xram[((sfr[0xd0] >> 3) & 0x03) * 8 + (1)] = 0x99;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0117]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x76)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(514), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT)((0x99)), (UNITY_INT)((xram[((sfr[0xd0] >> 3) & 0x03) * 8 + (1)])), (

 ((void *)0)

 ), (UNITY_UINT)(515), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0117 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(516), UNITY_DISPLAY_STYLE_HEX64);

}





void test_INC_R6_given_R6_value_45H_expect_value_of_R6_plus1_to_46H(void)

{



  uint8_t machineCode[] = {0x0e};



  sfr[0xe0] = 0;



  sfr[0xd0] = 3 << 3;



  ram[0x1e] = 0x45;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0301]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(535), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x46)), (UNITY_INT)((ram[0x1e])), (

 ((void *)0)

 ), (UNITY_UINT)(536), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0301 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(537), UNITY_DISPLAY_STYLE_HEX64);

}





void test_INC_17H_given_17H_value_54H_expect_value_of_location_17H_plus1_to_55H(void)

{



  uint8_t machineCode[] = {0x05, 0x17};



  sfr[0xe0] = 0;



  ram[0x17] = 0x54;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0302]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(554), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x55)), (UNITY_INT)((ram[0x17])), (

 ((void *)0)

 ), (UNITY_UINT)(555), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0302 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(556), UNITY_DISPLAY_STYLE_HEX64);

}





void test_INC_addressR1_given_addressR1_value_67H_expect_value_of_addressR1_plus1_to_68H(void)

{



   uint8_t machineCode[] = {0x07};



  sfr[0xe0] = 0;



  ram[0x88] = 0x67;

  sfr[0x88] = 0;



  sfr[0xd0] = 1 << 3;



  ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (1)] = 0x88;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0303]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(578), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x88)), (UNITY_INT)((ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (1)])), (

 ((void *)0)

 ), (UNITY_UINT)(579), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0303 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(580), UNITY_DISPLAY_STYLE_HEX64);

}





void test_DEC_A_given_A_value_65H_expect_value_of_A_MINUS1_to_64H(void)

{



  uint8_t machineCode[] = {0x14};



  sfr[0xe0] = 0x65;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0304]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x64)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(595), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT64)((0x304 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(596), UNITY_DISPLAY_STYLE_HEX64);

}





void test_DEC_R5_given_R5_value_55H_expect_value_of_R5_MINUS1_to_54H(void)

{



  uint8_t machineCode[] = {0x1d};



  sfr[0xe0] = 0;



  sfr[0xd0] = 2 << 3;



  ram[0x15] = 0x55;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0305]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x54)), (UNITY_INT)(UNITY_INT8 )((ram[0x15])), (

 ((void *)0)

 ), (UNITY_UINT)(615), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT64)((0x0305 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(616), UNITY_DISPLAY_STYLE_HEX64);

}





void test_INC_16H_given_16H_value_44H_expect_value_of_location_16H_MINUS1_to_43H(void)

{



  uint8_t machineCode[] = {0x15, 0x16};



  sfr[0xe0] = 0;



  ram[0x16] = 0x44;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0306]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x43)), (UNITY_INT)(UNITY_INT8 )((ram[0x16])), (

 ((void *)0)

 ), (UNITY_UINT)(633), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT64)((0x0306 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(634), UNITY_DISPLAY_STYLE_HEX64);

}





void test_DEC_addressR1_given_addressR1_value_72H_expect_value_of_addressR1_MINUS1_to_76H(void)

{



   uint8_t machineCode[] = {0x17};



  sfr[0xe0] = 0;



  ram[0x91] = 0x72;

  sfr[0x91] = 0;



  sfr[0xd0] = 2 << 3;



  ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (1)] = 0x91;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0307]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x91)), (UNITY_INT)(UNITY_INT8 )((ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (1)])), (

 ((void *)0)

 ), (UNITY_UINT)(656), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT64)((0x0307 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(657), UNITY_DISPLAY_STYLE_HEX64);

}





void test_CLR_A_given_A_value_22H_expect_value_of_A_is_clear(void)

{



  uint8_t machineCode[] = {0xe4};



  sfr[0xe0] = 0x22;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0200]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x00)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(672), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0200 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(673), UNITY_DISPLAY_STYLE_HEX64);

}





void test_NOP_to_perform_a_skip(void)

{



  uint8_t machineCode[] = {0x00};



  sfr[0xe0] = 0;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0201]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(688), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0201 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(689), UNITY_DISPLAY_STYLE_HEX64);

}





void test_SWAP_A_given_A_value_6BH_expect_value_of_A_swap_to_B6H_to_A(void)

{



  uint8_t machineCode[] = {0xc4};



  sfr[0xe0] = 0x6b;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0202]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0xb6)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(704), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0202 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(705), UNITY_DISPLAY_STYLE_HEX64);

}

void test_CPL_A_given_A_value_23H_expect_value_of_A_compliment_to_DCH(void)

{



  uint8_t machineCode[] = {0xf4};



  sfr[0xe0] = 0x23;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0203]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0xdc)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(729), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0203 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(730), UNITY_DISPLAY_STYLE_HEX64);

}





void test_RL_A_given_A_value_E6H_expect_value_A_rotate_left_73H(void)

{



  uint8_t machineCode[] = {0x23};



  sfr[0xe0] = 0xe6;



  (*(Status*)&sfr[0xd0]).CY = 0;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0204]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0xcd)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(747), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(748), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0204 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(749), UNITY_DISPLAY_STYLE_HEX64);

}





void test_RLC_A_given_A_value_E6H_expect_value_A_rotate_left_B9H_with_carry_set(void)

{



  uint8_t machineCode[] = {0x33};



  sfr[0xe0] = 0xe6;



  (*(Status*)&sfr[0xd0]).CY = 0;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0206]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0xcc)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(766), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(767), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0206 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(768), UNITY_DISPLAY_STYLE_HEX64);

}





void test_RLC_A_given_A_value_F4H_expect_value_A_rotate_left_E9H_with_carry_set(void)

{



  uint8_t machineCode[] = {0x33};



  sfr[0xe0] = 0xf4;



  (*(Status*)&sfr[0xd0]).CY = 1;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0207]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0xe9)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(785), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(786), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0207 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(787), UNITY_DISPLAY_STYLE_HEX64);

}





void test_RR_A_given_A_value_59H_expect_value_A_rotate_right_ACH(void)

{



  uint8_t machineCode[] = {0x03};



  sfr[0xe0] = 0x59;



  (*(Status*)&sfr[0xd0]).CY = 0;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0205]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0xac)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(804), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(805), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0205 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(806), UNITY_DISPLAY_STYLE_HEX64);

}





void test_RRC_A_given_A_value_D6H_expect_value_A_rotate_right_6BH_with_carry_set(void)

{



  uint8_t machineCode[] = {0x13};



  sfr[0xe0] = 0xd6;



  (*(Status*)&sfr[0xd0]).CY = 0;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0208]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x6b)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(823), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(824), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0208 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(825), UNITY_DISPLAY_STYLE_HEX64);

}





void test_RRC_A_given_A_value_C4H_expect_value_A_rotate_right_H_with_carry_set(void)

{



  uint8_t machineCode[] = {0x13};



  sfr[0xe0] = 0xC4;



  (*(Status*)&sfr[0xd0]).CY = 1;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0209]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0xe2)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(842), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(843), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0209 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(844), UNITY_DISPLAY_STYLE_HEX64);

}









void test_MUL_A_B_given_A_value_54H_and_B_value_A3H_expect_values_A_multiply_B_product_357CH(void)

{



  uint8_t machineCode[] = {0xa4};



  sfr[0xe0] = 0x54;



  sfr[0xf0] = 0xa3;



  (*(Status*)&sfr[0xd0]).CY = 1;



  (*(Status*)&sfr[0xd0]).OV = 0;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0210]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x7c)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(867), UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x35)), (UNITY_INT)(UNITY_INT8 )((sfr[0xf0])), (

 ((void *)0)

 ), (UNITY_UINT)(868), UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(869), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).OV)), (

 ((void *)0)

 ), (UNITY_UINT)(870), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0210 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(871), UNITY_DISPLAY_STYLE_HEX64);

}









void test_DIV_AB_given_A_value_FBH_and_B_value_12H_expect_values_A_divide_B_product_result_0D11H(void)

{



  uint8_t machineCode[] = {0x84};



  sfr[0xe0] = 0xfb;



  sfr[0xf0] = 0x12;



  (*(Status*)&sfr[0xd0]).CY = 1;



  (*(Status*)&sfr[0xd0]).OV = 1;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0211]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x0d)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(894), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x11)), (UNITY_INT)(UNITY_INT8 )((sfr[0xf0])), (

 ((void *)0)

 ), (UNITY_UINT)(895), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(896), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).OV)), (

 ((void *)0)

 ), (UNITY_UINT)(897), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0211 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(898), UNITY_DISPLAY_STYLE_HEX64);

}





void test_XRL_A_R2_given_R2_value_15H_and_A_value_24H_expect_value_of_R2_XOR_A(void)

{



  uint8_t machineCode[] = {0x6a};



  sfr[0xe0] = 0x24;



  sfr[0xd0] = 2 << 3;



  ram[0x12] = 0x15;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0001]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x31)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(917), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0001 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(918), UNITY_DISPLAY_STYLE_HEX64);

}





void test_XRL_A_12H_given_12H_value_15H_and_A_value_24H_expect_values_of_location_12H_XOR_A(void)

{



  uint8_t machineCode[] = {0x65, 0x12};



  sfr[0xe0] = 0x24;



  ram[0x12] = 0x15;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0002]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x31)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(935), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0002 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(936), UNITY_DISPLAY_STYLE_HEX64);

}





void test_XRL_A_hash15H_given_A_value_0x24_expect_value_of_A_XOR_hash15H(void)

{



  uint8_t machineCode[] = {0x64, 0x15};



  sfr[0xe0] = 0x24;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0003]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x31)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(951), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0003 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(952), UNITY_DISPLAY_STYLE_HEX64);

}





void test_XRL_A_addressR0_given_A_value_24H_and_addressR0_value_15H_expect_values_of_addressR0_XOR_A(void)

{



  uint8_t machineCode[] = {0x66};



  sfr[0xe0] = 0x24;



  ram[0xd6] = 0x15;

  sfr[0xd6] = 0;



  sfr[0xd0] = 2 << 3;



  ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (0)] = 0xd6;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0004]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x31)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(974), UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((UNITY_INT)((0xd6)), (UNITY_INT)((ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (0)])), (

 ((void *)0)

 ), (UNITY_UINT)(975), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0004 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(976), UNITY_DISPLAY_STYLE_HEX64);

}





void test_XRL_14H_A_given_A_value_15H_and_location_14H_value_24H_expect_values_A_XOR_location_14H(void)

{



  uint8_t machineCode[] = {0x62, 0x14};



  sfr[0xe0] = 0x15;



  ram[0x14] = 0x24;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0005]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x15)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(993), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x31)), (UNITY_INT)((ram[0x14])), (

 ((void *)0)

 ), (UNITY_UINT)(994), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0005 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(995), UNITY_DISPLAY_STYLE_HEX64);

}





void test_XRL_13H_hash15H_given_13H_value_24H_expect_value_of_location_13H_XOR_hash15H(void)

{



  uint8_t machineCode[] = {0x63,0x13,0x15};



  sfr[0xe0] = 0;



  ram[0x13] = 0x24;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0006]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x31)), (UNITY_INT)((ram[0x13])), (

 ((void *)0)

 ), (UNITY_UINT)(1012), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0006 + 3)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1013), UNITY_DISPLAY_STYLE_HEX64);

}





void test_ADD_A_R3_given_R3_value_4_and_A_value_126_expect_value_R3_add_A_equal_plus130(void)

{



  uint8_t machineCode[] = {0x2b};



  sfr[0xe0] = 126;



  sfr[0xd0] = 2 << 3;



  (*(Status*)&sfr[0xd0]).OV = 0;



  ram[0x13] = 4;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0500]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((130)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1034), UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).OV)), (

 ((void *)0)

 ), (UNITY_UINT)(1035), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0500 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1036), UNITY_DISPLAY_STYLE_HEX64);

}





void test_ADD_A_14H_given_A_value_plus126_and_14H_plus1_expect_value_of_location_14H_value_add_A_equal_plus127(void)

{



  uint8_t machineCode[] = {0x25, 0x14};



  sfr[0xe0] = 126;



  (*(Status*)&sfr[0xd0]).OV = 1;



  ram[0x14] = 1;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0501]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((127)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1055), UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).OV)), (

 ((void *)0)

 ), (UNITY_UINT)(1056), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0501 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1057), UNITY_DISPLAY_STYLE_HEX64);

}





void test_ADD_A_given_data_plus85_and_A_plus126_expect_data_add_A_equal_plus211(void)

{



  uint8_t machineCode[] = {0x24, 85};



  sfr[0xe0] = 126;



  (*(Status*)&sfr[0xd0]).OV = 0;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0502]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((211)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1074), UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).OV)), (

 ((void *)0)

 ), (UNITY_UINT)(1075), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0502 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1076), UNITY_DISPLAY_STYLE_HEX64);

}





void test_ADD_A_addressR0_given_addressR0_value_plus34_and_A_plus55_expect_addressR0_add_A_equal_89(void)

{



  uint8_t machineCode[] = {0x26};



  sfr[0xe0] = 55;



  (*(Status*)&sfr[0xd0]).OV = 1;



  ram[0xd4] = 34;

  sfr[0xd4] = 0;



  sfr[0xd0] = 2 << 3;



  ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (0)] = 0xd4;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0503]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((89)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1100), UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).OV)), (

 ((void *)0)

 ), (UNITY_UINT)(1101), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0xd4)), (UNITY_INT)((ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (0)])), (

 ((void *)0)

 ), (UNITY_UINT)(1102), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x503 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1103), UNITY_DISPLAY_STYLE_HEX64);

}





void test_ADDC_A_R4_given_A_value_C3H_R4_value_AAH_expect_values_A_plus_R4_where_CY_and_OV_set_1_AC_0_result_6EH_CY_1_OV_1_AC_0(void)

{



  uint8_t machineCode[] = {0x3c};



  sfr[0xe0] = 0xc3;



  (*(Status*)&sfr[0xd0]).CY = 1;



  (*(Status*)&sfr[0xd0]).OV = 0;



  (*(Status*)&sfr[0xd0]).AC = 0;



  sfr[0xd0] = 2 << 3;



  ram[0x14] = 0xaa;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0509]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x6e)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1128), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).AC)), (

 ((void *)0)

 ), (UNITY_UINT)(1129), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).OV)), (

 ((void *)0)

 ), (UNITY_UINT)(1130), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(1131), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0509 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1132), UNITY_DISPLAY_STYLE_HEX64);

}





void test_ADDC_A_R4_given_A_value_55H_R4_value_2H_expect_values_A_plus_R4_where_CY_0_AC_0_OV_0_result_57H(void)

{



  uint8_t machineCode[] = {0x3c};



  sfr[0xe0] = 0x55;



  (*(Status*)&sfr[0xd0]).CY = 0;



  (*(Status*)&sfr[0xd0]).OV = 0;



  (*(Status*)&sfr[0xd0]).AC = 0;



  sfr[0xd0] = 2 << 3;



  ram[0x14] = 0x02;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0510]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x57)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1157), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).AC)), (

 ((void *)0)

 ), (UNITY_UINT)(1158), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).OV)), (

 ((void *)0)

 ), (UNITY_UINT)(1159), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(1160), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0510 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1161), UNITY_DISPLAY_STYLE_HEX64);

}





void test_ADDC_A_11H_given_location11H_value_B2H_and_A_value_DDH_expect_values_A_plus_location11H_CY_1_OV_0_AC_0_result_90H_CY_1(void)

{



  uint8_t machineCode[] = {0x35, 0x11};



  sfr[0xe0] = 0xdd;



  ram[0x11] = 0xb2;



  (*(Status*)&sfr[0xd0]).CY = 1;



  (*(Status*)&sfr[0xd0]).OV = 0;



  (*(Status*)&sfr[0xd0]).AC = 0;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0511]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x90)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1184), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).AC)), (

 ((void *)0)

 ), (UNITY_UINT)(1185), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).OV)), (

 ((void *)0)

 ), (UNITY_UINT)(1186), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(1187), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0511 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1188), UNITY_DISPLAY_STYLE_HEX64);

}





void test_ADDC_A_hashCCH_given_A_value_77H_expect_values_A_plus_hashCCH_CY_1_OV_0_AC_0_result_44H_CY_1_AC_1(void)

{



  uint8_t machineCode[] = {0x34, 0xcc};



  sfr[0xe0] = 0x77;



  (*(Status*)&sfr[0xd0]).CY = 1;



  (*(Status*)&sfr[0xd0]).OV = 0;



  (*(Status*)&sfr[0xd0]).AC = 0;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0512]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x44)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1209), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).AC)), (

 ((void *)0)

 ), (UNITY_UINT)(1210), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).OV)), (

 ((void *)0)

 ), (UNITY_UINT)(1211), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(1212), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0512 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1213), UNITY_DISPLAY_STYLE_HEX64);

}





void test_ADDC_A_addressR1_given_addressR1_value_ADH_and_A_value_89H_expect_values_addressR1_plus_A_CY_1_OV_0_AC_0_result_37H_CY_1_OV_1_AC_1(void)

{



  uint8_t machineCode[] = {0x37};



  sfr[0xe0] = 0x89;



  ram[0xa5] = 0xad;

  sfr[0xa5] = 0;



  (*(Status*)&sfr[0xd0]).CY = 1;



  (*(Status*)&sfr[0xd0]).OV = 0;



  (*(Status*)&sfr[0xd0]).AC = 0;



  sfr[0xd0] = 2 << 3;



  ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (1)] = 0xa5;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0513]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x37)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1241), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).AC)), (

 ((void *)0)

 ), (UNITY_UINT)(1242), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).OV)), (

 ((void *)0)

 ), (UNITY_UINT)(1243), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(1244), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0xa5)), (UNITY_INT)((ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (1)])), (

 ((void *)0)

 ), (UNITY_UINT)(1245), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x513 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1246), UNITY_DISPLAY_STYLE_HEX64);

}

void test_SUBB_A_R2_given_R2_value_minus3_and_A_value_minus127_and_CY_0_expect_value_A_minus_CY_minus_R2_new_value_A_minus124(void)

{



  uint8_t machineCode[] = {0x9a};



  sfr[0xe0] = -127;



  sfr[0xd0] = 2 << 3;



  (*(Status*)&sfr[0xd0]).CY = 0;



  (*(Status*)&sfr[0xd0]).OV = 1;



  ram[0x12] = -3;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0504]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((-124)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1291), UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).OV)), (

 ((void *)0)

 ), (UNITY_UINT)(1292), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(1293), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0504 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1294), UNITY_DISPLAY_STYLE_HEX64);

}

void test_SUBB_A_R2_given_R3_value_40_and_A_value_minus110_and_CY_1_expect_value_A_minus_CY_minus_R3_new_value_A_minus151(void)

{



  uint8_t machineCode[] = {0x9b};



  sfr[0xe0] = -110;



  sfr[0xd0] = 2 << 3;



  (*(Status*)&sfr[0xd0]).CY = 1;



  (*(Status*)&sfr[0xd0]).OV = 0;



  ram[0x13] = 40;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0505]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((-151)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1324), UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).OV)), (

 ((void *)0)

 ), (UNITY_UINT)(1325), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(1326), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0505 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1327), UNITY_DISPLAY_STYLE_HEX64);

}





void test_SUBB_A_15H_given_15H_value_plus30_and_A_value_minus90_and_CY_1_expect_values_A_minus_CY_minus_location_15H_new_value_A_minus121(void)

{



  uint8_t machineCode[] = {0x95, 0x15};



  sfr[0xe0] = -90;



  (*(Status*)&sfr[0xd0]).CY = 1;



  (*(Status*)&sfr[0xd0]).OV = 1;



  ram[0x15] = 30;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0506]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((-121)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1348), UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).OV)), (

 ((void *)0)

 ), (UNITY_UINT)(1349), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(1350), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0506 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1351), UNITY_DISPLAY_STYLE_HEX64);

}





void test_SUBB_A_21_given_A_value_plus119_and_CY_1_expect_value_of_A_minus_CY_1_minus_21_new_value_A_plus97(void)

{



  uint8_t machineCode[] = {0x94, 21};



  sfr[0xe0] = 119;



  (*(Status*)&sfr[0xd0]).CY = 1;



  (*(Status*)&sfr[0xd0]).OV = 1;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0507]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((97)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1370), UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).OV)), (

 ((void *)0)

 ), (UNITY_UINT)(1371), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(1372), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0507 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1373), UNITY_DISPLAY_STYLE_HEX64);

}





void test_SUBB_A_addressR0_given_addressR0_value_plus126_and_A_value_minus40_CY_1_expect_value_of_A_minus_CY_1_minus_addressR0_new_value_minus167(void)

{



  uint8_t machineCode[] = {0x96};



  sfr[0xe0] = -40;



  (*(Status*)&sfr[0xd0]).CY = 1;



  (*(Status*)&sfr[0xd0]).OV = 0;



  ram[0xd5] = 126;

  sfr[0xd5] = 0;



  sfr[0xd0] = 2 << 3;



  ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (0)] = 0xd5;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0508]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).OV)), (

 ((void *)0)

 ), (UNITY_UINT)(1399), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(1400), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0xd5)), (UNITY_INT)((ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (0)])), (

 ((void *)0)

 ), (UNITY_UINT)(1401), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x508 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1402), UNITY_DISPLAY_STYLE_HEX64);

}





void test_ANL_A_R3_given_R3_55H_and_A_C3H_expect_values_R3_logicalAND_A(void)

{



  uint8_t machineCode[] = {0x5b};



  sfr[0xe0] = 0xc3;



  sfr[0xd0] = 2 << 3;



  ram[0x13] = 0x55;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0600]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x41)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1421), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT64)((0x0600 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1422), UNITY_DISPLAY_STYLE_HEX64);

}





void test_ANL_A_14H_given_A_4FH_and_location_14H_value_62H_expect_values_location_14H_logicalAND_A(void)

{



  uint8_t machineCode[] = {0x55, 0x14};



  sfr[0xe0] = 0x4f;



  ram[0x14] = 0x62;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0601]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x42)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1439), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT64)((0x0601 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1440), UNITY_DISPLAY_STYLE_HEX64);

}





void test_ANL_A_hash3AH_given_data_hash3AH_and_A_value_C3H_expect_values_hash3AH_logicalAND_A(void)

{



  uint8_t machineCode[] = {0x54, 0x3a};



  sfr[0xe0] = 0x6e;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0602]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x2a)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1455), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT64)((0x0602 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1456), UNITY_DISPLAY_STYLE_HEX64);

}





void test_ANL_A_addressR0_given_addressR0_value_63H_and_A_value_21H_expect_values_of_addressR0_logicalAND_A(void)

{



  uint8_t machineCode[] = {0x56};



  sfr[0xe0] = 0x21;



  ram[0xe4] = 0x63;

  sfr[0xe4] = 0;



  sfr[0xd0] = 2 << 3;



  ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (0)] = 0xe4;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0603]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x21)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1478), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT)((0xe4)), (UNITY_INT)((ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (0)])), (

 ((void *)0)

 ), (UNITY_UINT)(1479), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x603 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1480), UNITY_DISPLAY_STYLE_HEX64);

}



void test_1CH_A_given_A_value_65H_and_location_1CH_79H_expect_values_A_logicalAND_location_1CH(void)

{



  uint8_t machineCode[] = {0x52, 0x1c};



  sfr[0xe0] = 0x65;



  ram[0x1c] = 0x79;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0604]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x61)), (UNITY_INT)(UNITY_INT8 )((ram[0x1c])), (

 ((void *)0)

 ), (UNITY_UINT)(1496), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT64)((0x0604 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1497), UNITY_DISPLAY_STYLE_HEX64);

}





void test_1DH_hash55H_given_1DH_value_C3H_expect_hash55H_logicalAND_location_1DH(void)

{



  uint8_t machineCode[] = {0x53, 0x1d, 0x63};



  sfr[0xe0] = 0;



  ram[0x1d] = 0x21;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0605]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x21)), (UNITY_INT)(UNITY_INT8 )((ram[0x1d])), (

 ((void *)0)

 ), (UNITY_UINT)(1514), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT64)((0x0605 + 3)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1515), UNITY_DISPLAY_STYLE_HEX64);

}





void test_ORL_A_R5_given_R5_value_44H_and_A_value_56H_expect_values_R5_logicalOR_A(void)

{



  uint8_t machineCode[] = {0x4d};



  sfr[0xe0] = 0x56;



  sfr[0xd0] = 2 << 3;



  ram[0x15] = 0x44;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0700]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x56)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1534), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT64)((0x0700 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1535), UNITY_DISPLAY_STYLE_HEX64);

}





void test_ORL_A_16H_given_location_16H_value_AAH_and_A_value_74H_expect_values_of_location_16H_logicalOR_A(void)

{



  uint8_t machineCode[] = {0x45, 0x16};



  sfr[0xe0] = 0x74;



  ram[0x16] = 0xaa;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0701]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0xfe)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1552), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT64)((0x0701 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1553), UNITY_DISPLAY_STYLE_HEX64);

}





void test_ORL_A_hash88H_given_A_value_C3H_expect_value_hash88H_logicalOR_A(void)

{



  uint8_t machineCode[] = {0x44, 0x88};



  sfr[0xe0] = 0x99;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0702]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x99)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1568), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT64)((0x0702 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1569), UNITY_DISPLAY_STYLE_HEX64);

}





void test_ORL_A_addressR0_given_addressR0_value_55H_and_A_value_27H_expect_values_of_addressR0_logicalOR_A(void)

{



  uint8_t machineCode[] = {0x46};



  sfr[0xe0] = 0x27;



  ram[0xe8] = 0x77;

  sfr[0xe8] = 0;



  sfr[0xd0] = 2 << 3;



  ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (0)] = 0xe8;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0703]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x77)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1591), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT)((0xe8)), (UNITY_INT)((ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (0)])), (

 ((void *)0)

 ), (UNITY_UINT)(1592), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x703 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1593), UNITY_DISPLAY_STYLE_HEX64);

}





void test_1AH_A_given_A_value_10H_and_location_1AH_5BH_expect_values_A_logicalOR_location_1CH(void)

{



  uint8_t machineCode[] = {0x42, 0x1a};



  sfr[0xe0] = 0x10;



  ram[0x1a] = 0x5b;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0704]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x5b)), (UNITY_INT)(UNITY_INT8 )((ram[0x1a])), (

 ((void *)0)

 ), (UNITY_UINT)(1610), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT64)((0x0704 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1611), UNITY_DISPLAY_STYLE_HEX64);

}





void test_11H_hashFBH_given_location_11H_value_ACH_expect_hashFBH_logicalOR_location_11H(void)

{



  uint8_t machineCode[] = {0x43, 0x11, 0xfb};



  sfr[0xe0] = 0;



  ram[0x11] = 0xac;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0705]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0xff)), (UNITY_INT)(UNITY_INT8 )((ram[0x11])), (

 ((void *)0)

 ), (UNITY_UINT)(1628), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT64)((0x0705 + 3)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1629), UNITY_DISPLAY_STYLE_HEX64);

}





void test_SJMP_70_expect_relative_address_jump_to_2003H(void)

{



  uint8_t machineCode[] = {0x80, 70};



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x2003]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x2003 + 70 + 2)), (UNITY_INT)(UNITY_UINT16)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1642), UNITY_DISPLAY_STYLE_UINT16);

}





void test_SJMP_minus60_expect_relative_address_jump_to_2003H(void)

{



  uint8_t machineCode[] = {0x80, -60};



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x2004]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x2004 + (-60) + 2)), (UNITY_INT)(UNITY_UINT16)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1655), UNITY_DISPLAY_STYLE_UINT16);

}





void test_LJMP_1234H_expect_1234H_LJMP_to_location_23H(void)

{



  uint8_t machineCode[] = {0x10, 0x12, 0x34};



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x2005]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x1234)), (UNITY_INT)(UNITY_UINT16)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1668), UNITY_DISPLAY_STYLE_UINT16);

}





void test_JZ_10_expect_not_JMP_when_acc_is_not_0(void)

{



  uint8_t machineCode[] = {0x60, 10};



  sfr[0xe0] = 0x01;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x2006]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1682), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x2006 + 2)), (UNITY_INT)(UNITY_UINT16)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1683), UNITY_DISPLAY_STYLE_UINT16);

}





void test_JZ_10_expect_JMP_when_acc_is_0(void)

{



  uint8_t machineCode[] = {0x60, 10};



  sfr[0xe0] = 0x00;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x2007]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1697), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x2007 + 10 + 2)), (UNITY_INT)(UNITY_UINT16)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1698), UNITY_DISPLAY_STYLE_UINT16);

}





void test_JNZ_40_expect_no_JMP_when_acc_is_not_zero(void)

{



  uint8_t machineCode[] = {0x70, 40};



  sfr[0xe0] = 0x00;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x2008]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1712), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x2008 + 2)), (UNITY_INT)(UNITY_UINT16)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1713), UNITY_DISPLAY_STYLE_UINT16);

}





void test_JNZ_40_expect_JMP_when_acc_is_not_zero(void)

{



  uint8_t machineCode[] = {0x70, 40};



  sfr[0xe0] = 0x23;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x2009]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();

  UnityAssertEqualNumber((UNITY_INT)((0x23)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1727), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x2009 + 40 + 2)), (UNITY_INT)(UNITY_UINT16)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1728), UNITY_DISPLAY_STYLE_UINT16);

}





void test_JNC_30_expect_no_JMP_when_carry_is_set(void)

{



  uint8_t machineCode[] = {0x50, 30};



  (*(Status*)&sfr[0xd0]).CY = 1;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x2010]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(1742), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x2010 + 2)), (UNITY_INT)(UNITY_UINT16)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1743), UNITY_DISPLAY_STYLE_UINT16);

}





void test_JNC_30_expect_JMP_when_carry_is_not_set(void)

{



  uint8_t machineCode[] = {0x50, 30};



  (*(Status*)&sfr[0xd0]).CY = 0;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x2011]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(1757), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x2011 + 30 + 2)), (UNITY_INT)(UNITY_UINT16)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1758), UNITY_DISPLAY_STYLE_UINT16);

}





void test_JNC_44_expect_JMP_when_carry_is_set(void)

{



  uint8_t machineCode[] = {0x40, 44};



  (*(Status*)&sfr[0xd0]).CY = 1;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x2012]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(1772), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x2012 + 44 + 2)), (UNITY_INT)(UNITY_UINT16)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1773), UNITY_DISPLAY_STYLE_UINT16);

}





void test_JNC_44_expect_not_JMP_when_carry_is_not_set(void)

{



  uint8_t machineCode[] = {0x40, 44};



  (*(Status*)&sfr[0xd0]).CY = 0;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x2012]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(1787), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x2012 + 2)), (UNITY_INT)(UNITY_UINT16)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1788), UNITY_DISPLAY_STYLE_UINT16);

}





void test_DA_A_given_A_value_34H_and_data_37H_expect_value_A_plus_data_37H_is_71H(void)

{



  uint8_t machineCode[] = {0x24,0x37,

                           0xd4};



  sfr[0xe0] = 0x34;



  (*(Status*)&sfr[0xd0]).AC = 0;



  (*(Status*)&sfr[0xd0]).CY = 0;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x5000]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();

  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x71)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1809), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).AC)), (

 ((void *)0)

 ), (UNITY_UINT)(1810), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(1811), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x5000 + 3)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1812), UNITY_DISPLAY_STYLE_HEX64);

}





void test_DA_A_given_A_value_28H_and_data_29H_expect_value_A_plus_data_29H_is_57H(void)

{



  uint8_t machineCode[] = {0x24,0x29,

                           0xd4};



  sfr[0xe0] = 0x28;



  (*(Status*)&sfr[0xd0]).AC = 1;



  (*(Status*)&sfr[0xd0]).CY = 0;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x5001]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();

  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x57)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1833), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).AC)), (

 ((void *)0)

 ), (UNITY_UINT)(1834), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(1835), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x5001 + 3)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1836), UNITY_DISPLAY_STYLE_HEX64);

}





void test_DA_A_given_A_value_44H_and_data_64H_expect_value_A_plus_data_64H_is_108H(void)

{



  uint8_t machineCode[] = {0x24,0x64,

                           0xd4};



  sfr[0xe0] = 0x44;



  (*(Status*)&sfr[0xd0]).AC = 0;



  (*(Status*)&sfr[0xd0]).CY = 1;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x5002]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();

  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x108)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1857), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).AC)), (

 ((void *)0)

 ), (UNITY_UINT)(1858), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(1859), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x5002 + 3)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1860), UNITY_DISPLAY_STYLE_HEX64);

}





void test_DA_A_given_A_value_49H_and_data_68H_expect_value_A_plus_data_68H_is_117H(void)

{



  uint8_t machineCode[] = {0x24,0x68,

                           0xd4};



  sfr[0xe0] = 0x49;



  (*(Status*)&sfr[0xd0]).AC = 1;



  (*(Status*)&sfr[0xd0]).CY = 1;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x5003]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();

  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x117)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(1881), UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).AC)), (

 ((void *)0)

 ), (UNITY_UINT)(1882), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(1883), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x5003 + 3)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(1884), UNITY_DISPLAY_STYLE_HEX64);

}
