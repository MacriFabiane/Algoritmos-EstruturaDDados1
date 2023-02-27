/*Implemente uma função que receba um número inteiro. A função deverá calcular, utilizando recursão, a soma dos dígitos do número inteiro.

Exemplo:

-- Entrada: 375

-- Saída: 3 + 7 + 5 = 15

Input Format

Na primeira linha deve ser lido um número inteiro.

Constraints

.

Output Format

Imprimir o resultado da soma dos dígitos.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int soma_digitos(int n){
    if (n==0)
        return n;
    else
        return (n%10)+soma_digitos(n/10);
}

int main() {
    int n;
    scanf ("%d", &n);
    printf("%d", soma_digitos(n));

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

