#pragma XOD dirtieness disable
#define ten 10

node {
    void evaluate(Context ctx) {

        Number y = getValue<input_IN>(ctx);
        Number x1 = y / ten;
        byte x = fmod(y, ten);
        emitValue<output_U>(ctx, x);
        x = fmod(x1, ten);
        emitValue<output_T>(ctx, x);
        byte x2 = x1 / ten;
        x = fmod(x2, ten);
        emitValue<output_H>(ctx, x);
        x = x2 / ten;
        emitValue<output_TH>(ctx, x);
    }
}
