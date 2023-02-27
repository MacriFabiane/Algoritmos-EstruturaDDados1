//ponteiros->aponta um local da memoria
#include <stdio.h>

typedef struct {
	int x, y;

}Ret;

int main (){
	
	int i=16;
	char c= 'a';
	Ret r={2,2};
	
	/*printf("valor: %d\n", i);
	printf("endereco: %d\n", &i); //vai imprimir o endereço de memoria
	printf("endereco: %x\n", &i);//imprime o endereço de memoria em hexadecimal
	printf("valor: %c\n", c);
	printf("endereco: %d\n", &c);
	printf("endereco: %x\n", &c);*/
	printf("endereco: %d\n", &r.x);//espaco de cada campo da struct
	printf("valor: %d\n", &r.y);
	printf("endereco: %x\n", &r);
	

//	printf("%d\n", sizeof(double));
//	printf("%d\n", sizeof(short));  imprime o tamanho da memoria de cada tipo
//	printf("%d\n", sizeof(Ret));
	
	return 0;
}
