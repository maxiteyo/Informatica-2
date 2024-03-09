#include "Libro.h"
#include <iostream>
#include <string>
using namespace std;

void mostrarListado(Libro listadoLibro[3]);
void calcularSumaPrecio(Libro listadoLibro[3]);

int main(int argc, char *argv[]) {
	
	Libro listadoLibro[3];
	int i=0;
	string autor;
	string titulo;
	float precio=0;
	
	for(i=0;i<3;i++){
		printf("\nIngrese titulo:");
		getline(cin,titulo,'.');
		listadoLibro[i].setTitulo(titulo);
		
		printf("\nIngrese autor:");
		getline(cin,autor,'.');
		listadoLibro[i].setAutor(autor);
		
		printf("\nIngrese precio:");
		scanf("%f",&precio);
		listadoLibro[i].setPrecio(precio);
		
	}
	mostrarListado(listadoLibro);
	calcularSumaPrecio(listadoLibro);
	
	
	return 0;
}

void mostrarListado(Libro listadoLibro[3]){
	
	int i=0;
	printf("\nListado completo:\n");
	for(i=0;i<3;i++){
		cout<<listadoLibro[i].toString();
	}
}
	
void calcularSumaPrecio(Libro listadoLibro[3]){
	
	int i=0;
	float acumulador=0;
	
	for(i=0;i<3;i++){
		acumulador=acumulador+listadoLibro[i].getPrecio();
	}
	printf("\nLa suma total de todos los precios es: %f",acumulador);
	
}

