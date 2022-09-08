/*
 ============================================================================
 Name        : Agustin Lopez
 Description : Realizar un Menú que muestre las opciones:
        a-Iniciar
        b-Procesar
        c-Finalizar
        d-Salir
Nota:
-Antes de salir preguntar si "esta seguro que desea salir?s/n"
-Si Procesa sin haber Iniciado, debe avisar "Debe Iniciar antes de Procesar" y no deja continuar
-Si se Finaliza antes de Iniciar debe avisar "Debe Iniciar antes de Finalizar" y no deja continuar
-Si se Finaliza antes de Procesar debe avisar "Debe Procesar antes de Finalizar" y no deja continuar
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecas.h"



int main()
{
	setbuf(stdout, NULL);
	char opcion;
	char opcionSalir;
	int flagIniciar = 0;
	int flagProcesar = 0;
	int flagSalir = 0;

	do
	{
		opcion = menu();

		switch(opcion)
		{
		case 'a':
			printf("\n\nSE HA INCIADO CORRECTAMENTE...\n\n");
			flagIniciar = 1;
			break;
		case 'b':
			if(flagIniciar != 1)
			{
				printf("\nDebe Iniciar antes de Procesar.\n");
			}
			else
			{
				printf("\n\nSE HA PROCESADO CORRECTAMENTE...\n\n");
				flagProcesar = 1;
			}
			break;
		case 'c':
			if(flagIniciar != 1)
			{
				printf("\nDebe Iniciar antes de Finalizar.\n");
			}
			if(flagProcesar != 1)
			{
				printf("\nDebe Procesar antes de Finalizar\n");
			}
			else
			{
				printf("\n\nSE HA FINALIZADO CORRECTAMENTE...\n\n");
			}
			break;
		case 'd':
			opcionSalir = salir();

			if(opcionSalir == 's')
			{
				flagSalir = 1;
			}

			break;
		default:
			printf("Error - la opcion ingresada no existe.");
		}

	}while(flagSalir == 0);

	printf("EL PROGRAMA SE CERRO...");
	return 0;
}
