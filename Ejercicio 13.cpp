#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

void max(int *puntero);
void min(int *puntero);
int suma(int *puntero);

int main(int argc, char *argv[]) {
	
	int valores[5]={0},*puntero_valores=0,i=0,resultado=0;
	
	puntero_valores=valores;
	srand(time(NULL));
	
	for(i=0;i<5;i++){
		*(puntero_valores+i)=1+rand()%(21-1);
	}
	
	for(i=0;i<5;i++){
		printf("%d\t",*(puntero_valores+i));
	}
	
	max(puntero_valores);
	min(puntero_valores);
	resultado=suma(puntero_valores);
	printf("\nEl resultado de la suma es: %d",resultado);
	return 0;
}

void max(int *puntero){
	int i=0,maximo=0;
	
	for(i=0;i<5;i++){
		if(i==0){
			maximo=*(puntero+i);
		}
		else{
			if(*(puntero+i)>maximo){
				maximo=*(puntero+i);
			}
		}
	}
	printf("\nEl valor maximo del arreglo es: %d",maximo);
}
	
void min(int *puntero){
	int i=0,minimo=0;
	
	for(i=0;i<5;i++){
		if(i==0){
			minimo=*(puntero+i);
		}
		else{
			if(*(puntero+i)<minimo){
				minimo=*(puntero+i);
			}
		}
	}
	printf("\nEl valor minimo del arreglo es: %d",minimo);
}
	
int suma(int *puntero){
	int i=0,suma=0;
	
	for(i=0;i<5;i++){
		suma=suma+*(puntero+i);
	}
	return suma;
}

