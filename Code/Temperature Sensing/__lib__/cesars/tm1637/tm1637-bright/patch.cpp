
node {

    void evaluate(Context ctx) {

        emitValue<output_1637U0027>(ctx, getValue<input_1637>(ctx));
        if (!isInputDirty<input_SET>(ctx)){
            return;}

        auto Display = getValue<input_1637>(ctx);

        Display->setBrightness((uint8_t)getValue<input_Brightness>(ctx),(bool)getValue<input_ON>(ctx));

        emitValue<output_DONE>(ctx, 1);
    }
}
