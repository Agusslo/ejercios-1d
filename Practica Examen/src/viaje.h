#ifndef VIAJE_H_
#define VIAJE_H_

typedef struct
{
	int idTipo;
	char descripcion[30];
}eTipo;

typedef struct
{
	int idViaje;
	char destino[20];
	int cantidadPasajeros;
	eTipo tipoId;
	int isEmpty;// para saber si esta vacio o no
}eViaje;


int inicializar(eViaje viajes[],int tam);
int buscarLibre(eViaje viajes[],int tam);
void pedirNombre(char *mensaje, char *nombre,int largoNombre);
int pedirNumero(int*numero);
eViaje cargaViaje();
int altaViajes(eViaje viajes[],int tam);
int eViaje_buscarPorTipo(eViaje lista[], int TAM, int idTipo);
int buscarId(eViaje viajes[],int tam);
int menuModificar(eViaje viajes[],int tam);
int bajaViaje(eViaje viajes[], int tam);
void imprimirUno(eViaje viaje);
int imprimirTodos(eViaje lista[],int tam);
int eViaje_imprimirPorTipo(eViaje lista[], int TAM);
void listarTipo(void);
#endif /* VIAJE_H_ */
