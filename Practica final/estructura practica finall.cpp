#include <iostream>
using namespace std;

struct cancion{
	string artista;
	string titulo;
	int duracion;
	int tamano;
};

int main(int argc, char *argv[]) {
	
	struct cancion a;
	
	printf("\nIngrese nombre del artista:");
	getline(cin,a.artista,'.');
	printf("\nIngrese titulo:");
	getline(cin,a.titulo,'.');
	printf("\nIngrese duracion:");
	scanf("%d",&a.duracion);
	printf("\nIngrese tamano:");
	scanf("%d",&a.tamano);
	
	printf("\n\nDATOS DE LA CANCION\n\n");
	cout<<"Nombre:"<<a.artista;
	cout<<"\nTitulo:"<<a.titulo;
	cout<<"\nDuracion:"<<a.duracion;
	cout<<"\nTamano:"<<a.tamano;
	return 0;
}

