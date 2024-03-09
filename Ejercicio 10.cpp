#include <iostream>
using namespace std;

void valores_pares(int *punt);
void valores_impares(int *punt);

int main(int argc, char *argv[]) {
	int numeros[10]={1,2,3,4,5,6,7,8,9,10},*puntero=0;
	
	puntero=numeros;
	
	valores_pares(puntero);
	valores_impares(puntero);
	
	return 0;
}

void valores_pares(int *punt){
	int i=0;
	
	printf("Valores pares:\n");
	for(i=0;i<10;i++){
		if(*(punt+i)%2==0){
			printf("%d-",*(punt+i));
		}
	}	
}
	
void valores_impares(int *punt){
	int i=0;
	
	printf("\n\nValores impares:\n");
	for(i=0;i<10;i++){
		if(*(punt+i)%2!=0){
			printf("%d-",*(punt+i));
		}
	}
	
}
