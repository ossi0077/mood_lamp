#include <Adafruit_NeoPixel.h>
#define PIN        2
#define NUMPIXELS 7
#define bright 255
#define dly 350

#define tilt 12
Adafruit_NeoPixel neo(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int state;
int n;
int state2 = 0;

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
    if (state == 0)
    {
        if (state2 == 0)
        {
            n = random(0, 7);
            randomColor(n);
            state2++;
            delay(dly);
        }
        else if (state2 == 1)
        {
            allOFF();
            state2 = 0;
            delay(dly);
        }
    }
}

void allOFF()
{
    Serial.println("OFF");
    for (int i = 0; i < NUMPIXELS; i++)
    {
        neo.setPixelColor(i, 0, 0, 0);
    }
    neo.show();
}
void randomColor(int x)
{
    switch (x)
    {
    case 0: //white
        Serial.println("WHITE");
        for (int i = 0; i < NUMPIXELS; i++)
        {
            neo.setPixelColor(i, bright, bright, bright);
        }
        neo.show();
        break;

    case 1: //red
        Serial.println("RED");
        for (int i = 0; i < NUMPIXELS; i++)
        {
            neo.setPixelColor(i, bright, 0, 0);
        }
        neo.show();
        break;

    case 2://green
        Serial.println("GREEN");
        for (int i = 0; i < NUMPIXELS; i++)
        {
            neo.setPixelColor(i, 0, bright, 0);
        }
        neo.show();
        break;

    case 3://blue
        Serial.println("BLUE");
        for (int i = 0; i < NUMPIXELS; i++)
        {
            neo.setPixelColor(i, 0, 0, bright);
        }
        neo.show();
        break;

    case 4://yellow
        Serial.println("yellow");
        for (int i = 0; i < NUMPIXELS; i++)
        {
            neo.setPixelColor(i, bright, bright, 0);
        }
        neo.show();
        break;

    case 5://magenta
        Serial.println("magenta");
        for (int i = 0; i < NUMPIXELS; i++)
        {
            neo.setPixelColor(i, bright, 0, bright);
        }
        neo.show();
        break;

    case 6://cyan
        Serial.println("cyan");
        for (int i = 0; i < NUMPIXELS; i++)
        {
            neo.setPixelColor(i, 0, bright, bright);
        }
        neo.show();
        break;
    default:
        break;
    }
}