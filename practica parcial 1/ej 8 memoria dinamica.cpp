#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	char opcion=' ',eleccion=' ';
	int *puntero=NULL,cantidad=0,numeros=0,i=0,cantidad_realloc=0,suma=0;
	
	do{
		printf("---MENU---\n");
		printf("A.Reservar memoria e introducir datos\n");
		printf("B.Agregar reserva de memoria e introduccion de nuevos datos\n");
		printf("C.Mostrar los datos en orden y orden invertido al que fueron ingresados\n");
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
				printf("\nIngrese los numeros:\n");
				for(i=0;i<cantidad;i++){
					scanf("%d",&numeros);
					*(puntero+i)=numeros;
				}
			}
			suma=cantidad+cantidad_realloc;
			break;
		case 'b':
		case 'B':
			printf("\n¿Cual es la nuevva cantidad de nuemeros? ");
			scanf("%d",&cantidad_realloc);
			puntero=(int *) realloc(puntero,cantidad_realloc*sizeof(int));
				if(puntero==NULL){
				printf("\nNo hay memoria disponible...");
				exit(1);
			}
			else{
				printf("Ingrese los nuevos numeros:\n");
				for(i=0;i<cantidad_realloc;i++){
				scanf("%d",&numeros);
				*(puntero+cantidad+i)=numeros;
				}
			}
			suma=cantidad+cantidad_realloc;
			break;
		case 'c':
		case 'C':
			
			printf("\nNUMEROS TOTAL EN ORDEN:\n");
			for(i=0;i<suma;i++){
				printf("%d-",*(puntero+i));
			}
			printf("\nNUMEROS TOTAL EN ORDEN INVERSO:\n");
			for(i=suma-1;i>=0;i--){
				printf("%d-",*(puntero+i));
			}
			break;
		}
		
		printf("\n¿Desea seguir? s/n ");
		scanf(" %c",&eleccion);
	} while(eleccion=='s' || eleccion=='S');
	free(puntero);
	return 0;
}

