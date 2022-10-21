#include "nexo.h"
#define vacio 1//libre
#define lleno 0//ocupado


int nexo_alta(eVehiculo listaVehiculos[], int TAM_VEHICULO, eHojaServicio listaServicio[], int TAM_SERVICIO)
{
	int rtn = -1;
	int auxIdVehiculo;
	eHojaServicio auxServicio;
	int idEncontrado;

	///BUSCO ESPACIO EN lista
	int index = eHojaServicio_obtenerIndexLibre(listaServicio, TAM_SERVICIO);

	imprimirTodos(listaVehiculos, TAM_VEHICULO);
	utn_getNumero("\nPARA HABILITAR UN VEHICULO, SELECCIONE UN AUTO INGRESANDO SU ID: ", "ERROR. ", 100, 1000, 3, &auxIdVehiculo);
	idEncontrado = buscarId(listaVehiculos, TAM_VEHICULO);

	while (idEncontrado == -1)
	{
		puts("\nNO EXISTE ID.");
		utn_getNumero("\nPARA HABILITAR UN VEHICULO, SELECCIONE UN AUTO INGRESANDO SU ID: ", "ERROR. ", 100, 1000, 3, &auxIdVehiculo);
	}

	if (index != -1 && idEncontrado != -1)  //si tengo posicion de array libre
	{
		///PIDO DATOS - CARGO Products AUXILIAR
		auxServicio = eHojaServicio_ingresarDatos();

		///SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxServicio.idHoja = eHojaServicio_getID();

		///CAMBIO SU ESTADO A "OCUPADO"
		auxServicio.isEmpty = lleno;

		auxServicio.vehiculoId = auxIdVehiculo;

		///SETEO EL lista CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		listaServicio[index] = auxServicio;

		///RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = index;
	}

	return rtn;
}

int nexo_imprimirImporteVehiculo(eHojaServicio listaServicio[], int TAM_SERVICIO, eVehiculo listaVehiculo[], int TAM_VEHICULO)
{
	int rtn = -1;
	int precioAcumulado;
	char autoABuscar[TAM_CHAR];

	if(listaVehiculo != NULL && TAM_VEHICULO > 0 && listaServicio != NULL && TAM_SERVICIO > 0)
	{
		utn_getString("\nINGRESE EL VEHICULO A BUSCAR: ", "ERROR. ", 3, TAM_CHAR, autoABuscar);

		for(int i = 0; i < TAM_VEHICULO; i++)
		{
			if(stricmp(listaVehiculo[i].idVehiculo, autoABuscar) == 0)
			{
				eHojaServicio_acumularPrecio(listaServicio, TAM_SERVICIO, &precioAcumulado);
				printf("\nIMPORTE TOTAL DE LOS SERVICIOS REALIZADOS de un tipo de auto %s ES DE $%d\n", autoABuscar, precioAcumulado);
			}
		}
	}

	return rtn;
}

int nexo_imprimirImportePorTipoFecha(eHojaServicio listaServicio[], int TAM_SERVICIO, eVehiculo listaVehiculo[], int TAM_VEHICULO)
{
	int rtn = -1;
	int precioAcumulado;
	int dia, mes, anio;
	int idABuscar;
	int idTipoEcontrado;
	char tipo[TAM_CHAR];

	if(listaVehiculo != NULL && TAM_VEHICULO > 0 && listaServicio != NULL && TAM_SERVICIO > 0)
	{
		utn_getNumero("\nINGRESE EL TIPO DE AUTO(1. SEDAN 3 ptas | 2. SEDAN 5 ptas | 3. CAMIONETA): ", "ERROR. ", 1, 3, 3, &idABuscar);
		utn_getNumero("INGRESE DIA: ", "ERROR. ", 1, 31, 3, &dia);
		utn_getNumero("INGRESE MES: ", "ERROR. ", 1, 12, 3, &mes);
		utn_getNumero("INGRESE AÑO: ", "ERROR. ", 2022, 2025, 3, &anio);

		for(int i = 0; i < TAM_VEHICULO; i++)
		{
			for(int j = 0; j < TAM_SERVICIO; j++)
			{
				idTipoEcontrado = eVehiculo_buscarPorTipo(listaVehiculo, TAM_VEHICULO, idABuscar);

				if(idTipoEcontrado != -1)
				{
					if(listaVehiculo[i].tipoId.idTipo == idABuscar &&
						listaServicio[j].fecha.dia == dia &&
						listaServicio[j].fecha.mes == mes &&
						listaServicio[j].fecha.anio == anio)
					{
						eHojaServicio_acumularPrecio(listaServicio, TAM_SERVICIO, &precioAcumulado);

						switch(idTipoEcontrado)
						{
							case 1:
								strcpy(tipo, "SEDAN 3ptas");
							break;

							case 2:
								strcpy(tipo, "SEDAN 5ptas");
							break;

							case 3:
								strcpy(tipo, "CAMIONETA");
							break;
						}
					}
				}
			}
		}
		printf("\nIMPORTE TOTAL DE LAS HOJAS DE SERVICIO REALIZADOS CON TIPO %s ES DE $%d PLANIFICADO EL %2d/%1d/%4d\n", tipo, precioAcumulado, dia, mes, anio);
		rtn = 1;
	}

	return rtn;
}

