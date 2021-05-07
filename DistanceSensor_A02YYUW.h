#ifndef DistanceSensor_A02YYUW_H
#define DistanceSensor_A02YYUW_H

#include <Arduino.h>

#define MIN_DISTANCE 30
#define MAX_DISTANCE 4500

#define SERIAL_BAUD_RATE 9600
#define SERIAL_HEAD_DATA 0xff

#define SERIAL_AVAILABLE_CHECK_DELAY 50
#define SERIAL_AVAILABLE_CHECK_CICLES 10 // SERIAL_AVAILABLE_CHECK_DELAY * SERIAL_AVAILABLE_CHECK_CICLES = 500ms

enum {
    DistanceSensor_A02YYUW_MEASSUREMENT_STATUS_OK = 0,
    DistanceSensor_A02YYUW_MEASSUREMENT_STATUS_ERROR_CHECK_SUM = -1,
    DistanceSensor_A02YYUW_MEASSUREMENT_STATUS_ERROR_MAX_LIMIT = -2,
    DistanceSensor_A02YYUW_MEASSUREMENT_STATUS_ERROR_MIN_LIMIT = -3,
    DistanceSensor_A02YYUW_MEASSUREMENT_STATUS_ERROR_SERIAL = -4
};

typedef int DistanceSensor_A02YYUW_MEASSUREMENT_STATUS;

class DistanceSensor_A02YYUW {
  public:
    DistanceSensor_A02YYUW(Stream * _stream);
    DistanceSensor_A02YYUW(Stream * _stream, unsigned int minDistance, unsigned int maxDistance);
    DistanceSensor_A02YYUW_MEASSUREMENT_STATUS meassure();
    unsigned int getDistance();

  private:
    Stream * _stream;
    unsigned int _minDistance;
    unsigned int _maxDistance;
    unsigned int _distance;
    bool _checkSum(unsigned char data[]);
    void _flushSerialInput();
};

#endif
