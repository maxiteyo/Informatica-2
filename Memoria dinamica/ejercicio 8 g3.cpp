#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int i=0,*puntero=NULL,numero=0,cantidad=0,cantidad_realloc=0,suma=0;
	char opcion=' ',eleccion=' ';
	
	do{
		printf("Seleccione una opcion:\n");
		printf("a-Reserva de memoria e introduccion de datos enteros\n");
		printf("b-Agregar reserva de memoria e introduccion de nuevos datos enteros\n");
		printf("c-Mostrar los datos en el orden y orden invrtido al que fueron introducidos\n");
		scanf(" %c",&opcion);
		switch(opcion){
		case 'a':
		case 'A':
			printf("\n¿Cuantos numeros va a ingresar? ");
			scanf("%d",&cantidad);
			
			puntero=(int *) malloc(cantidad*sizeof(int));
			
			if(puntero==NULL){
				printf("\nNo hay memoria disponible...");
				exit(1);
			}
			else{
				printf("\nIngrese los numeros: ");
				for(i=0;i<cantidad;i++){
				scanf("%d",&numero);
				*(puntero+i)=numero;
				}
			}
			break;
		case 'b':
		case 'B':
			printf("¿Cuantos numeros mas va a ingresar? ");
			scanf("%d",&cantidad_realloc);
			
			puntero=(int *) realloc(puntero,cantidad_realloc*sizeof(int));
			
			if(puntero==NULL){
				printf("\nNo hay memoria disponible...");
				exit(1);
			}
			else{
				printf("\nIngrese los numeros: ");
				for(i=0;i<cantidad_realloc;i++){
				scanf("%d",&numero);
				*(puntero+i+cantidad)=numero;
				}
			}
			break;
		case 'c':
		case 'C':
			suma=cantidad+cantidad_realloc;
			printf("\nDatos en orden:\n");
			for(i=0;i<suma;i++){
				printf("%d-",*(puntero+i));
			}
			
			printf("\nDatos en orden INVERSO:\n");
			for(i=suma-1;i>=0;i--){
				printf("%d-",*(puntero+i));
			}
			break;
		}
		
		printf("\n¿Desea seguir? s/n  ");
		scanf(" %c",&eleccion);
	} while(eleccion=='s' || eleccion=='S');
	
	free(puntero);
	printf("\n\nMEMORIA LIBERADA");
	return 0;
}

