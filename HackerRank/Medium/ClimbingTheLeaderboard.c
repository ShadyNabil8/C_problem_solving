void rank(int *arr,int *ans, int n)
{
    /*[100,90,90,80,75,60] => [1,2,2,3,4,5]*/
    int rank = 1;
    ans[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i-1])
        {
            ans[i] = rank;
        }
        else
        {
            rank++;
            ans[i] = rank;
        }  
    }
}
int* climbingLeaderboard(int ranked_count, int* ranked, int player_count, int* player, int* result_count) {
    int LastIndex = ranked_count-1;
    *result_count = player_count;
    int *ans = (int*)calloc(player_count,sizeof(int));
    int *RankArr = (int*)calloc(ranked_count,sizeof(int));
    rank(ranked, RankArr, ranked_count);
    for (int i = 0 ; i <player_count; i++) 
    {
        while((LastIndex >= 0) && (player[i] > ranked[LastIndex]))
        {
            LastIndex--;
        }
        if(LastIndex < 0)
        {
            ans[i] = 1;
            LastIndex = 0;
        }
        else if(player[i] == ranked[LastIndex])
        {
            ans[i] = RankArr[LastIndex];
            
        }
        else
        {
            ans[i] = RankArr[LastIndex]+1;
        }       
    }
    return ans;

}