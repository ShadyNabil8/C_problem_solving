char* catAndMouse(int x, int y, int z) {
    char *ans = (char*)calloc(8, sizeof(char));
    if(abs(x-z) == abs(y-z))
    {
       ans = "Mouse C"; 
    }
    else if(abs(x-z) > abs(y-z))
    {
         ans = "Cat B";
    }
    else
    {
         ans = "Cat A";
    }

    return ans;
}
