/*
 ============================================================================
 Name        : Agustin Lopez
 Description : 1-2
 ingresar 3 números y mostrar cuál de los tres es el mayor.
Ejemplo: Si ingresamos 5, 9 y 3 el programa mostrará: “El mayor de los números es el
segundo: 9”
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	 setbuf(stdout,NULL);

	 int numeroUno;
	 int numeroDos;
	 int numeroTres;

	 printf("Ingrese el primer numero");
	 scanf("%d",&numeroUno);
	 printf("Ingrese el segundo numero");
	 scanf("%d",&numeroDos);
	 printf("Ingrese el tercer numero");
	 scanf("%d",&numeroTres);

	 if(numeroUno>numeroDos && numeroUno>numeroTres)
	 {
		 printf("el primer numero es el mayor:%d", numeroUno);
	 }
	 else{
		 if(numeroDos>numeroTres)
		 {
			 printf("el segundo numero es el mayor:%d", numeroDos);
		 }else
		 {
			 printf("el tercer numero es el mayor:%d", numeroTres);
		 }
	 }
	return 0;
}
