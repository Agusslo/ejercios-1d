#include "hojaServicio.h"
#define vacio 1
#define lleno 0

int eHojaServicio_getID(void)
{
	static int idIncremental = 20000; //20k
	static int rtn;

	rtn = idIncremental++;

	return rtn;
}

int servicioInicializar(eHojaServicio servicio[],int tam)
{
	//creo espacio vacio
	int retorno=-1;
	if(servicio!=NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			servicio[i].isEmpty=vacio;
			retorno=0;
		}
	}
	return retorno;
}

int eHojaServicio_obtenerIndexLibre(eHojaServicio lista[], int TAM)
{
	//encuentro espacio vacio
	int rtn = -1;
	int i;

	///SI EXISTE EL lista Y EL LIMITE ES VALIDO
	if (lista != NULL && TAM > 0)
	{
		//RECORRO EL lista
		for (i = 0; i < TAM; i++)
		{
			///PREGUNTA POR EL ESTADO "LIBRE"
			if (lista[i].isEmpty == vacio)
			{
				///OBTIENE EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

int eHojaServicio_buscarPorID(eHojaServicio lista[], int TAM, int ID)
{
	int rtn = -1;
	int i;

	///SI EXISTE EL lista Y EL LIMITE ES VALIDO
	if (lista != NULL && TAM > 0)
	{
		///RECORRE EL lista
		for (i = 0; i < TAM; i++)
		{
			///BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (lista[i].idHoja == ID && lista[i].isEmpty == lleno)
			{
				///SI ENCONTRO EL ID
				///DEVUELVE EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

eHojaServicio eHojaServicio_ingresarDatos(void)
{
	eHojaServicio auxiliar;

	utn_getString("INGRESE DESCRIPCION: ", "ERROR. ", 3, TAM_CHAR, auxiliar.descripcion);
	utn_getNumero("INGRESE PRECIO DEL AUTO: ", "ERROR. ", 1, 999999, 3, &auxiliar.precioServicio);
	//fecha
	printf("\nFECHA\n");
	utn_getNumero("INGRESE DIA: ", "ERROR. ", 1, 31, 3, &auxiliar.fecha.dia);
	utn_getNumero("INGRESE MES: ", "ERROR. ", 1, 31, 3, &auxiliar.fecha.mes);
	utn_getNumero("INGRESE AÑO: ", "ERROR. ", 1, 2025, 3, &auxiliar.fecha.anio);

	return auxiliar;
}

void eHojaServicio_imprimirUno(eHojaServicio servicio)
{
	printf("|%4d|%-15s|%-10d|", servicio.idHoja, servicio.descripcion, servicio.precioServicio);
	printf("%2d/%1d/%4d|\n",servicio.fecha.dia, servicio.fecha.mes, servicio.fecha.anio);
}

int eHojaServicio_imprimirTodos(eHojaServicio lista[], int TAM)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	if (lista != NULL && TAM > 0)
	{
		puts("\n\t\t LISTA DE VEHICULOS");
		puts("+------------------------------------------+");
		puts("|  ID |  DESCRIPCION  |  PRECIO  |  FECHA  |");
		puts("+------------------------------------------+");

		for (i = 0; i < TAM; i++)
		{
			if (lista[i].isEmpty == lleno)
			{
				eHojaServicio_imprimirUno(lista[i]);
				puts("+------------------------------------------+");
				cantidad++;
			}
		}
	}

	if (cantidad > 0)
	{
		rtn = 1;
	}

	return rtn;
}

int eHojaServicio_imprimirPorFecha(eHojaServicio lista[], int TAM)
{
	int i;
	int rtn = 0;
	int cantidad = 0;
	int dia, mes, anio;

	if (lista != NULL && TAM > 0)
	{
		puts("");
		utn_getNumero("INGRESE DIA: ", "ERROR. ", 1, 31, 3, &dia);
		utn_getNumero("INGRESE MES: ", "ERROR. ", 1, 12, 3, &mes);
		utn_getNumero("INGRESE AÑO: ", "ERROR. ", 1980, 2025, 3, &anio);

		puts("\n\t\t LISTA DE VEHICULOS");
		puts("+------------------------------------------+");
		puts("|  ID |  DESCRIPCION  |  PRECIO  |  FECHA  |");
		puts("+------------------------------------------+");

		for (i = 0; i < TAM; i++)
		{
			if (lista[i].isEmpty == lleno)
			{
				if(lista[i].fecha.dia == dia && lista[i].fecha.mes == mes && lista[i].fecha.anio == anio)
				{
					eHojaServicio_imprimirUno(lista[i]);
					puts("+------------------------------------------+");
					cantidad++;
				}
			}
		}
	}

	if (cantidad > 0)
	{
		rtn = 1;
	}

	return rtn;
}

int eHojaServicio_acumularPrecio(eHojaServicio lista[], int TAM, int* precioServicio)
{
	int rtn = -1;
	int acumuladorPrecio = 0;

	if (lista != NULL && TAM > 0)
	{
		for (int i = 0; i < TAM; i++)
		{
			if (lista[i].isEmpty == lleno)
			{
				acumuladorPrecio += lista[i].precioServicio;
				rtn = 1;
			}
		}
	}

	*precioServicio = acumuladorPrecio;

	return rtn;
}
