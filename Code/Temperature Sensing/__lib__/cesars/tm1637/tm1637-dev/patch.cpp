#pragma XOD require "https://github.com/Cesar-S/TM1637"

#include <TM1637Display.h>

node {
    static_assert(isValidDigitalPort(constant_input_pinCLK), "must be a valid digital port");
    static_assert(isValidDigitalPort(constant_input_pinDIO), "must be a valid digital port");

    meta {
        using Type = TM1637Display*;
    }

    uint8_t mem[sizeof(TM1637Display)];

    void evaluate(Context ctx){
        if (!isSettingUp()) return;
        Type Display = new (mem) TM1637Display(constant_input_pinCLK, constant_input_pinDIO);
        emitValue<output_1637U0027>(ctx, Display);
    }
}
