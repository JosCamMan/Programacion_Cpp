#include "stdafx.h"
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "funcionesUtilidades.h"

#pragma warning(disable: 4996)

int main(int argc, char* argv[]) {
	const char *cadenaAbuscar = "ca";
	FILE *archivo = funciones::abrirArchivo("archivoCasa.txt","r"); //archivo que contiene la palabra casa 20 veces
	const char *nombreArchivo = "archivoEnteros.txt"; // La suma de números es de -95.

	printf("Numero de veces que se repite la cadena '%s': %d\n", cadenaAbuscar, funcionesUtilidades::numRepeticionesCadena(archivo, cadenaAbuscar));
	printf("Total: %d\n", funcionesUtilidades::sumaEnterosArchivo(nombreArchivo));
	return 0;
}