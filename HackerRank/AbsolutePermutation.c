#define MIN(a, b) (((a) >= (b)) ? (b) : (a))

int *absolutePermutation(int n, int k, int *result_count)
{
    bool flags[n];
    int lower = 0;
    int upper = 0;
    int *ans = (int *)calloc(n, sizeof(int));
    *result_count = n;

    for (int i = 0; i < n; i++)
    {
        flags[i] = true;
    }
    if (k == 0)
    {
        for (int i = 0; i < n; i++)
        {
            ans[i] = i + 1;
        }
        return ans;
    }

    for (int i = 0; i < n; i++)
    {
        lower = i - k + 1;
        upper = i + k + 1;
        if ((lower > 0) && (lower <= n) && (flags[lower - 1]))
        {
            ans[i] = lower;
            flags[lower - 1] = false;
        }
        else
        {
            if ((upper <= n) && (flags[upper - 1]))
            {
                ans[i] = upper;
                flags[upper - 1] = false;
            }
            else
            {
                ans[0] = -1;
                *result_count = 1;
                return ans;
            }
        }
    }
    return ans;
}