#include <stdio.h>
#include "stdafx.h"

//Este pragma es para poder usar fopen y que no sale el warning del fopen_s
#pragma warning(disable: 4996)

/* OpenFile: Abre un fichero. Recibe como parámetro el nombre del fichero y el modo de apertura (lectura o escritura), retorna un 
identificador del fichero abierto.*/

FILE* abrirArchivo(const char *nombre, const char *modo) {
	FILE* archivo = fopen(nombre, modo);
	return archivo;
}

// CloseFile: Cierra un fichero. Recibe como parámetro el identificador del fichero a cerrar.
unsigned int cerrarArchivo(FILE *file) {
	unsigned int ret = fclose(file);
	return ret;
}

/* ReadFile: Lee los ‘n’ caracteres indicados del fichero de identificador indicado, los deja en el buffer pasado y retorna 
el número de caracteres realmente leídos.*/
unsigned int leerArchivo(const int numeroCaracteres, FILE *archivo, void *buffer) {
	unsigned int caracteresLeidos = fread(buffer, sizeof(char), numeroCaracteres, archivo);
	return caracteresLeidos;
}

// WriteFile: Escribe los ‘n’ caracteres del buffer pasado en el fichero de identificador pasado y retorna los caracteres escritos.
unsigned int escribirArchivo(const int numeroCaracteres, FILE *archivo, const void *buffer) {
	unsigned int caracteresEscritos = fwrite(buffer, sizeof(char), numeroCaracteres, archivo);
	return caracteresEscritos;
}