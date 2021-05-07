/*
 * 
 * Gets the distance from the sensor using a Serial2 every 1 second to print result on Serial Monitor
 *
 */

#include <DistanceSensor_A02YYUW.h>

#define SOFTWARE_SERIAL_PIN_RX 13
#define SOFTWARE_SERIAL_PIN_TX 12

DistanceSensor_A02YYUW distanceSensor(&Serial2);

void setup() {
  Serial2.begin(9600, SERIAL_8N1, SOFTWARE_SERIAL_PIN_RX, SOFTWARE_SERIAL_PIN_TX);
  Serial.begin(9600);
}

void loop() {
  DistanceSensor_A02YYUW_MEASSURE_STATUS meassureStatus;

  // Gets the distance from the sensor and if the measurement is wrong, it retries to get the distance
  do {
    meassureStatus = distanceSensor.meassure();

    if (meassureStatus == DistanceSensor_A02YYUW_MEASSURE_STATUS_OK) {
      Serial.print("Distance: ");
      Serial.println(distanceSensor.getDistance());
    } else {
      Serial.print("Error:" );
      Serial.println(meassureStatus);
    }
  } while (meassureStatus != DistanceSensor_A02YYUW_MEASSURE_STATUS_OK);

  delay(1000);
}
