/*
Lucas Emmanuel Mendoza
TP 2
Enunciado
Una empresa requiere un sistema para administrar su n�mina de empleados.
Se sabe que dicha n�mina bajo ninguna
circunstancia superara los 1000 empleados.
Datos:
El sistema deber� tener el siguiente men� de opciones:
1. ALTAS: Se debe permitir ingresar un empleado calculando
autom�ticamente el n�mero de Id. El resto de los
campos se le pedir� al usuario.
2. MODIFICAR: Se ingresar� el N�mero de Id,
permitiendo modificar: o Nombre o Apellido o Salario o Sector.
3. BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.
4. INFORMAR:
	1. Listado de los empleados ordenados alfab�ticamente por Apellido y Sector.
	2. Total y promedio de los salarios, y cu�ntos empleados superan
	el salario promedio.

NOTA: Se deber� realizar el men� de opciones y las validaciones
a trav�s de funciones.

Tener en cuenta que no se podr� ingresar a los casos 2, 3 y 4;
sin antes haber realizado la carga de alg�n empleado.
Para la realizaci�n de este programa, se utilizar� una biblioteca
llamada �ArrayEmployees� que
facilitar� el manejo de la lista de empleados y su modificaci�n.
En la secci�n siguiente se
detallan las funciones que esta biblioteca debe tener.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Biblioteca.h"
#define TAMCLIENTES 1000
#define MIN 1
#define MAX 10

int main(void)

{
	setbuf (stdout, NULL);

	Employee empleados[TAMCLIENTES];
	int listaDadosDeBaja [TAMCLIENTES];

	int banderaPrimerIngreso;

	/*	//datos empleado*/
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;


	int opcion;
	char subopcion;
	char seguir;

	int retornoModif;

	int idParaDarDeBaja;
	int baja;

	int retornoSort;

	float promSalarios;
	float sumaSalariosMain;
	int cantSuperanSalarioProm;

	banderaPrimerIngreso = 0;

	seguir = 's';

	InitEmployees (empleados, TAMCLIENTES); //inicializo los estados de los vectores
	Inicializar (listaDadosDeBaja, TAMCLIENTES);

	do {
	printf ("\nMen� de opciones: ");
	printf ("\n1)Ingresar un empleado: ");
	printf ("\n2)Modificar: ");
	printf ("\n3)Eliminar empleado: ");
	printf ("\n4)Informar: \n a)Listado de los empleados ordenados alfab�ticamente por Apellido y Sector \n b)Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio");

	opcion = PedirEntero ("Ingrese una opci�n: \n", 1, 4);

	if (banderaPrimerIngreso == 0)
	{
		if (opcion == 2 || opcion == 3 || opcion == 4)
		{
			printf ("Primero debe ingresar un empleado (Opci�n 1)\n");
		}
	}

	switch (opcion)
	{
	case 1:
		//Arreglar bien los retornos:
		PedirEmpleado (empleados, TAMCLIENTES, listaDadosDeBaja, &id, lastName, name, &salary, &sector);
		AddEmployee(empleados, TAMCLIENTES, id, lastName, name, salary, sector);
		banderaPrimerIngreso = 1;
		break;

	case 2:
		PrintEmployees (empleados, TAMCLIENTES);
		retornoModif = ModificarDato (empleados, TAMCLIENTES);
		if (retornoModif == 0)
		{
			printf ("No se ha realizado ninguna modificaci�n\n");
		}
		break;

	case 3:
		PrintEmployees (empleados, TAMCLIENTES);
		idParaDarDeBaja = PedirEntero ("Ingrese el id a dar de baja: \n", 1, 1000);
		baja = RemoveEmployee (empleados, TAMCLIENTES, idParaDarDeBaja);
		if (baja == 0)
		{
			printf ("El empleado ha sido dado de baja\n");
		}
		else
		if (baja == -1)
		{
			printf ("No se encontr� el empleado para dar de baja\n");
		}

		GuardarIdBajas (listaDadosDeBaja, TAMCLIENTES, idParaDarDeBaja);

		break;

	case 4:
		printf ("\nSeleccione una opci�n: \na)Listado de los empleados ordenados alfab�ticamente por Apellido y Sector \n b)Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio \n ");
		scanf("%c", &subopcion);
		if (subopcion != 'a' && subopcion != 'b')
		{
			printf ("Ingrese una opci�n correcta: a/b\n");
			scanf ("%c", &subopcion);
		}
		switch (subopcion)
		{
			case 'a':
				retornoSort = SortEmployees (empleados, TAMCLIENTES, 1);
				if (retornoSort == -1)
				{
					printf ("No hay elementos para ordenar");
				}
				else
				{
					printf ("    id     Nombre   Apellido  Salario  Sector\n"); //arreglar espaciado
					PrintEmployees (empleados, TAMCLIENTES);
				} //6 10 15 6 4
				break;

			case 'b':
				promSalarios = PromediarSalarios(empleados, TAMCLIENTES, &sumaSalariosMain);
				printf ("El total de los salarios es %f\n", sumaSalariosMain);

				cantSuperanSalarioProm = ContarSuperanSalarioPromedio (empleados, TAMCLIENTES, promSalarios);
				printf ("La cantidad de empleados que superan el salario promedio es: %d\n", cantSuperanSalarioProm);

				break;
		}
		break;
	}

	}while(seguir == 's');

	return EXIT_SUCCESS;
} // fin main



