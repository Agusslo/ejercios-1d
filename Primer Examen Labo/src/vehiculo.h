#ifndef VEHICULO_H_
#define VEHICULO_H_
#include "hojaServicio.h"

typedef struct
{
	int idTipo;
	char descripcion[30];
}eTipo;

typedef struct
{
	int idVehiculo;
	char descripcion;
	int modelo;
	char color[10];
	eTipo tipoId;
	int isEmpty;
}eVehiculo;


int inicializar(eVehiculo vehiculo[],int tam);
void pedirNombre(char *mensaje, char *nombre,int largoNombre);
int pedirNumero(int*numero);
int buscarLibre(eVehiculo vehiculo[],int tam);
eVehiculo cargaAuto();
int altaVehiculos(eVehiculo vehiculo[],int tam);
int eVehiculo_buscarPorTipo(eVehiculo vehiculo[], int TAM, int idTipo);
int buscarId(eVehiculo vehiculo[],int tam);
int menuModificar(eVehiculo vehiculo[],int tam,eHojaServicio servicio[]);
void imprimirUno(eVehiculo vehiculo);
int imprimirTodos(eVehiculo viajes[],int tam);
int eVehiculo_imprimirPorTipo(eVehiculo lista[], int TAM);
void listarTipo(void);
#endif /* VEHICULO_H_ */
