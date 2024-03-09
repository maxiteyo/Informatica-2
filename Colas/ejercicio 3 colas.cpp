#include <iostream>
using namespace std;

struct node{
	int data;
	struct node *link;
	
};

void agregar(struct node **front,struct node **back,int numero);
void borrar(struct node **front,struct node **back);
void imprimir(struct node *front);
int tamanio(struct node *front);

int main(int argc, char *argv[]) {
	struct node *back;
	struct node *front;
	char opcion=' ',eleccion=' ';
	int i=0,numero=0,size=0;
	
	do{
		
	printf("\n----MENU----\n");
	printf("a-Agregar nodo a la cola\n");
	printf("b-Borrar nodo\n");
	printf("c-Imprimir cola\n");
	printf("d-Tamaño de la cola\n");
	printf("e-Valor del frende de la cola\n");
	scanf(" %c",&opcion);
	
	switch(opcion){
	case 'a':
	case 'A':
		for(i=0;i<5;i++){
			printf("\nIngrese el dato %d: ",i+1);
			scanf("%d",&numero);
			agregar(&front,&back,numero);
		}
		break;
	case 'b':
	case 'B':
		borrar(&front,&back);
		break;
	case 'c':
	case 'C':
		imprimir(front);
		break;
	case 'd':
	case 'D':
		size=tamanio(front);
		printf("\nTamaño de colas: %d",size);
		break;
	case 'e':
	case 'E':
		printf("\nValor del frente de la cola: %d",front->data);
		break;
	}
	printf("\n¿Desea seguir? s/n  ");
	scanf(" %c",&eleccion);
	} while(eleccion=='s' || eleccion=='S');
	return 0;
}

void agregar(struct node **front,struct node **back,int numero){
		struct node *temp=NULL;

		temp=(struct node *) malloc(sizeof(struct node));
		if(temp==NULL){
			printf("\nNo hay memoria suficiente");
			exit(0);
		}
		temp->data=numero;
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

void borrar(struct node **front,struct node **back){
	struct node *temp=NULL;
	
	if((*front==*back)&&(*back==NULL)){
		printf("\nVacio\n");
		exit(1);
	}
	temp=*front;
	*front=(*front)->link;
	if(*back==temp){
		*back=(*back)->link;
	}
	free (temp);
}

void imprimir(struct node *front){
	struct node *temp=NULL;
	
	temp=front;
	while(temp!=NULL){
		printf("%d-",temp->data);
		temp=temp->link;
	}
}
	
int tamanio(struct node *front){
	struct node *temp=NULL;
	int contador=0;
	
	temp=front;
	while(temp!=NULL){
		contador++;
		temp=temp->link;
	}
	return contador;
}
