#include <iostream>
using namespace std;

struct node{
	char letra=' ';
	struct node *siguiente;
};

void push(struct node **sp);
void pop(struct node **sp);
void print(struct node **sp);

int main(int argc, char *argv[]) {
	struct node *stackptr=NULL;
	char opcion=' ',eleccion=' ';
	
	do{
		printf("----MENU----\n");
		printf("a- Agregar nodo (Letras)\n");
		printf("b- Borrar el ultimo nodo de la pila\n");
		printf("c- Imprimir pila\n");
		printf("d- Tamaño de la pila\n");
		printf("e- Cantidad de letras mayusculas y minusculas en la pila\n");
		scanf(" %c",&opcion);
		
		switch(opcion){
		case'a':
				push(&stackptr);
				break;
		case'b':
				pop(&stackptr);
				break;
		case'c':
				
				break;
		case'd':
			
				break;
		case'e':
			
				break;
				
		}
		
		printf("\n¿Deseas seguir? s/n  ");
		scanf(" %c",&eleccion);
	} while(eleccion=='s'||eleccion=='S');
	
	return 0;
}

void push(struct node **sp){
	struct node *new_node=NULL;
	char letra=' ';
	
	new_node=(struct node *)malloc(sizeof(struct node));
	
	if(new_node==NULL){
		printf("\nNo hay memoria disponible");
		exit(1);
	}
	new_node->letra=letra;
	new_node->siguiente=*sp;
	*sp=new_node;
	
}
	
void pop(struct node **sp){
	struct node *temp=NULL;
	
	temp=*sp;
	*sp=(*sp)->siguiente;
	free(temp);
}

void print(struct node **sp){
	struct node *temp=NULL;
	
	
	
}
