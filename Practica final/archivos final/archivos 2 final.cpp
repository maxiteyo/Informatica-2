#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int numeros[100]={0};
	int i=0,acumulador=0;
	FILE *fp=NULL;
	
	//CARGA DEL ARRGELO DE 1 A 100
	for(i=0;i<100;i++){
		acumulador++;
		numeros[i]=acumulador;
	}
	
	fp=fopen("pares.txt","w");
	
	if(fp==NULL){
		printf("\nNo se puede abrir el archivo");
		exit (1);
	}
	
	for(i=0;i<100;i++){
		if(numeros[i]%2==0){
		fprintf(fp,"%d\n",numeros[i]);
		}
	}
	fclose(fp);
	
	
	fp=fopen("pares.txt","r");
	
	if(fp==NULL){
		printf("\nNo se puede abrir el archivo");
		exit (2);
	}
	
	
	while(!feof(fp)){
		fscanf(fp,"%d\n",&numeros[i]);
		printf("%d\n",numeros[i]);
	}
	
	
	return 0;
}

