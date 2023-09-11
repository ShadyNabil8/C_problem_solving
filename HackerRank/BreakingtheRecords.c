int *breakingRecords(int scores_count, int *scores, int *result_count)
{
    *result_count = 2;
    int max = *scores;
    int min = *scores;
    int *arr = (int *)calloc(2, sizeof(int));
    /*(arr + 0) max*/
    /*(arr + 1) min*/
    for (int i = 1; i < scores_count; i++)
    {
        if (*(scores + i) > max)
        {
            (*(arr + 0))++;
            max = *(scores + i);
        }
        else if (*(scores + i) < min)
        {
            (*(arr + 1))++;
            min = *(scores + i);
        }
        else
        {
        }
    }
    return arr;
}