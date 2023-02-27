/*Implemente um dos algoritmos de ordenação avançados apresentados em sala de aula (quicksort, shellsort ou heaport) para a ordenação de floats.

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
void quicksort(float x[], int esq, int dir){
    int i = esq, j = dir;
	float pivo = x[(i + j) / 2], aux;

    do{
        while (x[i] < pivo)
            i++;

        while (x[j] > pivo)
            j--;

        if (i <= j){
            aux = x[i];
            x[i] = x[j];
            x[j] = aux;
            i++;
            j--;
        }
    }while (i <= j);

    if (j > esq)
        quicksort(x, esq, j);
    if (i < dir)
        quicksort(x, i, dir);
}

int main() {
    int n, i;
    float *v;

    scanf("%d", &n);

    v=(float*)malloc(sizeof(float)*n);

    for(i=0; i<n; i++)
    {
        scanf("%f", &v[i]);
    }

    quicksort(v, 0, n-1);

    for(i=0; i<n; i++){

        printf("%.1f ", v[i]);
    }

    free(v);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

