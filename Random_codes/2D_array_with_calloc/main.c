#include <stdio.h>
#include <stdlib.h>

/*
    => Assume that this is the array that we want to create with dynamic memory allocation

    1   2   3   4   5
    6   7   8   9   10
    11  12  13  14  15
*/

#define num_rows 3
#define num_columns 5

int main(int argc, char const *argv[])
{
    /*
        => First we will create a 3(num_rows) location of memory.
        => Each location will contain a pointer to one of the columns locations.
    */

    /*Is a pointer to the memory block that contains the pointers to the columns*/
    int **row_ptr = (int **)calloc(num_rows, sizeof(int *));
    if (NULL == row_ptr)
    {
        // Do nothing
    }
    else
    {
        /*We need each pointer to point to different column */
        unsigned int NULL_flag = 0;
        for (int i = 0; i < num_rows; i++)
        {
            *(row_ptr + i) = calloc(num_columns, sizeof(int));
            if (NULL == *(row_ptr + i))
            {
                NULL_flag = 1;
                break;
            }
        }
        if (!NULL_flag)
        {
            /*We need to fill the array*/
            int n = 1;
            for (int i = 0; i < num_rows; i++)
            {
                for (int j = 0; j < num_columns; j++)
                {
                    (*(*(row_ptr + i) + j)) = n++;
                    // row_ptr[i][j] = n++; /*You can use line instade*/
                }
            }

            /*We need to print the array*/
            for (int i = 0; i < num_rows; i++)
            {
                for (int j = 0; j < num_columns; j++)
                {
                    printf("%i\t", (*(*(row_ptr + i) + j)));
                    // printf("%i\t",row_ptr[i][j]); /*You can use line instade*/
                }
                printf("\n");
            }
        }
    }

    return 0;
}
