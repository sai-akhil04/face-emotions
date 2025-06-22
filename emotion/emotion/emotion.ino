#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11

void setup() {
    Serial.begin(9600);
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
}

void setColor(int r, int g, int b) {
    analogWrite(RED_PIN, r);
    analogWrite(GREEN_PIN, g);
    analogWrite(BLUE_PIN, b);
}

void loop() {
    if (Serial.available()) {
        String emotion = Serial.readStringUntil('\n');
        emotion.trim();  // Remove extra spaces

        if (emotion == "happy") {
            setColor(255, 255, 0);  // Yellow
        } else if (emotion == "sad") {
            setColor(0, 0, 255);  // Blue
        } else if (emotion == "angry") {
            setColor(255, 0, 0);  // Red
        } else if (emotion == "surprise") {
            setColor(128, 0, 128);  // Purple
        } else if (emotion == "neutral") {
            setColor(255, 255, 255);  // White
        } else {
            setColor(0, 0, 0);  // Off (Unknown emotion)
        }

        Serial.print("Emotion received: ");
        Serial.println(emotion);
    }
}
