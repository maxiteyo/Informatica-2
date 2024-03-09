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
};

int main(int argc, char *argv[]) {
	int i=0;
	struct datos persona[5];
	
	for(i=0;i<5;i++){
	//CARGA DE DATOS
	printf("\n\n---Persona nº %d---\n\n",i+1);
	printf("Ingrese nombre:");
	getline(cin,persona[i].nombre,'.');
	printf("\nIngrese apellido:");
	getline(cin,persona[i].apellido,'.');
	printf("\nIngrese dia de nacimiento:");
	scanf("%d",&persona[i].fecha.dia);
	printf("\nIngrese mes de nacimiento:");
	scanf("%d",&persona[i].fecha.mes);
	printf("\nIngrese año de nacimiento:");
	scanf("%d",&persona[i].fecha.anio);
	printf("\nIngrese provincia:");
	getline(cin,persona[i].dir.provincia,'.');
	printf("\nIngrese barrio:");
	getline(cin,persona[i].dir.barrio,'.');
	printf("\nIngrese telefono:");
	scanf("%lf",&persona[i].telefono);
	}
	//MUESTRA DE datos
	for(i=0;i<5;i++){
	printf("\n\n---Persona nº %d---\n\n",i+1);
	cout<<"\nNombre: "<<persona[i].nombre;
	cout<<"\nApellido: "<<persona[i].apellido;
	printf("\nDia de nacimiento: %d",persona[i].fecha.dia);
	printf("\nMes de nacimiento: %d",persona[i].fecha.mes);
	printf("\nAnio de nacimiento: %d",persona[i].fecha.anio);
	cout<<"\nProvincia: "<<persona[i].dir.provincia;
	cout<<"\nBarrio: "<<persona[i].dir.barrio;
	printf("\nTelefono: %lf",persona[i].telefono);
	}
	//double lf
	//long lo <--Formato para mostrarlo y cargarlo (COMPROBAR EL FORMATO EN LA PESTAÑA DE REPASO)
	
	
	return 0;
}

