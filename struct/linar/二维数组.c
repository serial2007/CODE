#include <stdio.h>
#include <malloc.h>
int main()
{
	int** a = (int**) malloc(5*5 * sizeof(int));
	int (*b)[5] = (int(*)[5])a;
	int (*ptr)(void) = main;
	free(a);
}