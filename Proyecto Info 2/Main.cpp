#include "Proyecto.h"
#include "Proyecto.cpp"

int main(int argc, char *argv[]) {
	Archivo a;
	struct city *hCba=NULL;
	struct city *hSf=NULL;
	struct city *hMen=NULL;
	float arreglo[3]={0};
	int opcion=0;
	char letra=' ';
	a.scanArchivo(&hCba,&hSf,&hMen);
	do
	{
		menu();
		scanf("%d",&opcion);
		switch(opcion)
		{	
			case 1:
				cantidadMedidas(hCba,hSf,hMen);
			break;
			case 2:
				tempPromProvincia(hCba,hSf,hMen);
			break; 
			case 3:
				tempPromCiudad(hCba);
				tempPromCiudad(hSf);
				tempPromCiudad(hMen);
			break;
			case 4:
				ciudadCalida(hCba);
				ciudadCalida(hSf);
				ciudadCalida(hMen);
			break; 
			case 5:
				ciudadFria(hCba);
				ciudadFria(hSf);
				ciudadFria(hMen);
			break;
			case 6:
				diaFrio(hCba);
				diaFrio(hSf);
				diaFrio(hMen);
			break; 
			case 7:
				diaCalor(hCba);
				diaCalor(hSf);
				diaCalor(hMen);
			break;
			case 8:
				provPimientos(hCba,hSf,hMen);
			break; 
			case 0:
				exit(0);
			break;
			}
		printf("¿Desea seguir operando?S/N\n");
		scanf(" %c",&letra);
	} while(letra=='s'||letra=='S');
	
	borrarTodo(&hCba);
	borrarTodo(&hSf);
	borrarTodo(&hMen);
	
	return 0;
}
