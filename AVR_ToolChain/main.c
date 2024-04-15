#include "LED_Strip/ledstrip.h" 
#define NUM_LEDS  50

int main() {

    // void setup()
    struct led_strip myStrip;

    begin(&myStrip, NUM_LEDS, LED_TYPE_WS2812_RGB);
     
    // void loop()
    while (1) {


    }

    return 0; 
}



