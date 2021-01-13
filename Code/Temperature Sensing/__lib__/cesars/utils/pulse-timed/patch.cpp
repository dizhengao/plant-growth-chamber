struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    bool oldState = getValue<output_ACT>(ctx);
    bool newState = oldState;

    newState = false;
    if (isInputDirty<input_UPD>(ctx)) {
        newState = true;
    }
    if (newState == oldState)
    return;

    emitValue<output_ACT>(ctx, newState);

    if (newState) {
        TimeMs dt = getValue<input_Ts>(ctx) * 1000;
        setTimeout(ctx, dt);
    } else if (isTimedOut(ctx)) {
        newState= true;
    }
}
