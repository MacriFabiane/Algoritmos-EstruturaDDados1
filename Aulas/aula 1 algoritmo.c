#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef float REAL; //tipo nome 
typedef struct Person P2; //renomeia um tipo de dado  troca nome

//struct agrupa varios tipos de dados em um só.
typedef struct Person{ //nome do comando (dá pra tirar o person e deixar a struct anonima)
	char nome [10];//campos
	int nivel; //não   pode fazer atribições inicializar dentro das structs
	float ki;
	char raca[10];
}P2 ;//não esquecer esse ponto e vígula.

void imprimir (Person p)
{
	printf("%s    %d	%f	%s\n", p.nome,p.nivel,p.ki,p.raca);
}
Person criar p(char nome[], int nivel, float ki, char raca[])
{
	Person p;
	strcpy(p.nome, nome);
	
	return p;
}
int main()
{
	struct Person p1= {"madruga", 10, 75.0,"android"}; //prestar atenção aos campos da struct
	P2 p2;
	P2 p3;
	P2 v[3];
	
//	printf("nome : %s\n", p.nome);
//	scanf("%s", p.nome);
//	scanf("%d", & p.nivel);
	
	
	p2.nivel =15;
	p2.ki=90.0;
	strcpy(p2.nome, "babidi");
	strcpy(p2.raca, "ice");
	
	p3=p2;
	
	printf("%s    %d	%f	%s\n", p3.nome,p3.nivel,p3.ki,p3.raca);
	
	v[0]= p1;
	v[1]=p2;
	v[2]=p3;
	
	v[2].ki=8001.0;
	v[2].nivel=50;
	strcpy(v[2].nome, "brooly");
	strcpy(v[2].raca, "saiajin");
	/*char nome[4][10];
	int nivel [4];
	float ki[4];
	char raca [4][10];
	
	strcpy(nome[0], "goku");
	strcpy(nome[1], "vegeta");
	strcpy(nome[2], "gohan");
	strcpy(nome[3], "freeza");
	
	nivel [0]=10;
	nivel [1]=10;
	nivel [2]=10;
    nivel [3]=10;*/
	
	return 0;
}
