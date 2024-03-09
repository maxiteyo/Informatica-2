#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	
	FILE *fp=NULL;
	
	char nombre[30],apellido[20],nacionalidad[20];
	int edad=0;
	long dni=0;
	
	fp=fopen("datos_personales.txt","w");
	if(fp==NULL){
		printf("\nImposible abrir el archivo");
		exit (1);
	}
	
	printf("Nombre:");
	scanf("%s",nombre);
	printf("\nApellido:");
	scanf("%s",apellido);
	printf("\nDNI:");
	scanf("%ld",&dni);
	printf("\nEdad:");
	scanf("%d",&edad);
	printf("\nNacionalidad:");
	scanf("%s",nacionalidad);
	
	fprintf(fp,"%s\n%s\n%ld\n%d\n%s\n",nombre,apellido,dni,edad,nacionalidad);
	fclose(fp);
	
	fp=fopen("datos_personales.txt","r");
	
	if(fp==NULL){
		printf("\nImposible abrir el archivo");
		exit (1);
	}
	
	while(!feof(fp)){
		fscanf(fp,"%s\n%s\n%ld\n%d\n%s\n",&nombre,&apellido,&dni,&edad,&nacionalidad);
		printf("%s\n%s\n%ld\n%d\n%s\n",nombre,apellido,dni,edad,nacionalidad);
	}
	
	fclose(fp);
	
	return 0;
}

