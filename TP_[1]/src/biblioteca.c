#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

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
