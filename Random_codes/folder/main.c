#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int getNumberOfthem(char *string)
{
    // We assumed here that the substrings is sebarated by
    // only one spase
    // sebarated<space>like<space>this

    int n = 0; // retured value
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == ' ')
            n++;
    }

    if (n == 0)
        return 1;
    else
        return n + 1;
}

int main()
{
    // *** * ***** *** *** *** ** ** * * *** ***
    // I need to get the string between spaces
    // ***
    // *
    // *****
    // and so on
    printf("%d", getNumberOfthem("*** 12 12 12 12 12"));

    return 0;
}