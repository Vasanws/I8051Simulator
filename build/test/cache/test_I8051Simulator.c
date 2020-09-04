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





void test_mov_12H_A_expect_value_of_A_hash54H_direct_to_location_12H(void)

{



    uint8_t machineCode[] = {0xf5,0x12};



    sfr[0xe0] = 0x54;



    ram[0x12] = 0;



    do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x2222]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



    executeInstruction();



    UnityAssertEqualNumber((UNITY_INT)((0x54)), (UNITY_INT)((sfr[0xe0])), (

   ((void *)0)

   ), (UNITY_UINT)(311), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x54)), (UNITY_INT)((ram[0x12])), (

   ((void *)0)

   ), (UNITY_UINT)(312), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT64)((0x2222 + 2)), (UNITY_INT64)((pc)), (

   ((void *)0)

   ), (UNITY_UINT)(313), UNITY_DISPLAY_STYLE_HEX64);

}





void test_mov_11H_R5_expect_R5_move_to_location_11H(void)

{



   uint8_t machineCode[] = {0x8d,0x11};



   sfr[0xe0] = 0;



   sfr[0xd0] = 1 << 3;



   ram[0x0d] = 0x66;



   do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x2234]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



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

   UnityAssertEqualNumber((UNITY_INT64)((0x2234 + 2)), (UNITY_INT64)((pc)), (

  ((void *)0)

  ), (UNITY_UINT)(335), UNITY_DISPLAY_STYLE_HEX64);

}





void test_mov_18H_1AH_expect_location_of_1AH_move_to_location_18H(void)

{



  uint8_t machineCode[] = {0x85, 0x1a, 0x18};



  sfr[0xe0] = 0;



  ram[0x1a] = 0x56;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x2534]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(352), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x56)), (UNITY_INT)((ram[0x18])), (

 ((void *)0)

 ), (UNITY_UINT)(353), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x2534 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(354), UNITY_DISPLAY_STYLE_HEX64);

}





void test_mov_1BH_addressR1_expect_addressR1_mov_to_location_1BH(void)

{



    uint8_t machineCode[] = {0x87,0x1b};



    sfr[0xe0] = 0;



    ram[0x87] = 0x22;

    sfr[0x87] = 0;



    sfr[0xd0] = 1 << 3;



    ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (1)] = 0x87;



    do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x1299]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



    executeInstruction();



    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

   ((void *)0)

   ), (UNITY_UINT)(376), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x87)), (UNITY_INT)((ram[((sfr[0xd0] >> 3) & 0x03) * 8 + (1)])), (

   ((void *)0)

   ), (UNITY_UINT)(377), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT64)((0x1299 + 2)), (UNITY_INT64)((pc)), (

   ((void *)0)

   ), (UNITY_UINT)(378), UNITY_DISPLAY_STYLE_HEX64);

}





void test_mov_10H_hash91_expect_hash91_move_to_location_10H(void)

{



  uint8_t machineCode[] = {0x75, 0x10, 0x91};



  sfr[0xe0] = 0;



  ram[0x10] = 0x91;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x2034]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(395), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x91)), (UNITY_INT)((ram[0x10])), (

 ((void *)0)

 ), (UNITY_UINT)(396), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x2034 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(397), UNITY_DISPLAY_STYLE_HEX64);

}

void test_MOV_DPTR_hash1234_given_hash1234_expect_DPH_hold_hash12H_DPL_hold_hash34H()

{



  uint8_t machineCode[] = {0x90, 0x12, 0x34};



  sfr[0xe0] = 0;



  sfr[0x83] = 0;

  sfr[0x82] = 0;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x987]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x12)), (UNITY_INT)(UNITY_INT8 )((sfr[0x83])), (

 ((void *)0)

 ), (UNITY_UINT)(439), UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x34)), (UNITY_INT)(UNITY_INT8 )((sfr[0x82])), (

 ((void *)0)

 ), (UNITY_UINT)(440), UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((UNITY_INT64)((0)), (UNITY_INT64)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(441), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((0x987 + 3)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(442), UNITY_DISPLAY_STYLE_HEX64);

}



void test_given_value_22H_to_acc_expect_CLR_value_in_acc(void)

