/*
            Aula 261: Tabela Hash com lista encadeada

            Código escrito por Wagner Gaspar
            Setembro de 2021
*/

// 2 * 15 = 31
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define TAM 31
typedef struct Cell Cell;
typedef struct ListaE ListaE;

struct Cell{
    int item;
    Cell *next;
};

struct ListaE{
    Cell *head;
    int tam;
};

void inicializarLista(Lista *l){
    l->inicio = NULL;
    l->tam = 0;
}
/*
     Procedimento para inserir ordenado
*/
void inserir_ordenado_Lista (Lista *lista, int num){
    No *aux;
	No *novo = (No*) malloc(sizeof(No));

    if(novo){
        novo->chave = num;
        if(lista->inicio == NULL){ // se estiver vazia só adiciona
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else if(novo->chave < lista->inicio->chave){ // se for menor que a cabeça
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }
        else{
            aux = lista->inicio;
            while(aux->proximo && novo->chave > aux->proximo->chave) // se a nova célua for maior que o proxímo da célula vai colocar no fim
                aux = aux->proximo;// repete até achar uma célula com valor menor do q eu quero inserir
                
            novo->proximo = aux->proximo; //apos achar a célula menor faz a mudança
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void inserir_na_lista(Lista *l, int valor){
    No *novo = (No*) malloc(sizeof(No));

    if(novo){
        novo->chave = valor;
        novo->proximo = l->inicio;
        l->inicio = novo;
        l->tam++;
        
    }
    else
        printf("\n\tErro ao alocar memoria!\n");
}

int buscar_na_lista(Lista *l, int valor){
    No *aux = l->inicio;
    while(aux && aux->chave != valor)
        aux = aux->proximo;
    if(aux)
        return aux->chave;
    return 0;
}

void imprimir_lista(Lista *l){
    No *aux = l->inicio;
    printf(" Tam: %d: ", l->tam);
    while(aux){
        printf("%d ", aux->chave);
        aux = aux->proximo;
    }
}

void inicializarTabela(Lista t[]){
    int i;

    for(i = 0; i < TAM; i++)
        inicializarLista(&t[i]);
}

int funcaoHash(int chave){
    return chave % TAM;
}

void inserir(Lista t[], int valor){
    int id = funcaoHash(valor);
    inserir_ordenado_Lista(&t[id], valor);
}

int busca(Lista t[], int chave){
    int id = funcaoHash(chave);
    return buscar_na_lista(&t[id], chave);
}

void imprimir(Lista t[]){
    int i;
    for(i = 0; i < TAM; i++){
        printf("%2d = ", i);
        imprimir_lista(&t[i]);
        printf("\n");
    }
}

int main(){

    int opcao, valor, retorno;
    Lista tabela[TAM];

    inicializarTabela(tabela);

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 -Imprimir\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\tQual valor desseja inserir? ");
            scanf("%d", &valor);
            inserir(tabela, valor);
            break;
        case 2:
            printf("\tQual valor desseja buscar? ");
            scanf("%d", &valor);
            retorno = busca(tabela, valor);
            if(retorno != 0)
                printf("\tValor encontrado: %d\n", retorno);
            else
                printf("\tValor nao encontrado!\n");
            break;
        case 3:
            imprimir(tabela);
            break;
        default:
            printf("Opcao invalida!\n");
        }
    }while(opcao != 0);

    return 0;
}
