#include <iostream>
using namespace std;

struct fecha_nacimiento{
	int dia;
	int mes;
	int anio;
};

struct direccion{
	string provincia;
	string barrio;
};

struct datos{
	string nombre;
	string apellido;
	struct fecha_nacimiento fecha; 
	struct direccion dir;
	double telefono;
	int materias_y_notas[3][1];
};

int main(int argc, char *argv[]) {
	int i=0,j=0;
	struct datos alumno[5];
	
	for(i=0;i<5;i++){
		//CARGA DE DATOS
		printf("\n\n---Persona nº %d---\n\n",i+1);
		printf("Ingrese nombre:");
		getline(cin,alumno[i].nombre,'.');
		printf("\nIngrese apellido:");
		getline(cin,alumno[i].apellido,'.');
		printf("\nIngrese dia de nacimiento:");
		scanf("%d",&alumno[i].fecha.dia);
		printf("\nIngrese mes de nacimiento:");
		scanf("%d",&alumno[i].fecha.mes);
		printf("\nIngrese año de nacimiento:");
		scanf("%d",&alumno[i].fecha.anio);
		printf("\nIngrese provincia:");
		getline(cin,alumno[i].dir.provincia,'.');
		printf("\nIngrese barrio:");
		getline(cin,alumno[i].dir.barrio,'.');
		printf("\nIngrese telefono:");
		scanf("%lf",&alumno[i].telefono);
		printf("\nIngrese notas de matematica,fisica e informatica:");
		for(j=0;j<3;j++){
			scanf("%d",&alumno[i].materias_y_notas[j][1]);
		}
	}
	//MUESTRA DE datos
	for(i=0;i<5;i++){
		printf("\n\n---Persona nº %d---\n\n",i+1);
		cout<<"\nNombre: "<<alumno[i].nombre;
		cout<<"\nApellido: "<<alumno[i].apellido;
		printf("\nDia de nacimiento: %d",alumno[i].fecha.dia);
		printf("\nMes de nacimiento: %d",alumno[i].fecha.mes);
		printf("\nAnio de nacimiento: %d",alumno[i].fecha.anio);
		cout<<"\nProvincia: "<<alumno[i].dir.provincia;
		cout<<"\nBarrio: "<<alumno[i].dir.barrio;
		printf("\nTelefono: %lf",alumno[i].telefono);
		printf("\nNota de matematica,fisica e informatica:");
		for(j=0;j<3;j++){
			printf("\n%d",alumno[i].materias_y_notas[j][1]);
		}
	}
	
	return 0;
}

