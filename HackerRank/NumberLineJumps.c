char* kangaroo(int x1, int v1, int x2, int v2) {
    char *ans = (char*)malloc(4);
    if(v2 >= v1)
    {
        ans = "NO";
    }
    else
    {
        //float numOfJumps = (x2-x1)/(v1-v2);
        if(((x2-x1)%(v1-v2))==0)
        {
            ans = "YES";
        }
        else
        {
            ans = "NO";
        } 
    }
    return ans;  
}