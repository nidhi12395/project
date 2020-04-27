
#include<Arduino.h>

#define sw A5
#define x A0
#define y A1
#define L1 13
#define L2 12
#define L3 11
#define L4 10
#define L5 9
#define L6 8
#define L7 7
#define sw_P1 5
#define sw_P2 6
#define P1W1 A3
#define P1W2 A4
#define P2W1 3
#define P2W2 2
#define buzzer A2


int count_up = 0, count_ups2=0, player1 = 0, player2 = 0, sw1pressed=0, sw2pressed=0, p1L1 =0,p1L2=0, p2L1=0, p2L2=0, P1=0, P2=0;
int count_up1 = 0,count_up2 = 0, result1=0, result2=0, win1=0, win2=0, turn =0, buttonstate = 0;
int p1glowl1 = 0, p1glowl2 = 0, p1glowl3 = 0, p1glowl4 = 0, p1glowl5 = 0, p1glowl6 = 0, p1glowl7 = 0;
int p2glowl1 = 0,p2glowl2 = 0, p2glowl3 = 0, p2glowl4 = 0,p2glowl5 = 0, p2glowl6 = 0,p2glowl7 = 0;

int selection1()
{
  int xValue = analogRead(x);
  int yValue = analogRead(y);
  xValue = map(xValue, 0, 1023, 0, 8);
  yValue = map(yValue, 0, 1023, 0, 8);
  Serial.print("\n X: | ");
  Serial.print(xValue);
  Serial.print("\n Y: | ");
  Serial.print(yValue);
  if(count_up == 0)
  {
   if(xValue ==8 && yValue == 3)
   {
     Serial.print("LED 1 ON");
     digitalWrite(L1, HIGH);
     while(buttonstate == 0)
     {
      Serial.print("\n CENTER");
        int xValue = analogRead(x);
        int yValue = analogRead(y);
         xValue = map(xValue, 0, 1023, 0, 8);
        yValue = map(yValue, 0, 1023, 0, 8);
      Serial.print("\n X: | ");
      Serial.print(xValue);
      Serial.print("\n Y: | ");
      Serial.print(yValue);
      if(digitalRead(sw) == NULL)
      {
        Serial.print("\n Button Pressed");
        Serial.print("\n LED 1 is selected");
        digitalWrite(L1, HIGH);
        player1++;
        P1=1;
        return (P1);
      }
      else if (xValue != 8 && yValue != 3)
      {
        Serial.print("\ Check this condition TRUE");
         Serial.print("LED 1 is OFF");
          digitalWrite(L1, LOW);
           buttonstate = 1;
      }
      else
      {
         buttonstate = 0;
      }
     }
  }
  else if(xValue == 3 &&yValue == 8)
  {
    buttonstate = 0;
    Serial.print("LED 2 ON");
    digitalWrite(L2, HIGH);
    while(buttonstate == 0)
    {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 2 is selected");
        digitalWrite(L2, HIGH);
        player1++;
        P1=2;
        return(P1);
      }
      else if (xValue != 3 && yValue != 8)
      {
        Serial.print("LED 2 is OFF");
        digitalWrite(L2, LOW);
        buttonstate = 1;
      }
      else
      {
         buttonstate = 0;
      }
    }
  }
  else if(xValue ==0&& yValue == 3)
  {
    buttonstate = 0;
    Serial.print("LED 3 ON");
    digitalWrite(L3, HIGH);
    count_up = 1;
    while(buttonstate == 0)
    {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 3 is selected");
        digitalWrite(L3, HIGH);
        player1++;
        P1=3;
        return(P1);
    }
    else if (xValue != 0 && yValue != 3)
    {
      Serial.print("LED 3 is OFF");
      digitalWrite(L3, LOW);
      buttonstate = 1;
    }
    else
    {
         buttonstate = 0;
    }
   }
  }
  else if(xValue == 3 &&yValue == 0)
  {
    buttonstate = 0;
    Serial.print("LED 4 ON");
    digitalWrite(L4, HIGH);
    while(buttonstate == 0)
    {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 4 is selected");
        digitalWrite(L4, HIGH);
        player1++;
        P1=4;
        return(P1);
      }
      else if (xValue != 3 && yValue != 0)
      {
        Serial.print("LED 4 is OFF");
        digitalWrite(L4, LOW);
        buttonstate = 1;
     }
     else
    {
         buttonstate = 0;
    }
  }
 }
}
 else
 {
  if(xValue ==8 && yValue == 3)
  {
    buttonstate = 0;
    Serial.print("LED 1 ON");
    digitalWrite(L1, HIGH);
    count_up = 0;
    while(buttonstate == 0)
    {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 1 is selected");
        digitalWrite(L1, HIGH);
        player1++;
        P1=1;
        return(P1);
    }
    else if (xValue != 8 && yValue != 3)
    {
      Serial.print("LED 1 is OFF");
      digitalWrite(L1, LOW);
      buttonstate = 1;
    }
    else
    {
         buttonstate = 0;
    }
   }
  }
  else if(xValue == 3 && yValue == 8)
  {
    buttonstate = 0;
    Serial.print("LED 5 ON");
    digitalWrite(L5, HIGH);
    while(buttonstate == 0)
    {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 5 is selected");
        digitalWrite(L5, HIGH);
        player1++;
        P1=5;
        return(P1);
      }
      else if (xValue != 3 && yValue != 8)
      {
        Serial.print("LED 5 is OFF");
        digitalWrite(L5, LOW);
        buttonstate = 1;
      }
       else
       {
         buttonstate = 0;
       }
    }
 }
 else if(xValue ==0 && yValue == 3)
 {
  buttonstate = 0;
  Serial.print("LED 6 ON");
  digitalWrite(L6, HIGH);
  count_up = 1;
  while(buttonstate == 0)
  {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
     {
        Serial.print("LED 6 is selected");
        digitalWrite(L6, HIGH);
        player1++;
        P1=6;
        return(P1);
      }
      else if (xValue != 0 && yValue != 3)
      {
        Serial.print("LED 6 is OFF");
        digitalWrite(L6, LOW);
        buttonstate = 1;
      }
      else
       {
         buttonstate = 0;
       }
  }
 }
 else if(xValue == 3 && yValue == 0)
 {
  buttonstate = 0;
  Serial.print("LED 7 ON");
  digitalWrite(L7, HIGH);
  while(buttonstate == 0)
  {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 7 is selected");
        digitalWrite(L7, HIGH);
        player1++;
        P1=7;
        return(P1);
      }
      else if (xValue != 3 && yValue != 0)
      {
        Serial.print("LED 7 is OFF");
        digitalWrite(L7, LOW);
        buttonstate = 1;
      }
       else
       {
         buttonstate = 0;
       }
  }
 }
 return 0;
}
}


