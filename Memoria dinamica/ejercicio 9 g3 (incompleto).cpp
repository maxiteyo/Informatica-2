#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int arreglo[2][3]={0},numero=0,cantidad=0,i=0;
	char opcion=' ',eleccion=' ';
	
	printf("\n¿Cuantos numeros va a ingresar en el arreglo 2x3? ");
	scanf("%d",&cantidad);
	
	&arreglo[0][0]=(int *) malloc(cantidad*sizeof(int));
	
	if(&arreglo[0][0]==NULL){
		printf("\nNo hay memoria disponible...");
	}
	else{
		printf("\n-Carga de valores aleatoriamente-");
		for(i=0;i<cantidad;i++){
			
		}
	}
	
	do{
		printf("\n---Elija una opcion---\n");
		printf("A-Sumatoria del arreglo\n");
		printf("B-Mostrar todos los valores\n");
		scanf(" %c",&opcion);
		
		switch(opcion){
		case 'a':
		case 'A':
			
			break;
		case 'b':
		case 'B':
			
			break;
		}
		printf("'Desea seguir? s/n  ");
		scanf(" %c",&eleccion);
	} while(eleccion=='s' || eleccion=='S');
	
	
	return 0;
}

