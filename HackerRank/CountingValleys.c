int countingValleys(int steps, char* path) {
    bool goDown = false;
    int count = 0;
    int val = 0;
    for(int i = 0 ; i < steps ; i++)
    {
        count = (*(path+i) == 'D') ? --count : ++count;
        if(count < 0)
        {
            goDown = true;
        }
        else if(goDown && (count == 0))
        {
            goDown = false;
            val++;   
        }
        
    }
    return val;
}
