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

    pixels->setPixelColor(getValue<input_PixelNumber>(ctx), pixels->Color(getValue<input_RED>(ctx),getValue<input_GREEN>(ctx),getValue<input_BLUE>(ctx))); // Moderately bright color.
    pixels->show(); // This sends the updated pixel color to the hardware.
    // Pulse that module initialized successfully
    emitValue<output_OUT>(ctx, pixels);
    emitValue<output_OK>(ctx, 1);
}
