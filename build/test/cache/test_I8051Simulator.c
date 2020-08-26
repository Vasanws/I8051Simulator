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





  writeToMemory(0xfa, DIRECT_ADDRESSING, 0x76);



  UnityAssertEqualNumber((UNITY_INT)((0x76)), (UNITY_INT)((sfr[0xfa])), (

 ((void *)0)

 ), (UNITY_UINT)(22), UNITY_DISPLAY_STYLE_INT);



}

void test_condition_for_address_0x9b_to_INDIRECT_ADDRESSING_contains_data_0x69_expect_address_0x9b_points_to_data_0x69_at_SRAM_INDIRECT_ADDRESSING(void)

{



  ram[0x9b] = 0;





  writeToMemory(0x9b, INDIRECT_ADDRESSING, 0x69);



  UnityAssertEqualNumber((UNITY_INT)((0x69)), (UNITY_INT)((ram[0x9b])), (

 ((void *)0)

 ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_INT);

}

void test_condition_for_address_0x11_to_DIRECT_ADDRESSING_contains_data_0x43_expect_address_0x11_points_to_data_0x43_at_RAM_DIRECT_ADDRESSING(void)

{



  ram[0x11] = 0;





  writeToMemory(0x11, DIRECT_ADDRESSING, 0x43);



  UnityAssertEqualNumber((UNITY_INT)((0x43)), (UNITY_INT)((ram[0x11])), (

 ((void *)0)

 ), (UNITY_UINT)(43), UNITY_DISPLAY_STYLE_INT);

}

void test_condition_for_address_0x7e_to_INDIRECT_ADDRESSING_contains_data_0x55_expect_address_0x7e_points_to_data_0x55_at_RAM_INDIRECT_ADDRESSING(void)

{



  ram[0x7e] = 0;





  writeToMemory(0x7e, DIRECT_ADDRESSING, 0x55);



  UnityAssertEqualNumber((UNITY_INT)((0x55)), (UNITY_INT)((ram[0x7e])), (

 ((void *)0)

 ), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_INT);

}





void test_condition_for_address_0xff_read_mode_DIRECT_ADDRESSING_of_SFR_expect_to_read_address_0xff_from_SFR_DIRECT_ADDRESSING(void)

{

  int dataRead = 0;



  sfr[0xff] = 0x98;

  ram[0xff] = 0;





  dataRead = readFromMemory(0xff, DIRECT_ADDRESSING);



  UnityAssertEqualNumber((UNITY_INT)((0x98)), (UNITY_INT)((dataRead)), (

 ((void *)0)

 ), (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_INT);

}



void test_condition_for_address_0x88_read_mode_INDIRECT_ADDRESSING_of_SRAM_expect_to_read_address_0x88_from_SRAM_INDIRECT_ADDRESSING(void)

{

  int dataRead = 0;



  ram[0x88] = 0x64;

  sfr[0x88] = 0;





  dataRead = readFromMemory(0x88, INDIRECT_ADDRESSING);



  UnityAssertEqualNumber((UNITY_INT)((0x64)), (UNITY_INT)((dataRead)), (

 ((void *)0)

 ), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_INT);

}



void test_condition_for_address_0x42_read_mode_DIRECT_ADDRESSING_of_RAM_expect_to_read_address_0x42_from_RAM_DIRECT_ADDRESSING(void)

{

  int dataRead = 0;



  ram[0x42] = 0x71;





  dataRead = readFromMemory(0x42, DIRECT_ADDRESSING);



  UnityAssertEqualNumber((UNITY_INT)((0x71)), (UNITY_INT)((dataRead)), (

 ((void *)0)

 ), (UNITY_UINT)(92), UNITY_DISPLAY_STYLE_INT);

}



void test_condition_for_address_0x38_read_mode_INDIRECT_ADDRESSING_of_RAM_expect_to_read_address_0x38_from_RAM_INDIRECT_ADDRESSING(void)

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

   ), (UNITY_UINT)(168), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x25)), (UNITY_INT)((sfr[0xe0])), (

   ((void *)0)

   ), (UNITY_UINT)(169), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT64)((0x167A + 1)), (UNITY_INT64)((pc)), (

   ((void *)0)

   ), (UNITY_UINT)(170), UNITY_DISPLAY_STYLE_HEX64);

}





