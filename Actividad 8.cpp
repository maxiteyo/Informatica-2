#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	char abc[26]={' '},*puntero;
	int i=0;
	
	puntero=abc;
	
	for(i=0;i<26;i++){//Cargar abecedario con codigo ASCII
		abc[i]=i+65;
	}
	
	printf("Abecedario en mayuscula:\n");
	
	for(i=0;i<26;i++){
		*(puntero+i)=toupper(*(puntero+i));
		printf(" %c",*(puntero+i));
	}
	
	printf("\n\nAbecedario en minuscula:\n");
	for(i=0;i<26;i++){
	*(puntero+i)=tolower(*(puntero+i));
	printf(" %c",*(puntero+i));
	}
	return 0;
}

