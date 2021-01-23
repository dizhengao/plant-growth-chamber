
struct State {
    char str[16];
    CStringView view;
    State() : view(str) { }
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    auto state = getState(ctx);
    auto inValue = getValue<input_NUM>(ctx);
    char fmt[10];
    sprintf(fmt, "0x%%0%uX", int(getValue<input_DIG>(ctx)));
    sprintf(state->str, fmt, int(inValue));
    emitValue<output_OUT>(ctx, XString(&state->view));
}
