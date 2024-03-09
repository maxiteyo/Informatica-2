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
	
	FILE *fp=NULL;
	struct producto p[3];
	int i=0;
	
	fp=fopen("Listado_Producto.txt","w");
	null(fp);
	
	for(i=0;i<3;i++){
	printf("Nombre del producto:");
	scanf("%s",p[i].nombre);
	printf("\nMarca del producto:");
	scanf("%s",p[i].marca);
	printf("\nPrecio del producto:");
	scanf("%d",&p[i].precio);
	printf("\nFecha de elaboracion del producto:");
	scanf("%d",&p[i].fecha);
	printf("\nTamano del producto:");
	scanf("%s",p[i].tamano);
	
	fprintf(fp,"%s\n%s\n%d\n%d\n%s\n",p[i].nombre,p[i].marca,p[i].precio,p[i].fecha,p[i].tamano);
	fclose(fp);
	
	fp=fopen("Listado_Producto.txt","r");
	null(fp);
	
	while(!feof(fp)){
		fscanf(fp,"%s\n%s\n%d\n%d\n%s\n",&p[i].nombre,&p[i].marca,&p[i].precio,&p[i].fecha,&p[i].tamano);
		printf("%s\n%s\n%d\n%d\n%s\n",p[i].nombre,p[i].marca,p[i].precio,p[i].fecha,p[i].tamano);
	}
	fclose(fp);
	
	return 0;
}
}
void null(FILE *fp){
	if(fp==NULL){
		printf("\nImposible abrir el archivo");
		exit(1);
	}
}
