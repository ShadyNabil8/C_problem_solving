int compare(const void *x_void, const void *y_void)
{
    return (*(int *)x_void - *(int *)y_void);
}
void almostSorted(int arr_count, int *arr)
{
    int *myarr = (int *)calloc(arr_count, sizeof(int));

    for (int i = 0; i < arr_count; i++)
        myarr[i] = arr[i];

    qsort(myarr, arr_count, sizeof(int), compare);

    for (int i = 0; i < arr_count; i++)
        myarr[i] = myarr[i] - arr[i];

    int left = 0, right = 0, nonzero = 0;

    for (int i = 0; i < arr_count; i++)
    {
        if (myarr[i] != 0)
            nonzero++;
    }

    for (int i = 0; i < arr_count; i++)
    {
        if (myarr[i] != 0)
        {
            left = i;
            break;
        }
    }

    for (int i = arr_count - 1; i >= 0; i--)
    {
        if (myarr[i] != 0)
        {
            right = i;
            break;
        }
    }

    if (nonzero == 0)
    {
        // already sorted
        printf("yes");
    }
    else if (nonzero == 2)
    {
        // can swap
        printf("yes\n");
        printf("swap %d %d", left + 1, right + 1);
    }
    else
    {
        int temp = 0;
        int templeft = left, tempright = right;
        while (templeft < tempright)
        {
            temp = arr[templeft];
            arr[templeft] = arr[tempright];
            arr[tempright] = temp;
            templeft++;
            tempright--;
        }

        bool issorted = true;

        // for(int i = 0 ; i < arr_count  ; i++)
        // printf("%d",arr[i]);

        for (int i = 0; i < arr_count - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                issorted = false;
                break;
            }
        }
        if (issorted)
        {
            printf("yes\n");
            printf("reverse %d %d", left + 1, right + 1);
        }
        else
        {
            printf("no");
        }
    }
}