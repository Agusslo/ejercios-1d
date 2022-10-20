#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viaje.h"

#define vacio 1
#define lleno 0

static int obtenerID();
static int idIncremental = 1000;
static int obtenerID()
{
    return idIncremental++;
}

int inicializar(eViaje viajes[],int tam)///agarra todos los arrays y isempty y los pone vacio(en 0), sin importar quien sea
{
	int retorno=-1;
	if(viajes!=NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			viajes[i].isEmpty=vacio;
			retorno=0;
		}
	}
	return retorno;
}

int buscarLibre(eViaje viajes[],int tam)
{
	int retorno=-1;///si no entra al if devuelve -1


	if(viajes!=NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(viajes[i].isEmpty==vacio)///busca que isEmpty este vacio, si encuentra devuelve la i
			{
				retorno=i;
				break;///cuando encuentre el vacio, se termina el bucle
			}
		}
	}

	return retorno;
}

void pedirNombre(char *mensaje, char *nombre,int largoNombre)///usar utn_getString
{
    printf(mensaje);
    fflush(stdin);
    fgets(nombre,largoNombre,stdin);
    nombre[strlen(nombre)-1]='\0';
}

int pedirNumero(int*numero)///usar utn_getNumero
{
    int retorno=-1;
    int buffer;
    if(numero!=NULL)
    {
        printf(" ingrese numero \n");
        scanf("%d",&buffer);
        if(numero>0)
        {
            *numero=buffer;
            retorno=0;
        }
        else
        {
            printf("ingrese un numero positivo");
        }
    }
    return retorno;
}

eViaje cargaViaje()///ingreso datos de 1 viaje
{
	eViaje aux;

		aux.isEmpty=lleno;
		pedirNombre("ingrese su destino: \n",aux.destino,20);
		pedirNumero(&aux.cantidadPasajeros);
		printf("selecione un Tipo\n"
				"1. AEREO\n"
				"2. TERRESTRE\n"
				"3. MARITIMO\n");
		scanf("%d",&aux.tipoId.idTipo);
		printf("%d",aux.tipoId.idTipo);
		aux.idViaje=obtenerID();///para obtener el id, id incrementando +1

	return aux;
}

int altaViajes(eViaje viajes[],int tam)
{
	int retorno=-1;

	if(viajes!=NULL && tam>0)
	{
		int i=buscarLibre(viajes,tam);
		if(i!=-1)
		{
			viajes[i]=cargaViaje();
			retorno=0;
		}else
		{
			printf("no hay espacio libre");
		}
	}
	return retorno;
}

int eViaje_buscarPorTipo(eViaje lista[], int TAM, int idTipo)
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
			if (lista[i].tipoId.idTipo == idTipo && lista[i].isEmpty == vacio)
			{
				///SI ENCONTRO EL ID
				///DEVUELVE EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = idTipo;
				break;
			}
		}
	}

	return rtn;
}


int buscarId(eViaje viajes[],int tam)
{
	int retorno=-1;
	int id;
	pedirNumero(&id);/// el & porque el pedirNumero tiene un puntero
	if(viajes!=NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(viajes[i].idViaje==id)///entra al if solamente cuando el id del viaje en la posicion de i coincide con el id ingresado por el usuario
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

int menuModificar(eViaje viajes[],int tam)
{
	int retorno=-1;
	int opcion;
	int i;

	i=buscarId(viajes,tam);

	do
	{
		printf("que desea modificar?\n");
		printf("1. Destino\n");
		printf("2. Cantidad Pasajeros\n");
		printf("3. SALIR\n");
		scanf("%d",&opcion);
		switch(opcion)
		{
			case 1:
				retorno=0;
				pedirNombre("ingrese su nuevo destino\n",viajes[i].destino,20);
				break;
			case 2:
				retorno=0;
				pedirNumero(&viajes[i].cantidadPasajeros);
				break;
			case 3:
				retorno=0;
				break;
			default:
				printf("ingrese una opcion valida");
				break;
		}
	}while(opcion!=3);

	return retorno;
}

int bajaViaje(eViaje viajes[], int tam)/// doy de baja un viaje lleno y si esta vacio notifica que esta vacio
{
	int retorno=-1;
	int i;
	i=buscarId(viajes,tam);

	if(viajes[i].isEmpty==lleno && tam>0)
	{
		retorno=0;
		viajes[i].isEmpty=vacio;
	}else
	{
		printf("este viaje esta vacio");
	}

	return retorno;
}

void imprimirUno(eViaje viaje)
{
	printf("|%4d|%-11s|%-11d|", viaje.idViaje, viaje.destino,viaje.cantidadPasajeros);/// los numeros raros son los valores de cada viaje

	switch(viaje.tipoId.idTipo)
	{
		case 1:
			printf("%-10s|\n", "AEREO");
		break;

		case 2:
			printf("%-10s|\n", "TERRESTRE");
		break;

		case 3:
			printf("%-10s|\n", "MARITIMO");
		break;
	}

}

int imprimirTodos(eViaje viajes[],int tam)
{
	int retorno=-1;
	int cantidad=0;

	if (viajes != NULL && tam > 0)
	{
		puts("\n\t LISTA DE VIAJES");
		puts("+---------------------------------------+");
		puts("| ID |  DESTINO  | PASAJEROS |   TIPO   |");
		puts("+---------------------------------------+");

		for (int i = 0; i < tam; i++)
		{
			if (viajes[i].isEmpty == lleno)
			{
				retorno=0;
				imprimirUno(viajes[i]);
				puts("+---------------------------------------+");
				cantidad++;
			}
		}
	}
	return retorno;
}

int eViaje_imprimirPorTipo(eViaje lista[], int TAM)
{
	int i;
	int rtn = 0;
	int cantidad = 0;
	int idTipo;
	int idEncontrado;

	if (lista != NULL && TAM > 0)
	{
		utn_getNumero("\nINGRESE EL TIPO REQUERIDO (1. AEREO | 2. TERRESTRE | 3. MARITIMO): ", "ERROR. ", 1, 3, 3, &idTipo);

		puts("\n\t\t LISTA DE VIAJES");
		puts("+---------------------------------------+");
		puts("| ID |  DESTINO  | PASAJEROS |   TIPO   |");
		puts("+---------------------------------------+");

		idEncontrado = eViaje_buscarPorTipo(lista, TAM, idTipo);

		for (i = 0; i < TAM; i++)
		{
			if (lista[i].isEmpty == lleno && idEncontrado != -1)
			{
				if(lista[i].tipoId.idTipo == idTipo)
				{
					imprimirUno(lista[i]);
					puts("+---------------------------------------+");
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

void listarTipo(void)///literalmente lista los tipos en orden
{
	printf("\nTIPOS DE VIAJE: \n"
		   "1. AEREO\n"
		   "2. TERRESTRE\n"
		   "3. MARITIMO\n");
}

