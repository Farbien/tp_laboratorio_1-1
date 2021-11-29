#include "Biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAMCLIENTES 1000
#define MIN 1
#define MAX 10

/// @fn int VerificarRango(int, int, int): verifica si un número está entre dos parametros
/// @param numero: número ingresado
/// @param min: límite inferior del rango
/// @param max: límite superior del rango
/// @return retorna 0 si si el número no está en el rango solicitado
int VerificarRango (int numero, int min, int max)
{
	int retorno;
	retorno = 1;

	if (numero < min || numero > max)
	{
		retorno = 0; // o sea mal
	}

	return retorno;
}

/// @fn int PedirEntero(char[]): pide el ingreso de un número mediante un mensaje
/// @param mensaje: pide el número
/// @return retorna el número ingresado

int PedirEntero (char mensaje[], int min, int max)
{
	int i;
	int retorno;
	char numero[15];
	int tam;
	int numeroAux;

	retorno = 1;

	do {
		printf ("%s", mensaje);
		scanf ("%s", numero);
		tam = strlen (numero);

			for (i=0; i<tam; i++)
			{
				if (isdigit(numero[i]) == 0 /* || isalpha (numero[i] == 1)*/)
				{
					printf ("Error!!!\n");
					printf ("%s", mensaje);
					scanf ("%s", numero);
					tam = strlen (numero);
					i=0;
				}
			}

			numeroAux = atoi (numero);

	}while (numeroAux < min || numeroAux > max);

	retorno = numeroAux;

	return retorno;
}


/// @fn float PedirFlotante(char[]): pide el ingreso de un número mediante un mensaje
/// @param mensaje: pide el número flotante
/// @return: retorna el número flotante
float PedirFlotante (char mensaje[])
{
	float retorno;
	char numero[30];
	int tam;

	printf ("%s", mensaje);
	scanf ("%s", numero);

	tam = strlen (numero);

	while(CAL_esFloat(numero, tam) == 0)
	{
		printf ("%s", mensaje);
		scanf ("%s", numero);

		tam = strlen (numero);
	}

	retorno = atof (numero);

	return retorno;
}

