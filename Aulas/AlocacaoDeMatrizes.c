//Alocação de matrizes 
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int** gerar_matriz(int n){
	//int** m = malloc (sizeof(int*)*n); //*no int do sizeof
	int** m = malloc (n, sizeof(int*)); //*no int do sizeof
	int i;
	
	for (i=0; i<n; i++){
		m[i]=malloc (sizeof(int) * n);
	}
	return m;
}
int main (){
	int mat  [4][4]={{1,2,3,4},{1,2,3,4}, {1,2,3,4}, {1,2,3,4}};
	int *v = mat[0];
	int i; 
	int **mat;//matriz ponteiro de ponteiros
	
	for (i=0; i<4; i++)
	{
	   printf ("%d\n", v[i]);
	}
		
		
	return 0;
}
