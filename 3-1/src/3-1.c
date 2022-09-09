/*
 ============================================================================
 Name        : Ejercicio3-1.c
 Author      : Agustin Lopez
 Description :3-1
	Crear una función que muestre por pantalla el número entero que
recibe como parámetro.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void mostrarNumero(int numero);

int main() {

	setbuf(stdout, NULL);
	int numero;

	printf("Ingrese un numero : ");
	scanf("%d", &numero);

	mostrarNumero(numero);

	return 0;
}

void mostrarNumero(int numero){

	printf("El numero es : %d", numero);
}
