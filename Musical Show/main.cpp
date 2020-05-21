#include <Arduino.h>

#include "Arduino_FreeRTOS.h"
#include "queue.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"

#define LEDB1 5
#define LEDB2 6
#define LEDB3 7
#define LEDR1 8
#define LEDR2 9
#define LEDR3 10
#define LEDG1 11
#define LEDG2 12
#define LEDG3 13

int RedLEDs[3] = {LEDR1, LEDR2, LEDR3};
int BlueLEDs[3] = {LEDB1, LEDB2, LEDB3};
int GreenLEDs[3] = {LEDG1, LEDG2, LEDG3};

TaskHandle_t Redcontrol, Bluecontrol, Greencontrol;

#define BuzzerPin A5     // Connect Buzzer to Arduino pin 11

int Si2 =1975;
int LaS2=1864;
int La2= 1760;
int SolS2=1661;
int Sol2=1567;
int FaS2=1479;
int Fa2= 1396;
int Mi2= 1318;
int ReS2=1244;
int Re2= 1174;
int DoS2=1108;
int Do2= 1046;

// Low Octave
int Si = 987;
int LaS= 932;
int La = 880;
int SolS=830;
int Sol= 783;
int FaS= 739;
int Fa=  698;
int Mi=  659;
int ReS= 622;
int Re = 587;
int DoS =554;
int Do = 523;

// define the notes
int rounda=0;
int roundp=0;
int white= 0;
int whitep=0;
int black=0;  
int blackp=0;
int quaver=0;
int quaverp =0;
int semiquaver=0;
int semiquaverp=0;
int bpm= 120;

int eventcount = 0;
int eventcountresume = 0;
int eventcountblue = 0;

boolean resumecount_blue = false;
boolean resumecount_green = false;

void BlueLEDPattern(void *pvParameter)
{
  while (1)
  {
    for (int i = 0; i < 3; i++)
    {
      if (eventcount >= 15000)
      {
        digitalWrite(BlueLEDs[i], HIGH);
      }
      if(resumecount_green == true)
      {
        eventcountresume++;
        if(eventcountresume >= 15000)
        {
          eventcount = 0;
          resumecount_green = false;
           for (int i = 0; i < 3; i++)
           {
              digitalWrite(BlueLEDs[i], LOW);
           }
          vTaskResume(Redcontrol);
          vTaskResume(Greencontrol);
          // vTaskSuspend(NULL);
        }
        // else if(eventcountresume >= 7120)
        // {
        //   vTaskResume(NULL);
        // }
      }
    }
  }
  
}

void RedLEDPattern(void *pvParameter)
{
  while (1)
  {
    
    eventcount++;
    for (int i = 0; i < 3; i++)
    {
      digitalWrite(RedLEDs[i], digitalRead(RedLEDs[i])^1);
      // vTaskDelay(100);
      if (eventcount >= 15000)
      {
        resumecount_green = true;
        eventcountresume = 0;
        // vTaskResume(Bluecontrol);
        vTaskSuspend(Greencontrol);
        vTaskSuspend(NULL);
      }
    }
  }
}

void GreenLEDPattern(void *pvParameter)
{
  while (1)
  {
    for (int i = 0; i < 3; i++)
    {
      digitalWrite(GreenLEDs[i], digitalRead(GreenLEDs[i])^1);
      // if(eventcount >= 7120)
      // {
      //   resumecount_blue = true;
      //   vTaskSuspend(Bluecontrol);
      // }
    }
  }
}

void song(void *pvParameters)
{
    tone(BuzzerPin,Mi,black);
  delay(black+50);
  tone(BuzzerPin,La,black);
  delay(black+50);
  tone(BuzzerPin,Si,black);
  delay(black+50);
  tone(BuzzerPin,Do2,black);
  delay(black+50);
  tone(BuzzerPin,La,black);
  
  delay(2*white+50);
  
  tone(BuzzerPin,Mi,black);
  delay(black+50);
  tone(BuzzerPin,La,black);
  delay(black+50);
  tone(BuzzerPin,Si,black);
  delay(black+50);
  tone(BuzzerPin,Do2,black);
  delay(black+50);
  tone(BuzzerPin,La,black);
  
  delay(2*white+50);
  
  tone(BuzzerPin,Mi,black);
  delay(black+50);
  tone(BuzzerPin,La,black);
  delay(black+50);
  tone(BuzzerPin,Si,black);
  delay(black+50);
  tone(BuzzerPin,Do2,white*1.3);
  delay(2*black+50);
  
  tone(BuzzerPin,Si,black);
  delay(black+50);
  tone(BuzzerPin,La,black);
  delay(black+50);
  tone(BuzzerPin,Do2,white*1.3);
  delay(2*black+50);
  
  tone(BuzzerPin,Si,black);
  delay(black+50);
  tone(BuzzerPin,La,black);
  delay(black+50);
  tone(BuzzerPin,Mi2,black);
  delay(white+50);
  tone(BuzzerPin,Mi2,black);
  delay(white+100);
  
  tone(BuzzerPin,Mi2,black);
  delay(white+50);
  tone(BuzzerPin,Re2,black);
  delay(black+50);
  tone(BuzzerPin,Mi2,black);
  delay(black+50);
  tone(BuzzerPin,Fa2,black);
  delay(black+50);
  tone(BuzzerPin,Fa2,white*1.3);
  delay(rounda+100);
  
  tone(BuzzerPin,Fa2,black);
  delay(black+50);
  tone(BuzzerPin,Mi2,black);
  delay(black+50);
  tone(BuzzerPin,Re2,black);
  delay(black+50);
  tone(BuzzerPin,Fa2,black);
  delay(black+50);
  tone(BuzzerPin,Mi2,white*1.3);
  delay(rounda+100);
  
  tone(BuzzerPin,Mi2,black);
  delay(black+50);
  tone(BuzzerPin,Re2,black);
  delay(black+50);
   tone(BuzzerPin,Do2,black);
  delay(black+50);
  tone(BuzzerPin,Si,white*1.3);
  delay(white+50);
  tone(BuzzerPin,Mi2,white*1.3);
  delay(white+50);
  tone(BuzzerPin,Si,white*1.3);
  delay(white+50);
  tone(BuzzerPin,Do2,white*1.3);
  delay(white+50);
  tone(BuzzerPin,La,rounda*1.3);
  delay(rounda+50);
}

void setup()
{
  Serial.begin(9600);

  for (int i = 0; i < 3; i++)
  {
    pinMode(RedLEDs[i], OUTPUT);
    pinMode(BlueLEDs[i], OUTPUT);
    pinMode(GreenLEDs[i], OUTPUT);
  }

  // eventcount = xSemaphoreCreateCounting(100,0);

  xTaskCreate (BlueLEDPattern, "BLUE LED Pattern", 100, NULL, 1, &Bluecontrol);
  xTaskCreate (RedLEDPattern, "RED LED Pattern", 100, NULL, 1, &Redcontrol);
  xTaskCreate (GreenLEDPattern, "GREEN LED Pattern", 100, NULL, 1, &Greencontrol);

  pinMode(BuzzerPin,OUTPUT);
      
  black= 35000/bpm; 
  blackp=black*1.5;
  white= black*2;
  whitep=white*1.5;
  rounda= black*4;
  roundp= rounda*1.5;
  quaver= black/2;
  quaverp=quaver*1.5;
  semiquaver= black/4;
  semiquaverp=semiquaver*1.5;

  xTaskCreate(song, "buzzer song", 100, NULL, 1, NULL);

  // xSemaphoreGive(eventcount);
  
}


void loop()
{}


