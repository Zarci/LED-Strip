# AVR Functions for the WS2812B implemented in C
## This project is an extention of [light_ws2812](https://github.com/cpldcpu/light_ws2812).
 

### Setup
- LED Strip State: t/f -> True: individually addressable, False: Entire strip is static and one color
- LED Count: Numer of LED's in the strip.

### Defined functions
- LED ON(pos, hex value) state: true turns a specific LED on the strip on
- LED ON(Hex value) -> state:false
