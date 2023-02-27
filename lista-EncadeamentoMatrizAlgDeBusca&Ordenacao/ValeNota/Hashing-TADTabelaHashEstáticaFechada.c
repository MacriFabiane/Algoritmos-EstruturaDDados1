/*Implemente um TAD para hashing estático fechado utilizando as seguintes abordagens vistas para a sala de aula: -> função hash: método da multiplicação -> rehash: segunda função hash --> h1(k) = método da multiplicação --> h2(k) = 1 + k % (B - 1) --> rh(k, i) = (h1(k) + i * h2(k)) % B

Input Format

Na primeira linha devem ser lidos a constante c considerada na alocação de chaves (tipo float), sendo que 0 < c < 1 e o tamanho n da tabela hash (tipo int). Na segunda linha deve ser lida a quantidade de chaves que serão alocadas. Por fim, devem ser lidas as chaves que serão alocadas na tabela hash.

Constraints
.

Output Format

Imprimir a posição onde cada chave foi alocada.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct{
    unsigned int tam;
    int *buckets;
}HashT;

HashT *criar(unsigned int tam){
    HashT *t = malloc(sizeof(HashT));
    int i;

    t->tam = tam;
    t->buckets = malloc((tam) * sizeof(int));

    for (i = 0; i < tam; i++)
        t->buckets[i] = -1;

    return t;
}
static int h1_mult(int chave, int tam, float c){
    int parteint, intTamfrac;
    float partedec, chaveVc, tamfrac;
    chaveVc=chave*c;

    parteint=(int)chaveVc;
    partedec= chaveVc-parteint;

    tamfrac=(tam)*partedec;

    intTamfrac= (int)tamfrac;

    return intTamfrac;

}
static int h2(int chave, int tam){
    return (1 + chave % (tam - 1));
}

int rehash (int h1, int chave, int tam, int i){
    return ((h1 + i * h2(chave, tam)) % tam);

}

int buscar(int key, HashT *t, int tam, float c){
    int x = h1_mult(key, t->tam, c);
    int i, rh;

    if (t->buckets[x] == key)
        return x;

    else if (t->buckets[x] >= 0){
        i = 1;
        rh = x;

        while ((i < t->tam) && (t->buckets[rh] != key) && (t->buckets[rh] >= 0)){
            rh = rehash(x, key, t->tam, i);

            i++;
        }


        if ((i < t->tam) && (t->buckets[rh] == key)){
            return rh;
        }

    }
        return (-1);
}


int inserir(int key, HashT *t, float c){
    int x;
    int i, rh;

    if ((t != NULL) && (key > 0)){
        x = h1_mult(key, t->tam, c);

        if (t->buckets[x] <= 0){
            t->buckets[x] = key;

            return 1;
        }else{
            i = 1;
            rh = x;


            while ((i < t->tam) && (t->buckets[rh] != key) && (t->buckets[rh] > 0)){
                rh = rehash(x, key, t->tam, i);

                i++;
            }


            if ((i < t->tam) && (t->buckets[rh] <= 0)){
                t->buckets[rh] = key;

                return 1;
            }
        }
    }

    return 0;
}
int remover(int key, HashT *t, int tam, float c){
    int x;

    if (t != NULL){
        x = buscar(key, t, tam, c);

        if (x >= 0){
            t->buckets[x] = 0;

            return 1;
        }
    }

    return 0;
}


void imprimir(HashT *t, int key, float c){
    int i;
    if (t != NULL){

        printf("%d\n", buscar( key, t, t->tam, c));
        }
    }


int liberar(HashT *t){
    if (t != NULL){
        free(t->buckets);

        free(t);

        return 1;
    }

    return 0;
}
int main() {
    int tam, i, key, nchaves;
    float c;

    scanf("%f %d", &c, &tam);
    scanf("%d", &nchaves);
    HashT *tabela=criar(tam);

    for(i=0; i<tam; i++)
    {
        scanf("%d", &key);
        inserir(key,tabela, c);
        if(i<nchaves){
            imprimir(tabela, key, c);
        }

    }

    liberar(tabela);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
