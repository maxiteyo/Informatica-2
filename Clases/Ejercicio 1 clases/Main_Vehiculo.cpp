#include <iostream>
#include <string>

#include "Vehiculo.h"
#include "Vehiculo.cpp"
using namespace std;

int main(int argc, char *argv[]) {
	Vehiculo v1,v2;
	
	v1.setTipo({"Auto"});
	v1.setCapacidad({5});
	v1.setPatente({123});
	v1.setColor({"Rojo"});
	
	v2.setTipo({"Moto"});
	v2.setCapacidad({2});
	v2.setPatente({456});
	v2.setColor({"Verde"});
	
	printf("\n---VEHICULO 1---\n");
	cout<<"\nTipo: "<<v1.getTipo();
	printf("\nCapacidad: %d",v1.getCapacidad());
	printf("\nPatente: %d",v1.getPatente());
	cout<<"\nColor: "<<v1.getColor();
	
	printf("\n---VEHICULO 2---\n");
	cout<<"\nTipo: "<<v2.getTipo();
	printf("\nCapacidad: %d",v2.getCapacidad());
	printf("\nPatente: %d",v2.getPatente());
	cout<<"\nColor: "<<v2.getColor();
	return 0;
}

