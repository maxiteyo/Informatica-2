#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	FILE *fp=NULL;
	char palabra[20]={0};
	int quijote=0,rocinante=0,sancho=0;
	
	fp=fopen("el_quijote.txt","r");
	
	if(fp==NULL){
		printf("\nImposible abrir el archivo");
		exit (1);
	}
	
	while(!feof(fp)){
		if(fscanf(fp,"%s",&palabra)== "Quijote"){
			quijote++;
		}
		if(fscanf(fp,"%s",&palabra)== "Sancho"){
			sancho++;
		}
		if(fscanf(fp,"%s",&palabra)== "Rocinante"){
			rocinante++;
		}
	}
	
	printf("\nQuijote: %d veces",quijote);
	printf("\nRocinante: %d veces",rocinante);
	printf("\nSancho: %d veces",sancho);
	return 0;
}

