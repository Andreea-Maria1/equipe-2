#include "SR04.h"

long distance;

int motor1pin1 = 2;
int motor1pin2 = 3;

int motor2pin1 = 4;
int motor2pin2 = 5;

int powerMotorPin = 8;
const int trigPin = 9;
const int echoPin = 10;
const int vccTemp = 11;

SR04 capteurUltraSon = SR04(trigPin, echoPin);

void setup() {
    pinMode(3, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(motor1pin1, OUTPUT);
    pinMode(motor1pin2, OUTPUT);
    pinMode(motor2pin1, OUTPUT);
    pinMode(motor2pin2, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(11, 255);
    distance = capteurUltraSon.Distance();
    if (distance <= 25) digitalWrite(12, 1);
    else digitalWrite(12, 0);

    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);  // Le moteur tourne dans un sens

    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);  // Le moteur tourne dans un sens
}