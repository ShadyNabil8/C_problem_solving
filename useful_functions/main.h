#ifndef __MAIN_H__
#define __MAIN_H__

int swap(int *x, int *y);
void print_binary(int num);
int mmset(void *const string, const char c, unsigned int n);
int mmcpy(void *dst, unsigned int dst_size, const void *const *src, unsigned int n);

#endif