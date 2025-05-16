# 🛰️ CSE 211s - GPS Tracking System Project [Spring 2025]

## 📍 Project Title
**GPS-Based Landmark Detection using TM4C123G LaunchPad**

## 🧑‍🏫 Course Information
- **Course:** Introduction to Embedded Systems (CSE 211s)
- **Faculty:** Faculty of Engineering, Ain Shams University
- **Department:** Computer and Systems Engineering
- **Semester:** Spring 2025

## 🧑‍💻 Team Members
- [Member 1 Name] – UART & GPS Parsing
- [Member 2 Name] – LCD Interface & Display
- [Member 3 Name] – Landmark Logic & Distance Calculation
- [Member 4 Name] – Hardware Integration & Buzzer Control
- [Member 5 Name] – Testing & Debugging
- [Member 6 Name] – Documentation & Report Writing
- [Member 7 Name] – GitHub Management & Final Integration

> 📌 Replace each `[Member Name]` with actual team members and their contributions.

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
| LCD RS        | Register Select       | PA5              |
| LCD EN        | Enable Pin            | PA6              |
| LCD D4-D7     | Data Lines            | PA0–PA3          |
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
   - If within 10m (`BUZZER_DISTANCE`), activate buzzer

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

