/*Implemente uma função que verifica se a matriz esparsa é diagonal.

"Matriz diagonal é uma matriz quadrada onde os elementos que não pertencem à diagonal principal são obrigatoriamente iguais a zero." Fonte:

Input Format

Na primeira linha deve ser lido um número inteiro, que representará os números de linhas e de colunas (matriz quadrada). Em seguida, uma matriz deve ser lida. Por último, a matriz bidimensional deve ser convertida para uma matriz esparsa.

Constraints
.

Output Format

Deve ser impresso "diagonal" se a matriz for diagonal ou "nao diagonal", caso contrário.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct Cell Cell;

typedef struct ListaE ListaE;

typedef struct Spa_Mat Spa_Mat;

struct Cell{
        int item;
        int col;
        Cell *next;
};


struct ListaE{
        Cell *head;
};


struct Spa_Mat{
       int n_lin;
       int n_col;
       ListaE **lin;
};


Spa_Mat* criar(int l, int c){
        Spa_Mat* mat = (Spa_Mat*) malloc(sizeof(Spa_Mat));
        int i;

        mat->n_col = c;
        mat->n_lin = l;
        mat->lin = (ListaE**) malloc(sizeof(ListaE*) * l);

        for (i = 0; i < l; i++){
                mat->lin[i] = (ListaE*) malloc(sizeof(ListaE));
                mat->lin[i]->head = NULL;
        }

        return mat;
}


Cell* criar_celula(int item, int col){
    Cell *nova = (Cell*) malloc(sizeof(Cell));
    nova->item = item;
    nova->col = col;
    nova->next = NULL;

    return nova;
}


static int procurar_lista(int item, ListaE *l){
        Cell *aux = 0;

        if (l != NULL){
                aux = l->head;

                while ((aux != NULL) && (aux->item != item))
                    aux = aux->next;
        }

        if ((aux != NULL) && (aux->item == item))
                return 1;
        else
                return 0;
}


int buscar(int item, Spa_Mat* mat){
        int i;
        int aux = 0;

        for (i = 0; (i < mat->n_lin) && (aux == 0); i++)
                aux = procurar_lista(item, mat->lin[i]);

        return aux;
}


static int validar_pos_matriz(int lin, int col, Spa_Mat* mat){
    return (mat != NULL) && (lin >= 0) && (lin < mat->n_lin) && (col >= 0) && (col < mat->n_col);
}


int buscar_pos(int l, int c, Spa_Mat* mat){

    Cell *aux;
    int valor = 0;

    if ((mat != NULL) && validar_pos_matriz(l, c, mat)){
        aux = mat->lin[l]->head;

        while ((aux != NULL) && (c < aux->col))
            aux = aux->next;

        if ((aux != NULL) && (c == aux->col))
            valor = aux->item;
    }

    return valor;
}

static void trocar_inserir_na_lista(int item, int col, ListaE *l){
    Cell *auxA, *auxP, *novo;

    if ((l->head == NULL) || (col < l->head->col)){
        novo = criar_celula(item, col);
        novo->next = l->head;
        l->head = novo;

    }else if (col == l->head->col){
        l->head->item = item;
    }else{
        auxA = l->head;
        auxP = auxA;


        while ((auxP != NULL) && (auxP->col < col)){
            auxA = auxP;
            auxP = auxP->next;
        }


        if ((auxP != NULL) && (col == auxP->col))
            auxP->item = item;

        else{
            novo = criar_celula(item, col);
            novo->next = auxA->next;
            auxA->next = novo;
        }
    }
}

static void remover_na_lista(int col, ListaE *l){
    Cell *auxA, *auxP = NULL;

    if (l->head != NULL){

        if (col == l->head->col){
            auxP = l->head;
            l->head = l->head->next;
            free(auxP);
        }else{
            auxA = l->head;
            auxP = auxA;

            while ((auxP != NULL) && (auxP->col < col)){
                auxA = auxP;
                auxP = auxP->next;
            }

            if ((auxP != NULL) && (col == auxP->col)){
                auxA->next = auxP->next;

                free(auxP);
            }
        }
    }
}


void trocar(int item, int l, int c, Spa_Mat* mat){
    if (validar_pos_matriz(l, c, mat)){
        if (item > 0)
            trocar_inserir_na_lista(item, c, mat->lin[l]);
        else
            remover_na_lista(c, mat->lin[l]);
    }
}

void diagonal (Spa_Mat *mat, int c, int l){
    int i =0;
    int  contsup=0;
    Cell* aux;

    for (i=0;i<l;i++){
        aux=mat->lin[i]->head;
            if (aux!=NULL)
            {
                if(i==aux->col){
                    if((mat->lin[i]!=NULL) && (mat->lin[i]->head->col==i) && mat->lin[i]->head->next==NULL){
                            contsup++;
                        }

                    }

             }
            else if (aux==NULL){
                        contsup++;
                    }

            }


if (contsup == l){
    printf ("diagonal");
}
else
    printf ("nao diagonal");

}
void imprimir(Spa_Mat* mat){
    int i, j;
    Cell* aux;

    for(i = 0; i < mat->n_lin; i++){
        aux = mat->lin[i]->head;
        j = 0;

        while (aux != NULL){
            while (j < aux->col){
                printf("0 ");
                j++;
            }

            printf("%d ", aux->item);
            j++;
            aux = aux->next;
        }

        for(j=j; j < mat->n_col; j++)
            printf("0 ");

        printf("\n");
    }
}

 Spa_Mat * converter (int lc, int** mat_bi){
     int i, j;
     Spa_Mat *matrix = criar(lc, lc);
     for (i=0; i<lc; i++){
         for(j=lc-1; j>=0; j--){
             trocar(mat_bi[i][j],i, j,matrix);

        }
     }
     return matrix;

 }
int main() {
    int lc, i, j;
    Spa_Mat *matrix;

    scanf("%d", &lc);

    int **mat_bi = (int**) malloc(sizeof(int*) * lc);;
    for (i=0; i<lc; i++){
        mat_bi[i] = (int*)malloc(sizeof(int)*lc);
        for(j=0; j<lc; j++){
            scanf("%d", & mat_bi[i][j]);
        }
    }

    matrix =converter(lc, mat_bi);

    diagonal(matrix, lc, lc);


    return 0;
}
