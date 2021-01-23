
node {

        void evaluate(Context ctx) {

        emitValue<output_1637U0027>(ctx, getValue<input_1637>(ctx));
        if (!isInputDirty<input_UPD>(ctx)) return;

        auto Display = getValue<input_1637>(ctx);

        Display->showNumberDec((int)getValue<input_Number>(ctx), (bool)getValue<input_Zeros>(ctx),
                               (uint8_t)getValue<input_Length>(ctx), (uint8_t)getValue<input_Position>(ctx));
        emitValue<output_DONE>(ctx, 1);
    }
}
