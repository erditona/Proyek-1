//Include the library files
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
bool pirbutton = 0;

//Define the relay pins
#define relay1 D0
#define relay2 D1
#define PIR D2

//Define Blynk
#define BLYNK_AUTH_TOKEN "9HwmkdD5sMRfLK0OrhXhMaxJqYfsnzdI" //Enter your blynk auth token
char auth[] = BLYNK_AUTH_TOKEN ;
char ssid[] = "Ditoo";//Enter your WIFI name
char pass[] = "";//Enter your WIFI password


//Get the button values
BLYNK_WRITE(V0) {
  bool value1 = param.asInt();
  // Check these values and turn the relay1 ON and OFF
  if (value1 == 1) {
    digitalWrite(relay1, LOW);
    Blynk.logEvent("r1on", "Relay 1 ON !!!");
  } else {
    digitalWrite(relay1, HIGH);
    Blynk.logEvent("r1off", "Relay 1 OFF !!!");
  }
}

//Get the button values
BLYNK_WRITE(V1) {
  bool value2 = param.asInt();
  // Check these values and turn the relay2 ON and OFF
  if (value2 == 1) {
    digitalWrite(relay2, LOW);
    Blynk.logEvent("r2on", "Relay 2 ON !!!");
  } else {
    digitalWrite(relay2, HIGH);
    Blynk.logEvent("r2off", "Relay 2 OFF !!!");
  }
}

//Get the button values
BLYNK_WRITE(V2) {
  bool allvalue = param.asInt();
  // Check these values and turn the relay2 ON and OFF
  if (allvalue == 1) {
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    Blynk.logEvent("aron", "Semua ON !!!");
  } else {
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    Blynk.logEvent("aroff", "Semua OFF !!!");
  }
}


void setup() {
  //Set the relay pins as output pins
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(PIR, INPUT);
  
  // Turn OFF the relay
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);

  //Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  
}

void loop() {
  //Run the Blynk library
  Blynk.run();
  timer.run();
}
