#include "LinkedList.h"
#include "Employee.h"

Employee* employee_getEmployeeById (LinkedList* this, int tam, int idBusqueda)
{
	Employee* auxEmpleado;
	int i;

	for (i=0; i<tam; i++)
	{
		auxEmpleado = ll_get(this, i);

		if (auxEmpleado->id == idBusqueda)
		{
			break;
		}
	}

	return auxEmpleado;
}

int MostrarEmpleados (LinkedList* this, int tam)
{
	int retorno;
	int retornoEmpleado;
	int i;
	Employee* empleado;
	retorno = 0;

	for (i=0; i<tam; i++)
	{
		empleado = ll_get(this, i);
		retornoEmpleado = PrintOneEmployee (empleado);
		retorno = 1;
		//ver que hacer con el retorno
		/* if (retornoEmpleado == 0)
   	   {

   	   }*/
	}
	return retorno;
}

/// @fn int CompararElementos(void*, void*) Compara el nombre de dos empleados
/// @param empleado1
/// @param empleado2
/// @return
int CompararElementos (void* empleado1, void* empleado2)
{
	int retorno;
	char nombre1[50];
	char nombre2[50];
	retorno = 0;

	empleado1 = (Employee*) empleado1;
	empleado2 = (Employee*) empleado2;

	employee_getNombre(empleado1, nombre1);
	employee_getNombre(empleado2, nombre2);

	retorno = strcmp (nombre1, nombre2);

	return retorno;
}

/// @fn void ArregloNombrePropio(char[]) Convierte la primera letra de cada palabra de una oración en mayúscula y las demás en minúscula
/// @param cadena1
void ArregloNombrePropio (char cadena1[])
{
	int tam;
	tam = strlen (cadena1);
	int i;

	strlwr (cadena1);

	for (i=0; i<tam; i ++)
	{
		if (i== 0 || cadena1[i-1] == 32)
		{
			cadena1[i] = toupper (cadena1[i]);
		}
	}
}

/// @fn int PedirCadena(char[], char[])
/// @param mensaje: pide la cadena
/// @param cadena
/// @return: retorna 1 si se ingresó una cadena y 0 si no
int PedirCadena (char mensaje[], char cadena[])
{
	int i;
	int retorno;
	int tam;

	retorno = 0;

	printf ("%s", mensaje);
	fflush (stdin);
	gets (cadena);

	tam = strlen (cadena);

	for (i=0; i<tam; i++)
	{
		if (cadena[i] != 32 && isalpha(cadena[i]) == 0) //32 = código ASCII del espacio //si lo que ingresó el usuario no es una letra
		{
			printf ("Error!!!");
			printf ("%s", mensaje);
			fflush (stdin);
			gets (cadena);
			retorno = 1;
		}
	}

	ArregloNombrePropio (cadena);

	return retorno;
}

int PedirEntero (char mensaje[])
{
	int i;
	int retorno;
	int tam;
	int numero;
	char buffer[10];

	char str[10];
	//int val;

	retorno = 1;

	printf ("%s", mensaje);//pido el número
	scanf ("%d", &numero);//lo tomo
	itoa (numero, buffer, 10); //convierto el número en string
	tam = strlen (buffer);

	for (i=0; i<tam; i++)
	{
		if (isdigit(buffer[i]) == 0)
		{
			printf ("Error!!!\n");
			printf ("%s", mensaje);
			scanf ("%d", &numero);
			itoa (numero, buffer, 10);
			tam = strlen (buffer);
		}
	}

	strcpy (str, buffer);

	retorno = atoi (str);

	return retorno;
}
