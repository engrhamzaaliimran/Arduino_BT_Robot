#include <Arduino.h>
#include <SoftwareSerial.h>

char receivedChar; // received value will be stored as CHAR in this variable
const byte rxPin = 2;
const byte txPin = 3;

// set up a new serial object
SoftwareSerial BT (rxPin, txPin);

const int HBridge1_pos = 4;
const int HBridge1_neg = 5;
const int HBridge2_pos = 6;
const int HBridge2_neg = 7;

void stop()
{
  Serial.println("Stop");
  digitalWrite(HBridge1_pos, LOW);
  digitalWrite(HBridge1_neg, LOW);
  digitalWrite(HBridge2_pos, LOW);
  digitalWrite(HBridge2_neg, LOW);
}

void forward()
{
  Serial.println("forward");
  digitalWrite(HBridge1_pos, HIGH);
  digitalWrite(HBridge1_neg, LOW);
  digitalWrite(HBridge2_pos, HIGH);
  digitalWrite(HBridge2_neg, LOW);
  delay(100);
}

void backward()
{
  Serial.println("backward");
  digitalWrite(HBridge1_pos, LOW);
  digitalWrite(HBridge1_neg, HIGH);
  digitalWrite(HBridge2_pos, LOW);
  digitalWrite(HBridge2_neg, HIGH);
  delay(100);
}

void right()
{
  Serial.println("right");
  digitalWrite(HBridge1_pos, HIGH);
  digitalWrite(HBridge1_neg, LOW);
  digitalWrite(HBridge2_pos, LOW);
  digitalWrite(HBridge2_neg, HIGH);
  delay(100);
}

void left()
{
  Serial.println("right");
  digitalWrite(HBridge1_pos, LOW);
  digitalWrite(HBridge1_neg, HIGH);
  digitalWrite(HBridge2_pos, LOW);
  digitalWrite(HBridge2_neg, HIGH);
  delay(100);
}

void setup()
{
  Serial.begin(9600);
    BT.begin(9600);
  Serial.println("The device started, now you can pair it with bluetooth!");
  pinMode(HBridge1_pos, OUTPUT);
  pinMode(HBridge1_neg, OUTPUT);
  pinMode(HBridge2_pos, OUTPUT);
  pinMode(HBridge2_neg, OUTPUT);
  stop();
}

void loop()
{    

  if (Serial.available())
  {
    receivedChar = Serial.read();
    Serial.print("Received: ");    // write on BT app
    Serial.println(receivedChar); // write on BT app

    if (receivedChar == '1')
    {
      forward();
      stop();
    }

    if (receivedChar == '2')
    {
      backward();
      stop();
    }

    if (receivedChar == '3')
    {
      right();
      stop();
    }

    if (receivedChar == '4')
    {
      left();
      stop();
    }
  }
}