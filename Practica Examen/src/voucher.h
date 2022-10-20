#ifndef VOUCHER_H_
#define VOUCHER_H_
#include "utn.h"

typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int idVoucher;
	int viajeId;
	char descripcion[TAM_CHAR];
	int precioViaje;
	eFecha fecha;
	int isEmpty;
}eVoucher;

int voucherInicializar(eVoucher voucher[],int tam);
int eVoucher_obtenerIndexLibre(eVoucher lista[], int TAM);
int eVoucher_getID(void);
int eVoucher_buscarPorID(eVoucher lista[], int TAM, int ID);
eVoucher eVoucher_ingresarDatos(void);
void eVoucher_imprimirUno(eVoucher voucher);
int eVoucher_imprimirTodos(eVoucher lista[], int TAM);
int eVoucher_imprimirPorFecha(eVoucher lista[], int TAM);
int eVoucher_acumularPrecio(eVoucher lista[], int TAM, int* precioAcumulado);

#endif /* VOUCHER_H_ */
