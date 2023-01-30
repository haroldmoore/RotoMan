/*
 * RotoMan  
 * 
 * original encoder code by Manuel Reimer
 * program modified by Harold Moore 12/31/2022
 * ----------------------------------------------------
 * math functions to enable encoder display values 
 * on ATtiny3226 encoder PCB to work with the ATtiny3226
 * Display Module PCB with obsolete LTP-305 Matrix Display LEDs
 * thru the I2C bus:
 * 
 *               int ones = (position%10);
                 int tens = ((position/10)%10);
                 int huns = ((position/100)%10);
                 int thos = ((position/1000)%10);
                
   ----------------------------------------------------
programmed into the "encoder pcb" with an arduino nano as a'jtag2updi' programmer
   
 */



#include "EncoderStepCounter.h"
#include <Wire.h>
#include <EEPROM.h>
#include <stdio.h>
#include <avr/wdt.h>


#define ENCODER_PIN1 A4
#define ENCODER_INT1 digitalPinToInterrupt(ENCODER_PIN1)
#define ENCODER_PIN2 A2
#define ENCODER_INT2 digitalPinToInterrupt(ENCODER_PIN2)

#define BUTTON_PIN 4
byte lastButtonState = LOW;
unsigned long debounceDuration = 50; // millis
unsigned long lastTimeButtonStateChanged = 0;
const int buttonPin =  12;        //second pin of button switch
int buttonPresses = 0;

int ones;     //I2C  display at address 3
int tens;     //I2C  display at address 4 
int huns;     //I2C  display at address 5
int thos;     //I2C  display at address 6
//-------------------------------------------
// int b_count = 0;
byte n0 = '0';
byte n1 = '1';
byte n2 = '2';
byte n3 = '3';
byte n4 = '4';
byte n5 = '5';
byte n6 = '6';
byte n7 = '7';
byte n8 = '8';
byte n9 = '9';
//-------------------------------------------



// Create instance for one full step encoder
EncoderStepCounter encoder(ENCODER_PIN1, ENCODER_PIN2);
// Use the following for half step encoders
//EncoderStepCounter encoder(ENCODER_PIN1, ENCODER_PIN2, HALF_STEP);

void setup() {

   // set ATtiny3226 encoder pcb I2C pins
   Wire.begin();
   pinMode(8, OUTPUT);
   pinMode(9, OUTPUT);

   // set ATtiny3226 encoder pcb switch pins
   pinMode(BUTTON_PIN, INPUT_PULLUP);
   pinMode(buttonPin, OUTPUT);
   digitalWrite(buttonPin, LOW);   // make second pin of button switch low, (so the other is readable).

  
  Serial.begin(9600);              // make use of TxRx lines on the encoder PCB.
  
 
  
  // Initialize encoder
  encoder.begin();
  
  // Initialize interrupts
  attachInterrupt(ENCODER_INT1, interrupt, CHANGE);
  attachInterrupt(ENCODER_INT2, interrupt, CHANGE);
}

// --------------------------call library----------------------
void interrupt() {
  encoder.tick();
}


signed long position = 0;         //encoder position varible

void(* resetFunc) (void) = 0;     //reset funtion if needed


void loop() {
                 get_encoder();    //get encoder and its button
                 get_button();
                 
                                 
                 EEPROM.get(5, position);    //recall ecoder value
                 
//---------------perform math functions on it---------                             
                 int ones = (position%10);        //i2c address 3
                 int tens = ((position/10)%10);   //i2c address 4
                 int huns = ((position/100)%10);  //i2c address 5
                 int thos = (position/1000)%10;   //i2c address 6
//----------------------------------------------------

//---------display it on matrix display modules for the appropriate powers of ten-------------
//--------------------------------------------------------------------------------------------

  Wire.beginTransmission(3);
  if (ones ==  0){Wire.write(n0);}
  if (ones ==  1){Wire.write(n1);}
  if (ones ==  2){Wire.write(n2);}
  if (ones ==  3){Wire.write(n3);}
  if (ones ==  4){Wire.write(n4);}
  if (ones ==  5){Wire.write(n5);}
  if (ones ==  6){Wire.write(n6);}
  if (ones ==  7){Wire.write(n7);}
  if (ones ==  8){Wire.write(n8);}
  if (ones ==  9){Wire.write(n9);}
  Wire.endTransmission(); 

  Wire.beginTransmission(4);
  if (tens ==  0){Wire.write(n0);}
  if (tens ==  1){Wire.write(n1);}
  if (tens ==  2){Wire.write(n2);}
  if (tens ==  3){Wire.write(n3);}
  if (tens ==  4){Wire.write(n4);}
  if (tens ==  5){Wire.write(n5);}
  if (tens ==  6){Wire.write(n6);}
  if (tens ==  7){Wire.write(n7);}
  if (tens ==  8){Wire.write(n8);}
  if (tens ==  9){Wire.write(n9);}
  Wire.endTransmission();

   Wire.beginTransmission(5);
  if (huns ==  0){Wire.write(n0);}
  if (huns ==  1){Wire.write(n1);}
  if (huns ==  2){Wire.write(n2);}
  if (huns ==  3){Wire.write(n3);}
  if (huns ==  4){Wire.write(n4);}
  if (huns ==  5){Wire.write(n5);}
  if (huns ==  6){Wire.write(n6);}
  if (huns ==  7){Wire.write(n7);}
  if (huns ==  8){Wire.write(n8);}
  if (huns ==  9){Wire.write(n9);}
  Wire.endTransmission();

    Wire.beginTransmission(6);
  if (thos ==  0){Wire.write(n0);}
  if (thos ==  1){Wire.write(n1);}
  if (thos ==  2){Wire.write(n2);}
  if (thos ==  3){Wire.write(n3);}
  if (thos ==  4){Wire.write(n4);}
  if (thos ==  5){Wire.write(n5);}
  if (thos ==  6){Wire.write(n6);}
  if (thos ==  7){Wire.write(n7);}
  if (thos ==  8){Wire.write(n8);}
  if (thos ==  9){Wire.write(n9);}
   Wire.endTransmission();
 
       
}

void get_encoder(){
//-------------------------encoder----------------------------------------------
      signed char pos = encoder.getPosition();
        if (pos != 0) {
          position += pos;
             EEPROM.put(5, position);   // save encoder value when powered down.
               encoder.reset();
                 if (position < 1){
                    position = 0;
                 }
                 //     Serial.println(position);
         }
} 



void get_button(){
//------------------------encoder  button----------------------------------------
/*
 * put out on TTL TxRx pins to communicate with the outside world.
 * 
 */
if (millis() - lastTimeButtonStateChanged > debounceDuration) {
     
    byte buttonState = digitalRead(BUTTON_PIN);
      if (buttonState != lastButtonState) {
         lastTimeButtonStateChanged = millis();
            lastButtonState = buttonState;
               if (buttonState == LOW) {
                  buttonPresses++; 
                     switch(buttonPresses){
                        case 1:
                           Serial.println("3000");  // example values
                           EEPROM.put(5, 3000);     // to display
                        break;
                        case 2:
                          Serial.println("5000");
                          EEPROM.put(5, 7000);
                        break;
                        case 3:
                          Serial.println("6000");
                          EEPROM.put(5, 9000);
                        break;
                        case 4:
                          buttonPresses = 0;         // reset and start again 
                          resetFunc(); 
                        break;
                      }
                 }
                 if (buttonState == HIGH) {
                    // Serial.println("up");
                 } 
             }
      }
}
