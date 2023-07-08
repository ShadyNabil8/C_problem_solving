char *appendAndDelete(char *s, char *t, int k)
{
    int sIndex = 0;
    int tIndex = 0;
    int sLen = strlen(s);
    int tLen = strlen(t);
    while (sIndex < sLen && tIndex < tLen)
    {
        if (s[sIndex] == t[tIndex])
        {
            sIndex++;
            tIndex++;
        }
        else
        {
            break;
        }
    }
    int minOps = (sLen - sIndex) + (tLen - tIndex);

    if (minOps > k)
        return "No";
    else if (k >= (sLen + tLen))
        return "Yes";
    else if ((k - minOps) % 2 == 0)
        return "Yes";
    else
        return "No";
}