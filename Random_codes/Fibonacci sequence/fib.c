#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int key;
    long long val;
} obj;

typedef struct
{
    int size;
    obj arr[1024];
} map;

void mapInit(map *m)
{
    m->size = 0;
    memset(m->arr, 0, 1024 * sizeof(obj));
}

int inMap(map *m, int k)
{
    for (int i = 0; i < m->size; i++)
    {
        if (m->arr[i].key == k)
            return i;
    }
    return -1;
}

long long fib(int n, map *m)
{
    if (n <= 2)
        return 1;

    int index = inMap(m, n);

    if (index != -1)
        return m->arr[index].val;

    m->arr[m->size].key = n;
    m->arr[m->size].val = fib(n - 1, m) + fib(n - 2, m);
    m->size++;
    return m->arr[m->size - 1].val;
}
int main()
{
    map m;
    mapInit(&m);
    // 1 1 2 3 5 8 13
    // printf("%d \n",sizeof(long long));
    printf("%lld \n", fib(90, &m));
    return 0;
}