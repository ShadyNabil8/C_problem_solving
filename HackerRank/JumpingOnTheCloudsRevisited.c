int jumpingOnClouds(int c_count, int* c, int k) {
    int energy = 100;
    int index = 0;
    do
    {
        /* There is a trick because you may need to iterate multipe time to get the cloud 0*/
        energy = (c[(index + k)%c_count]) ? (energy -3) :(energy -1);
        index += k;
        index %= c_count;
    }
    while((index)!=0);
    
    //energy = (c[0]) ? (energy -3) :(energy -1);
    return energy;
}