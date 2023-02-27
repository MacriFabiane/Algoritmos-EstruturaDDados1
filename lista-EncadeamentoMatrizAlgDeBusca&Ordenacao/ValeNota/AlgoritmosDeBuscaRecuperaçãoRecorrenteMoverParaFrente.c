/*Implemente uma função que receba uma lista encadeada. Nessa função deverá ser implementado o método de recuperação recorrente mover-para-frente, no qual, cada vez que um registro é recuperado com sucesso, ele é movimentado para a primeira posição. Por exemplo, suponha que procuramos a chave 2 na seguinte: {7, 3, 4, 2, 6}. Após recuperar a chave 2, a mesma é posicionada na primeira posição: {2, 7, 3, 4, 6}.

Input Format

Na primeira linha, enquanto -1 não for lido, devem ser lidos os elementos da lista encadeada. Na segunda linha deve ser lida a quantidade de chaves que deverão ser procuradas). A partir da próxima linha, as chaves que serão procuradas devem ser lidas.

Constraints
.

Output Format

Após execução do algoritmo para cada caso teste, imprimir a lista encadeada.*/
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
int mover_para_frente(int x, ListaE *l){

    if (procurar(x,l)==1)
    {
        remover(x,l);
        inserir_primeiro(x,l);

        return 0;
    }

    return -1;
}

int main() {
    ListaE *l=criar_listaE();
    int item=0, quant=0, chave;
    int i=0;

    while (item!=-1)
    {
        scanf("%d", & item);
        if (item!=-1)
            inserir_ultimo(item, l);
    }

    scanf("%d", &quant);

    while( i!=quant)
    {
        scanf("%d", &chave);
        mover_para_frente(chave, l);
        i++;
        if(i==quant)
            break;
    }
    imprimir(l);
    liberar_LE(l);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
