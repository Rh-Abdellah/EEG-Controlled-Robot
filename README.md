# Brain-Controlled Car using EEG Signals

This project demonstrates a brain-controlled car prototype using EEG signal data to recognize simple hand movements (left, right, stop) and translate them into movement commands via a trained neural network model. The commands are transmitted to an ESP32 board using the MQTT protocol.

## 🧠 Overview

- **EEG Input**: Simulated or real EEG data representing hand movements.
- **Deep Learning**: A feedforward neural network classifies the EEG input.
- **MQTT Communication**: Python sends movement commands to the ESP32 over MQTT.
- **ESP32**: Receives and acts on commands to control a motorized system (e.g., car prototype).

## 🛠️ Technologies

- **Python**
- **ESP32 with Arduino**
- **MQTT (via HiveMQ broker)**
- **paho-mqtt (Python MQTT client)**
- **NumPy**
- **Feedforward Neural Network (simulated in example)**

## 🚀 Getting Started

### Python Side

1. Install dependencies:
    ```bash
    pip install -r requirements.txt
    ```

2. Run the main script:
    ```bash
    python main.py
    ```

> Note: Replace the EEG simulation with actual signal processing and model inference as needed.

### ESP32 Side

1. Flash the `esp32_receiver.ino` file to your ESP32 using the Arduino IDE.
2. Set your Wi-Fi SSID and password in the code.
3. Open the Serial Monitor to view received commands.

## 🔌 MQTT Details

- **Broker**: [HiveMQ Public Broker](https://www.hivemq.com/public-mqtt-broker/)
- **Topic**: `braincar/control`

## 📷 Future Improvements

- Integrate a real EEG acquisition device (e.g., OpenBCI or Emotiv).
- Use a trained TensorFlow/Keras model for higher accuracy.
- Extend robot controls with more movement types.
- Add a GUI for monitoring EEG signals in real-time.

## 👤 Author

Made by [Your Name]  
Student in Embedded Systems and Electronics – ENSA Marrakech

## 📜 License

This project is licensed under the MIT License.
