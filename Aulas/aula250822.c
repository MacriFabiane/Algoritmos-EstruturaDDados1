//alocação de fucoes
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int* func (int *v)
{
	int *p = malloc (sizeof(int)*2);
	p[0]=v[0]*v[0];
	p[1]= v[1]*v[1];
	
	return p;
}
int main ()
{	
	
	int *v1 =malloc(sizeof(int)*2); 
	int *v2 = NULL;
	v1[0]=2;
	v2

	
	return 0;
}
