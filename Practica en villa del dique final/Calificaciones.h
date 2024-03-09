#include <iostream>
using namespace std;

class Calificaciones{
private:
	string nombre;
	int nota1;
	int nota2;
	int nota3;
	int recuperatorio;
	float promedio;
	string resultado;
public:
	Calificaciones();
	void setNombre(string nom);
	string getNombre();
	void setNota1(int n1);
	int getNota1();
	void setNota2(int n2);
	int getNota2();
	void setNota3(int n3);
	int getNota3();
	void setRecuperatorio(int rec);
	int getRecuperatorio();
	void setPromedio(float prom);
	float getPromedio();
	void setResultado(string res);
	string getResultado();
	string toString();
};

Calificaciones::Calificaciones(){
}

void Calificaciones::setNombre(string nom){
	nombre=nom;
}

string Calificaciones::getNombre(){
	return nombre;
}

void Calificaciones::setNota1(int n1){
	nota1=n1;
}

int Calificaciones::getNota1(){
	return nota1;
}

void Calificaciones::setNota2(int n2){
	nota2=n2;
}

int Calificaciones::getNota2(){
	return nota2;
}

void Calificaciones::setNota3(int n3){
	nota3=n3;
}

int Calificaciones::getNota3(){
	return nota3;
}

void Calificaciones::setRecuperatorio(int rec){
	recuperatorio=rec;
}

int Calificaciones::getRecuperatorio(){
	return recuperatorio;
}

void Calificaciones::setPromedio(float prom){
	promedio=prom;
}

float Calificaciones::getPromedio(){
	return promedio;
}

void Calificaciones::setResultado(string res){
	resultado=res;
}

string Calificaciones::getResultado(){
	return resultado;
}

string Calificaciones::toString(){
	string cadena; 
		
	cadena="Nombre: "+nombre+"\tNota 1: "+std::to_string(nota1)+"\tNota 2:"+std::to_string(nota2)+"\tNota 3:"+std::to_string(nota3)+"\tRecuperatorio: "+std::to_string(recuperatorio)+"\tPromedio: "+std::to_string(promedio)+"\tResultado: "+resultado;
	return cadena;
}
