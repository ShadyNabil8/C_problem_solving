int pickingNumbers(int a_count, int* a) {
    /* Another solution is to sort the array first*/
    int Max = 0;
    int MaxTemp1 = 0;
    int MaxTemp2 = 0;
    for (int i = 0 ; i < a_count -1 ; i++)
    {
        MaxTemp1 = 1;
        MaxTemp2 = 1;
        for (int j = i+1 ; j < a_count; j++)
        {
            if(((a[i] - a[j]) == -1))
            {
                MaxTemp1++;
            }
            else if(((a[i] - a[j]) == 1))
            {
                MaxTemp2++;

            }
            else if(((a[i] - a[j]) == 0))
            {
                MaxTemp1++;
                MaxTemp2++;
            }
        }
        Max = (MaxTemp1 > Max) ? MaxTemp1 : Max ;
        Max = (MaxTemp2 > Max) ? MaxTemp2 : Max ;
        
    }
    return Max;
}