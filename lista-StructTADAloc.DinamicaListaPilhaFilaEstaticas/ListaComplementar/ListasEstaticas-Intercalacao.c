/*Dadas duas listas L1 e L2, sem elementos repetidos, impemente a operação INTER, que cria uma terceira lista L3 com a intercalação entre as duas listas, também sem elementos repetidos.

Utilize um TAD do tipo Lista (pode ser utilizado o que foi apresentado em aula) para todos os processos. Ou seja, toda alteração nos dados (inserção, remoção, etc..) deve ser realizada através de uma função. Alterações nos dados fora de funções serão desconsideradas na correção e descontado pontos.

Input Format

A primeira linha contém o número de casos de teste. Em seguida, cada duas linhas são referentes a um par de listas que serão intercaladas. Observação: "-1" não é inserido na lista, este número serve apenas para finalizar a leitura e inserção de elementos na lista.

Constraints

.

Output Format

A lista L3 intercalada sem elementos repetidos*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 100
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
    return (l == NULL) || (l->tam == 0);
}

int lista_cheia(Lista *l){
    return (l != NULL) && (l->tam == MAX_SIZE);
}


int buscar(Lista *l, int chave){
    int i;

    if (!lista_vazia(l)){
        for (i = 0; i < l->tam; i++)
            if (l->item[i] == chave)
                return i;
    }


    return -1;
}

int inserir(Lista *l, int chave){

    if (l == NULL)
        l = criar_lista();

    if (!lista_cheia(l)){

        l->item[l->tam] = chave;


        l->tam++;
        return 1;
    }


    return 0;
}

int remover(Lista *l, int chave){
    int i, p = buscar(l, chave);


    if (p > -1){
        for (i = p; i < l->tam - 1; i++)

            l->item[i] = l->item[i + 1];


        l->tam--;
        return 1;
    }

    return 0;
}


void imprimir_lista(Lista *l){
    int i;

    if (!lista_vazia(l)){
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

Lista *inter(Lista *l1, Lista*l2){
    Lista *l3=NULL;
    int i;

    if (l1==NULL)
        l3=l2;
    else if(l2==NULL)
        l3=l1;
    else{
        l3= criar_lista();

        for (i=0; (i<l1->tam)&&(i<l2->tam); i++){
            if (buscar(l3, l1->item[i])==-1)
               inserir(l3, l1->item[i]);

            if (buscar(l3, l2->item[i])==-1)
               inserir(l3, l2->item[i]);
        }

        for (i=l2->tam; i<l1->tam; i++){
            if (buscar(l3, l1->item[i])==-1)
               inserir(l3, l1->item[i]);
        }
        for (i=l1->tam; i<l2->tam; i++){
            if (buscar(l3, l2->item[i])==-1)
               inserir(l3, l2->item[i]);
    }

  }
      return l3;
}

int main() {
    int n, item, i;
    Lista *l1, *l2, *l3;

    scanf("%d", &n);


   for (i=0; i<n; i++){
       item =0;
       l1= criar_lista();
       l2 =criar_lista();

       while(item!=-1){
           scanf("%d", &item);

           if (item!=-1)
               inserir(l1, item);
       }
       item =0;
       while(item!=-1){
           scanf("%d", &item);

           if (item!=-1) //isere o -1 na lista
               inserir(l2, item);
       }
       l3= inter (l1, l2);

       imprimir_lista(l3);

       liberar_lista(l1);
       liberar_lista(l2);
       liberar_lista(l3);


   }


    return 0;
}
