#include <stdio.h>
#include <string.h>
void troca (int *a, int *b){ //passa o endereco das variaveis
   int aux;	
   aux = *a;//TROCA DOIS VALORES DE SEUS ENDERECOS
   *a=*b;
   *b=aux;
}
int main (){
	
	int x=10, y=15;
	int *px =&x, *py=&y;
	
	printf ("Antes a= %d, b = %d\n", x, y);
	troca (&x,&y); //vai passar o endereco OU USAR troca(px, py);
	printf ("depois a= %d, b = %d\n", x, y);
	
	
	
	return 0;
}
//pc++; //desloca o endereco em 1byte(pra char)e 4byte(pra int) util para vetores


