#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Cell Cell; 

typedef struct PilhaE PilhaE;  

struct Cell{
    int item; 
    Cell *next;
};

struct PilhaE{
    Cell *topo;
};

Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}



PilhaE* criar_pilhaE(){
    PilhaE* p = (PilhaE*) malloc(sizeof(PilhaE));

    p->topo = NULL;

    return p;
}



int pilhaE_vazia(PilhaE *p){
    return (p == NULL) || (p->topo == NULL);
}



void empilhar(int key, PilhaE *p){
    Cell *aux;


    if (p == NULL)
        p = criar_pilhaE();

   
    aux = criar_celula(key);

    aux->next = p->topo;
    p->topo = aux;
}

int desempilhar(PilhaE *p){
    Cell *aux; 
    int item = INT_MIN; 

    if (!pilhaE_vazia(p)){
    
        aux = p->topo;
        
        
        item = aux->item;

        p->topo = aux->next;

        free(aux);
    }

    return item;
}

void imprimir_pilha(PilhaE *p){
    Cell *aux; 

    if (!pilhaE_vazia(p)){
        aux = p->topo;

        while (aux != NULL){
            printf("%d\n", aux->item);

            aux = aux->next;
        }
    }
}

int liberar_pilha(PilhaE *p){
    if (p != NULL){
        while (!pilhaE_vazia(p))
            desempilhar(p);

        free(p);

        return 1;
    }

    return 0;
}
void binario (int num, Pilha *bin){
    int quociente=0;
    if (num<=0)
    {
      	empilhar(bin, 0);
    }
    while (num>=2){
        quociente=num/2;
        empilhar(bin, num%2);
        num=quociente;  
    }
     if(num<2){
           empilhar(bin, num);// quer dizer que chegou ao fim
       }  
}

int main() {
    int num;
    Pilha *bin=criar_pilha();
    
    scanf("%d", &num);
    binario(num, bin);
    imprimir_pilha(bin);
    
    liberar_pilha(bin);
    
    return 0;
}
