#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

/// @fn void SwitchOpciones(int)
///	Toma una opci�n del men� de opciones ingresada por el usuario. Mediante un switch va realizando la tarea que le corresponde-
/// a cada opci�n.
/// @param opcion
void SwitchOpciones (int opcion)
{
	float primerOperando;
	float segundoOperando;
	float suma;
	float resta;
	float producto;
	// int i;
	int seguir;

	seguir = 1;

	while (seguir == 1)
	{
			switch (opcion)
			{
			case 1:
				primerOperando =  IngresarOperando("Ingrese el primer operando: \n");
				opcion = MenuOpciones1(primerOperando);
				break;
				seguir = 1;

			case 2:
				segundoOperando = IngresarOperando("Ingrese el segundo operando: \n");
				opcion = MenuOpciones2 (primerOperando, segundoOperando);
				break;
				seguir = 1;

			case 3:
				printf ("\nCalcular operaciones: \n");
				printf ("a)Calcular la suma (%.2f+%.2f)\n", primerOperando, segundoOperando);
				printf ("b)Calcular la resta (%.2f-%.2f)\n", primerOperando, segundoOperando);
				printf ("c)Calcular la division (%.2f/%.2f)\n", primerOperando, segundoOperando);
				printf ("d)Calcular la multiplicacion (%.2f*%.2f)\n", primerOperando, segundoOperando);
				printf ("e)Calcular el factorial de %.2f y el factorial de %.2f \n", primerOperando, segundoOperando);
				opcion = MenuOpciones3 (primerOperando, segundoOperando);
				break;
				seguir = 1;

			case 4:
				seguir = 1;
				suma = Sumar (primerOperando, segundoOperando);
				printf ("a)El resultado de %.2f + %.2f es %.2f\n", primerOperando, segundoOperando, suma);
				resta = Restar (primerOperando, segundoOperando);
				printf ("b)El resultado de %.2f - %.2f es %.2f\n", primerOperando, segundoOperando, resta);
				Dividir (primerOperando, segundoOperando);
				producto = Multiplicar (primerOperando, segundoOperando);
				printf ("d)El resultado de %.2f*%.2f es: %.2f\n", primerOperando, segundoOperando, producto);
				Factorial (primerOperando);
				Factorial (segundoOperando);

				opcion = MenuOpciones3 (primerOperando, segundoOperando);
				break;

			case 5:
				break;
			}
	}
}

