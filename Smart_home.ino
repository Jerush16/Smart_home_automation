#define BLYNK_TEMPLATE_ID "TMPL3TbMqt37m"
#define BLYNK_TEMPLATE_NAME "Smart home"
#define BLYNK_AUTH_TOKEN "dQr9O5xY3QxQZT4xOVUeSfjywrPbplWu"

#include <WiFi.h>
#include <DHT.h>
#include <BlynkSimpleEsp32.h>
#include <WiFiManager.h>
#include <DNSServer.h>
#include <WebServer.h>

#define pir_pin 14
#define temp 21
#define led1 4
#define led2 13
//#define relay
BlynkTimer timer;
DHT dht(temp,DHT11);
WiFiManager wm;

void wificonnect(){
  //wm.resetSettings();  //Uncomment it to reset the wifi device connected
  bool success=wm.autoConnect("Jerush","123456789");   //('wifi name','password') for the esp32 setup //here it gives the status of the wifi whether it is connected  or not using the already saved wifi and password automaticallly
  if(!success){
    Serial.println("Failed to connect or hit timeout.Restarting .......");
    delay(3000);
    ESP.restart();
  }
  Serial.println();     //prints this section if wifi is connected successfully
  Serial.println("Wifi connected successfully via Wifi Manager!");
  Serial.print("IP address: ");
  Serial.print(WiFi.localIP());
}

void detectperson(){    //using pir sensor to detect presence and glow a led
  int pir_state=digitalRead(pir_pin);
    if(pir_state==1){
      Blynk.virtualWrite(V0,"Presence detected");
      Serial.println("PIR State :Presence detected");
      digitalWrite(led1,HIGH);
    }
    else{
    Blynk.virtualWrite(V0,"No presence detected");
    Serial.println("PIR State :No Presence detected");
    digitalWrite(led1,LOW);
    }
}

void tempdisplay(){     //using temp sensor and displaying the value and switch on the ac switch
  //delay(dht.getMinimumSamplingPeriod());  //for every minimum sapling period time this loop runs again i.e delay is equal to that time 
  delay(50);
  float tempvalue=dht.readTemperature();
  float humidity=dht.readHumidity();
  Blynk.virtualWrite(V1,tempvalue);
  Blynk.virtualWrite(V4,humidity);
  if(isnan(tempvalue) || isnan(humidity)){  //isnan is used to know whether the value of that variable is empty
    Serial.println("Temp sensor not working");
  }
  Serial.print("Humidity :");
  Serial.println(humidity, 2);
  Serial.print("Temperature :");
  Serial.println(tempvalue, 2);       //here it prints the tempvalue and after decimal prints only one value
  if(tempvalue>=35){    //to turn on ac
    Blynk.virtualWrite(V3,1);
    Serial.println("AC turned on");
  }
  else{
    Blynk.virtualWrite(V3,0);
    Serial.println("AC is turned off");
  }
  
}

BLYNK_WRITE(V2){   //using blynk to turn on a led
  int led_state=param.asInt();
  if(led_state==1){
    digitalWrite(led2,HIGH);
    Serial.println("Using blynk led turned on");
  }
  else{
    digitalWrite(led2,LOW);
    Serial.println("Using blynk led turned off");
  }
}

void setup(){
  Serial.begin(115200);
  pinMode(led1,OUTPUT);
  //pinMode(relay,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(pir_pin,INPUT);
  pinMode(temp,INPUT);
  dht.begin();
  wificonnect();
  timer.setInterval(50L,detectperson);
  timer.setInterval(25L,tempdisplay);
}

void loop(){
  Blynk.run();
  timer.run();
}