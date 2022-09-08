/*
 ============================================================================
 Name        : Agustin Lopez
 Description : 1-1
 Ingresar dos números enteros entre -50 y 100, sumarlos y mostrar el
resultado. Ejemplo: Si ingresamos 3 y 2 el programa mostrará: “La suma entre 3 y 2
da como resultado 5”
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    setbuf(stdout,NULL);
    int numeroUno;
    int numeroDos;
    int resultado;

    printf("Ingrese numero ");
    while(numeroUno<-50 || numeroDos >100)
    {
        printf("Numero incorrecto, ingrese de nuevo.");
        scanf("%d",&numeroUno);
    }
    scanf("%d",&numeroUno);

    printf("\nIngrese segundo numero");
    while(numeroDos<-50 || numeroDos >100)
    {
        printf("Numero incorrecto, ingrese de nuevo.");
        scanf("%d",&numeroDos);
    }
    scanf("%d",&numeroDos);
    resultado=numeroUno+numeroDos;

    printf("La suma da como resultado : %d",resultado);
    return 0;
}
