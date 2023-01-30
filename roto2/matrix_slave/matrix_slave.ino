
/*
 *------------------------ATtiny3226-----------------------------      
 * 
C0 -> 14, B0 -> 8 , D0 -> Rx
C1 -> 15, B1 -> 9 , D1 -> Tx
C2 -> 16, B2 -> 10, D2 -> 2
C3 -> 17, B3 -> 11, D3 -> 3
C4 -> 18, B4 -> 12, D4 -> 4
C5 -> 19, B5 -> 13, D5 -> 5
C6 -> 20,           D6 -> 6
C7 -> 21,           D7 -> 7
   
    
---------------------------ARDUINO NANO----------------------------
                            
                GND - - - - - - - - |                  |
                 B3- - - - - - - -| |
                +5V - - - - - - | | |
                                o o o  
                                o o o 
                               /  |  \
                              B4  B5  C6 
 
                             _ _ _ _ _ _
                            |   o o o   |
                            |   o o o   |
//                     - D1 |o         o| VIN
//                     - C0 |o         o| GND   
//                     - C6 |o         o| RESET
//                      GND |o         o| +5V
//                     - D2 |o         o| A7
//                     - D3 |o         o| A6
//                     - D4 |o         o| A5 - SCL  
//                     - D5 |o         o| A4 - SDA  
//                     - D6 |o Arduino o| A3 
//                     - D7 |o   NANO  o| A2 
//                     - B0 |o         o| A1 - 
//                     - B1 |o         o| A0 - 
//                     - B2 |o   ___   o| AREF
//                     - B3 |o  |USB|  o| +3.3V
//                     - B4 |o__|___|__o| B5
// 

*/



#include "special.h"
#include "multiplex.h"
#include <Wire.h>


//************************** ATtiny3226 *************************
int rowPins[7] = {1, 16, 2, 3, 13, 12, 11};   //-program ROW pins
//***************************************************************
//***************************************************************
int colPins[6] = {5, 4, 0, 10, 15, 14 };   //-program COLUMN pins
//***************************************************************
int r;
int c;



int ones;
int letter = 0;             
                
int female [7][5] = {
        {0, 1, 1, 1, 0},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
       };

void setup()
{
   Wire.swap(0);
   Wire.begin(3);                   //change this address for 1's,10's,100's, or 1000's display positions.     
   Wire.onReceive(receiveEvent);      
   pinMode(8, INPUT_PULLUP);
   pinMode(9, INPUT_PULLUP);


//---------------------------------------------------------
  for (int c = 0; c < 6; c++)
  {
    pinMode(colPins[c], OUTPUT);  // initalize column pins
  }

  for (int r = 0; r < 7; r++)                      
  {
      pinMode(rowPins[r], OUTPUT);  // initialize row pins
  }
//--------------------------------------------------------




     
}
//---------------------------------------------------

//---------------------------------------------------  

void loop()
{

   delay(3);
   receiveEvent(1); 
   letter_man(); 
 }
   

void led_test(){
 // for(int i=0; i<35; i++)
 // {
    
 //     glow_led(i);
 //     delay(50);
 //     off_all();

       disp_char_scroll('K');
        delay(30);   
        off_all();



         
//  } 
}

//--------------------------------------------
void receiveEvent(int Data) {
  while (1 < Wire.available()) {   

     }
     int i = Wire.read();           // receive byte as an integer
     switch (i){

                   case 65:        //A
                       letter = 65;
                    
                         
                   break;

                   case 66:        //B

                      led_test();
                     
                   break;

                   case 67:        //C
                 
                       
                    
                   break;

                   case 68:        //D

                        
                     
                   break; 


                


                   case 48:        //0
                     letter = 48;
                 
                    
                   break;

                   case 49:        //1
                       letter = 49;
                  
                    
                   break;

                   case 50:        //2
                       letter = 50;
                 
                   break;

                   case 51:        //3
                        letter = 51;
                    
                    
                   break;

                   case 52:        //4
                        letter = 52;
                    
                    
                   break;

                   case 53:        //5
                         letter = 53;
                   
                    
                   break;

                   case 54:        //6
                         letter = 54;
                     
                    
                   break;

                   case 55:        //7
                         letter = 55;
                      
                    
                   break;

                   case 56:        //8
                        letter = 56;
                       
                   break;

                   case 57:        //9
                        letter = 57;
                      
                    
                   break;

                                    

                   
               }
 
}

//--------------------------------------------

void letter_man(){
  if (letter ==  48){disp_char('0');}
  if (letter ==  49){disp_char('1');}                    
  if (letter ==  50){disp_char('2');}                      
  if (letter ==  51){disp_char('3');}
  if (letter ==  52){disp_char('4');}
  if (letter ==  53){disp_char('5');}
  if (letter ==  54){disp_char('6');}
  if (letter ==  55){disp_char('7');}
  if (letter ==  56){disp_char('8');}
  if (letter ==  57){disp_char('9');}

 
}


  
  
