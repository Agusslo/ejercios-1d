#ifndef HOJASERVICIO_H_
#define HOJASERVICIO_H_
#include "utn.h"

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int idHoja;
	int vehiculoId;
	char descripcion[TAM_CHAR];
	int precioServicio;
	eFecha fecha;
	int isEmpty;
}eHojaServicio;

int eHojaServicio_getID(void);
int servicioInicializar(eHojaServicio servicio[],int tam);
int eHojaServicio_obtenerIndexLibre(eHojaServicio lista[], int TAM);
eHojaServicio eHojaServicio_ingresarDatos(void);
void eHojaServicio_imprimirUno(eHojaServicio servicio);
int eHojaServicio_imprimirTodos(eHojaServicio lista[], int TAM);
int eHojaServicio_imprimirPorFecha(eHojaServicio lista[], int TAM);
int eHojaServicio_acumularPrecio(eHojaServicio lista[], int TAM, int* precioServicio);


#endif /* HOJASERVICIO_H_ */
