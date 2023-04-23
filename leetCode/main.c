#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{

    return 0;
}
bool isAnagram(char *s, char *t)
{
    int sLen = strlen(s);
    int tLen = strlen(t);
    if (sLen != tLen)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < sLen; i++)
        {
            if (strchr(*(s + i), t) == NULL)
            {
                return false;
            }
        }
        return true;
    }
}
