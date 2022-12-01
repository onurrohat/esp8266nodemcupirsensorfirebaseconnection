//int Status = 7;  // Digital pin D6



#include <ArduinoJson.h>
#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>

int sensor = 13 ;  // Digital pin D7


String mydata; // sending integer data as string ,sensor data can also be send as integer
String motion = "detected";   // string which stores state - motion/no motion
String nomotion="nomotion";
int sdata = 0; // PIR sensor  value will be stored in sdata.


FirebaseData firebaseData ;


//#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
//#include "addons/RTDBHelper.h"

// Insert your network credentials
#define WIFI_SSID "TurkTelekom_Z3RYN"
#define WIFI_PASSWORD "512DDD167F7A5"
// Insert Firebase project API Key
#define FIREBASE_AUTH  "2G1cAvbGTAo6zRiPhcYeOo5L9o5JcF0rTtpsmhlC"

// Insert RTDB URLefine the RTDB URL *//
#define FIREBASE_HOST "pirsensor-b1ff2-default-rtdb.firebaseio.com" 



void setup() {

  
  Serial.begin(9600);
  //Provide the token generation process info.
  int val = 0;  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED)
      {
    Serial.print(".");
    delay(500);
      }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
 
}


void loop() {


  //sdata = digitalRead(sensor);
  //mydata = String(sdata); 
  //Serial.println(mydata);//printing string to verify whether sensor is working or not  
  //Firebase.setString("Variable/Value",mydata);//A string will be sent to real time database under variable /value (user need not create this in advance)
 
    long state = digitalRead(sensor);
    if(state == HIGH) {

      
      Serial.println("Motion detected!");
      //Serial.println(state);
      Firebase.setString(firebaseData,"State",motion);//A string will be sent to real time database under state- alert -ex -  motion , no motion 
      delay(100);
       
 }
    
    else {
      
      Serial.println("Motion absent!");
       Firebase.setString(firebaseData, "State",nomotion);
      delay(100);
       
      }

}      