/*
 ============================================================================
 Name        : 3-2.c
 Author      : Agustin Lopez
 Description : Crear una función que pida el ingreso de un flotante y lo retorne.
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

float returnNumero();


int main(void)
{
	setbuf(stdout, NULL);

	printf("El numero ingresado es : %f", returnNumero());

	return 0;
}

float returnNumero()
{
	float numero;

	printf("ingrese el numero flotante");
	scanf("%f",&numero);

	return numero;
}
