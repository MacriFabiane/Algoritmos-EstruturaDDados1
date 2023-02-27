/*Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve conter a matrícula do aluno, nome, nota da primeira prova, nota da segunda prova e nota da terceira prova.

(a) Permita ao usuário entrar com os dados de n alunos. (b) Encontre o aluno com maior nota da primeira prova. (c) Encontre o aluno com maior média geral. (d) Encontre o aluno com menor média geral (e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando a média 6 para aprovação.

Input Format

A primeira linha é composta por um número n de alunos. Seguem a matricula (numérico até 65000), nome (string max 255 caracteres) e 3 notas (float com 1 casa de precisão)

Constraints

.

Output Format

A saída devera informar, para cada aluno se ele foi aprovado ou reprovado. Seguido das soluções para as questões (b), (c) e (d)*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct aluno{
    int RA;
    char nome[255];
    float notas[3];
}aluno;

float media(float vetor[], int n)
{
    int i;
    float soma =0.0;
    for (i=0; i< n; i++)
    {
        soma += vetor[i];
    }
    return soma/(n);
}
void resultado (aluno v[], int n)
{
    int i;

    for (i=0; i<n; i++){
        if (media(v[i].notas, 3)>= 6.0)
        {
            printf ("Aprovado!\n");
        }
        else
        {
            printf ("Reprovado!\n");
        }
    }

}
void maior (aluno v[], int n)
{
    int i;
    int p_maior =0;
    float aux, m = media(v[0].notas, 3);

    for (i=1; i<n; i++)
    {
        aux = media(v[i].notas, 3);

        if (aux>m){
            p_maior=i;
            m=aux;
        }
    }

    printf ("O aluno com maior media e: %d %s %.1f\n", v[p_maior].RA, v[p_maior].nome, m );
}

void menor (aluno v[], int n)
{
    int i;
    int p_menor =0;
    float aux, m = media(v[0].notas, 3);

    for (i=1; i<n; i++)
    {
        aux = media(v[i].notas, 3);

        if (aux< m){
            p_menor=i;
            m=aux;
        }
    }

    printf ("O aluno com menor media e: %d %s %.1f\n", v[p_menor].RA, v[p_menor].nome,m);
}

void maior_P1 (aluno v[], int n)
{
    int i;
    int p_maior= 0;
    float aux, m = v[0].notas[0];

    for (i= 1; i<n; i++)
    {
        aux = v[i].notas[0];

        if (aux>m){
            p_maior=i;
            m=aux;
        }
    }

    printf ("O aluno com maior P1 e: %d %s %.1f\n", v[p_maior].RA, v[p_maior].nome, m);
}

int main() {

    int i, n;

    scanf ("%d", &n);

    aluno v[n];

    for (i=0; i<n; i++){
        scanf("%d", &v[i].RA);
        scanf("%s", v[i].nome);
        scanf("%f %f %f", &v[i].notas[0], &v[i].notas[1], &v[i].notas[2]);

    }
        resultado(v, n);
        maior(v,n);
        menor(v,n);
        maior_P1(v,n);

    return 0;
}

