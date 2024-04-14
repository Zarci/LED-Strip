
#ifndef LEDSTRIP_SETTINGS
#define LEDSTRIP_SETTINGS


// Set the pin and port for the led strip's data line (in my case this is the green wire)
// This example is set to arduino pin 8
#define LED_SIGNAL_PORT B
#define LED_SIGNAL_PIN  0 





// --------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////
// Define Reset time in µs. 
//
// This is the time the library spends waiting after writing the data.
//
// WS2813 needs 300 µs reset time
// WS2812 and clones only need 50 µs
//
///////////////////////////////////////////////////////////////////////

#define ws2812_resettime  300 

///////////////////////////////////////////////////////////////////////
// Define I/O pin
///////////////////////////////////////////////////////////////////////


#define ws2812_port LED_SIGNAL_PORT
#define ws2812_pin  LED_SIGNAL_PIN

#endif