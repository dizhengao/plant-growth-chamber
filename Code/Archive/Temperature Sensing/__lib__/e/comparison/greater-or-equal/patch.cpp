
#pragma XOD dirtieness disable

struct State {};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    auto lhs = getValue<input_LHS>(ctx);
    auto rhs = getValue<input_RHS>(ctx);
    emitValue<output_OUT>(ctx, lhs >= rhs);
}
