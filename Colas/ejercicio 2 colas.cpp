#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

struct node{
	int data;
	struct node *link;
};

int main(int argc, char *argv[]) {
	struct node *back=NULL;
	struct node *front=NULL;
	struct node *temp=NULL;
	int numero=0,i=0;
	srand(time(NULL));
	
	for(i=0;i<5;i++){
		numero=1+rand()%(11-1);
		
		temp=(struct node *) malloc(sizeof(struct node));
		if(temp==NULL){
			printf("\nNo hay memoria suficiente");
			exit (0);
		}
		temp->data=numero;
		temp->link=NULL;
		if(back==NULL){
			back=temp;
			front=back;
		}
		else{
			back->link=temp;
			back=temp;
		}
	}
	
	temp=front;
	
	printf("\nImpresion de todos los  numeros: ");
	while(temp!=NULL){
	printf("%d-",temp->data);
	temp=temp->link;
	}
	
	temp=front;
	
	printf("\n\nImpresion de numeros pares: ");
	while(temp!=NULL){
		if(temp->data%2==0){
		printf("%d-",temp->data);
		}
		temp=temp->link;
	}
	
	return 0;
}

