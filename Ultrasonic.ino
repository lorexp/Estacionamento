#include <Ultrasonic.h>

#define BUZINA 7
#define TRIG 8
#define ECHO 9
#define led1 3
#define led2 5
#define led3 12
#define led4 13


Ultrasonic ultrasonic(TRIG,ECHO);
void setup() {
  // put your setup code here, to run once:
  pinMode(BUZINA,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int distance = ultrasonic.distanceRead(CM);
  if(distance < 100){
    if(distance <50){
      if(distance < 25){
        if(distance < 10){
          if(distance <5){
          digitalWrite(led2,LOW);
          digitalWrite(led3,LOW);
          digitalWrite(led4,LOW);
          digitalWrite(BUZINA,HIGH);
          digitalWrite(led1,HIGH);
          Serial.println(distance);
          delay(100);
          }else{
          digitalWrite(led2,LOW);
          digitalWrite(led3,LOW);
          digitalWrite(led4,LOW);
          digitalWrite(BUZINA,LOW);
          digitalWrite(led1,HIGH);
          delay(100);
          digitalWrite(BUZINA,HIGH);
          digitalWrite(led1,LOW);
          Serial.println(distance);
          delay(100);
        }
        }
        else{
          digitalWrite(led1,LOW);
          digitalWrite(led3,LOW);
          digitalWrite(led4,LOW);
          Serial.println(distance);
          digitalWrite(BUZINA,LOW);
          digitalWrite(led2,LOW);
          delay(100);
          digitalWrite(led2,HIGH);
          delay(100);
          
        }
      }
      else{
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
        digitalWrite(led4,LOW);
          Serial.println(distance);
          digitalWrite(BUZINA,LOW);
          digitalWrite(led3,LOW);
          delay(100);
          digitalWrite(led3,HIGH);
          delay(100);
    }
  }
  else{
          digitalWrite(led1,LOW);
          digitalWrite(led2,LOW);
          digitalWrite(led3,LOW);
          Serial.println(distance);
          digitalWrite(BUZINA,LOW);
          digitalWrite(led4,LOW);
          delay(100);
          digitalWrite(led4,HIGH);
          delay(100);
  }
  }
}
