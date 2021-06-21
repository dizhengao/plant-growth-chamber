
node {

    void evaluate(Context ctx) {

        if(!isInputDirty<input_UPD>(ctx)) return;

        auto inValue0 = getValue<input_D_IN>(ctx);
        auto inValue1 = getValue<output_D1>(ctx);
        auto inValue2 = getValue<output_D2>(ctx);
        auto inValue3 = getValue<output_D3>(ctx);
        auto inValue4 = getValue<output_D4>(ctx);

        emitValue<output_D1>(ctx, inValue0);
        emitValue<output_D2>(ctx, inValue1);
        emitValue<output_D3>(ctx, inValue2);
        emitValue<output_D4>(ctx, inValue3);
        emitValue<output_D_OUT>(ctx, inValue4);
        emitValue<output_TICK>(ctx, 1);
    }
}
