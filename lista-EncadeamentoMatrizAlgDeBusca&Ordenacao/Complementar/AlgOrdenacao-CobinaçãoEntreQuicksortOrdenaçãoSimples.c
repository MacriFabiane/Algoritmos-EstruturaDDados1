/*Implemente uma combinação entre o quicksort e um método de ordenação simples. A função deve, pelo menos, receber três parâmetros: vetor de inteiros (v[] ou *v), tamanho do vetor (n) e um número inteiro representando tamanho mínimo (m). Nessa função, enquanto a partição for maior que m, o método de ordenação que deve ser aplicado é quicksort. Caso contrário, um método de ordenação simples (bubblesort, select sort ou insert sort) deve ser utilizado na partição.

Input Format

Na primeira linha deve ser lido o tamanho do vetor. Na segunda linha devem ser lidos os elementos do vetor. Na terceira linha deve ser lido um número inteiro que represente o tamanho mínimo de partição.

Constraints

.

Output Format

Imprimir o vetor ordenado.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void quick_bublle_sort(int v[], int esq, int dir, int m){
    int i=esq, j=dir, pivo=v[(i+j)/2], aux, troca;

    if(dir-esq> m){
        do{
            while(v[i]<pivo)
                i++;
            while(v[j]>pivo)
                j--;

            if (i<=j){
                aux =v[i];
                v[i]=v[j];
                v[j]=aux;
                i++;
                j--;
            }

        }while(i<=j);

        if(j> esq)
            quick_bublle_sort(v, esq, j, m);
        if(i<dir)
            quick_bublle_sort(v, i, dir, m);
    }else{
        troca=1;
        for(i=esq; (i<dir) && troca; i++){
            troca =0;

            for(j=esq; j<=dir-i-1; j++)
                if (v[j]>v[j+1]){
                    troca =1;
                    aux=v[j];
                    v[j]=v[j+1];
                    v[j+1]=aux;
                }
        }

    }
}

int main() {
    int i, n, *v, m;

    scanf("%d", &n);

    v=(int*)malloc(sizeof(int)*n);

    for(i=0; i<n; i++)
        scanf("%d", &v[i]);

    scanf("%d", &m);

    quick_bublle_sort(v, 0, n-1, m);

    for(i=0; i<n; i++)
        printf("%d ", v[i]);

    free(v);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
