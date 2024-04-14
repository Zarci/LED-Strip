/**
 * 
 *  A wrapper library for the "light_ws2812_AVR" library that exposes many useful custom color matrix functions.
 * 
 *  Author: Blake Rile
 * 
 * 
 * 
*/

#ifndef LED_STRIP
#define LED_STRIP

#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include <ledstrip_settings.h>

#include <Light_WS2812/light_ws2812.h>


// Constants for LED types
#define LED_TYPE_WS2812_RGB  0
#define LED_TYPE_SK6812_RGBW 1

// Structure to hold LED strip state
struct led_strip {
    // int pinmask;                // Output pin  
    // int pin;
    int length;             // Number of LEDs
    int type;               // LED type (e.g., LED_TYPE_WS2812_RGB)
    struct cRGB *leds;      // Array of LED colors
};

void begin(struct led_strip *strip, int number_pixels, int nType);
// void updateType(struct led_strip *strip, int new_type);
void show(struct led_strip *strip); 
void setPixelColor(struct led_strip *strip, int num, uint8_t red, uint8_t green, uint8_t blue);
void fill(struct led_strip *strip, uint8_t red, uint8_t green, uint8_t blue);
void setBrightness(struct led_strip *strip, uint8_t brightness); 
void clear(struct led_strip *strip);

#endif