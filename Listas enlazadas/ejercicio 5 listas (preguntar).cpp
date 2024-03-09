#include <iostream>
using namespace std;

struct node{
	char letras;
	struct node *p_next;
};

int main(int argc, char *argv[]) {
	char letra=' ';
	struct node *head=NULL;
	struct node *temp=NULL;
	struct node *new_node=NULL;
	int i=0;
	
	for(i=0;i<10;i++){
		printf("\nIngrese la letra n°%d: ",i+1);
		scanf(" %c",&letra);
		
		new_node=(struct node *)malloc(sizeof(struct node));
		if(new_node==NULL){
			printf("\nNo hay memoria disponible");
			exit(0);
		}
		
		new_node->letras=letra;
		new_node->p_next=NULL;
		
		if(head==NULL){
			head=new_node;
		}
		else{
			temp=head;
			while(temp->p_next!=NULL){
				temp=temp->p_next;
			}
			temp->p_next=new_node;
		}
	}
	
	temp=head;
	printf("\n--SOLO CONSONANTES--\n\n");
	while(temp!=NULL){
		/*if(temp->letras!='a'||
		   temp->letras!='e' ||
		   temp->letras!='i' ||
		   temp->letras!='o' || 
		   temp->letras!='u'){
			printf("\nLetra: %c",temp->letras);
		}
		temp=temp->p_next;*/ //NO FUNCIONA.
		if((temp->letras!='a') && (temp->letras!='A') && 
			(temp->letras!='e') && (temp->letras!='E') && 
			(temp->letras!='i') && (temp->letras!='I') && 
			(temp->letras!='o') && (temp->letras!='O') && 
			(temp->letras!='u') && (temp->letras!='U')){
			printf("%c\t", temp->letras);
		}
			temp=temp->p_next;
	}
	
	return 0;
}

