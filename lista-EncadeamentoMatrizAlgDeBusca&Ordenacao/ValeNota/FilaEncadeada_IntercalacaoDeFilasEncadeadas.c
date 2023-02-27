/*Implemente uma função que receba duas filas encadeadas compostas por números naturais. A função deverá retornar uma fila encadeada resultante da interlação das duas filas de entrada. Em cada intercalação, o maior elemento deve ser enfileirado primeiro.

Exemplo:

Antes

f1 = {1, 5, 3}

f2 = {4, 2, 3, 4}

f3 = {}

Depois

f1 = {}

f2 = {}

f3 = {4, 1, 5, 2, 3, 3, 4}

Input Format

Na primeira linha, enquanto "-1" não for lido, ler números inteiros. Na segunda linha, a mesma restrição da primeira linha deve ser aplicada.

Constraints

O acesso aos elementos da fila deve ser através da função desenfileirar.

Output Format

Imprimir a fila intercalada.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Cell Cell;

typedef struct FilaE FilaE;

struct Cell{
    int item;
    Cell *next;
};



struct FilaE{
    Cell *inicio;
    Cell *fim;
};



Cell* criar_celula(int key){
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



void enfileirar(int key, FilaE* f){
    Cell *aux;


    if (f == NULL)
        f = criar_filaE();


    aux = criar_celula(key);


    if (f->inicio == NULL)
        f->inicio = f->fim = aux;
    else{

        f->fim->next = aux;
        f->fim = f->fim->next;
    }

}



int desenfileirar(FilaE* f){
    Cell *aux;
    int item = INT_MIN;

    if (!filaE_vazia(f)){

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
void interlacao(FilaE* f1, FilaE* f2, FilaE* f3){

    int a=0, b=0;

    if (f1==NULL){
        f3=f2;
    }
     if (f2==NULL){
        f3=f1;
    }

    else {
        while (!filaE_vazia(f1)||!filaE_vazia(f2))
        {
            if (!filaE_vazia(f1))
                a=desenfileirar(f1);

            if (!filaE_vazia(f2))
                b=desenfileirar(f2);

            if (b==-1)
                enfileirar(a,f3);//quer dizer que a fila F2 acabou mas ainda tem elementos na f1
            else if (a==-1)
                enfileirar(b, f3);

            else if (a > b){ //com f1->inicio e f2->inicio da errado no teste 1

                enfileirar(a, f3);
                enfileirar(b, f3);
            }
            else {

                enfileirar(b, f3);
                enfileirar(a, f3);
            }
            a=-1;
            b=-1;

    }

}
}

int main() {
    FilaE* f1=criar_filaE();
    FilaE* f2=criar_filaE();
    FilaE* f3=criar_filaE();
    int item, i;

    while(item!=-1){
        scanf("%d",&item);

        if(item!=-1)
            enfileirar(item, f1);
    }

     while(i!=-1){
        scanf("%d",&i);

        if(i!=-1)
            enfileirar(i, f2);
    }


    interlacao(f1,f2,f3);
    imprimir_fila(f3);

    liberar_filaE(f1);
    liberar_filaE(f2);
    liberar_filaE(f3);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

