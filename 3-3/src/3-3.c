/*
 ============================================================================
 Name        : 3-3.c
 Author      : Agustin Lopez
 Description : 3-3
	Crear una función que permita determinar si un número es par o no. La
función retorna 1 en caso afirmativo y 0 en caso contrario. Probar en el main.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int esPar(int numero);

int main() {
	setbuf(stdout, NULL);
	int numero;

	printf("Ingrese un numero : ");
	scanf("%d", &numero);

	if(esPar(numero) == 1)
	{
		printf("El numero %d, es par.", numero);
	}
	else
	{
		printf("El numero %d, es impar.", numero);
	}

	return 0;
}

int esPar(int numero)
{
	if(numero % 2 == 0)
	{
		return 1;
	}

	return 0;
}
