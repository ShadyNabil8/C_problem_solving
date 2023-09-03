void swapChar(char *w, int c1, int c2)
{
    char temp = w[c1];
    w[c1] = w[c2];
    w[c2] = temp;
}
int compare(const void *x, const void *y)
{
    return *(unsigned char *)x - *(unsigned char *)y;
}
void sortChar(char *w, int len, int start)
{
    qsort(w + start + 1, len - start - 1, sizeof(char), compare);
}

int findBigger(char *w, int len, int c)
{
    int temp = INT_MAX;
    int diff = 0;
    int index = 0;
    for (int i = c + 1; i < len; i++)
    {
        diff = ((unsigned char)w[i] - (unsigned char)w[c]);
        if ((diff > 0) && (diff < temp))
        {
            temp = (unsigned char)w[i] - (unsigned char)w[c];
            index = i;
        }
    }
    if (temp == INT_MAX)
        return -1;
    else
        return index;
}
char *biggerIsGreater(char *w)
{
    int sl = strlen(w); // String length
    int swappedCharIndex = 0;
    bool noAnswerFlag = true;
    for (int i = sl - 1; i > 0; i--)
    {
        if ((w[i - 1] - w[i]) < 0)
        {
            printf("%c\n", w[i - 1]);
            swappedCharIndex = findBigger(w, sl, i - 1);
            if (swappedCharIndex != -1)
                swapChar(w, i - 1, swappedCharIndex);
            printf("%s\n", w);
            sortChar(w, sl, i - 1);
            noAnswerFlag = false;
            break;
        }
    }
    if (noAnswerFlag)
        return "no answer";
    else
        return w;
}