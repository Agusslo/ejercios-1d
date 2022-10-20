#include "viaje.h"
#include "voucher.h"

#ifndef NEXO_H_
#define NEXO_H_

#include "viaje.h"
#include "voucher.h"

int nexo_alta(eViaje listaViajes[], int TAM_VIAJES, eVoucher listaVoucher[], int TAM_VOUCHERS);
int nexo_imprimirImportePorDestino(eVoucher listaVoucher[], int TAM_VOUCHER, eViaje listaViaje[], int TAM_VIAJE);
int nexo_imprimirImportePorTipoFecha(eVoucher listaVoucher[], int TAM_VOUCHER, eViaje listaViaje[], int TAM_VIAJE);

#endif /* NEXO_H_ */










