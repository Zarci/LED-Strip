# AVR Functions for the WS2812B implemented in C
This project is an extension of [light_ws2812](https://github.com/cpldcpu/light_ws2812).

The ledstrip library acts as a wrapper for [light_ws2812](https://github.com/cpldcpu/light_ws2812) exposing useful color matrix functions.


## Setup
- Use the provided main.c template found [here](https://github.com/Zarci/LED-Strip/blob/main/PlatformIO/src/main.c) to get started.

### PlatformIO (recommended) 

1. Install PlatformIO; directions can be found [here](https://github.com/Zarci/LED-Strip/blob/main/Ece484_platformio.pdf)

```git clone https://github.com/Zarci/LED-Strip.git```

2. Copy one of the examples found [here](https://github.com/Zarci/LED-Strip/tree/main/PlatformIO/test/Examples) into main.c

3. Upload and go!

### AVR Tool Chain

---
### Defined functions
- begin(struct led_strip *strip, int number_pixels, int nType);
- show(struct led_strip *strip);
- setPixelColor(struct led_strip *strip, int num, uint8_t red, uint8_t green, uint8_t blue);
- fill(struct led_strip *strip, uint8_t red, uint8_t green, uint8_t blue);
- setBrightness(struct led_strip *strip, uint8_t brightness);
- clear(struct led_strip *strip);

### led_strip Data Structure
- int length;             // Number of LEDs
- int type;               // LED type (e.g., LED_TYPE_WS2812_RGB)
- struct cRGB *leds;      // Array of LED colors

---

## Demo Videos




