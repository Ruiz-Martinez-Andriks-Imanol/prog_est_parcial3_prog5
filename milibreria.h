/* Autor: Andriks Imanol Ruiz Mártinez, Realizado: 07/04/2022
Libreria para funciones comunes del programa C
*/
#ifndef _MILIBRERIA
#define _MILIBRERIA
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Prototipos
void leers(char *mensaje,char s[], int n);
float leerf(char *mensaje, float inferior, float superior);
int leerd(char *mensaje, int inferior, int superior);
int es_entero(char *cadena);
int es_decimal(char *cadena);
#include"milibreria.cpp"
#endif
