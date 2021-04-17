
node {
    char _str[16];

    void evaluate(Context ctx) {
        auto state = getState(ctx);
        auto str = getValue<input_IN>(ctx);
        dump(str,_str);
        emitValue<output_OUT>(ctx, atof(_str));
    }
}
