#include<Ultrassonic.h>
#include<Arduino.h>
#include<Wire.h>

Ultrassonic::Ultrassonic(int echoPin, int trigPin){
    this->echoPin = echoPin;
    this->trigPin = trigPin;

    pinMode(echoPin, INPUT); 
    pinMode(trigPin, OUTPUT);
    digitalWrite(trigPin, LOW);
}

void Ultrassonic::send_pulse(){
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW);
}

float Ultrassonic::distance_meters(){
    send_pulse();
    time = pulseIn(echoPin,HIGH);
    distance = (time*0.000340)/2;

    return distance;
}

float Ultrassonic::distance_cm(){
    send_pulse();
    time = pulseIn(echoPin,HIGH);
    distance = ((time*0.000340)/2)*100;

    return distance;
}
