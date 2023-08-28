#define BLYNK_TEMPLATE_ID "TMPL6Ds3mWukr"
#define BLYNK_TEMPLATE_NAME "Fire alert"
#define BLYNK_AUTH_TOKEN "KkpjginJQvJ_RWjJvqX9SxGsvIA-dBbV"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "HCK Connect";  // type your wifi name
char pass[] = "#erald77";  // type your wifi password

BlynkTimer timer;
int flag = 0;

void sendSensor() {
  int isButtonPressed = digitalRead(D2); // Use the correct Dx pin number here
  if (isButtonPressed == 0 && flag == 0) {
    Serial.println("Fire in the car");
    Blynk.logEvent("fire_alert", "Fire Detected");
    flag = 1;
  } else if (isButtonPressed == 1) {
    flag = 0;
  }
}

void setup() {
  pinMode(D2, INPUT); // Use the correct Dx pin number here
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(5000L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}