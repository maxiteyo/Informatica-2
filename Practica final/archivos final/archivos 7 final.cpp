#include <iostream>
using namespace std;

struct producto{
	char nombre[20];
	char marca[20];
	int precio;
	int fecha;
	char tamano[15];
};

void null(FILE *fp);

int main(int argc, char *argv[]) {
	
	struct producto p;
	FILE *fp=NULL;
	
	
	fp=fopen("Datos_producto2.txt","w");
	
	null(fp);
	
	printf("Nombre del producto:");
	scanf("%s",p.nombre);
	printf("\nMarca:");
	scanf("%s",p.marca);
	printf("\nPrecio unitario:");
	scanf("%d",&p.precio);
	printf("\nFecha elaboracion:");
	scanf("%d",&p.fecha);
	printf("\nTamano(grande,mediano,chico):");
	scanf("%s",p.tamano);
	
	fprintf(fp,"%s\n%s\n%d\n%d\n%s\n",p.nombre,p.marca,p.precio,p.fecha,p.tamano);
	fclose(fp);
	
	fp=fopen("Datos_Producto2.txt","r");	
	null(fp);
	
	while(!feof(fp)){
		fscanf(fp,"%s\n%s\n%d\n%d\n%s\n",&p.nombre,&p.marca,&p.precio,&p.fecha,&p.tamano);
		printf("%s\n%s\n%d\n%d\n%s\n",p.nombre,p.marca,p.precio,p.fecha,p.tamano);
	}
	fclose(fp);
	return 0;
}

void null(FILE *fp){
	if(fp==NULL){
		printf("\nImposible abrir el archivo");
		exit(1);
	}
}
