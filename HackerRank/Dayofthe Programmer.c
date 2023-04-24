char* dayOfProgrammer(int year) {
    char *d = (char *)calloc(11,1);
    char *buffer = (char*)malloc(5);
    sprintf(buffer,"%d",year);
    if(year < 1918)
    {
        if((year%4) == 0)
        {
            strcat(d,"12.09.");
            strcat(d,buffer);
        }
        else
        {
            strcat(d,"13.09.");
            strcat(d,buffer);
        }
    }
    else if(year == 1918)
    {
        strcat(d,"26.09.");
        strcat(d,buffer);
    }
    else
    {
        if(((year%400) == 0) || (((year%4) == 0) && ((year%100) != 0)))
        {
            strcat(d,"12.09.");
            strcat(d,buffer);
        }
        else
        {
            strcat(d,"13.09.");
            strcat(d,buffer);
        }
    }
    return d;
}