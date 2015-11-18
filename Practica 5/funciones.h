#pragma once
#include <stdio.h>

FILE* abrirArchivo(const char *, const char *);
unsigned int cerrarArchivo(FILE *);
unsigned int leerArchivo(const int, FILE *, void *);
unsigned int escribirArchivo(const int, FILE *, const void *);
