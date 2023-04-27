int saveThePrisoner(int n, int m, int s) {
    /*https://www.youtube.com/watch?v=uGYw2Jntw68*/
    s--;
    if(((((s)+ (m%n)))%n) == 0)
    {
        return n;
    }
    else
    {
       return ((((s)+ (m%n)))%n);
    }
}