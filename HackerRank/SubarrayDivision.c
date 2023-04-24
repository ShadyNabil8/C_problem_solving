int birthday(int s_count, int* s, int d, int m) {
    int sum = 0;
    int ans = 0;
    for (int window = 0; window < s_count-m+1; window++)
    {
        sum = 0;
        for(int i = window ; i < m+window ; i++)
        {
            sum += *(s+i);
        }
        if(sum == d)
        {
            ans++;
        }
        

    }
    return ans;
}