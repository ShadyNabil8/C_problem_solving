#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#define MOD (int)(10e9 + 7)

int compare(const void *x, const void *y)
{
    return *(int *)x - *(int *)y;
}

// The brute force solustion
uint64_t sortedSums_bf(int size, int *arr)
{
    int var = 1;
    uint64_t ans = 0;
    for (int i = 0; i < size; i++)
    {
        qsort(arr, var, sizeof(int), compare);
        for (int j = 1; j <= var; j++)
        {
            ans += j * arr[j - 1];
        }
        var++;
    }
    return ans % MOD;
}

// try to omtimize the solution
uint64_t sortedSums_ob(int size, int *arr)
{

    uint64_t ans = 0;                                // returned value
    int *ws = (int *)calloc(size, sizeof(int)); // ws: workshop
    int ws_size = 0;
    int fl = 0; // first larger element
    int current = 0;
    for (int i = 0; i < size; i++)
    {

        fl = 0;
        current = arr[i];

        // First get the 1s element larger that current element
        for (; fl < ws_size; fl++)
        {
            if (ws[fl] > current)
                break;
        }

        // Sheft
        for (int j = ws_size; j > fl; j--)
            ws[j] = ws[j - 1];

        ws[fl] = current;

        ws_size++;

        for (int k = 1; k <= ws_size; k++)
            ans += ws[k - 1] * k;
    }

    free(ws);
    return ans % MOD;
}

int main()
{
    int arr[10000] = {0};
    for(int i = 10000 ; i >= 1 ; i--)
    {
        arr[i] = i;
    }
    int x = sortedSums_ob((sizeof(arr) / sizeof(arr[0])), arr);
    printf("%d \n", x);
    x = sortedSums_bf((sizeof(arr) / sizeof(arr[0])), arr);
    printf("%d \n", x);
    return 0;
}