
node {
    void evaluate(Context ctx) {

        emitValue<output_1637U0027>(ctx, getValue<input_1637>(ctx));
        if (!isInputDirty<input_UPD>(ctx))return;

       uint8_t dots = getValue<input_Dots>(ctx);
        int dot;
        switch(dots){
            case 1:
                dot = 32;
                break;
            case 2:
                dot = 64;
                break;
            case 3:
                dot = 128;
                break;
            case 4:
                dot = 224;
                break;
            default:
                dot = 0;
                break;
        }

        auto Display = getValue<input_1637>(ctx);

        Display->showNumberHexEx((uint16_t)getValue<input_HEX>(ctx),dot,(bool)getValue<input_Zeros>(ctx),
                                 (uint8_t)getValue<input_Length>(ctx),(uint8_t)getValue<input_Position>(ctx));

        emitValue<output_DONE>(ctx, 1);
    }
}
