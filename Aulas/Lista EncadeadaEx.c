struct Cel{
    int item; 
    Cel *next;
};
int main(){
	Cel *p1 = (Cel*) malloc(sizeof(Cel));
	Cel *p2 = (Cel*) malloc(sizeof(Cel));
	Cel *p3 = (Cel*) malloc(sizeof(Cel));
	Cel *aux;
    p1->item = 10;
    p2->item = 20;
    p3->item = 30;
    p3->next=NULL;
    p2->next = p3;
    p1->next=p2;
    
    printf("%d\n", p1->item);
    printf("%d\n", p2->item);
    printf("%d\n", p1->next->item);
    printf("%d\n", p3->item);
    printf("%d\n", p2->next->item);
    printf("%d\n", p1->next->next->item);//problematico
	
	aux=p1;
	
	while(aux!=NULL){//para imprimir todos elementos em seguida
		printf("%d\n", aux->item);//aux p/ n perder a head
		aux=aux->next;
	}
	return 0;
}
