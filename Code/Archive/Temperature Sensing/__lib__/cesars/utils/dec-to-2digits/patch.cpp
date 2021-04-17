#pragma XOD dirtieness disable
#define ten 10

node {
    void evaluate(Context ctx) {
        Number y = getValue<input_IN>(ctx);
        int16_t x1 = y / ten;
        byte x = fmod(y, ten);
        emitValue<output_U>(ctx, x);
        x = fmod(x1, ten);
        emitValue<output_T>(ctx, x);
    }
}
