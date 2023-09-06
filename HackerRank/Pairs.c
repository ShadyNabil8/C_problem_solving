int compare(const void *x_void, const void *y_void)
{
    return (*(int *)x_void - *(int *)y_void);
}
int pairs(int k, int arr_count, int *arr)
{
    qsort(arr, arr_count, sizeof(int), compare);
    int pairs = 0;
    int diff = 0;
    int *ptr = NULL;
    for (int i = 0; i < arr_count - 1; i++)
    {
        diff = k + arr[i];
        ptr = (int *)bsearch(&diff, arr + i + 1, arr_count - i - 1, sizeof(int), compare);
        if (ptr != NULL)
            pairs++;
    }
    return pairs;
}