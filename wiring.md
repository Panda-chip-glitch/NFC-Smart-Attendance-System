# ESP32 Wiring Connections

## PN532 NFC Module (SPI Communication)

| PN532 Pin | ESP32 Pin |
|---|---|
| VCC | 3.3V |
| GND | GND |
| SCK | GPIO 18 |
| MISO | GPIO 19 |
| MOSI | GPIO 23 |
| SS | GPIO 5 |

---

## I2C LCD Display

| LCD Pin | ESP32 Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

---

## Red LED

| LED Pin | ESP32 Pin |
|---|---|
| Anode (+) | GPIO 15 (via 220Ω resistor) |
| Cathode (-) | GND |

---

## Buzzer

| Buzzer Pin | ESP32 Pin |
|---|---|
| Positive (+) | GPIO 2 |
| Negative (-) | GND |

---

## Notes

- PN532 NFC module is configured in SPI mode.
- LCD display communicates using I2C protocol.
- ESP32 handles NFC authentication and Google Sheets attendance logging through WiFi connectivity.
