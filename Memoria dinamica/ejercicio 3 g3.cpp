#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	char *puntero=NULL,letras=' ';
	int i=0,cantidad=0;
	
	printf("Ingrese la cantidad de letras que va a cargar:\n");
	scanf("%d",&cantidad);
	puntero=(char *) malloc(cantidad*sizeof(char));
	if(puntero==NULL){
		printf("No hay memoria suficiente\n");
		exit(1);
	}
	else{
		printf("Ingrese las letras:\n");
		for(i=0;i<cantidad;i++){
			scanf(" %c",&letras);
			*(puntero+i)=letras;
		}
	}
	
	printf("Letras ingresadas:\n");
	for(i=0;i<cantidad;i++){
		printf(" %c\t",*(puntero+i));
	
	}
	free(puntero);
	return 0;
}

