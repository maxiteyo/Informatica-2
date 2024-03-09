#include <iostream>
using namespace std;

struct cancion
{
	string artista;
	string titulo;
	int duracion;
	float tamkb;
};


int main(int argc, char *argv[]) {
	
	struct cancion a;
	printf("Ingrese los siguientes datos de la cancion:\n");
	printf("Artista:");
	getline(cin,a.artista,'.');
	printf("\nTitulo:");
	getline(cin,a.titulo,'.');
	printf("\nDuracion en segundos:");
	scanf("%d",&a.duracion);
	printf("\nTamaño en KB:");
	scanf("%f",&a.tamkb);
	
	printf("\n\n---Datos de la cancion---\n\n");
	printf("Artista: %s",a.artista);
	printf("\nTitulo: %s",a.titulo);
	printf("\nDuracion: %d",a.duracion);
	printf("\nTamaño en kb: %f",a.tamkb);
	
	return 0;
}

