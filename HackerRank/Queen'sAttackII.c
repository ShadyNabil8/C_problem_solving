int queensAttack(int n, int k, int r_q, int c_q, int obstacles_rows, int obstacles_columns, int **obstacles)
{
    int res = 0;

    int **ob = (int **)calloc(n + 1, sizeof(int *));

    for (int r = 1; r <= n; r++)
        ob[r] = (int *)calloc(n + 1, sizeof(int));

    for (int r = 0; r < obstacles_rows; r++)
        ob[obstacles[r][0]][obstacles[r][1]]++;

    int upDown[8] = {1, -1, 0, 0, 1, 1, -1, -1};
    int rightLeft[8] = {0, 0, 1, -1, 1, -1, 1, -1};

    int row = 0; // Up and down variable
    int col = 0; // Right and Left variable
    for (int i = 0; i < 8; i++)
    {
        row = r_q + upDown[i];
        col = c_q + rightLeft[i];
        while ((row >= 1) && (col >= 1) && (row <= n) && (col <= n) && (ob[row][col] == 0))
        {
            res++;
            row += upDown[i];
            col += rightLeft[i];
        }
    }

    for (int r = 1; r <= n; r++)
        free(ob[r]);

    free(ob);

    return res;
}