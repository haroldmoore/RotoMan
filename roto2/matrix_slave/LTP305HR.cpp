/******************************************** 5x7 LED Dot Matrix *******************************************/
/* https://github.com/kjitender469/5x7_LED_Matrix
 * original code from Jitender Kumar
 * His teachers-- Mr. Murtaza Ameen, Mr. Naveen, Mrs. Kirti Panwar Bhati, and Mrs. Manju K. chattopadhayay.  
 *  
 *  adapted for attiny3226 and LTP305HR by Harold Moore 3/3/2022
 ************************************************************************************************************        

//###############################################################

      { 1, 2, 3, 4, 5},
      { 6, 7, 8, 9,10},
      {11,12,13,14,15},
      {16,17,18,19,20},
      {21,22,23,24,25},
      {26,27,28,29,30},
      {31,32,33,34,35}
*/
// int scroll_var = 7;
 
#include <Arduino.h>
#include "multiplex.h"

#define enable_disp_char_scroll
#define dataInFlash

#define dataInRAM

#ifdef dataInFlash
  const char data_A[] PROGMEM = {"00100010101000111111100011000110001"};
  const char data_B[] PROGMEM = {"11110100011000111110100011000111110"};
  const char data_C[] PROGMEM = {"01110100011000010000100001000101110"};
  const char data_D[] PROGMEM = {"11110100011000110001100011000111110"};
  
  const char data_E[] PROGMEM = {"11111 10000 10000 11110 10000 10000 11111"};
  
  const char data_F[] PROGMEM = {"11111100001000011111100001000010000"};
  
  const char data_G[] PROGMEM = {"01110 10001 10000 10110 10001 10001 01110"};
  
  const char data_H[] PROGMEM = {"10001100011000111111100011000110001"};
  const char data_I[] PROGMEM = {"11111001000010000100001000010011111"};
  const char data_J[] PROGMEM = {"11111001000010000100101001010001100"};
  const char data_K[] PROGMEM = {"10001100101010011000101001001010001"};
  const char data_L[] PROGMEM = {"10000100001000010000100001000011111"};
  const char data_M[] PROGMEM = {"10001110111010110001100011000110001"};
  const char data_N[] PROGMEM = {"10001100011100110101100111000110001"};
  const char data_O[] PROGMEM = {"01110100011000110001100011000101110"};
  const char data_P[] PROGMEM = {"11110100011000111110100001000010000"};
  const char data_Q[] PROGMEM = {"01110100011000110001100011001101110"};
  const char data_R[] PROGMEM = {"11110100011000111110101001001010001"};
  const char data_S[] PROGMEM = {"01110100011000001110000011000101110"};
  const char data_T[] PROGMEM = {"11111001000010000100001000010000100"};
  const char data_U[] PROGMEM = {"10001100011000110001100011000101110"};
  const char data_V[] PROGMEM = {"10001100011000110001100010101000100"};
  const char data_W[] PROGMEM = {"10001100011000110001101011010101010"};
  const char data_X[] PROGMEM = {"10001100010101000100010101000110001"};
  const char data_Y[] PROGMEM = {"10001100010101000100001000010000100"};
  const char data_Z[] PROGMEM = {"11111000010001000100010001000011111"};
  const char data_0[] PROGMEM = {"01110100011001110101110011000101110"};
  const char data_1[] PROGMEM = {"00100011000010000100001000010001110"};
  const char data_2[] PROGMEM = {"01110100010000100010001000100011111"};
  const char data_3[] PROGMEM = {"01110100010000100110000011000101110"};
  const char data_4[] PROGMEM = {"10001100011000111111000010000100001"};
  const char data_5[] PROGMEM = {"11111100001000011110000010000111110"};
  const char data_6[] PROGMEM = {"01110100001000011110100011000101110"};
  const char data_7[] PROGMEM = {"11111100010000100010001000010000100"};
  const char data_8[] PROGMEM = {"01110100011000101110100011000101110"};
  const char data_9[] PROGMEM = {"01110100011000101111000010000101110"};
  
  const char *const data_table[] PROGMEM = {data_A, data_B, data_C, data_D, data_E, data_F,
                                            data_G, data_H, data_I, data_J, data_K, data_L,
                                            data_M, data_N, data_O, data_P, data_Q, data_R,
                                            data_S, data_T, data_U, data_V, data_W, data_X,
                                            data_Y, data_Z, data_0, data_1, data_2, data_3,
                                            data_4, data_5, data_6, data_7, data_8, data_9
                                           };
