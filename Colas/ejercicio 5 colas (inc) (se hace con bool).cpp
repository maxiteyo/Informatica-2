#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

struct node{
	int data;
	struct node *link;
};

void agregar(struct node **front,struct node **back,int dato);

int main(int argc, char *argv[]) {
	struct node *front=NULL;
	struct node *back=NULL;
	struct node *temp=NULL;
	int numero=0;
	char opcion=' ',eleccion=' ';
	srand(time(NULL));
	
	do{
	printf("-----MENU-----\n");
	printf("a. Agregar un nodo a la cola\n");
	printf("b. Borrar el primer nodo\n");
	printf("c. Imprimir cola\n");
	scanf(" %c",&opcion);
	
	switch(opcion){
	case 'a':
	case 'A':
		printf("\nIngrese un numero: ");
		scanf("%d",&numero);
		
		temp=front;
		while(temp!=NULL){
			if(temp->data
		agregar(&front,&back,numero);
		}//SE NECESITA SABER BOOL
		break;
	case 'b':
	case 'B':
		
		break;
	case 'c':
	case 'C':
		
		break;
	}
	
	} while(eleccion=='s' || eleccion=='S');
	return 0;
}

void agregar(struct node **front,struct node **back,int dato){
	struct node *temp=NULL;
	
	temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("\nNo hay espacio suficiente");
		exit(0);
	}
	temp->data=dato;
	temp->link=NULL;
	if(*back=NULL){
		*back=temp;
		*front=*back;
	}
	else{
		(*back)->link=temp;
		*back=temp;
	}
	
}
