// TOMAS: Mira los comentarios que te hago en el código (busca la palabra TOMAS en el fichero)
// TOMAS: Tienes que quitar los warnings.

// Tenemos un entero de 32 bits:
// 8 bits mayor peso la vida
// siguientes 8 bits: número de balas.
// Siguientes 4 bits: número de compañeros.
// bit 0: invulnerable
// bit 1: balas infinitas.
// bit 2: escudo.
// bit 3: berseker mode.

// Hacer la siguiente práctica.
// Para almacenar el estado de un personaje se utiliza la variable
// que está empaquetada según el formato de arriba.
// 1.- Hacer una función que pasado un valor retorne el número de balas
// 2.- Hacer una función que añada un número de balas a las ya existentes.
// 3.- Hacer una función que pasado un valor retorne si se tienen balas infinitas

// 4.- Hacer una función ponga modo de balas infinitas.

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
		printf_s("1. Mostrar número de balas\n");
		printf_s("2. Añadir balas\n");
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
			printf_s("Número de balas actual: %u\n", balasInventario(infoMago));
			printf_s("¿Cuántas balas quieres añadir?: ");
			scanf_s("%i", &balas);
			printf_s("\n");
			if (balas > 255) {
				printf_s("El máximo de balas que puedes llevar es 255\n");
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

//1. - Hacer una función que pasado un valor retorne el número de balas
//Creamos la máscara conveniente para que al realizar una operación AND y moverla 16 bits a la derecha (el sitio de las 
//balas) nos muestre el valor que deseamos. Se usa unsigned int para que al moverlo, no cambie el número de balas y no nos 
//muestre un valor erróneo. El uso de unsigned int a lo largo de toda la práctica se justifica por la misma razón.
int balasInventario(int infoMago) {

	int mascaraBalasInventario = 0x00FF0000;
	infoMago &= mascaraBalasInventario;
	unsigned int balasActuales = infoMago >> 16;

	return balasActuales;
}

// 2.- Hacer una función que añada un número de balas a las ya existentes.
//Para no hacer tan larga la función de añadir balas y hacerla más eficiente, se utiliza una función auxiliar
//que actualiza y asigna el nuevo número de balas que el usuario introduzca por pantalla.
// TOMAS: ¿Que pasa si antes había 1 bala y se están poniendo 2 balas?¿cuantas balas qudan en infoMago?
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

// 3.- Hacer una función que pasado un valor retorne si se tienen balas infinitas
//La opción de balas infinitas está en el bit 1, que correspondería con el valor decimal de 2, es por eso que nuestra
//máscara tiene un 2 en el bit byte 0. Al hacer una operación AND, y compararla con el infoMago del main, podremos
//saber si el modo de balas infinitas está activo o inactivo.
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

//4. - Hacer una función ponga modo de balas infinitas.
//Funciona igual que el anterior pero en vez de una puerta AND se debe aplicar una puerta OR e invertir la máscara.
//En esta función no estoy muy seguro de que todo funcione como debería. Lo ideal sería que al pulsar sobre la opción
//4 del menú, la función compruebe si ya está activo el modo de balas infinitas y si no lo está, lo active y viceversa
//si ya estuviera activo.
// TOMAS: Esto no está bien. fifaté que estas poniendo a unos casi toda la información del mago.
//        repasaló y si tienes dudas preguntamé en tutorias.
int activarBalasInfinitas(int infoMago) {
	int mascaraBalasInfinitas = 0x00000002;
	infoMago |= mascaraBalasInfinitas;

	return infoMago;
}