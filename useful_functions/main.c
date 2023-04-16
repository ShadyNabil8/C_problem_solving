#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main()
{
    return 0;
}

int swap(int *x, int *y)
{
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

void print_binary(int num)
{
    int i;
    printf("Binary representation of %d: ", num);
    for (i = (sizeof(int) * 8) - 1; i >= 0; i--)
    {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int mmset(void *const string, const char c, unsigned int n)
{
    if (!(NULL == string))
    {
        char *temp = (char *)string;
        unsigned int num_of_chars = 0;

        /*Calculate the number of chars in the string*/
        while (*(temp + num_of_chars) != '\0')
        {
            num_of_chars++;
        }

        n = num_of_chars >= n ? n : num_of_chars;

        for (int index = 0; index < n; index++)
        {
            *(temp++) = c;
        }
        return 0; /*OK*/
    }
    else
    {
        return 1; /*NOK*/
    }
}

int mmcpy(void *dst, unsigned int dst_size, const void *const *src, unsigned int n)
{
    /* you should make dst_size greater than the original size by 1
    to let the function add the null operator */
    if (!(NULL == src))
    {
        char *temp = (char *)src;
        unsigned int src_size = 0;
        while (*(temp + src_size) != '\0')
        {
            src_size++; /*Calculate the number of chars in the src*/
        }

        n = src_size >= n ? n : src_size;
        n = dst_size -1 >= n ? n : dst_size -1;

        unsigned int index = 0;
        for (index; index < n; index++)
        {
            *((char *)dst + index) = *((char *)src + index);
        }
        *((char *)dst + index) = '\0';

        return 0; /*OK*/
    }
    else
    {
        return 1; /*NOK*/
    }
}
