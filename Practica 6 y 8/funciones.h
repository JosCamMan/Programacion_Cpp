#include "stdafx.h"

namespace funciones {
	FILE* abrirArchivo(const char *, const char *);
	unsigned int cerrarArchivo(FILE *);
	unsigned int leerArchivo(const int, FILE *, void *);
	unsigned int escribirArchivo(const int, FILE *, const void *);
}