/// @fn int MenuOpciones(void)
/// Muestra el men� de opciones, pidiendo ingresar una de ellas.
/// @return retorna la opci�n elegida.
int MenuOpciones (void)
{
	int opcion;
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf ("---------------------------------------\n");
	printf ("Men� de opciones: \n");
	printf ("1.Ingrese el primer operando: \n");
	printf ("2.Ingrese el segundo operando: \n");
	printf ("3.Calcular todas las operaciones: \n");
	printf ("4.Informar resultados \n");
	printf ("5.Salir\n");
	printf ("---------------------------------------\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf ("Seleccione una opci�n: ");


	scanf ("%d", &opcion);

	return opcion;
}

/// @fn int MenuOpciones1(float)
/// Muestra el mismo men� de opciones pero esta vez completando con el primer operando en su respectiva -
/// opci�n, luego de ingresarlo.
/// @param numero1: es el primer n�mero ingresado.
/// @return retorna la opci�n elegida
int MenuOpciones1 (float numero1)
{
	int opcion;
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf ("---------------------------------------\n");
	printf ("Men� de opciones: \n");
	printf ("1.Ingrese el primer operando: %.2f \n", numero1);
	printf ("2.Ingrese el segundo operando: \n");
	printf ("3.Calcular todas las operaciones \n");
	printf ("4.Informar resultados \n");
	printf ("5.Salir\n");
	printf ("---------------------------------------\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	printf ("Seleccione una opci�n: ");

	scanf ("%d", &opcion);

	return opcion;
}

/// @fn int MenuOpciones2(float, float)
/// Muestra el men� luego de ingresar el segundo n�mero, teniendo los dos operandos cargados y -
/// reemplz�ndolos en el men� en sus respectivas l�neas de opciones.
/// @param numero1: es el primer n�mero ingresado.
/// @param numero2: es el segundo n�mero ingresado.
/// @return retorna la opci�n elegida.
int MenuOpciones2 (float numero1, float numero2)
{
	int opcion;
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf ("---------------------------------------\n");
	printf ("Men� de opciones: \n");
	printf ("1.Ingrese el primer operando: %.2f \n", numero1);
	printf ("2.Ingrese el segundo operando: %.2f \n", numero2);
	printf ("3.Calcular todas las operaciones \n");
	printf ("4.Informar resultados \n");
	printf ("5.Salir\n");
	printf ("---------------------------------------\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	printf ("Seleccione una opci�n: ");
	scanf ("%d", &opcion);

	return opcion;
}

/// @fn int MenuOpciones2(float, float)
/// Muestra el men� luego de ingresar el segundo n�mero, teniendo los dos operandos cargados y -
/// reemplz�ndolos en el men� en sus respectivas l�neas de opciones.
/// @param numero1: es el primer n�mero ingresado.
/// @param numero2: es el segundo n�mero ingresado.
/// @return retorna la opci�n elegida.
int MenuOpciones3(float numero1, float numero2)
{
	int opcion;
	printf ("\nMen� de opciones: \n");
	printf ("1.Ingrese el primer operando: %.2f \n", numero1);
	printf ("2.Ingrese el segundo operando: %.2f \n", numero2);
	printf ("3.Calcular todas las operaciones \n");
	printf ("4.Informar resultados \n");
	printf ("5.Salir\n");
	printf ("---------------------------------------\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	printf ("Seleccione una opci�n: ");
	scanf ("%d", &opcion);

	return opcion;
}

/// @fn float IngresarOperando(char[])
/// Pide el ingreso de un n�mero flotante mediante un mensaje.
/// @param mensaje: es el que pide el n�mero.
/// @return retorna el n�mero ingresado.
float IngresarOperando (char mensaje[])
{
	float operando;

	printf ("%s", mensaje);
	scanf ("%f", &operando);

	return operando;
}

/// @fn float Sumar(float, float)
/// Suma dos n�meros.
/// @param primerNumero: es el primer operando.
/// @param segundoNumero: es el segundo operando.
/// @return retorna la suma de los dos n�meros.
float Sumar (float primerNumero, float segundoNumero)
{
	float suma;

	suma = primerNumero + segundoNumero;

	return suma;
}

/// @fn float Restar(float, float)
/// Resta dos n�meros.
/// @param primerNumero: es el primer operando.
/// @param segundoNumero: es el segundo operando.
/// @return retorna la resta de los dos n�meros.
float Restar (float primerNumero, float segundoNumero)
{
	float resta;

	resta = primerNumero - segundoNumero;

	return resta;
}

/// @fn void Dividir(float, float)
/// Divide el primer numero ingresado por el segundo. Muestra la divisi�n en caso de que puede ser -
/// calculada y en caso de que no (cuando el segundo operando es 0) muestra un mensaje de error.
/// @param primerNumero: es el primer operando.
/// @param segundoNumero: es el segundo operando.
void Dividir (float primerNumero, float segundoNumero)
{
	float division;

	if (segundoNumero == 0)
	{
		printf("No es posible dividir por cero\n");
	}
	else
	{
		division = primerNumero / segundoNumero;
		printf ("c)El resultado de %.2f / %f es: %.2f\n", primerNumero, segundoNumero, division);
	}
}

/// @fn float Multiplicar(float, float)
/// Realiza el producto de dos n�meros y devuelve el resultado.
/// @param primerNumero: es el primer operando.
/// @param segundoNumero: es el segundo operando.
/// @return retorna el resultado de la multiplicaci�n.
float Multiplicar (float primerNumero, float segundoNumero)
{
	float multiplicacion;

	multiplicacion = primerNumero * segundoNumero;

	return multiplicacion;
}

/// @fn void Factorial(float)
/// Calcula el factorial de un n�mero
/// Como solo podemos calcular el factorial de n�mero positivos enteros, defino el entero parteEnteraNumero, que nos va a devolver la parte entera del n�mero ingresado.
/// Si la parte entera de un n�mero es igual al n�mero significa que el n�mero es un entero, y si adem�s es positivo significa que vamos a poder calcular su factorial.
/// En caso de que esto no se cumpla mostramos un mensaje de error.
/// @param es el operando ingresado.
void Factorial (float numero)
{
	int parteEnteraNumero;
	int contador;
    double factorial;

	parteEnteraNumero = numero;

	factorial = 1;

	if (numero == parteEnteraNumero && numero>-1)
	{
		for (contador = numero; contador > 0; contador --)
		{
			factorial = factorial *contador;
		}

		printf ("e)El factorial de %.2f es: %.0lf \n", numero, factorial);
	}
	else
	{
		printf ("��No existe el factorial de %.2f!!\n", numero);
	}
}
