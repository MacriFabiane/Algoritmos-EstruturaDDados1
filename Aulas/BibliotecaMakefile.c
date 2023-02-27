
#include <stdio.h>
#define max(a,b) a>b ? a : b
//#undef max //desdefine/fax com que seja esquecido
//#define MENSAGEM 
#ifdef MENSAGEM //para varias versions de una funcion//só sera execuado se Mensagem for definida
	void mostrar(){
		printf("Inseto\n");
	}
#else
	void mostrar(){
		printf("KAkaroto\n");
	}
#endif

int main (){
	printf("%d", max(10, 20));
	mostrar();	
	return 0;
}

