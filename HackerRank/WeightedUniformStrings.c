char **weightedUniformStrings(char *s, int queries_count, int *queries, int *result_count)
{
    *result_count = queries_count;
    int counter[27];
    counter[0] = 0;
    int sum = 0;
    int temp = 0;
    int size = 0;
    for (int i = 97; i < 26 + 97; i++)
    {
        sum = 0;
        for (int j = 0; j < strlen(s); j++)
        {
            if (i == s[j])
                temp++;
            else
            {
                if (sum < temp)
                    sum = temp;
                temp = 0;
            }
        }
        if (sum < temp)
        {
            sum = temp;
            temp = 0;
        }
        counter[i - 96] = sum;
    }

    for (int i = 0; i < 27; i++)
        size += counter[i];

    int *q = (int *)calloc(size, sizeof(int));
    sum = 0;
    int c = 0; // index for q array
    for (int i = 1; i <= 26; i++)
    {
        sum = 0;
        if (counter[i] == 0)
            continue;
        else
        {
            for (int j = 0; j < counter[i]; j++)
            {
                sum += i;
                q[c] += sum;
                c++;
            }
        }
    }

    char **ans = (char **)calloc(queries_count, sizeof(char *));
    for (int i = 0; i < queries_count; i++)
    {
        ans[i] = (char *)calloc(4, 1);
        ans[i] = "No";
        for (int j = 0; j < size; j++)
        {
            if (q[j] == queries[i])
            {
                ans[i] = "Yes";
                break;
            }
        }
    }
    /*
    for(int i = 0 ; i < size ; i++)
    {
        printf("%d ",q[i]);
    }
    printf("\n%d\n",size);
    for(int i = 0 ; i < 27 ; i ++)
    {
        printf("%d ",counter[i]);
    }*/
    return ans;
}