int hurdleRace(int k, int height_count, int* height) {
    /* Find the maximun height*/
    int maxHeight = -1;
    for (int i = 0; i<height_count; i++)
    {
        maxHeight = (maxHeight < height[i]) ? height[i] : maxHeight;
    }
    if(k >= maxHeight)
    {
        return 0;
    }
    else
    {
        return maxHeight-k;
    }

}