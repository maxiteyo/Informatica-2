#include <iostream>
using namespace std;

void cargar_datos(int *puntero,int cantidad);
void mostrar_datos(int *puntero,int cantidad);

void cargar_realloc(int *puntero, int cantidad,int cantidad_2);

int main(int argc, char *argv[]) {
	int *puntero=NULL,cantidad=0,cantidad_2=0,suma=0;
	
	
	printf("¿Cuantos numeros desea ingresar?: ");
	scanf("%d",&cantidad);
	puntero=(int *) malloc(cantidad*sizeof(int));
	
	cargar_datos(puntero,cantidad);
	mostrar_datos(puntero,cantidad);
	
	printf("\n¿Cuantos valores mas desea agregar a la lista?: ");
	scanf("%d",&cantidad_2);
	puntero=(int *) realloc(puntero,cantidad_2*sizeof(int));
	suma=cantidad+cantidad_2;
	
	cargar_realloc(puntero,cantidad,cantidad_2);
	mostrar_datos(puntero,suma);
	
	free(puntero);
	return 0;
}

	void cargar_datos(int *puntero,int cantidad){
		int i=0,numero=0;
		
		if(puntero==NULL){
			printf("No hay suficiente memoria...\n");
			exit(1);
		}
		else{
			printf("Ingrese los numeros:\n");
			for(i=0;i<cantidad;i++){
			scanf("%d",&numero);
			*(puntero+i)=numero;
			}
		}
	}
	
	void mostrar_datos(int *puntero,int cantidad){
		int i=0;
		
		printf("Numeros ingresados:\n\n");
		for(i=0;i<cantidad;i++){
			printf("%d-",*(puntero+i));
		}
		
	}
	
	void cargar_realloc(int *puntero, int cantidad,int cantidad_2){
		int i=0,numero=0;
		
		if(puntero==NULL){
			printf("No hay suficiente memoria...\n");
			exit(1);
		}
		else{
		printf("\nIngrese los nuevos numeros:\n");
		for(i=0;i<cantidad_2;i++){
		scanf("%d",&numero);
		*(puntero+i+cantidad)=numero;
		}
		}
	}

