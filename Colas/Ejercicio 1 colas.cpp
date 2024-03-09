#include <iostream>
using namespace std;

struct node{
	int data;
	struct node *link;
};

void push(struct node **front,struct node **back,int dato);
void pop(struct node **front,struct node **back);
void mostrar(struct node *front);
void suma(struct node *front);
int main(int argc, char *argv[]) {
	char opcion=' ',eleccion=' ';
	struct node *front=NULL;
	struct node *back=NULL;
	int dato=0,i=0;
	
	do{
	printf("---MENU---\n");
	printf("a-Agregar un nodo a la cola\n");
	printf("b-Borrar el primer nodo de la cola\n");
	printf("c-Imprimir cola\n");
	printf("d-Suma de los valores dela cola\n\n");
	scanf(" %c",&opcion);
	
	switch(opcion){
	case 'a':
		for(i=0;i<5;i++){
			printf("\nIngrese dato %d: ",i+1);
			scanf("%d",&dato);
			push(&front, &back, dato);
		}
		break;
	case 'b':
		pop(&front,&back);
		break;
	case 'c':
		mostrar(front);
		break;
	case 'd':
		suma(front);
		break;
	}
		printf("\n¿Desea seguir? ");
		scanf(" %c",&eleccion);
		
	} while(eleccion=='s' || eleccion=='S');
	
	return 0;
}

void push(struct node **front,struct node **back,int dato){
	struct node *temp=NULL;
	
	temp=(struct node *) malloc(sizeof(struct node *));
	if(temp==NULL){
		printf("\nNo hay memoria disponible");
		exit(0);
	}
	temp->data=dato;
	temp->link=NULL;
	if(*back==NULL){
		*back=temp;
		*front=*back;
	}
	else{
		(*back)->link=temp;
		*back=temp;
	}
}

void pop(struct node **front,struct node **back){
	struct node *temp;
	if((*front==*back)&&(*back==NULL)){
		printf("Vacia\n");
		exit(0);
	}
	temp=*front;
	*front=(*front)->link;
	if(*back==temp){
		*back=(*back)->link;
	}
	free(temp);
}
	
	
void mostrar(struct node *front){
	struct node *temp=NULL;
	
	temp=front;
	while(temp!=NULL){
		printf("%d- ",temp->data);
		temp=temp->link;
	}
}

void suma(struct node *front){
	struct node *temp;
	int acumulador=0;
	
	temp=front;
	while(temp!=NULL){
		acumulador=acumulador+temp->data;
		temp=temp->link;
	}
	printf("La suma de los numeros es: %d",acumulador);
	
	
}
	
