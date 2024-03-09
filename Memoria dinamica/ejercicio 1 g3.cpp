#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int numeros=0,cantidad=0,*puntero=0,i=0;
	
	printf("Aclare la cantidad de numeros que va a utilzar:\n");
	scanf("%d",&cantidad);
	
	puntero=(int *) malloc(cantidad*sizeof(int));
	if(puntero==NULL){
		printf("No hay memoria suficiente disponible");
		exit(1);
	}
	else{
		for(i=0;i<cantidad;i++){
			printf("Ingrese sus numeros enteros:\n");
			scanf("%d",&numeros);
			*(puntero+i)=numeros;
		}
	}
	
	printf("\n");
	printf("Numeros ingresados:\n");
	for(i=0;i<cantidad;i++){
		printf("%d\n",*(puntero+i));
	};
	free(puntero);
	
	return 0;
}

