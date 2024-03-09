#ifndef PROYECTO_H
#define PROYECTO_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct timestamp{
	int day;
	int month;
	int hh;
	int mm;
};
struct measurement{
	struct timestamp time;
	float temp;
	float hum;
};
struct city{
	struct city *next;
	struct measurement m;
	int cityId;
	int provId;
	char city_name[50];
};
class Archivo{
	private:
		FILE *fp;
	public:
		Archivo();
		void scanArchivo(struct city **cba,struct city **sf,struct city **men);
		~Archivo();
};
void check_null(FILE *fp);
void pull(struct city **head, int id_ciudad, int id_prov, char nombre[50], float temperatura, float humedad, int hora, int min, int dia, int mes);
void tempPromProvincia(struct city *hCba,struct city *hSf,struct city *hMen);
void borrarTodo(struct city **head);
void tempPromCiudad(struct city *head);
void ciudadCalida(struct city *head);
void ciudadFria(struct city *head);
void diaFrio(struct city *head);
void provPimientos(struct city *hCba,struct city *hSf,struct city *hMen);
void menu (void);
void diaCalor(struct city *head);
void cantidadMedidas(struct city *hCba,struct city *hSf,struct city *hMen);
#endif