int CAL_esFloat(char cadena[], int dimension)
{
	int retorno;
	int i;
	int contadorPunto;

	contadorPunto = 0;
	retorno = 1;

	for (i = 0; i < dimension && cadena[i] != '\0'; i++) {
		if (i == 0 && (cadena[i] == '-' || cadena[i] == '+')) {
			continue;
		}
		if (cadena[i] > '9' || cadena[i] < '0') {
			if (cadena[i] == '.') {
				contadorPunto++;
				if (contadorPunto > 1) {
					retorno = 0;
					break;
				}

			} else {
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}


/// @fn void GuardarIdBajas(int[], int, int) Guarda un id en un array
/// @param listado: es el listado donde va a guardarlo
/// @param len: es el tamaño del array de los ids
/// @param id: es el id ingresado que va a ser guardado
void GuardarIdBajas (int listado[], int len, int id)
{
	int i;

	for (i=0; i<len; i++)
	{
		if (listado[i] == 0)
		{
			listado[i] = id;
		}
	}
}

/// @fn void Inicializar(int[], int) Inicializa un vector para que esté cargado con "basura"
/// @param listado: es le listado con los elementos a inicializar
/// @param len: es el tamaño del listado
void Inicializar (int listado[], int len)
{
	int i;

	for (i=0; i<len; i++)
	{
		listado[i] = 0;
	}
}

int InitEmployees(Employee list[], int tam)
{
	int i;
	int retorno;
	retorno = -1;

	if (tam > 1 && list != NULL)
	{
		for (i=0; i<tam; i++)
		{
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}

/// @fn int ModificarDato(Employee[], int): Permite modificar un dato de un empleado mediante el ingreso de su id
/// @param empleados: es el vector de empleados
/// @param tam: es el tamaño del vector de los empleados
/// @return: retorna 0 si no se modificó nada y 1 si sí.
int ModificarDato (Employee empleados[], int tam)
{
	int idModificacion;
	int posEmployeeMod;
	int opcionMod;
	char nombreMod[21];
	char apellidoMod[21];
	float salarioMod;
	int sectorMod;
	int retornoMod;

	retornoMod = 0;

	idModificacion = PedirEntero ("Ingrese su id para realizar una modificación: \n", 1, 1000);

	posEmployeeMod = FindEmployeeById (empleados, tam, idModificacion);

	printf ("¿Qué desea modificar?\n1-Nombre\n2-Apellido\n3-Salario\n4-Sector");
	printf ("\nSeleccione una opcion:");
	scanf ("%d", &opcionMod);

	switch (opcionMod)
	{
	case 1:
		PedirCadena ("Ingrese el nuevo nombre: \n", nombreMod);
		strcpy (empleados[posEmployeeMod].name, nombreMod);
		printf ("Se ha modificado el nombre.");
		retornoMod = 1;
		break;

	case 2:
		PedirCadena ("Ingrese el nuevo apellido: \n", apellidoMod);
		strcpy (empleados[posEmployeeMod].lastName, apellidoMod);
		printf ("Se ha modificado el apellido.");
		retornoMod = 1;
		break;

	case 3:
		salarioMod = PedirFlotante ("Ingrese el nuevo salario: \n");
		empleados[posEmployeeMod].salary = salarioMod;
		printf ("Se ha modificado el salario.");
		retornoMod = 1;
		break;

	case 4:
		sectorMod = PedirEntero ("Ingrese el nuevo sector: \n", MIN, MAX);
		empleados[posEmployeeMod].sector = sectorMod;
		printf ("Se ha modificado el sector.");
		retornoMod = 1;
		break;
	}

	return retornoMod;
}

/// @fn int IdAutomatico(Employee[], int, int[], int): Genera un id, teniendo en cuenta que no esté usado. Es decir, que no haya sido asignado a un empleado y que no haya sido de baja
/// @param empleados: es el vector de empleados
/// @param tam: es el tamaño del vector
/// @param listaIdBajas: es la lista de los ids dados de baja
/// @param tamIdBajas: es el tamaño de la lista de los ids dados de baja
/// @return retorna el id generado
int IdAutomatico1 (Employee empleados[], int tam, int listaIdBajas[], int tamIdBajas)
{
	int numeroId;
	int i;
	int j;

	numeroId = 1;

	for (i=0; i<tam; i++)
	{
		for (j=0; j<tamIdBajas; j++)
		{
			if ((empleados[i].isEmpty == 0) && (empleados[j].isEmpty == 0) && (numeroId == empleados[i].id || numeroId == listaIdBajas[j]))
			{
				numeroId ++;
			}
		}
	}

	return numeroId;
}

/// @fn int PedirEmpleado(Employee[], int, int[], int*, char[], char[], float*, int*): Pide los datos de un empleado y los pasa por referencia en vectores y punteros
/// @param empleados: es el array de los empleados
/// @param tam: es el tamaño del array de los empleados
/// @param listaBajas: es la lista de los ids dados de baja
/// @param id: es el id del empleado
/// @param name: es el nombre del empleado
/// @param lastName: es el apellido del empleado
/// @param salary: es el salario del empleado
/// @param sector: es el sector del empleado
/// @return retorna 1;
int PedirEmpleado (Employee empleados[], int tam, int listaBajas[], int* id, char name[], char lastName[], float* salary, int* sector)//le paso el array sólo para usarlo en idRandom.
{
	int retorno;
	int idRandom;
	int sector1;
	float salario;

	retorno = 1;

	idRandom = IdAutomatico1 (empleados, tam, listaBajas, tam);
	*id = idRandom;
	PedirCadena ("Ingrese su nombre: \n", name);
	PedirCadena ("Ingrese su apellido: \n", lastName);
	salario = PedirFlotante ("Ingrese su salario: \n");
	*salary = salario;
	sector1 = PedirEntero ("Ingrese el sector: \n", MIN, MAX);
	*sector = sector1;
	return retorno;
}

int AddEmployee (Employee list[], int tam, int id, char name[], char lastName[], float salary, int sector) // tengo que pasarle datos sí o sí (enunciado)
{
	int i;
	int retorno;
	retorno = -1;

	for (i=0; i<tam; i++)
	{
		if (list[i].isEmpty == 1)
		{
			list[i].id = id;
			strcpy (list[i].name, name);
			strcpy (list[i].lastName, lastName);
			list[i].salary = salary;
			list[i].sector = sector;
			list[i].isEmpty = 0;

			retorno = 0;
			break;
		}
	}

	return retorno;
}

/// @fn int PedirCadena(char[], char[]): Pide una cadena mediante un mensaje
/// @param mensaje: pide la cadena
/// @param cadena: es la cadena donde se va a guardar lo solicitado
/// @return: retorna 0
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
		}
	}

	ArregloNombrePropio (cadena);

	return retorno;
}

/// @fn void ArregloNombrePropio(char[]): Convierte la primera letra de cada palabra de una cadena en mayúscula y todas las demás en minúscula
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

int FindEmployeeById (Employee list[], int len, int id) //retorna la posición del empleado a buscar
{
	int retorno;
	int i;

	retorno = -1;

	for (i=0; i<len; i++)
	{
		if (len>0 && list != NULL && list[i].id == id)
		{
			retorno = i;
			//retorno = i+1;
			break;
		}
	}

	return retorno;
}

int RemoveEmployee(Employee list[], int len, int id)
{
	int retorno;
	int i;

	retorno = -1;

	for (i=0; i<len; i++)
	{
		if ((len > 0) && (list != NULL) && (list[i].id == id) && (list[i].isEmpty == 0))
		{
			list[i].isEmpty = 1;
			retorno = 0;
			break;
		}
	}

	return retorno;
}

//Arreglar: ¿Qué pasa si no hay nada que ordenar?
int SortEmployees(Employee list[], int len, int order) //  ordenar por apellido y sector  ////////// REVISAR Y TENER EN CUENTA LOS CASOS DE "ERROR" O EN LOS QUE PODRÍA LLEGAR A PASAR ALGO "RARO"
{

	//CUANDO TODOS LOS APELLIDOS SON IGUALES NO ORDENA Y RETORNA = -1
	int i;
	int j;
	int retorno;
	retorno = -1; //IF INVALID LENGTH OR NULL POINTER

	for (i=0; i<len; i++)
	{
		for (j=i+1; j<len-1 ;j++)
		{
			switch (order)
			{
			case 1: // ascendente
				if (list[i].isEmpty == 0 && list[j].isEmpty == 0) //ESTO FUNCIONA TAMBIÉN CUANDO DOY DE BAJA: usa el primero de i no vacío y hasta que no encuentra uno de j no vacío no ordena.
				{
					if (/*list[i].isEmpty == 0 && list[j].isEmpty == 0 &&  */strcmp (list[i].lastName, list[j].lastName) != 0) //primero por apellido, después por sector (Si entra acá por lo menos va a haber dos distintos)
					{
						if (strcmp(list[i].lastName, list[j].lastName) > 0)
						{
							Ordenar (list, len, i, j);
							retorno = 0;
						}
					}
					else // si los apellidos son iguales
					{
						if (list[i].sector > list[j].sector)
						{
							Ordenar (list, len, i, j);
							retorno = 0;
						}
						else
						{
							retorno = 0;
						}

					}
				}
				else
				{
					if (list[i].isEmpty == 0 && list[j].isEmpty == 1)
					{
						retorno = 0;
					}
				}
				break;

			case 2: //descendente
				if (list[i].isEmpty == 0 && list[j].isEmpty == 0)
				{
					if (list[i].lastName != list[j].lastName)
					{
						if (strcmp(list[i].lastName, list[j].lastName) < 0)
						{
							Ordenar (list, len, i, j);
							retorno = 0;
						}
					}
					else
					{
						if (list[i].sector < list[j].sector)
						{
							Ordenar (list, len, i, j);
							retorno = 0;
						}
					}
				}
				break;
			}
		}
	}

	return retorno;
}

/// @fn void Ordenar(Employee[], int, int, int): ordena un vector
/// @param list: es la lista a ordenar
/// @param len: es el tamaño de la lista
/// @param i: es la posición i del vector;
/// @param j: es la posición j del vector;
void Ordenar (Employee list[], int len, int i, int j)
{
	Employee guardar;

	guardar = list[i];
	list[i] = list[j];
	list[j] = guardar;
}

int PrintEmployees(Employee list[], int length)
{
	int i;

	for (i=0; i<length; i++)
	{
		if (list[i].isEmpty == 0)
		{
			PrintAnEmployee (list[i]);
		}
	}

	return 0;
}

/// @fn void PrintAnEmployee(Employee): imprime en pantalla un vector
/// @param empleado: es el empleado que va a imprimir la función
void PrintAnEmployee (Employee empleado)
{
	printf ("%6d %10s %10s %8.2f %4d \n", empleado.id, empleado.name, empleado.lastName, empleado.salary, empleado.sector);
}

/// @fn float PromediarSalarios(Employee[], int, float*): calcula el promedio de los salarios de una lista de empleados
/// @param list: es la lista de los empleados
/// @param tam: es el tamaño de la lista
/// @param sumaSalarios1: es la suma de los salarios de los empleados de la lista
/// @return: devuelve el promedio calculado
float PromediarSalarios (Employee list[], int tam, float* sumaSalarios1)
{
	int i;
	int cantEmployees;
	float sumaSalarios;
	float promedio;

	cantEmployees = 0;
	sumaSalarios = 0;

	for (i=0 ; i<tam; i++)
	{
		if (list[i].isEmpty == 0) //si no está vacío
		{
			sumaSalarios = sumaSalarios + list[i].salary;
			cantEmployees ++;
		}
	}

	*sumaSalarios1 = sumaSalarios;

	promedio = sumaSalarios / cantEmployees;

	return promedio;
}

/// @fn int ContarSuperanSalarioPromedio(Employee[], int, float): cuenta la cantidad de empleados que superan el salario promedio
/// @param list: es la lista de los empleados
/// @param tam: es el tamaño de la lista
/// @param salarioPromedio: es el salario promedio entre los empleados del array
/// @return: retorna la cantidad de empleados que superan el salario promedio
int ContarSuperanSalarioPromedio (Employee list[], int tam, float salarioPromedio)
{
	int i;
	int cantidadSuperanSalarioPromedio;

	cantidadSuperanSalarioPromedio = 0;

	for (i=0; i<tam; i++)
	{
		if (list[i].isEmpty == 0 )
		{
			if (list[i].salary > salarioPromedio)
			{
				cantidadSuperanSalarioPromedio ++;
			}
		}
	}

	return cantidadSuperanSalarioPromedio;
}
