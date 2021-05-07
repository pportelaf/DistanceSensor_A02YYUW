#include "DistanceSensor_A02YYUW.h"

DistanceSensor_A02YYUW::DistanceSensor_A02YYUW(Stream * stream): DistanceSensor_A02YYUW(stream, MIN_DISTANCE, MAX_DISTANCE) {

}

DistanceSensor_A02YYUW::DistanceSensor_A02YYUW(Stream * stream, unsigned int minDistance, unsigned int maxDistance) {
  _stream = stream;
  _minDistance = minDistance;
  _maxDistance = maxDistance;

}

DistanceSensor_A02YYUW_MEASSUREMENT_STATUS DistanceSensor_A02YYUW::meassure() {
  unsigned long startTime = millis();
  unsigned char data[4] = {};
  int i = 0;
  unsigned int meassuredDistance;

  _flushSerialInput();

  _distance = _minDistance;

  while (!_stream->available() && i < SERIAL_AVAILABLE_CHECK_CICLES) {
    i++;
    delay(SERIAL_AVAILABLE_CHECK_DELAY);
  }

  i = 0;

  while(_stream->available() && i < 4) {
    data[i] = _stream->read();

    i++;

    if (data[0] != SERIAL_HEAD_DATA) {
      i = 0;
    }
  }

  if (i != 4) {
    return DistanceSensor_A02YYUW_MEASSUREMENT_STATUS_ERROR_SERIAL;
  }

  if (!_checkSum(data)) {
    return DistanceSensor_A02YYUW_MEASSUREMENT_STATUS_ERROR_CHECK_SUM;
  }

  meassuredDistance = ((data[1] << 8) + data[2]);

  if (meassuredDistance < _minDistance) {
    return DistanceSensor_A02YYUW_MEASSUREMENT_STATUS_ERROR_MIN_LIMIT;
  }

  if (meassuredDistance > _maxDistance) {
    return DistanceSensor_A02YYUW_MEASSUREMENT_STATUS_ERROR_MAX_LIMIT;
  }

  _distance = meassuredDistance;

  return DistanceSensor_A02YYUW_MEASSUREMENT_STATUS_OK;
}

unsigned int DistanceSensor_A02YYUW::getDistance() {
  return _distance;
}


bool DistanceSensor_A02YYUW::_checkSum(unsigned char data[]) {
  return ((data[0] + data[1] + data[2])& 0x00FF) == data[3];
}

void DistanceSensor_A02YYUW::_flushSerialInput() {
  unsigned long startTime = millis();

  while (_stream->available()) {
    _stream->read();
  }
}
