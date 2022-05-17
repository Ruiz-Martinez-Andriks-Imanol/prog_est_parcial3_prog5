/* Autor: Andriks Imanol Ruiz Mártinez, Realizado:  05/05/2022
Escuela: Universidad del Valle de México Campus Villahermosa
Materia: Programación Estructurada
Ciclo: 01/2022

Este es un programa de funciones, ciclos y condicionales en Lenguaje C de la materia de Programación Estructurada
Muestra el uso de:

    -Variables enteras, flotantes y en cadena
    -printf para mostrar mensajes y variables
    -fgets
    -scanf
    -El uso de include para las librerías
    -Librerías de la función string.h
   	-Uso de condicionales
    -Archivos en cpp y tipo Header
    -Método de burbuja
    -#define MAX
    -Ciclos
    -fflush
    -Funciones
    -FILE: open/close
    -Comentarios para la documentación interna del programa
*/
#include<stdio.h>
#include<stdlib.h>
#include"milibreria.h"
//Declaraciones globales
#define MAX 10
struct alumno {
	char nombre[30];
	float promedio;
	int faltas;
};
int n=0; //Variable que dice cuantos alumnos hay en el arreglo
//Prototipos
int menu();
void agregar(struct alumno x[]);
void imprimir(struct alumno x[], int tipo);
void promedio(struct alumno x[]);
void Per(struct alumno x[]);
void guardar(struct alumno x[]);
void cargar(struct alumno x[]);
void ordenarNombre(struct alumno x[]);
void ordenarCalificacion(struct alumno x[]);
//main
int main(){
	//Declaración
	int op;
	struct alumno grupo[MAX];
	//Proceso
	do{ //Ciclo
		op=menu();
		switch(op){
			case 0: printf("Adios..\n");
				break;
			case 1: agregar(grupo);
				break;
			case 2: imprimir(grupo,0);
				break;
			case 3: imprimir(grupo,1);
				break;
			case 4: imprimir(grupo, 2);
				break;
			case 5: promedio(grupo);
				break;
			case 6: Per(grupo);
				break;
			case 7: guardar(grupo);
				break;
			case 8: cargar(grupo);
				break;
			case 9: ordenarNombre(grupo);
				break;
			case 10: ordenarCalificacion(grupo);
				break;
		}
	}while(op!=0);
	return 0;
}
//funciones
int menu(){
 	int opcion;
	printf("-------- MENU PRINCIPAL ---------\n");
	printf("0. Salir \n");
	printf("1. Agregar alumnos \n");
	printf("2. Imprimir \n");
	printf("3. Alumnos Aprobados \n");
	printf("4. Alumnos Reprobados \n");
	printf("5. Promedio del grupo \n");
	printf("6. Porcentaje de alumnos Aprobados: \n");
	printf("7. Guardar Datos: \n");
	printf("8. Cargar Datos: \n");
	printf("9. Ordenar por nombre\n");
	printf("10. Ordenar por calificacion\n");
	printf("--------------------------------------\n");
	opcion=leerd("Selecciona una opcion: ",0,10);
	return opcion;
}
void agregar(struct alumno x[]){
	int pregunta;
	while(n<MAX){
		leers("Nombre: ", x[n].nombre,30);
		x[n].promedio=leerf("Promedio: ",0,10);
		x[n].faltas=leerd("Faltas: ",0,32);
		n++; //hay que validar
		pregunta=leerd("¿Agregar otro alumno? (1-Si, 0-No): ", 0, 1);
		if (pregunta==0) {
			break;
		}
	}
	if(n==MAX){
		printf("Arreglo lleno!!!\n");
		system("PAUSE");
	}
}
//La funcion imprimir el parametro tipo se le indica que va a imprimir
//0 a todos, 1 aprobados, 2 reprobados
void imprimir(struct alumno x[], int tipo){
	char mensaje[20];
	switch(tipo){
		case 0: strcpy(mensaje, "TOTALES	");
			break;
		case 1: strcpy(mensaje, "APROBADOS");
			break;
		case 2: strcpy(mensaje, "REPROBADOS");
			break;	
	}
	printf("----------------- ALUMNOS %s ----------------------------\n", mensaje);
	printf("NO.ALUMNO\tNOMBRE  \t\t\tFALTAS \t\tPROM\n");
	printf("----------------------------\n");
	for (int i=0;i<n;i++){ 
		switch(tipo){
			case 0: printf("%2d \t\t%-30s\t%2d\t\t%4.1f\n",i+1,x[i].nombre,x[i].faltas,x[i].promedio);
				break;
			case 1: if(x[i].promedio>=7 && x[i].faltas<=6){
					printf("%2d \t\t%-30s\t%2d\t\t%4.1f\n",i+1,x[i].nombre,x[i].faltas,x[i].promedio);
			}
				break;
			case 2: if(x[i].promedio<7 || x[i].faltas>6){
					printf("%2d\t\t%-30s\t%2d\t\t%4.1f\n",i+1,x[i].nombre,x[i].faltas,x[i].promedio);
			}
			break;
		}
	}
	printf("----------------------------\n");
		system("PAUSE");
}
void promedio(struct alumno x[]){
	float suma=0, prom;
	for(int i =0;i<n;i++){
		if(x[i].faltas<=6){
			suma=suma+x[i].promedio;	
		}	else{
			suma=suma+(float)5.0;
		}
	} 
	prom=suma/n;
		printf("PROMEDIO DEL GRUPO\n");
		printf("------------------------\n");
		printf("El promedio es %.01f\n: ", prom);
		printf("------------------------\n");
		system("PAUSE");
	}
