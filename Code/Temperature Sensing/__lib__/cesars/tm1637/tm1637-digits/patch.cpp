
node {

    uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
    uint8_t blank[] = { 0x00, 0x00, 0x00, 0x00 };

    void evaluate(Context ctx) {

        emitValue<output_1637U0027>(ctx, getValue<input_1637>(ctx));
        if (!isInputDirty<input_UPD>(ctx)) return;

        auto Display = getValue<input_1637>(ctx);

        data[0] = getValue<input_DIG0>(ctx);
        data[1] = getValue<input_DIG1>(ctx);
        data[2] = getValue<input_DIG2>(ctx);
        data[3] = getValue<input_DIG3>(ctx);

        Display->setSegments(data);

        emitValue<output_DONE>(ctx, 1);
    }
}
