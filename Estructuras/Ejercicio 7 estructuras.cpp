#include <iostream>
using namespace std;

struct producto{
	int codigo;
	string nombre;
	int stock;
	int cant_vend;
};

void cargar_prod(struct producto articulos[10]);
void mostrar_prod(struct producto articulos[10]);
void cargar_vent(struct producto articulos[10]);
void reponer(struct producto articulos[10]);
void ordenar_mas_vendido(struct producto articulos[10]);//menor a mayor
void ordenar_menor_stock(struct producto articulos[10]);//menor a mayor

int main(int argc, char *argv[]) {
	char opcion=' ',eleccion=' ';
	struct producto articulos[10];
	
	cargar_prod(articulos);
	
	do{
	printf("---MENU---\n");
	printf("a- Mostrar todos los productos\n");
	printf("b- Cargar una venta\n");
	printf("c- Reponer mercaderia\n");
	printf("d- Ordenar por productos mas vendidos\n");
	printf("e- Ordenar por productos con menor stock\n");
	scanf(" %c",&opcion);
	
	switch(opcion){
	case 'a':
	case 'A':
		mostrar_prod(articulos);
		break;
	case 'b':
	case 'B':
		cargar_vent(articulos);
		break;
	case 'c':
	case 'C':
		reponer(articulos);
		break;
	case 'd':
	case 'D':
		ordenar_mas_vendido(articulos);
		break;
	case 'e':
	case 'E':
		ordenar_menor_stock(articulos);
		break;
	}
	
	printf("\n\n¿Desea seguir?s/n  ");
	scanf(" %c",&eleccion);
	} while(eleccion=='s' || eleccion=='S');
	return 0;
}

void cargar_prod(struct producto articulos[10]){
	int i=0;
	
	for(i=0;i<10;i++){
		printf("\n---Producto n° %d---\n",i+1);
		printf("\nIngrese codigo: ");
		scanf("%d",&articulos[i].codigo);
		printf("\nIngrese nombre: ");
		getline(cin,articulos[i].nombre,'.');
		printf("\nIngrese cantidad de stock: ");
		scanf("%d",&articulos[i].stock);
		printf("\nIngrese cantidad vendida: ");
		scanf("%d",&articulos[i].cant_vend);
	}
}
	
void mostrar_prod(struct producto articulos[10]){
	int i=0;
	
	for(i=0;i<10;i++){
		printf("\n---Producto n° %d---\n",i+1);
		printf("\nCodigo: %d",articulos[i].codigo);
		cout<<"\nNombre: "<<articulos[i].nombre;
		printf("\nCantidad de stock: %d",articulos[i].stock);
		printf("\nCantidad vendida: %d",articulos[i].cant_vend);
	}
}

void cargar_vent(struct producto articulos[10]){
	int i=0,codigo=0,cantidad=0;
	
	printf("\nIngrese codigo del producto vendido: ");
	scanf("%d",&codigo);
	
	for(i=0;i<10;i++){
		if(codigo==articulos[i].codigo){
			printf("\nIngrese la cantidad que vendio: ");
			scanf("%d",&cantidad);
			if(cantidad>articulos[i].stock){
				printf("\nNo hay stock suficiente para la venta");
			}
			else{
				articulos[i].stock=articulos[i].stock-cantidad;
				articulos[i].cant_vend=articulos[i].cant_vend+cantidad;
			}
		}
	}
	
}

void reponer(struct producto articulos[10]){
	int i=0,codigo=0,cantidad=0;
	
	printf("\nIngrese codigo del producto a reponer: ");
	scanf("%d",&codigo);
	
	for(i=0;i<10;i++){
		if(codigo==articulos[i].codigo){
			printf("\nIngrese la cantidad a reponer: ");
			scanf("%d",&cantidad);
			articulos[i].stock=articulos[i].stock+cantidad;
		}
	}
}
	
void ordenar_mas_vendido(struct producto articulos[10]){
	int i=0,j=0;
	struct producto aux;

	for (i=0; i<10-1; i++) { //nº de comparaciones
		for (j=0 ; j<10-1; j++) {
			//compara los elementos adyacentes y los intercambia
			if (articulos[j].cant_vend > articulos[j+1].cant_vend) {
				aux = articulos[j];
				articulos[j] = articulos[j+1];
				articulos[j+1] = aux;
			}
		}
	}
}

void ordenar_menor_stock(struct producto articulos[10]){
	int i=0,j=0;
	struct producto aux;
	
	for (i=0; i<10-1; i++) { //nº de comparaciones
		for (j=0 ; j<10-1; j++) {
			//compara los elementos adyacentes y los intercambia
			if (articulos[j].stock > articulos[j+1].stock) {
				aux = articulos[j];
				articulos[j] = articulos[j+1];
				articulos[j+1] = aux;
			}
		}
	}
}
