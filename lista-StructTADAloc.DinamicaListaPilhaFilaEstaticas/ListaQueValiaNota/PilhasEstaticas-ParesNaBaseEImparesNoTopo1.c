/*Implemente uma função que receba duas pilhas de números inteiros positivos. A função deverá retornar uma terceira pilha resultante da concatenação das duas pilhas, mas os números ímpares deverão estar próximos à base e os pares próximos do topo (utilizar apenas operações de empilhar e desempilhar).

Input Format

Na primeira linha, enquanto "-1" não for lido, ler números inteiros e colocá-los na primeira pilha.

Na segunda linha, enquanto "-1" não for lido, ler números inteiros e colocá-los na segunda pilha pilha.

Constraints

Os elementos da pilha devem ser acessados através da função desempilhar.

Output Format

Imprimir o resultado da concatenação das duas pilhas.*/
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#define TAM_MAX 100

typedef struct Pilha Pilha;

struct Pilha{
	int item[TAM_MAX];
	int topo;
};

Pilha * criar_pilha(){
	Pilha *p=(Pilha *)malloc(sizeof(Pilha));

	p->topo=-1;

	return p;
}
int pilha_vazia(Pilha *p){
	if(p==NULL)
	   return -1;
	else if(p->topo==-1)
		return 1;
	else
		return 0;
}
int pilha_cheia(Pilha *p){
	if (p==NULL)
		return -1;
	else if (p->topo==(TAM_MAX-1))
		return 1;
	else
		return 0;
}
int empilhar(Pilha *p, int chave){
	if (p==NULL)
		p= criar_pilha();

	if(!pilha_cheia(p)){
		p->topo++;
		p->item[p->topo]=chave;

		return 1;
	}
	return 0;
}
int desempilhar (Pilha *p){
	int item=INT_MIN;

	if (!pilha_vazia(p)){
		item = p->item[p->topo];

		p->topo--;
	}
	return item;
}
void imprimir_pilha(Pilha *p){
	Pilha aux = *p;
	int x;

	if (p!=NULL){
		while (!pilha_vazia(&aux)){
			x=desempilhar(&aux);
			printf ("%d ", x);
		}
		printf ("\n");
	}
}
void liberar_pilha(Pilha *p){
	if (p!=NULL)
	  free(p);
}

Pilha * concatenar_pei (Pilha *p1, Pilha *p2, Pilha *p3){
	int i, j;
	Pilha *p4=criar_pilha();
	Pilha *p5=criar_pilha();

	if(p1==NULL){
		while(p2->topo!=-1){
		j=desempilhar(p2);
		if(j%2==0)
			empilhar(p4, j);
		else if(j%2!=0)
			empilhar(p5, j);
		}
		 while(p5->topo!=-1){
			j=desempilhar(p5);
			empilhar(p3, j);
		}
	    while(p4->topo!=-1){
			j=desempilhar(p4);
			empilhar(p3, j);
		}
	}

	else if(p2==NULL){
	while(p1->topo!=-1){
		j=desempilhar(p1);
		if(j%2==0)
			empilhar(p4, j);
		else if(j%2!=0)
			empilhar(p5, j);
		}
		 while(p5->topo!=-1){
			j=desempilhar(p5);
			empilhar(p3, j);
		}
	    while(p4->topo!=-1){
			j=desempilhar(p4);
			empilhar(p3, j);
		}
	}

	else{

		while(p1->topo!=-1){
			j=desempilhar(p1);
				if(j%2==0)
					empilhar(p4, j);
				else if(j%2==1)
					empilhar(p5, j);
		}
		while(p2->topo!=-1){
			j=desempilhar(p2);
				if(j%2==0)
					empilhar(p4, j);
				else if(j%2==1)
					empilhar(p5, j);
		}
		while(p5->topo!=-1){
			j=desempilhar(p5);
			empilhar(p3, j);
		}
		while(p4->topo!=-1){
			j=desempilhar(p4);
			empilhar(p3, j);
		}
	}
	liberar_pilha(p4);
	liberar_pilha(p5);
	return p3;
}
int main (){
	Pilha *p1,*p2, *p3;
	int item;

	p1=criar_pilha();

	do{
        scanf("%d", &item);

           if (item!=-1)
               empilhar (p1, item);

    }while(item!=-1);

    p2=criar_pilha();

	do{
        scanf("%d", &item);

           if (item!=-1)
               empilhar (p2, item);

    }while(item!=-1);

    p3=criar_pilha();

    concatenar_pei(p1, p2, p3);

    imprimir_pilha(p3);

    liberar_pilha(p1);
    liberar_pilha(p2);
    liberar_pilha(p3);

    return 0;
}
