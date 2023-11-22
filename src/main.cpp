
#include <Arduino.h>
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");

  pinMode(2, INPUT_PULLUP);

  bleKeyboard.begin();
}

void loop() {
  static int counter = 0;
  if(bleKeyboard.isConnected()) {
    if (digitalRead(2) == LOW){
      Serial.print("STOP ");
      Serial.println(counter++);
      bleKeyboard.write(KEY_MEDIA_STOP);
      delay(1000);
    } else {
      delay(50);
    }
  } else {
    Serial.println("Waiting 1 second...");
    delay(1000);
  }
}
