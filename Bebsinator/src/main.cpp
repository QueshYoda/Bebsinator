#include <TM1637Display.h>
#include <IRremote.hpp>

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3
#define LA 5
#define LB 6 
#define BA 7 
#define BB 8

//Led Delay
int delayInx = 0;
int delayValues[] = {250 , 400 , 500 , 1000};

// Led Mode
int L_mode = 0;
int B_mode = 0;
boolean L_on = true;
boolean B_on = true;
boolean mode3 = true;

// Button codes
#define BUTTON0 0xE619FF00
#define BUTTON1 0xBA45FF00
#define BUTTON2 0xB946FF00
#define BUTTON3 0xB847FF00
#define BUTTON4 0xBB44FF00
#define BUTTON5 0xBF40FF00
#define BUTTON6 0xBC57BF00
#define BUTTON7 0xF807FF00
#define BUTTON8 0xEA15FF00
#define BUTTON9 0xF609FF00
#define LEFT    0xF708FF00
#define RIGHT   0xA55AFF00
#define UP      0xE718FF00
#define DOWN    0xAD52FF00
#define OK      0xE31CFF00
#define STAR    0xE916FF00
#define HASH    0xF20DFF00

TM1637Display display(CLK, DIO);

// Variables to track time
unsigned long previousMillis = 0;
const long interval = 60000; // 1 minute in milliseconds
int hours = 22;  
int minutes = 31; 

uint16_t brightness = 3;

void setup() {
    display.setBrightness(brightness);
    Serial.begin(9600);
    IrReceiver.begin(4);
    pinMode(LA, OUTPUT);
    digitalWrite(LA, LOW);
    pinMode(LB, OUTPUT);
    digitalWrite(LB, LOW);
    pinMode(BA, OUTPUT);
    digitalWrite(BA, LOW);
    pinMode(BB, OUTPUT);
    digitalWrite(BB, LOW);
}

void changeDisplayBrightness(){
    brightness++;
    if (brightness > 7) {
        brightness = 0;
    }
    Serial.print("The Brightness is set to ");
    Serial.println(brightness);
    display.setBrightness(brightness);
}

void displayLed(int L_mode , int B_mode){
    if (L_mode == 1)
    {
        if (L_on)
        {
            digitalWrite(LA, HIGH);
            digitalWrite(LB, HIGH);
        }else{
            digitalWrite(LA, LOW);
            digitalWrite(LB, LOW);
        }
    }

    if (B_mode == 1)
    {
        if (B_on)
        {
            digitalWrite(BA, HIGH);
            digitalWrite(BB, HIGH);
        }else{
            digitalWrite(BA, LOW);
            digitalWrite(BB, LOW);
        }
    }

    if (L_mode == 2 && B_mode == 2)
    {
        digitalWrite(BA, HIGH);
        digitalWrite(BB, HIGH);
        digitalWrite(LA, HIGH);
        digitalWrite(LB, HIGH);
        delay(delayValues[delayInx]);
        digitalWrite(BA, LOW);
        digitalWrite(BB, LOW);
        digitalWrite(LA, LOW);
        digitalWrite(LB, LOW);
        delay(delayValues[delayInx]);
    }

    if (L_mode == 2 || B_mode == 2)
    {
        if (L_mode == 2)
        {
            digitalWrite(LA, HIGH);
            digitalWrite(LB, HIGH);
        }
        if (B_mode == 2)
        {
            digitalWrite(BA, HIGH);
            digitalWrite(BB, HIGH);        
        }
        if (L_mode == 3)
        {
            digitalWrite(LA, HIGH);
            digitalWrite(LB, LOW);
        }
        if (B_mode == 3)
        {
            digitalWrite(BA, HIGH);
            digitalWrite(BB, LOW); 
        }
    delay(delayValues[delayInx]);
        if (L_mode == 2)
        {
            digitalWrite(LA, LOW);
            digitalWrite(LB, LOW);
        }
        if (B_mode == 2)
        {
            digitalWrite(BA, LOW);
            digitalWrite(BB, LOW);        
        }
        if (L_mode == 3)
        {
            digitalWrite(LA, LOW);
            digitalWrite(LB, HIGH);
        }
        if (B_mode == 3)
        {
            digitalWrite(BA, LOW);
            digitalWrite(BB, HIGH); 
        }
    delay(delayValues[delayInx]);
    }
    
    if (L_mode == 3 && B_mode == 3)
    {
        if (mode3)
        {
            digitalWrite(LA, HIGH);
            digitalWrite(BA, LOW);
            digitalWrite(LB, LOW);
            digitalWrite(BB, HIGH);
        }else{
            digitalWrite(LA, HIGH);
            digitalWrite(BA, HIGH);
            digitalWrite(LB, LOW);
            digitalWrite(BB, LOW);
        }
    delay(delayValues[delayInx]);
        if (mode3)
        {
            digitalWrite(LA, LOW);
            digitalWrite(BA, HIGH);
            digitalWrite(LB, HIGH);
            digitalWrite(BB, LOW);
        }else{
            digitalWrite(LA, LOW);
            digitalWrite(BA, LOW);
            digitalWrite(LB, HIGH);
            digitalWrite(BB, HIGH);
        }
    delay(delayValues[delayInx]);
    }
    
    if (L_mode == 4 && B_mode == 4)
    {
        digitalWrite(BA, HIGH);
        digitalWrite(BB, HIGH);
        digitalWrite(LA, LOW);
        digitalWrite(LB, LOW);
        delay(delayValues[delayInx]);
        digitalWrite(BA, LOW);
        digitalWrite(BB, LOW);
        digitalWrite(LA, HIGH);
        digitalWrite(LB, HIGH);
        delay(delayValues[delayInx]);
    }
    
    if (L_mode == 1 && B_mode == 1)
    {
        delay(delayValues[delayInx]);
    }
    
}

