/*Implemente uma função que receba um número inteiro na base decimal. A função deverá retornar uma pilha com elementos resultantes da conversão da entrada para a base octal.

Para a resolução desse exercício, utilize um TAD do tipo pilha estática para números inteiros, podendo ser o código apresentado em sala de aula.

#define TAM_MAX 100

typedef struct ItemP ItemP;

typedef struct Pilha Pilha;

Pilha* criar_pilha();

int pilha_cheia(Pilha *p);

int pilha_vazia(Pilha *p);

int empilhar(Pilha *p, int chave);

ItemP* desempilhar (Pilha *p);

void imprimir_pilha(Pilha *p);

void liberar_pilha(Pilha *p);

void liberar_itemP(ItemP *item);

int obter_chaveP(ItemP *item);

int obter_posicao_topo(Pilha *p);
Observação: não é necessário considerar o arquivo .h, já que no HackerRank não tem como "upar" arquivos .h e .c.

Input Format

A primeira linha apresenta um inteiro N, denotando o número de entradas na base decimal que serão testadas. Nas próximas N linhas devem ser lidos os números na base decimal.

Constraints

.

Output Format

A saída deve conter N linhas contendo os resultados da conversão dos números para a base octal.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<limits.h>

#define TAM_MAX 100

typedef struct Pilha Pilha;

struct Pilha{
    int item[TAM_MAX];
    int topo;
};

Pilha* criar_pilha(){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));

    p->topo = -1;

    return p;
}

int pilha_cheia(Pilha *p){

    if (p == NULL)
        return -1;
    else if (p->topo == (TAM_MAX - 1))
        return 1;
    else
        return 0;
}

int pilha_vazia(Pilha *p){

    if (p == NULL)
        return -1;
    else if (p->topo == -1)
        return 1;
    else
        return 0;
}

int empilhar(Pilha *p, int item){

    if (p == NULL)
        p = criar_pilha();

    if (!pilha_cheia(p)){
        p->topo++;

        p->item[p->topo] = item;

        return 1;
    }

    return 0; // opera
}

int desempilhar (Pilha *p){
    int item = INT_MIN;

    if (!pilha_vazia(p)){
        item = p->item[p->topo];

        p->topo--;
    }

    return item;
}

void imprimir_pilha(Pilha *p){

    Pilha aux = *p;
    int item;

    while (!pilha_vazia(&aux)){
        item = desempilhar(&aux);
        printf ("%d", item);
    }
    printf("\n");
}

// Liberar a pilha
void liberar_pilha(Pilha *p){
    if (p != NULL)
        free(p);
}

int obter_posicao_topo(Pilha *p){
    if (!pilha_vazia(p))
        return p->topo;
    else
        return -1;
}

Pilha* dec2oct(int n){
    Pilha *p =criar_pilha();

    do {
        empilhar(p, n%8);
        n = n/8;
    }while(n!=0);

    return p;
}

int main() {
    int n, i, item;
    Pilha *p;

    scanf ("%d", &n);

    for (i=0; i<n; i++){
        scanf("%d", &item);

        p= dec2oct(item);
        imprimir_pilha(p);

        liberar_pilha (p);
    }

    return 0;
}
