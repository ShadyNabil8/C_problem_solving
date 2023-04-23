int getTotalX(int a_count, int* a, int b_count, int* b) {
    int minNumInB = *b;
    int n = 0;
    int flag = 1;
    for(int i = 1 ; i<b_count ; i++)
    {
        if(*(b+i) < minNumInB)
        {
            minNumInB = *(b+i);
        }else{}
    }
    for(int i = 1 ; i <= minNumInB ; i++)
    {
        flag = 1;
        for(int j = 0 ; j < b_count ; j++)
        {
            if((*(b+j) % i) != 0)
            {
                flag = 0;
                break;
            }    
        }
        if(flag == 0)
        {
            continue;
        }
        else
        {
            for(int k = 0 ; k < a_count ; k++)
            {
                if((i % *(a+k)) != 0)
                {
                    flag = 0;
                    break;
                    
                }
            }
            if(flag != 0)
            {
                n++;
            }  
        }
    }
    return n;

}
