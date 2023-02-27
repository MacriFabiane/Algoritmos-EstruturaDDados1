/*Crie uma struct para representar um número racional, ou seja, nessa estrutura deve haver os seguintes campos: numerador e denominador.
Em seguida, crie uma função que receba dois números racionais. A função deverá retornar um outro número racional resultante da divisão dos números fornecidos como entrada.
A primeira linha é composta pelo numerador e denominador, respectivamente, do primeiro número racional.
A segunda linha é composta pelo numerador e denominador, respectivamente, do segundo número racional.
Constraints
As entradas lidas devem ser armazenadas em varíaveis do tipo de estrutura que você criou.
Output Format
Número racional resultante da divisão dos números fornecidos como entrada.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct racional{
    int numerador;
    int denominador;
    
}racional;

racional divisao (racional n1, racional n2)
{
    racional n3;
    
    n3.numerador= n1.numerador * n2.denominador;
    n3.denominador= n1.denominador * n2.numerador;

    return n3;
}
int main() {
    racional n1;
    racional n2;
    racional n;
    
    scanf("%d %d", &n1.numerador, &n1.denominador);
    scanf("%d %d", &n2.numerador, &n2.denominador);
    
    n=divisao(n1,n2);
    
    printf ("%d %d", n.numerador, n.denominador);
    
    return 0;
}
