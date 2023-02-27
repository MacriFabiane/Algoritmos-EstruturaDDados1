/*Implemente um dos algoritmos de ordenação avançados apresentados em sala de aula (quicksort, shellsort ou heaport)

Input Format

Na primeira linha deve ser lido o tamanho do vetor. Na segunda linha devem ser lidos os elementos do vetor.

Constraints

.

Output Format

Imprimir o vetor ordenado.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void quicksort(int v[], int esq, int dir){
    int i=esq, j=dir, pivo=v[(i+j)/2], aux;

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
        quicksort(v, esq, j);
    if(i<dir)
        quicksort(v, i, dir);
}

int main() {
    int i, n, *v;

    scanf("%d", &n);

    v=(int*)malloc(sizeof(int)*n);

    for(i=0; i<n; i++)
        scanf("%d", &v[i]);

    quicksort(v, 0, n-1);

    for(i=0; i<n; i++)
        printf("%d ", v[i]);

    free(v);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