#endif

#ifdef dataInRAM
const int A[7][5]  = {
  {0, 0, 1, 0, 0},
  {0, 1, 0, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1}
};

const int B[7][5]  = {
  {1, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 0}
};

const int C[7][5]  = {
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 0}
};

const int D[7][5]  = {
  {1, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 0}
};

const int E[7][5]  = {
  {1, 1, 1, 1, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 1, 1, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 1, 1, 1, 0}
};

const int F[7][5]  = {
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0}
};

const int G[7][5] = {
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 1, 1, 0},
  {1, 0, 0, 1, 0},
  {1, 0, 0, 1, 0},
  {0, 1, 1, 1, 0}
};

const int H[7][5]  = {
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1}
};

const int I[7][5]  = {
  {0, 1, 1, 1, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 1, 1, 1, 0}
};

const int J[7][5]  = {
  {1, 1, 1, 1, 1},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {1, 0, 1, 0, 0},
  {0, 1, 1, 0, 0}
};

const int K[7][5]  = {
  {1, 0, 0, 0, 1},
  {1, 0, 0, 1, 0},
  {1, 0, 1, 0, 0},
  {1, 1, 0, 0, 0},
  {1, 0, 1, 0, 0},
  {1, 0, 0, 1, 0},
  {1, 0, 0, 0, 1}
};

const int L[7][5] = {
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1}
};

const int M[7][5]  = {
  {1, 0, 0, 0, 1},
  {1, 1, 0, 1, 1},
  {1, 0, 1, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1}
};

const int N[7][5]  = {
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 0, 0, 1},
  {1, 0, 1, 0, 1},
  {1, 0, 0, 1, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1}
};

const int O[7][5]  = {
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 1, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 0}
};

const int P[7][5]  = {
  {1, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0}
};

const int Q[7][5]  = {
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 1, 1},
  {0, 1, 1, 1, 0}
};

const int R[7][5]  = {
  {1, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 0},
  {1, 0, 1, 0, 0},
  {1, 0, 0, 1, 0},
  {1, 0, 0, 0, 1}
};

const int S[7][5]  = {
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 0},
  {0, 1, 1, 1, 0},
  {0, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 0}
};

const int T[7][5]  = {
  {1, 1, 1, 1, 1},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0}
};

const int U[7][5]  = {
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 0}
};

const int V[7][5]  = {
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 0, 1, 0},
  {0, 0, 1, 0, 0}
};

const int W[7][5]  = {
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1},
  {0, 1, 0, 1, 0}
};

const int X[7][5]  = {
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 0, 1, 0},
  {0, 0, 1, 0, 0},
  {0, 1, 0, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1}
};

const int Y[7][5]  = {
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 0, 1, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0}
};

const int Z[7][5]  = {
  {1, 1, 1, 1, 1},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 1, 0},
  {0, 0, 1, 0, 0},
  {0, 1, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1}
};

const int m_char_0[7][5]  = {
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 1, 1},
  {1, 0, 1, 0, 1},
  {1, 1, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 0}
};

const int m_char_1[7][5]  = {
  {0, 0, 1, 0, 0},
  {0, 1, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 1, 1, 1, 0}
};

const int m_char_2[7][5]  = {
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 1, 0},
  {0, 0, 1, 0, 0},
  {0, 1, 0, 0, 0},
  {1, 1, 1, 1, 1}
};

const int m_char_3[7][5]  = {
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {0, 0, 0, 0, 1},
  {0, 0, 1, 1, 0},
  {0, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 0}
};

const int m_char_4[7][5]  = {
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 1},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 0, 1}
};

const int m_char_5[7][5]  = {
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 1, 1, 1, 0},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 0, 1},
  {1, 1, 1, 1, 0}
};

int m_char_6[7][5]  = {
  {1, 1, 1, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 1, 1, 0, 0},
  {1, 0, 1, 0, 0},
  {1, 0, 1, 0, 0},
  {1, 1, 1, 0, 0}
};

int m_char_7[7][5]  = {
  {0, 1, 1, 1, 1},
  {1, 0, 0, 0, 1},
  {0, 0, 0, 1, 0},
  {0, 0, 1, 0, 0},
  {0, 1, 0, 0, 0},
  {0, 1, 0, 0, 0},
  {0, 1, 0, 0, 0}
};