int selection2()
{
  buttonstate = 0;
  int xValue = analogRead(x);
  int yValue = analogRead(y);
  xValue = map(xValue, 0, 1023, 0, 8);
  yValue = map(yValue, 0, 1023, 0, 8);
  if(count_ups2 == 0)
  {
   if(xValue ==8 && yValue == 3)
   {
     Serial.print("LED 1 ON");
     digitalWrite(L1, HIGH);
     while(buttonstate == 0)
     {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 1 is selected");
        digitalWrite(L1, HIGH);
        player2++;
        P2=1;
        return(P2);
      }
      else if (xValue != 8 && yValue != 3)
      {
        Serial.print("LED 1 is OFF");
        digitalWrite(L1, LOW);
        buttonstate = 1;
      }
      else
      {
        buttonstate = 0;
      }
     }
  }
  else if(xValue ==3 && yValue == 8)
  {
    buttonstate = 0;
    Serial.print("LED 2 ON");
    digitalWrite(L2, HIGH);
     while(buttonstate == 0)
     {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 2 is selected");
        digitalWrite(L2, HIGH);
        player2++;
        P2=2;
        return(P2);
      }
      else if (xValue != 3 && yValue != 8)
      {
        Serial.print("LED 2 is OFF");
        digitalWrite(L2, LOW);
        buttonstate = 1;
      }
      else
      {
        buttonstate = 0;
      }
    }
  }
  else if(xValue ==0 && yValue == 3)
  {
    buttonstate = 0;
    Serial.print("LED 3 ON");
    digitalWrite(L3, HIGH);
    count_ups2 = 1;
    while(buttonstate == 0)
     {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 3 is selected");
        digitalWrite(L3, HIGH);
        player2++;
        P2=3;
        return(P2);
      }
      else if (xValue != 0 && yValue != 3)
      {
       Serial.print("LED 3 is OFF");
       digitalWrite(L3, LOW);
       buttonstate = 1;
      }
      else
      {
        buttonstate = 0;
      }
    }
  }
  else if(xValue ==3 && yValue == 0)
  {
    buttonstate = 0;
    Serial.print("LED 4 ON");
    digitalWrite(L4, HIGH);
    while(buttonstate == 0)
     {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 4 is selected");
        digitalWrite(L4, HIGH);
        player2++;
        P2=4;
        return(P2);
      }
      else if (xValue != 3 && yValue != 0)
      {
        Serial.print("LED 4 is OFF");
        digitalWrite(L4, LOW);
        buttonstate = 1;
      }
      else
      {
        buttonstate = 0;
      }
    }
  }
 }
 else
 {
   if(xValue ==8 && yValue == 3)
  {
    buttonstate = 0;
    Serial.print("LED 1 ON");
    digitalWrite(L1, HIGH);
    count_ups2 = 0;
    while(buttonstate == 0)
     {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 1 is selected");
        digitalWrite(L1, HIGH);
        player2++;
        P2=1;
        return(P2);
      }
      else if (xValue != 8 && yValue != 3)
      {
        Serial.print("LED 1 is OFF");
        digitalWrite(L1, LOW);
        buttonstate = 1;
      }
      else
      {
        buttonstate = 0;
      }
    }
  }
  else if(xValue ==3 && yValue == 8)
 {
  buttonstate = 0;
  Serial.print("LED 5 ON");
  digitalWrite(L5, HIGH);
  while(buttonstate == 0)
  {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
      { 
        Serial.print("LED 5 is selected");
        digitalWrite(L5, HIGH);
        player2++;
        P2=5;
        return(P2);
      }
      else if (xValue != 3 && yValue != 8)
      {
        Serial.print("LED 5 is OFF");
        digitalWrite(L5, LOW);
        buttonstate = 1;
      }
      else
      {
        buttonstate = 0;
      }
   }
 }
  else if(xValue ==0 && yValue == 3)
 {
  buttonstate = 0;
  Serial.print("LED 6 ON");
  digitalWrite(L6, HIGH);
  count_ups2 = 1;
  while(buttonstate == 0)
  {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 6 is selected");
        digitalWrite(L6, HIGH);
        player2++;
        P2=6;
        return(P2);
      }
      else if (xValue != 0 && yValue != 3)
      {
        Serial.print("LED 6 is OFF");
        digitalWrite(L6, LOW);
        buttonstate = 1;
      }
      else
      {
        buttonstate = 0;
      }
  }
 }
 else if(xValue ==3 && yValue == 0)
 {
  buttonstate = 0;
  Serial.print("LED 7 ON");
  digitalWrite(L7, HIGH);
   while(buttonstate == 0)
  {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 7 is selected");
        digitalWrite(L7, HIGH);
        player2++;
        P2=7;
        return(P2);
      }
      else if (xValue != 3 && yValue != 0)
      {
        Serial.print("LED 7 is OFF");
        digitalWrite(L7, LOW);
         buttonstate = 1;
      }
      else
      {
         buttonstate = 0;
      }
    }
    }
  }
  return 0;
}

