/*Dada uma expressão qualquer com parênteses, indique se a quantidade de parênteses está correta ou não, sem levar em conta o restante da expressão. Por exemplo:

a+(b*c)-2-a está correto (a+b*(2-c)-2+a)*2 está correto

enquanto

(a*b-(2+c) está incorreto 2*(3-a)) está incorreto )3+b*(2-c)( está incorreto

Ou seja, todo parênteses que fecha deve ter um outro parênteses que abre correspondente e não pode haver parênteses que fecha sem um previo parenteses que abre e a quantidade total de parenteses que abre e fecha deve ser igual.

Para a solução desse exercício, utilize uma pilha estática de caracteres.

Input Format

Deve ser lido um valor inteiro N que representa a quantidade de casos de teste. Cada linha a seguir é uma expressões (1 <= N <= 10000), cada uma delas com até 1000 caracteres.

Constraints

As pilhas devem ser manipuladas apenas por funções. Por exemplo, o acesso a elementos deve ser feito apenas através da função desempilhar.

Output Format

O arquivo de saída deverá ter a quantidade de linhas correspondente ao arquivo de entrada, cada uma delas contendo as palavras correct ou incorrect de acordo com as regras acima fornecidas.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<string.h>
#define TAM_MAX 100

typedef struct PilhaC PilhaC;

struct PilhaC{
    char item[TAM_MAX];
    int topo;
};


PilhaC* criar_pilha(){
    PilhaC *p = (PilhaC*) malloc(sizeof(PilhaC));

    p->topo = -1;

    return p;
}


int pilha_cheia(PilhaC *p){

    if (p == NULL)
        return -1;
    else if (p->topo == (TAM_MAX - 1))
        return 1;
    else
        return 0;
}


int pilha_vazia(PilhaC *p){

    if (p == NULL)
        return -1;
    else if (p->topo == -1)
        return 1;
    else
        return 0;
}


int empilhar(PilhaC *p, char item){

    if (p == NULL)
        p = criar_pilha();


    if (!pilha_cheia(p)){
        p->topo++; // a pilha aumenta

        p->item[p->topo] = item;

        return 1;
    }

    return 0;
}
char desempilhar (PilhaC *p){
    char item= ' ';

    if (!pilha_vazia(p)){
        item = p->item[p->topo];

        p->topo--;
    }

    return item;
}

void imprimir_pilha(PilhaC *p){

    PilhaC aux = *p;
    char item;


    while (!pilha_vazia(&aux)){
        item = desempilhar(&aux);

        printf("%d\n", item);
    }
}

// Liberar a pilha
void liberar_pilha(PilhaC *p){
    if (p != NULL)
        free(p);
}

int obter_posicao_topo(PilhaC *p){
    if (!pilha_vazia(p))
        return p->topo;
    else
        return -1;
}
int parenteses (char str[]){
    PilhaC *p =criar_pilha();
    int i, res =1;

    for (i =0; (i< strlen(str))&& res; i++){
        if (str[i]== '(')
            empilhar(p, str[i]);
        else if (str[i]== ')'){
            if (!pilha_vazia(p))
                desempilhar (p);
            else
                res =0;
        }
    }

    if ((res == 1)&& !pilha_vazia(p))
        res=0;

    liberar_pilha(p);
    return res;
}

int main() {
    int n, i, res;
    char *str;

    scanf("%d", &n);
    for (i=0; i<n; i++){
        str= (char *)malloc(sizeof(char)*1000);

        scanf ("%s", str);

        res=parenteses(str);

        if (res==1)
            printf ("correct\n");
        else
            printf ("incorrect\n");

        free(str);
    }
    return 0;
}
