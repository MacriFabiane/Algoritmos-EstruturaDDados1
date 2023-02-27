//ponteiros-> tipo de dado para armazenar enderecos de tipos de dados, ou alocação dinamica
//declarar ponteiro tipo de dado *x, colocara asterisco na variavel;
#include <stdio.h>
#include <string.h>

int main (){
	
	int i=16;
	char c= 'a';
	int *pi;
	char *pc;
	
	pi= &i; //atribuir o enderec da variavel ao ponteiro, ponteiro pi aponta para a variavel i;
	pc = &c;
	 //OPERADORES DE PONTEIRO = & , *->declara ponteiro, acessa o valor atribuido ao enderereco q o ponteiro aponta.
	printf("%d\n", i);
	printf("%d\n", *pi);
	printf("endereco: %x\n", &i);
	printf("endereco: %x\n", pi);
	
	*pi= 100;
	
	printf("%d\n", i);
	printf("%d\n", *pi);
	
	i=28;
	printf("%d\n", i);
	printf("%d\n", *pi);
	
	return 0;
}
