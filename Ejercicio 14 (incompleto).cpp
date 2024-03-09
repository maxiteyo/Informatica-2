#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main(int argc, char *argv[]) {
	int arreglo[2][3]={0},*puntero_arreglo=0,i=0,j=0;
	
	puntero_arreglo=&arreglo[0][0];
	srand(time(NULL));
	
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			arreglo[i][j]=1+rand()%(51-1);
		}
	}
	
	for(i=0;i<2;i++){
		printf("\n");
		for(j=0;j<3;j++){
			printf("%d",*(*(puntero_arreglo+i)+j));
		}
	}
	
	
	return 0;
}

