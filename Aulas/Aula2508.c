//aula 25/08 ALOCAÇÃO DINÂMICA
//MEMÓRIA é dividida em duas estática(declaradas no inicio) e dinamica (dividida em pilha-acessa o q vem first-, Heap- restante do
//espaco que tem livre, alocado durante a execução do programa-)
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


//funcão malloc recebe um numero inteiro que da  o tamanho d alocação
//calloc esvasia a memoria que aloca;
int main ()
{	
	int n =15;
	int *v1 =malloc(sizeof(int)*n); //sizeof e tam da variavel n= quat de variaveis a serem armazenadas
	int *v2 = calloc(n, sizeof(int)); //x= quantidade y= tipo
	char *str = malloc(sizeof(char)*20);
	
	strcpy (str, "oi, eu sou o goku");
	
	printf ("Antes: %s\n", str);
	
	str =realloc (str, 25);
	strcat(str, "!"); //concatenar
	
	printf ("Depois: %s\n", str);
	
	free(v1);
	free(v2);//libera espaço NUNCA ESQUECER, liberar o espaço alocado depois de usado
	
//    *v1= 10;
	
//	printf ("%d\n", *v1);
	
	return 0;
}
