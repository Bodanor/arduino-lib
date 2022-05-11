#include <avr/io.h>
#include "util_pin.h"
#include "timer.h"
#include "uart.h"
#include <stdio.h>

#define echoPin 2
#define trigPin 3

int main()
{
    USART_Init(MYUBRR);

    char buffer[30];
    setState(trigPin, OUTPUT);
    setState(echoPin, INPUT);

    while (1)
    {
        long duration = 0, distance = 0;
        writePin(trigPin, LOW);
        delayMs(2);
        writePin(trigPin, HIGH);
        delayMs(10);
        writePin(trigPin, LOW);

        duration = pulsePin(echoPin, HIGH);

        distance = duration * 0.034 /2;


        sprintf(buffer, "%ld", distance);
        USART_SendStr(buffer);
        USART_SendStr(" cm \n");
        delayMs(100);

    }
}