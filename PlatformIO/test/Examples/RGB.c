#include "ledstrip.h" 
#define NUM_LEDS  50

int main() {
    struct led_strip myStrip;

    begin(&myStrip, NUM_LEDS, LED_TYPE_WS2812_RGB); 

    uint8_t r = 0, g = 0, b = 0;

    while (1) {
        // Cycle through red values
        for (r = 0; r < 255; r++) {
            fill(&myStrip, r, g, b);
            show(&myStrip);
        }
        r = 0;

        // Cycle through green values
        for (g = 0; g < 255; g++) {
            fill(&myStrip, r, g, b);
            show(&myStrip);
        }
        g = 0;

        // Cycle through blue values
        for (b = 0; b < 255; b++) {
            fill(&myStrip, r, g, b);
            show(&myStrip);
        }
        b = 0;
    }


    return 0; 
}



