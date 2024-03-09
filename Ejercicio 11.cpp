#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int numeros[10]={0},*puntero=0,i=0,num=0,acumulador=0,*puntero_acumulador=0;
	float promedio=0;
	
	puntero=numeros;
	puntero_acumulador=&acumulador;
	
	printf("Ingrese 10 numeros:\n");
	for(i=0;i<10;i++){
		scanf("%d",&num);
		*(puntero+i)=num;
		num=0;
	}
	
	for(i=0;i<10;i++){
		*puntero_acumulador=*puntero_acumulador+*(puntero+i);
	}
	
	promedio=*puntero_acumulador/10;
	
	printf("\nEl promedio de la sumatoria de sus numeros es: %f\n",promedio);
	for(i=0;i<10;i++){
		printf("%d\t",*(puntero+i));
	
	}
	return 0;
}

