#include <iostream>
using namespace std;

void cargar_datos(int *puntero,int cantidad);
void mostrar_datos(int *puntero,int cantidad);
void orden_inverso(int *puntero,int cantidad);

int main(int argc, char *argv[]) {
	int *puntero=NULL,cantidad=0; 
	
	printf("¿Cuantos numeros desea ingresar?: ");
	scanf("%d",&cantidad);
	puntero=(int *) malloc(cantidad*sizeof(int));
	cargar_datos(puntero,cantidad);
	mostrar_datos(puntero,cantidad);
	orden_inverso(puntero,cantidad);
	
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
		printf("Ingrese los numeros: ");
		for(i=0;i<cantidad;i++){
			scanf("%d",&numero);
			*(puntero+i)=numero;
		}
	}
}

	void mostrar_datos(int *puntero,int cantidad){
		int i=0;
		
		printf("Numeros ingresados en orden seguido:\n");
		for(i=0;i<cantidad;i++) {
			printf("%d\t",*(puntero+i));
		}
	}

	void orden_inverso(int *puntero,int cantidad){
		int i=0;
		
		printf("\nNumeros ingresados en orden INVERSO:\n");
		for(i=cantidad-1; i>=0 ;i--){
			printf("%d\t",*(puntero+i));
		}
	}
