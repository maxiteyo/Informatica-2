#include <iostream>
using namespace std;

struct empleado
{
	int legajo;
	string puesto_de_trabajo;
	float sueldo;
	int anios_antiguedad;
};

void agregar(struct empleado datos[3],int contador);
void mostrar(struct empleado datos[3]);
void buscar_legajo(struct empleado datos[3]);
void actualizar_sueldo(struct empleado datos[3]);
void ordenar_sueldo(struct empleado datos[3]);

int main(int argc, char *argv[]) {
	
	struct empleado datos[3];
	char opcion=' ',eleccion=' ';
	int contador=0,i=0;
	
	for(i=0;i<3;i++){
		datos[i].sueldo=0;
		datos[i].anios_antiguedad=0;
		datos[i].legajo=0;
	}//VER SI SE PUEDE INICIALIZAR EN CERO
	
	do{
		printf("---MENU---\n");
		printf("a.Agregar un empleado\n");
		printf("b.Mostrar todos los empleados\n");
		printf("c.Buscar un empleado por legajo\n");
		printf("d.Actualizar sueldo\n");
		printf("e.Ordenar por sueldo\n");
		printf("f.Ordenar por años de antiguedad\n");
		scanf(" %c",&opcion);
		
		switch(opcion){
		case 'a':
		case 'A':
			if(contador<3){
			agregar(datos,contador);
			contador++;
			}
			else{
				printf("\nNo hay espacio para guardar mas datos de empleados");
			}
			break;
		case 'b':
		case 'B':
			mostrar(datos);
			break;
		case 'c':
		case 'C':
			buscar_legajo(datos);
			break;
		case 'd':
		case 'D':
			actualizar_sueldo(datos);
			break;
		case 'e':
		case 'E':
			ordenar_sueldo(datos);
			break;
		case 'f':
		case 'F':
			
			break;
		}
		
		printf("\n\n¿Desea seguir? s/n  ");
		scanf(" %c",&eleccion);
	} while(eleccion=='s' || eleccion=='S');
	
	return 0;
}


void agregar(struct empleado datos[3],int contador){
	int i=0;
	
		printf("\nIngrese legajo del empleado(en numeros): ");
		scanf("%d",&datos[contador].legajo);
		printf("\nIngrese puesto de trabajo: ");
		getline(cin,datos[contador].puesto_de_trabajo,'.');
		printf("\nIngrese sueldo: ");
		scanf("%f",&datos[contador].sueldo);
		printf("\nIngrese años de antiguedad: ");
		scanf("%d",&datos[contador].anios_antiguedad);
}
	
	void mostrar(struct empleado datos[3]){
		int i=0;
		
		for(i=0;i<3;i++){
			printf("\n\nEMPLEADO %d: \n",i+1);
			printf("Legajo: %d",datos[i].legajo);
			printf("\nPuesto de trabajo: %s",datos[i].puesto_de_trabajo);
			printf("\nSueldo: $%f",datos[i].sueldo);
			printf("\nAños de antiguedad: %d",datos[i].anios_antiguedad);
		}
	}
	
	void buscar_legajo(struct empleado datos[3]){
		int i=0,legajo=0;
		
		printf("\nIngrese numero de legajo a buscar: ");
		scanf("%d",&legajo);
		
		for(i=0;i<3;i++){
			if(legajo==datos[i].legajo){
				printf("\nSi, el empleado existe");
			}//VER QUE PONER SI NO EXISTE
		}
	}

	void actualizar_sueldo(struct empleado datos[3]){
		int i=0,legajo=0;
		float nuevo_sueldo=0;
		
		printf("\nIngrese legajo del empleado que quiere actualizar el sueldo: ");
		scanf("%d",&legajo);
		
		for(i=0;i<3;i++){
			if(legajo==datos[i].legajo){
				printf("\nIngrese nuevo sueldo del empleado del legajo %d: ",datos[i].legajo);
				scanf("%f",&nuevo_sueldo);
				datos[i].sueldo=nuevo_sueldo;
			}
		}
		
	}

	void ordenar_sueldo(struct empleado datos[3]){
		int i=0, j=0;
		struct empleado aux;
		for (i=0; i<3-1; i++) { //nº de comparaciones
			for (j=0 ; j<3-1; j++) {
				//compara los elementos adyacentes y los intercambia
				if (datos[j].sueldo > datos[j+1].sueldo) {
					aux = datos[j];
					datos[j] = datos[j+1];
					datos[j+1] = aux;
				}
			}
		}
	}
