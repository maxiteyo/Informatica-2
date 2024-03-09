#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

struct node{
	int numero;
	struct node *siguiente;
};


int main(int argc, char *argv[]) {
	int numero=0,i=0;
	struct node *stackptr=NULL;
	struct node *temp=NULL;
	struct node *new_node=NULL;
	
	srand(time(NULL));
	
	
	for(i=0;i<5;i++){
		printf("Dato %d ingresado aleatoriamente\n",i+1);
		numero=1+rand()%(11-1);
		new_node=(struct node *)malloc(sizeof(struct node));
		if(new_node==NULL){
			printf("\nNo hay memoria disponible");
			exit(1);
		}
		
		new_node->numero=numero;
		new_node->siguiente=stackptr;
		stackptr=new_node;
		
	}
	
	temp=stackptr;
	printf("\nMuestra de todos los numeros:\n");
	for(i=0;i<5;i++){
		printf("%d\n",temp->numero);
		temp=temp->siguiente;
	}
		
	temp=stackptr;
	printf("\nMuestra de los numeros pares:\n");
	for(i=0;i<5;i++){
		if(temp->numero%2==0){
			printf("%d\n",temp->numero);
		}
		temp=temp->siguiente;
	}
	
	return 0;
}

