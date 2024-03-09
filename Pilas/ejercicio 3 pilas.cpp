#include <iostream>
using namespace std;

struct node{
	int numero;
	struct node *siguiente;
};

void push(struct node **sp);
void pop(struct node **sp);
void print(struct node **sp);
void size(struct node **sp);
void print_last(struct node **sp);

int main(int argc, char *argv[]) {
	struct node *stackptr=NULL;
	char opcion=' ', eleccion=' ';
	
	do{
		printf("-----MENU-----\n");
		printf("a- Agregar un nodo a la pila\n");
		printf("b- Borrar el ultimo nodo de la pila\n");
		printf("c- Imprimir cola\n");
		printf("d- Tamaño de la pila\n");
		printf("e- Mostrar el ultimo valor de la pila\n");
		scanf(" %c",&opcion);
		
		switch(opcion){
		case 'a':
		case 'A':
			push(&stackptr);
			break;
		case 'b':
		case 'B':
			pop(&stackptr);
			break;
		case 'c':
		case 'C':
			print(&stackptr);
			break;
		case 'd':
		case 'D':
			size(&stackptr);
			break;
		case 'e':
		case 'E':
			print_last(&stackptr);
			break;
		}
		
		
		printf("\n¿Desea seguir?s/n ");
		scanf(" %c",&eleccion);
	} while(eleccion=='s' || eleccion=='S');
	
	
	return 0;
}

void push(struct node **sp){
	struct node *new_node=NULL;
	int numero=0,i=0;
	
	for(i=0;i<5;i++){
		
	printf("\nIngrese dato n°%d: ",i+1);
	scanf("%d",&numero);
		
	new_node=(struct node *)malloc(sizeof(struct node));
	
	if(new_node==NULL){
		printf("\nNo hay memoria disponible");
		exit(1);
	}
	
	new_node->numero=numero;
	new_node->siguiente=*sp;
	*sp=new_node;
	   
	}
}

void pop(struct node **sp){
	struct node *temp=NULL;
	
	temp=*sp;
	*sp=(*sp)->siguiente;
	
	free(temp);
}

void print(struct node **sp){
	
	struct node *temp=NULL;
	
	temp=*sp;
	while(temp!=NULL){
		printf("\n%d\n",temp->numero);
		temp=temp->siguiente;
	}
}
	
void size(struct node **sp){
	struct node *temp=NULL;
	int tam=0;
	
	temp=*sp;
	
	while(temp!=NULL){
		tam++;
		temp=temp->siguiente;
	}
	printf("El tamaño de la pila es: %d",tam);
}

void print_last(struct node **sp){
	
	printf("El ultimo valor de la pila es: %d",**sp);
}
	
