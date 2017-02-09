#define RMpin1 8
#define RMpin2 9
#define RMpin3 10
#define RMpin4 11
#define LMpin1 4
#define LMpin2 5
#define LMpin3 6
#define LMpin4 7
#define motorSpeed 1200 //variable to set stepper speed 1200 is standaard, 800 kan nog.
int count = 0; // count of steps made
int countsperrev = 512; // number of steps per full revolution
int lookup[8] = {B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};

void anticlockwise()
{
 for(int i = 0; i < 8; i++)
 {
 setOutput(i);
 delayMicroseconds(motorSpeed);
 }
}
void clockwise()
{
 for(int i = 7; i >= 0; i--)
 {
 setOutput(i);
 delayMicroseconds(motorSpeed);
 }
}
void setOutput(int out)
{
 digitalWrite(RMpin1, bitRead(lookup[out], 0));
 digitalWrite(RMpin2, bitRead(lookup[out], 1));
 digitalWrite(RMpin3, bitRead(lookup[out], 2));
 digitalWrite(RMpin4, bitRead(lookup[out], 3));
 digitalWrite(LMpin1, bitRead(lookup[out], 0));
 digitalWrite(LMpin2, bitRead(lookup[out], 1));
 digitalWrite(LMpin3, bitRead(lookup[out], 2));
 digitalWrite(LMpin4, bitRead(lookup[out], 3));
}

void clockwiseL()
{
 for(int i = 7; i >= 0; i--)
 {
 setOutputL(i);
 delayMicroseconds(motorSpeed);
 }
}

void anticlockwiseR()
{
 for(int i = 0; i < 8; i++)
 {
 setOutputR(i);
 delayMicroseconds(motorSpeed);
 }
}

void anticlockwiseL()
{
 for(int i = 0; i < 8; i++)
 {
 setOutputL(i);
 delayMicroseconds(motorSpeed);
 }
}

void clockwiseR()
{
 for(int i = 7; i >= 0; i--)
 {
 setOutputR(i);
 delayMicroseconds(motorSpeed);
 }
}

void setOutputL(int out)
{
 digitalWrite(LMpin1, bitRead(lookup[out], 0));
 digitalWrite(LMpin2, bitRead(lookup[out], 1));
 digitalWrite(LMpin3, bitRead(lookup[out], 2));
 digitalWrite(LMpin4, bitRead(lookup[out], 3));
}

void setOutputR(int out)
{
 digitalWrite(RMpin1, bitRead(lookup[out], 0));
 digitalWrite(RMpin2, bitRead(lookup[out], 1));
 digitalWrite(RMpin3, bitRead(lookup[out], 2));
 digitalWrite(RMpin4, bitRead(lookup[out], 3));
}
