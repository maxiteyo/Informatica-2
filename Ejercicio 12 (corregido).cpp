#include <iostream>
using namespace std;

void cant_saldos(float *puntero);
float promedio(float *puntero);
void saldos_menores(float *puntero);
void saldos_mayores(float *puntero);
void recaudado(float *puntero);

int main(int argc, char *argv[]) {
	float saldos[10]={0},saldo=0,*puntero_saldos=NULL,promedio_saldos=0;
	int i=0;
	char opcion=' ',eleccion=' ';
	
	puntero_saldos=saldos;
	printf("Ingrese saldos de proveedores(MAX 10) o 0 para salir:\n");
	
	do{
		scanf("%f",&saldo);
		saldos[i]=saldo;		
		i++;

	}while((i<10)&&(saldo>0));
	
	do{
		printf("\n----MENU----\n");
		printf("A-Cantidad de saldos cargados\n");
		printf("B-Promedio de saldos\n");
		printf("C-Cantidad de saldos menores al promedio\n");
		printf("D-Cantidad de saldos mayores al promedio\n");
		printf("E-Calcular lo recaudado en el mes\n");
		scanf(" %c",&opcion);
		
		switch(opcion){
		case 'a':
		case 'A':
			cant_saldos(puntero_saldos);
			break;
		case 'b':
		case 'B':
			promedio_saldos=promedio(puntero_saldos);
			printf("\nEl promedio de todos los saldos es %f",promedio_saldos);
			break;
		case 'c':
		case 'C':
			saldos_menores(puntero_saldos);
			break;
		case 'd':
		case 'D':
			saldos_mayores(puntero_saldos);
			break;
		case 'e':
		case 'E':
			recaudado(puntero_saldos);
			break;
					
		}
		
		
		printf("\n¿Desea seguir? s/n ");
		scanf(" %c",&eleccion);
	} while(eleccion=='s' || eleccion=='S');
	
	return 0;
}

void cant_saldos(float *puntero){
	int i=0,cantidad=0;
	
	for(i=0;i<10;i++){
		if(*(puntero+i)>0){
			printf("$%f\n",*(puntero+i));
			cantidad++;
		}
	}
	printf("\nSe ingresaron %d saldos",cantidad);
	
}
	
float promedio(float *puntero){
	int i=0,cantidad=0;
	float sumatoria=0,promedio=0;
	
	for(i=0;i<10;i++){
		if(*(puntero+i)>0){
		sumatoria=sumatoria+*(puntero+i);
		cantidad++;
		}
	}
		
	promedio=sumatoria/cantidad;
	
	return promedio;
	
}

void saldos_menores(float *puntero){
	int i=0,cantidad=0;
	float promedio_saldo=0;
	
	promedio_saldo=promedio(puntero);
		
	for(i=0;i<10;i++){
		if(*(puntero+i)>0){
			if(*(puntero+i)<promedio_saldo){
				cantidad++;
			}
		}
	}
	
	printf("\nHay %d saldos menor/es al promedio",cantidad);
}
	
void saldos_mayores(float *puntero){
	int i=0,cantidad=0;
	float promedio_saldo=0;
	
	promedio_saldo=promedio(puntero);
	
	for(i=0;i<10;i++){
		if(*(puntero+i)>0){
			if(*(puntero+i)>promedio_saldo){
				cantidad++;
			}
		}
	}
	
	printf("\nHay %d saldos mayor/es al promedio",cantidad);
}
	
void recaudado(float *puntero){
	int i=0;
	float sumatoria=0;
	
	for(i=0;i<10;i++){
		if(*(puntero+i)>0){
			sumatoria=sumatoria+*(puntero+i);
		}
	}
	
	printf("\nLo recaudado en el mes fue un total de $%f",sumatoria);
}
