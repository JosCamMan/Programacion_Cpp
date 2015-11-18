// Practica 3 - Uso de funciones.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

const char *t[] = { "hola", "adios", "quetal" };
const int tamanioT = sizeof(t) / sizeof(t[0]);

bool existeIndice(int, char const *&);
char *indiceCadenaInvertido(int, char const *&);
void cadenaInvertida(char const *const, char *&, int);

int main()
{
	printf_s("EJERCICIO 1\n");
	const char *pCadena = NULL;
	if (existeIndice(1, pCadena)) {
		printf_s("La cadena es: %s\n\n", pCadena);
	}
	else {
		printf_s("La cadena no existe\n\n");
	}

	printf_s("EJERCICIO 2\n");
	char *cadenaInvertida = indiceCadenaInvertido(2, pCadena);
	printf("La cadena invertida es: %s\n\n", cadenaInvertida);
	free(cadenaInvertida);
}


// 1. Hacer una funci�n que, dado un �ndice de cadena, retorne si existe una cadena con ese �ndice y, si existe, que la retorne. 
bool existeIndice(int indice, char const *&pCadena) { // Referencia de un puntero que apunta a contenido (cadena) constante. 
	bool existe = false;
	if ((indice < tamanioT) && (indice >= 0)) {
		pCadena = t[indice];
		existe = true;
	}
	return existe;
}

// 2. Hacer una funci�n que retorne la cadena de la posici�n dada invertida.
char *indiceCadenaInvertido(int indice, char const *&pCadena) {
	char *retCadena = NULL;
	if (existeIndice(indice, pCadena)) {
		int elementos = static_cast<int>(strlen(pCadena) + 1);
		retCadena = static_cast<char *>(malloc(static_cast<unsigned int>(elementos)));
		cadenaInvertida(pCadena, retCadena, (elementos - 1));
	}
	return retCadena;
}

//Si le pas�ramos una cadena a la funci�n anterior, se llamar�a a esta de forma din�mica y mostrar�a la cadena invertida.
// 3. Hacer una funci�n que dada una cadena retorne la cadena invertida.
void cadenaInvertida(char const *const pCadena, char *&pInvertido, int elementos) {
	int total = elementos - 1;
	for (int i = total; i >= 0; i--) {
		pInvertido[i] = pCadena[total - i];
	}
	pInvertido[elementos] = '\0';
}