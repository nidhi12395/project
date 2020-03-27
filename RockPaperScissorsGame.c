#define l1 4
#define l2 12
#define l3 13
#define b1 8
#define b2 2
#define l4 9
#define l5 7
#define l6 5
#define p2 11
#define p1 10
#define d 6

#define arrsize 3
#define arrsize1 3

int ledstatus;
int ledstatus1;
int i;
int j;
int c;
int c1;

int arr[arrsize] = {l1,l2,l3};
int arr1[arrsize1] = {l4,l5,l6};

void initialize()
{
  for(i=0; i<arrsize; i++)
  {
     digitalWrite(arr[i], LOW);
  }
  for(j=0; j<arrsize1; j++)
  {
    digitalWrite(arr1[j], LOW);
  }
 digitalWrite(p1, LOW);
 digitalWrite(p2, LOW);
 digitalWrite(d, LOW);
}

int work()
{
  
    for(i=0; i<arrsize; i++)
      {
        if (digitalRead(b1)==HIGH)
        {
          digitalWrite(arr[i], HIGH);
          delay(10);
          digitalWrite(arr[i], LOW);
          delay(10);
          ledstatus=i+1;
      }
  }
      
  
  return ledstatus;  
}

int work1()
{
           for(j=0; j<arrsize1; j++)
           {
            if (digitalRead(b2)==HIGH)
            {
              digitalWrite(arr1[j], HIGH);
             delay(10);
              digitalWrite(arr1[j], LOW);
              delay(10);
              ledstatus1=j+1;
          }
      }
 
  
  return ledstatus1;  
}

void mode()
{
  for(i=0; i<arrsize; i++)
  {
    pinMode(arr[i], OUTPUT);
  }
  for(j=0; j<arrsize1; j++)
  {
    pinMode(arr1[j], OUTPUT);
  }
  
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(d, OUTPUT);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(250000);
  mode();
  initialize();

}

void loop() {
  // put your main code here, to run repeatedly:
 
 while (digitalRead(b1)== HIGH || digitalRead(b2)== HIGH)
 {
    c1=work1();
    c=work();
 }

  
  if (c == 1 && c1 == 1 && false)
  {
    digitalWrite(d, HIGH);
    digitalWrite(l1, HIGH);
    digitalWrite(l4, HIGH); 
  }
  else if (c == 2 && c1 == 2)
  {
     digitalWrite(d, HIGH);
    digitalWrite(l2, HIGH);
    digitalWrite(l5, HIGH);
    
  }
  else if (c == 3 && c1 == 3)
  {
    digitalWrite(d, HIGH);
    digitalWrite(l3, HIGH);
    digitalWrite(l6, HIGH);
     
  }
  else if (c == 1 && c1 == 2)
  {
    digitalWrite(p1, HIGH);
    digitalWrite(l1, HIGH);
    digitalWrite(l5, HIGH);
  }
  else if (c == 2 && c1 == 1)
  {
    digitalWrite(p2, HIGH);
    digitalWrite(l2, HIGH);
    digitalWrite(l4, HIGH);
  }
  else if (c == 2 && c1 == 3)
  {
    digitalWrite(p1, HIGH);
    digitalWrite(l2, HIGH);
    digitalWrite(l6, HIGH);
  }
  else if (c == 3 && c1 == 2)
  {
    digitalWrite(p2, HIGH);
    digitalWrite(l3, HIGH);
    digitalWrite(l5, HIGH);
  }
  else if (c == 3 && c1 == 1)
  {
    digitalWrite(p1, HIGH);
    digitalWrite(l3, HIGH);
    digitalWrite(l4, HIGH);
  }
  else if (c == 1 && c1 == 3)
  {
    digitalWrite(p2, HIGH);
    digitalWrite(l1, HIGH);
    digitalWrite(l4, HIGH);
  }
  else
  {
    digitalWrite(p1, LOW);
    digitalWrite(p2, LOW);
    digitalWrite(d, LOW);
  }
}
