
#pragma XOD dirtieness disable

node {

    void evaluate(Context ctx) {
        auto x = getValue<input_X>(ctx);
        auto min = getValue<input_LOW>(ctx);
        auto max = getValue<input_HIGH>(ctx);
        bool oldState = getValue<output_ACT>(ctx);
        bool newState = oldState;

        if (x <= min) {
            newState = false;
        } else if (x >= max) {
            newState = true;
        }
        emitValue<output_ACT>(ctx, newState);
        if (getValue<output_ACT>(ctx) == true){
            emitValue<output_Xout>(ctx, getValue<input_X>(ctx));
            emitValue<output_XoutU0027>(ctx, 0);
            emitValue<output_ACTU0027>(ctx, false);
        }else{
            emitValue<output_ACTU0027>(ctx, true);
            emitValue<output_Xout>(ctx, 0);
            emitValue<output_XoutU0027>(ctx, getValue<input_X>(ctx));
        }
    }
}
