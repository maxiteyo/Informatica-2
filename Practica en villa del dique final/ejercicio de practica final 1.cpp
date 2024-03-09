#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

struct calificaciones{
	string nombre;
	int nota1;
	int nota2;
	int nota3;
	int recuperatorio;
	float nota_final;
	int resultado;
	struct calificaciones *p_next;
};

float promedio(struct calificaciones *new_node);

int main(int argc, char *argv[]) {
	string nom;
	srand(time(NULL));
	struct calificaciones *temp=NULL;
	struct calificaciones *head=NULL;
	struct calificaciones *new_node=NULL;
	int i=0,contador=0;
	char opcion=' ',eleccion=' ';
	float promedio_mayor=0;
	FILE *fp=NULL;
	
	for(i=0;i<2;i++){
		
	printf("\nIngrese nombre del alumno %d: ",i+1);
	getline(cin,nom,'.');
	new_node=(struct calificaciones *) malloc(sizeof(struct calificaciones));
	
	if(new_node==NULL){
		printf("\nNo hay memoria disponible");
		exit(1);
	}
	
	new_node->nombre=nom;
	new_node->p_next=NULL;
	new_node->nota1=rand()%(11-1);
	new_node->nota2=rand()%(11-1);
	new_node->nota3=rand()%(11-1);
	new_node->nota_final=promedio(new_node);
	
	if((new_node->nota1<4)||(new_node->nota2<4)||(new_node->nota3<4)){
		new_node->recuperatorio=rand()%(11-1);
	}
	else{
		new_node->recuperatorio=-1;
	}
	
	if(((new_node->nota1==0)||(new_node->nota2==0)||(new_node->nota3==0))&&((new_node->recuperatorio==0))){
		new_node->nota_final=0;
	}
	
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
	do{
		printf("-----MENU-----\n");
		printf("a- Mostrar el listado de calificaciones del curso\n");
		printf("b- Mostrar el mejor alumno\n");
		printf("c- Mostrar todos los alumnos que reprobaron\n");
		printf("d- Mostrar todos los alumnos que aprobaron\n");
		printf("e- Mostrar todos los alumnos que tuvieron al menos un ausente\n");
		printf("f- Contar cuantos alumnos en total hay en el curso\n");
		printf("g- Grabar un archivo\n");
		scanf(" %c",&opcion);
		
		switch(opcion){
		case 'a':
			temp=head;
			printf("\n---LISTADO DE CALIFICACIONES---\n");
			while(temp!=NULL){
				cout<<temp->nombre;
				printf("\t%d\t%d\t%d\t%d\t%f\n",temp->nota1,temp->nota2,temp->nota3,temp->recuperatorio,temp->nota_final);
				temp=temp->p_next;
			}
			break;
		case 'b':
			printf("\n---MEJOR/ES ALUMNOS---\n");
			temp=head;
			while(temp!=NULL){
				if(temp->nota_final>promedio_mayor){
					promedio_mayor=temp->nota_final;
				}
				temp=temp->p_next;
			}
			temp=head;
			while(temp!=NULL){
				if(temp->nota_final==promedio_mayor){
					cout<<temp->nombre;
					printf("\t%d\t%d\t%d\t%d\t%f\n",temp->nota1,temp->nota2,temp->nota3,temp->recuperatorio,temp->nota_final);
				}
				temp=temp->p_next;
			}
			break;
		case 'c':
			temp=head;
			printf("\n---ALUMNOS QUE REPROBARON---\n");
			while(temp!=NULL){
				if(temp->nota_final<4){
					cout<<temp->nombre;
					printf("\t%d\t%d\t%d\t%d\t%f\n",temp->nota1,temp->nota2,temp->nota3,temp->recuperatorio,temp->nota_final);
				}
				temp=temp->p_next;
			}
			break;
		case 'd':
			temp=head;
				printf("\n---ALUMNOS QUE APROBARON---\n");
			while(temp!=NULL){
				if(temp->nota_final>4){
					cout<<temp->nombre;
					printf("\t%d\t%d\t%d\t%d\t%f\n",temp->nota1,temp->nota2,temp->nota3,temp->recuperatorio,temp->nota_final);
				}
				temp=temp->p_next;
			}
			break;
		case 'e':
			temp=head;
				printf("\n---ALUMNOS CON AL MENOS UN AUSENTE---\n");
			while(temp!=NULL){
				if((temp->nota1==0)||(temp->nota2==0)||(temp->nota3==0)){
					cout<<temp->nombre;
					printf("\t%d\t%d\t%d\t%d\t%f\n",temp->nota1,temp->nota2,temp->nota3,temp->recuperatorio,temp->nota_final);
				}
				temp=temp->p_next;
			}
			break;
		case 'f':
			temp=head;
			while(temp!=NULL){
				contador++;
				temp=temp->p_next;
			}
			printf("\nHay %d alumnos en el curso",contador);
			break;
		case 'g':
			temp=head;
			while(temp!=NULL){
			
			fp=fopen("calificaciones.txt","w");
			if(fp==NULL){
				printf("\nNo se puede abrir el archivo");
				exit (2);
			}
			cout<<temp->nombre;
			printf("\t%d\t%d\t%d\t%d\t%f\n",temp->nota1,temp->nota2,temp->nota3,temp->recuperatorio,temp->nota_final);
			fclose(fp);
			
			fp=fopen("calificaciones.txt","r");
			if(fp==NULL){
				printf("\nNo se puede abrir el archivo");
				exit (3);
			}
			while(!feof(fp)){
			fscanf(fp,"%s\t%d\t%d\t%d\t%d\t%f\n",&temp->nombre,&temp->nota1,&temp->nota2,&temp->nota3,&temp->recuperatorio,&temp->nota_final);
			cout<<temp->nombre;
			printf("\t%d\t%d\t%d\t%d\t%f\n",temp->nota1,temp->nota2,temp->nota3,temp->recuperatorio,temp->nota_final);
			}
			fclose(fp);
			temp=temp->p_next;
			}	
			break;
		
		}
		
		
		printf("\n¿Desea seguir? s/n ");
		scanf(" %c",&eleccion);
	} while(eleccion=='s' || eleccion=='S');
	return 0;
}

float promedio(struct calificaciones *new_node){
	int acumulador=0;
	float promedio=0;
	
	acumulador=new_node->nota1+new_node->nota2+new_node->nota3;
	promedio=acumulador/3;
	return promedio;
}

