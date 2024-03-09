#include <iostream>
using namespace std;

struct equipo{
	string nombre;
	int ganados;
	int perdidos;
	int empatados;
	float puntaje;
	struct equipo *siguiente;
};

int main(int argc, char *argv[]) {
	
	struct equipo listado;
	struct equipo *new_node;
	
	for(i=0;i<4;i++){
		printf("\nIngrese partidos ganados,perdidos y empatados del equipo n°%d: ",i+1);
		scanf("%d",listado.ganados);
		scanf("%d",listado.perdidos);
		scanf("%d",listado.empatados);
		
		
	}
	
	return 0;
}

