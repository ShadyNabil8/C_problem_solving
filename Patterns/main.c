#include <stdio.h>
void pattern_1(int n);
void pattern_2(int n);
void pattern_3(int n);
void pattern_4(int n);
void pattern_5(int n);
void pattern_6(int n);
int main()
{
  pattern_6(6);
  return 0;
}

void pattern_1(int n)
{
  /*
   *
   **
   ***
   ****
   *****
   ******
   */
  int row = 1;
  int col = 1;
  for (row = 1; row <= n; row++)
  {
    for (col = row; col >= 1; col--)
    {
      printf("*");
    }
    printf("\n");
  }
}

void pattern_2(int n)
{
  /*
  ******
  *****
  ****
  ***
  **
  *
  */
  int row = 1;
  int col = 1;
  for (row = n; row >= 1; row--)
  {
    for (col = row; col >= 1; col--)
    {
      printf("*");
    }
    printf("\n");
  }
}

void pattern_3(int n)
{
  /*

  ******
  *   *
  *  *
  * *
  **
  *

  */
  int row = 1;
  int col = 1;
  for (col = 1; col <= n; col++)
  {
    printf("*");
  }
  for (row = n - 1; row >= 2; row--)
  {
    printf("\n*");
    for (col = row - 2; col >= 1; col--)
    {
      printf(" ");
    }
    printf("*");
  }
  printf("\n*");
}

void pattern_4(int n)
{
  /*

  1 
  1 2
  1 2 3
  1 2 3 4
  1 2 3 4 5
  1 2 3 4 5 6

  */
  int row = 1;
  int col = 1;
  for (row; row <= n; row++)
  {
    for (col = 1; col <= row; col++)
    {
      printf("%i ", col);
    }
    printf("\n");
  }
}

void pattern_5(int n)
{
  /*

  1 2 3 4 5 6
  1 2 3 4 5
  1 2 3 4
  1 2 3
  1 2
  1

  */
  int row = n;
  int col = 1;
  for (row; row >= 1; row--)
  {
    for (col = 1; col <= row; col++)
    {
      printf("%i ", col);
    }
    printf("\n");
  }
}

void pattern_6(int n)
{
  /*

  1
  1 2
  1   3
  1     4
  1       5
  1 2 3 4 5 6
  
  */
  int row = 2;
  int col = 1;
  printf("1\n");
  for(row ; row <= n-1 ; row++)
  {
    printf("1 ");
    for(col = row-2 ; col >= 1 ; col--)
    {
      printf("  ");
    }
    printf("%d\n",row);
  }
  for(col = 1 ; col <= n ; col++)
  {
    printf("%d ",col);
  }

}