int player2_turn()
{
  buttonstate=0;
  int xValue = analogRead(x);
  int yValue = analogRead(y);
  xValue = map(xValue, 0, 1023, 0, 8);
  yValue = map(yValue, 0, 1023, 0, 8);
  Serial.print("\n X: | ");
  Serial.print(xValue);
  Serial.print("\n Y: | ");
  Serial.print(yValue);
  if(count_up1 == 0)
  {
   if(xValue ==8 && yValue == 3)
   {
     Serial.print("LED 1 ON");
     digitalWrite(L1, HIGH);
    while(buttonstate == 0)
    {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 1 is selected");
        digitalWrite(L1, HIGH);
        p2glowl1=1;
        if((p1L1 == 1 || p1L2 == 1) && digitalRead(P2W1) == LOW)
        {
          digitalWrite(P2W1, HIGH);
          digitalWrite(L1, LOW);
          win1=1;
          return(win1);
        }
        else if((p1L1 == 1 || p1L2 == 1) && digitalRead(P2W1) == HIGH)
        {
          digitalWrite(P2W2, HIGH);
          digitalWrite(L1, LOW);
          win1=2;
          return(win1);
        }
        else
        {
          digitalWrite(L1, LOW);
          return(win1);
        }
      }
      else if (xValue != 8 && yValue != 3)
      {
        Serial.print("LED 1 is OFF");
        digitalWrite(L1, LOW);
        buttonstate = 1;
      }
      else
      {
        buttonstate = 0;
      }
    }
   }
  else if(xValue ==3 && yValue == 8)
  {
    buttonstate = 0;
    Serial.print("LED 2 ON");
    digitalWrite(L2, HIGH);
    while(buttonstate == 0)
    {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 2 is selected");
        digitalWrite(L2, HIGH);
        p2glowl2=1;
        if((p1L1 == 2 || p1L2 == 2) && digitalRead(P2W1) == LOW)
        {
          digitalWrite(P2W1, HIGH);
          digitalWrite(L2, LOW);
          win1=1;
          return(win1);
        }
        else if((p1L1 == 2 || p1L2 == 2) && digitalRead(P2W1) == HIGH)
        {
          digitalWrite(P2W2, HIGH);
          digitalWrite(L2, LOW);
          win1=2;
          return(win1);
        }
        else
        {
          digitalWrite(L2, LOW);
          return(win1);
        }
      }
    else if(xValue != 3 && yValue != 8)
    {
      Serial.print("LED 2 is OFF");
      digitalWrite(L2, LOW);
      buttonstate = 1;
    }
    else
    {
      buttonstate = 0;
    }
   }
 }
  else if(xValue ==0 && yValue == 3)
  {
    buttonstate = 0;
    Serial.print("LED 3 ON");
    digitalWrite(L3, HIGH);
    count_up1 = 1;
    while(buttonstate == 0)
    {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 3 is selected");
        digitalWrite(L3, HIGH);
        p2glowl3=1;
        if((p1L1 == 3 || p1L2 == 3) && digitalRead(P2W1) == LOW)
        {
          digitalWrite(P2W1, HIGH);
          digitalWrite(L3, LOW);
          win1=1;
          return(win1);
        }
        else if((p1L1 == 3 || p1L2 == 3) && digitalRead(P2W1) == HIGH)
        {
          digitalWrite(P2W2, HIGH);
          digitalWrite(L3, LOW);
          win1=2;
          return(win1);
        }
        else
        {
          digitalWrite(L3, LOW);
          return(win1);
        }
      }
      else if(xValue !=0 && yValue != 3)
      {
        Serial.print("LED 3 is OFF");
        digitalWrite(L3, LOW);
        buttonstate=1;
      }
      else
      {
        buttonstate=0;
      }
    }
  }
  else if(xValue ==3 && yValue == 0)
  {
    buttonstate=0;
    Serial.print("LED 4 ON");
    digitalWrite(L4, HIGH);
    while(buttonstate == 0)
    {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 4 is selected");
        digitalWrite(L4, HIGH);
        p2glowl4=1;
       if((p1L1 == 4 || p1L2 == 4) && digitalRead(P2W1) == LOW)
        {
          digitalWrite(P2W1, HIGH);
          digitalWrite(L4, LOW);
          win1=1;
          return(win1);
        }
        else if((p1L1 == 4 || p1L2 == 4) && digitalRead(P2W1) == HIGH)
        {
          digitalWrite(P2W2, HIGH);
          digitalWrite(L4, LOW);
          win1=2;
          return(win1);
        }
        else
        {
          digitalWrite(L4, LOW);
          return(win1);
        }
      }
      else if(xValue !=3 && yValue != 0)
      {
        Serial.print("LED 4 is OFF");
        digitalWrite(L4, LOW);
        buttonstate=1;
      }
      else
      {
        buttonstate=0;
      }
    }
 }
 }
 else
 {
   if(xValue ==8 && yValue == 3)
  {
    buttonstate=0;
    Serial.print("LED 1 ON");
    digitalWrite(L1, HIGH);
    count_up = 0;
     while(buttonstate == 0)
    {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 1 is selected");
        digitalWrite(L1, HIGH);
        p2glowl1=1;
        if((p1L1 == 1 || p1L2 == 1) && digitalRead(P2W1) == LOW)
        {
          digitalWrite(P2W1, HIGH);
          digitalWrite(L1, LOW);
          win1=1;
          return(win1);
        }
        else if((p1L1 == 1 || p1L2 == 1) && digitalRead(P2W1) == HIGH)
        {
          digitalWrite(P2W2, HIGH);
          digitalWrite(L1, LOW);
          win1=2;
          return(win1);
        }
        else
        {
          digitalWrite(L1, LOW);
          return(win1);
        }
      }
      else if(xValue ==8 && yValue == 3)
      {
        Serial.print("LED 1 is OFF");
        digitalWrite(L1, LOW);
        buttonstate=1;
      }
      else
      {
        buttonstate=0;
      }
    }
   }
  else if(xValue ==3 && yValue == 8)
 {
  buttonstate=0;
  Serial.print("LED 5 ON");
  digitalWrite(L5, HIGH);
  while(buttonstate == 0)
    {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
     if(digitalRead(sw) == NULL)
     {
      Serial.print("LED 5 is selected");
      digitalWrite(L5, HIGH);
      p2glowl5=1;
      if((p1L1 == 5 || p1L2 == 5) && digitalRead(P2W1) == LOW)
        {
          digitalWrite(P2W1, HIGH);
          digitalWrite(L5, LOW);
          win1=1;
          return(win1);
        }
        else if((p1L1 == 5 || p1L2 == 5) && digitalRead(P2W1) == HIGH)
        {
          digitalWrite(P2W2, HIGH);
          digitalWrite(L5, LOW);
          win1=2;
          return(win1);
        }
        else
        {
          digitalWrite(L5, LOW);
          return(win1);
        }
    }
    else if(xValue ==3 && yValue == 8)
    {
      Serial.print("LED 5 is OFF");
      digitalWrite(L5, LOW);
      buttonstate=1;
    }
    else
    {
      buttonstate=0;
    }
   }
 }
  else if(xValue ==0 && yValue == 3)
 {
  buttonstate=0;
  Serial.print("LED 6 ON");
  digitalWrite(L6, HIGH);
  count_up1 = 1;
   while(buttonstate == 0)
   {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
     if(digitalRead(sw) == NULL)
     {
      Serial.print("LED 6 is selected");
      digitalWrite(L6, HIGH);
      p2glowl6=1;
      if((p1L1 == 6 || p1L2 == 6) && digitalRead(P2W1) == LOW)
        {
          digitalWrite(P2W1, HIGH);
          digitalWrite(L6, LOW);
          win1=1;
          return(win1);
        }
        else if((p1L1 == 6 || p1L2 == 6) && digitalRead(P2W1) == HIGH)
        {
          digitalWrite(P2W2, HIGH);
          digitalWrite(L6, LOW);
          win1=2;
          return(win1);
        }
        else
        {
          digitalWrite(L6, LOW);
          return(win1);
        }
    }
    else if(xValue !=0 && yValue != 3)
    {
      Serial.print("LED 6 is OFF");
      digitalWrite(L6, LOW);
      buttonstate=1;
    }
    else
    {
      buttonstate=0;
    }
   }
 }
  else if(xValue ==3 && yValue == 0)
 {
  buttonstate=0;
  Serial.print("LED 7 ON");
  digitalWrite(L7, HIGH);
  while(buttonstate == 0)
   {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 7 is selected");
        digitalWrite(L7, HIGH);
        p2glowl7=1;
        if((p1L1 == 7 || p1L2 == 7) && digitalRead(P2W1) == LOW)
          {
            digitalWrite(P2W1, HIGH);
            digitalWrite(L7, LOW);
            win1=1;
            return(win1);
          }
          else if((p1L1 == 7 || p1L2 == 7) && digitalRead(P2W1) == HIGH)
          {
            digitalWrite(P2W2, HIGH);
            digitalWrite(L7, LOW);
            win1=2;
            return(win1);
          }
          else
          {
            digitalWrite(L7, LOW);
            return(win1);
          }
      }
      else if(xValue !=3 && yValue != 0)
      {
        Serial.print("LED 7 is OFF");
        digitalWrite(L7, LOW);
        buttonstate=1;
      }
      else
      {
        buttonstate=0;
      }
   }
 }
}
  return 4;
}

