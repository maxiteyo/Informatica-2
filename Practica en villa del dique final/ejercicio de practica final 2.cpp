#include <iostream>
#include <string.h>

using namespace std;

struct cargamento{
	int numero_cargamento;
	int peso;
	char cereal[20];
	int precio;
	int precio_total;
	struct cargamento *link;
};

void preciototal(struct cargamento *temp);
void push(struct cargamento **front,struct cargamento **back,int acumulador);
void pop(struct cargamento **front,struct cargamento **back);
void imprimir(struct cargamento *front);
void cargamento_pesado(struct cargamento *front);
void cargamento_liviano(struct cargamento *front);
void valuacion_total(struct cargamento *front);
void cantidad_cargamentos(struct cargamento *front);
void grabar_archivo(struct cargamento *front,FILE *fp);

int main(int argc, char *argv[]) {
	
	struct cargamento *back=NULL;
	struct cargamento *front=NULL;
	char opcion=' ',eleccion=' ';
	int acumulador=0;
	FILE *fp=NULL;
	
	do{
		printf("\nA- Agregar un cargamento a la cola");
		printf("\nB- Borrar un cargamento");
		printf("\nC- Mostrar todos los cargamentos");
		printf("\nD- Mostrar el cargamento mas pesado");
		printf("\nE- Mostrar el cargamento mas liviano");
		printf("\nF- Mostrar la valuacion total de todos los cargamentos");
		printf("\nG- Contar cuantos cargamentos hay en la cola");
		printf("\nH- Grabar un archivo\n");
		scanf(" %c",&opcion);
		
		switch(opcion){
		case 'a':
		case 'A':
			acumulador++;
			push(&front,&back,acumulador);
			break;
		case 'b':
		case 'B':
			pop(&front,&back);
			cout<<"\nCargamento borrado con exito\n";
			break;
		case 'c':
		case 'C':
			imprimir(front);
			break;
		case 'd':
		case 'D':
			cargamento_pesado(front);
			break;
		case 'e':
		case 'E':
			cargamento_liviano(front);
			break;
		case 'f':
		case 'F':
			valuacion_total(front);
			break;
		case 'g':
		case 'G':
			cantidad_cargamentos(front);
			break;
		case 'h':
		case 'H':
			grabar_archivo(front,fp);
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

	void push(struct cargamento **front,struct cargamento **back,int acumulador){
		
		struct cargamento *temp=NULL;
		int pes=0,prec_ton=0;
		char cere[20]={0};
		
		
		temp=(struct cargamento *) malloc(sizeof(struct cargamento));
		if(temp==NULL){
			printf("\nNo hay memoria suficiente");
			exit(1);
		}
		
		
		printf("\nIngrese peso del cargamento en toneladas: ");
		scanf("%d",&pes);
		printf("\nIngrese nombre del cereal: ");
		scanf("%s",cere);
		printf("\nPrecio por tonelada: ");
		scanf("%d",&prec_ton);
		
		temp->numero_cargamento=acumulador;
		temp->peso=pes;
		strcpy(temp->cereal,cere);//SI BORRO ESTO NO CRASHEA
		temp->precio=prec_ton;
		preciototal(temp);
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
	
void pop(struct cargamento **front,struct cargamento **back){
	
	struct cargamento *temp=NULL;
	
	if((*front==*back)&&(*back==NULL)){
		printf("\nLa cola esta vacia");
		exit(2);
	}
	temp=*front;
	*front=(*front)->link;
	free(temp);
}
	
void imprimir(struct cargamento *front){
	
	struct cargamento *temp=NULL;
	
	temp=front;
	while(temp!=NULL){
		printf("%s",temp->cereal);
		cout<<"NUMERO: "<<temp->numero_cargamento<<"\tPESO: "<<temp->peso<<"\tNOMBRE: "<<temp->cereal<<"\tPRECIO: "<<temp->precio<<"\tPRECIO TOTAL:"<<temp->precio_total<<"\n";
		temp=temp->link;
	}
	
}

void cargamento_pesado(struct cargamento *front){
	
	struct cargamento *temp=NULL;
	int mas_pesado=0;
	
	temp=front;
	while(temp!=NULL){
		if(temp->peso > mas_pesado){
			mas_pesado=temp->peso;
		}
		temp=temp->link;
	}
	
	cout<<"\n---CARGAMENTO MAS PESADO---\n";
	temp=front;
	while(temp!=NULL){
		if(temp->peso==mas_pesado){
			cout<<"NUMERO: "<<temp->numero_cargamento<<"\tPESO: "<<temp->peso<<"\tNOMBRE: "<<temp->cereal<<"\tPRECIO: "<<temp->precio<<"\tPRECIO TOTAL:"<<temp->precio_total<<"\n";	
		}
		temp=temp->link;
	}
}

void cargamento_liviano(struct cargamento *front){
	
	struct cargamento *temp=NULL;
	int mas_liviano=10000;
	
	temp=front;
	while(temp!=NULL){
		if(temp->peso < mas_liviano){
			mas_liviano=temp->peso;
		}
		temp=temp->link;
	}
	
	cout<<"\n---CARGAMENTO MAS LIVIANO---\n";
	temp=front;
	while(temp!=NULL){
		if(temp->peso==mas_liviano){
			cout<<"NUMERO: "<<temp->numero_cargamento<<"\tPESO: "<<temp->peso<<"\tNOMBRE: "<<temp->cereal<<"\tPRECIO: "<<temp->precio<<"\tPRECIO TOTAL:"<<temp->precio_total<<"\n";	
		}
		temp=temp->link;
	}
	
}
	
void valuacion_total(struct cargamento *front){
	
	struct cargamento *temp=NULL;
	int acumulador=0;
	
	temp=front;
	while(temp!=NULL){
		acumulador=acumulador+temp->precio_total;
		temp=temp->link;
	}
	cout<<"\nLa valuacion total de todos los cargamentos es: $"<<acumulador;
	
}
	
void cantidad_cargamentos(struct cargamento *front){
	
	struct cargamento *temp=NULL;
	int contador=0;
	
	temp=front;
	
	while(temp!=NULL){
		contador++;
		temp=temp->link;
	}
	cout<<"\nHay "<<contador<<" cargamentos en la cola\n";
	
}
	
	
void grabar_archivo(struct cargamento *front,FILE *fp){
	
	struct cargamento *temp=NULL;
	
	temp=front;
	
	while(temp!=NULL){
	fp=fopen("cargamentos.txt","w");
	
	if(fp==NULL){
		cout<<"\nNo se puede abrir el archivo";
		exit (3);
	}
	
	fprintf(fp,"%d\t%d\t%s\t%d\t%d\n",temp->numero_cargamento,temp->peso,temp->cereal,temp->precio,temp->precio_total);
	fclose(fp);
	
	fp=fopen("cargamentos.txt","r");
	
	if(fp==NULL){
		cout<<"\nNo se puede abrir el archivo";
			exit (4);
	}
	while(!feof(fp)){
		fscanf(fp,"%d\t%d\t%s\t%d\t%d\n",&temp->numero_cargamento,&temp->peso,&temp->cereal,&temp->precio,&temp->precio_total);
		printf("%d\t%d\t%s\t%d\t%d\n",temp->numero_cargamento,temp->peso,temp->cereal,temp->precio,temp->precio_total);
	}
	fclose(fp);
	temp=temp->link;
}
}
