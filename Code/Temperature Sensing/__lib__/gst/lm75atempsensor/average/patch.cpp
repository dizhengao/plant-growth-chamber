
struct State {
      // Number a;
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
 // State* state = getState(ctx);
    Number a = a;
   
    Number average = average;
    average = getValue<output_OUT>(ctx);
    Number sum = getValue<output_SUMOUT>(ctx);
    int incist = getValue<output_INCOUT>(ctx);
    incist ++;
   //emitValue<output_inc_out>(ctx, incist);
    Number Step = getValue<input_STEP>(ctx);
   
    if (incist >= Step)
    {
        incist = 0;
        sum = (sum / Step);
        average = sum;
    }
        else if (isInputDirty<input_INC>(ctx))
        sum += getValue<input_IN>(ctx);
    emitValue<output_INCOUT>(ctx, incist);
    emitValue<output_OUT>(ctx, average);
    emitValue<output_SUMOUT>(ctx, sum);
   // state->a = a;
}
