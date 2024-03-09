#include "Proyecto.h"
Archivo::Archivo(){
}
Archivo::~Archivo(){
}
void check_null(FILE *fp)
{
	if(fp==NULL)
	{
		printf("Imposible mostrar\n");
		exit(1);
	}else{
		printf("Archivo encontrado\n\n");
	}
}
void Archivo::scanArchivo(struct city **cba,struct city **sf,struct city **men)
{
	int id_prov=0, id_ciudad=0, mes=0, dia=0, hora=0, min=0;
	char nombre[50];
	float temperatura=0, humedad=0;
	
	this->fp=fopen("data_set.txt", "r");
	
	check_null(this->fp);
	while(!feof(this->fp))
	{
		fscanf(this->fp,"%d	%d",&id_ciudad,&id_prov);
		if(id_prov==1)	{
			fscanf(this->fp,"	%s			%f	%f	%d	%d	%d	%d\n", &nombre, &temperatura, &humedad, &hora, &min, &dia, &mes);
			pull(cba,id_ciudad,id_prov,nombre,temperatura,humedad,hora,min,dia,mes);
		}else if(id_prov==2){
			fscanf(this->fp,"	%s			%f	%f	%d	%d	%d	%d\n", &nombre, &temperatura, &humedad, &hora, &min, &dia, &mes);
			pull(sf,id_ciudad,id_prov,nombre,temperatura,humedad,hora,min,dia,mes);
		}else if(id_prov==3){
			fscanf(this->fp,"	%s			%f	%f	%d	%d	%d	%d\n", &nombre, &temperatura, &humedad, &hora, &min, &dia, &mes);
			pull(men,id_ciudad,id_prov,nombre,temperatura,humedad,hora,min,dia,mes);
		}else{
			fscanf(this->fp, "%*[^n]n");
		}
	}
	
	fclose(this->fp);
}
void pull(struct city **head, int id_ciudad, int id_prov, char nombre[50], float temperatura, float humedad, int hora, int min, int dia, int mes)
{
	int i=0;
	struct city *new_node=NULL;
	new_node=(struct city*) malloc(sizeof(struct city));
	if(new_node==NULL)
	{
		printf("Memoria insuficiente\n");
		exit(1);
	}else{
		struct city*temp=*head;
		new_node->cityId=id_ciudad;
		new_node->provId=id_prov;
		for(i=0;i<50;i++)new_node->city_name[i]=nombre[i];
		new_node->m.temp=temperatura;
		new_node->m.hum=humedad;
		new_node->m.time.day=dia;
		new_node->m.time.hh=hora;
		new_node->m.time.mm=min;
		new_node->m.time.month=mes;
		new_node->next=NULL;
		if(*head==NULL){
			*head=new_node;
		}else{
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=new_node;
		}
	}
}
void tempPromProvincia(struct city *hCba,struct city *hSf,struct city *hMen)
{
	struct city *temp=NULL;
	float cba=0, men=0, sf=0;
	int i=0, j=0, k=0;
	temp=hCba;
	while(temp!=NULL)
	{
		cba=cba+temp->m.temp;
		i++;
		temp=temp->next;
	}
	temp=hSf;
	while(temp!=NULL)
	{
		sf=sf+temp->m.temp;
		j++;
		temp=temp->next;
	}
	temp=hMen;
	while(temp!=NULL)
	{
		men=men+temp->m.temp;
		k++;
		temp=temp->next;
	}
	
	printf("Temperaturas promedio\nCordoba: %.2f\nSanta Fe: %.2f\nMendoza: %.2f °c\n", cba/i, sf/j, men/k);
}
void borrarTodo(struct city **head)
{
	struct city *temp;
	while(*head!=NULL){
		temp=*(head);
		*(head)=(*head)->next;
		free(temp);
	}
}
void tempPromCiudad(struct city *head)
{
	struct city *temp=NULL;
	char cadena[50];
	float suma=0;
	int idAux=0, i=0, j=0;
	temp=head;
	idAux=temp->cityId;
	while(temp!=NULL)
	{
		if(temp->cityId==idAux)
		{
			suma=suma+temp->m.temp;
			i++;
			for(j=0;j<50;j++)
			{
			cadena[j]=temp->city_name[j];
			}
		}else{
			printf("La temperatura promedio en %s es: %.2f °c\n",cadena,suma/i);
			suma=temp->m.temp;
			i=1;
			idAux=temp->cityId;
		}
		temp=temp->next;
	}
	printf("La temperatura promedio en %s es: %.2f °c\n",cadena,suma/i);
}
void ciudadCalida(struct city *head)
{
	struct city *temp=NULL;
	temp=head;
	int i=0, k=0, idAux=0, idProv=0;
	char cadena[50],MaxCadena[50];
	float suma=0, max=0;
	idAux=temp->cityId;
	while(temp!=NULL)
	{
		if(temp->cityId==idAux)
		{
			suma=suma+temp->m.temp;
			i++;
			for(k=0;k<50;k++)
			{
				cadena[k]=temp->city_name[k];
			}
			idProv=temp->provId;
		}else{
			if(suma/i>max)
				{
				max=suma/i;
				for(k=0;k<50;k++)
				{
					MaxCadena[k]=cadena[k];
				}
			}
			i=1;
			suma=temp->m.temp;
			idAux=temp->cityId;
		}
		temp=temp->next;
	}
	if(idProv==1){
		printf("La ciudad mas cálida de Córdoba es %s, con una temperatura promedio de: %.2f °c\n", MaxCadena, max);
	}else if(idProv==2){
		printf("La ciudad mas cálida de Santa Fé es %s, con una temperatura promedio de: %.2f °c\n", MaxCadena, max);
	}else if(idProv==3){
		printf("La ciudad mas cálida de Mendoza es %s, con una temperatura promedio de: %.2f °c\n", MaxCadena, max);
	}
}
void ciudadFria(struct city *head)
{
	struct city *temp=NULL;
	temp=head;
	int i=0, k=0, idAux=0, idProv=0;
	char cadena[50],MinCadena[50];
	float suma=0, min=100;
	idAux=temp->cityId;
	while(temp!=NULL)
	{
		if(temp->cityId==idAux)
		{
			suma=suma+temp->m.temp;
			i++;
			for(k=0;k<50;k++)
			{
				cadena[k]=temp->city_name[k];
			}
			idProv=temp->provId;
		}else{
			if(suma/i<min)
				{
				min=suma/i;
				for(k=0;k<50;k++)
				{
					MinCadena[k]=cadena[k];
				}
			}
			i=1;
			suma=temp->m.temp;
			idAux=temp->cityId;
		}
		temp=temp->next;
	}
	if(idProv==1){
		printf("La ciudad mas fria de Córdoba es %s, con una temperatura promedio de: %.2f °c\n", MinCadena, min);
	}else if(idProv==2){
		printf("La ciudad mas fria de Santa Fé es %s, con una temperatura promedio de: %.2f °c\n", MinCadena, min);
	}else if(idProv==3){
		printf("La ciudad mas fria de Mendoza es %s, con una temperatura promedio de: %.2f °c\n", MinCadena, min);
	}
}
void diaFrio(struct city *head)
{
	struct city *temp=NULL;
	temp=head;
	int k=0, d=0, m=0,idProv=0;
	char cadena[50];
	float min=100;
	
	while(temp!=NULL)
	{
		if(temp->m.temp<min)
		{
			min=temp->m.temp;
			idProv=temp->provId;
			for(k=0;k<50;k++)
			{
				cadena[k]=temp->city_name[k];
			}
			d=temp->m.time.day;
			m=temp->m.time.month;
		}
		temp=temp->next;
	}
	
	if(idProv==1){
		printf("El día mas frío de Córdoba es %d/%d, con una temperatura de %.2f °c en la ciudad de %s\n", d, m, min, cadena);
	}else if(idProv==2){
		printf("El día mas frío de Santa Fe es %d/%d, con una temperatura de %.2f °c en la ciudad de %s\n", d, m, min, cadena);
	}else if(idProv==3){
		printf("El día mas frío de Mendoza es %d/%d, con una temperatura de %.2f °c en la ciudad de %s\n", d, m, min, cadena);
	}
}
void provPimientos(struct city *hCba,struct city *hSf,struct city *hMen)
{
	struct city *temp=NULL;
	float cba=0, men=0, sf=0;
	int i=0, j=0, k=0;
	temp=hCba;
	while(temp!=NULL)
	{
		if((temp->provId)==1)
		{
			cba=cba+temp->m.temp;
			i++;
		}
		temp=temp->next;
	}
	temp=hSf;
	while(temp!=NULL)
	{
		if((temp->provId)==2)
		{
			sf=sf+temp->m.temp;
			j++;
		}
		temp=temp->next;
	}
	temp=hMen;
	while(temp!=NULL)
	{
		if((temp->provId)==3)
		{
			men=men+temp->m.temp;
			k++;
		}
		temp=temp->next;
	}
	if(fabs((men/i)-23)<fabs((cba/k)-23) && fabs((men/i)-23)<fabs((sf/j)-23)){
		printf("La mejor provincia para cultivar pimientos es Mendoza ya que tiene una temperatura promedio de %.2f °c.\n",men/k);
	}else if(fabs((sf/j)-23)<fabs((cba/k)-23)){
		printf("La mejor provincia para cultivar pimientos es Santa Fe ya que tiene una temperatura promedio de %.2f °c.\n",sf/j);
	}else{
		printf("La mejor provincia para cultivar pimientos es Cordoba ya que tiene una temperatura promedio de %.2f °c.\n",cba/i);
	}
}
void menu (void)
{
	printf("\nIngrese los datos que quiere recuperar.\n"
			"(1)Cantidad de mediciones que se registraron.\n"
		   "(2)Temperatura promedio de cada provincia.\n"
		   "(3)Temperatura promedio de cada ciudad.\n"
		   "(4)Ciudad mas calida de cada provincia.\n"
		   "(5)Ciudad mas fria de cada provincia.\n"
		   "(6)Dia mas frio de cada provincia.\n"
		   "(7)Dia mas cálido de cada ciudad.\n"
		   "(8)Mejor provincia para cultiva pimientos(Temperatura promedio cercana a los 23°c).\n"
		   "(0)Salir.\n");
}
void diaCalor(struct city *head){
	float max=0;
	int aux=0,dia=0,mes=0,k=0;
	struct city *temp=NULL;
	char cadena[50];
	temp=head;
	aux=temp->cityId;
	while(temp!=NULL){
		if(temp->cityId==aux){
			if(temp->m.temp>max){
				max=temp->m.temp;
				dia=temp->m.time.day;
				mes=temp->m.time.month;
				for(k=0;k<50;k++)
				{
					cadena[k]=temp->city_name[k];
				}
			}
		}else{
			printf("El dia mas caluroso de la ciudad %s fue el dia %d/%d con %.2f °c.\n",cadena,dia,mes,max);
			aux=temp->cityId;
			max=temp->m.temp;
			dia=temp->m.time.day;
			mes=temp->m.time.month;
		}
		temp=temp->next;
	}
	printf("El dia mas caluroso de la ciudad %s fue el dia %d/%d con %.2f °c.\n",cadena,dia,mes,max);	
}
void cantidadMedidas(struct city *hCba,struct city *hSf,struct city *hMen)
{
	struct city *temp=NULL;
	float cba=0, men=0, sf=0;
	float rcba=0, rmen=0, rsf=0;
	int i=0, j=0, k=0;
	temp=hCba;
	while(temp!=NULL)
	{i++;
	temp=temp->next;
	}
	temp=hSf;
	while(temp!=NULL){
		j++;
		temp=temp->next;
	}
	temp=hMen;
	while(temp!=NULL){
		k++;
		temp=temp->next;
	}
	printf("Se registraron %d mediciones de la provincia de Córdiba.\n"
	"Se registraron %d mediciones de la provincia de Santa Fe.\n"
	"Se registraron %d mediciones de la provincia de Mendoza.\n",i,j,k);
}

