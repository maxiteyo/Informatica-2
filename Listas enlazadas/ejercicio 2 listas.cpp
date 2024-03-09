#include <iostream>
using namespace std;

struct node{
	int numeros;
	struct node *p_next;
};

int main(int argc, char *argv[]) {
	
	int numero=0,i=0,acumulador=0;
	float prom=0;
	
	struct node *head=NULL;
	struct node *temp=NULL;
	struct node *new_node=NULL;
	
	for(i=0;i<5;i++){
		printf("Ingrese un dato: ");
		scanf("%d",&numero);
		
		new_node=(struct node *) malloc(sizeof(struct node));
		
		if(new_node==NULL){
			printf("\nNo hay memoria disponible");
			exit(0);
		}
		
		new_node->numeros=numero;
		new_node->p_next=NULL;
		
		if(head==NULL){
			head=new_node;
		}
		else{
			temp=head;
			while(temp->p_next != NULL){
				temp=temp->p_next;
			}
			temp->p_next=new_node;
		}
	}
	temp=head;
	while(temp!=NULL){
		printf("\nNumero: %d",temp->numeros);
		acumulador=acumulador+temp->numeros;
		temp=temp->p_next;
	}
	
	prom=acumulador/5;
	printf("\nEl promedio es %f",prom);
	return 0;
}

