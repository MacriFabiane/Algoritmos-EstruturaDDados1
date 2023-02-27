/*Implemente uma função que receba 3 listas estáticas (l1, l2, l3). A função deve concatenar l1 e l2, de forma que ambas sejam invertidas, em l3. Durante a concatenação, as listas l1 e l2 devem ser esvaziadas.

Exemplo:

Antes

l1 = {1, 2, 3}

l2 = {4, 5, 6, 7}

l3 = {}

Depois

l1 = {}

l2 = {}

l3 = {3, 2, 1, 7, 6, 5, 4}

Para isso utilize um TAD do tipo Lista, podendo ser o código que foi apresentado em aula (esse código pode ser copiado ):

#define MAX_SIZE 100

typedef struct ItemL ItemL;
typedef struct Lista Lista;

Lista* criar_lista();

int lista_vazia(Lista *l);

int lista_cheia(Lista *l);

int inserir(Lista *l, int chave);

int remover(Lista *l, int chave);

void imprimir_lista(Lista *l);

int liberar_lista(Lista *l);
Dica: implemente uma função para remover o último elemento. Essa função facilitará a implementação do exercício proposto.

Observação: não é necessário considerar o arquivo .h, já que no HackerRank não tem como "upar" arquivos .h e .c.

Input Format

Na primeira linha, enquanto "-1" não for lido, ler números inteiros. Na segunda linha, a mesma restrição da primeira linha deve ser aplicada.

Constraints
.

Output Format

Imprimir a lista concatenada.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_SIZE 100

typedef struct ItemL ItemL;
typedef struct Lista Lista;

struct Lista{
    int item[MAX_SIZE];
    int tam;
};

Lista* criar_lista(){
    Lista *l = (Lista*) malloc(sizeof(Lista));

    l->tam = 0;

    return l;
}

int lista_vazia(Lista *l){

    if (l==NULL)
     return -1;
    else if(l->tam >MAX_SIZE)
      return 0;
    else
      return 1;
}

int lista_cheia(Lista *l){
    if (l==NULL)
     return -1;
    else if(l->tam < MAX_SIZE)
      return 0;
    else
      return 1;
}
int buscar(Lista *l, int chave){
    int i;

    if (!lista_vazia(l)){

        for (i = 0; i <= l->tam; i++)
            if (l->item[i] == chave)
                return i;
    }

    return -1;
}

int inserir(Lista *l, int chave){
    if (l==NULL)
      l=criar_lista();

    if (!lista_cheia(l)){

        l->item[l->tam] = chave;

        l->tam++;

        return 1;
    }

    return 0;
}

void imprimir_lista(Lista *l){
    int i;

    if (l!=NULL){
        for (i = 0; i < l->tam; i++)
            printf("%d ", l->item[i]);

        printf("\n");
    }
}

int liberar_lista(Lista *l){
    if (l != NULL){
        free(l);

        return 1;
    }

    return 0;
}

Lista* concatenar (Lista *l1, Lista *l2, Lista *l3){

    int i;

    if(l1==NULL){
        for(i=l2->tam-1; i>=0; i--)
            inserir (l3, l2->item[i]);

        liberar_lista(l2);
    }

    else if (l2==NULL){
      for(i=l1->tam-1; i>=0; i--)
            inserir (l3, l1->item[i]);

         liberar_lista(l1);
    }

    else{

         for(i=(l1->tam-1); i>=0; i--){
            inserir (l3, (l1->item[i]));
         }
        liberar_lista(l1);

        for(i=l2->tam-1; i>=0; i--){
           inserir (l3, (l2->item[i]));
        }
        liberar_lista(l2);

    }
    return l3;
}

int main() {
    int item;
    Lista *l1, *l2, *l3;

    l1= criar_lista();

    do{
        scanf("%d", &item);

           if (item!=-1)
               inserir(l1, item);

    }while(item!=-1);

    l2 =criar_lista();

    do{
        scanf("%d", &item);

           if (item!=-1)
               inserir(l2, item);

    }while(item!=-1);
    l3= criar_lista();

    concatenar(l1, l2, l3);

    imprimir_lista(l3);

    free(l3);
    return 0;
}
