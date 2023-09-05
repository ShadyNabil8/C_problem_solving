char *larrysArray(int A_count, int *A)
{
    int sum = 0;
    for (int i = 0; i < A_count; i++)
    {
        for (int j = i + 1; j < A_count; j++)
        {
            if (A[j] < A[i])
                sum++;
        }
    }
    if (sum % 2 == 0)
        return "YES";
    else
        return "NO";
}