int m_char_8[7][5]  = {
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 0}
};

int m_char_9[7][5]  = {
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 1},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 0, 1},
  {0, 1, 1, 1, 0}
};
#endif

void glow_all()
{
#ifdef debug
  Serial.println("glow all LEDs.");
#endif
//14 --> 16
//16 --->15
//15 -->14
  //---------rows-----------------
  digitalWrite(1, LOW);    
  digitalWrite(16, LOW);   //-
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  //--------columns---------------
  digitalWrite(4, HIGH);
  digitalWrite(0, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(15, HIGH);  //-
  digitalWrite(14, HIGH);  //-
  //----------------------------- 
}

void off_all()
{
#ifdef debug
  Serial.println("off all LEDs.");
#endif
//14 --> 16
//16 --->15
//15 -->14
  //---------rows-----------------
  digitalWrite(1, LOW);    
  digitalWrite(16, LOW); //14-  
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  //--------columns---------------
  digitalWrite(4, LOW);
  digitalWrite(0, LOW);
  digitalWrite(10, LOW);
  digitalWrite(15, LOW); //15-
  digitalWrite(14, LOW); //14-
  //------------------------------
 
}

void glow_led(int ledNumber)
{
  switch (ledNumber)
  {
    case 1:
#ifdef debug
      Serial.print("Case : ");
      Serial.println(ledNumber);
#endif
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, LOW); //2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(4, HIGH);//4
    
      break;
    case 2:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, LOW); //2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(0, HIGH);//0
      
      break;
    case 3:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, LOW);  //2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(10, HIGH);//10
      
      break;
    case 4:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, LOW);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(15, HIGH);//15-
      
      break;
    case 5:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, LOW);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(14, HIGH);//14-
      
      break;
    case 6:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, LOW);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(4, HIGH);//4
      
      break;
    case 7:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, LOW);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(0, HIGH);//0
      
      break;
    case 8:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, LOW);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(10, HIGH);//10
      
      break;
    case 9:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, LOW);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(15, HIGH);//15-
      
      break;
    case 10:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, LOW);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(14, HIGH);//14-
      
      break;
    case 11:
  //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, LOW);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(4, HIGH);//4
      
      break;
    case 12:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, LOW);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(0, HIGH);//0
      
      break;
    case 13:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, LOW);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(10, HIGH);//10
      
      break;
    case 14:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, LOW);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(15, HIGH);//15-
      
      break;
    case 15:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, LOW);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(14, HIGH);//14-
      
      break;
    case 16:
  //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, LOW);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(4, HIGH);//4

      break;
    case 17:
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, LOW);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(0, HIGH);//0
      
      break;
    case 18:
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, LOW);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(10, HIGH);//10
      
      break;
    case 19:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, LOW);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(15, HIGH);//15-
      
      break;
    case 20:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, LOW);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(14, HIGH);//14-
      
      break;
    case 21:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, LOW);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(4, HIGH);//4
      
      break;
    case 22:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, LOW);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(0, HIGH);//0
      
      break;
    case 23:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, LOW);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(10, HIGH);//10
      
      break;
    case 24:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, LOW);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(15, HIGH);//15-
      
      break;
    case 25:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, LOW);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(14, HIGH);//14-
      
      break;
    case 26:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, LOW);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(4, HIGH);//4
      
      break;
    case 27:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, LOW);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(0, HIGH);//0
      
      break;
    case 28:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, LOW);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(10, HIGH);//10
      
      break;
    case 29:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, LOW);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(15, HIGH);//15-
      
      break;
    case 30:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, LOW);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(14, HIGH);//14-
      
      break;
    case 31:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, LOW);//11
      digitalWrite(4, HIGH);//4
      
      break;
    case 32:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, LOW);//11
      digitalWrite(0, HIGH);//0
      
      break;
    case 33:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, LOW);//11
      digitalWrite(10, HIGH);//10
      
      break;
    case 34:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, LOW);//11
      digitalWrite(15, HIGH);//15-
      
      break;
    case 35:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, LOW);//11
      digitalWrite(14, HIGH);//14-
      
      break;
    default:
      break;
  }
}

