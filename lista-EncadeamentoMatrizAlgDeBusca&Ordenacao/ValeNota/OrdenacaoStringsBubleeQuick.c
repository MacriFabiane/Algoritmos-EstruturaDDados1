/*Implemente uma combinação entre o quicksort e um método de ordenação simples para a ordenação de strings. A função deve, pelo menos, receber três parâmetros: vetor de strings (v[][] ou **v), tamanho do vetor (n) e um número inteiro representando tamanho mínimo (m). Nessa função, enquanto a partição for maior que m, o método de ordenação que deve ser aplicado é quicksort. Caso contrário, um método de ordenação simples (bubblesort, select sort ou insert sort) deve ser utilizado na partição.

Input Format

Na primeira linha deve ser lido o tamanho do vetor. Na segunda linha, deve ser lido um número inteiro que represente o tamanho mínimo de partição. A partir da terceiralinha devem ser lidos os elementos do vetor.

Constraints
.

Output Format

Imprimir o vetor ordenado.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int comparar_char(char c1, char c2){
    if (c1 == c2) return 0;
    else if (c1 < c2) return -1;
    else return 1;
}


int comparar(char s1[], char s2[]){
    int i;

    for (i = 0; (s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'); i++);

    return comparar_char(s1[i], s2[i]);
}


void troca(char **vstr, int p1, int p2){
    char *str;

    str = vstr[p1];
    vstr[p1] = vstr[p2];
    vstr[p2] = str;
}

void quicksort_booble_str(char **vstr, int n_cima, int n_baixo, int m, int n){
     int i = n_cima, j = n_baixo;
     char *pivo = vstr[(i + j) / 2];
     int t=1;

     if ((j+i)/2 > m){
         do{
             while ((comparar(vstr[i], pivo) < 0) && (i < j))
                 i++;

             while ((comparar(vstr[j], pivo) > 0) && (j > i))
                 j--;

             if (i <= j){
                 troca(vstr, i, j);
                 i++;
                 j--;
            }
         }while (i<=j);

         if (j > n_cima)
            quicksort_booble_str(vstr, n_cima, j, m, n);
         if (i < n_baixo)
             quicksort_booble_str(vstr, i, n_baixo, m, n);
     }
   else{

         for (i = 0; (i < n - 1) && t; i++){
           t = 0;

         for (j = 0; j < n - i - 1; j++)
             if (comparar(vstr[j], vstr[j + 1]) > 0){
                 troca(vstr, j, j + 1);
                 t = 1;
             }
         }
    }

 }


void imprimir_vet_str(char **vstr, int n){
    int i;

    for (i = 0; i < n; i++)
        printf("%s\n", vstr[i]);
}


int main() {
    int n, m, i;

    scanf("%d", & n);

    scanf("%d", & m);

    char **vstr= (char**)malloc(sizeof(char*)*n);

    for (i=0; i<n; i++){
        vstr[i] = malloc(sizeof(char) * 30);//alocar os vetores de char dentro do vetor de char
        scanf("%s", vstr[i]);
    }


    quicksort_booble_str(vstr, 0, n-1, m, n);

    imprimir_vet_str(vstr, n);

    for(i=0; i<n; i++)
        free(vstr[i]);


    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

