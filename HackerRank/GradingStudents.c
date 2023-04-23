int* gradingStudents(int grades_count, int* grades, int* result_count) {
    int *ptr = (int*)calloc(grades_count, sizeof(int));
    if(ptr != NULL)
    {
        *result_count = grades_count;
        int temp = 0;
        int rem = 0;
        for(int i = 0 ; i < grades_count ; i++)
        {
            temp = *(grades+i);
            if(temp < 38)
            {
                // Do nothing
            }
            else
            {
                rem = temp%5;
                if((5-(rem)) < 3)
                {
                   *(grades+i) = temp - rem + 5; 
                }
                else
                {
                   // Do nothing 
                }
            }
            
        }
        
    }
    else
    {
        
    }
    return grades;

}