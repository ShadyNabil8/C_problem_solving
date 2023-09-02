#define MIN(a,b) (((a)<=(b)) ? (a) : (b))
#define MAX(a,b) (((a)<=(b)) ? (b) : (a))

int nonDivisibleSubset(int k, int s_count, int *s)
{
    int res = 0;
    int *freq = (int*)calloc(k,sizeof(int));
    for(int i = 0 ; i < s_count ; i ++)
        freq[(s[i])%k]++;

    if((k%2) == 0)
        freq[k/2] = MIN(1,freq[k/2]);
        
    res = MIN(1,freq[0]);
    
    for(int i = 1 ; i <= k/2 ; i++)
        res += MAX(freq[i] , freq[k-i]);
    
    return res;
}