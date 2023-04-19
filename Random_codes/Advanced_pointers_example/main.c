/*
    ******************** When dealing with pointers in C ********************

    int *ptr1;          // pointer to int
    int (*ptr3)[2];     // pointer to array
    int (*ptr4)(void);  // pointer to fun
    int *ptr5(void);    // function returns pointer

    => Conclusion 1: "pointer to" means that the *ptr is encapsulated with()
    like (*ptr), or there is no thins after it

    => Conclusion 2: if (void) comed directly after ptr, it is a function
    in the case the ptr is not pointer fron conclusion 1

    => If conclusion 2 is happend and it is a function, then the thing berfore it
    will be returned
*/

/*
    This code uses some comples forms of pointers
*/

#include <stdio.h>

/*Declear the functions*/
int function1(void);
int function2(void);
int function3(void);
int function4(void);
/*Function takes void and returns a pointer to an array of type pointer to function :)*/
int (*(*get_ptr_to_arr(void))[4])(void);

/*Array of pointers to functions*/
int (*(*arr[4]))(void) = {function1, function2, function3, function4};

int main()
{
    /*Pointer to array of rype pointer to function*/
    int (*(*ptr_to_arr)[4])(void) = get_ptr_to_arr();

    for (int i = 0; i < 4; i++)
    {
        printf("%d \n", (*ptr_to_arr)[i]());
    }
    return 0;
}

int function1(void)
{
    return 1;
}
int function2(void)
{
    return 2;
}
int function3(void)
{
    return 3;
}
int function4(void)
{
    return 4;
}
int (*(*get_ptr_to_arr(void))[4])(void)
{
    /*Pointer to array of rype pointer to function*/
    int (*(*ptr_to_arr)[4])(void) = &arr;
    return ptr_to_arr;
}
