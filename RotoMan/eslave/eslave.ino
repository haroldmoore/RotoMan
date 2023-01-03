
/*
 * slave code to work with the encoder PCB
 * 
 * Modified by Harold Moore 12/31/22
 * 
 */




 
#include "multiplex.h"
#include "refreshMatrix.h"
#include <Wire.h>


char j;

int r;
int c;


void setup() {
  
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  Wire.begin(3);                     // change the for 3,4,5 or 6 for the appropriate slave display module and its
                                     // powers of ten, to work with the master encoder pcb on the I2C bus.
  
  Wire.onReceive(receiveEvent);      // register event
  
  Serial.begin(9600);                // start serial for output
 
 
//-----------------------------------------------------
  for (int c = 0; c < 6; c++)
  {
    pinMode(colPins[c], OUTPUT);                    // initalize column pins
  }

  for (int r = 0; r < 7; r++)                       // initialize row pins
  {
      pinMode(rowPins[r], OUTPUT);
  }
//-----------------------------------------------------
  
}

void loop() {
  Wire.onReceive(receiveEvent);
 // delay(1);
  receiveEvent(1);
 // delay(3);
}


void receiveEvent(int Data) {
  while (1 < Wire.available()) {   
   // char j = Wire.read();           // receive byte as a character
     }
     int j = Wire.read();           // receive byte as an integer
     switch (j){

                  



                   case 48:        //0
                     
                        for (int i = 0; i<4; i++)
                        {
                          refreshMatrix_zero();
                          Wire.flush();  
                        }
                    
                   break;

                   case 49:        //1
                 
                        for (int i = 0; i<4; i++)
                        {
                          refreshMatrix_one();
                          Wire.flush();  
                        }
                    
                   break;

                   case 50:        //2
                 
                        for (int i = 0; i<4; i++)
                        {
                          refreshMatrix_two();
                          Wire.flush();  
                        }
                    
                   break;

                   case 51:        //3
                 
                        for (int i = 0; i<4; i++)
                        {
                          refreshMatrix_three();
                          Wire.flush();  
                        }
                    
                   break;

                   case 52:        //4
                 
                        for (int i = 0; i<4; i++)
                        {
                          refreshMatrix_four();
                          Wire.flush();  
                        }
                    
                   break;

                   case 53:        //5
                 
                        for (int i = 0; i<4; i++)
                        {
                          refreshMatrix_five();
                          Wire.flush();  
                        }
                    
                   break;

                   case 54:        //6
                 
                        for (int i = 0; i<4; i++)
                        {
                          refreshMatrix_six();
                          Wire.flush();  
                        }
                    
                   break;

                   case 55:        //7
                 
                        for (int i = 0; i<4; i++)
                        {
                          refreshMatrix_seven(); 
                          Wire.flush(); 
                        }
                    
                   break;

                   case 56:        //8
                 
                        for (int i = 0; i<4; i++)
                        {
                          refreshMatrix_eight();
                          Wire.flush();  
                        }
                    
                   break;

                   case 57:        //9
                 
                        for (int i = 0; i<4; i++)
                        {
                          refreshMatrix_nine();
                          Wire.flush();  
                        }
                   break;
                     
                

                                    

                   
               }
 
}
