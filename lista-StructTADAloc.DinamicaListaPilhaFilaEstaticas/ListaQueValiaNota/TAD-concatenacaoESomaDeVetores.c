/*Crie um TAD para processamento de vetores com a seguinte estrutura e operações, onde v é o vetor e n é a quantidade de elementos contidos no vetor:

typedef struct{
    int *v; // Array (vetor) de tamanho n
    int n; // tamanho do v
    int q; // quantidade de elementos preenchidos no vetor
}Vetor;

Vetor * iniciar(int n);

int inserir(Vetor *v, int x); // inserir x na última posição. A função retorna 1 se a operação foi bem-sucedida

Vetor * concatenar(Vetor *v1, Vetor *v2);

Vetor * soma(Vetor *v1, Vetor *v2);
Observação: não é necessário considerar o arquivo .h, já que no HackerRank não tem como "upar" arquivos .h e .c.

Input Format

Deve ser lido um valor inteiro n que representa a quantidade de elementos de um v. Em seguida, devem ser lidos os n elementos do vetor. Repetir o processo para o segundo vetor.

Constraints
.

Output Format

Vetores na seguinte ordem: resultantes da concatenação resultantes da soma*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct{
    int *v; // Array (vetor) de tamanho n
    int n; // tamanho do v
    int q; // quantidade de elementos preenchidos no vetor
}Vetor;

Vetor * iniciar(int n){
    Vetor *v= (Vetor*)malloc (sizeof(Vetor));

    v->n=n;
    v->v =(int*)malloc(sizeof(int)*n);
    v->q =0;

    return v;
}

int inserir(Vetor *v, int x){// inserir x na ultima posicao. A funcao retorna 1 se a operacao foi bem-sucedida
     if ((v!=NULL) && (v->q < v->n)){ //precisa de espaco para inserir no final
        v->v[v->q]= x;
        v->q++;

        return 1;
    }
   return 0;

}

Vetor * concatenar(Vetor *v1, Vetor *v2){
    int i;
    Vetor *v3=NULL;

    if (v1==NULL)
        return v2;
    else if (v2==NULL) //pra caso algum deles for nulo, retornar o outro
        return v1;
    else{
        v3=iniciar(v1->q + v2->q) ;// para somar os espacos

        for (i=0; i<v1->q; i++)//se o v1 for o maior
            inserir(v3, v1->v[i]);

        for (i=0; i<v2->q;i++) //se o v2 for maior
            inserir(v3, v2->v[i]);

        return v3;
    }

}

Vetor *soma(Vetor *v1, Vetor *v2){
    int i;
    Vetor *s;

    if (v1==NULL)
        return v2;
    else if (v2==NULL)
        return v1;
    else{
        if(v1->q > v2->q)
            s=iniciar(v1->q);
        else
            s=iniciar(v2->q);

        for(i=0; i<v1->q && i<v2->q; i++){
            s->v[i]= v1->v[i] + v2->v[i];
            s->q++;
        }
        for (i=v2->q; i<v1->q; i++){
            s->v[i]=v1->v[i];
            s->q++;
        }

        for (i=v1->q; i<v2->q; i++){
            s->v[i]=v2->v[i];
            s->q++;
        }

        return(s);
}
}
void imprimir(Vetor *vx){
    int i;

    if (vx!=NULL){
        for (i=0; i<vx->q; i++)
         printf ("%d ", vx->v[i]);


     printf ("\n");

    }

}

int main() {
    int n1, n2, x;
    Vetor *v1, *v2, *v3, *s;
    int i;

    scanf ("%d", &n1);

    v1 = iniciar(n1);

    for (i=0; i<n1; i++){
        scanf ("%d", &x);
        inserir (v1, x);
    }

    scanf ("%d", &n2);

    v2 = iniciar(n2);

    for (i=0; i<n2; i++){
        scanf ("%d", &x);
        inserir (v2, x);
    }

    v3 = concatenar(v1, v2);
    s = soma(v1, v2);

    imprimir(v3);
    imprimir(s);

    free(v1);
    free(v2);
    free(v3);
    free(s);

    return 0;
}
