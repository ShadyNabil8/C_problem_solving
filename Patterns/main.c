#include <stdio.h>
void pattern_1(int n);
void pattern_2(int n);
void pattern_3(int n);
void pattern_4(int n);
void pattern_5(int n);
void pattern_6(int n);
int main()
{
  pattern_3(6);
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