{



  uint8_t machineCode[] = {0xe4};



  sfr[0xe0] = 0x22;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0980]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x00)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(456), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0980 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(457), UNITY_DISPLAY_STYLE_HEX64);

}





void test_given_value_to_acc_value_7CH_expect_value_to_increment_plus1_to_7DH(void)

{



  uint8_t machineCode[] = {0x04};



  sfr[0xe0] = 0x7c;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0999]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x7d)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(472), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x999 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(473), UNITY_DISPLAY_STYLE_HEX64);

}





void test_INC_R6_expected_value_in_R6_inc(void)

{



  uint8_t machineCode[] = {0x0e};



  sfr[0xe0] = 0;



  sfr[0xd0] = 3 << 3;



  ram[0x1e] = 0x45;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x7806]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(492), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x46)), (UNITY_INT)((ram[0x1e])), (

 ((void *)0)

 ), (UNITY_UINT)(493), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x7806 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(494), UNITY_DISPLAY_STYLE_HEX64);

}





void test_INC_17H_expected_hash45_increment_to_hash46_in_location_17H(void)

{



  uint8_t machineCode[] = {0x05, 0x17};



  sfr[0xe0] = 0;



  ram[0x17] = 0x45;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x7816]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(511), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x46)), (UNITY_INT)((ram[0x17])), (

 ((void *)0)

 ), (UNITY_UINT)(512), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x7816 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(513), UNITY_DISPLAY_STYLE_HEX64);

}

void test_given_value_to_acc_value_65H_expect_value_to_decrement_MINUS1_to_64H(void)

{



  uint8_t machineCode[] = {0x14};



  sfr[0xe0] = 0x65;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0799]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x64)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(552), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x799 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(553), UNITY_DISPLAY_STYLE_HEX64);

}





void test_DEC_R5_expected_value_in_R5_decrement(void)

{



  uint8_t machineCode[] = {0x1d};



  sfr[0xe0] = 0;



  sfr[0xd0] = 2 << 3;



  ram[0x15] = 0x55;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x0789]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(572), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x54)), (UNITY_INT)((ram[0x15])), (

 ((void *)0)

 ), (UNITY_UINT)(573), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x0789 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(574), UNITY_DISPLAY_STYLE_HEX64);

}





void test_INC_16H_expected_hash44_decrement_to_hash43_in_location_16H(void)

{



  uint8_t machineCode[] = {0x15, 0x16};



  sfr[0xe0] = 0;



  ram[0x16] = 0x44;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x7811]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(591), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x43)), (UNITY_INT)((ram[0x16])), (

 ((void *)0)

 ), (UNITY_UINT)(592), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x7811 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(593), UNITY_DISPLAY_STYLE_HEX64);

}





void test_NOP_to_skip_expect_NOP_to_skip_or_do_(void)

{



  uint8_t machineCode[] = {0x00};



  sfr[0xe0] = 0;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x567]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(608), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x567 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(609), UNITY_DISPLAY_STYLE_HEX64);

}





void test_SWAP_A_give_value_6BH_expect_SWAP_A_B6H_in_acc(void)

{



  uint8_t machineCode[] = {0xc4};



  sfr[0xe0] = 0x6b;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x324]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0xb6)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(624), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x324 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(625), UNITY_DISPLAY_STYLE_HEX64);

}

void test_given_value_23H_to_acc_expect_23H_complement_become_DCH_in_acc(void)

{



  uint8_t machineCode[] = {0xf4};



  sfr[0xe0] = 0x23;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x222]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0xdc)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(649), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x222 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(650), UNITY_DISPLAY_STYLE_HEX64);

}





void test_XRL_Acc_R2_expect_R2_XRL_Acc(void)

{



  uint8_t machineCode[] = {0x6a};



  sfr[0xe0] = 0x24;



  sfr[0xd0] = 2 << 3;



  ram[0x12] = 0x15;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x111]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)((0x31)), (UNITY_INT)((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(669), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x111 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(670), UNITY_DISPLAY_STYLE_HEX64);

}





void test_add_Acc_R3_expect_R3_value_add_to_Acc(void)

