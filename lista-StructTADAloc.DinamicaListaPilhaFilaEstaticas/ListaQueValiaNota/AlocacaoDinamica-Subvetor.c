/*Implemente uma função que receba um vetor de números inteiros e três variáveis escalares do tipo int: tamanho do vetor; posição inicial no vetor; e posição final no vetor. A função deverá retornar um subvetor com os elementos, entre as posições inicial e a final, do vetor de entrada.

Input Format

Na primeira linha deve ser lido o tamanho do vetor. Na segunda linha, devem ser lidos todos os elementos do vetor. Na terceira linha, devem ser lidas as posições inicial e final, respectivamente.

Constraints
.

Output Format

Caso o subvetor existir (de acordo as posições inicial e final), todos os elementos do subvetor devem ser impressos. Caso contrário, a seguinte mensagem deve ser impressa: subvetor inexistente*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int* subvetor(int *v, int n, int ini, int fim){
    int i;
    int *sv =NULL;

    if((v!=NULL)&&(ini >= 0)&&(fim<n )&& (ini<=fim)){
        sv = (int*) malloc(sizeof(int)*(fim-ini+1)); //calcula o tamanho do sub vetor

        for (i=ini; i<=fim; i++)
            sv[i-ini]= v[i];//subvetor pegando do vetor
    }


    return sv;
}
int main() {
    int n, i, ini, fim;
    int *v, *sv;

    scanf("%d", &n);

    v= (int*) malloc(sizeof(int)* n);

    for (i=0; i<n; i++)
        scanf ("%d", &v[i]);

    scanf("%d %d", &ini, &fim);

    sv = subvetor(v,  n,  ini,  fim);

    for (i=0; i<fim-ini+1; i++)
        printf("%d ", sv[i]);

    free(v);
    free(sv);

    return 0;
}
