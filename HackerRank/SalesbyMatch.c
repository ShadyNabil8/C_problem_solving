int sockMerchant(int n, int ar_count, int* ar) {
    n = 0;
    int max = *ar;
    /*1-fimd the max numer in the ar*/
    for(int i = 0 ; i <ar_count ; i++)
    {
        if(*(ar+i) > max)
        {
            max = *(ar+i);;
        }
    }
    int *arrPtr = (int*)calloc(max+1, sizeof(int));
    if(arrPtr != NULL)
    {
        for(int i = 0 ; i < ar_count ; i++)
        {
            (*(arrPtr + (*(ar+i))))++;
        }
        
        for(int i = 0 ; i < max+1 ; i++)
        {
            n += (int)((*(arrPtr+i))/2);
        }
        
    }
    return n;
}