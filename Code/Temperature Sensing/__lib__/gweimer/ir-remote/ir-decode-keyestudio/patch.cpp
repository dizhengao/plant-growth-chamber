struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    long int out = 0xFF;
    long int key = getValue<input_IN>(ctx);
                switch (key & 0xFFFFu) {
                case 0xFFFF: // repeat
                    out = getValue<output_OUT>(ctx);
                    break;
                case 0x629D: // up
                case 0x1DBB:
                    out = 11;
                    break;
                case 0xD41F: // left
                case 0x22DD:
                    out = 12;
                    break;
                case 0x4B1B: // OK
                case 0x02FD:
                    out = 13;
                    break;
                case 0x4DBB: // right
                case 0xC23D:
                    out = 14;
                    break;
                case 0xA857: // down
                case 0xEDDB:
                    out = 15;
                    break;
                case 0xE57B: // 1
                case 0x6897:
                    out = 1;
                    break;
                case 0x3BFB: // 2
                case 0x9867:
                    out = 2;
                    break;
                case 0xB04F: // 3
                case 0x1643:
                    out = 3;
                    break;
                case 0x30CF:
                case 0xBE3F:
                    out = 4;
                    break;
                case 0x18E7:
                case 0xE3F7:
                    out = 5;
                    break;
                case 0x7A85:
                case 0x021B:
                    out = 6;
                    break;
                case 0x657B:
                case 0x10EF:
                    out = 7;
                    break;
                case 0x38C7:
                case 0x3CBB:
                    out = 8;
                    break;
                case 0xE79F:
                case 0x5AA5:
                    out = 9;
                    break;
                case 0x4AB5: // 0
                case 0x157B:
                    out = 0;
                    break;
                case 0x42BD: // *
                case 0xFDF7:
                    out = 16;
                    break;
                case 0xFC1B: // #
                case 0x52AD:
                    out = 17;
                    break;
            }
    emitValue<output_OUT>(ctx, out);
}
