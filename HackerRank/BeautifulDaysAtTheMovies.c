int intRev(int num)
{
    int temp = num;
    int digits = 1;
    while ((temp /= 10) != 0)
    {
        digits++;
    }
    char *buffer = (char *)calloc(digits + 1, sizeof(char));
    sprintf(buffer, "%d", num);
    for (int i = 0; i < digits / 2; i++)
    {
        /*swap*/
        buffer[i]              = buffer[i] ^ buffer[digits - i - 1];
        buffer[digits - i - 1] = buffer[i] ^ buffer[digits - i - 1];
        buffer[i]              = buffer[i] ^ buffer[digits - i - 1];
    }
    temp = atoi(buffer);
    free(buffer);
    return temp;
}
int beautifulDays(int i, int j, int k) {
    int ans = 0;
    while(i <= j)
    {
        if((abs(i - intRev(i)) % k) == 0)
        {
            ans++;
        }
        i++;
    }
    
    return ans;
}