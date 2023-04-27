int viralAdvertising(int n) {
    int shared = 5;
    int commulative = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        commulative += (shared/=2);
        shared *= 3;
        
    }
    return commulative;
}