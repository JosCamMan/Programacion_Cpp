// TOMAS: Mira los comentarios que te hago en el c�digo (busca la palabra TOMAS en el fichero)
// TOMAS: Tienes que quitar los warnings.

// Tenemos un entero de 32 bits:
// 8 bits mayor peso la vida
// siguientes 8 bits: n�mero de balas.
// Siguientes 4 bits: n�mero de compa�eros.
// bit 0: invulnerable
// bit 1: balas infinitas.
// bit 2: escudo.
// bit 3: berseker mode.

// Hacer la siguiente pr�ctica.
// Para almacenar el estado de un personaje se utiliza la variable
// que est� empaquetada seg�n el formato de arriba.
// 1.- Hacer una funci�n que pasado un valor retorne el n�mero de balas
// 2.- Hacer una funci�n que a�ada un n�mero de balas a las ya existentes.
// 3.- Hacer una funci�n que pasado un valor retorne si se tienen balas infinitas

// 4.- Hacer una funci�n ponga modo de balas infinitas.

#pragma warning(disable: 4514)

#include "stdafx.h"
#include "stdlib.h"

int balasInventario(int);
int anadirBalas(int, unsigned int);
int setBalas(int, int);
bool comprobarBalasInfinitas(int);
int activarBalasInfinitas(int);

int main(int argc, char* argv[])
{
	int infoMago = 0xFFA82000;
	int opcion = 0;
	unsigned int balas = 0;

	do {
		printf_s("MENU DEL PERSONAJE:\n");

		printf_s("Elija una de las siguientes opciones\n");
		printf_s("1. Mostrar n�mero de balas\n");
		printf_s("2. A�adir balas\n");
		printf_s("3. Comprobar si tienes balas infinitas\n");
		printf_s("4. Activar las balas infinitas\n");
		printf_s("5. Salir\n\n");

		scanf_s("%i", &opcion);
		printf_s("\n");


		switch (opcion) {
		case 1:
			printf_s("Balas en el inventario: %d\n", balasInventario(infoMago));
			printf_s("\n");
			break;
		case 2:
			printf_s("N�mero de balas actual: %u\n", balasInventario(infoMago));
			printf_s("�Cu�ntas balas quieres a�adir?: ");
			scanf_s("%i", &balas);
			printf_s("\n");
			if (balas > 255) {
				printf_s("El m�ximo de balas que puedes llevar es 255\n");
			}
			printf_s("Balas en el inventario: %u\n", anadirBalas(infoMago, balas));
			printf_s("\n");
			break;
		case 3:
			if (comprobarBalasInfinitas(infoMago)) {
				printf_s("Tienes balas infinitas\n");
				printf_s("\n");
			}
			else {
				printf_s("No tienes balas infinitas\n");
				printf_s("\n");
			}
			break;
		case 4:
			if (activarBalasInfinitas(infoMago)) {
				printf_s("Ya tienes balas infinitas\n");
				printf_s("\n");
			}
			else {
				printf_s("No tienes balas infinitas\n");
				printf_s("\n");
			}
			break;
		case 5:
			break;
		}
	} while (opcion != 5);
}

//1. - Hacer una funci�n que pasado un valor retorne el n�mero de balas
//Creamos la m�scara conveniente para que al realizar una operaci�n AND y moverla 16 bits a la derecha (el sitio de las 
//balas) nos muestre el valor que deseamos. Se usa unsigned int para que al moverlo, no cambie el n�mero de balas y no nos 
//muestre un valor err�neo. El uso de unsigned int a lo largo de toda la pr�ctica se justifica por la misma raz�n.
int balasInventario(int infoMago) {

	int mascaraBalasInventario = 0x00FF0000;
	infoMago &= mascaraBalasInventario;
	unsigned int balasActuales = infoMago >> 16;

	return balasActuales;
}

// 2.- Hacer una funci�n que a�ada un n�mero de balas a las ya existentes.
//Para no hacer tan larga la funci�n de a�adir balas y hacerla m�s eficiente, se utiliza una funci�n auxiliar
//que actualiza y asigna el nuevo n�mero de balas que el usuario introduzca por pantalla.
// TOMAS: �Que pasa si antes hab�a 1 bala y se est�n poniendo 2 balas?�cuantas balas qudan en infoMago?
int setBalas(int infoMago, int balasTotales) {
	int mascaraBalasNuevas = balasTotales << 16;
	infoMago |= mascaraBalasNuevas;

	return balasTotales;
}

int anadirBalas(int infoMago, unsigned int balasNuevas) {
	int balasActuales = balasInventario(infoMago);
	unsigned int balasTotales = balasActuales + balasNuevas;

	if (balasTotales < 255) {
		infoMago = setBalas(infoMago, balasTotales);
	}
	else {
		infoMago = setBalas(infoMago, 255);
	}

	return infoMago;
}

// 3.- Hacer una funci�n que pasado un valor retorne si se tienen balas infinitas
//La opci�n de balas infinitas est� en el bit 1, que corresponder�a con el valor decimal de 2, es por eso que nuestra
//m�scara tiene un 2 en el bit byte 0. Al hacer una operaci�n AND, y compararla con el infoMago del main, podremos
//saber si el modo de balas infinitas est� activo o inactivo.
bool comprobarBalasInfinitas(int infoMago) {
	int mascaraBalasInfinitas = 0x00000002;

	infoMago &= mascaraBalasInfinitas;

	if (infoMago != 0) {
		return true;
	}
	else {
		return false;
	}
}

//4. - Hacer una funci�n ponga modo de balas infinitas.
//Funciona igual que el anterior pero en vez de una puerta AND se debe aplicar una puerta OR e invertir la m�scara.
//En esta funci�n no estoy muy seguro de que todo funcione como deber�a. Lo ideal ser�a que al pulsar sobre la opci�n
//4 del men�, la funci�n compruebe si ya est� activo el modo de balas infinitas y si no lo est�, lo active y viceversa
//si ya estuviera activo.
// TOMAS: Esto no est� bien. fifat� que estas poniendo a unos casi toda la informaci�n del mago.
//        repasal� y si tienes dudas preguntam� en tutorias.
int activarBalasInfinitas(int infoMago) {
	int mascaraBalasInfinitas = 0x00000002;
	infoMago |= mascaraBalasInfinitas;

	return infoMago;
}