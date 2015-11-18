#include <stdlib.h>
#include <string.h>
#include "stdafx.h"

#include "funciones.h"
#include "funcionesUtilidades.h"

// Funci�n que retorna el n�mero de apariciones de una cadena en un fichero.

unsigned int funcionesUtilidades::numRepeticionesCadena(FILE *archivo, const char *cadena) {
	int contador = 0;
	char c;

	do {
		c = getc(archivo);
		if (c == *cadena) {
			contador++;
		}
	} while (c != EOF); //EOF es lo que indica que el cursor ha llegado al final del archivo

	return contador;
}

// Funci�n que retorna la suma de los n�meros enteros separados por coma presentes en un fichero.
int funcionesUtilidades::sumaEnterosArchivo(const char *nombreArchivo) {
	int tama�oArchivo = 0;
	int totalSuma = 0;

	FILE *archivo = funciones::abrirArchivo(nombreArchivo, "r");

	fseek(archivo, 0, SEEK_END); // Con SEEK_END apuntamos al final del archivo
	tama�oArchivo = ftell(archivo); // ftell nos devuelve la posici�n exacta del cursor en bytes

	void *buffer = malloc(tama�oArchivo + 1); //reservamos memoria con el tama�o del archivo + 1

	rewind(archivo); // El puntero vuelve al inicio de file (rebobinamos el fichero) porque antes lo hemos colocado al final para poder calcular su tama�o
	funciones::leerArchivo(tama�oArchivo, archivo, buffer);

	char *charBuffer = static_cast<char *>(buffer);
	*(charBuffer + tama�oArchivo) = '\0';

	char *pChar = strtok(charBuffer, ",\0"); //Divide el archivo en tokens. Delimitamos el archivo por las comas. Cuando llegue al \0 se parar�.

	while (pChar != NULL) {
		totalSuma += atoi(pChar);
		pChar = strtok(NULL, ",\0");
	}
	free(buffer);
	return totalSuma;
}
