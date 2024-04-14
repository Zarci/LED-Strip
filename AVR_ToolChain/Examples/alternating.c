#include "ledstrip.h"
#define NUM_LEDS 50


const uint8_t GREEN[3] = {0, 75, 0};
const uint8_t GOLD[3] = {25, 25, 0};

void delay(unsigned int ms)
{
    unsigned int i;

    for (i = 0; i < (ms / 10); i++)
    {
        _delay_ms(10);
    }
    for (i = 0; i < (ms % 10); i++)
    {
        _delay_ms(1);
    }
}

int main()
{
    struct led_strip myStrip;

    begin(&myStrip, NUM_LEDS, LED_TYPE_WS2812_RGB);

    while (1)
    {
        for (int i = 0; i < NUM_LEDS; i++)
        {
            if (i % 2 == 0)
            {
                setPixelColor(&myStrip, i, GREEN[0], GREEN[1], GREEN[2]);
                show(&myStrip);
            }
            else if (i % 2 != 0)
            {
                setPixelColor(&myStrip, i, GOLD[0], GOLD[1], GOLD[2]);
                show(&myStrip);
            }
        }
        delay(350);
        for (int i = 0; i < NUM_LEDS; i++)
        {
            if (i % 2 == 0)
            {
                setPixelColor(&myStrip, i, GOLD[0], GOLD[1], GOLD[2]);
                show(&myStrip);
            }
            else if (i % 2 != 0)
            {
                setPixelColor(&myStrip, i, GREEN[0], GREEN[1], GREEN[2]);
                show(&myStrip);
            }
        }
    }

    return 0;
}