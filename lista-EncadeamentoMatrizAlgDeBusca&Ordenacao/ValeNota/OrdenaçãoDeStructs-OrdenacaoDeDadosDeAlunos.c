/*Adapte um dos algorimos de ordenação para o vetor de elementos da seguinte estrutura:

typedef struct{
    int matricula;
    char* nome;
    char* curso;
    float coef;
}Aluno;
A ordenação deve ser por nome. Caso haja registros com o mesmo nome, o critério de ordenação nesse caso é a matrícula.

Input Format

Na primeira linha deve ser lido o tamanho do vetor. A partir da segunda linha, ler os dados de cada elemento do vetor.

Constraints
.

Output Format

Imprimir os registro ordenados. Diferentemente da forma leitura, cada registro deve ser impresso em uma linha.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct lista lista;

typedef struct{
    int matricula;
    char* nome;
    char* curso;
    float coef;
}Aluno;



void bubble_struct  (Aluno * v, int tam){
    int i, j;
    Aluno aux;

    for(i = tam - 1; i > 0; i--){
        for(j = 0; j < i; j++){
       if(strcmp(v[j].nome, v[j+1].nome)>0){
           aux=v[j];
           v[j]=v[j+1];
           v[j+1]=aux;
       }
       else if (strcmp(v[j].nome, v[j+1].nome)==0){
           if(v[j].matricula>v[j+1].matricula){
               aux=v[j];
               v[j]=v[j+1];
               v[j+1]=aux;
           }
       }
    }
    }
}

int main() {
    int tam, i;

    scanf ("%d", &tam);

    Aluno *v = malloc(sizeof(Aluno)* tam);
    for(i = 0; i <tam; i++){
        v[i].nome = (char*)malloc(sizeof(char*) * 100);
        v[i].curso = (char*)malloc(sizeof(char*) * 100);
    }
    for (i=0; i<tam; i++){
        scanf("%d", &v[i].matricula);
        scanf("%s", &v[i].nome[0]);
        scanf("%s", &v[i].curso[0]);
        scanf("%f", &v[i].coef);

    }


    bubble_struct (v,tam);

     for (i=0; i<tam; i++){
         printf("%s %d %s %.2f",v[i].nome, v[i].matricula, v[i].curso, v[i].coef);
         printf ("\n");

     }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

