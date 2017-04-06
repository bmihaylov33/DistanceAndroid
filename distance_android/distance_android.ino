#include <NewPing.h>

#define TRIGGER_PIN 9    //Arduino pint tied to trigger pin
#define ECHO_PIN 8       //Arduino pin tied to echo pin
#define MAX_DISTANCE 250 //Maximum distance to ping (in cm)

char command;
char sending;
String string;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(9600);
}

void loop() {
  sendDistanceValue();
  delay(100);
}

void sendDistanceValue() {
  Serial.print('#');                  //puts # before the values so our app knows what to do with the data
  delay(50);                          // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping();     // Send ping, get ping time in microseconds (uS).
  Serial.print(sonar.convert_cm(uS)); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
  Serial.print('~');                  //used as an end of transmission character - used in app for string length
  Serial.println();
  delay(500);
}
