#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int key;
    bool val;
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

bool canSum_Optimized(int *arr, int size, int target, map *m)
{
    if (target < 0)
        return false;
    if (target == 0)
        return true;

    int index = inMap(m, target);

    if (index != -1)
        return m->arr[index].val;

    for (int i = 0; i < size; i++)
    {
        int remainder = target - arr[i];

        if (canSum_Optimized(arr, size, remainder, m) == true)
        {
            m->arr[m->size].key = target;
            m->arr[m->size].val = true;
            m->size++;
            return true;
        }
    }
    m->arr[m->size].key = target;
    m->arr[m->size].val = false;
    m->size++;
    return false;
}

bool canSum_BruteForce(int *arr, int size, int target)
{
    if (target < 0)
        return false;
    if (target == 0)
        return true;

    for (int i = 0; i < size; i++)
    {
        int remainder = target - arr[i];
        bool can = canSum_BruteForce(arr, size, remainder);
        if (can)
            return true;
    }
    return false;
}

int main()
{
    map m;
    mapInit(&m);
    int arr2[2] = {2, 3};
    int arr3[4] = {5, 3, 4, 7};
    int arr4[2] = {2, 4};
    int arr5[3] = {2, 3, 5};
    int arr6[2] = {7, 14};
    printf("%d \n", canSum_Optimized(arr2, 2, 7, &m)); // true
    mapInit(&m);
    printf("%d \n", canSum_Optimized(arr3, 4, 7, &m)); // true
    mapInit(&m);
    printf("%d \n", canSum_Optimized(arr4, 2, 7, &m)); // false
    mapInit(&m);
    printf("%d \n", canSum_Optimized(arr5, 3, 8, &m)); // true
    mapInit(&m);
    printf("%d \n", canSum_Optimized(arr6, 2, 300, &m)); // false
    return 0;
}