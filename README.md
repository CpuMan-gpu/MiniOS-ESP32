# MiniOS-ESP32
A tiny OLED-based operating environment built for the ESP32.

MiniOS-ESP32

A tiny OLED-based operating environment built for the ESP32. MiniOS features an interactive menu, physical button controls, and plans for homebrew applications and games.

Current Version
v0.2 — First public version

Hardware Requirements

- ESP32 DevKit V1
- 0.96-inch OLED display (128×64, SSD1306, I²C)
- 2 red tactile push buttons
- 1 blue tactile push button
- Breadboard
- Jumper wires
- USB cable for programming and power

Wiring

OLED Display

| OLED Pin | ESP32 Pin |
|---|---|
| GND | GND |
| VCC | 3V3 |
| SCL | GPIO22 |
| SDA | GPIO21 |

Buttons

| Button | ESP32 Pin |
|---|---|
| UP | GPIO18 |
| DOWN | GPIO19 |
| SELECT | GPIO23 |

Each button connects its GPIO pin to GND when pressed. MiniOS uses the ESP32's internal pull-up resistors.

Software Requirements

- Arduino IDE
- ESP32 board support package
- Adafruit SSD1306 library
- Adafruit GFX Library

Installation

1. Install Arduino IDE.
2. Install ESP32 board support.
3. Install the Adafruit SSD1306 and Adafruit GFX libraries.
4. Open `src/MiniOS_v0.2.ino`.
5. Select **ESP32 Dev Module** as the board.
6. Connect your ESP32 and select its serial port.
7. Compile and upload the sketch.

Controls

| Button | Function |
|---|---|
| UP | Move selection up |
| DOWN | Move selection down |
| SELECT | Open a menu item or return home |

Current Features

- OLED boot and home screen
- Interactive menu
- System information screen
- Settings placeholder
- Applications placeholder
- About screen

Roadmap

- [x] v0.1 — Initial OLED boot screen prototype
- [x] v0.2 — Interactive menu and button navigation
- [ ] v0.3 — Snake game
- [ ] Future releases — More applications and features

Project Status

MiniOS is an experimental hobby project built on the ESP32. It is actively being developed.

Created by Yousuf.
