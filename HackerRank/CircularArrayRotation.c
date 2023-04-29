int* circularArrayRotation(int a_count, int* a, int k, int queries_count, int* queries, int* result_count) {
    k%=a_count; /* if the number of rotation greater than the size of the array, it will cause errors in this code,so this line fix*/
    *result_count = queries_count;
    int temp = 0;
    int n = 0;
    for (int i = a_count - k; i < a_count; i++)
    {
        temp = a[i];
        for (int j = i; j > n; j--)
        {
            a[j] = a[j-1];
        }
        a[n] = temp;
        n++;
    }
    int *ans = (int*)calloc(queries_count, sizeof(int));
    if(ans != NULL)
    {
        for(int i = 0 ; i < queries_count ; i++)
        {
            ans[i] = a[queries[i]];
        
        }
    }
    return ans;
}