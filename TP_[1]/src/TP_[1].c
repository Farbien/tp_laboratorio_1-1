/*
Lucas Emmanuel Mendoza
TP1
Enunciado
Hacer una calculadora. Para ello el programa iniciar� y contar� con un men� de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) �El resultado de A+B es: r�
b) �El resultado de A-B es: r�
c) �El resultado de A/B es: r� o �No es posible dividir por cero�
d) �El resultado de A*B es: r�
e) �El factorial de A es: r1 y El factorial de B es: r2�
5. Salir
� Todas las funciones matem�ticas del men� se deber�n realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
� En el men� deber�n aparecer los valores actuales cargados en los operandos A y B
(donde dice �x� e �y� en el ejemplo, se debe mostrar el n�mero cargado)
� Deber�n contemplarse los casos de error (divisi�n por cero, etc)
� Documentar todas las funciones
*/

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main(void)
{
	setbuf(stdout, NULL);

	int opcion;
	float primerOperando;
	float segundoOperando;
	int banderaPrimerOperando;
	int banderaSegundoOperando;
	float suma;
	float resta;
	float producto;
	int seguir;
	float division;
	int banderaDivision;
	double factorial;
	int banderaFactorial;

	seguir = 1;
	banderaPrimerOperando = 1;
	banderaSegundoOperando = 1;

	while (seguir == 1)
	{
		printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf ("---------------------------------------\n");
		printf ("Men� de opciones: \n");

		if (banderaPrimerOperando == 1)
		{
			printf ("1.Ingrese el primer operando: \n");
			banderaPrimerOperando = 0;
		}
			else
			{
				printf ("1.Ingrese el primer operando: %.2f\n", primerOperando);
			}

		if (banderaSegundoOperando == 1)
		{
			printf ("2.Ingrese el segundo operando: \n");
			banderaSegundoOperando = 0;
		}
			else
			{
				printf ("2.Ingrese el segundo operando: %.2f\n", segundoOperando);
			}
		printf ("3.Calcular todas las operaciones: \n");
		printf ("4.Informar resultados \n");
		printf ("5.Salir\n");
		printf ("---------------------------------------\n");
		printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf ("Seleccione una opci�n: ");
		scanf ("%d", &opcion);

		switch (opcion)
			{
			case 1:
				primerOperando =  IngresarOperando("Ingrese el primer operando: ");
				break;
				seguir = 1;

			case 2:
				segundoOperando = IngresarOperando("Ingrese el segundo operando: ");
				break;
				seguir = 1;

			case 3:
				printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				printf ("---------------------------------------\n");
				printf ("\nCalcular operaciones: \n");
				printf ("a)Calcular la suma (%.2f+%.2f)\n", primerOperando, segundoOperando);
				printf ("b)Calcular la resta (%.2f-%.2f)\n", primerOperando, segundoOperando);
				printf ("c)Calcular la division (%.2f/%.2f)\n", primerOperando, segundoOperando);
				printf ("d)Calcular la multiplicacion (%.2f*%.2f)\n", primerOperando, segundoOperando);
				printf ("e)Calcular el factorial de %.2f y el factorial de %.2f \n", primerOperando, segundoOperando);
				printf ("\n---------------------------------------\n");
				printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
				break;
				seguir = 1;

			case 4:
				seguir = 1;

				printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				printf ("---------------------------------------\n");
				printf ("Resultados: \n");
				suma = Sumar (primerOperando, segundoOperando);
				printf ("a)El resultado de %.2f + %.2f es %.2f\n", primerOperando, segundoOperando, suma);
				resta = Restar (primerOperando, segundoOperando);
				printf ("b)El resultado de %.2f - %.2f es %.2f\n", primerOperando, segundoOperando, resta);

				//div:
				banderaDivision = Dividir (primerOperando, segundoOperando, &division);
				if (banderaDivision == 1)
				{
					printf ("c)El resultado de %.2f / %f es: %.2f\n", primerOperando, segundoOperando, division);
				}
				else
				{
					printf ("c)Error!!! No es posible dividir por cero\n");
				}

				producto = Multiplicar (primerOperando, segundoOperando);
				printf ("d)El resultado de %.2f*%.2f es: %.2f\n", primerOperando, segundoOperando, producto);

				//fact:
				banderaFactorial = Factorial (primerOperando, &factorial);
				if (banderaFactorial == 1)
				{
					printf ("e.1)El factorial de %.2f es %.2f\n", primerOperando, factorial);
				}
				else
				{
					printf ("e.1)No existe el factorial de %.2f\n", primerOperando);
				}

				banderaFactorial = Factorial (segundoOperando, &factorial);
				if (banderaFactorial == 1)
				{
					printf ("e.2)El factorial de %.2f es %.2f\n", segundoOperando, factorial);
				}
				else
				{
					printf ("e.2)No existe el factorial de %.2f\n", segundoOperando);
				}

				printf ("---------------------------------------\n");
				printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
				break;

			case 5:
				seguir = 0;
				break;
			}
	}
}

