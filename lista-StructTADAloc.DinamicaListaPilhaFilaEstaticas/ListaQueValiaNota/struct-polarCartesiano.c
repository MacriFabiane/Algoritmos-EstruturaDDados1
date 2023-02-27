/*Faça uma função que converta coordenadas polares para cartesianas. O programa principal deve apenas ler e imprimir,
a conversão deve ser realizada por uma função sabendo que x = r*cos(a) e y = r*sin(a).

Input Format

A entrada contem um ponto em coordenada polar, composto por raio (r) e argumento (a) em radianos.

Constraints

.

Output Format

Imprima o ponto lido em coordenada cartesiana, composto por x e y.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    float x;
    float y;
    float r;
    float a;
}ponto;

ponto coordenadas (ponto k){
    ponto j;
    j.x=k.r*cos(k.a);
    j.y=k.r*sin(k.a);

    return j;
}

int main() {

    ponto b;
    scanf ("%f %f", &b.r, &b.a);
    printf ("%.1f\n", coordenadas(b).x);
    printf ("%.1f", coordenadas(b).y);

    return 0;
}

