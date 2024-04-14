#include "ledstrip.h" 

#define NUM_LEDS  50 // Adjust this to the number of LEDs in your strip
// #define LED_STRIP_PIN 4

int main() {
    struct led_strip myStrip; // define LED strip structure: you can treat this like an object in C++
    
    // Initialize the strip, with pixel count, and type of strip, Only supports "LED_TYPE_WS2812_RGB"
    begin(&myStrip, NUM_LEDS, LED_TYPE_WS2812_RGB); 
 
    fill(&myStrip, 0, 255, 255); // set all led's to cyan

    setBrightness(&myStrip, 50); // set brightness to 50/255

    setPixelColor(&myStrip, 10, 255, 0, 0); // turn the led at position 10 (index @ 0) to red

    show(&myStrip); // update and show led strip

    return 0; 
}
