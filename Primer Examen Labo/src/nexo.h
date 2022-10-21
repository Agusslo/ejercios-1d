#ifndef NEXO_H_
#define NEXO_H_

#include "vehiculo.h"
#include "hojaServicio.h"

int nexo_alta(eVehiculo listaVehiculos[], int TAM_VIAJES, eHojaServicio listaVoucher[], int TAM_SERVICIO);
int nexo_imprimirImporteVehiculo(eHojaServicio listaServicio[], int TAM_SERVICIO, eVehiculo listaVehiculo[], int TAM_VEHICULO);
int nexo_imprimirImportePorTipoFecha(eHojaServicio listaServicio[], int TAM_SERVICIO, eVehiculo listaVehiculo[], int TAM_VEHICULO);


#endif /* NEXO_H_ */
