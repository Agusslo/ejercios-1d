#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LEN_EMAIL 26
#define MAX_LEN_PASSWORD 11
#define MIN_LEN_PASSWORD 5
#define MAX_LEN_DIRECTION 51
#define TAM_CHAR 51

int utn_getNumero(char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos, int* pResultado);
int utn_getNumFloat(char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos, float *pNumeroIngresado);
int utn_getString(char* mensaje, char* mensajeError, int reintentos,  int longitud, char* pResultado);
int utn_getAlfaNum(char mensaje[], char mensajeError[], int reintentos, int TAM, char cadena[]);
int utn_getEmail(char mensaje[], char mensajeError[], int reintentos, char correo[]);
int utn_getPassword(char mensaje[], char mensajeError[], int min, int max, int reintentos, char password[]);
long int time_Current(void);
long int time_Add(double secondsAdd);
int funcionContinuar(char mensaje[], char mensajeError[]);

#endif /* UTN_H_ */
