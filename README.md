# Arduino_SleepSafe: Automated Eye Closure Detection System

## Overview

**Arduino_SleepSafe** is an innovative Arduino-based project designed to enhance safety and awareness by detecting when a user’s eyes are closed for an extended period. Utilizing an IR sensor, a motor controlled by a relay, and a buzzer, EyeGuard provides an automated response to ensure that users remain alert and safe in various situations, such as while driving or operating machinery.

## Features

- **Real-time Eye Closure Detection**: The system continuously monitors the state of the user's eyes using an IR sensor.
- **Buzzer Alert**: If the eyes remain closed for more than 2 seconds, a buzzer is activated to alert the user.
- **Motor Control**: If the eyes stay closed for an additional 2 seconds (4 seconds total), the motor is stopped, ensuring safety.
- **Immediate Motor Activation**: The motor starts running immediately upon system initialization, providing instant functionality.

## Components Used

- **Arduino Nano**: The microcontroller that powers the project.
- **IR Sensor**: Detects the presence of an object (simulating closed eyes).
- **5V Relay Module**: Controls the motor based on the sensor input.
- **DC Motor & Wheel**: Represents the action that needs to be controlled.
- **Buzzer**: Provides auditory feedback when the eyes are detected as closed.
- **Power Supply**: Two 9V batteries to power the system.

## Installation

1. **Hardware Setup**:
   - Connect the IR sensor to digital pin 2.
   - Connect the relay module to digital pin 8.
   - Connect the buzzer to digital pin 9.
   - Ensure proper power connections for the Arduino and other components.

2. **Software Setup**:
   - Upload the provided Arduino code to your Arduino Nano.
   - Adjust the IR sensor threshold if necessary to ensure accurate detection.

## Usage

Once the system is powered on, it will start monitoring the state of the user's eyes. If the eyes are detected as closed for more than 2 seconds, the buzzer will sound. If the eyes remain closed for a total of 4 seconds, the motor will stop running, ensuring safety.
