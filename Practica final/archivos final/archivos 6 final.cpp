#include <iostream>
using namespace std;

void null(FILE *fp);

int main(int argc, char *argv[]) {
	
	FILE *fp=NULL;
	char nombre[20],marca[15],tamano[15];
	int precio=0,fecha_elab=0;
	
	
	fp=fopen("Datos_Producto.txt","w");
	
	null(fp);
	
	printf("Nombre del producto:");
	scanf("%s",nombre);
	printf("\nMarca:");
	scanf("%s",marca);
	printf("\nPrecio unitario:");
	scanf("%d",&precio);
	printf("\nFecha elaboracion:");
	scanf("%d",&fecha_elab);
	printf("\nTamano(grande,mediano,chico):");
	scanf("%s",tamano);
	
	fprintf(fp,"%s\n%s\n%d\n%d\n%s\n",nombre,marca,precio,fecha_elab,tamano);
	fclose(fp);
	   
	fp=fopen("Datos_Producto.txt","r");
	
	null(fp);
	
	while(!feof(fp)){
		fscanf(fp,"%s\n%s\n%d\n%d\n%s\n",&nombre,&marca,&precio,&fecha_elab,&tamano);
		printf("%s\n%s\n%d\n%d\n%s\n",nombre,marca,precio,fecha_elab,tamano);
	}
	fclose(fp);
	
	
	return 0;
}

void null(FILE *fp){
	
	if(fp==NULL){
		printf("\nImposible abrir el archivo");
		exit (1);
	}
}
