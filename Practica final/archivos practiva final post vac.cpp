#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	FILE *fp=NULL;
	char nombre[25],apellido[25],nacionalidad[25];
	int edad=0;
	long dni=0;
	
	fp=fopen("datos_personales_postvac.txt","w");
	if(fp==NULL){
		printf("\nNo se puede abrir el archivo");
		exit(1);
	}
	
	printf("INGRESAR DATOS:\n\n");
	printf("Nombre: ");
	scanf("%s",nombre);
	printf("\nApellido: ");
	scanf("%s",apellido);
	printf("\nDNI: ");
	scanf("%ld",&dni);
	printf("\nEdad: ");
	scanf("%d",&edad);
	printf("\nNacionalidad: ");
	scanf("%s",nacionalidad);
	
	fprintf(fp,"%s\n%s\n%ld\n%d\n%s\n",nombre,apellido,dni,edad,nacionalidad);
	
	fclose(fp);
	
	
	fp=fopen("datos_personales_postvac.txt","r");
	if(fp==NULL){
		printf("\nNo se puede abrir el archivo");
		exit(1);
	}
	
	fscanf(fp,"%s\n%s\n%ld\n%d\n%s\n",&nombre,&apellido,&dni,&edad,&nacionalidad);
	printf("%s\n%s\n%ld\n%d\n%s\n",nombre,apellido,dni,edad,nacionalidad);
	
	fclose(fp);
	
	return 0;
}

