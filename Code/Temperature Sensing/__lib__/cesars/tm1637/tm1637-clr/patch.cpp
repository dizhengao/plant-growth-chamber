
node {
    void evaluate(Context ctx) {

        emitValue<output_1637U0027>(ctx, getValue<input_1637>(ctx));
        if (!isInputDirty<input_CLR>(ctx)){
            return;}

        auto Display = getValue<input_1637>(ctx);

        Display->clear();

        emitValue<output_DONE>(ctx, 1);
    }
}
