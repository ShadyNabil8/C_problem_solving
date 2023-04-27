#ifndef __MAIN_H__
#define __MAIN_H__

int swap(int *x, int *y);
void print_binary(int num);
int mmset(void *const string, const char c, unsigned int n);
int mmcpy(void *dst, unsigned int dst_size, const void *const *src, unsigned int n);
int intRev(int num);/* 12345 => 54321*/
void matrixTr(void *matArg, int n); /* Get the Transpose of a square matrix*/
void matrixFlip(void *matArg, int n); /*flip the first and last element of each row of a square matrix */
int matrixDiff(void *mat1, void *mat2, int n); /* Get the difference between two matrix*/



#endif