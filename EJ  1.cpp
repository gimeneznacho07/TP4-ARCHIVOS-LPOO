#include <stdio.h>
FILE *archivo;
char nombre[20], apellido[20]; 
int dni, opc, dni_busq;
main(){
	printf("Ingrese la opcion:\n 1. Guardar datos en un archivo\n 2. Buscar por dni\n 3. Salir\n");
	scanf("%d", &opc);
	switch(opc){
		case 1:
			printf("Ingrese su nombre: \n");
			scanf("%s", nombre);
			printf("Ingrese su apellido: \n");
			scanf("%s", apellido);
			printf("Ingrese su DNI: \n");
			scanf("%d", &dni); 
			archivo = fopen("guardar.txt", "a");
			fprintf(archivo, "%s %s %d\n", nombre, apellido, dni);
			fclose(archivo);
			break;
		case 2:
			printf("Ingrese el dni que quiere buscar: \n");
			scanf("%d", &dni_busq);
			archivo = fopen("guardar.txt", "r");
			while(fscanf(archivo, "%s %s %d", nombre, apellido, &dni) != EOF)
			{
				if(dni == dni_busq)
				{
				printf("Su nombre es: %s\n", nombre);
				printf("Su apellido es: %s\n", apellido);
				}
			}
			fclose(archivo);
			break;
		case 3:
			break;	
		}
}
