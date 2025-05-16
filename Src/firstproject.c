 #include "../Inc/TM4C123GH6PM.h"
#include "../Inc/GPS.h"
#include "../Inc/LCD.h"
#include "../Inc/UART.h"
#include "../Inc/SysTick.h"
#include "../Inc/Buzzer.h"
#include "../Inc/Bitwise.h"
#include "../Inc/GPIO.h"

#define PROXIMITY_RADIUS 50  

int i;
typedef struct {
    char name[16];
    double latitude;
    double longitude;
} Landmark;

const Landmark landmarks[] = {
    {"Credit", 30.063669, 31.278422},
    {"Loban Workshp", 30.063354, 31.279386},
    {"Hall C&D", 30.063880, 31.280430},
    {"Hall A&B", 30.064176, 31.280445},
    {"Library", 30.065141, 31.279957},
    {"Fountain", 30.065614, 31.278412},
    {"Civil", 30.064372, 31.277789},
    {"Workshop street", 30.064929, 31.279727}
};


int main(void) {  
    double lat, log;
    float test;
    char slat[20], slog[20], dist_str[20];
    double currentLat, currentLog;
    int near_flag = 0;
   
    PORTF_Init();
    Buzzer_Init();                  // Initialize buzzer
    SysTick_Init(50000000); 
    UART5_Init();            
    LCD_Init();
    LCD_Clear();
    LCD_PrintString("GPS Tracking");
    SysTick_DelayMs(2000);
    LCD_Clear();


    while(1) {
			
        readGPSDouble(&lat, &log);
        currentLat = lat;
        currentLog = log;
        float_to_str(currentLat, slat, 6);
        float_to_str(currentLog, slog, 6);
        for(i = 0; i < sizeof(landmarks)/sizeof(landmarks[0]); i++) {
            double distance = calcDistance(currentLat, currentLog, 
                                         landmarks[i].latitude, 
                                         landmarks[i].longitude);
            
            if(distance < PROXIMITY_RADIUS) {
                LCD_PrintString("Near:");
                LCD_SetCursor(1, 0);
                LCD_PrintString(landmarks[i].name);
                float_to_str(distance, dist_str, 1);
                LCD_SetCursor(0, 8);
                LCD_PrintString(dist_str);
                LCD_PrintString("m");
                if(distance < BUZZER_DISTANCE) {
                    Buzzer_On();
                    SysTick_DelayMs(500); 
                    Buzzer_Off();
                    SysTick_DelayMs(500); 
                } else {
                    Buzzer_Off();
                }
                
                if(distance > 47) {
                    LCD_PrintString("No landmarks");
                    LCD_SetCursor(1, 0);
                    LCD_PrintString("nearby");
                    SysTick_DelayMs(2000);
                    LCD_Clear();
                }
                
                near_flag = 1;
                SysTick_DelayMs(5000);
                LCD_Clear();
                break;
            }
        }

        if(!near_flag) {
            LCD_PrintString("No landmarks");
            LCD_SetCursor(1, 0);
            LCD_PrintString("nearby");
            Buzzer_Off();
            SysTick_DelayMs(2000);
            LCD_Clear();
        }
    }
}
