#include "voucher.h"
#define vacio 1//libre
#define lleno 0//ocupado

int eVoucher_getID(void)
{
	///INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION sProducts_getID();
	static int idIncremental = 20000; //20k
	static int rtn;

	rtn = idIncremental++;

	return rtn;
}


int voucherInicializar(eVoucher voucher[],int tam)///agarra todos los arrays y isempty y los pone vacio(en 0), sin importar quien sea
{
	//creo espacio vacio
	int retorno=-1;
	if(voucher!=NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			voucher[i].isEmpty=vacio;
			retorno=0;
		}
	}
	return retorno;
}

int eVoucher_obtenerIndexLibre(eVoucher lista[], int TAM)
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

int eVoucher_buscarPorID(eVoucher lista[], int TAM, int ID)
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
			if (lista[i].idVoucher == ID && lista[i].isEmpty == lleno)
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

eVoucher eVoucher_ingresarDatos(void)
{
	eVoucher auxiliar;

	utn_getString("INGRESE DESCRIPCION: ", "ERROR. ", 3, TAM_CHAR, auxiliar.descripcion);
	utn_getNumero("INGRESE PRECIO DEL VUELO: ", "ERROR. ", 1, 999999, 3, &auxiliar.precioViaje);
	//fecha
	printf("\nFECHA DE VUELO\n");
	utn_getNumero("INGRESE DIA DE VUELO: ", "ERROR. ", 1, 31, 3, &auxiliar.fecha.dia);
	utn_getNumero("INGRESE MES DE VUELO: ", "ERROR. ", 1, 31, 3, &auxiliar.fecha.mes);
	utn_getNumero("INGRESE AÑO DE VUELO: ", "ERROR. ", 1, 2025, 3, &auxiliar.fecha.anio);

	return auxiliar;
}

void eVoucher_imprimirUno(eVoucher voucher)
{
	printf("|%4d|%-15s|%-10d|", voucher.idVoucher, voucher.descripcion, voucher.precioViaje);
	printf("%2d/%1d/%4d|\n",voucher.fecha.dia, voucher.fecha.mes, voucher.fecha.anio);
}

int eVoucher_imprimirTodos(eVoucher lista[], int TAM)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	if (lista != NULL && TAM > 0)
	{
		puts("\n\t\t LISTA DE VOUCHERS");
		puts("+------------------------------------------+");
		puts("|  ID |  DESCRIPCION  |  PRECIO  |  FECHA  |");
		puts("+------------------------------------------+");

		for (i = 0; i < TAM; i++)
		{
			if (lista[i].isEmpty == lleno)
			{
				eVoucher_imprimirUno(lista[i]);
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

int eVoucher_imprimirPorFecha(eVoucher lista[], int TAM)
{
	int i;
	int rtn = 0;
	int cantidad = 0;
	int dia, mes, anio;

	if (lista != NULL && TAM > 0)
	{
		puts("");
		utn_getNumero("INGRESE DIA DE VUELO: ", "ERROR. ", 1, 31, 3, &dia);
		utn_getNumero("INGRESE MES DE VUELO: ", "ERROR. ", 1, 12, 3, &mes);
		utn_getNumero("INGRESE AÑO DE VUELO: ", "ERROR. ", 2022, 2025, 3, &anio);

		puts("\n\t\t LISTA DE VOUCHERS");
		puts("+------------------------------------------+");
		puts("|  ID |  DESCRIPCION  |  PRECIO  |  FECHA  |");
		puts("+------------------------------------------+");

		for (i = 0; i < TAM; i++)
		{
			if (lista[i].isEmpty == lleno)
			{
				if(lista[i].fecha.dia == dia && lista[i].fecha.mes == mes && lista[i].fecha.anio == anio)
				{
					eVoucher_imprimirUno(lista[i]);
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

int eVoucher_acumularPrecio(eVoucher lista[], int TAM, int* precioAcumulado)
{
	int rtn = -1;
	int acumuladorPrecio = 0;

	if (lista != NULL && TAM > 0)
	{
		for (int i = 0; i < TAM; i++)
		{
			if (lista[i].isEmpty == lleno)
			{
				acumuladorPrecio += lista[i].precioViaje;
				rtn = 1;
			}
		}
	}

	*precioAcumulado = acumuladorPrecio;

	return rtn;
}
