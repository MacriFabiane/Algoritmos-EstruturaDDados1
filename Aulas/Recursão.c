//recursão (imitacao do for e while)
#include<stdio.h>
#include<math.h>
#include<string.h>

int sum(int v[], int n){
	if(n==0)
		return 0;
	if (n==1)
		return v[0];
	return v[n-1]+sum(v,n-1);
	
}
int fatorial_rec(int n){//recursividade (chamar uma função nela mesma) se a recursão for infinita pode acontecer o stack overflow
	if(n<=1)
		return 1;
	else return n *fatorial_rec (n-1);
}
int sum2 (int v[], int )

int mdc(int a, int b){
	if (b==0)
		return a;
	else 
		return mdc(b, a%b);
}

int fatorial(int n){//repeticao interativa o loop é exlicito
	int i, f=1;
	
	for (i=n; i>1; i--)
		f*=i;
		
		return f;
}
int main(){
	int v[]={1,2,3,4,5};
	
	printf("%d\n\n", sum(v, 5));
	
	return 0;
}
