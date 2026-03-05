# NFC Smart Attendance System using ESP32

## Overview
The NFC Smart Attendance System is an IoT-based solution designed to automate attendance recording using NFC-enabled ID cards.

The system uses an ESP32 microcontroller and a PN532 NFC module to detect NFC cards embedded in student ID cards. When a student taps their card, the system reads the card UID and records attendance automatically.

## Features
• Contactless attendance system  
• Fast NFC card scanning  
• LCD display for real-time feedback  
• LED and buzzer indication  
• WiFi-enabled system  
• Secure student identification  

## Hardware Components
- ESP32
- PN532 NFC Module
- I2C LCD Display
- RGB LED
- Buzzer
- Jumper Wires
- Breadboard
- NFC-enabled ID Cards

## Working Principle
1. Student taps NFC ID card near the PN532 reader.
2. PN532 reads the unique card UID.
3. ESP32 processes the UID.
4. LCD displays attendance status.
5. LED and buzzer provide feedback.
6. Data can be transmitted through WiFi.

## Applications
- Smart classroom attendance
- Office employee attendance
- Secure entry systems
- Automated access control

## Technologies Used
- Embedded Systems
- IoT
- NFC Communication
- WiFi Networking

## Future Improvements
- Cloud database integration
- Mobile application dashboard
- Web portal for attendance tracking
- Biometric backup authentication
