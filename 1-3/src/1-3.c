/*
 ============================================================================
 Name        : Agustin Lopez
 Description : 1-3
 ingresar 3 números y mostrar el número del medio, sólo si existe. En
caso de que no exista también informarlo.
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

	 if((numeroUno>numeroDos&&numeroUno<numeroTres)||(numeroUno<numeroDos&&numeroUno>numeroTres))
	 {
		 printf("el primer numero es el del medio");
	 }else{

		 if((numeroDos>numeroUno&&numeroDos<numeroTres)||(numeroDos<numeroUno&&numeroDos>numeroTres))
		 {
			 printf("el segundo numero es el del medio");
		 }else{
			 if((numeroTres>numeroUno&&numeroTres<numeroDos)||(numeroTres<numeroDos&&numeroTres>numeroDos))
					 {
				 	 	 printf("el tercer numero es el del medio");
					 }
				 }
		 }
	return 0;
}
