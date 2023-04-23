void countApplesAndOranges(int s, int t, int a, int b, int apples_count, int* apples, int oranges_count, int* oranges) {
    int applesNum = 0 , orangesNum = 0;
    int temp = 0;
    for(int i = 0 ; i < apples_count ; i++)
    {
        temp = (*(apples+i))+a;
        if((temp>=s) && (temp<=t) )
        {
            applesNum++;
        }
        
    }
    for(int i = 0 ; i < oranges_count ; i++)
    {
        temp = (*(oranges+i))+b;
        if((temp>=s) && (temp<=t) )
        {
            orangesNum++;
        }
        
    }
    printf("%d\n", applesNum);
    printf("%d\n", orangesNum);
    
}