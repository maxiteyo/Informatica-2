#include <iostream>
#include <string.h>
using namespace std;

struct cargamento{
	int numero_cargamento;
	int peso;
	char ceral[20];
	int precio;
	int precio_total;
	struct cargamento *siguiente;
};

void preciototal(struct cargamento *temp);
void push(struct cargamento **stackptr,int acumulador);
void pop(struct cargamento **stackptr);
void imprimir(struct cargamento *stackptr);
void cargamento_pesado(struct cargamento *stackptr);
void cargamento_liviano(struct cargamento *stackptr);
void valuacion_total(struct cargamento *stackptr);
void contar(struct cargamento *stackptr);
void grabar_archivo(struct cargamento *stackptr,FILE *fp);
void check_null(FILE *fp);

int main(int argc, char *argv[]) {
	
	struct cargamento *stackptr=NULL;
	char opcion=' ',eleccion=' ';
	int acumulador=0;
	FILE *fp=NULL;
	
	do{
		printf("----MENU----\n");
		printf("a- Agregar un cargamento a la pila\n");
		printf("b- Borrar un cargamento\n");
		printf("c- Mostrar todos los cargamentos\n");
		printf("d- Mostrar el cargamento mas pesado\n");
		printf("e- Mostrar el cargamento mas liviano\n");
		printf("f- Mostrar valuacion total de todos los cargamentos\n");
		printf("g- Contar cuantos cargamentos hay en la pila\n");
		printf("h- Grabar un archivo\n");
		printf("Opcion: ");
		scanf(" %c",&opcion);
		
		switch(opcion){
		case 'a':
		case 'A':
			acumulador++;
			push(&stackptr,acumulador);
			break;
		case 'b':
		case 'B':
			pop(&stackptr);
			printf("\nCargamento borrado con exito");
			break;
		case 'c':
		case 'C':
			imprimir(stackptr);
			break;
		case 'd':
		case 'D':
			cargamento_pesado(stackptr);
			break;
		case 'e':
		case 'E':
			cargamento_liviano(stackptr);
			break;
		case 'f':
		case 'F':
			valuacion_total(stackptr);
			break;
		case 'g':
		case 'G':
			contar(stackptr);
			break;
		case 'h':
		case 'H':
			grabar_archivo(stackptr,fp);
			break;
		}
		
		
		
		printf("\n¿Desea seguir? s/n ");
		scanf(" %c",&eleccion);
	} while(eleccion=='s' || eleccion=='S');
	
	
	return 0;
}

void preciototal(struct cargamento *temp){
	
	temp->precio_total=temp->peso*temp->precio;
}

void push(struct cargamento **stackptr,int acumulador){
	
	struct cargamento *temp=NULL;
	//int num=0,pes=0,prec=0;
	//char cer[20]={0};
	
	temp=(struct cargamento *) malloc(sizeof(struct cargamento));
	
	if(temp==NULL){
		printf("\nNo hay memoria disponible");
		exit(1);
	}
	temp->numero_cargamento=acumulador;
	printf("\nIngrese peso en toneladas: ");
	scanf("%d",&temp->peso);
	printf("\nIngrese nombre del ceral: ");
	scanf("%s",&temp->ceral);
	printf("\nIngrese precio por tonelada: ");
	scanf("%d",&temp->precio);
	preciototal(temp);
	temp->siguiente=*stackptr;
	*stackptr=temp;
	
}

void pop(struct cargamento **stackptr){
	
	struct cargamento *temp=NULL;
	
	temp=*stackptr;
	*stackptr=(*stackptr)->siguiente;
	free(temp);
	
}

void imprimir(struct cargamento *stackptr){
	
	struct cargamento *temp=NULL;
	
	printf("\n---CARGAMENTOS---\n");
	temp=stackptr;
	while(temp!=NULL){
		
		printf("NUMERO: %d\tPESO: %d\tCERAL: %s\tPRECIO: $%d\tPRECIO TOTAL: $%d\n",temp->numero_cargamento,temp->peso,temp->ceral,temp->precio,temp->precio_total);
		temp=temp->siguiente;
	}
	
}

void cargamento_pesado(struct cargamento *stackptr){
	
	struct cargamento *temp=NULL;
	int pesado=0;
	
	temp=stackptr;
	
	while(temp!=NULL){
		if(temp->peso>pesado){
			pesado=temp->peso;
		}
		temp=temp->siguiente;
	}
	
	temp=stackptr;
	
	printf("\n---CARGAMENTO MAS PESADO---\n");
	while(temp!=NULL){
		if(temp->peso==pesado){
			printf("NUMERO: %d\tPESO: %d\tCERAL: %s\tPRECIO: $%d\tPRECIO TOTAL: $%d\n",temp->numero_cargamento,temp->peso,temp->ceral,temp->precio,temp->precio_total);
		}
		temp=temp->siguiente;
	}
}
	
void cargamento_liviano(struct cargamento *stackptr){
	
	struct cargamento *temp=NULL;
	int liviano=10000;
	
	temp=stackptr;
	
	while(temp!=NULL){
		if(temp->peso<liviano){
			liviano=temp->peso;
		}
		temp=temp->siguiente;
	}
	
	temp=stackptr;
	
	printf("\n---CARGAMENTO MAS LIVIANO---\n");
	while(temp!=NULL){
		if(temp->peso==liviano){
			printf("NUMERO: %d\tPESO: %d\tCERAL: %s\tPRECIO: $%d\tPRECIO TOTAL: $%d\n",temp->numero_cargamento,temp->peso,temp->ceral,temp->precio,temp->precio_total);
		}
		temp=temp->siguiente;
	}	
}
	
void valuacion_total(struct cargamento *stackptr){
	
	struct cargamento *temp=NULL;
	int acumulador=0;
	
	temp=stackptr;
	while(temp!=NULL){
		acumulador=acumulador+temp->precio_total;
		temp=temp->siguiente;
	}
	printf("\nLa valuacion total de los cargamentos es de: $%d",acumulador);
}
	
void contar(struct cargamento *stackptr){
	
	struct cargamento *temp=NULL;
	int contador=0;
	
	temp=stackptr;
	while(temp!=NULL){
		contador++;
		temp=temp->siguiente;
	}
	printf("\nHay %d cargamentos en la pila",contador);
}

void check_null(FILE *fp){
	if(fp==NULL){
		printf("\nNo se puede abrir el archivo");
		exit(1);
	}
}
	
void grabar_archivo(struct cargamento *stackptr,FILE *fp){
	
	struct cargamento *temp=NULL;
	
	temp=stackptr;
	
	fp=fopen("cargamentosPILA.txt","w");
	check_null(fp);
	while(temp!=NULL){
	
	fprintf(fp,"%d\t%d\t%s\t%d\t%d\n",temp->numero_cargamento,temp->peso,temp->ceral,temp->precio,temp->precio_total);
	temp=temp->siguiente;
	}
	fclose(fp);
	
	temp=stackptr;
	
	fp=fopen("cargamentosPILA.txt","r");
	check_null(fp);
	while(temp!=NULL){
	
	fscanf(fp,"%d\t%d\t%s\t%d\t%d\n",&temp->numero_cargamento,&temp->peso,&temp->ceral,&temp->precio,&temp->precio_total);
	printf("%d\t%d\t%s\t%d\t%d\n",temp->numero_cargamento,temp->peso,temp->ceral,temp->precio,temp->precio_total);
	temp=temp->siguiente;
	}
	fclose(fp);
}
