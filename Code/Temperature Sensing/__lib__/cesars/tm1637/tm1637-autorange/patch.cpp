
node {
    int temp;
    int8_t point;
    int8_t zero;

    void evaluate(Context ctx) {

        emitValue<output_1637U0027>(ctx, getValue<input_1637>(ctx));
        if (!isInputDirty<input_UPD>(ctx)) return;

        auto val = getValue<input_Value>(ctx);
        if(0 < val && val < 1){
            zero = 1;
        }else{
            zero = 0;
        }
        if(val > 9999)return;
        else if(val < -999)return;
        uint8_t i = 0;
        if(val > 0)
        {
        for( ;i < 3; i ++)
        {
            if(val < 1000)val *= 10;
            else break;
        }
        temp = (int)val;
        if((val - temp)>0.5)temp++;
        }
       else
       {
        for( ;i < 1; i ++)
        {
          if(val > -100)val *= 10;
          else break;
        }
        temp = (int)val;
        if((temp - val)>0.5)temp--;
        }
        point = i ;

        int dot;
        switch(point){
            case 1:
                dot = 32;
                break;
            case 2:
                dot = 64;
                break;
            case 3:
                dot = 128;
                break;
            case 4:
                dot = 224;
                break;
            default:
                dot = 0;
                break;
        }

        auto Display = getValue<input_1637>(ctx);

        Display->showNumberDecEx(temp, dot, zero, 4, 0);

        emitValue<output_DONE>(ctx, 1);
    }
}