void loop() {
    if (IrReceiver.decode()) {
        Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);

        // Toggle LED
        if (IrReceiver.decodedIRData.decodedRawData == BUTTON0) {
            digitalWrite(5, !digitalRead(5));
        }

        // Adjust Hours
        if (IrReceiver.decodedIRData.decodedRawData == UP) {
            hours++;
            if (hours >= 24) hours = 0; // Reset at 24
        }
        if (IrReceiver.decodedIRData.decodedRawData == DOWN) {
            hours--;
            if (hours < 0) hours = 23; // Prevent negative values
        }

        // Adjust Minutes
        if (IrReceiver.decodedIRData.decodedRawData == LEFT) {
            minutes--;
            if (minutes < 0) minutes = 59; // Prevent negative values
        }
        if (IrReceiver.decodedIRData.decodedRawData == RIGHT) {
            minutes++;
            if (minutes >= 60) minutes = 0; // Reset at 60
        }

        // Change Brightness
        if (IrReceiver.decodedIRData.decodedRawData == STAR) {
            changeDisplayBrightness();
        }
        // Change Delay
        if (IrReceiver.decodedIRData.decodedRawData == HASH) {
            delayInx++;
            if (delayInx > 3)
            {
                delayInx = 0;
            }
        }
        if (IrReceiver.decodedIRData.decodedRawData == BUTTON1) {
            // L open or close
            L_mode = 1;
            L_on = !L_on;
        }
        if (IrReceiver.decodedIRData.decodedRawData == BUTTON2) {
            // B open or close
            B_mode = 1;
            B_on = !B_on;
        }
        if (IrReceiver.decodedIRData.decodedRawData == BUTTON3) {
            // L blink
            L_mode = 2;
        }
        if (IrReceiver.decodedIRData.decodedRawData == BUTTON4) {
            // B blink
            B_mode = 2;
        }
        if (IrReceiver.decodedIRData.decodedRawData == BUTTON5) {
            // L bip bop
            B_mode = 3;
        }
        if (IrReceiver.decodedIRData.decodedRawData == BUTTON6) {
            // B bip bop
            B_mode = 3;
        }
        if (IrReceiver.decodedIRData.decodedRawData == BUTTON7) {
            // Both blink 
            B_mode = 4;
            L_mode = 4;
        }
        if (IrReceiver.decodedIRData.decodedRawData == BUTTON8) {
            mode3 = !mode3;
        }

        IrReceiver.resume();
    }

    displayLed(L_mode , B_mode);

    unsigned long currentMillis = millis();

    // Increment minutes every 60,000 milliseconds (1 minute)
    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        minutes++;
        if (minutes >= 60) {
            minutes = 0;
            hours++;
            if (hours >= 24) {
                hours = 0;
            }
        }
    }

    // Convert time to HHMM format
    int timeToDisplay = (hours * 100) + minutes;
    display.showNumberDecEx(timeToDisplay, 0b01000000, true);
}
