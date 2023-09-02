int getMaxNum(int arr_count, int* arr)
{
    int max = INT_MIN;
    for(int i = 0 ; i < arr_count ; i ++)
    {
        if(arr[i] > max)
        max = arr[i];
    }
    return max;
}
int getMostFrequentNum(int arr_count, int* arr)
{
    int max = getMaxNum(arr_count, arr);
    int repeat = 0;
    int index = 0;
    int *arrTemp = (int*)calloc(max+1, sizeof(int));
    if(arrTemp != NULL)
    {
        for(int i = 0 ; i < arr_count ; i ++)
        {
            arrTemp[arr[i]]++;
        }
        for(int i = 0 ; i < max+1 ; i ++)
        {
            if(arrTemp[i] > repeat)
            {
                repeat = arrTemp[i];
                index = i;
            }
        }
    }
    return index;
}
int equalizeArray(int arr_count, int* arr) {
    int mostFrequentNum = getMostFrequentNum(arr_count, arr);
    int res = 0;;
    for(int i = 0 ; i < arr_count ; i ++)
    {
        if(arr[i]!= mostFrequentNum)
        res++;
    }
    return res;
}