#include "nexo.h"
#define vacio 1//libre
#define lleno 0//ocupado


int nexo_alta(eViaje listaViajes[], int TAM_VIAJES, eVoucher listaVoucher[], int TAM_VOUCHERS)
{
	int rtn = -1;
	int auxIdViaje;
	eVoucher auxVoucher;
	int idEncontrado;

	///BUSCO ESPACIO EN lista
	int index = eVoucher_obtenerIndexLibre(listaVoucher, TAM_VOUCHERS);

	imprimirTodos(listaViajes, TAM_VIAJES);
	utn_getNumero("\nPARA HABILITAR UN VOUCHER, SELECCIONE UN VIAJE INGRESANDO SU ID: ", "ERROR. ", 100, 1000, 3, &auxIdViaje);
	idEncontrado = buscarId(listaViajes, TAM_VIAJES);

	while (idEncontrado == -1)
	{
		puts("\nNO EXISTE ID.");
		utn_getNumero("\nPARA HABILITAR UN VOUCHER, SELECCIONE UN VIAJE INGRESANDO SU ID: ", "ERROR. ", 100, 1000, 3, &auxIdViaje);
	}

	if (index != -1 && idEncontrado != -1)  //si tengo posicion de array libre
	{
		///PIDO DATOS - CARGO Products AUXILIAR
		auxVoucher = eVoucher_ingresarDatos();

		///SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxVoucher.idVoucher = eVoucher_getID();

		///CAMBIO SU ESTADO A "OCUPADO"
		auxVoucher.isEmpty = lleno;

		///ASIGNO ID VIAJE EN ESTRUCTURA VOUCHER
		auxVoucher.viajeId = auxIdViaje;

		///SETEO EL lista CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		listaVoucher[index] = auxVoucher;

		///RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = index;
	}

	return rtn;
}

int nexo_imprimirImportePorDestino(eVoucher listaVoucher[], int TAM_VOUCHER, eViaje listaViaje[], int TAM_VIAJE)
{
	int rtn = -1;
	int precioAcumulado;
	char destinoABuscar[TAM_CHAR];

	if(listaViaje != NULL && TAM_VIAJE > 0 && listaVoucher != NULL && TAM_VOUCHER > 0)
	{
		utn_getString("\nINGRESE EL DESTINO A BUSCAR: ", "ERROR. ", 3, TAM_CHAR, destinoABuscar);

		for(int i = 0; i < TAM_VIAJE; i++)
		{
			if(stricmp(listaViaje[i].destino, destinoABuscar) == 0)
			{
				eVoucher_acumularPrecio(listaVoucher, TAM_VOUCHER, &precioAcumulado);
				printf("\nIMPORTE TOTAL DE LOS VOUCHERS REALIZADOS CON DESTINO HACIA %s ES DE $%d\n", destinoABuscar, precioAcumulado);
			}
		}
	}

	return rtn;
}

int nexo_imprimirImportePorTipoFecha(eVoucher listaVoucher[], int TAM_VOUCHER, eViaje listaViaje[], int TAM_VIAJE)
{
	int rtn = -1;
	int precioAcumulado;
	int dia, mes, anio;
	int idABuscar;
	int idTipoEcontrado;
	char tipo[TAM_CHAR];

	if(listaViaje != NULL && TAM_VIAJE > 0 && listaVoucher != NULL && TAM_VOUCHER > 0)
	{
		utn_getNumero("\nINGRESE EL TIPO DE VIAJE (1. AEREO | 2. TERRESTRE | 3. MARITIMO): ", "ERROR. ", 1, 3, 3, &idABuscar);
		utn_getNumero("INGRESE DIA DE VUELO: ", "ERROR. ", 1, 31, 3, &dia);
		utn_getNumero("INGRESE MES DE VUELO: ", "ERROR. ", 1, 12, 3, &mes);
		utn_getNumero("INGRESE AÑO DE VUELO: ", "ERROR. ", 2022, 2025, 3, &anio);

		for(int i = 0; i < TAM_VIAJE; i++)
		{
			for(int j = 0; j < TAM_VOUCHER; j++)
			{
				idTipoEcontrado = eViaje_buscarPorTipo(listaViaje, TAM_VIAJE, idABuscar);

				if(idTipoEcontrado != -1)
				{
					if(listaViaje[i].tipoId.idTipo == idABuscar &&
				       listaVoucher[j].fecha.dia == dia &&
					   listaVoucher[j].fecha.mes == mes &&
					   listaVoucher[j].fecha.anio == anio)
					{
						eVoucher_acumularPrecio(listaVoucher, TAM_VOUCHER, &precioAcumulado);

						switch(idTipoEcontrado)
						{
							case 1:
								strcpy(tipo, "AEREO");
							break;

							case 2:
								strcpy(tipo, "TERRESTRE");
							break;

							case 3:
								strcpy(tipo, "MARITIMO");
							break;
						}
					}
				}
			}
		}
		printf("\nIMPORTE TOTAL DE LOS VOUCHERS REALIZADOS CON TIPO %s ES DE $%d PLANIFICADO EL %2d/%1d/%4d\n", tipo, precioAcumulado, dia, mes, anio);
		rtn = 1;
	}

	return rtn;
}

