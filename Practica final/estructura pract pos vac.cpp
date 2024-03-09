#include <iostream>
using namespace std;

struct cancion{
	string artista;
	string titulo;
	int duracion;
	int tamkb;
};

int main(int argc, char *argv[]) {
	
	struct cancion a;
	
	
	printf("--INGRESE DATOS--\n\n");
	
	printf("Artista: ");
	getline(cin,a.artista,'.');
	printf("\nTitulo: ");
	getline(cin,a.titulo,'.');
	printf("\nDuracion: ");
	scanf("%d",&a.duracion);
	printf("\nTamaño en KB: ");
	scanf("%d",&a.tamkb);
	
	printf("\n\n---DATOS CANCION---\n\n");
	cout<<"Artista: "<<a.artista;
	cout<<"\nTitulo: "<<a.titulo;
	cout<<"\nDuracion: "<<a.duracion;
	cout<<"\nTamaño en KB: "<<a.tamkb;
	
	return 0;
}

