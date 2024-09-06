#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

const char* ssid = "vinay hiremath2";
const char* password = "venom12345";

WiFiClient client;

unsigned long myChannelNumber = 2371856;
const char * myWriteAPIKey = "8ZW3FBKVNSHGL4BQ";
const char * myReadAPIKey = "9ITM3DQPYQY2M4FJ";

int led_1;
int led_2;
int led_3;
int led_4;

int ir1 = D0;
int led1 = D5;

int ir2 = D1;
int led2 = D6;
int led3 = D7;
int led4 = D8;

int ldr = A0;
int val =0;

void setup() {
  Serial.begin(9600);
  delay(50);
  pinMode(ir1,INPUT);
  pinMode(led1,OUTPUT);

  pinMode(ir2,INPUT);
  pinMode(led2,OUTPUT);
  
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
 

  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
}

void loop() {
  int s1 = digitalRead(ir1);
  int s2 = digitalRead(ir2);
  
  val = analogRead(ldr);

  Serial.print(s1);
  Serial.print(":");
  Serial.print(s2);
  Serial.print(" ");
  
  Serial.println(val);
  if(val<70)
  {
    if(s1==0)
    {
      digitalWrite(led2,LOW);
      digitalWrite(led4,LOW);
    }
    else
    {
      digitalWrite(led2,HIGH);
      digitalWrite(led4,HIGH);
    }
    if(s2==0)
    {
      digitalWrite(led1,LOW);
      digitalWrite(led3,LOW);
    }
    else
    {
      digitalWrite(led1,HIGH);
      digitalWrite(led3,HIGH);
    }
  }
  else
  {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    
  }

  ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 2,s1, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 3,s2, myWriteAPIKey);

  ThingSpeak.writeField(myChannelNumber, 5,led1, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 6,led2, myWriteAPIKey);
 

 
  if(led_1==1)
  {
    digitalWrite(led1,HIGH);
  }
  else
  {
    digitalWrite(led1,LOW);
  }

  if(led_2==1)
  {
    digitalWrite(led2,HIGH);
  }
  else
  {
    digitalWrite(led2,LOW);
  }
  if(led_3==1)
  {
    digitalWrite(led3,HIGH);
  }
  else
  {
    digitalWrite(led3,LOW);
  }
  if(led_4==1)
  {
    digitalWrite(led4,HIGH);
  }
  else
  {
    digitalWrite(led4,LOW);
  }
}