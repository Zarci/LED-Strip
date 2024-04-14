#include "ledstrip.h" 
#define NUM_LEDS  50

// Define rainbow colors
const uint8_t RED[3] = {255, 0, 0};
const uint8_t ORANGE[3] = {255, 127, 0};
const uint8_t PINK[3] = {255, 192, 203};
const uint8_t MAGENTA[3] = {255, 0, 255};
const uint8_t CYAN[3] = {0, 255, 255};
const uint8_t YELLOW[3] = {255, 255, 0};
const uint8_t GREEN[3] = {0, 255, 0};
const uint8_t BLUE[3] = {0, 0, 255};
const uint8_t INDIGO[3] = {75, 0, 130};
const uint8_t VIOLET[3] = {148, 0, 211}; 

const uint8_t *rainbowColors[] = {RED, ORANGE, YELLOW, GREEN, BLUE, INDIGO, VIOLET, PINK, MAGENTA, CYAN}; 
const int NUM_COLORS = 10; 
const int FADE_STEPS = 30;

void delay(unsigned int ms) 
{
	unsigned int i;

	for (i=0; i<(ms/10); i++) 
	{
		_delay_ms(10);
	}
	for (i=0; i<(ms % 10); i++) 
	{
		_delay_ms(1);
	}
}


int main() {
    struct led_strip myStrip;

    begin(&myStrip, NUM_LEDS, LED_TYPE_WS2812_RGB); 
    
    int colorIndex = 0; 
    uint8_t currentColor[3] = {0, 0, 0};
    uint8_t targetColor[3] = {0, 0, 0};
    int fadeStep = 0; 

    while (1) {

        for (int i = 0; i < 3; i++) {
            currentColor[i] = rainbowColors[colorIndex][i] + 
                              ((rainbowColors[(colorIndex + 1) % NUM_COLORS][i] - rainbowColors[colorIndex][i]) * fadeStep) / FADE_STEPS;
        }

        fill(&myStrip, currentColor[0], currentColor[1], currentColor[2]);
        setBrightness(&myStrip, 75);
        show(&myStrip);
        delay(10);

        fadeStep++;
        if (fadeStep >= FADE_STEPS) {
            colorIndex = (colorIndex + 1) % NUM_COLORS;
            fadeStep = 0;
        }
    }

    return 0; 
}