/*
 * @brief:  To understand the idea: https://www.youtube.com/watch?v=_uQCgss-aB4&t=647s  
*/


#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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
int formingMagicSquare(int s_rows, int s_columns, int **s)
{
    int cost = INT_MAX;
    int tempCost = 0;
    int **arr = (int **)calloc(3, sizeof(int *));
    for (int i = 0; i < 3; i++)
    {
        *(arr + i) = (int *)calloc(3, sizeof(int));
    }
    *(*(arr + 0) + 0) = 8;
    *(*(arr + 0) + 1) = 3;
    *(*(arr + 0) + 2) = 4;
    *(*(arr + 1) + 0) = 1;
    *(*(arr + 1) + 1) = 5;
    *(*(arr + 1) + 2) = 9;
    *(*(arr + 2) + 0) = 6;
    *(*(arr + 2) + 1) = 7;
    *(*(arr + 2) + 2) = 2;
    for (int k = 0; k < 4; k++)
    {
        for (int i = 0; i < 2; i++)
        {
            tempCost = abs(matrixDiff(arr, s, 3));
            cost = (tempCost < cost) ? tempCost : cost;
            matrixTr(arr, 3);
        }
        matrixTr(arr, 3);
        matrixFlip(arr, 3);
    }
    return cost;
}