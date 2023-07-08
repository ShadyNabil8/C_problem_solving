#include <stdio.h>
#include <stdlib.h>

void factorial(int n)
{
    // The factorial of 100 consists of 158 digits
    int arr[1000];
    // Initialze the first number with 1
    arr[0] = 1;
    // Track the size of the array for printing the result
    int arr_size = 1;
    // Initialize the carry with 0;
    int carry = 0;
    // Temp value contains the multiplication value
    int temp = 0;

    for (int i = 1; i <= n; i++)
    {
        carry = 0;
        for (int j = 0; j < arr_size; j++)
        {
            /*
                if temp = 65,  arr[j] = 5, and carry = 6
            */
            temp = (i * arr[j]) + carry;
            arr[j] = temp % 10;
            carry = (int)(temp / 10);
        }
        while(temp >= 1)
        {
            arr_size++;
            arr[arr_size - 1] = temp%10;
            temp = (int)(temp/10);
        }
        // if (temp >= 10)
        // {
        //     arr_size++;
        //     arr[arr_size - 1] = carry;
        // }
    }

    for (int k = 0; k < arr_size; k++)
        printf("%d", arr[arr_size - 1 - k]);
}

int main(void)
{
    factorial(40);

    return 0;
}