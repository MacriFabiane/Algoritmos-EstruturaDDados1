/*Implemente um TAD para hashing estático aberto, onde as colisões devem ser resolvidas por meio de listas encadeadas ordenadas. A função hash deve ser resto de divisão, ou seja, h(k) = k % B, onde k é uma chave e B é o tamanho da tabela hash.

Input Format

Na primeira linha deve ser lido o tamanho da tabela hash. Na segunda linha deve ser lida a quantidade de chaves que serão alocadas. Por fim, devem ser lidas as chaves que serão alocadas na tabela hash.

Constraints
.

Output Format

Imprimir as posições onde as chaves foram colocadas na tabela. Em seguida, imprimir a tabela hash inteira. Para isso, deve ser considerado o seguinte formato: "linha_i: -> item_0 -> item_1 -> ... -> item_n"

Caso a i-ésima linha da matriz esparsa seja nula, basta imprimir "linha_i -> ".*/
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

void inicializarLista(ListaE *l){

    l->head = NULL;
}

void inserir_ordenado_Lista (ListaE *lista, int num){
    Cell *aux;
    Cell *novo = (Cell*) malloc(sizeof(Cell));

        novo->item = num;
        if(lista->head == NULL){ // se estiver vazia so adiciona
            novo->next = NULL;
            lista->head = novo;
        }
        else if(novo->item < lista->head->item){ // se for menor que a cabeca
            novo->next = lista->head;
            lista->head = novo;
        }
        else{
            aux = lista->head;
            while(aux->next && novo->item > aux->next->item) // se a nova celua for maior que o proximo da celula vai colocar no fim
                aux = aux->next;// repete ate achar uma celula com valor menor do q eu quero inserir

            novo->next = aux->next; //apos achar a celula menor faz a mudanca
            aux->next = novo;
        }

}

int buscar_na_lista(ListaE *l, int valor){
    Cell *aux = l->head;
    while(aux && aux->item != valor)
        aux = aux->next;
    if(aux)
        return aux->item;
    return 0;
}

void imprimir_lista(ListaE *l){
    Cell *aux = l->head;
    if (aux == NULL)
         printf (" -> ");
    while(aux){
        printf (" -> ");
        printf("%d", aux->item);
        aux = aux->next;
    }


}

void inicializarTabela(ListaE t[], int tam){ //a tabela hash vai ser um vetor de listas
    int i;

    for(i = 0; i < tam; i++)
        inicializarLista(&t[i]);
}

int funcaoHash(int chave, int tam){
    return chave % tam;
}

void inserir(ListaE t[], int chave, int tam){
    int  x;
    x= funcaoHash(chave, tam);
    inserir_ordenado_Lista(&t[x], chave);
}

int buscarNaTabela(ListaE t[], int chave, int tam){
    int x;
    x = funcaoHash(chave, tam);
    return buscar_na_lista(&t[x], chave);
}

void imprimirTabela(ListaE t[], int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("%d:", i);
        imprimir_lista(&t[i]);
        printf("\n");
    }
}
void imprimir_pos(int key, int tam){
    int x;
    x= funcaoHash(key, tam);
    printf("%d\n", x);
}

int main(){

    int tam, nchaves, chave, i;
    scanf("%d", &tam);
    scanf("%d", &nchaves);
    ListaE tabela[tam];

    inicializarTabela(tabela, tam);

        for (i=0; i<nchaves; i++){
            scanf("%d", &chave);
            inserir(tabela, chave, tam);
            imprimir_pos(chave, tam);
        }
    printf("\n");

    imprimirTabela(tabela, tam);


    return 0;
}

