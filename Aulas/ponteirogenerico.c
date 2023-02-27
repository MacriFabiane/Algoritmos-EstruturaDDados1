//ponteiro generico aponta para qualquer tipo de dados;
#include <stdio.h>
#include <string.h>
int main(){
	void *p; //ponteiro generico
	int  i=10;
	char c= 'a';
	
	p = &i;
	p= &c; //o ultimo é o que vai ser mostrado.
	
	//p++; //desloca apenas 1 byte pois n reconhece o type

	printf("%x\n", p);
	printf ("%c\n", c);
	printf ("%c\n", *(char*)p); //forcar a mudanca, converte o ponteiro
	
	return 0;
}
