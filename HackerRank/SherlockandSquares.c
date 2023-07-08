int squares(int a, int b)
{
    double temp = 0.0;
    int ans = 0;

    /* Find the 1st number has an int square root */
    for (a; a <= b; a++)
    {
        temp = sqrt((double)a);
        if (temp == (int)temp)
        {
            break;
        }
    }
    if (a > b)
    {
        return 0;
    }
    else if (a == b)
    {
        return 1;
    }
    else
    {
        /* Now a is the first number has an int square root */
        int n = temp;
        while (pow((double)n, (double)2) <= b)
        {
            n++;
            ans++;
        }
    }

    return ans;
}