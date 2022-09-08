/*
============================================================================
 Name        : Agustin Lopez
 Description :	Ejercicio 2-2: Ingresar números enteros, hasta que el usuario pida. Mostrar:
a) El promedio de los positivos y su mínimo.
b) El promedio de los negativos y su máximo.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int main(void) {

	setbuf(stdout, NULL);

	int numeroIngresado;
	float promedioNegativos;
	float promedioPositivos;
	int positivoMinimo;
	int negativoMaximo;
	char continuar;
	int flagPositivos=0;
	int flagNegativos=0;
	int acumuladorPositivo=0;
	int acumuladorNegativo=0;

	do
	{

		printf("Ingrese un numero:");
		scanf("%d",&numeroIngresado);

		if(numeroIngresado >0)
		{
			acumuladorPositivo+=numeroIngresado;
			if(numeroIngresado < positivoMinimo || flagPositivos==0 )
			{
				positivoMinimo=numeroIngresado;

			}
			flagPositivos++;
		}
		else
		{
			acumuladorNegativo+=numeroIngresado;
			if(numeroIngresado>negativoMaximo || flagNegativos==0)
			{
				negativoMaximo=numeroIngresado;

			}
			flagNegativos++;
		}



		// salida del bucle
		printf("Desea continuar 's' o 'n' :");
		fflush(stdin);
		scanf("%c",&continuar);
		//validar salida
		while(continuar!='s' && continuar!='n')
		{
			printf("ERROR(Ingrese 's' para continuar o 'n' para terminar)\n"
					"Desea continuar 's' o 'n' :");
			fflush(stdin);
			scanf("%c",&continuar);
		}

	}while(continuar!='n');

	promedioNegativos= acumuladorNegativo/flagNegativos;
	promedioPositivos=acumuladorPositivo/flagPositivos;

	printf("El promedio de los positivos fue: %.2f\n"
			"el numero positivo mas chico: %d\n"
			"El promedio de los negativos fue: %.2f\n"
			"El numero negativo mas grande: %d"
			,promedioPositivos,positivoMinimo,promedioNegativos,negativoMaximo);

	return 0;
}


