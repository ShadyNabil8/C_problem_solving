#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (((a) >= (b)) ? (a) : (b))
int compare(const void *p, const void *q)
{
    // Get the values at given addresses
    int x = *(const int *)p;
    int y = *(const int *)q;

    if (x < y)
        return -1;
    else if (x > y)
        return 1;
    else
        return 0;
}
// Complete the flatlandSpaceStations function below.
int flatlandSpaceStations(int n, int c_count, int *c)
{
    qsort(c, c_count, sizeof(int), compare);
    int ans = 0;
    ans = MAX(c[0], n - 1 - c[c_count - 1]);
    for (int i = 1; i < c_count; i++)
    {
        ans = MAX(ans, (int)((c[i] - c[i - 1]) / 2));
    }
    return ans;
}
