/*
 * 
 * Gets the distance from the sensor using a Software Serial every 1 second to print result on Serial Monitor
 *
 */

#include <DistanceSensor_A02YYUW.h>
#include <SoftwareSerial.h>

#define SOFTWARE_SERIAL_PIN_RX 11
#define SOFTWARE_SERIAL_PIN_TX 10

SoftwareSerial mySerial(SOFTWARE_SERIAL_PIN_RX, SOFTWARE_SERIAL_PIN_TX);
DistanceSensor_A02YYUW distanceSensor(&mySerial);

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  DistanceSensor_A02YYUW_MEASSUREMENT_STATUS meassurementStatus;

  // Gets the distance from the sensor and if the measurement is wrong, it retries to get the distance
  do {
    meassurementStatus = distanceSensor.meassure();

    if (meassurementStatus == DistanceSensor_A02YYUW_MEASSUREMENT_STATUS_OK) {
      Serial.print("Distance: ");
      Serial.println(distanceSensor.getDistance());
    } else {
      Serial.print("Error:" );
      Serial.println(meassurementStatus);
    }
  } while (meassurementStatus != DistanceSensor_A02YYUW_MEASSUREMENT_STATUS_OK);

  delay(1000);
}
