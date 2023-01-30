


#include <Arduino.h>

void glow_all();                                          //external

void off_all();                                           //external 

void glow_led(int ledNumber);                             //external

void off_led(int ledNumber);                              //external

void print_pattern(int print_array[7][5]);                //internal

void disp_char(char c);                                   //external

void disp_special_char(int print_array[7][5]);             //external 

void glow_led_scroll(int);                                //internal

void off_led_scroll(int);                                 //internal

void glow_matrix_scroll(char);                            //internal 

void disp_char_scroll(char c);                            //external
