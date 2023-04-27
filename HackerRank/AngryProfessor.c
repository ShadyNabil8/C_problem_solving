char* angryProfessor(int k, int a_count, int* a) {
    int onTimeStudents = 0;
    for(int i = 0 ; i < a_count ; i++)
    {
        if(a[i] <= 0)
        {
            onTimeStudents++;
        }
    }
    if(onTimeStudents < k)
    {
        return "YES";
    }
    else
    {
        return "NO";
    }

}