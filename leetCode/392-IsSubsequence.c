bool isSubsequence(char *s, char *t)
{
    int len_s = strlen(s);
    int len_t = strlen(t);
    bool retVal = true;
    if (len_t < len_s)
        retVal = false;
    else if (len_s == 0)
        retVal = true;
    else
    {
        int s_index = 0;
        for (int i = 0; (s_index < strlen(s)) && (i < strlen(t)); i++)
        {
            if (s[s_index] == t[i])
            {
                s_index++;
            }
        }
        if (s_index != len_s)
            retVal = false;
    }
    return retVal;
}