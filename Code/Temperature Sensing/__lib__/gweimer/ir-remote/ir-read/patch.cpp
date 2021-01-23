#pragma XOD require "https://github.com/z3t0/Arduino-IRremote"

{{#global}}
#include <IRremote.h>
{{/global}}

struct State {
    int configuredPort = -1;
    IRrecv* irrecv;
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    State* state = getState(ctx);
    auto port = getValue<input_PORT>(ctx);
    auto irrecv = state->irrecv;
    if (state->configuredPort != port) {
        state->irrecv = irrecv = new IRrecv(port);
        irrecv->enableIRIn(); // Start the receiver
        state->configuredPort = port;
    }
    if (isInputDirty<input_UPD>(ctx)) {
        long int out = 0;
        decode_results results;         //cache of decode of IR remoter control
        if (irrecv->decode(&results)) {
            out = results.value;
            irrecv->resume();
        }
        emitValue<output_OUT>(ctx, out);
    }
}
