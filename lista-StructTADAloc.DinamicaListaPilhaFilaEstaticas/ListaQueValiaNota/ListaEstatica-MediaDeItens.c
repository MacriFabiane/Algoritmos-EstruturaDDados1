/*Implemente uma função que receba uma lista estática de floats. A função deverá retornar a média dos elementos da lista.

Input Format

Enquanto -1 não for lido, ler números inteiros e colocá-los na lista encadeada.

Constraints
.

Output Format

Imprimir o resultado da média dos elementos.*/
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define TAM_MAX 100

typedef struct Lista Lista;

struct Lista{
    float item[TAM_MAX];
    int tam;
};

Lista * criar_lista() {
    Lista *l= (Lista*)malloc(sizeof(Lista));
    l->tam=0;

    return l;
}

int lista_vazia(Lista *l){
    if (l==NULL)
        return -1;
    else if (l->tam >0)
        return 0;
    else
        return 1;
}
int lista_cheia(Lista*l){
        if (l==NULL)
        return -1;
    else if (l->tam <TAM_MAX)
        return 0;
    else
        return 1;
}

float iserir(Lista *l, float chave){
    if (l==NULL)
      criar_lista(l);

    else if (!lista_cheia(l)){
        l->item[l->tam]=chave;
        l->tam++;

        return 1;
    }

    return 0;
}

int liberar_lista (Lista *l){
    if (l!=NULL){
        free(l);

        return 1;
    }
    return 0;
}
float media(Lista *l){
    int i, soma=0.0, media=0.0;

    for(i=0; i<l->tam;i++)
        soma=soma +l->item[i];

    media=soma/(l->tam);

    return media;
}
int main (){
    Lista *l=criar_lista();
    float i, m;


    while(i!=-1){
    	scanf("%f", &i);

    	if (i==-1)
        	break;

        else{
	        iserir(l, i);
        }

    }
    m=media(l);
    printf("%.1f", m);

    liberar_lista(l);

    return 0;
}
