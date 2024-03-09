#include <iostream>
using namespace std;

struct node{
	char data;
	struct node *link;
};

void agregar(struct node **front,struct node **back,char dato);
void borrar(struct node **front,struct node **back);
void mostrar(struct node *front);
void cantidad(struct node *front);
void cant_mayus_minus(struct node *front);


int main(int argc, char *argv[]) {
	char opcion=' ',eleccion=' ',value=' ';
	struct node *front=NULL;
	struct node *back=NULL;
	
	do{
		printf("---MENU---\n");
		printf("a-Agregar un nodo a la cola\n");
		printf("b-Borrar el primer nodo de la cola\n");
		printf("c-Imprimir cola\n");
		printf("d-Cantidad de nodos\n");
		printf("e-Cantidad de letras mayus y minus\n");
		scanf(" %c",&opcion);
		
		switch(opcion){
		case 'a':
		case 'A':
			printf("Ingrese las letras [. para terminar la carga]:\n");
			do{
				scanf(" %c", &value);
				if(value!='.' && ((value>=65 && value<=90)||(value>=97 && value<=122))){
					agregar(&front, &back, value);
				}else{
					if(value=='.')
						printf("Fin de la carga.\n");
					else
						printf("No es una letra, ingrese otra:\n");
				}
			}while(value!='.');
			break;
		case 'b':
		case 'B':
			borrar(&front,&back);
			break;
		case 'c':
		case 'C':
			mostrar(front);
			break;
		case 'd':
		case 'D':
			cantidad(front);
			break;
		case 'e':
		case 'E':
			cant_mayus_minus(front);
			break;
		}
		
		printf("\n¿Desea seguir? ");
		scanf(" %c",&eleccion);
		
	} while(eleccion=='s' || eleccion=='S');
	return 0;
}

void agregar(struct node **front,struct node **back,char dato){
	struct node *temp=NULL;
	
	temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("\nNo hay memoria disponible");
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

void borrar(struct node **front,struct node **back){
	struct node *temp=NULL;
	
	if((*front==*back)&&(*back==NULL)){
		printf("Vacia\n");
		exit(0);
	}
	temp=*front;
	*front=(*front)->link;
	if(*back==temp){
		*back=(*back)->link;
	}
	printf("Primer nodo borrado de la cola\n");
	free(temp);
}

void mostrar(struct node *front){
	struct node *temp=NULL;
	temp=front;
	while(temp!=NULL){
		printf("%c--",temp->data);
		temp=temp->link;
	}
}

void cantidad(struct node *front){
	struct node *temp=NULL;
	int contador=0;
	
	temp=front;
	while(temp!=NULL){
		contador++;
		temp=temp->link;
	}
	printf("El tamaño es: %d",contador);
}
	
void cant_mayus_minus(struct node *front){
	int cant_may=0,cant_min=0;
	struct node *temp=NULL;
	temp=front;
	while(temp!=NULL){
		if(temp->data>=65 && temp->data<=90){
			cant_may++;
		}
		else{
			if(temp->data>=97 && temp->data<=122){
				cant_min++;
			}
		}
		temp=temp->link;
	}
	printf("Cantidad de mayusculas: %d \n",cant_may);
	printf("Cantidad de minusculas: %d \n",cant_min);
}
