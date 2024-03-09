#ifndef VEHICULO_H
#define VEHICULO_H
#include <string>
using namespace std;

class Vehiculo{
private:
	string tipo;
	int capacidad;
	int patente;
	string color;
public:
	Vehiculo();
	
	void setTipo(string tipo);
	string getTipo();
	void setCapacidad(int capacidad);
	int getCapacidad();
	void setPatente(int patente);
	int getPatente();
	void setColor(string color);
	string getColor();
	string toString();
};

#endif //VEHICULO_H (VER SI VA O NO)
