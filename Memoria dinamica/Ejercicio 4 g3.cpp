#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	char *puntero=NULL,letras=' ';
	int cantidad=0,cant_realloc=0,i=0,suma=0;
	
	printf("Ingrese la cantidad de letras que va a cargar:\n");
	scanf("%d",&cantidad);
	//funcion malloc
	puntero=(char *) malloc(cantidad*sizeof(char));
	
	if(puntero==NULL){
		printf("No hay memoria disponible :(");
		exit(1);
	}
	else{
		printf("Ingrese las letras:\n");
		for(i=0;i<cantidad;i++){
		scanf(" %c",&letras);
		*(puntero+i)=letras;
		}
		
	printf("Letras ingresadas:\n");
		for(i=0;i<cantidad;i++){
			printf(" %c",*(puntero+i));
		}
	}
	
	printf("\n\nIngrese la nueva cantidad de letras que va a cargar:\n");
	scanf("%d",&cant_realloc);
	//funcion realloc
	puntero=(char *) realloc(puntero,cant_realloc*sizeof(char));
	suma=cantidad+cant_realloc;
	if(puntero==NULL){
		printf("No hay memoria disponible :(");
		exit(1);
	}
	else{
		printf("Ingrese las letras:\n");
		for(i=0;i<cant_realloc;i++){
			scanf(" %c",&letras);
			*(puntero+i+cantidad)=letras;
		}
		
		printf("Letras en total ingresadas:\n");
		for(i=0;i<suma;i++){
			printf(" %c",*(puntero+i));
		}
	}
	free(puntero);
	return 0;
}

