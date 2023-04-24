void bonAppetit(int bill_count, int* bill, int k, int b) {
    
    int sum = 0;
    for (int i = 0; i<bill_count; i++) 
    {
        if(i == k)
        {
            continue;   
        }
        else
        {
            sum += bill[i];
        }
    }
    sum = sum/2;
    if(b==sum)
    {
        printf("Bon Appetit");
    }
    else
    {
       printf("%i",b-sum); 
    }

}