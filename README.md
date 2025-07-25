# 🤖 Smart Line-Following and Obstacle-Avoiding Robot

An Arduino-based robotic system that combines **IR sensor-based line detection**, **ultrasonic obstacle detection**, and **RGB LED visual feedback** to perform intelligent navigation and environment awareness.

---

## 🔧 Features

- 🖤 **Line Detection with IR Sensors**  
  Uses three IR sensors to detect black and white surfaces. Stops the robot when a white surface is detected (e.g., edge or line gap).

- 📏 **Ultrasonic Obstacle Detection**  
  Detects obstacles ahead using a distance sensor (HC-SR04). Measures the distance and stops/reacts based on the object proximity.

- 🌈 **RGB LED Feedback**  
  - **<10 cm**: Yellow (Red + Green) – Close object  
  - **10–12 cm**: Pink (Red + Blue) – Medium distance  
  - **12–15 cm**: Cyan (Green + Blue) – Farther object  
  - **>15 cm**: Off (No object nearby)

- ⚙️ **Motor Control**  
  Controls two motors for forward motion and stops based on IR or distance conditions.

---

## 🛠️ Hardware Requirements

- Arduino Uno  
- 2 DC Motors  
- L293D Motor Driver  
- 3 IR Sensors  
- HC-SR04 Ultrasonic Sensor  
- RGB LED (Common Cathode)  
- Jumper Wires, Breadboard  
- Power Supply (Battery Pack)

---

## 🧠 Arduino Pin Configuration

| Component        | Pin(s) Used |
|------------------|-------------|
| Motor 1          | 2, 3        |
| Motor 2          | 4, 5        |
| IR Sensors       | 6, 7, 8     |
| Ultrasonic Sensor| Trig: 9, Echo: 10 |
| RGB LED          | Red: 11, Green: 12, Blue: 13 |

---

## 📜 Code Overview

### Line Detection
```cpp
if (ir1Value == LOW && ir2Value == LOW && ir3Value == HIGH) {
  // Stop motors
}
