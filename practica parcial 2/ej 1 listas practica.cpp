#include <iostream>
using namespace std;

struct node{
	int numero;
	struct node *next;
};

int main(int argc, char *argv[]) {
	
	struct node *head=NULL;
	struct node *new_node=NULL;
	struct node *temp=NULL;
	int i=0,dato=0;
	
	
	for(i=0;i<5;i++){
		printf("\nIngrese dato n°%d: ",i+1);
		scanf("%d",&dato);
		
		new_node=(struct node *)malloc(sizeof(struct node));
		if(new_node==NULL){
			printf("\nNo hay memoria disponible");
			exit(1);
		}
		new_node->numero=dato;
		new_node->next=NULL;
		
		if(head==NULL){
			head=new_node;
		}
		else{
			temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=new_node;
		}
	
	}
	
	temp=head;
	printf("\nLista:");
	while(temp!=NULL){
		printf("%d",temp->numero);
		temp=temp->next;
	}
		
	
	
	return 0;
}

