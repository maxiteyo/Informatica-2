#include <iostream>
using namespace std;

class Libro{
private:
	string titulo;
	float precio;
	string autor;
	
	
public:
	Libro();
	
	void setTitulo(string tit);
	string getTitulo();
	void setAutor(string aut);
	string getAutor();
	void setPrecio(float pre);
	float getPrecio();
	string toString();
	
};

Libro::Libro(){
}

void Libro::setTitulo(string tit){
	titulo=tit;
}

string Libro::getTitulo(){
	return titulo;
}

void Libro::setAutor(string aut){
	autor=aut;
}

string Libro::getAutor(){
	return autor;
}

void Libro::setPrecio(float pre){
	precio=pre;
}

float Libro::getPrecio(){
	return precio; 
}

string Libro::toString(){
	string cadena;
	cadena="Titulo:"+titulo+"Autor:"+autor+"Precio:$"+std::to_string(precio);
	return cadena;
}

