
#define trigger 8
#define echo 9
#define buzzer 7
#define LEDstart 10
#define LED5 11
#define LED10 12
#define LED15 13
#define LED20 6

int i=0; 

void setup() {
  // put your setup code here, to run once:
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(LEDstart, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED10, OUTPUT);
  pinMode(LED15, OUTPUT);
  pinMode(LED20, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, dist;
  digitalWrite(trigger, HIGH);
  delay(1000);
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo, HIGH);
  dist = (duration/2)/29.1;
  delay(10);
 if(dist <= 50 && i==0)
 {
  digitalWrite(LEDstart, HIGH);
  delay(5000);
  digitalWrite(LED5, HIGH);
  delay(5000);
  digitalWrite(LED5, LOW);
  digitalWrite(LED10, HIGH);
  delay(5000);
  digitalWrite(LED10, LOW);
  digitalWrite(LED15, HIGH);
  delay(5000);
  digitalWrite(LED15, LOW);
  digitalWrite(LED20, HIGH);
  for (int j=0; j<5; j++)
  {
      digitalWrite(buzzer, HIGH);
      delay(10);
     digitalWrite(buzzer, LOW);
     delay(1000);
  }
  digitalWrite(buzzer, HIGH);
  i=1;
 }
 long duration1, dist1;
  digitalWrite(trigger, HIGH);
  delay(1000);
  digitalWrite(trigger, LOW);
  duration1 = pulseIn(echo, HIGH);
  dist1 = (duration1/2)/29.1;
  if (dist1<=50 && i==1)
  {
     digitalWrite(LED20, LOW);
    digitalWrite(buzzer, LOW);
    digitalWrite(LEDstart, LOW);
    i=0;
  }
  
}
