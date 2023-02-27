/*Implemente uma função que receba uma fila encadeada. A função deverá inverter a fila. Para isso, pode ser utilizada uma estrutura auxiliar (e.g. pilha).

Input Format

Enquanto "-1" não for lido, ler números inteiros.

Constraints

O acesso aos elementos da fila deve ser através da função desenfileirar.

Output Format

Imprimir a fila invertida.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Cell Cell;
typedef struct FilaE FilaE;
typedef struct PilhaE PilhaE;

struct Cell{
    int item;
    Cell *next;
};



struct PilhaE{
    Cell *topo;
};

struct FilaE{
    Cell *inicio;
    Cell *fim;
};
Cell* criar_celula(int  key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}
FilaE* criar_filaE(){
    FilaE *f = (FilaE*) malloc(sizeof(FilaE));

    f->inicio = NULL;
    f->fim = NULL;

    return f;
}



int filaE_vazia(FilaE* f){
    return (f == NULL) || (f->inicio == NULL);
}


// Enfileirar um item
void enfileirar(int key, FilaE* f){
    Cell *aux;


    if (f == NULL)
        f = criar_filaE();


    aux = criar_celula(key);


    if (f->inicio == NULL)
        f->inicio = f->fim = aux;
    else{

        // o final da estrutura
        f->fim->next = aux;
        f->fim = f->fim->next;
    }

}


// Desenfileirar um item da fila
int desenfileirar(FilaE* f){
    Cell *aux; // Primeiro elemento da fila
    int item = INT_MIN;

    if (!filaE_vazia(f)){
        // obter o primeiro elemento da fila
        aux = f->inicio;

        f->inicio = aux->next;


        item = aux->item;


        free(aux);
    }

    return item;
}



void imprimir_fila(FilaE* f){
    Cell *aux;

    if (!filaE_vazia(f)){
        aux = f->inicio;

        while (aux != NULL){
            printf("%d ", aux->item);
            aux = aux->next;
        }
    }
}



int liberar_filaE(FilaE* f){
    if (!filaE_vazia(f)){
        while (f->inicio != NULL)
            desenfileirar(f);

        free(f);

        return 1;
    }

    return 0;
}




PilhaE* criar_pilhaE(){
    PilhaE* p = (PilhaE*) malloc(sizeof(PilhaE));

    p->topo = NULL;

    return p;
}

int pilhaE_vazia(PilhaE *p){
    return (p == NULL) || (p->topo == NULL);
}



void empilhar(int  key, PilhaE *p){
    Cell *aux;


    if (p == NULL)
        p = criar_pilhaE();


    aux = criar_celula(key);

    aux->next = p->topo;

    // Atualizar topo da pilha
    p->topo = aux;
}



int  desempilhar(PilhaE *p){
    Cell *aux;
    int item = ' ';

    if (!pilhaE_vazia(p)){

        aux = p->topo;


        item = aux->item;


        p->topo = aux->next;


        free(aux);
    }

    return item;
}

int liberar_pilha(PilhaE *p){
    if (p != NULL){
        while (!pilhaE_vazia(p))
            desempilhar(p);

        free(p);

        return 1;
    }

    return 0;
}

void inverter(FilaE*f){
    PilhaE *p;

    if (f!=NULL){
        p = criar_pilhaE();

        while (!filaE_vazia(f))
            empilhar(desenfileirar(f), p);

        while (!pilhaE_vazia(p))
            enfileirar(desempilhar(p), f);

        liberar_pilha(p);
    }
}

int main() {
    int item;
    FilaE *f =criar_filaE();

    while (item !=-1){
        scanf("%d", &item);
        if (item !=-1)
            enfileirar(item, f);
    }
    inverter(f);

    imprimir_fila(f);

    liberar_filaE(f);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

