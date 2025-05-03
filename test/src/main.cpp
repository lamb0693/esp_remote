#include <Arduino.h>

int myFunction(int, int);

int count = 0;

void setup() {
    Serial.begin(115200);
    Serial.println("Hello from ESP32!");
    int result = 2 + 3;
    Serial.print("2 + 3 = ");
    Serial.println(result);
}

void loop() {
    delay(1000);  // <-- 여기를 delay로!
    count++;
    Serial.print("count = ");
    Serial.println(count);
}

int myFunction(int x, int y) {
  return x + y;
}
