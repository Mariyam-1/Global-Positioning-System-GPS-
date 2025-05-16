#include "TM4C123GH6PM.h"
#include "UART.h"
#include <math.h>
#include "Bitwise.h"
#include <string.h>
#include "LCD.h"
#include "Systick.h"
#include "GPIO.h"
#include <string.h>
#include <math.h>
#include "stdlib.h"
#include "UART.h"
int readGPS(char* lat, char* log, char* lat_dir, char* log_dir) ;
float convert_to_decimal_degrees(char* coordinate, char direction) ;
float toFloat(char *c, int size);
float DEG_TO_RAD(float angle) ;
double calcDistance(double lat1, double lon1, double lat2, double lon2);
void readGPSDouble(double* dlat, double* dlog);
void float_to_str(float num, char* buffer, int precision);