void test_mov_given_value_1CH_location_0FH_expect_MOV_0FH_value_direct_to_acc(void)

{



  uint8_t machineCode[] = {0xe5,0x0f};



  sfr[0xe0] = 0;



  ram[0x0f] = 0x1c;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x145C]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x1c)), (UNITY_INT)((ram[0x0f])), (

 ((void *)0)

 ), (UNITY_UINT)(187), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x1c)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(188), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x145C + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(189), UNITY_DISPLAY_STYLE_HEX64);

}





void test_mov_given_address_of_R1_value_21H_expect_address_of_R1_value_21H_to_acc(void)

{



    uint8_t machineCode[] = {0xe7};



    sfr[0xe0] = 0;



    ram[0x89] = 0x21;

    sfr[0x89] = 0;



    sfr[0xd0] = 1 << 3;



    ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (1)] = 0x89;



    do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x1200]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



    executeInstruction();



    UnityAssertEqualNumber((UNITY_INT)((0x21)), (UNITY_INT)((sfr[0xe0])), (

   ((void *)0)

   ), (UNITY_UINT)(211), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x89)), (UNITY_INT)((ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (1)])), (

   ((void *)0)

   ), (UNITY_UINT)(212), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT64)((0x1200 + 1)), (UNITY_INT64)((pc)), (

   ((void *)0)

   ), (UNITY_UINT)(213), UNITY_DISPLAY_STYLE_HEX64);

}





void test_mov_A_hash22H_given_22H_to_acc_expect_22H_direct_to_acc(void)

{



    uint8_t machineCode[] = {0x74, 0x22};



    sfr[0xe0] = 0x00;



    do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x1100]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



    executeInstruction();



    UnityAssertEqualNumber((UNITY_INT)((0x22)), (UNITY_INT)((sfr[0xe0])), (

   ((void *)0)

   ), (UNITY_UINT)(228), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT64)((0x1100 + 2)), (UNITY_INT64)((pc)), (

   ((void *)0)

   ), (UNITY_UINT)(229), UNITY_DISPLAY_STYLE_HEX64);

}





void test_mov_R3_A_given_99H_in_acc_expect_99H_from_A_to_R3(void)

{



    uint8_t machineCode[] = {0xfb};



    sfr[0xe0] = 0x99;



    sfr[0xd0] = 2 << 3;



    ram[0x13] = 0;



    do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x66A]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



    executeInstruction();



    UnityAssertEqualNumber((UNITY_INT)((0x99)), (UNITY_INT)((ram[0x13])), (

   ((void *)0)

   ), (UNITY_UINT)(248), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x99)), (UNITY_INT)((sfr[0xe0])), (

   ((void *)0)

   ), (UNITY_UINT)(249), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT64)((0x66A + 1)), (UNITY_INT64)((pc)), (

   ((void *)0)

   ), (UNITY_UINT)(250), UNITY_DISPLAY_STYLE_HEX64);

}





void test_mov_R4_04H_given_44H_in_address_04H_expect_44H_from_04H_to_R4(void)

{



    uint8_t machineCode[] = {0xac,0x04};



    sfr[0xe0] = 0;



    sfr[0xd0] = 1 << 3;



    ram[0x0c] = 0;



    ram[0x04] = 0x44;



    do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x66A]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



    executeInstruction();



    UnityAssertEqualNumber((UNITY_INT)((0x44)), (UNITY_INT)((ram[0x0c])), (

   ((void *)0)

   ), (UNITY_UINT)(271), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

   ((void *)0)

   ), (UNITY_UINT)(272), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT64)((0x66A + 2)), (UNITY_INT64)((pc)), (

   ((void *)0)

   ), (UNITY_UINT)(273), UNITY_DISPLAY_STYLE_HEX64);

}





void test_mov_R6_hash77H_expect_hash77H_to_R6(void)

