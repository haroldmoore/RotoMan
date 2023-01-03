


//################## Decimal Point Control ######################

//************************** rev2 *******************************
int rowPins[7] = {1, 16, 2, 3, 13, 12, 11};   //-program ROW pins
//***************************************************************
//***************************************************************
int colPins[6] = {5, 4, 0, 10, 15, 14 };   //-program COLUMN pins
//***************************************************************

//###############################################################



void refreshMatrix_zero()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_0[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}

void refreshMatrix_one()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_1[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}

void refreshMatrix_two()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_2[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_three()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_3[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_four()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_4[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_five()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_5[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_six()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_6[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_seven()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_7[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_eight()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_8[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_nine()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_9[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void refreshMatrix_A()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_A[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_B()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_B[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_C()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_C[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_D()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_D[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_E()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_E[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_F()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_F[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_G()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_G[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_H()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_H[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_I()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_I[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_J()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_J[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_K()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_K[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_L()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_L[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_M()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_M[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_N()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_N[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_O()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_O[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_P()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_P[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_Q()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_Q[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_R()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_R[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_S()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_S[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_T()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_T[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_U()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_U[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_V()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_V[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_W()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_W[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_X()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_X[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_Y()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_Y[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}
void refreshMatrix_Z()                      
{
//--------------------------------------------------------
 for (int r = 0; r < 7; r++)
    {
        int c;
        for (c = 0; c < 6; c++)
        {
          digitalWrite(colPins[c], m_char_Z[r][c]);
        } 
        digitalWrite(rowPins[r], LOW);
        delay(2);
        digitalWrite(rowPins[r], HIGH);
    }
  return;
//--------------------------------------------------------
}




//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
















void display_hex(){
   for (int i = 0; i<40; i++)
 {
  refreshMatrix_zero(); 
 }

 for (int i = 0; i<40; i++)
 {
  refreshMatrix_one(); 
 }

 

 for (int i = 0; i<40; i++)
 {
  refreshMatrix_two(); 
 }

 for (int i = 0; i<40; i++)
 {
  refreshMatrix_three(); 
 }

 for (int i = 0; i<40; i++)
 {
  refreshMatrix_four(); 
 }

for (int i = 0; i<40; i++)
 {
  refreshMatrix_five(); 
 }

for (int i = 0; i<40; i++)
 {
  refreshMatrix_six(); 
 }
 
for (int i = 0; i<40; i++)
 {
  refreshMatrix_seven(); 
 }

for (int i = 0; i<40; i++)
 {
  refreshMatrix_eight(); 
 }

for (int i = 0; i<40; i++)
 {
  refreshMatrix_nine(); 
 }

for (int i = 0; i<40; i++)
 {
  refreshMatrix_A(); 
 }

 for (int i = 0; i<40; i++)
 {
  refreshMatrix_B(); 
 }

for (int i = 0; i<40; i++)
 {
  refreshMatrix_C(); 
 }

for (int i = 0; i<40; i++)
 {
  refreshMatrix_D(); 
 }

 for (int i = 0; i<40; i++)
 {
  refreshMatrix_E(); 
 }

for (int i = 0; i<40; i++)
 {
  refreshMatrix_F(); 
 }
 for (int i = 0; i<40; i++)
 {
  refreshMatrix_G(); 
 }
 for (int i = 0; i<40; i++)
 {
  refreshMatrix_H(); 
 }
 for (int i = 0; i<40; i++)
 {
  refreshMatrix_I(); 
 }
 for (int i = 0; i<40; i++)
 {
  refreshMatrix_J(); 
 }
 for (int i = 0; i<40; i++)
 {
  refreshMatrix_K(); 
 }
 for (int i = 0; i<40; i++)
 {
  refreshMatrix_L(); 
 }
 for (int i = 0; i<40; i++)
 {
  refreshMatrix_M(); 
 }
 for (int i = 0; i<40; i++)
 {
  refreshMatrix_N(); 
 }
 for (int i = 0; i<40; i++)
 {
  refreshMatrix_O(); 
 }
 for (int i = 0; i<40; i++)
 {
  refreshMatrix_P(); 
 }
 for (int i = 0; i<40; i++)
 {
  refreshMatrix_Q(); 
 }
 for (int i = 0; i<40; i++)
 {
  refreshMatrix_R(); 
 }
 for (int i = 0; i<40; i++)
 {
  refreshMatrix_S(); 
 }
 for (int i = 0; i<40; i++)
 {
  refreshMatrix_T(); 
 }
 for (int i = 0; i<40; i++)
 {
  refreshMatrix_U(); 
 }
 for (int i = 0; i<40; i++)
 {
  refreshMatrix_V(); 
 }
 for (int i = 0; i<40; i++)
 {
  refreshMatrix_W(); 
 }
 for (int i = 0; i<40; i++)
 {
  refreshMatrix_X(); 
 }
 for (int i = 0; i<40; i++)
 {
  refreshMatrix_Y(); 
 }
 for (int i = 0; i<40; i++)
 {
  refreshMatrix_Z(); 
 }
 
}
