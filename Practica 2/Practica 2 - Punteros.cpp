// TOMAS: Bastante bien el ejercicio. busca la cadena "TOMAS" en el fichero para ver comentarios.
// TOMAS: Tienes que quitar los warnings.
//

#pragma warning(disable:4710)

void bytesDeEntero(int);
void mayorEntero();
void mayorChar();
void byteMayor();
void insideOutHola();

int main()
{
	int num = 23658910;
	printf_s("Ejercicio 1\n");
	bytesDeEntero(num);
	printf_s("Ejercicio 2\n");
	mayorEntero();
	printf_s("Ejercicio 3\n");
	mayorChar();
	printf_s("Ejercicio 4\n");
	byteMayor(); 
	printf_s("Ejercicio 5\n");
	insideOutHola();

	return 0;
}

// PRÁCTICAS.
// 1.- Dado un entero obtener por separado cada uno de sus bytes usando operaciones de punteros.
void bytesDeEntero(int num) {
	int *p = &num;

	unsigned char *punteroChar = reinterpret_cast <unsigned char *>(p);
	const unsigned char byte1 = *punteroChar; //este byte no es modificable debido al const

	punteroChar = reinterpret_cast<unsigned char *>(p) + 1;
	const unsigned char byte2 = *punteroChar; //este byte no es modificable debido al const

	punteroChar = reinterpret_cast<unsigned char *>(p) + 2;
	const unsigned char byte3 = *punteroChar; //este byte no es modificable debido al const

	punteroChar = reinterpret_cast<unsigned char *>(p) + 3;
	const unsigned char byte4 = *punteroChar; //este byte no es modificable debido al const

	printf_s("Nuestro numero entero: 0x%x\n\n", num);
	printf_s("Primer byte: 0x%02x\n", byte1);
	printf_s("Segundo byte: 0x%02x\n", byte2);
	printf_s("Tercer byte: 0x%02x\n", byte3);
	printf_s("Cuarto byte: 0x%02x\n\n", byte4);
}


// 2.- Dada la tabla de enteros int tabla[] = {1, 3, 2, 5, 3, 0xFFFFFFFF, 2}
//		 Realizar código que obtenga el entero mayor usando aritmética de punteros.

void mayorEntero() {
	int tabla[] = { 1, 4, 2, 5, 3, static_cast<int>(0xFFFFFFFF), 2, 10 }; //static_cast para la conversión implicita del tipo int sobre el numero hexadecimal que lo considera como unsigned int

	const int *tablaP = tabla; //la tabla no es modificable
  // TOMAS: Es mejor establecer como mayor el primer número de la tabla, el mayor prodría no ser el cero si todos los caracteres son negativos
	int mayor = tablaP;
	unsigned int tamanioT = sizeof(tabla)/sizeof(tabla[0]);

	printf_s("Tamaño tabla: %d\n", tamanioT);

	for (unsigned int i = 0; i < tamanioT; i++) {

		if (mayor < *tablaP) {
			mayor = *tablaP;
		}

		tablaP++;
	}

	printf_s("El mayor es el: %d\n\n", mayor);

}

// 3.- Dada la tabla de caracteres char tabla[] = {'a', 'z', 'f', 'g', '2'}
//		 Realizar código que obtenga el caracter mayor usando aritmética de punteros.

void mayorChar() {
	char tabla[] = { 'a', 'z', 'f', 'g', '2'};

	const char *tablaP = tabla; //la tabla no es modificable
  // TOMAS: Es mejor establecer como mayor el primer número de la tabla, el mayor prodría no ser el cero si todos los caracteres son negativos
	char mayor = tablaP;
	int tamanioT = sizeof(tabla) / sizeof(char);

	printf_s("Tamaño tabla: %d\n", tamanioT);

	for (int i = 0; i < tamanioT; i++) {

		if (mayor < *tablaP) {
			mayor = *tablaP;
		}

		tablaP++;
	}

	printf_s("El mayor es el: %c\n\n", mayor);

}

// 4.- Igual que el 2 pero que obtenga la posición del byte mayor.
void byteMayor() {
	int tabla[] = { 1, 3, 2, 5, 3, static_cast<int>(0xFFFFFFFF), 2 }; //static_cast para la conversión implicita del tipo int sobre el numero hexadecimal que lo considera como unsigned int
	unsigned char *tablaP = reinterpret_cast<unsigned char *>(tabla); //estamos asignando un unsigned char a un tipo int. El reinterpret_cast nos permite esta asignación porque se tratan de
																	  //variables de naturaleza diferente	

	unsigned char *mayor = tablaP;
	int tamanioT = sizeof(tabla) / sizeof(char);

	for (int i = 0; i < tamanioT; i++) {

		if (*mayor > *tablaP) {
			mayor = tablaP;
		}

		tablaP++;
	}

	printf_s("El mayor es el: 0x%x\n\n", reinterpret_cast<unsigned int>(mayor));

}


// 5.- Generar código que dada una cadena le de la vuelta: ejmp "hola" -> "aloh"
void insideOutHola() {
	char cadena[4] = { 'h','o', 'l', 'a' };
	char *cadenaP;

	for (int i = 3; i >= 0; i--) {
		cadenaP = &cadena[i];
		printf_s("%c", *cadenaP);
	}
}