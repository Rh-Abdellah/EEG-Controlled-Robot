import paho.mqtt.client as mqtt
import numpy as np
import time

# Simulated feedforward neural network model
def predict_movement(eeg_data):
    # In a real scenario, you would load a trained model here and run inference
    # Example: model.predict(eeg_data)
    if np.mean(eeg_data) > 0.7:
        return "left"
    elif np.mean(eeg_data) < 0.3:
        return "right"
    else:
        return "stop"

# MQTT setup
broker = "broker.hivemq.com"
topic = "braincar/control"
client = mqtt.Client()
client.connect(broker, 1883, 60)

print("Brain-controlled car interface started...")

while True:
    # Simulated EEG input (replace this with real EEG data input)
    eeg_sample = np.random.rand(10)

    movement = predict_movement(eeg_sample)
    print(f"Predicted movement: {movement}")
    client.publish(topic, movement)

    time.sleep(1)
