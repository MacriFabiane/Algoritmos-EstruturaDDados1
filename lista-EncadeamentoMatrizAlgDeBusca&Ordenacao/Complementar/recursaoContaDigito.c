/*Escreva uma função recursiva para determinar quantas vezes um determinado dígito X ocorre em um número N. Por exemplo, o dígito 3 ocorre 4 vezes em 3304353.

Input Format

Na primeira linha, devem ser lidos dois números inteiros: o primeiro deve ser o dígito a ser procurado e o segundo deve ser o número natural onde o dígito é procurado.

Constraints

.

Output Format

Imprimir a quantidade de vezes que o dígito procurado ocorre.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int conta_digito (int d, int n){
    if ((abs(n)>=0) &&(abs(n)<=9))
        return n ==d;
    else
        return ((n%10)==d)+conta_digito (d, n/10);
}
int main() {
    int d, n;
    scanf("%d %d", &d, &n);
    printf("%d", conta_digito(d, n));

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
