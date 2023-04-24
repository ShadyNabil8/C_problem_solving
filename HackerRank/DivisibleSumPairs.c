int divisibleSumPairs(int n, int k, int ar_count, int* ar) {
    n = 0;
    for(int i = 0 ; i < ar_count-1 ; i++)
    {
        for(int j = i+1 ; j<ar_count ; j++)
        {
            if(((ar[i] + ar[j])%k) == 0)
            {
                n++;
            } 
        }
         
    }
    return n;

}