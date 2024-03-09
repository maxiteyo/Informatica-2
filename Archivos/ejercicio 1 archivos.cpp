#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	char nombre[30]=' ',apellido[15]=' ',nacionalidad[15]=' ';
	long dni=0;
	int edad=0;
	
	FILE *fp;
	fp=fopen("./datos_personales.txt","w");
	if(fp==NULL){
		printf("\nNo se pudo abrir el archivo");
		exit(1);
	}
	
	printf("\nNombre: ");
	scanf("%s",nombre);
	printf("\nApellido: ");
	scanf("%s",apellido);
	printf("\nDNI: ");
	scanf("%ld",&dni);
	printf("\nEdad: ");
	scanf("%d",&edad);
	printf("\nNacionalidad: ");
	scanf("%s",nacionalidad);
	
	
	
	fclose(fp);
	
	fp=fopen("./datos_personales.txt","r");
	if(fp==NULL){
		printf("\No se pudo abrir el archivo");
		exit(1);
	}
	
	while(!feof(fp)){
		letra=getc(fp);
		printf("%c",letra);
	}
	fclose(fp);
	
	
	return 0;
}

