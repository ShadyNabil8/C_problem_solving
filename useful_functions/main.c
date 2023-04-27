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

int intRev(int num)
{
    int temp = num;
    int digits = 1;
    while ((temp /= 10) != 0)
    {
        digits++;
    }
    char *buffer = (char *)calloc(digits + 1, sizeof(char));
    sprintf(buffer, "%d", num);
    for (int i = 0; i < digits / 2; i++)
    {
        /*swap*/
        buffer[i]              = buffer[i] ^ buffer[digits - i - 1];
        buffer[digits - i - 1] = buffer[i] ^ buffer[digits - i - 1];
        buffer[i]              = buffer[i] ^ buffer[digits - i - 1];
    }
    temp = atoi(buffer);
    free(buffer);
    return temp;
}

void matrixTr(void *matArg, int n)
{
    int NULL_flag = 0;
    int **matrix = (int **)calloc(n, sizeof(int *));
    if (NULL != matrix)
    {
        for (int i = 0; i < 3; i++)
        {
            *(matrix + i) = (int *)calloc(n, sizeof(int));
            if (NULL == *(matrix + i))
            {
                NULL_flag = 1;
                break;
            }
        }
        if (!NULL_flag)
        {
            for (int r = 0; r < n; r++)
            {
                for (int c = 0; c < n; c++)
                {

                    /*  *((*(matrix + r)) + c) = *((*((int **)matArg + r)) + c);  */
                    matrix[r][c] = ((int **)matArg)[r][c];
                }
            }
            for (int r = 0; r < n; r++)
            {
                for (int c = 0; c < n; c++)
                {
                    /*  *((*((int **)matArg + r)) + c) = *((*(matrix + c)) + r);   */
                    ((int **)matArg)[r][c] = matrix[c][r];
                }
            }
        }
        else
        {
        }
    }
    else
    {
        NULL_flag = 1;
    }
    for (int i = 0; i < n; i++)
    {
        free(*(matrix + i));
    }
    free(matrix);
    //  return flag;
}
void matrixFlip(void *matArg, int n)
{
    for (int i = 0; i < n; i++)
    {
        /* *(*((int **)matArg + i)) = *(*((int **)matArg + i)) ^ *(*((int **)matArg + i) + n - 1);
         *(*((int **)matArg + i) + n - 1) = *(*((int **)matArg + i)) ^ *(*((int **)matArg + i) + n - 1);
         *(*((int **)matArg + i)) = *(*((int **)matArg + i)) ^ *(*((int **)matArg + i) + n - 1); */
        ((int **)matArg)[i][0] = ((int **)matArg)[i][0] ^ ((int **)matArg)[i][n - 1];
        ((int **)matArg)[i][n - 1] = ((int **)matArg)[i][0] ^ ((int **)matArg)[i][n - 1];
        ((int **)matArg)[i][0] = ((int **)matArg)[i][0] ^ ((int **)matArg)[i][n - 1];
    }
}
int matrixDiff(void *mat1, void *mat2, int n)
{
    int diff = 0;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            /*diff += abs(*(*((int **)mat1 + r) + c) - *(*((int **)mat2 + r) + c));*/
            diff += abs(((int **)mat1)[r][c] - ((int **)mat2)[r][c]);
        }
    }
    return diff;
}