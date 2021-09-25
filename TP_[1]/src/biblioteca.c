#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

/// @fn float IngresarOperando(char[])
/// Pide el ingreso de un número flotante mediante un mensaje.
/// @param mensaje: es el que pide el número.
/// @return retorna el número ingresado.
float IngresarOperando (char mensaje[])
{
	float operando;

	printf ("%s", mensaje);
	scanf ("%f", &operando);

	return operando;
}

/// @fn float Sumar(float, float)
/// Suma dos números.
/// @param primerNumero: es el primer operando.
/// @param segundoNumero: es el segundo operando.
/// @return retorna la suma de los dos números.
float Sumar (float primerNumero, float segundoNumero)
{
	float suma;

	suma = primerNumero + segundoNumero;

	return suma;
}

/// @fn float Restar(float, float)
/// Resta dos números.
/// @param primerNumero: es el primer operando.
/// @param segundoNumero: es el segundo operando.
/// @return retorna la resta de los dos números.
float Restar (float primerNumero, float segundoNumero)
{
	float resta;

	resta = primerNumero - segundoNumero;

	return resta;
}

/// @fn int Dividir(float, float, float*)
/// Divide dos números.
/// @param primerNumero: es el primer operando, el dividendo.
/// @param segundoNumero: es el seugndo operando, el divisor.
/// @param division: es el puntero que me va a devolver el resultado de la división en caso de que sea posible calcularlo.
/// @return retorna el valor de la bandera. 0 Si la división no se realizó y 1 en caso contrario.
int Dividir (float primerNumero, float segundoNumero, float* division)
{
	int bandera;
	float div;

    bandera = 0;

    if (segundoNumero != 0)
	{
		div = primerNumero / segundoNumero;
		bandera = 1;
		*division = div;
	}

	return bandera;
}

/// @fn float Multiplicar(float, float)
/// Realiza el producto de dos números y devuelve el resultado.
/// @param primerNumero: es el primer operando.
/// @param segundoNumero: es el segundo operando.
/// @return retorna el resultado de la multiplicación.
float Multiplicar (float primerNumero, float segundoNumero)
{
	float multiplicacion;

	multiplicacion = primerNumero * segundoNumero;

	return multiplicacion;
}

/// @fn int Factorial(float, double*)
/// Calcula el factorial de un número.
/// @param numero: es el número ingresado al que se le va a calcular el factorial.
/// @param factorial: es el puntero que va a guardar el valor del factorial en caso de que sea posible calcularlo.
/// @return retorna la bandera del factorial. Devuelve 1 en caso de que se puede calcular y 0 en caso contrario.
int Factorial (float numero, double* factorial)
{
	int parteEnteraNumero;
	int contador;
    double factorial1;
    int banderaRetorno;

    banderaRetorno = 0;
	parteEnteraNumero = numero;

	factorial1 = 1;

	if (parteEnteraNumero == numero && numero >-1)
	{
		for (contador = numero; contador > 0; contador --)
		{
			factorial1 = factorial1 *contador;
		}

		*factorial = factorial1;
		banderaRetorno = 1;
	}

	return banderaRetorno;
}