void off_led(int ledNumber)
{
  switch (ledNumber)
  {
    case 1:
#ifdef debug
      Serial.print("Case : ");
      Serial.println(ledNumber);
#endif
//14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, LOW);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(4, LOW);//4
      
      break;
    case 2:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, LOW);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(0, LOW);//0
      
      break;
    case 3:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, LOW);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(10, LOW);//10
      
      break;
    case 4:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, LOW);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(15, LOW);//15-
      
      break;
    case 5:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, LOW);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(14, LOW);//14-
      
      break;
    case 6:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, LOW);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(4, LOW);//4
      
      break;
    case 7:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, LOW);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(0, LOW);//0
      
      break;
    case 8:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, LOW);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(10, LOW);//10
      
      break;
    case 9:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, LOW);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(15, LOW);//15-
      
      break;
    case 10:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, LOW);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(14, LOW);//14-
      
      break;
    case 11:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, LOW);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(4, LOW);//4
      
      break;
    case 12:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, LOW);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(0, LOW);//0
      
      break;
    case 13:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, LOW);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(10, LOW);//10
      
      break;
    case 14:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, LOW);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(15, LOW);//15-
      
      break;
    case 15:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, LOW);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(14, LOW);//14-
      
      break;
    case 16:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, LOW);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(4, LOW);//4
      
      break;
    case 17:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, LOW);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(0, LOW);//0
      
      break;
    case 18:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, LOW);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(10, LOW);//10
      
      break;
    case 19:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16
      digitalWrite(2, HIGH);//3
      digitalWrite(3, LOW);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(15, LOW);//15-
      
      break;
    case 20:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16
      digitalWrite(2, HIGH);//3
      digitalWrite(3, LOW);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(14, LOW);//14-
      
      break;
    case 21:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, LOW);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(4, LOW);//4
      
      break;
    case 22:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, LOW);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(0, LOW);//0
      
      break;
    case 23:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, LOW);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(10, LOW);//10
      
      break;
    case 24:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, LOW);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(15, LOW);//15-
      
      break;
    case 25:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, LOW);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(14, LOW);//14-
      
      break;
    case 26:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, LOW);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(4, LOW);//4
      
      break;
    case 27:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, LOW);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(0, LOW);//0
      
      break;
    case 28:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, LOW);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(10, LOW);//10
      
      break;
    case 29:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, LOW);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(15, LOW);//15-
      
      break;
    case 30:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, LOW);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(14, LOW);//14-
      
      break;
    case 31:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, LOW);//11
      digitalWrite(4, LOW);//4
      
      break;
    case 32:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, LOW);//11
      digitalWrite(0, LOW);//0
      
      break;
    case 33:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, LOW);//11
      digitalWrite(10, LOW);//10
      
      break;
    case 34:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, LOW);//11
      digitalWrite(15, LOW);//15-
      
      break;
    case 35:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, LOW);//11
      digitalWrite(14, LOW);//14-
      
      break;
    default:
      break;
  }
}

////////////////////////////////////////////////////////////////////////////////////////

void glow_led_scroll(int ledNumber)
{
  switch (ledNumber)
  {
    case 6:
#ifdef debug
      Serial.print("Case : ");
      Serial.println(ledNumber);
#endif
//14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, LOW);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(4, HIGH);//4
      
      break;
    case 7:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, LOW);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(0, HIGH);//0
      
      break;
    case 8:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, LOW);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(10, HIGH);//10
      
      break;
    case 9:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, LOW);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(15, HIGH);//15-
      
      break;
    case 10:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, LOW);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(14, HIGH);//14-
      
      break;
    case 21:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, LOW);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(4, HIGH);//4
      
      break;
    case 22:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, LOW);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(0, HIGH);//0
      
      break;
    case 23:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, LOW);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(10, HIGH);//10
      
      break;
    case 24:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, LOW);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(15, HIGH);//15-
      
      break;
    case 25:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(15, LOW);//15-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(14, HIGH);//14-
      
      break;
    case 36:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, LOW);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(4, HIGH);//4
      
      break;
    case 37:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16
      digitalWrite(2, LOW);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(0, HIGH);//0
      
      break;
    case 38:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, LOW);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(10, HIGH);//10
      
      break;
    case 39:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16
      digitalWrite(2, LOW);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(15, HIGH);//15-
      
      break;
    case 40:
    //14 --> 16
