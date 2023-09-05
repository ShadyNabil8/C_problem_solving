int *icecreamParlor(int m, int arr_count, int *arr, int *result_count)
{
    *result_count = 2;
    int max = INT_MIN;
    for (int i = 0; i < arr_count; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    int *map = (int *)calloc(max + 1, sizeof(int));
    for (int i = 0; i < arr_count; i++)
        map[arr[i]]++;

    int *res = (int *)calloc(2, sizeof(int));

    for (int i = 0; i < arr_count; i++)
    {
        map[arr[i]]--;
        if (arr[i] >= m)
            continue;
        else
        {
            if (map[m - arr[i]] > 0)
            {
                res[0] = i + 1;
                int j = 0;
                for (j = i + 1; j < arr_count; j++)
                {
                    if (arr[j] == m - arr[i])
                        break;
                }
                res[1] = j + 1;
            }
        }
    }
    return res;
}