void Per(struct alumno x[]){
	int aprobados=0;
	float porcentaje;
	printf("PORCENTAJE DE APROBADOS DEL GRUPO\n");
	printf("------------------------\n");
	for(int i =0;i<n;i++){
		if(x[i].promedio>=7 && x[i].faltas<=6){
			aprobados++;		
		}	
	}
	porcentaje=(aprobados*100)/n;
	printf("El porcentaje es: %.1f%%:\n",porcentaje);
	printf("------------------------\n");
	system("PAUSE");
	}
	//Guardar los datos como arreglos de estructuras en un archivo bimario
void guardar(struct alumno x[]){
	FILE *f;
	f=fopen("alumnos.dat","w");
	if(f==NULL){
		printf("Error al tratar de guardar el archivo\n");
	}
	else {
		for(int i=0;i<n;i++){
			fwrite(&x[i],sizeof(x[i]),1,f);
		}
		fclose(f);
		printf("--->Se guardaron %d registro\n",n);
		system("PAUSE");
	}
}
//Leer el archivo binario y cargarlo a larreglo de estructuras
void cargar(struct alumno x[]){
	FILE *f;
	f=fopen("alumnos.dat","r");
	n=0;
	if(f==NULL){
		printf("Error al intentar a cargar los datos!!!\n");
	}
	else {
		printf("Leyendo.............!\n");
		while(fread(&x[n],sizeof(x[n]),1,f)==1){
			n++;
			printf("%3d\t%-30s\t%4.1f\t%2d\n",n,x[n-1].nombre,x[n-1].promedio,x[n-1].faltas);
		}
		fclose(f);
		printf("--->%d registros leidos\n",n);
		system("PAUSE");
	}
}
void ordenarNombre(struct alumno x[]){
	//Ordenamiendo del arreglo por el metodo de la burbuja
	//Usando el codigo de https://es.wikipedia.org/wiki/Ordenamiento_de_burbuja
	for(int z = 1; z < n; ++z) {
		struct alumno aux;
      	for(int v = 0; v < (n - z); v++) {
         	if(strcmp(x[v].nombre, x[v+1].nombre)>0){
            	aux = x[v];
            	x[v] = x[v + 1];
            	x[v + 1] = aux;
         	}
      	}
    }
    imprimir(x,0);
}
void ordenarCalificacion(struct alumno x[]){
	for(int z = 1; z < n; ++z) {
		struct alumno aux;
      	for(int v = 0; v < (n - z); v++) {
         	if(x[v].promedio <x[v+1].promedio){
            	aux = x[v];
            	x[v] = x[v + 1];
            	x[v + 1] = aux;
         	}
      	}
    }
    imprimir(x,0);
}
