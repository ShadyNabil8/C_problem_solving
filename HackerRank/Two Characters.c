int alternate(char *s)
{

    int length = strlen(s);

    if (length <= 1)
    {
        return 0;
    }

    int letter[26][26];
    int count[26][26];
    for (int row = 0; row < 26; row++)
    {
        for (int col = 0; col < 26; col++)
        {
            letter[row][col] = 0;
            count[row][col] = 0;
        }
    }
    char current;
    int currentIndex = 0;

    for (int l = 0; l < length; l++)
    {
        current = s[l];
        currentIndex = (current - 'a');

        /* Updata rows */
        for (int col = 0; col < 26; col++)
        {
            if (letter[currentIndex][col] == current)
            {
                count[currentIndex][col] = -1;
            }
            if (count[currentIndex][col] != -1)
            {
                letter[currentIndex][col] = current;
                count[currentIndex][col]++;
            }
        }

        /* Updata columns */
        for (int row = 0; row < 26; row++)
        {
            if (letter[row][currentIndex] == current)
            {
                count[row][currentIndex] = -1;
            }
            if (count[currentIndex][row] != -1)
            {
                letter[row][currentIndex] = current;
                count[row][currentIndex]++;
            }
        }
    }
    int res = 0;
    for (int row = 0; row < 26; row++)
    {
        for (int col = 0; col < 26; col++)
        {
            if (count[row][col] > res)
                res = count[row][col];
        }
    }
    return res;
}