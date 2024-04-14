#include "ledstrip.h"

/**
 * The initialization function that sets up the data structure
 * @param strip Pass by ref (&myStrip) of the led data structure.
 * @param number_pixels The number of diodes your led strip has.
 * @param nType The type of chip being interfaced with: for this project use "LED_TYPE_WS2812_RGB"
*/
void begin(struct led_strip *strip, int number_pixels, int nType) 
{
    strip->length = number_pixels;
    strip->leds = (struct cRGB *)malloc(strip->length * sizeof(struct cRGB)); // Allocate memory
    strip->type = nType;
    DDRB |=_BV(ws2812_pin);
    clear(strip);
}

/**
 * Sends the data to the led strip & updates the colors
 * @param strip Pass by ref (&myStrip) of the led data structure.
*/
void show(struct led_strip *strip) 
{
    if (strip->type == LED_TYPE_WS2812_RGB) {
        ws2812_setleds(strip->leds, strip->length);
    } else if (strip->type == LED_TYPE_SK6812_RGBW) {
        // ws2812_setleds_rgbw(strip->leds, strip->length);
        // Not implemented -> diffrent chip
    } 
}

/**
 * Sets the led at num (indexed at 0) to the color mix of red, green, and blue
*/
void setPixelColor(struct led_strip *strip, int num, uint8_t red, uint8_t green, uint8_t blue)
{
    if (num >= 0 && num < strip->length) {
        strip->leds[num].r = red;
        strip->leds[num].g = green;
        strip->leds[num].b = blue; 
    } 
}
/**
 * Sets the entire led strip to one color
*/
void fill(struct led_strip *strip, uint8_t red, uint8_t green, uint8_t blue) 
{
    for (int i = 0; i < strip->length; i++) {
        setPixelColor(strip, i, red, green, blue);
    }
}

/**
 * Sets the brightness of the led strip
*/
void setBrightness(struct led_strip *strip, uint8_t brightness) 
{
    // Assumes the 'light_ws2812' library doesn't have brightness control
    for (int i = 0; i < strip->length; i++) {
        strip->leds[i].r = (strip->leds[i].r * brightness) >> 8; 
        strip->leds[i].g = (strip->leds[i].g * brightness) >> 8;
        strip->leds[i].b = (strip->leds[i].b * brightness) >> 8;
    }
}
/**
 * Turns off the led strip
*/
void clear(struct led_strip *strip) 
{
    fill(strip, 0, 0, 0); // Fill with black (off)
}








// void LEDS_init(LEDStrip *ledstrip, const uint8_t signalPin, const uint8_t pixelCOUNT)
// {
//     ledstrip->LED_COUNT = pixelCOUNT;

//     if (signalPin >= 0 && signalPin <= 7)
//     {
//         ledstrip->LED_PIN = signalPin;
//         ledstrip->LED_PIN_PORT = 'D';
//     }
//     else if (signalPin >= 8 && signalPin <= 13)
//     {
//         ledstrip->LED_PIN = signalPin - 8;
//         ledstrip->LED_PIN_PORT = 'B';
//     }
// }