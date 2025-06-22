import cv2
import serial
import time
from deepface import DeepFace

# Connect to Arduino (Set COM port accordingly)
arduino = serial.Serial('COM9', 9600)
time.sleep(2)  # Allow connection time

# Open webcam
cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    if not ret:
        break

    # Analyze the face for emotion
    result = DeepFace.analyze(frame, actions=['emotion'], enforce_detection=False)
    
    if result:
        emotion = result[0]['dominant_emotion']
        print(f"Detected Emotion: {emotion}")

        # Send the emotion to Arduino
        arduino.write(emotion.encode())
        time.sleep(1)  # Delay to prevent flooding

    cv2.imshow('Emotion Detection', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
arduino.close()
