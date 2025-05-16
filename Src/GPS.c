#include "../Inc/GPS.h"
#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371000

void float_to_str(float num, char* buffer, int precision) {
	  int i,m,p,digit;
    int integer = (int)num;
    float fraction = num - integer;
    i = 0;
    
    if(integer == 0) {
        buffer[i++] = '0';
    } else {
        int temp = integer;
        while(temp > 0) {
            buffer[i++] = (temp % 10) + '0';
            temp /= 10;
        }
        // Reverse the string
        for(m=0; m<i/2; m++) {
            char temp = buffer[m];
            buffer[m] = buffer[i-m-1];
            buffer[i-m-1] = temp;
        }
    }
    
    // Add decimal point
    buffer[i++] = '.';
    
    // Convert fractional part
    for(p=0; p<precision; p++) {
        fraction *= 10;
        digit = (int)fraction;
        buffer[i++] = digit + '0';
        fraction -= digit;
    }
    
    buffer[i] = '\0';
}
float toFloat(char *c, int size){
	int i;
	int j;
	char *ptr = c;
	float result = 0;
	for (j = 0 ; j < size ; j++){
		if(ptr[j] == '.'){
			break;
		}
	}
		for (i = j - 1 ; i>=0 ; i--){
				result += (ptr[i]-48) * pow(10 , (j-1) - i);
		}
		
		for (i = j + 1 ; i < size ; i++){
				result += (ptr[i]-48) * pow(10 , j - i);
		}
		
	return result;
}

//----------------$GPRMC,200751.00,A,4047.32510,N,02929.63031,E,9.879,105.80,301117,,,A*6C-----------------//
int readGPS(char *lat, char *log, char *lat_dir, char *log_dir) {
    char data[100];
    int i = 0, j = 0, commaCount = 0;

    UART5_ReceiveString(data, '\n');  // or '\r'

    // Ensure it starts with $GPRMC
    if (data[0] != '$' || data[1] != 'G' || data[2] != 'P' || data[3] != 'R' || data[4] != 'M' || data[5] != 'C') {
        return -1;
    }

    // Find the status field (3rd comma)
    while (commaCount < 2 && data[i] != '\0') {
        if (data[i++] == ',') commaCount++;
    }

    // Now i points to the start of status field
    if (data[i] != 'A') return -1;  // Check if status is valid

    // Move to next field (Latitude)
    while (data[i++] != ',');  // Skip comma after status

    // Extract latitude
    j = 0;
    while (data[i] != ',' && data[i] != '\0') {
        lat[j++] = data[i++];
    }
    lat[j] = '\0';

    i++; // Move to latitude direction
    *lat_dir = data[i++];
    i++; // Skip comma

    // Extract longitude
    j = 0;
    while (data[i] != ',' && data[i] != '\0') {
        log[j++] = data[i++];
    }
    log[j] = '\0';

    i++; // Move to longitude direction
    *log_dir = data[i];

    return 0;
}

//----------------- Convert GPS coordinates from "ddmm.mmmm" format to decimal degrees ----------------//
float convert_to_decimal_degrees(char *coordinate, char direction)
{
    int degrees = atoi(coordinate) / 100;
    float minutes = toFloat(coordinate,11) - (degrees * 100);
    float decimal_degrees = degrees + (minutes / 60.0);

    /*if (direction == 'S' || direction == 'W')
    {
        decimal_degrees = -decimal_degrees;
    }*/

    return decimal_degrees;
}

//----------- Convert degrees to radians ------------//
float DEG_TO_RAD(float angle)
{
    return angle * PI / 180.0;
}

//---------- Calculate Distance using Haversine formula -------------//
double calcDistance(double lat1, double lon1, double lat2, double lon2)
{
    double phi1 = DEG_TO_RAD(lat1);
    double phi2 = DEG_TO_RAD(lat2);
    double delta_phi = DEG_TO_RAD(lat2 - lat1);
    double delta_lambda = DEG_TO_RAD(lon2 - lon1);

    double a = sin(delta_phi / 2) * sin(delta_phi / 2) +
               cos(phi1) * cos(phi2) *
                   sin(delta_lambda / 2) * sin(delta_lambda / 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

//---------------- Fetch coordinates and convert them ----------------//
void readGPSDouble(double *dlat, double *dlog)
{
    char lat[15], log[15];
    char lat_dir, log_dir;

    while (readGPS(lat, log, &lat_dir, &log_dir) != 0); 
    *dlat = convert_to_decimal_degrees(lat, lat_dir);
    *dlog = convert_to_decimal_degrees(log, log_dir);//
}
