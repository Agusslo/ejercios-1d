/*
 ============================================================================
 Name        : Ejercicio3-5.c
 Author      : Agustin Lopez
	Description : 3-5
Realizar un programa en donde se puedan utilizar los prototipos de la
función Restar en sus 4 combinaciones.
- int Restar1(int, int);
- int Restar2(void);
- void Restar3(int, int);
- void Restar4(void);
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int restar1(int, int);
int restar2();
void restar3(int, int);
void restar4();

int main() {
	setbuf(stdout, NULL);

	printf("Funcion restar1 : la resta es %d", restar1(10, 5));

	printf("\nFuncion restar2 : la resta es %d", restar2());

	restar3(50, 20);

	restar4();

	return 0;
}


int restar1(int primerNumero, int segundoNumero)
{
	int restar;

	restar = primerNumero - segundoNumero;

	return restar;
}

int restar2()
{
	int restar;
	int primerNumero = 10;
	int segundoNumero = 4;

	restar = primerNumero - segundoNumero;

	return restar;
}

void restar3(int primerNumero, int segundoNumero)
{
	printf("\nFuncion restar3 : la resta es %d", (primerNumero - segundoNumero));
}

void restar4()
{

	int primerNumero = 40;
	int segundoNumero = 10;

	printf("\nFuncion restar4 : la resta es %d", (primerNumero - segundoNumero));
}
