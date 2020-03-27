#include <Arduino_FreeRTOS.h>

#define sw 2
#define x A0
#define y A1
#define l1 5
#define l2 6 
#define l3 7
#define l4 8
#define l5 9
#define l6 10
#define l7 11
#define l8 12
#define buzzer 13
#define b1 A4
#define b2 3
#define commonLED A5

const int arrsize = 4;
int column1[arrsize] = {l1,l2,l3,l4};
int column2[arrsize] = {l5,l6,l7,l8};
int i,k, temp1,temp2;
int speed1 = 200;
int speed2 = 200;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
   xTaskCreate(REDcolumn,
             "Throgh light from column1",
             100,
             NULL,
             1,
             NULL);
   xTaskCreate(BLUEcolumn,
             "Throgh light from column2",
             100,
             NULL,
             1,
             NULL);
}

void REDcolumn(void *pvParameters)
{
  for(i=0;i<arrsize;i++)
  {
    pinMode(column1[i], OUTPUT);
  }
  pinMode(buzzer,OUTPUT);
  pinMode(b1,INPUT);
  pinMode(commonLED,OUTPUT);

  while(1)
  {
   if (digitalRead(b1) == 1)
    {
      for(i=0;i<arrsize;i++)
      {
        temp1=0;
        digitalWrite(column1[i], HIGH);
        delay(speed1);
        digitalWrite(column1[i], LOW);
        speed1=speed1-10;
        if (speed1 == 10)
        {
          speed1 = 20;
        }
        if (analogRead(y)>950 &&  analogRead(y)<=1023)
        {
          break;
        }
        else
        {
           temp1=1; 
        }
       }
       if(i == 4 && temp1 == 1)
       {
        digitalWrite(commonLED, HIGH);
        delay(100);
        digitalWrite(buzzer,HIGH);
        delay(500);
        digitalWrite(buzzer,LOW);
       }
      }
  }
}

void BLUEcolumn(void *pvParameters)
{
  for(k=0;k<arrsize;k++)
  {
    pinMode(column1[k], OUTPUT);
  }
  pinMode(buzzer,OUTPUT);
  pinMode(b2,INPUT);
  pinMode(commonLED,OUTPUT);

  while(1)
  {
    if(digitalRead(b2) == 1)
      {
        for(k=0;k<arrsize;k++)
        {
          temp2=0;
          digitalWrite(column2[k], HIGH);
          delay(speed2);
          digitalWrite(column2[k], LOW);
          speed2=speed2-10;
          if(speed2 == 10)
          {
            speed2 = 20;
          }
          if (analogRead(y)>= 0 && analogRead(y)<100)
          {
            break;
          }
          else
          {
            temp2=1;
          }
      }
      if(k == 4 && temp2 == 1)
      {
        digitalWrite(commonLED, HIGH);
        delay(100);
        digitalWrite(buzzer,HIGH);
        delay(500);
        digitalWrite(buzzer,LOW);

      }
  }
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
