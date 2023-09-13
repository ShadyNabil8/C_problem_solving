#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>


// Function to check if a number is a power of 2
bool isPowerOf2(int x)
{
    return x > 0 && !(x & (x - 1));
}

// Comparison function for sorting key-value pairs by key


// Comparison function for sorting array element
int compare_int(const void *a, const void *b)
{
    return (*(int *)a) - (*(int *)b);
}

// function to return the max number of an array
int getMax(int n, int arr[])
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    // max = (max < arr[i]) ? arr[i] : max;
}

int countPairs(int n, int arr[])
{

    // qsort(arr, n, sizeof(int), compare_int);
    int max = getMax(n, arr);

    int *m = (int *)calloc(max + 1, sizeof(int));

    if (m == NULL)
        return -1;

    for (int i = 0; i < n; i++)
        m[arr[i]]++;

    int ans = 0;
    int a = 0, b = 0;
    int a_c = 0, b_c = 0; // a_count , b_count
    for (int i = 0; i < max + 1; i++)
    {
        a = i;
        a_c = m[i];

        if (a_c == 0)
            continue;

        for (int j = i; j < max + 1; j++)
        {
            b = j;
            b_c = m[j];

            if (b_c == 0)
                continue;

            if (isPowerOf2(a & b))
            {
                if (a == b)
                    ans += ((a_c) * (a_c - 1)) / 2;
                else
                    ans += a_c * b_c;
            }
        }
    }

    free(m); // Free dynamically allocated memory

    return ans;
}

int main()
{
    int arr[500] = {0};
    for (int i = 0; i < 500; i++)
    {
        arr[i] = i;
        // printf("%d : %d\n",i,arr[i]);
    }

    printf("%d \n", countPairs(sizeof(arr) / sizeof(arr[0]), arr));

    return 0;
}