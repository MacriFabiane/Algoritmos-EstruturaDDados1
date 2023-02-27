/*Implemente o algoritmo heapsort para ordenar vetor de strings.

Input Format

Na primeira linha deve ser lido o tamanho do vetor. A partir da segunda linha, ler as strings do vetor.

Constraints

.

Output Format

Imprimir o vetor após a ordenação.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int comparar_char(char c1, char c2){
    if (c1 == c2) return 0;
    else if (c1 < c2) return -1;
    else return 1;
}


int comparar(char s1[], char s2[]){
    int i;

    for (i = 0; (s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'); i++);

    return comparar_char(s1[i], s2[i]);
}
static void refazer(char **v, int esq, int dir){
    int j = (esq + 1) * 2 - 1;

   char* x = v[esq];


    while (j <= dir){

        if ((j < dir) && (comparar(v[j],v[j + 1])<0))
            j++;

        if (comparar(x,v[j])>0)
            break;


        v[esq] = v[j];
        esq = j;
        j = (esq + 1) * 2 - 1;
    }

    v[esq] = x;
}

static void gerarHeap(char**v, int n){
    int esq = n / 2;


    while (esq >= 0){
        refazer(v, esq, n - 1);
        esq--;
    }
}



void heapsort(char** v, int n){
    char* x;
    int dir = n - 1;

    gerarHeap(v, n);


    while (dir > 0){
        x = v[0];
        v[0] = v[dir];
        v[dir] = x;
        dir--;

        refazer(v, 0, dir);
    }
}

int main() {
    int n, i;
    char**v;

    scanf("%d", &n);

    v= (char**)malloc(sizeof(char*)*n);//alocando vetor char ponteiro

    for(i=0; i<n; i++){
        v[i]=(char*)malloc(sizeof(char)*50);
        scanf("%s", v[i]);
    }

  heapsort(v, n);

    for(i=0; i<n; i++){
        printf("%s\n", v[i]);
        free(v[i]);
    }
    free(v);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

