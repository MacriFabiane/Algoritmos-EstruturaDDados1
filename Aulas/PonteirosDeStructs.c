//ponteiros em structs: 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//(*p).campo==p->campo

typedef struct {
	char nome[101];
	int RA;
	float coef;
}Aluno1;

typedef struct {
	char nome[101];
	int *RA;
	float coef;
}Aluno2;

int main ()
{
	Aluno1 a;
	Aluno1 *p;//vai armazenar os enderecos do tipo aluno1, no caso 3;
	Aluno2 b;
	Aluno2 *pb;
	int ra;
	
	pb = &b;
	
	//*b.RA = &b; //campo como ponteiros 
	(*pb).RA = &b; //ponteiro acessando ponteiro
	//*(*pb).RA = 120 //atribuir valora a variavel apontada por dois ponteiros ==*pb ->RA;

	p =&a;
	
	(*p).RA=123; //armazena no endereco o RA, pelo endereço NAO CONFUNDIR COM *P.ra
	(*p).coef = 6.5;
	strcpy((*p).nome, "Alcebiates");
	
	printf ("%d\n", *(*pb).RA); //ponteiro apontando pra outro que aponta pra variavel
	
	/*printf ("%x\n", p);
	printf ("%x\n", &a);
	
	printf ("%s\n", (*p).nome);
	printf ("%d\n", (*p).RA);
	printf ("%f\n", (*p).coef);*/
	
	
	
	return 0;
}
