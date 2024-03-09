#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float arreglo[5]={4.5,8,2.3,1.1,3},*puntero=0,acumulador=0,promedio=0;
	int i=0;
	
	puntero=arreglo;
	
	for(i=0;i<5;i++){
		acumulador=acumulador+*(puntero+i);
	}
	
	printf("La sumatoria del arreglo es: %f\n",acumulador);
	promedio=acumulador/5;
	printf("El promedio de la sumatoria es: %f",promedio);
	

	return 0;
}

