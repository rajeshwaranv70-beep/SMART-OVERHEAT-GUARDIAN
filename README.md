# Smart Overheat Guardian

An Arduino-based temperature monitoring and safety alert system that detects overheating conditions and automatically triggers alerts, cuts power, and simulates SMS notifications.

# Overview

Smart Overheat Guardian continuously monitors temperature using an LM35 sensor. When the temperature crosses a critical threshold (70°C), the system:
- Displays a real-time alert on a 16x2 LCD screen
- Activates a buzzer and LED warning
- Trips a relay to cut power to the connected load
- Sends a simulated GSM SMS alert with temperature and location details

# Components Used

| Component | Purpose |
|---|---|
| Arduino Uno | Main microcontroller |
| LM35 Temperature Sensor | Measures ambient/board temperature |
| 16x2 LCD Display | Shows live temperature and alert status |
| Buzzer | Audible overheating alarm |
| LED | Visual alert indicator |
| Relay Module | Cuts power to load during overheating |
| Resistors | Current limiting for LED/circuit protection |
| GSM Module (simulated) | Sends SMS alert on overheat detection |

##  How It Works

1. The LM35 sensor continuously reads temperature via analog pin A0.
2. The Arduino converts the analog reading into a Celsius temperature value.
3. The LCD displays the live temperature reading every second.
4. If temperature exceeds **70°C**:
   - LED turns ON
   - Buzzer activates
   - Relay trips to cut power
   - LCD shows "HIGH TEMP ALERT"
   - A simulated SMS alert is sent once via Serial Monitor (GSM AT commands)
5. Once temperature drops back to normal, the system resets and displays "Temp Normal".

## Circuit Connections

| Component | Arduino Pin  

| LCD (RS, E, D4-D7) | 12, 11, 5, 4, 3, 2 |
| LM35 Sensor | A0 |
| LED | 13 |
| Buzzer | 9 |
| Relay | 7 |

*(Circuit diagram designed and simulated using Tinkercad)*

# Circuit Diagram

[Circuit Diagram](SMARTOVERHEATGUARD.png)
Full schematic PDF: [SmartOverheatGuardian.pdf](SmartOverheatGuardian.pdf)

# Code

The Arduino sketch (`.ino` file) is included in this repository.

# Applications

- Electrical panel / distribution board fire safety
- Server room and equipment overheat protection
- Industrial machinery monitoring
- Battery charging safety systems
- Remote/unattended location monitoring (via SMS alerts)

# Future Improvements

- Real GSM module integration for actual SMS alerts
- WiFi/IoT connectivity for remote monitoring dashboard
- Data logging to track temperature trends over time
- Mobile app integration

# Author

Built and simulated using [Tinkercad](https://www.tinkercad.com)
