# 🛰️ CSE 211s - GPS Tracking System Project [Spring 2025]

## 📍 Project Title
**GPS-Based Landmark Detection using TM4C123G LaunchPad**

## 🧑‍🏫 Course Information
- **Course:** Introduction to Embedded Systems (CSE 211s)
- **Faculty:** Faculty of Engineering, Ain Shams University
- **Department:** Computer and Systems Engineering
- **Semester:** Spring 2025

## 🧩 Table of Bonuses

| # | Bonus Feature Description | Implemented |
|---|----------------------------|-------------|
| 1 | Used Portable Energy Source (Power Bank) | ✅ |
| 2 | Packaging | ✅ |
| 3 | Buzzer alerts if destination is near (< 15 m) | ✅ |
| 4 | Potentiometer to control LCD Contrast | ✅ |
| 5 | Code separated into `.h` and `.c` files for readability | ✅ |
| 6 | Custom LCD driver built using datasheet | ✅ |

---

## 👥 Contribution List

| Name | ID | Contribution |
|------|----|--------------|
| **Maryam Muhammad ElSayed Mousa** | 2200373 | Main Driver, Testing, Packaging |
| **Manar Atef Anwer** | 2200694 | GPS and Buzzer Drivers, Project Documentation |
| **Malak Sherif Abdelghaffar** | 2200605 | GPS and Buzzer Drivers, Project Documentation |
| **Jumana Waleed Elsayed Muhamed** | 2200362 | GPIO and UART Drivers |
| **Rofayda Alaa Aawadallah** | 2201473 | GPIO and UART Drivers |
| **Abdelrahman Sherif Ali** | 2200645 | SysTick Timer, LCD Driver, Buzzer Driver |
| **Abdallah Khaled Allam** | 2200969 | SysTick Timer, LCD Driver, Buzzer Driver |

---

## 📦 Project Overview

This project implements a real-time GPS tracking system using the TM4C123G microcontroller. It gathers coordinates from a GPS module, compares them against stored landmarks, and displays nearby landmark names on an LCD. A buzzer is used for proximity alerts.

### 🎯 Goals
- Interface a GPS module using UART
- Parse GPS ASCII data and extract coordinates
- Compare current location with predefined faculty landmarks
- Display nearby landmarks and distances on an LCD
- Sound a buzzer when very close to a landmark

---

## 🛠️ Hardware Used
- TM4C123G LaunchPad (Tiva C)
- GPS Module (e.g., NEO-6M)
- 16x2 LCD Display
- Active Buzzer
- Jumper wires, breadboard
- USB Cable for programming
- Optional: Power bank or battery pack (for bonus marks)

---

## 🔌 Connections
| **Component** | **Pin Description** | **TM4C123G Pin** |
|---------------|----------------------|------------------|
| LCD RS        | Register Select       | PB4              |
| LCD EN        | Enable Pin            | PB5              |
| LCD D4-D7     | Data Lines            | PB0–PB3          |
| GPS TX        | Serial Output         | PE4 (UART5 Rx)   |
| Buzzer        | Digital Output        | PF1              |

---

## 💻 Software Used
- **IDE:** Keil µVision
- **Language:** Embedded C
- **Libraries:**
  - `GPS.h` – GPS data parsing and distance calculation
  - `UART.h` – UART5 initialization
  - `LCD.h` – LCD control commands
  - `SysTick.h` – Delay functions
  - `Buzzer.h` – Buzzer control
  - `GPIO.h` – GPIO initialization
  - `Bitwise.h` – Bit manipulation macros
  - `TM4C123GH6PM.h` – Tiva C register definitions

---

## 🧮 How It Works

1. **Initialization:**
   - Configure UART5 for GPS module
   - Setup GPIO for LCD and buzzer
   - Display startup message

2. **GPS Parsing:**
   - Read NMEA sentences from GPS
   - Extract latitude and longitude

3. **Distance Calculation:**
   - Compute distance between current GPS coordinates and each landmark using Haversine formula

4. **Display Logic:**
   - If within 50m of a landmark, show name and distance on LCD
   - If within 15m (`BUZZER_DISTANCE`), activate buzzer

5. **Fallback:**
   - If no nearby landmarks, show “No landmarks nearby” and turn buzzer off

---

## 🗺️ Landmark Coordinates

| **Landmark**        | **Latitude**   | **Longitude**  |
|---------------------|----------------|----------------|
| Credit              | 30.063669      | 31.278422      |
| Loban Workshop      | 30.063354      | 31.279386      |
| Hall C&D            | 30.063880      | 31.280430      |
| Hall A&B            | 30.064176      | 31.280445      |
| Library             | 30.065141      | 31.279957      |
| Fountain            | 30.065614      | 31.278412      |
| Civil               | 30.064372      | 31.277789      |
| Workshop Street     | 30.064929      | 31.279727      |

---

## 📷 Demo

🎥 **Demo Video (One-shot, no cuts)**  
📎 [Watch on Drive](https://drive.google.com/drive/folders/1dnURdzcUv93dDKmu0cbW_O_x28QXpHPa)

---

## 📂 Project Structure
## Folder Structure

### Source Files (`src`)
- `Bitwise.c` – Bitwise operations
- `Buzzer.c` – Buzzer driver
- `firstproject.c` – Main project logic
- `GPIO.c` – GPIO driver
- `GPS.c` – GPS module interface
- `Lcd.c` – LCD driver
- `system_TM4C123.c` – System initialization
- `Systick.c` – SysTick timer for delays
- `UART.c` – UART communication driver

### Header Files (`inc`)
- `Bitwise.h`
- `Buzzer.h`
- `define.h`
- `GPIO.h`
- `GPS.h`
- `Lcd.h`
- `STD.h`
- `Systick.h`
- `tm4c123gh6pm.h` – MCU register definitions
- `UART.h`

---


