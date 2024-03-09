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
	
	struct datos persona;
	
	//CARGA DE DATOS
	printf("Ingrese nombre:");
	getline(cin,persona.nombre,'.');
	printf("\nIngrese apellido:");
	getline(cin,persona.apellido,'.');
	printf("\nIngrese dia de nacimiento:");
	scanf("%d",&persona.fecha.dia);
	printf("\nIngrese mes de nacimiento:");
	scanf("%d",&persona.fecha.mes);
	printf("\nIngrese año de nacimiento:");
	scanf("%d",&persona.fecha.anio);
	printf("\nIngrese provincia:");
	getline(cin,persona.dir.provincia,'.');
	printf("\nIngrese barrio:");
	getline(cin,persona.dir.barrio,'.');
	printf("\nIngrese telefono:");
	scanf("%lf",&persona.telefono);
	
	//MUESTRA DE datos
	
	cout<<"\nNombre: "<<persona.nombre;
	cout<<"\nApellido: "<<persona.apellido;
	printf("\nDia de nacimiento: %d",persona.fecha.dia);
	printf("\nMes de nacimiento: %d",persona.fecha.mes);
	printf("\nAnio de nacimiento: %d",persona.fecha.anio);
	cout<<"\nProvincia: "<<persona.dir.provincia;
	cout<<"\nBarrio: "<<persona.dir.barrio;
	printf("\nTelefono: %lf",persona.telefono);
	
	//double lf
	//long lo <--Formato para mostrarlo y cargarlo (COMPROBAR EL FORMATO EN LA PESTAÑA DE REPASO)
	
	return 0;
}

