/*Implemente uma função que receba dois números inteiros, sendo uma para o tamanho do vetor (n) e a outra para razão (r). A função deverá retornar um vetor de tamanho n ordenado de forma crescente representado uma sequência de elementos de uma progressão aritmética iniciada por 0.

Para a implementação da solução, considere o protótipo de função abaixo:

int * prog_arit(int n, int r);
Input Format

Na primeira linha devem ser lidos dois números inteiros, sendo o primeiro referente ao tamanho do vetor e o segundo, à razão da progressão aritmética.

Constraints
.

Output Format

Vetor que represente uma sequência de elementos de uma progressão aritmética.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int * prog_arit(int n, int r){
    int *prog, i;

    prog =(int*)malloc(sizeof(int)*n);

    prog[0]=0;
    for (i=1; i<n; i++)
        prog[i]=prog[i-1]+r;

    return prog;
}
void imprimir (int *prog, int n){
    int i;

    for (i=0; i<n; i++)
        printf ("%d ", prog[i]);
}
int main() {
    int n, r, *prog;

    scanf ("%d %d", &n, &r);

    prog=prog_arit(n, r);

    imprimir(prog, n);


    return 0;
}

