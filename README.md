
# Blink-Led-Using-Timer

## Overview

**Blink-Led-Using-Timer** is a straightforward embedded C project that demonstrates how to blink an LED using a hardware timer interrupt. This approach ensures precise timing without relying on blocking delay functions, making it ideal for real-time embedded applications.

---

## Features

- **Hardware Timer Utilization:** Leverages a microcontroller's hardware timer to generate periodic interrupts.
- **Non-Blocking LED Control:** Avoids the use of blocking delays, allowing for more efficient CPU utilization.
- **Interrupt-Driven Design:** Ensures accurate and consistent LED toggling intervals.
- **Educational Value:** Serves as a foundational example for understanding timer interrupts in embedded systems.

---

## Project Structure

| File           | Description                                      |
|----------------|--------------------------------------------------|
| `main.c`       | Contains the main application logic, including timer and GPIO initialization, and the interrupt service routine (ISR) for toggling the LED. |
| `README.md`    | Provides an overview and instructions for the project. |

---

## Requirements

- **Microcontroller:** Any MCU with a hardware timer and GPIO support (e.g., STM32, AVR, MSP430).
- **Development Environment:** An IDE or toolchain compatible with your chosen MCU (e.g., STM32CubeIDE, Atmel Studio, Keil uVision).
- **Hardware:** A development board with an onboard LED or an external LED connected to a GPIO pin.

---

## How It Works

1. **Timer Configuration:**
   - The hardware timer is configured to generate an interrupt at a specified interval (e.g., every 1 second).
   
2. **Interrupt Service Routine (ISR):**
   - Each time the timer interrupt occurs, the ISR toggles the state of the LED.
   
3. **Main Loop:**
   - The main loop remains idle or can perform other tasks, as the LED control is handled entirely by the ISR.

This design ensures that the LED blinks at precise intervals without hindering the main program's execution flow.

---
Got it — thanks for the clarification!

Since you used **ModusToolbox**, I’ll update that part specifically to match your actual setup.  
Here’s the corrected version for the **Getting Started** section of your `README.md`:

---

## Getting Started

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/ViralPatel-19/Blink-Led-Using-Timer.git
   ```

2. **Open the Project in ModusToolbox:**
   - Launch **ModusToolbox**.
   - Click **Import Application** → **From GitHub** and paste the repository link.
   - Alternatively, clone manually and then use **"Import Project"**.

3. **Build the Project:**
   - After importing, click **Build** to compile the project.

4. **Flash the Program:**
   - Connect your development board (e.g., PSoC, XMC).
   - Use **Program and Debug** in ModusToolbox to flash the firmware.

5. **Observe the LED:**
   - The LED will start blinking according to the timer settings.
