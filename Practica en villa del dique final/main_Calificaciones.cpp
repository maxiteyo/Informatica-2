#include <iostream>
#include "Calificaciones.h"

using namespace std;

void calcularpromedio(Calificaciones alumnos[2]);
void calcularresultado(Calificaciones alumnos[2]);

int main(int argc, char *argv[]) {
	
	Calificaciones alumnos[2];
	int i=0;
	string nomb;
	string resul;
	int not1=0,not2=0,not3=0,recuper=0;
	float prom=0;
	
	for(i=0;i<2;i++){
		
		printf("\nIngrese nombre del alumno: ");
		getline(cin,nomb,'.');
		alumnos[i].setNombre(nomb);
		
		printf("\nIngrese nota 1: ");
		scanf("%d",&not1);
		alumnos[i].setNota1(not1);
		
		printf("\nIngrese nota 2: ");
		scanf("%d",&not2);
		alumnos[i].setNota2(not2);
		
		printf("\nIngrese nota 3: ");
		scanf("%d",&not3);
		alumnos[i].setNota3(not3);
		
		printf("\nIngrese nota recuperatorio: ");
		scanf("%d",&recuper);
		alumnos[i].setRecuperatorio(recuper);
		
		calcularpromedio(alumnos);
				
	}
	
	for(i=0;i<2;i++){
		cout<<alumnos[i].toString();
	}
	
	return 0;
}

void calcularpromedio(Calificaciones alumnos[2]){
	
	float prom=0;
	int acumulador=0,i=0;
	
	for(i=0;i<2;i++){
	acumulador=alumnos[i].getNota1()+alumnos[i].getNota2()+alumnos[i].getNota3();
	prom=acumulador/3;
	alumnos[i].setPromedio(prom);
	}
}
	
void calcularresultado(Calificaciones alumnos[2]){
	
	string aprob="Aprobado";
	string desaprob="Desaprobado";
	
	
	
	
	
}
