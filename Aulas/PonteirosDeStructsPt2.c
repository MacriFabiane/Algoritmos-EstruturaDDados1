//ponteiros em structs parte 2 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//(*p).campo==p->campo

/*typedef struct ponto {
	int a, b;
}ponto;

void troca (ponto *p)
{
	int aux = p->a;
	p->a=p->b;
	p->b =aux;
}*/

//na UNION só podemos utilizar um campo
typedef enum { azul=10, verde, vermelho, rosa
}Cor; //atribui numeros aos valores
typedef struct{
	char nome[10];
	Integer in;
/*	xunion { 
		short s;    //UNIONS ANONIMAS
		int i;
		long l;
		float f;
	};*/
}Algo;


typedef union {
	short s;
	int i;
	long l;
	float f;
}Integer;

int main ()
{
	Algo a;
	printf ("%d", azul);
	a.in.f=10.125; ///se tivesse a intercessao //se fosse a anonima nao precisaria disso o in
	
	printf ("%d\n", a.in.s);
	printf ("%d\n", a.in.i);
	printf ("%d\n", a.in.l);
	printf ("%f\n", a.in.f);
	
	return 0;
}
