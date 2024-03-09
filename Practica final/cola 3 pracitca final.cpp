#include <iostream>
using namespace std;

struct node{
	int numero;
	struct node *link;
};

void push(struct node **front,struct node **back,int num);
void pop(struct node **front,struct node **back);
void imprimir(struct node *front);
void tamano(struct node *front);
void frente(struct node *front);

int main(int argc, char *argv[]) {
	
	struct node *front=NULL;
	struct node *back=NULL;
	int i=0,num=0;
	char opcion=' ',eleccion=' ';
	
	do{
		printf("\n---MENU---\n");
		printf("a- Agregar nodo a la cola\n");
		printf("b- Borrar el primer nodo de la cola\n");
		printf("c- Imprimir cola\n");
		printf("d- Tamaño de la cola\n");
		printf("e- Valor del frente de la cola\n");
		scanf(" %c",&opcion);
		
		switch(opcion){
		case 'a':
		case 'A':
			for(i=0;i<5;i++){
				printf("\nIngrese dato %d: ",i+1);
				scanf("%d",&num);
				push(&front,&back,num);
			}
			break;
		case 'b':
		case 'B':
			pop(&front,&back);
			break;
		case 'c':
		case 'C':
			imprimir(front);
			break;
		case 'd':
		case 'D':
			tamano(front);
			break;
		case 'e':
		case 'E':
			frente(front);
			break;
			
		}
		
		printf("\n\n¿Desea seguir? s/n   ");
		scanf(" %c",&eleccion);
	} while(eleccion=='s' || eleccion=='S');
	
	return 0;
}

void push(struct node **front,struct node **back,int num){
	
	struct node *temp=NULL;
	
	temp=(struct node *) malloc(sizeof(struct node));
	
	if(temp==NULL){
		printf("\nNo hay memoria disponible");
		exit (1);
	}
	
	temp->numero=num;
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
	
	struct node *temp=NULL;
	
	if((*front==*back)&&(*back=NULL)){
		printf("\nLa cola esta vacia");
		exit (1);
	}
	
	temp=*front;
	*front=(*front)->link;
	free(temp);
}
	
void imprimir(struct node *front){
	
	struct node *temp=NULL;
	
	printf("\n--IMPRESION DE LA COLA--\n");
	temp=front;
	while(temp!=NULL){
		printf("%d-",temp->numero);
		temp=temp->link;
	}
	
}

void tamano(struct node *front){
	
	struct node *temp=NULL;
	int acumulador=0;
	
	temp=front;
	while(temp!=NULL){
		acumulador++;
		temp=temp->link;
	}
	printf("\nLa cola tiene un tamano de %d elementos",acumulador);
}
	
void frente(struct node *front){
	
	printf("\nEl valor del frende de la cola es %d",front->numero);
	
}
