typedef struct 
{
    int smallest;
    int nonZeroElements;
}data;

void subNum(int* arr , int arr_count, int sub)
{
    for(int i = 0; i < arr_count ; i++)
    {
        if(arr[i] == 0){
            continue;
        }    
        else {
            arr[i] -= sub;
        }
    }
}
void getTheSmallest(int* arr , int arr_count, data* d)
{
    d->smallest = INT_MAX;
    d->nonZeroElements = 0;
    for(int i = 0; i < arr_count ; i++)
    {
        if(arr[i] == 0){
            continue;
        }    
        else {
            d->nonZeroElements ++;
            if(arr[i] < d->smallest)
            {
                d->smallest = arr[i];
            }
        }
    } 
}
int* cutTheSticks(int arr_count, int* arr, int* result_count) {
    int *a = (int*)calloc(1000, sizeof(int));
    if(NULL !=a)
    {
       *result_count = 0;
        data d = {0,0};
        do {
            getTheSmallest(arr,arr_count, &d);
            if(d.nonZeroElements != 0)
            {
                a[*result_count] = d.nonZeroElements;
                (*result_count)++;
                subNum(arr,arr_count,d.smallest);
            }
        }while(d.nonZeroElements != 0);
        return a; 
    }
    else
    {
        return NULL;
    }
}