#include <Adafruit_NeoPixel.h>

#define neoPin 2
#define pixelNum 7
#define neo_dly 10000
#define tilt 12
#define neo_bright_term 51

Adafruit_NeoPixel neo(pixelNum, neoPin, NEO_GRB + NEO_KHZ800);
int state = 0;
int neo_bright = 255;

int neo_state = 0;

void setup()
{
    neo.begin();
    neo.setBrightness(neo_bright);
    neo.clear();

    for (int i = 0; i < pixelNum; i++)
    {
        neo.setPixelColor(i, 255, 255, 255);
    }

    neo.show();
    pinMode(tilt, INPUT);
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
            switch (neo_state)
            {
            case 0:
                neo_bright = 0;
                neo_state++;
                chg_last(neo_bright);
                break;

            case 1:
                neo_bright = neo_bright + neo_bright_term;
                neo_state++;
                chg_last(neo_bright);
                break;

            case 2:
                neo_bright = neo_bright + neo_bright_term;
                neo_state++;
                chg_last(neo_bright);
                break;

            case 3:
                neo_bright = neo_bright + neo_bright_term;
                neo_state++;
                chg_last(neo_bright);
                break;

            case 4:
                neo_bright = neo_bright + neo_bright_term;
                neo_state++;
                chg_last(neo_bright);
                break;

            case 5:
                neo_bright = neo_bright + neo_bright_term;
                neo_state = 0;
                chg_last(neo_bright);
                break;

            default:
                break;
            }
        }
    }
}

void chg_last(int setBright)
{
    neo.clear();
    for (int i = 0; i < pixelNum; i++)
    {
        neo.setPixelColor(i, setBright, setBright, setBright);
    }
    neo.show();
    state = 0;
    delay(150);
}
