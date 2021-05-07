# DistanceSensor_A02YYUW
Library for ultrasonic distance sensor [A02YYUW](https://wiki.dfrobot.com/A02YYUW%20Waterproof%20Ultrasonic%20Sensor%20SKU:%20SEN0311)

## Table of Contents

* [Methods](#methods)
* [Meassurement status](#meassurement-status)
* [Installation](#installation)

## Methods
```C++
/*
 * @brief Try to get the sensor distance
 *
 * @return The meassurement status
 */
DistanceSensor_A02YYUW_MEASSUREMENT_STATUS meassure();

/*
 * @brief Gets the last meassured distance
 *
 * @return The last meassured distance in millimeters
 */
unsigned int getDistance();
```

## Meassurement status
| DistanceSensor_A02YYUW_MEASSUREMENT_STATUS                 | Value | Description                     |
|------------------------------------------------------------|:-----:|---------------------------------|
| DistanceSensor_A02YYUW_MEASSUREMENT_STATUS_OK              |   0   | Meassurement ok                 |
| DistanceSensor_A02YYUW_MEASSUREMENT_STATUS_ERROR_CHECK_SUM |   -1  | Error in checksum               |
| DistanceSensor_A02YYUW_MEASSUREMENT_STATUS_ERROR_MAX_LIMIT |   -2  | Error distance bellow the limit |
| DistanceSensor_A02YYUW_MEASSUREMENT_STATUS_ERROR_MIN_LIMIT |   -3  | Error distance above the limit  |
| DistanceSensor_A02YYUW_MEASSUREMENT_STATUS_ERROR_SERIAL    |   -4  | Error with Serial               |

https://www.arduino.cc/en/Guide/Libraries

## Installation
https://www.arduino.cc/en/Guide/Libraries
