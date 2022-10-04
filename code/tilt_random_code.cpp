#include <Adafruit_NeoPixel.h>
#define PIN        2
#define NUMPIXELS 7
#define bright 255
#define dly 50

#define tilt 12
Adafruit_NeoPixel neo(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int state = 0;
int n;

void setup() {
    Serial.begin(9600);
    neo.begin();
    neo.setBrightness(bright);
    neo.clear();
    neo.show();
    pinMode(tilt, INPUT);

    Serial.println("Serial start");
}

void loop()
{
    state = digitalRead(tilt);
    if (state == 1)
    {
        state = state + digitalRead(tilt);
        if (state != 1)
        {
            state = 0;
        }
        else if (state == 1)
        {
            n = random(0, 3);
            if (n == 1)
                RED();
            else if (n == 2)
                GREEN();
            else
                BLUE();
        }
    }
}

void RED()
{
    Serial.println("RED 함수 호출");
    for (int i = 0; i < NUMPIXELS; i++)
    {
        neo.setPixelColor(i, bright, 0, 0);
        neo.show();
    }
    state = 0;
}
void GREEN()
{
    Serial.println("GREEN 함수 호출");
    for (int i = 0; i < NUMPIXELS; i++)
    {
        neo.setPixelColor(i, 0, bright, 0);
        neo.show();
    }
    state = 0;
}
void BLUE()
{
    Serial.println("BLUE 함수 호출");
    for (int i = 0; i < NUMPIXELS; i++)
    {
        neo.setPixelColor(i, 0, 0, bright);
        neo.show();
    }
    state = 0;
}