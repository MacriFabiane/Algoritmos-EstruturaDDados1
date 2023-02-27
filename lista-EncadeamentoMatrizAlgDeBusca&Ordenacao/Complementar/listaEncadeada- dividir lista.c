/*Implemente uma função que receba duas listas encadeadas, sendo uma com itens (l1) e a outra vazia (l2). A função deverá transferir a metade do conteúdo de l1 para l2.

Input Format

Enquanto -1 não for lido, ler números inteiros.

Constraints

.

Output Format

Imprimir o conteúdo das duas listas.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell Cell;
typedef struct ListaE ListaE;


struct Cell{
    int item;
    Cell *next;
};


struct ListaE{
    Cell *head;
};


Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}

ListaE* criar_listaE(){
    ListaE* l = (ListaE*) malloc(sizeof(ListaE));

    l->head = NULL;

    return l;
}



int listaE_vazia(ListaE *l){
    return (l == NULL) || (l->head == NULL);
}



int procurar(int key, ListaE *l){
    Cell *aux;

    if (l != NULL){
        aux = l->head;

        while (aux != NULL){
            if (aux->item == key)
                return 1;

            aux = aux->next;
        }
    }

    return 0;
}


void inserir_primeiro(int key, ListaE *l){
    Cell *aux;
    if (l == NULL)
        l = criar_listaE();


    aux = criar_celula(key);


    aux->next = l->head;
    l->head = aux;
}



void inserir_ultimo(int key, ListaE *l){
    Cell *aux, *novo;


    if (l == NULL)
        l = criar_listaE();


    if (listaE_vazia(l))
        inserir_primeiro(key, l);
    else{
        aux = l->head;


        while(aux->next != NULL)
            aux = aux->next;


        novo = criar_celula(key);


        aux->next = novo;
    }
}


int remover(int key, ListaE *l){
    Cell *auxA, *auxP = NULL;

    if (!listaE_vazia(l)){
        auxA = l->head;
        if(auxA->item == key){

            l->head = l->head->next;
        }else{

            auxP = auxA;


            while((auxA != NULL) && (auxA->item != key)){
                //if (auxP != NULL)
                    auxP = auxA;

                auxA = auxA->next;
            }
        }

        if (auxA != NULL){

            if (auxP != NULL)
                auxP->next = auxA->next;
            free(auxA);

            return 1;
        }

    }

    return 0;
}


void imprimir(ListaE *l){
    Cell *aux;


    if (!listaE_vazia(l)){
        aux = l->head;

        while (aux != NULL){
            printf("%d ", aux->item);

            aux = aux->next;
        }

        printf("\n");
    }
}


int liberar_LE(ListaE *l){
    Cell *aux = NULL;

    if (l != NULL){
        while(l->head != NULL){
            aux = l->head;

            l->head = aux->next;

            free(aux);
        }

        free(l);

        return 1;
    }

    return 0;
}

int tamanho_LE(ListaE *l){
    Cell *aux;
    int tam = 0;

     if (!listaE_vazia(l)){
        aux = l->head;

        while(aux != NULL){
            aux = aux->next;

            tam++;
        }
    }

    return tam;
}
void dividir (ListaE *l1, ListaE *l2){
    int t;
    Cell *aux;

    if (!listaE_vazia(l1)){
        if (l2==NULL)
            l2=criar_listaE();

        t = (tamanho_LE(l1))/2;

        aux = l1->head;

        while (t>1){
            t--;
            aux= aux->next;
        }
        l2->head = aux->next;
        aux->next = NULL;
    }
}

int main() {
    ListaE *l1= criar_listaE();
    ListaE *l2 =criar_listaE();
    int item =0;

    while (item !=-1){
        scanf("%d", & item);

        if (item!=-1)
            inserir_ultimo(item, l1);
    }
    dividir(l1, l2);

    imprimir(l1);
    imprimir(l2);

    return 0;
}

