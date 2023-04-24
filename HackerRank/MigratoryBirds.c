int migratoryBirds(int arr_count, int* arr) {
    /* I know that in the question the max number is 5 as the Constraints,
    but i make it general*/
    
    int id = 0;
    /*1-Find the max number*/
    int maxNum = *arr;
    for(int i = 1 ; i < arr_count ; i++)
    {
        if(maxNum < *(arr+i))
        {
            maxNum = *(arr+i);
        }
    }
    /*2-Create an array with {maxNum} of elements*/
    int *ptr = (int*)calloc(maxNum+1,sizeof(int));
    if(ptr != NULL)
    {
        for(int i = 0 ; i < arr_count ; i++)
        {
            /*3-treat any number in arr as an index in ptr*/
            (*(ptr+(*(arr+i))))++;
        }
        
        /*4-find the most frequently sighted birds*/
        int f = *(ptr);
        for(int i = 1 ; i < maxNum+1 ; i++)
        {
            if(f < *(ptr+i))
            {
                /*This will automaticly get the lowest of the he most 
                  frequently sighted bird id*/
                f = *(ptr+i);
                id = i;
            }
            else
            {
                
            }
            
        }
    }
    else
    {
        
    }
    return id;
}
}