int player1_turn()
{
  buttonstate=0;
  int xValue = analogRead(x);
  int yValue = analogRead(y);
  xValue = map(xValue, 0, 1023, 0, 8);
  yValue = map(yValue, 0, 1023, 0, 8);
  Serial.print("\n X: | ");
  Serial.print(xValue);
  Serial.print("\n Y: | ");
  Serial.print(yValue);
  if(count_up2 == 0)
  {
   if(xValue ==8 && yValue == 3)
   {
     Serial.print("LED 1 ON");
     digitalWrite(L1, HIGH);
     while(buttonstate == 0)
     {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 1 is selected");
        digitalWrite(L1, HIGH);
        p1glowl1=1;
        if((p2L1 == 1 || p2L2 == 1) && digitalRead(P1W1) == LOW)
        {
          Serial.print("\n WIN WIN");
          digitalWrite(P1W1, HIGH);
          digitalWrite(L1, LOW);
          win2=1;
          return(win2);
        }
        else if((p2L1 == 1 || p2L2 == 1) && digitalRead(P1W1) == HIGH)
        {
         digitalWrite(P1W2, HIGH);
          digitalWrite(L1, LOW);
          win2=2;
          return(win2);
        }
        else
        {
          digitalWrite(L1, LOW);
          return(win2);
        }
      }
      else if(xValue ==8 && yValue == 3)
      {
        Serial.print("LED 1 is OFF");
        digitalWrite(L1, LOW);
        buttonstate=1;
      }
      else
      {
        buttonstate=0;
      }
     }
  }
  else if(xValue ==3 && yValue == 8)
  {
    buttonstate=0;
    Serial.print("LED 2 ON");
    digitalWrite(L2, HIGH);
    while(buttonstate == 0)
    {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 2 is selected");
        digitalWrite(L2, HIGH);
        p1glowl2=1;
       if((p2L1 == 2 || p2L2 == 2) && digitalRead(P1W1) == LOW)
        {
          digitalWrite(P1W1, HIGH);
          digitalWrite(L2, LOW);
          win2=1;
          return(win2);
        }
        else if((p2L1 == 2 || p2L2 == 2) && digitalRead(P1W1) == HIGH)
        {
          digitalWrite(P1W2, HIGH);
          digitalWrite(L2, LOW);
          win2=2;
          return(win2);
        }
        else
        {
          digitalWrite(L2, LOW);
          return(win2);
        }
      }
      else if(xValue !=3 && yValue != 8)
      {
        Serial.print("LED 2 is OFF");
        digitalWrite(L2, LOW);
        buttonstate=1;
      }
      else
      {
        buttonstate=0;
      }
     }
  }
  else if(xValue ==0 && yValue == 3)
  {
    buttonstate=0;
    Serial.print("LED 3 ON");
    digitalWrite(L3, HIGH);
    count_up2 = 1;
    while(buttonstate == 0)
    {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 3 is selected");
        digitalWrite(L3, HIGH);
        p1glowl3=1;
        if((p2L1 == 3 || p2L2 == 3) && digitalRead(P1W1) == LOW)
        {
          digitalWrite(P1W1, HIGH);
          digitalWrite(L3, LOW);
          win2=1;
          return(win2);
        }
        else if((p2L1 == 3 || p2L2 == 3) && digitalRead(P1W1) == HIGH)
        {
          digitalWrite(P1W2, HIGH);
          digitalWrite(L3, LOW);
          win2=2;
          return(win2);
        }
        else
        {
          digitalWrite(L3, LOW);
          return(win2);
        }
      }
      else if(xValue !=0 && yValue != 3)
      {
        Serial.print("LED 3 is OFF");
        digitalWrite(L3, LOW);
        buttonstate=1;
      }
      else
      {
        buttonstate=0;
      }
    }
  }
  else if(xValue ==3 && yValue == 0)
  {
    buttonstate=0;
    Serial.print("LED 4 ON");
    digitalWrite(L4, HIGH);
    while(buttonstate == 0)
    {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 4 is selected");
        digitalWrite(L4, HIGH);
        p1glowl4=1;
       if((p2L1 == 4 || p2L2 == 4) && digitalRead(P1W1) == LOW)
        {
          digitalWrite(P1W1, HIGH);
          digitalWrite(L4, LOW);
          win2=1;
          return(win2);
        }
        else if((p2L1 == 4 || p2L2 == 4) && digitalRead(P1W1) == HIGH)
        {
          digitalWrite(P1W2, HIGH);
          digitalWrite(L4, LOW);
          win2=2;
          return(win2);
        }
        else
        {
          digitalWrite(L4, LOW);
          return(win2);
        }
      }
      else if(xValue !=3 && yValue != 0)
      {
        Serial.print("LED 4 is OFF");
        digitalWrite(L4, LOW);
        buttonstate=1;
      }
      else
      {
        buttonstate=0;
      }
    }
  }
 }
 else
 {
   if(xValue ==8 && yValue == 3)
  {
    buttonstate=0;
    Serial.print("LED 1 ON");
    digitalWrite(L1, HIGH);
    count_up2 = 0;
    while(buttonstate == 0)
    {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 1 is selected");
        digitalWrite(L1, HIGH);
        p1glowl1=1;
        if((p2L1 == 1 || p2L2 == 1) && digitalRead(P1W1) == LOW)
        {
          digitalWrite(P1W1, HIGH);
          digitalWrite(L1, LOW);
          win2=1;
          return(win2);
        }
        else if((p2L1 == 1 || p2L2 == 1) && digitalRead(P1W1) == HIGH)
        {
          digitalWrite(P1W2, HIGH);
          digitalWrite(L1, LOW);
          win2=2;
          return(win2);
        }
        else
        {
          digitalWrite(L1, LOW);
          return(win2);
        }
      }
      else if(xValue !=8 && yValue != 3)
      {
        Serial.print("LED 1 is OFF");
        digitalWrite(L1, LOW);
        buttonstate=1;
      }
      else
      {
        buttonstate=0;
      }
     }
  }
  else if(xValue ==3 && yValue == 8)
 {
  buttonstate=0;
  Serial.print("LED 5 ON");
  digitalWrite(L5, HIGH);
  while(buttonstate == 0)
  {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
       if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 5 is selected");
        digitalWrite(L5, HIGH);
        p1glowl5=1;
        if((p2L1 == 5 || p2L2 == 5) && digitalRead(P1W1) == LOW)
          {
            digitalWrite(P1W1, HIGH);
            digitalWrite(L5, LOW);
            win2=1;
            return(win2);
          }
          else if((p2L1 == 5 || p2L2 == 5) && digitalRead(P1W1) == HIGH)
          {
            digitalWrite(P1W2, HIGH);
            digitalWrite(L5, LOW);
            win2=2;
            return(win2);
          }
          else
          {
            digitalWrite(L5, LOW);
            return(win2);
          }
      }
      else if(xValue !=3 && yValue != 8)
      {
        Serial.print("LED 5 is OFF");
        digitalWrite(L5, LOW);
        buttonstate=1;
      }
      else
      {
        buttonstate=0;
      }
     }
 }
  else if(xValue ==0 && yValue == 3)
 {
  buttonstate=0;
  Serial.print("LED 6 ON");
  digitalWrite(L6, HIGH);
  count_up2 = 1;
  while(buttonstate == 0)
  {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
       if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 6 is selected");
        digitalWrite(L6, HIGH);
        p1glowl6=1;
       if((p2L1 == 6 || p2L2 == 6) && digitalRead(P1W1) == LOW)
          {
            digitalWrite(P1W1, HIGH);
            digitalWrite(L6, LOW);
            win2=1;
            return(win2);
          }
          else if((p2L1 == 6 || p2L2 == 6) && digitalRead(P1W1) == HIGH)
          {
            digitalWrite(P1W2, HIGH);
            digitalWrite(L6, LOW);
            win2=2;
            return(win2);
          }
          else
          {
            digitalWrite(L6, LOW);
            return(win2);
          }
      }
      else if(xValue !=0 && yValue != 3)
      {
        Serial.print("LED 6 is OFF");
        digitalWrite(L6, LOW);
        buttonstate=1;
      }
      else
      {
        buttonstate=0;
      }
     }
 }
 else if(xValue ==3 && yValue == 0)
 {
  buttonstate=0;
  Serial.print("LED 7 ON");
  digitalWrite(L7, HIGH);
  while(buttonstate == 0)
  {
      int xValue = analogRead(x);
      int yValue = analogRead(y);
      xValue = map(xValue, 0, 1023, 0, 8);
      yValue = map(yValue, 0, 1023, 0, 8);
      if(digitalRead(sw) == NULL)
      {
        Serial.print("LED 7 is selected");
        digitalWrite(L7, HIGH);
        p1glowl7=1;
        if((p2L1 == 7 || p2L2 == 7) && digitalRead(P1W1) == LOW)
          {
            digitalWrite(P1W1, HIGH);
            digitalWrite(L7, LOW);
            win2=1;
            return(win2);
          }
          else if((p2L1 == 7 || p2L2 == 7) && digitalRead(P1W1) == HIGH)
          {
            digitalWrite(P1W2, HIGH); 
            digitalWrite(L7, LOW);
            win2=2;
            return(win2);
          }
          else
          {
            digitalWrite(L7, LOW);
            return(win2);
          }
      }
      else if(xValue !=3 && yValue != 0)
      {
        Serial.print("LED 7 is OFF");
        digitalWrite(L7, LOW);
        buttonstate=1;
      }
      else
      {
        buttonstate=0;
      }
    }
  }
 }
  return 4;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(sw,INPUT_PULLUP);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
  pinMode(L6, OUTPUT);
  pinMode(L7, OUTPUT);
  pinMode(sw_P1, INPUT);
  pinMode(sw_P2, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(P1W1, OUTPUT);
  pinMode(P1W2, OUTPUT);
  pinMode(P2W1, OUTPUT);
  pinMode(P2W2, OUTPUT);
  digitalWrite(P1W1, LOW);
  digitalWrite(P1W2, LOW);
  digitalWrite(P2W1, LOW);
  digitalWrite(P2W2, LOW);
  digitalWrite(sw_P1, LOW);
  digitalWrite(sw_P2, LOW);
  digitalWrite(buzzer, LOW);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(player1<1)
  {
     p1L1 = selection1();
  }
  else if(player1 == 1)
  {
     p1L2 = selection1();
      Serial.print("PLAYER 1 LED 2 : |");
     Serial.print(p1L2);
  }
  else if (digitalRead(sw_P1) == HIGH)
  {
    Serial.print("ENTER");
    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
    digitalWrite(L3, LOW);
    digitalWrite(L4, LOW);
    digitalWrite(L5, LOW);
    digitalWrite(L6, LOW);
    digitalWrite(L7, LOW);
    sw1pressed=1;
  }
  else if (digitalRead(sw_P2) == HIGH)
  {
    sw2pressed=1;
    Serial.print("value of switch : |");
    Serial.print(sw2pressed);
    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
    digitalWrite(L3, LOW);
    digitalWrite(L4, LOW);
    digitalWrite(L5, LOW);
    digitalWrite(L6, LOW);
    digitalWrite(L7, LOW);
  }
  if (sw1pressed == 1)
  {
       if(player2<1)
      {
        p2L1 = selection2();
        Serial.print("PLAYER 2 LED 1 : |");
       Serial.print(p2L1);
      }
      else if(player2 == 1)
      {
        p2L2 = selection2();
        Serial.print("PLAYER 2 LED 2 : |");
        Serial.print(p2L2);
      }
  }
  if(sw2pressed == 1)
  {
    while (turn == 0)
    {
      if(result2 == 2)
      {
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        sw2pressed=0;
        turn = 4;
        break;
      }
      if(p1glowl1 == 1)
      {
        digitalWrite(L1,HIGH);
      }
      if(p1glowl2 == 1)
      {
        digitalWrite(L2,HIGH);
      }
      if(p1glowl3 == 1)
      {
        digitalWrite(L3,HIGH);
      }
      if(p1glowl4 == 1)
      {
        digitalWrite(L4,HIGH);
      }
      if(p1glowl5 == 1)
      {
        digitalWrite(L5,HIGH);
      }
      if(p1glowl6 == 1)
      {
        digitalWrite(L6,HIGH);
      }
      if(p1glowl7 == 1)
      {
        digitalWrite(L7,HIGH);
      }
      result1 = player1_turn();
      Serial.print("\n RESULT PLAYER 1 : |");
      Serial.print(result1);
      if(result1 == 4)
      {
        turn = 0;
      }
      else
      {
        turn = 1;
        digitalWrite(L1, LOW);
        digitalWrite(L2, LOW);
        digitalWrite(L3, LOW);
        digitalWrite(L4, LOW);
        digitalWrite(L5, LOW);
        digitalWrite(L6, LOW);
        digitalWrite(L7, LOW);
        delay(1000);
      }
    }
    while (turn == 1) 
    {
      if(result1 == 2)
      {
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        turn = 4;
        sw2pressed=0;
        break;
      }
      if(p2glowl1 == 1)
      {
        digitalWrite(L1,HIGH);
      }
      if(p2glowl2 == 1)
      {
        digitalWrite(L2,HIGH);
      }
      if(p2glowl3 == 1)
      {
        digitalWrite(L3,HIGH);
      }
      if(p2glowl4 == 1)
      {
        digitalWrite(L4,HIGH);
      }
      if(p2glowl5 == 1)
      {
        digitalWrite(L5,HIGH);
      }
      if(p2glowl6 == 1)
      {
        digitalWrite(L6,HIGH);
      }
      if(p2glowl7 == 1)
      {
        digitalWrite(L7,HIGH);
      }
        result2 = player2_turn();
        if(result2 == 4)
        {
          turn = 1;
        }
        else
        {
          turn = 0;
          digitalWrite(L1, LOW);
          digitalWrite(L2, LOW);
          digitalWrite(L3, LOW);
          digitalWrite(L4, LOW);
          digitalWrite(L5, LOW);
          digitalWrite(L6, LOW);
          digitalWrite(L7, LOW);
          delay(1000);
        }
    }
    
   
  }
}