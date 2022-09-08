#include <stdio.h>
#include <stdlib.h>
#include "bibliotecas.h"

char menu()
{
	char opcion;

	fflush(stdin);
	printf("- MENU -\n");
	printf("a - Iniciar\nb - Procesar\nc - Finalizar\nd- Salir : ");
	scanf("%c", &opcion);

	opcion = validarOpcion(opcion);

	return opcion;
}

char validarOpcion(char  opcion)
{
	while(opcion != 'a' && opcion != 'b' && opcion != 'c' && opcion != 'd')
	{
		fflush(stdin);
		printf("Error - Ingrese una opcion valida : ");
		scanf("%c", &opcion);
	}

	return opcion;
}

char salir()
{
	char opcion;

	fflush(stdin);
	printf("Esta seguro que desea salir? s/n : ");
	scanf("%c", &opcion);

	opcion = validarSalir(opcion);

	return opcion;
}

char validarSalir(char opcion)
{
	while(opcion != 's' && opcion != 'n')
	{
		fflush(stdin);
		printf("Error - Ingrese una opcion valida : ");
		scanf("%c", &opcion);
	}

	return opcion;
}
