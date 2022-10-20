/*
 ============================================================================
 Name        : Practica.c
 Author      : Agustin Lopez
 Description : en el classroom
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "nexo.h"
#include "voucher.h"
#define TAM 100


int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	int opcionInforme;
	int flag=0;
	int salir;
	int validarOpcion;
	eViaje viajes[TAM];
	eVoucher voucher[TAM];

	inicializar(viajes,TAM);
	voucherInicializar(voucher,TAM);
	do{
		printf("\n\t\tMENU DE OPCIONES\n\n"
			   "1. ALTA VIAJE\n"
			   "2. MODIFICAR VIAJE\n"
			   "3. BAJA VIAJE\n"
			   "4. LISTAR VIAJES\n"
			   "5. LISTAR TIPOS\n"
			   "6. ALTA VOUCHER\n"
			   "7. LISTAR VOUCHER\n"
			   "8. INFORMES\n"
				"9. SALIR\n\n");

		validarOpcion=utn_getNumero("INGRESE LA OPCION: ", "ERROR. ", 1, 9, 0, &opcion);

		if(validarOpcion == 0)
		{
			switch(opcion)
			{
				case 1:
					altaViajes(viajes,TAM);
					flag=1;
					break;

				case 2:
					if(flag==1)
					{
						menuModificar(viajes,TAM);
					}
					break;

				case 3:
					if(flag==1)
					{
						bajaViaje(viajes,TAM);
					}
					break;

				case 4:
					if(flag==1)
					{
						imprimirTodos(viajes,TAM);
					}
					break;
				case 5:
						listarTipo();//queda vacio xq es un void
					break;
				case 6:
					if(flag==1)
					{
						if(flag == 1)
						{
							nexo_alta(viajes, TAM, voucher, TAM);
						}
						else
						{
							printf("\nNO ES POSIBLE ACTIVAR UN VOUCHER SIN HABER DADO DE ALTA UN VIAJE PRIMERO.\n");
						}
					}
					break;
				case 7:
					if(flag==1)
					{
						eVoucher_imprimirTodos(voucher,TAM);
					}
					break;
				case 8:
					if(flag == 1)
					{
						//informe tres sumar todos los precios que van a cierto destino
						printf("\nINFORMES\n"
							   "1. MOSTRAR VIAJES DE UN TIPO SELECCIONADO\n"
							   "2. MOSTRAR TODOS LOS VOUCHERS EFECTUADOS EN UNA FECHA RELACIONADA.\n"
							   "3. INFORMAR IMPORTE TOTAL DE LOS VIAJES REALIZADOS A UN CIERTO DESTINO\n"
							   "4. INFORMAR IMPORTE TOTAL DE TODOS LOS VOUCHERS DE UN TIPO EN UNA FECHA SELECCIONADA\n\n");
						utn_getNumero("SELECCIONE EL INFORME QUE DESEA VER: ", "ERROR. ", 1, 4, 3, &opcionInforme);

						switch(opcionInforme)
						{
							case 1:
								eViaje_imprimirPorTipo(viajes, TAM);
							break;

							case 2:
								eVoucher_imprimirPorFecha(voucher, TAM);
							break;

							case 3:
								nexo_imprimirImportePorDestino(voucher, TAM, viajes, TAM);
							break;

							case 4:
								nexo_imprimirImportePorTipoFecha(voucher, TAM, viajes, TAM);
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
