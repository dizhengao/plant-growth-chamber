
#pragma XOD dirtieness disable

struct State {};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    auto x = getValue<input_X>(ctx);
    auto min = getValue<input_MIN>(ctx);
    auto max = getValue<input_MAX>(ctx);
    emitValue<output_OUT>(ctx, min <= x && x <= max);
}
