#include <iostream>
using namespace std;

struct node{
	int numero;
	struct node *siguiente;
};

int main(int argc, char *argv[]) {
	
	char eleccion=' ',opcion=' ';
	int numero=0,i=0,suma=0;
	struct node *stackptr=NULL;
	struct node *temp=NULL;
	struct node *new_node=NULL;
	
	do{
		printf("---MENU---\n");
		printf("a. Agregar nodo a la pila\n");
		printf("b. Borrar el ultimo nodo de la pila\n");
		printf("c. Imprimir pila\n");
		printf("d. Suma de los valores de la pila\n");
		scanf(" %c",&opcion);
		
		switch(opcion){
		case 'a':
		case 'A':
			for(i=0;i<5;i++){
				printf("\nIngrese el dato n°%d: ",i+1);
				scanf("%d",&numero);
				new_node=(struct node *)malloc(sizeof(struct node));
				if(new_node==NULL){
					printf("\nNo hay memoria disponible");
					exit(1);
				}
				
				new_node->numero=numero;
				new_node->siguiente=stackptr;
				stackptr=new_node;
			}
			break;
		case 'b':
		case 'B':
			if(stackptr!=NULL){
				temp=stackptr;
				stackptr=stackptr->siguiente;
				free(temp);
			}
			else{
				printf("Pila vacia\n");
			}
			break;
		case 'c':
		case 'C':
			temp=stackptr;
			while(temp!=NULL){
				printf("%d\n",temp->numero);
				temp=temp->siguiente;
			}
			break;
		case 'd':
		case 'D':
			temp=stackptr;
			while(temp!=NULL){
				suma=suma+temp->numero;
				temp=temp->siguiente;
			}
			printf("\nLa sumatoria de todos los numeros de la pila es %d",suma);
			break;
		}
		
		
		
		printf("\n¿Desea seguir? s/n");
		scanf(" %c",&eleccion);
	} while(eleccion=='s' || eleccion=='S');
	
	return 0;
}

