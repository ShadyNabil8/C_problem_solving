int binary_search(const int *const arr, const int arr_size, const int target, int left_arg)
{
    int left = left_arg;
    int right = arr_size - 1;
    int middle = 0;
    int temp = 0;
    while (left <= right)
    {
        middle = (int)((right + left) / 2);
        temp = *(arr + middle);
        if (target == temp)
        {
            return middle;
        }
        else if (target < temp)
        {
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }
    }
    return -1;
}