/*
 ============================================================================
 Name        : Agustin Lopez
 Description : Ejercicio 2-1: Ingresar 7 números negativos distintos de 0 calcular y mostrar el
promedio de los números. Probar la aplicación con distintos valores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

    int numeros = 0;
    int numero;
    int acumulador = 0;
    float promedio;

    while(numeros <= 7)
    {
    	printf("Ingrese el número: ");
    	scanf("%d",&numero);
    	if(numero >= 0)
    	{
    		printf("Ingrese el primer número nuevamente: ");
    		scanf("%d",&numero);
    	}
    	acumulador = acumulador + numero;
    	numeros++;
    }

    promedio = acumulador / numeros;
	printf("El promedio es: %.2f", promedio);

    return 0;
}
