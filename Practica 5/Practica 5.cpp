// Practica 5.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdlib.h>

#include "funciones.h"


int main()
{
	FILE *archivo;
	unsigned int ret;
	unsigned int caracteresLeidos;
	unsigned int caracteresEscritos;
	int numCaracteres;

	caracteresLeidos = 1;
	caracteresEscritos = 1;
	numCaracteres = 25;

	void *buffer = (char *)malloc(sizeof(char)*caracteresLeidos);
	void *buffer2 = (char *)malloc(sizeof(char)*caracteresEscritos);

	//abrirArchivo
	archivo = abrirArchivo("prueba1.txt","a+");
	
	//cerrarArchivo
	ret = cerrarArchivo(archivo);

	//leerArchivo
	archivo = abrirArchivo("prueba1.txt", "a+");
	caracteresLeidos = leerArchivo(numCaracteres, archivo, buffer);
	ret = cerrarArchivo(archivo);
	printf_s("Caracteres leídos: %d", caracteresLeidos);
	
	//escribirArchivo
	archivo = abrirArchivo("prueba2.txt", "a+");
	caracteresEscritos = escribirArchivo(numCaracteres, archivo, buffer2);
	ret = cerrarArchivo(archivo);
	printf_s("Caracteres escritos: %d", caracteresEscritos);

}

