
node {

    void evaluate(Context ctx) {

        Number start = getValue<input_START>(ctx);
        Number stop = getValue<input_STOP>(ctx);
        Number step = getValue<input_STEP>(ctx);
        Number count = getValue<output_OUT>(ctx);

        if (isInputDirty<input_RST>(ctx)) {
            emitValue<output_OUT>(ctx, start);
        }
        else if (isInputDirty<input_PULSE>(ctx)){
            if(start>=count){
                count=start;
            }
            count += step;
            if (step*count >= step*stop) {
                    count=stop;
                    emitValue<output_DONE>(ctx, true);
            }
            emitValue<output_OUT>(ctx, count);
        }
    }
}
