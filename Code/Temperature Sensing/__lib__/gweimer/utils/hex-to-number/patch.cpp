
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    auto hex = getValue<input_HEX>(ctx);
    char valid[] = "0123456789ABCDEFabcdef";
    int error = 0;
    int i = 0; // Index for position in string
    for (auto it = hex->iterate(); !error && it; ++it) {
        i++;
        if (i == 1) {
            (char)*it == '0' || (error = -i);
        } else if (i == 2) {
            (char)*it == 'x' || (error = -i);
        } else if (strchr(valid, (char)*it) == NULL) {
            error = -i;
        }
    }
    int dec;
    if (error) {
        dec = error;
    } else {
        char hexBuff[length(hex)+1] = { 0 }; // init with terminal zeros
        dump(hex, hexBuff);
        sscanf(hexBuff, "0x%x", &dec);
    }
    emitValue<output_DEC>(ctx, dec);
}