//16 --->15
//15 -->14
       digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, LOW);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(14, HIGH);//14-
      
      break;
    case 51:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, LOW);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(4, HIGH);//4
      
      break;
    case 52:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, LOW);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(0, HIGH);//0
      
      break;
    case 53:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, LOW);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(10, HIGH);//10
      
      break;
    case 54:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, LOW);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(15, HIGH);//15-
      
      break;
    case 55:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, LOW);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(14, HIGH);//14
      
      break;
    case 66:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, LOW);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(4, HIGH);//4
      
      break;
    case 67:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, LOW);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(0, HIGH);//0
      
      break;
    case 68:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, LOW);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(10, HIGH);//10
      
      break;
    case 69:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, LOW);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(15, HIGH);//15-
      
      break;
    case 70:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, LOW);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(14, HIGH);//14-
      
      break;
    case 81:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, LOW);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(4, HIGH);//4
      
      break;
    case 82:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, LOW);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(0, HIGH);//0
      
      break;
    case 83:
    //14 --> 16
//16 --->15
//15 -->14
       digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, LOW);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(10, HIGH);//10
      
      break;
    case 84:
    //14 --> 16
//16 --->15
//15 -->14
       digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, LOW);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(15, HIGH);//15-
      
      break;
    case 85:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, LOW);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(14, HIGH);//14-
      
      break;
    case 96:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, LOW);//11
      digitalWrite(4, HIGH);//4
      
      break;
    case 97:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, LOW);//11
      digitalWrite(0, HIGH);//0
      
      break;
    case 98:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, LOW);//11
      digitalWrite(10, HIGH);//10
      
      break;
    case 99:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, LOW);//11
      digitalWrite(15, HIGH);//15-
      
      break;
    case 100:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, LOW);//11
      digitalWrite(14, HIGH);//14-
      
      break;
    default:
      break;
  }
}

void off_led_scroll(int ledNumber)
{
  switch (ledNumber)
  {
    case 6:
#ifdef debug
      Serial.print("Case : ");
      Serial.println(ledNumber);
#endif
//14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, LOW);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(4, LOW);//4
      
      break;
    case 7:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, LOW);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(0, LOW);//0
      
      break;
    case 8:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, LOW);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(10, LOW);//10
      
      break;
    case 9:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, LOW);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(15, LOW);//15- 
      
      break;
    case 10:
    //14 --> 16
//16 --->15
//15 -->14
       digitalWrite(1, LOW);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(14, LOW);//14
      
      break;
    case 21:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, LOW);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(4, LOW);//4
      
      break;
    case 22:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, LOW);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(0, LOW);//0
      
      break;
    case 23:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, LOW);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(10, LOW);//10
      
      break;
    case 24:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, LOW);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(15, LOW);//15-
      
      break;
    case 25:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, LOW);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(14, LOW);//14-
      
      break;
    case 36:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, LOW);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(4, LOW);//4
      
      break;
    case 37:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, LOW);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(0, LOW);//0
      
      break;
    case 38:
    //14 --> 16
//16 --->15
//15 -->14
       digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, LOW);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(10, LOW);//10
      
      break;
    case 39:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, LOW);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(15, LOW);//15-
      
      break;
    case 40:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, LOW);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(14, LOW);//14-
      
      break;
    case 51:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, LOW);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(4, LOW);//4
      
      break;
    case 52:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, LOW);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(0, LOW);//0
      
      break;
    case 53:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, LOW);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(10, LOW);//10
      
      break;
    case 54:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, LOW);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(15, LOW);//15-
      
      break;
    case 55:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, LOW);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(14, LOW);//14-
      
      break;
    case 66:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, LOW);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(4, LOW);//4
      
      break;
    case 67:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, LOW);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(0, LOW);//0
      
      break;
    case 68:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, LOW);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(10, LOW);//10
      
      break;
    case 69:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, LOW);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(15, LOW);//15-
      
      break;
    case 70:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, LOW);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(14, LOW);//14-
      
      break;
    case 81:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, LOW);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(4, LOW);//4
      
      break;
    case 82:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, LOW);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(0, LOW);//0
      
      break;
    case 83:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, LOW);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(10, LOW);//10
      
      break;
    case 84:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, LOW);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(16, LOW);//16
      
      break;
    case 85:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, LOW);//12
      digitalWrite(11, HIGH);//11
      digitalWrite(14, LOW);//14-
      
      break;
    case 96:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, LOW);//11
      digitalWrite(4, LOW);//4
      
      break;
    case 97:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, LOW);//11
      digitalWrite(0, LOW);//0
      
      break;
    case 98:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, LOW);//11
      digitalWrite(10, LOW);//10
      
      break;
    case 99:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, LOW);//11
      digitalWrite(15, LOW);//15-
      
      break;
    case 100:
    //14 --> 16
