#include "Vehiculo.h"

Vehiculo::Vehiculo() {
}

void Vehiculo::setTipo(string tip){
	tipo=tip;
}
string Vehiculo::getTipo(){
	return tipo;
}
void Vehiculo::setCapacidad(int capac){
	capacidad=capac;
}
int Vehiculo::getCapacidad(){
	return capacidad;
}
void Vehiculo::setPatente(int pat){
	patente=pat;
}
int Vehiculo::getPatente(){
	return patente;
}
void Vehiculo::setColor(string col){
	color=col;
}
string Vehiculo::getColor(){
	return color;
}
string Vehiculo::toString(){
	string cadena=tipo+"\t\t"+capacidad+"\t\t"+patente+"\t\t"+std::to_string(color);
	return cadena;
}
