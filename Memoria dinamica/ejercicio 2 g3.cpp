#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int cantidad=0,i=0;
	float *puntero=NULL,numeros=0;
	
	printf("Ingrese cantidad de numeros que va a cargar:\n");
	scanf("%d",&cantidad);
	puntero=(float *) malloc(cantidad*sizeof(float));
	if(puntero==NULL){
		printf("No hay cantidad de memoria disponible\n");
		exit(1);
	}
	else{
		printf("Ingrese los numeros decimales:\n");
		for(i=0;i<cantidad;i++){
			scanf("%f",&numeros);
			*(puntero+i)=numeros;
		}
	}
	
	printf("Numeros ingresados:\n");
	for(i=0;i<cantidad;i++){
		printf("%0.1f\t",*(puntero+i));
	}
	free(puntero);
	return 0;
}

