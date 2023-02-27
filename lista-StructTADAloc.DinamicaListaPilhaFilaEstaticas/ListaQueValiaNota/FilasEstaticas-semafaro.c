/*Três estradas movimentadas ligam a uma única rodovia (principal), conforme a figura abaixo. Para o gerenciamento do trânsito, um semáforo foi adicionado para cada estrada, na qual, enquanto o
sinal estiver verde, os veículos que chegaram primeiro podem acessar a rodovia principal. Quando o sinal estiver verde para uma estrada, para as outras duas estradas, o sinal será vermelho.
No entanto, como as estradas estão cheias de buracos e os veículos devem transitar vagarosamente, para cada vez que o sinal estiver verde para uma estrada, apenas três veículos conseguem acessar a
estrada principal antes do sinal ficar vermelho. Por outro lado, os semáforos possuem um sistema inteligente, no qual, enquanto a estrada estiver vazia, o sinal será vermelho. Também, durante o sinal verde,
quando a estrada tiver menos que três veículos, assim que os mesmos acessarem a rodovia principal, o sinal ficará vermelho antecipadamente.

image

Implemente uma função para o gerenciamento do trânsito conforme ilustrado acima. A função deverá receber, como parâmetro, 4 filas estáticas (E1, E2, E3, R). Na função, os elementos de E1, E2 e E3 devem ser transferidos para R de forma que simule o trânsito descrito acima.

Input Format

Em cada uma das 3 primeiras linhas, enquanto -1 não for lido, ler números inteiros e inserí-los em suas respectivas filas (E1, E2 e E3).

Constraints

O acesso aos elementos da fila deve ser através da função desenfileirar.

Output Format

Imprimir a fila R*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<limits.h>
#define TAM_MAX 100

typedef struct Fila Fila;

struct Fila{
	int item[TAM_MAX];
	int ini;
	int fim;
	int tam;
};
Fila * criar_fila(){
	Fila *f = (Fila*)malloc(sizeof(Fila));

	f->ini =f->fim = -1;

	f->tam =0;

	return f;
}
int fila_cheia(Fila *f){
	if (f==NULL)
		return -1;
	else if (f->tam<TAM_MAX)
		return 0;
	else
		return 1;
}
int fila_vazia(Fila *f){
	if (f==NULL)
		return -1;
	else if (f->tam>0)
		return 0;
	else
		return 1;
}
int enfileirar(Fila *f, int chave){
	if (f==NULL)
		f=criar_fila();

	if (!fila_cheia(f)){

        if (f->ini < 0)
            f->ini = 0;

        if (f->fim < TAM_MAX - 1)
            f->fim++;
        else
            f->fim = 0;

        f->item[f->fim] = chave;

        f->tam++;

        return 1;
    }

    return 0; // A fila estava cheia
}
int desenfileirar (Fila *f){
	int item= INT_MIN;

	if(!fila_vazia(f)){
		item =f->item[f->ini];
		f->tam--;

		if (f->tam == 0){
            f->ini = -1;
            f->fim = -1;
        }
		else if (f->ini < TAM_MAX - 1)
            f->ini++;
        else
            f->ini = 0;
	}
	return item;
}
void imprimir_fila(Fila *f){
	int item;
	Fila aux=*f;

	while (!fila_vazia(&aux)){
		item = desenfileirar(&aux);

        printf("%d ", item);
	}
	printf ("\n");

}
void liberar_fila(Fila *f){
    if (f != NULL)
        free(f);
}
Fila * concatenar (Fila *e1, Fila *e2, Fila *e3, Fila *R){
	int i=0;

	do{
        if(e1->tam >= 3)
        {
            i=0;
            do
            {
                enfileirar(R, desenfileirar(e1));
                i++;
            }
            while(i<3);
        }
        else if(e1->tam <3)
        {
            while(e1->tam != 0)
            {
                enfileirar(R, desenfileirar(e1));
            }
        }

        if(e2->tam >= 3)
        {
            i=0;
            do
            {
                enfileirar(R, desenfileirar(e2));
                i++;
            }
            while(i<3);
        }
        else if(e2->tam <3)
        {
            while(e2->tam != 0)
            {
                enfileirar(R, desenfileirar(e2));
            }
        }

        if(e3->tam >= 3)
        {
            i=0;
            do
            {
                enfileirar(R, desenfileirar(e3));
                i++;
            }
            while(i<3);
        }
        else if(e3->tam <=3)
        {
            while(e3->tam != 0)
            {
                enfileirar(R, desenfileirar(e3));
            }
        }
	}while((!fila_vazia(e1))||(!fila_vazia(e2))||(!fila_vazia(e3)));
	return R;
}

int main (){
	Fila *e1, *e2, *e3, *R;
	int i;

	e1=criar_fila();
	do{
		scanf ("%d", &i);
		if(i!=-1){
			enfileirar(e1, i);
		}

	}while (i!=-1);

	e2=criar_fila();
	do{
		scanf ("%d", &i);
		if(i!=-1){
			enfileirar(e2, i);
		}


	}while (i!=-1);

	e3=criar_fila();
	do{
		scanf ("%d", &i);
		if(i!=-1){
			enfileirar(e3, i);
		}

	}while (i!=-1);

	R=criar_fila();

	concatenar (e1, e2, e3, R);

	imprimir_fila(R);

	liberar_fila(e1);
	liberar_fila(e2);
	liberar_fila(e3);
	liberar_fila(R);

	return 0;
}
