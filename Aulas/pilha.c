#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<string.h>
#include "pilha.h"

struct Pilha{
	int item [TAM_MAX];
	int topo;
};


// Criar uma pilha vazia
Pilha* criar_pilha(){
	Pilha *p = (Pilha*)malloc (sizeof(Pilha));
	p->topo=-1;
	
	return p;
}

// Verificar se a pilha está cheia (stack overflow)
int pilha_cheia(Pilha *p){
	
	if (p == NULL)
		return -1;
	else if (p->topo <TAM_MAX-1) //n tá cheia
		return 0;
	else 
		return 1;
}

// Verificar se a pilha está vazia (stack underflow)
int pilha_vazia(Pilha *p){
	if (p==NULL)
		return -1;
	else if (p->topo>= 0)//n ta vazia
		return 0;
	else 
		return 1;
}

// Inserir um novo item na pilha, caso houver espaço
int empilhar(Pilha *p, int chave){
	if (p==NULL)
		p= criar_pilha();
	
	if (!pilha_cheia(p)){
		p->topo++;
		p->item[p->topo]=chave;//recebe a chave elemento
		
		return 1;
	}
	return 0;
}

// Remover item do topo da pilha, caso essa estrutura não estiver vazia
int desempilhar(Pilha *p){
	int item= INT_MIN; //maximo INT_MAX - minimo, menor valor do type int (p dizer q ta vazia)
	
	if (!pilha_vazia(p)){
		item= p->item[p->topo]; //(retira o item do topo;
		p->topo--;
	}
	
	return item;
}

// Imprimir conteúdo da pilha
void imprimir_pilha(Pilha *p){
	Pilha aux= *p;//imprimira a copia
	int x;
	
	if (p!=NULL){
		while (!pilha_vazia(&aux)){
			x=desempilhar(&aux);
			printf("%d ", x);
			
		}
		printf("\n");
	}
}

// Liberar a pilha
void liberar_pilha(Pilha *p){
	if (p!=NULL)
		free(p);
}

// Obter a posição da pilha em que está o topo
int obter_posicao_topo(Pilha *p){
	if (!pilha_vazia(p))
		return p->topo;
	else 
	    return -1;
}

int obter_topo(Pilha *p){
	if (!pilha_vazia(p))
		return p->item[p->topo];
		
	else 
	    return INT_MIN;
}


