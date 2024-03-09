#include <iostream>
using namespace std;

struct cancion
{
	string artista;
	string titulo;
	int duracion;
	float tamkb;
};

void agregar (struct cancion datos[3],int contador);
void mostrar (struct cancion datos[3]);
void buscar_cancion(struct cancion datos[3]);


int main(int argc, char *argv[]) {
	
	int contador=0;
	char opcion=' ',eleccion=' ';
	struct cancion datos[3]; 
	datos[1].duracion=0;
	datos[2].duracion=0;
	datos[3].duracion=0;
	
	do{
		printf("-----MENU-----\n");
		printf("a-Agregar cancion");
		printf("\nb-Mostrar todas las canciones");
		printf("\nc-Buscar una cancion por titulo\n");
		scanf(" %c",&opcion);
		
		switch(opcion){
		case 'a':
		case 'A':
			if(contador<3){
			agregar(datos,contador);
			contador++;
			}
			else{
				printf("No hay lugar para cargar mas canciones");
			}
			break;
		case 'b':
		case 'B':
			mostrar (datos);
			break;
		case 'c':
		case 'C':
			buscar_cancion(datos);
			break;
		}
		
		
		printf("\n\n¿Desea seguir?s/n  ");
		scanf(" %c",&eleccion);
	} while(eleccion=='s' || eleccion=='S');
	
	return 0;
}

	void agregar (struct cancion datos[3], int contador){
		
		printf("Ingrese los siguientes  datos de la cancion:\n\n");
		printf("Artista: ");
		getline(cin,datos[contador].artista,'.');
		printf("\nTitulo: ");
		getline(cin,datos[contador].titulo,'.');
		printf("\nDuracion: ");
		scanf("%d",&datos[contador].duracion);
		printf("\nTamaño en KB:");
		scanf("%f",&datos[contador].tamkb);
			
	}
		
	void mostrar (struct cancion datos[3]){
		int i=0;
		
		for(i=0;i<3;i++){
			printf("---Cancion n° %d---\n",i+1);
			printf("\n%s\n",datos[i].artista);
			printf("\n%s\n",datos[i].titulo);
			printf("\n%d\n",datos[i].duracion);
			printf("\n%f\n",datos[i].tamkb);
		}
		
	}

	void buscar_cancion(struct cancion datos[3]){
		int i=0;
		string nombre;
		
		printf("Ingrese el nombre de la cancion que esta buscando(ingrese un punto para buscar): ");
		getline(cin,nombre,'.');
		
		for(i=0;i<3;i++){
			if(datos[i].titulo==nombre){
				printf("\nSu cancion es la numero %d",i+1);
			}
		}
		
	}
