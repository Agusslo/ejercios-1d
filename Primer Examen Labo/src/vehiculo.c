#include "vehiculo.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define vacio 1
#define lleno 0


static int obtenerID();
static int idIncremental = 1000;
static int obtenerID()
{
    return idIncremental++;
}

int inicializar(eVehiculo vehiculo[],int tam)
{
	int retorno=-1;
	if(vehiculo!=NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			vehiculo[i].isEmpty=vacio;
			retorno=0;
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

int buscarLibre(eVehiculo vehiculo[],int tam)
{
	int retorno=-1;///si no entra al if devuelve -1


	if(vehiculo!=NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(vehiculo[i].isEmpty==vacio)///busca que isEmpty este vacio, si encuentra devuelve la i
			{
				retorno=i;
				break;///cuando encuentre el vacio, se termina el bucle
			}
		}
	}
	return retorno;
}

eVehiculo cargaAuto()
{
	eVehiculo aux;

		aux.isEmpty=lleno;
		utn_getString("ingrese la descripcion del auto","ERROR",7,30,&aux);
		utn_getString("ingrese el color del auto: ","ERROR",7,10,&aux);
		utn_getNumero("ingrese el modelo del auto","ERROR",1980,2022,7,&aux);
		utn_getNumero("ingrese el precio del auto","ERROR",0,10000,7,&aux);
		printf("selecione un Tipo\n"
				"1. SEDAN 3PTAS\n"
				"2. SEDAN 5PTAS\n"
				"3. CAMIONETA\n");
		scanf("%d",&aux.tipoId.idTipo);
		printf("%d",aux.tipoId.idTipo);
		aux.idVehiculo=obtenerID();///para obtener el id, id incrementando +1

	return aux;
}

int altaVehiculos(eVehiculo vehiculo[],int tam)
{
	int retorno=-1;

	if(vehiculo!=NULL && tam>0)
	{
		int i=buscarLibre(vehiculo,tam);
		if(i!=-1)
		{
			vehiculo[i]=cargaAuto();
			retorno=0;
		}else
		{
			printf("no hay espacio libre");
		}
	}
	return retorno;
}

int eVehiculo_buscarPorTipo(eVehiculo vehiculo[], int TAM, int idTipo)
{
	int rtn = -1;
	int i;

	///SI EXISTE EL lista Y EL LIMITE ES VALIDO
	if (vehiculo != NULL && TAM > 0)
	{
		///RECORRE EL lista
		for (i = 0; i < TAM; i++)
		{
			///BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (vehiculo[i].tipoId.idTipo == idTipo && vehiculo[i].isEmpty == vacio)
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

int buscarId(eVehiculo vehiculo[],int tam)
{
	int retorno=-1;
	int id;
	pedirNumero(&id);/// el & porque el pedirNumero tiene un puntero
	if(vehiculo!=NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(vehiculo[i].idVehiculo==id)///entra al if solamente cuando el id del viaje en la posicion de i coincide con el id ingresado por el usuario
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

int menuModificar(eVehiculo vehiculo[],int tam,eHojaServicio servicio[])
{
	int retorno=-1;
	int opcion;
	int i;

	i=buscarId(vehiculo,tam);

	do
	{
		printf("que desea modificar?\n");
		printf("1. Descripcion\n");
		printf("2. Precio Servicio\n");
		printf("3. SALIR\n");
		scanf("%d",&opcion);
		switch(opcion)
		{
			case 1:
				retorno=0;
				pedirNombre("ingrese su nueva descripcion\n",vehiculo[i].descripcion,20);
				break;
			case 2:
				retorno=0;
				pedirNumero(&servicio[i].precioServicio);//arreglar
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

int bajaViaje(eVehiculo vehiculo[], int tam)
{
	int retorno=-1;
	int i;
	i=buscarId(vehiculo,tam);

	if(vehiculo[i].isEmpty==lleno && tam>0)
	{
		retorno=0;
		vehiculo[i].isEmpty=vacio;
	}else
	{
		printf("este vehiculo esta dado de baja");
	}

	return retorno;
}

void imprimirUno(eVehiculo vehiculo)
{
	printf("|%4d|%-11d|%-11s|", vehiculo.idVehiculo, vehiculo.descripcion, vehiculo.color);

	switch(vehiculo.tipoId.idTipo)
	{
		case 1:
			printf("%-10s|\n", "SEDAN 3PTAS");
		break;

		case 2:
			printf("%-10s|\n", "SEDAN 5PTAS");
		break;

		case 3:
			printf("%-10s|\n", "CAMIONETA)");
		break;
	}

}

int imprimirTodos(eVehiculo viajes[],int tam)
{
	int retorno=-1;
	int cantidad=0;
	eVehiculo aux;
	if (viajes != NULL && tam > 0)
	{
		puts("\n\t LISTA DE VIAJES");
		puts("+-------------------------------------------+");
		puts("| ID |  DESCRIPCION  | MODELO |   TIPO     |");
		puts("+-------------------------------------------+");

		for (int i = 0; i < tam; i++)
		{
			for(int j=i+1;j<tam-1;j++)
			{

				if(viajes[i].isEmpty == lleno && viajes[i].tipoId.idTipo<viajes[j].tipoId.idTipo)
				{
					aux=viajes[i];
					viajes[i]=viajes[j];
					viajes[j]=aux;

				}
				else if(strcmp(viajes[i].descripcion,viajes[j].descripcion)>0)
				{
					aux=viajes[i];
					viajes[i]=viajes[j];
					viajes[j]=aux;
				}

			}
			if (viajes[i].isEmpty == lleno)
							{
								imprimirUno(viajes[i]);
								puts("+-------------------------------------------+");
								cantidad++;
							}

		}
	}
	return retorno;
}

int eVehiculo_imprimirPorTipo(eVehiculo lista[], int TAM)
{
	int i;
	int rtn = 0;
	int cantidad = 0;
	int idTipo;
	int idEncontrado;

	if (lista != NULL && TAM > 0)
	{
		utn_getNumero("\nINGRESE EL TIPO REQUERIDO (1. SEDAN 3pts | 2. SEDAN 5ptas | 3. CAMIONETA): ", "ERROR. ", 1, 3, 3, &idTipo);

		puts("\n\t\t LISTA DE VEHICULOS");
		puts("+---------------------------------------+");
		puts("| ID |  DESCRIPCION  | COLOR |   TIPO   |");
		puts("+---------------------------------------+");

		idEncontrado = eVehiculo_buscarPorTipo(lista, TAM, idTipo);

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

void listarTipo(void)
{
	printf("\nTIPOS DE VEHICULOS: \n"
		   "1. SEDAN 3pts\n"
		   "2. SEDAN 5pts\n"
		   "3. CAMIONETA\n");
}
