int beautifulPairs(int A_count, int *A, int B_count, int *B)
{
    int freq[1001] = {0}; // Assuming values in A and B are between 1 and 1000
    int beautiful_pairs = 0;

    // Count the frequencies of elements in array A
    for (int i = 0; i < A_count; i++)
    {
        freq[A[i]]++;
    }

    // Iterate through array B and find beautiful pairs
    for (int i = 0; i < B_count; i++)
    {
        if (freq[B[i]] > 0)
        {
            beautiful_pairs++;
            freq[B[i]]--; // Mark the element as used in A
        }
    }

    // If all elements are beautiful pairs, decrement one to make a swap
    if (beautiful_pairs == A_count && beautiful_pairs == B_count)
    {
        return beautiful_pairs - 1;
    }
    else
    {
        return beautiful_pairs + 1;
    }
}