{



    uint8_t machineCode[] = {0x7e,0x77};



    sfr[0xe0] = 0;



    sfr[0xd0] = 2 << 3;



    ram[0x16] = 0;



    do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x66A]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



    executeInstruction();



    UnityAssertEqualNumber((UNITY_INT)((0x77)), (UNITY_INT)((ram[0x16])), (

   ((void *)0)

   ), (UNITY_UINT)(292), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

   ((void *)0)

   ), (UNITY_UINT)(293), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT64)((0x66A + 2)), (UNITY_INT64)((pc)), (

   ((void *)0)

   ), (UNITY_UINT)(294), UNITY_DISPLAY_STYLE_HEX64);

}





void test_mov_address_of_10H_A_expect_value_of_A_54H_direct_to_address_10H(void)

{



    uint8_t machineCode[] = {0xf5,0x10};



    sfr[0xe0] = 0x54;



    ram[0x10] = 0;



    do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x66A]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



    executeInstruction();



    UnityAssertEqualNumber((UNITY_INT)((0x54)), (UNITY_INT)((ram[0x10])), (

   ((void *)0)

   ), (UNITY_UINT)(311), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT64)((0x66A + 2)), (UNITY_INT64)((pc)), (

   ((void *)0)

   ), (UNITY_UINT)(312), UNITY_DISPLAY_STYLE_HEX64);

}



void test_given_value_22H_to_acc_expect_CLR_value_in_acc(void)

{



  uint8_t machineCode[] = {0xe4};



  sfr[0xe0] = 0x22;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0980]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x00)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(326), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0980 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(327), UNITY_DISPLAY_STYLE_HEX64);

}





void test_given_value_to_acc_value_7CH_expect_value_to_increment_plus1_to_7DH(void)

{



  uint8_t machineCode[] = {0x04};



  sfr[0xe0] = 0x7c;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0999]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x7d)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(342), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x999 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(343), UNITY_DISPLAY_STYLE_HEX64);

}





void test_given_value_to_acc_value_65H_expect_value_to_decrement_MINUS1_to_64H(void)

{



  uint8_t machineCode[] = {0x14};



  sfr[0xe0] = 0x65;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0799]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x64)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(358), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x799 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(359), UNITY_DISPLAY_STYLE_HEX64);

}





void test_given_value_45H_to_R6_bank3_expect_value_to_increment_to_46H_in_R6(void)

{



  uint8_t machineCode[] = {0x0e};



  sfr[0xe0] = 0;



  sfr[0xd0] = 3 << 3;



  ram[0x1e] = 0x45;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x7806]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(378), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x46)), (UNITY_INT)((ram[0x1e])), (

 ((void *)0)

 ), (UNITY_UINT)(379), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x7806 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(380), UNITY_DISPLAY_STYLE_HEX64);

}





void test_given_value_66H_to_R5_bank1_expect_value_to_increment_to_67H_in_R5(void)

{



  uint8_t machineCode[] = {0x0d};



  sfr[0xe0] = 0;



  sfr[0xd0] = 1 << 3;



  ram[0x0d] = 0x66;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x7817]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(399), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x67)), (UNITY_INT)((ram[0x0d])), (

 ((void *)0)

 ), (UNITY_UINT)(400), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x7817 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(401), UNITY_DISPLAY_STYLE_HEX64);

}





void test_NOP_to_skip_expect_NOP_to_skip_or_do_(void)

{



  uint8_t machineCode[] = {0x00};



  sfr[0xe0] = 0;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x567]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(416), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x567 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(417), UNITY_DISPLAY_STYLE_HEX64);

}





void test_SWAP_A_give_value_6BH_expect_SWAP_A_B6H_in_acc(void)

{



  uint8_t machineCode[] = {0xc4};



  sfr[0xe0] = 0x6b;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x324]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0xb6)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(432), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x324 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(433), UNITY_DISPLAY_STYLE_HEX64);

}

void test_given_value_23H_to_acc_expect_23H_complement_become_DCH_in_acc(void)

{



  uint8_t machineCode[] = {0xf4};



  sfr[0xe0] = 0x23;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x222]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0xdc)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(457), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x222 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(458), UNITY_DISPLAY_STYLE_HEX64);

}
