#include <stdio.h>
#include <string.h>
int main(){
	int v[]={1,2,3,4,5, 6, 7,8, 9, 10};
	int i;
	for (i=0; i<10; i++)
	    printf("%d\n", *(v+i));//outra forma de imprimir vetor 
	
	return 0;
}
