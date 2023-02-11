#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
}
int i=0;
void loop() {
  delay(1000); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("WaterTank: ");
  Serial.println(++i);
}