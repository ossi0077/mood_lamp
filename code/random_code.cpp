#include <Adafruit_NeoPixel.h>
#define PIN        2
#define NUMPIXELS 7
#define bright 255
#define dly 50
Adafruit_NeoPixel neo(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
    neo.begin();
    neo.setBrightness(bright);
    neo.clear();
    neo.show();
}

void RED()
{
    for (int i = 0; i < NUMPIXELS; i++)
    {
        neo.setPixelColor(i, bright, 0, 0);
        neo.show();
        delay(dly);
    }
}
void GREEN()
{
    for (int i = 0; i < NUMPIXELS; i++)
    {
        neo.setPixelColor(i, 0, bright, 0);
        neo.show();
        delay(dly);
    }
}
void BLUE()
{
    for (int i = 0; i < NUMPIXELS; i++)
    {
        neo.setPixelColor(i, 0, 0, bright);
        neo.show();
        delay(dly);
    }
}

void loop()
{
    int n = random(0, 3);
    if (n == 1)
        RED();
    else if (n == 2)
        GREEN();
    else
        BLUE();
}
/*
  int n1 = random(200, bright);
  int n2 = random(200, bright);
  int n3 = random(200, bright);
  int i7 = random(0,6);
  neo.setPixelColor(i7, 0, n2, n3);
  neo.show();
  delay(dly);

    for (int i = 0; i < NUMPIXELS; i++)
    {
    neo.setPixelColor(i7, n, n+100, n+30);
    neo.show();
    delay(dly);
    }


    for (int i = 0; i < NUMPIXELS; i++)
    {
    neo.setPixelColor(i, bright, bright, bright);
    neo.show();
    delay(dly);
    }
*/

