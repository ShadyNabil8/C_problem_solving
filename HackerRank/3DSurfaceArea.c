int surfaceArea(int A_rows, int A_columns, int **A)
{
    // h 1 3 4
    // h 2 2 3
    // h 1 2 4
    //   w w w
    int area = 0;
    area += A_rows * A_columns * 2;
    for (int r = 0; r < A_rows; r++)
    {
        area += (A[r][0] + A[r][A_columns - 1]);
        if (r < A_rows - 1)
        {
            for (int c = 0; c < A_columns; c++)
            {
                area += abs(A[r][c] - A[r + 1][c]);
            }
        }
    }
    for (int c = 0; c < A_columns; c++)
    {
        area += (A[0][c] + A[A_rows - 1][c]);
        if (c < A_columns - 1)
        {
            for (int r = 0; r < A_rows; r++)
            {
                area += abs(A[r][c] - A[r][c + 1]);
            }
        }
    }

    printf("%d", area);
    return area;
}