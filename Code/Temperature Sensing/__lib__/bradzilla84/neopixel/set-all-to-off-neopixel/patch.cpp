struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_INIT>(ctx)){
    emitValue<output_OUT>(ctx, getValue<input_DEV>(ctx));
        return;}

    // Get a pointer to the `OLED` class instance
    auto pixels = getValue<input_DEV>(ctx);

    for(uint16_t i=0; i<pixels->numPixels(); i++) {
    pixels->setPixelColor(i, 0,0,0);
    }
    pixels->show();

    emitValue<output_OUT>(ctx, pixels);
    emitValue<output_OK>(ctx, 1);
}
