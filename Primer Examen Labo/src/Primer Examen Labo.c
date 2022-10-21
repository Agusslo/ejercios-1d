/*
 ============================================================================
 Name        : Primer.c
 Author      : Agustin Lopez
 Description : Primer Examen laboratorio
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define TAM 100


int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int opcionInforme;
	int validarOpcion;
	int flag=0;
	int salir;
	eVehiculo vehiculo[TAM];
	eHojaServicio servicio[TAM];


	do{
		printf("\n\t\tMENU DE OPCIONES\n\n"
					   "1. ALTA VEHICULO\n"
					   "2. MODIFICAR VEHICULO\n"
					   "3. BAJA VEHICULO\n"
					   "4. LISTAR VEHICULO\n"
					   "5. LISTAR TIPOS\n"
					   "6. ALTA HOJA DE SERVICIO:\n"
					   "7. LISTAR HOJAS DE SERVICIO\n"
					   "8. INFORMES\n"
						"9. SALIR\n\n");
		validarOpcion=utn_getNumero("INGRESE LA OPCION: ", "ERROR. ", 1, 9, 0, &opcion);

		if(validarOpcion == 0)
		{
			switch(opcion)
			{
				case 1:
					altaViajes(vehiculo,TAM);
					flag=1;
					break;
				case 2:
					if(flag==1)
					{
						menuModificar(vehiculo,TAM,servicio);
					}
					break;
				case 3:
					if(flag==1)
					{
						bajaViaje(vehiculo,TAM);
					}
					break;
				case 4:
					if(flag==1)
					{
						imprimirTodos(vehiculo,TAM);
					}
					break;
				case 5:
					if(flag==1)
					{
						listarTipo();
					}
					break;
				case 6:
					if(flag==1)
					{
						nexo_alta(vehiculo, TAM, servicio, TAM);
					}
					else
					{
						printf("\nNO ES POSIBLE ACTIVAR UN VEHICULO SIN HABER DADO DE ALTA UN AUTO PRIMERO.\n");
					}
					break;
				case 7:
					if(flag==1)
					{
						eHojaServicio_imprimirTodos(servicio,TAM);
					}
					break;
				case 8:
					if(flag==1)
					{
						printf("\nINFORMES\n"
					   "1. MOSTRAR VEHICULOS DE UN TIPO SELECCIONADO\n"
					   "2. MOSTRAR TODOS LAS HOJAS DE SERVICIO EFECTUADOS EN UNA FECHA SELECIONADA.\n"
					   "3. INFORMAR IMPORTE TOTAL DE LAS HOJAS DE SERVICIO REALIZADOS EN UN VEHICULO RELACIONADO\n"
					   "4. INFORMAR IMPORTE TOTAL DE TODAS LAS HOJAS DE SERVICIO DE UN TIPO EN UNA FECHA SELECCIONADA\n\n");
						utn_getNumero("SELECCIONE EL INFORME QUE DESEA VER: ", "ERROR. ", 1, 4, 3, &opcionInforme);

						switch(opcionInforme)
						{
							case 1:
								eVehiculo_imprimirPorTipo(vehiculo,TAM);
								break;
							case 2:
								eHojaServicio_imprimirPorFecha(servicio,TAM);
								break;
							case 3:
								nexo_imprimirImporteVehiculo(servicio,TAM,vehiculo,TAM);
								break;
							case 4:
								nexo_imprimirImportePorTipoFecha(servicio,TAM,vehiculo,TAM);
								break;
							default:
								printf("ingrese opcion valida");
								break;
						}
					}
					break;
				case 9:
					salir = funcionContinuar("\nDESEA SALIR? (s/n): ", "ERROR. ");
					break;
			}
		}
	}while(salir!=1);

	return 0;
}
