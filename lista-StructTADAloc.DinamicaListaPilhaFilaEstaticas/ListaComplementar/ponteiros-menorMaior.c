//ponteiros-menor maior
/*Implemente uma função que receba duas variáveis fo tipo inteiro e coloque o maior valor na primeira variável e o menor valor na segunda variável. Escreva o conteúdo das 2 variáveis dentro da função main.

Use o seguinte protótipo de função:

void troca (int *A, int *B);
Input Format

A primeira linha da entrada contém um único inteiro N, indicando o número de casos de teste. Cada caso de teste contém um inteiro X (-100 ≤ X ≤ 100).

Constraints
.

Output Format

Para cada caso de teste de entrada deverá ser apresentada uma linha de saída, no seguinte formato: A=X B=Y*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void troca (int *A, int *B) //passagem por endereco, ponteiro
{
    int aux;
    if (*B>*A)
    {
        aux=*A;
        *A=*B;
        *B=aux;
    }
    printf ("A=%d B=%d\n", *A, *B);
}
int main() {

    int n, num1, num2, i;
    scanf ("%d", &n);

    for (i=0;i<n; i++)
    {
        scanf ("%d %d\n", &num1, &num2);
        troca(&num1, &num2);
    }


    return 0;
}

