/*Um treinador de voleibol gostaria de manter estatísticas sobre sua equipe. A cada jogo, seu auxiliar anota quantas tentativas de saques, bloqueios e ataques cada um de seus jogadores fez, bem como quantos desses saques, bloqueios e ataques tiveram sucesso (resultaram em pontos). Seu programa deve mostrar qual o percentual de saques, bloqueios e ataques do time todo tiveram sucesso.

O programa deve ter a seguinte struct:

typedef struct {
    char nome[255];
    int saquesTotal;
    int bloqueiosTotal;
    int ataquesTotal;
    int saquesSucesso;
    int bloqueiosSucesso;
    int ataquesSucesso;
}Jogador;
A taxa de sucesso de cada jogador deve ser calculada em porcentagem (%) para cada um individualmente.

Para isso crie uma função que recebe a struct como REFERÊNCIA e preencha as variáveis de % dentro dessa função.

Input Format

A entrada é dada pelo número de jogadores N, seguido pelo nome de cada um dos jogadores. Abaixo do nome de cada jogador, seguem duas linhas com três inteiros cada. Na primeira linha S, B e A representam a quantidade de tentativas de saques, bloqueios e ataques e na segunda linha, S1, B1 e A1 com o número de saques, bloqueios e ataques deste jogador que tiveram sucesso.

Constraints
.

Output Format

A saída deve conter o percentual total de saques, bloqueios e ataques do time todo que resultaram em pontos, conforme mostrado nos exemplos.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    char nome[255];
    int saquesTotal;
    int bloqueiosTotal;
    int ataquesTotal;
    int saquesSucesso;
    int bloqueiosSucesso;
    int ataquesSucesso;

}Jogador;

void porcentagem (Jogador v[], int n){

    int i,somaAtaques=0,somaSaques=0, somaBloqueios=0, somaBloqueiosSucess=0, somaAtaquesSucess=0, somaSaquesSucess=0;
    float pontosAtaque=0, pontosBloqueio=0, pontosSaque=0;

    for (i=0; i<n; i++)
    {
        somaAtaques =somaAtaques+ v[i].ataquesTotal;
        somaSaques = somaSaques+v[i].saquesTotal;
        somaBloqueios = somaBloqueios+ v[i].bloqueiosTotal;
        somaAtaquesSucess = somaAtaquesSucess+ v[i].ataquesSucesso;
        somaSaquesSucess = somaSaquesSucess+ v[i].saquesSucesso;
        somaBloqueiosSucess =  somaBloqueiosSucess + v[i].bloqueiosSucesso;
    }

    pontosSaque= (somaSaquesSucess*100.0)/somaSaques;
    pontosBloqueio=(somaBloqueiosSucess*100.0)/somaBloqueios;
    pontosAtaque=(somaAtaquesSucess*100.0)/somaAtaques;

    printf ("Pontos de Saque: %.2f%%\n", pontosSaque);
    printf ("Pontos de Bloqueio: %.2f%%\n", pontosBloqueio);
    printf ("Pontos de Ataque: %.2f%%\n", pontosAtaque);

}
int main() {

    int n, i;

    scanf ("%d", &n);
    Jogador v[n];

    for (i=0; i<n; i++)
    {
        scanf ("%s", v[i].nome);
        scanf ("%d %d %d",&v[i].saquesTotal, &v[i].bloqueiosTotal, &v[i].ataquesTotal);
        scanf ("%d %d %d", &v[i].saquesSucesso,&v[i].bloqueiosSucesso, &v[i].ataquesSucesso);
    }

    porcentagem (v, n);

    return 0;
}

