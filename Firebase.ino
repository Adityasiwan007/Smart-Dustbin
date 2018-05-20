#include <FirebaseArduino.h>

#include  <ESP8266WiFi.h>

#define FIREBASE_HOST "fireapp-98645.firebaseio.com" 
#define WIFI_SSID "tech" // Change the name of your WIFI   //"smartdustbin-81387.firebaseio.com"
#define WIFI_PASSWORD "rathore2" // Change the password of your WIFI

const int echo=2;
const int trig=0;
int distance;
long duration;

void setup() {

 
   WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
   Serial.begin(9600);
   while (WiFi.status() != WL_CONNECTED) 
   {
    delay(500);
    Serial.print(".");
  }
  
  //Serial.println ("");
  //Serial.println ("WiFi Connected!");
  Firebase.begin(FIREBASE_HOST);

  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  
}

void loop() {
 
  distance=calculateDistance();
  Firebase.setFloat ("id/1",distance);
  delay(10000);
}

int calculateDistance()
{
 digitalWrite(trig,LOW);
 delayMicroseconds(2);
 digitalWrite(trig,HIGH);
 delayMicroseconds(10);
 digitalWrite(trig,LOW);
 duration=pulseIn(echo,HIGH);
 distance=(int)duration*0.034/2;
 return distance;
}