//16 --->15
//15 -->14
      digitalWrite(1, HIGH);//2
      digitalWrite(16, HIGH);//16-
      digitalWrite(2, HIGH);//3
      digitalWrite(3, HIGH);//13
      digitalWrite(13, HIGH);//1
      digitalWrite(12, HIGH);//12
      digitalWrite(11, LOW);//11
      digitalWrite(14, LOW);//14-
      
      break;
    default:
      break;
  }
}

////////////////////////////////////////////////////////////////////////////////////////

void print_pattern(int print_array[7][5])
{
  int temp[7][5] = {
    { 1,  2,  3,  4,  5},
    { 6,  7,  8,  9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25},
    {26, 27, 28, 29, 30},
    {31, 32, 33, 34, 35}
  };
  for (int k = 0; k < 30; k++)
  {
    for (int i = 0; i < 7; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        if(print_array[i][j] == 49)
        {
          glow_led(temp[i][j]);
          delayMicroseconds(70);
          off_led(temp[i][j]);
          delayMicroseconds(1);
        }
      }
    }
  }
}

void disp_char(char c)
{
  int temp[7][5] = {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
  };
  char x[35];
  byte count = 0;
  switch (c)
  {
    case 'A':
      count = 0;
      break;
    case 'B':
      count = 1;
      break;
    case 'C':
      count = 2;
      break;
    case 'D':
      count = 3;
      break;
    case 'E':
      count = 4;
      break;
    case 'F':
      count = 5;
      break;
    case 'G':
      count = 6;
      break;
    case 'H':
      count = 7;
      break;
    case 'I':
      count = 8;
      break;
    case 'J':
      count = 9;
      break;
    case 'K':
      count = 10;
      break;
    case 'L':
      count = 11;
      break;
    case 'M':
      count = 12;
      break;
    case 'N':
      count = 13;
      break;
    case 'O':
      count = 14;
      break;
    case 'P':
      count = 15;
      break;
    case 'Q':
      count = 16;
      break;
    case 'R':
      count = 17;
      break;
    case 'S':
      count = 18;
      break;
    case 'T':
      count = 19;
      break;
    case 'U':
      count = 20;
      break;
    case 'V':
      count = 21;
      break;
    case 'W':
      count = 22;
      break;
    case 'X':
      count = 23;
      break;
    case 'Y':
      count = 24;
      break;
    case 'Z':
      count = 25;
      break;
    case '0':
      count = 26;
      break;
    case '1':
      count = 27;
      break;
    case '2':
      count = 28;
      break;
    case '3':
      count = 29;
      break;
    case '4':
      count = 30;
      break;
    case '5':
      count = 31;
      break;
    case '6':
      count = 32;
      break;
    case '7':
      count = 33;
      break;
    case '8':
      count = 34;
      break;
    case '9':
      count = 35;
      break;
    default:
      break;
  }
  strcpy_P(x, (char *)pgm_read_word(&(data_table[count])));
  count = 0;
  for (int i = 0; i < 7; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      temp[i][j] = x[count];
      count++;
    }
  }
  count = 0;
  print_pattern(temp);
}

void disp_custom_char(int print_array[7][5])
{
  int temp[7][5] = {
    { 1,  2,  3,  4,  5},
    { 6,  7,  8,  9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25},
    {26, 27, 28, 29, 30},
    {31, 32, 33, 34, 35}
  };
  for (int k = 0; k < 30; k++)
  {
    for (int i = 0; i < 7; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        if(print_array[i][j] == 1)
        {
          glow_led(temp[i][j]);
          delayMicroseconds(1000);
          off_led(temp[i][j]);
          delayMicroseconds(1);
        }
      }
    }
  }
}

