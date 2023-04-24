int pageCount(int n, int p) {
    int ans = 0;
    int fromLeft = 0;
    int fromRight = 0;
    if((n%2) == 0)
    {
        fromLeft = ((n-p)%2) == 0 ? ((n-p)/2) : ((int)((n-p)/2))+1;
    }
    else
    {
        fromLeft = (n-p)/2;
    }
    fromRight = ((p-1)%2) == 0 ? ((p-1)/2) : ((int)((p-1)/2))+1;
    
    if(fromRight >= fromLeft)
    {
        return fromLeft;
    }
    else
    {
        return fromRight;
    }
}
