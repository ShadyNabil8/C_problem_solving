int GetDigit(int num, int index)
{
    int retVal = -1;
    if (index > 0)
    {
        retVal = (((num % (int)pow((int)10, (int)index)) - ((num % (int)pow((int)10, (int)(index - 1))))) / ((int)pow((int)10, (int)(index - 1))));
    }
    else
    {
    }
    return retVal;
}
int GetNumDigit(int num)
{
    int retVal = 1;
    if (num != 0)
    {
        while ((num/=10) != 0)
        {
            retVal++;
        }
    }
    return retVal;
}
int findDigits(int n) {
    int numOfDigits = GetNumDigit(n);
    int retVal= 0;
    int temp = 0;
    for(int i = 1 ; i <= numOfDigits ; i++)
    {
        temp = GetDigit(n,i);
        if(temp == 0)
        {
            continue;
        }
        else
        {
            if((n%temp) == 0)
            {
                retVal++;
            }
            
        }
    }
    return retVal;
}