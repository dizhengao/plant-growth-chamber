#pragma XOD require "https://github.com/adafruit/Adafruit_NeoPixel"

// Include C++ library:
{{#global}}
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
{{/global}}


struct State {
    uint8_t mem[sizeof(Adafruit_NeoPixel)];
};

// Define our custom type as a pointer on the class instance.
using Type = Adafruit_NeoPixel*;

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // It should be evaluated only once on the first (setup) transaction
    if (!isSettingUp())
        return;

    auto state = getState(ctx);

    // Create a new object in the memory area reserved previously.
    Type strip = new (state->mem) Adafruit_NeoPixel(getValue<input_NUM_LEDS>(ctx), getValue<input_DataPin>(ctx), NEO_GRB + NEO_KHZ800);
    strip->setBrightness(getValue<input_BRIGHTNESS>(ctx));
    strip->begin();
    strip->show(); // Initialize all pixels to 'off'
    emitValue<output_DEV>(ctx, strip);
}
