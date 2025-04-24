#include <stdio.h>
#include <string.h>
FILE *archivo;
char nombre[20], apellido[20], nombreBusq[20], apellidoBusq[20]; 
int dni, opc, dni_busq;
main(){
	printf("Ingrese la opcion:\n 1. Guardar datos en un archivo\n 2. Buscar por dni\n 3. Salir\n 4. Buscar por nombre y apellido\n");
	scanf("%d", &opc);
	switch(opc){
		case 1:{
			int nombreRep=0, apellidoRep=0, dniRep=0;
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
		}
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
		case 4:
			printf("Ingrese el nombre que quiere buscar: \n");
			scanf("%s", &nombreBusq);
			printf("Ingrese el apellido que quiere buscar: \n");
			scanf("%s", &apellidoBusq);
			archivo = fopen("guardar.txt", "r");
			while(fscanf(archivo, "%s %s %d", nombre, apellido, &dni) != EOF)
			{
				if(strcmp(nombre, nombreBusq) == 0 && strcmp(apellido, apellidoBusq) == 0)
				{
				printf("Su dni es: %d\n", dni);
				}
			}
			fclose(archivo);
			break;
		}
}