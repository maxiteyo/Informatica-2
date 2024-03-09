#include <iostream>
using namespace std;

void mayuscula(char *punt);
void minuscula(char *punt);

int main(int argc, char *argv[]) {
	char abc[26]={' '},*puntero;
	int i=0;
	
	puntero=abc;
	
	for(i=0;i<26;i++){
		abc[i]=i+65;
	}
	
	mayuscula(puntero);
	minuscula(puntero);
	return 0;
}

void mayuscula(char *punt){
	int i=0;
	
	printf("Abecedario en mayuscula con funciones:\n");
	for(i=0;i<26;i++){
		*(punt+i)=toupper(*(punt+i));
		printf(" %c",*(punt+i));
	}
}
	
void minuscula(char *punt){
	int i=0;
	
	printf("\n\nAbecedario en minuscula con funciones:\n");
	for(i=0;i<26;i++){
		*(punt+i)=tolower(*(punt+i));
		printf(" %c",*(punt+i));
	}

	
}
