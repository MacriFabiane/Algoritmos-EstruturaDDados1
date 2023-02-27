/*O Sr. Pupunha, um grande investidor, comprou um terreno e decidiu fazê-lo um estacionamento, o qual tem capacidade para 10 carros. Ao estacionar o automóvel,
o cliente recebe um ticket representando por um número inteiro. No entanto, o terreno é muito estreito e, consequentemente, os carros devem ser colocados em
fila. Nesse terreno, a entrada é pelos fundos e a saída é pela frente. Caso um cliente precisar sair com o seu carro, os outros automóveis deverão ser retirados
e estacionados novamente. Por exemplo, considere a seguinte fila de carros: {1, 2, 3, 4, 5, 6, 7, 8}, onde o primeiro elemento é o veículo que está mais
próximo à saída e o último é mais próximo da entrada. Caso o carro 4 for retirado, os veículos 1, 2 e 3 devem estacionados novamente pela entrada do
estacionamento. Desse modo, após a remoção do veículo 4, o estacionamento ficaria na seguinte forma: {5, 6, 7, 8, 1, 2, 3}.

Implemente uma função que receba uma fila estática (representação do estacionamento) e um número inteiro (ticket ou id do carro) como parâmetros e faça o
gerenciamento de veículos no estacionamento do Pupunha. Enquanto o ticket não for encontrado, o primeiro elemento da fila deverá ser removido e recolocado no
final da da fila. Também, deve ser tratado o caso em que o elemento não é encontrado na fila. A função deverá retornar um número inteiro representado a
quantidade de veículos que precisaram ser estacionados novamente para que o cliente pudesse retirar o seu carro.

Input Format

Na primeira linha, enquanto -1 não for lido, ler números inteiros. Na segunda linha deve ser lido um número inteiro que será o ticket a ser procurado na fila.

Constraints

O acesso aos elementos da fila deve ser através da função desenfileirar.

Output Format

Na primeira linha, o conteúdo da fila, após a operação de busca, deve ser impresso.

Na segunda linha impresso a quantidade de movimentações que foram necessárias para procurar o ticket.

Na terceira linha deve ser impressa a string "sucesso" caso o ticket for encontrado, ou "falha", caso contrário.*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define TAM_MAX 100

typedef struct Fila Fila;

struct Fila{
    int item[TAM_MAX];
    int ini;
    int fim;
    int tam; // tamanho da fila
};

// Criar uma fila vazia
Fila* criar_fila(){
    Fila *f = (Fila*) malloc(sizeof(Fila));

    f->ini = -1;
    f->fim = -1;
    f->tam = 0;

    return f;
}

int fila_cheia(Fila *f){

    if (f == NULL)
        return -1;
    else if (f->tam < TAM_MAX)
        return 0;
    else
        return 1; // fila cheia
}


int fila_vazia(Fila *f){
    if (f == NULL)
        return -1;
    else if (f->tam > 0)
        return 0;
    else
        return 1; // fila vazia
}

// Colocar um item na fila
int enfileirar(Fila *f, int chave){

    if (f == NULL)
        f = criar_fila();


    if (!fila_cheia(f)){
        // Caso a fila estiver vazia
        if (f->ini < 0)
            f->ini = 0;

        if (f->fim < TAM_MAX - 1)
            f->fim++;
        else
            f->fim = 0;


        f->item[f->fim] = chave;


        f->tam++;

        return 1;
    }

    return 0; // A fila estava cheia
}

// remover um item da fila
int desenfileirar(Fila *f){
    int item = INT_MIN;


    if (!fila_vazia(f)){
        item = f->item[f->ini];
        f->tam--; // a fila reduz o seu tamanho

    if (f->tam == 0){
            f->ini = -1;
            f->fim = -1;
        }else if (f->ini < TAM_MAX - 1)
            f->ini++;
        else
            f->ini = 0;
    }

    return item;
}


void imprimir_fila(Fila *f){

    Fila aux = *f;
    int item;

    while (!fila_vazia(&aux)){
        item = desenfileirar(&aux);

        printf("%d ", item);
    }

    printf("\n");
}

// liberar fila
void liberar_fila(Fila *f){
    if (f != NULL)
        free(f);
}
int tamanho_fila(Fila *f){
    if (f!=NULL)
        return f->tam;
    else
        return 0;
}
int gerenciar_estacionamento(Fila *f, int t){
    int x=tamanho_fila(f);
    int item= ' ', contador= 0;

    if(f!=NULL){
    do{
        item = desenfileirar(f);

        if (item!=t){
            enfileirar(f,item);
            contador++;
        }
        x--;
    }while((x>0)&&(item!=t));
    }

    imprimir_fila(f);

    printf ("%d\n", contador);

    if (item==t)
        printf("sucesso\n");
    else
        printf("falha\n");

    return contador;
}

int main() {
    Fila *f = criar_fila();
    int item = 0, t;

    while (item!=-1){
        scanf("%d", & item);

        if (item!=-1)
            enfileirar(f, item);

    }
    scanf ("%d", & t);

    gerenciar_estacionamento(f, t);

    liberar_fila(f);

    return 0;
}