{



  uint8_t machineCode[] = {0x2b};



  sfr[0xe0] = 126;



  sfr[0xd0] = 2 << 3;



  (*(Status*)&sfr[0xd0]).OV = 0;



  ram[0x13] = 4;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x123]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((130)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(691), UNITY_DISPLAY_STYLE_INT8);





  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).OV)), (

 ((void *)0)

 ), (UNITY_UINT)(694), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x123 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(695), UNITY_DISPLAY_STYLE_HEX64);

}





void test_ADD_A_14H_given_A_plus126_and_14H_plus1_expect_14H_value_add_to_Acc_value_plus127(void)

{



  uint8_t machineCode[] = {0x25, 0x14};



  sfr[0xe0] = 126;



  (*(Status*)&sfr[0xd0]).OV = 1;



  ram[0x14] = 1;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x124]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((127)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(714), UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).OV)), (

 ((void *)0)

 ), (UNITY_UINT)(715), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x124 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(716), UNITY_DISPLAY_STYLE_HEX64);

}





void test_ADD_A_hash55_given_A_plus126_and_85_expect_85_add_Acc_value_181_with_overflow(void)

{



  uint8_t machineCode[] = {0x24, 85};



  sfr[0xe0] = 126;



  (*(Status*)&sfr[0xd0]).OV = 0;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x125]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((211)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(733), UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).OV)), (

 ((void *)0)

 ), (UNITY_UINT)(734), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x125 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(735), UNITY_DISPLAY_STYLE_HEX64);

}

void test_SUBB_A_R2_expect_R2_value_minus_to_Acc(void)

{



  uint8_t machineCode[] = {0x9a};



  sfr[0xe0] = -127;



  sfr[0xd0] = 2 << 3;



  (*(Status*)&sfr[0xd0]).CY = 0;



  (*(Status*)&sfr[0xd0]).OV = 1;



  ram[0x12] = -3;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x130]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((-124)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(779), UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).OV)), (

 ((void *)0)

 ), (UNITY_UINT)(780), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(781), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x130 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(782), UNITY_DISPLAY_STYLE_HEX64);

}

void test_SUBB_A_R2_given_A_minus110_R2_40_CY_1_expect_minus151_in_Acc(void)

{



  uint8_t machineCode[] = {0x9a};



  sfr[0xe0] = -110;



  sfr[0xd0] = 2 << 3;



  (*(Status*)&sfr[0xd0]).CY = 1;



  (*(Status*)&sfr[0xd0]).OV = 0;



  ram[0x12] = 40;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x131]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((-151)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(813), UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).OV)), (

 ((void *)0)

 ), (UNITY_UINT)(814), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(815), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x131 + 1)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(816), UNITY_DISPLAY_STYLE_HEX64);

}





void test_SUBB_A_15H_given_A_minus90_location_15H_30_CY_1_expect_minus121_in_Acc(void)

{



  uint8_t machineCode[] = {0x95, 0x15};



  sfr[0xe0] = -90;



  (*(Status*)&sfr[0xd0]).CY = 1;



  (*(Status*)&sfr[0xd0]).OV = 1;



  ram[0x15] = 30;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x132]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((-121)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(837), UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).OV)), (

 ((void *)0)

 ), (UNITY_UINT)(838), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(839), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x132 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(840), UNITY_DISPLAY_STYLE_HEX64);

}





void test_SUBB_A_given_A_119_minus_21_CY_1_OV_1_expect_98_in_Acc(void)

{



  uint8_t machineCode[] = {0x94, 21};



  sfr[0xe0] = 119;



  (*(Status*)&sfr[0xd0]).CY = 1;



  (*(Status*)&sfr[0xd0]).OV = 1;



  do{ int i; unsigned char *dst = (unsigned char *)&codeMemory[pc = 0x133]; for(i = 0; i < sizeof(machineCode); i++){ dst[i] = (machineCode)[i]; } }while(0);



  executeInstruction();



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((98)), (UNITY_INT)(UNITY_INT8 )((sfr[0xe0])), (

 ((void *)0)

 ), (UNITY_UINT)(859), UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).OV)), (

 ((void *)0)

 ), (UNITY_UINT)(860), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)(((*(Status*)&sfr[0xd0]).CY)), (

 ((void *)0)

 ), (UNITY_UINT)(861), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT64)((0x133 + 2)), (UNITY_INT64)((pc)), (

 ((void *)0)

 ), (UNITY_UINT)(862), UNITY_DISPLAY_STYLE_HEX64);

}