void glow_matrix_scroll(char c)
{

  int count = 0;
  int scroll = 0;
  int scroll_var = 0;
  int second_iteration_var = 0;
  int glow_map[7][15] = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
    {31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45},
    {46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
    {61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75},
    {76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
    {91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105}
  };

  //xvar[0] = 'j';

  switch (c)
  {
    case 'X':
//-------------------------------------------------------------------------------------    
      scroll_var = 11;
      while (scroll < 17)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (J[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(500);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
                //Serial.print(glow_map[i][j]);
                //Serial.print("+++");
              }
              // Serial.print(j);
              //Serial.print("---");
              second_iteration_var ++;
              //if(second_iteration_var > 4) second_iteration_var=0;
            }
            //Serial.println();
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var--;
        //Serial.println(scroll_var);
      }
      break;
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------


      

      
    case 'Y':
      scroll_var = 11;
      while (scroll < 17)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (T[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(500);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var--;
      }
      break;
    default:
      break;
  }

  //Serial.println("Exit Function");


}

void disp_char_scroll(char c)
{
  int count = 0;
  int scroll = 0;
  int scroll_var = 0;
  int second_iteration_var = 0;
  int glow_map[7][15] = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
    {31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45},
    {46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
    {61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75},
    {76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
    {91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105}
  };
  switch (c)
  {

    case 'A':
      scroll_var = 11;
      while (scroll < 17)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (A[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(500);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var--;
      }
      break;

    case 'B':
      scroll_var = 11;
      while (scroll < 17)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (B[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(200);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var--;
      }
      break;

    case 'C':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (C[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'D':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (D[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'E':
      scroll_var = 11;
      while (scroll < 17)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (E[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(300);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var--;
      }
      break;

    case 'F':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (F[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'G':
      scroll_var = 11;
      while (scroll < 17)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (G[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(300);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var--;
      }
      break;

    case 'H':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (H[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;
//-----------------------------------------------------------------------
      case 'I':
      scroll_var = 11;
      while (scroll < 17)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (I[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(360);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var--;
      }
      break;

//-----------------------------------------------------------------------      

    case 'K':
      scroll_var = 11;
      while (scroll < 17)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (K[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(300);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var--;
      }
      break;

    case 'L':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (L[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'M':
      scroll_var = 11;
      while (scroll < 17)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (M[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(300);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var--;
      }
      break;

    case 'N':
      scroll_var = 11;
      while (scroll < 17)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (N[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(300);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var--;
      }
      break;

    case 'O':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (O[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'P':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (P[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'Q':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (Q[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'R':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (R[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'S':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (S[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'V':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (V[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'W':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (W[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'X':
//-----------------------------------------------------------------------  
      scroll_var = 11;
      while (scroll < 17)
     
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (X[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(500);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var--;
      }
      break;

    case 'Y':
      scroll_var = 11;
      while (scroll < 17)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (Y[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(500);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var--;
      }
      break;

    case 'Z':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (Z[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case '0':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (m_char_0[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case '1':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (m_char_1[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case '2':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (m_char_2[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case '3':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (m_char_3[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case '4':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (m_char_4[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case '5':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (m_char_5[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case '6':
      scroll_var = 11;
      while (scroll < 17)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (m_char_6[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(300);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var--;
      }
      break;

    case '7':
      scroll_var = 11;
      while (scroll < 17)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (m_char_7[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(300);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var--;
      }
      break;

    case '8':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (m_char_8[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case '9':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (m_char_9[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'J':
      scroll_var = 11; 
      while (scroll < 17)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (J[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(300);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var--;
      }
      break;

 //---------------------------------------------------------------------     
 //   case 'I':
  //    while (scroll < 11)
  //    {
 //       while (count <= 10)
 //       {
 //         for (int i = 0; i < 7; i++)
 //         {
 //           for (int j = scroll_var; j <= (scroll_var + 4); j++)
 //           {
 //             if (I[i][second_iteration_var] == 1)
 //             {
 //               glow_led_scroll(glow_map[i][j]);
 //               delayMicroseconds(1000);
 //               off_led_scroll(glow_map[i][j]);
 //               delayMicroseconds(1);
 //             }
 //             second_iteration_var ++;
 //           }
 //           second_iteration_var = 0;
 //         }
 //         count++;
 //       }
 //       scroll++;
 //       count = 0;
 //       scroll_var++;
 //     }
 //     break;
//-----------------------------------------------------------------------------
      
    case 'T':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (T[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;
    case 'U':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (U[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;
    default:
      break;
  }
}
