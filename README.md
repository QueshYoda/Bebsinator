# Bebsinator
## LED Clock & Remote Control System

This is an Arduino-based project that integrates a **TM1637 4-digit display**, an **IR remote control**, and **LED control**. The project allows users to:

- Display time on a TM1637 display.
- Control LED modes using an IR remote.
- Adjust time and brightness using remote buttons.
- Implement various LED blinking patterns.

## Components Used

- **Arduino Board**
- **TM1637 4-Digit Display**
- **IR Receiver Module**
- **Infrared Remote**
- **3mm Red LEDs**
- **10x10 Perforated Plate**
- **Wires**
- **IKEA RÖDALM**

## Features

- Display and update the time.
- Adjust time using remote buttons.
- Control LED states and blinking patterns.
- Adjust display brightness.

## Wiring Diagram

| Component       | Pin Connection |
|----------------|---------------|
| TM1637 CLK     | D2            |
| TM1637 DIO     | D3            |
| IR Receiver    | D4            |
| LED A (LA)     | D5            |
| LED B (LB)     | D6            |
| LED A (BA)     | D7            |
| LED B (BB)     | D8            |

## IR Remote Button Functions

| Button  | Function |
|---------|----------|
| 0       | Toggle LED A |
| 1       | Toggle LED B |
| 2       | Blink LED A |
| 3       | Blink LED B |
| 4       | Alternate LED A & B |
| 5       | Both LEDs Blink |
| 6       | Mode 3 Pattern |
| 7       | Both LEDs Blink Together |
| 8       | Toggle Mode 3 |
| UP      | Increase Hours |
| DOWN    | Decrease Hours |
| LEFT    | Decrease Minutes |
| RIGHT   | Increase Minutes |
| STAR    | Change Display Brightness |
| HASH    | Change Blink Delay |

## Installation & Usage

1. Clone this repository:
   ```sh
   git clone https://github.com/queshyoda/bebsinator.git
   ```
2. Open the code in **PlatformIO**.
3. Install required libraries:
   - `TM1637Display`
   - `IRremote`
4. Connect your hardware as per the wiring diagram.
![solder](https://github.com/user-attachments/assets/525720d6-990f-443e-9b03-173625927811)


5. Solder all components as given in the wiring diagram.
     
![soldering_pattern ](https://github.com/user-attachments/assets/a033a326-e260-4c95-b9f6-1a38e3ccd1c9)

7. Upload the code to your Arduino board.

![final ](https://github.com/user-attachments/assets/7a701929-b87f-4c9a-8f2b-300c91b16481)

## Contributions
Contributions are welcome! Feel free to fork this repository and submit pull requests.

## Author
[Your Name](https://github.com/queshyoda)

