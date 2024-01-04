#include "TM1637.h" //seed studio

unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long interval = 1200;

const int CLK = 6;
const int DIO = 7;

TM1637 tm1637(CLK, DIO);

int8_t TimeDisp[] = {0x00, 0x00, 0x00, 0x00};

int buttonP = 5;
int buttonU = 0;
int buttonD = 0;
int state = 0;
int V = 0;
int T = 0;
int Tset = 0;
int ajuste =0;
int ajap = 0;

int D = 0;

int Vsys = 0;
int ledState = LOW;

void setup() {

tm1637.init();
tm1637.set(BRIGHT_TYPICAL);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;

analogWriteFreq(2000);
Vsys = 3.3;

Tset = 4;
pinMode(A0, INPUT);
pinMode(3, OUTPUT);
pinMode(buttonP,INPUT);

tm1637.display(TimeDisp); // MOVE TO LOOP???

}

void loop() {

if (buttonP = LOW)
{
state =+ 10;
if (state = 110) { state = 0; }

}



V = (analogRead (A0)/1024)*Vsys;
T = (V/(0.010));

if (buttonU = LOW) 
{
Tset =+ 1;
}
if (buttonD = LOW)
{
Tset =- 1;
}



if (5>=(T-Tset)) {D = 5;}
if (3>=(T-Tset)<5) {D = 3;}
if (1>=(T-Tset)<3) {D = 1;}
if ((T-Tset)<1) {D = 0.5;}

ajuste = (state * (D));

ajap = map(ajuste, 0, 500, 0, 65535);

analogWrite(3, (ajap+15));

unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {

      TimeDisp[0] = state / 10;
      TimeDisp[1] = state % 10;
      
      ledState = HIGH;
 
    } else {

      TimeDisp[0] = Tset / 10;
      TimeDisp[1] = Tset % 10;
      
      ledState = LOW;
    }

    
  }

    TimeDisp[2] = T / 10;
    TimeDisp[3] = T % 10;

delay(20); //??????????????????????????????????????
// done //
}
