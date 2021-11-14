#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* pArchivo;
	int retornoParser;

	retorno = 0;

	pArchivo = fopen(path, "r");

	if(pArchivo != NULL)
	{
		retornoParser = parser_EmployeeFromText (pArchivo, pArrayListEmployee);
		if (retornoParser == 1)
		{
			retorno = 1;
		}
	}

	fclose (pArchivo);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* pArchivo;
	int retornoParser;

	retorno = 0;

	pArchivo = fopen (path, "rb");

	if (pArchivo != NULL)
	{
		retornoParser = parser_EmployeeFromBinary (pArchivo, pArrayListEmployee);
		if (retornoParser == 1)
		{
			retorno = 1;
		}
	}

	fclose (pArchivo);

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee* empleado;
	FILE* fileUltimoId;
	int lastId;
	int nuevoId;
	char nuevoNombre[50];
	int nuevasHoras;
	int nuevoSueldo;
	int retornoAdd;

	retorno = 0;

	empleado = employee_new();
	//FALTA ID

	fileUltimoId = fopen ("ultimoId.txt", "r");

	fscanf (fileUltimoId, "%d", &lastId);

	fclose (fileUltimoId);

	nuevoId = lastId + 1;

	employee_setId (empleado, nuevoId);

	PedirCadena ("Ingrese el nombre: \n", nuevoNombre);
	employee_setNombre (empleado, nuevoNombre);

	nuevasHoras = PedirEntero ("Ingrese las horas trabajadas: \n");
	employee_setHorasTrabajadas (empleado, nuevasHoras);

	nuevoSueldo = PedirEntero ("Ingrese el sueldo: \n");
	employee_setSueldo (empleado, nuevoSueldo);

	retornoAdd = ll_add (pArrayListEmployee, empleado);

	fileUltimoId = fopen ("ultimoId.txt", "w");
	lastId = nuevoId;
	fprintf (fileUltimoId, "%d", lastId);
	fclose (fileUltimoId);

	if (retornoAdd)
	{
		printf ("Empleado agregado");
	}
	retorno = 1;

    return retorno;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee* empleadoBuscado;
	//FILE* pArchivo;
	int tamLista;
	int opcion;
	int idMod;
	char nombreMod[50];
	int sueldoMod;
	int horasMod;
	int retornoSetNombre;
	int retornoSetSueldo;
	int retornoSetHoras;
	int indiceEmpleado;
	int retornoMostrar;

	retorno = 0;

	tamLista = ll_len(pArrayListEmployee);

	retornoMostrar = MostrarEmpleados (pArrayListEmployee, tamLista);

	if (retornoMostrar == 0)
	{
		printf ("No hay empleados que mostrar");
	}

	idMod = PedirEntero ("Ingrese el id del empleado a modificar: ");

	empleadoBuscado = employee_getEmployeeById (pArrayListEmployee, tamLista, idMod);

	indiceEmpleado = ll_indexOf(pArrayListEmployee, empleadoBuscado);

	printf ("\nSeleccione el dato que desea modificar: 1-Nombre  2-Horas Trabajadas  3-Sueldo");
	scanf ("%d", &opcion);

	switch (opcion)
	{
	case 1:
		PedirCadena("Ingrese el nuevo nombre: ", nombreMod);
		retornoSetNombre = employee_setNombre (empleadoBuscado, nombreMod);
		if (retornoSetNombre == 1)
		{
			printf ("Nombre cambiado con éxito.");
		}
		else
		{
			printf ("No se pudo modificar el nombre");
		}
		break;

	case 2:
		horasMod = PedirEntero ("Ingrese las nuevas horas: ");
		retornoSetHoras = employee_setHorasTrabajadas(empleadoBuscado, horasMod);
		if (retornoSetHoras == 1)
		{
			printf ("Horas Trabajadas cambiadas con éxito.");
		}
		else
		{
			printf ("No se pudieron modificar las horas trabajadas");
		}
		break;

	case 3:
		sueldoMod = PedirEntero ("Ingrese el nuevo sueldo: ");
		retornoSetSueldo = employee_setSueldo (empleadoBuscado, sueldoMod);
		if (retornoSetSueldo == 1)
		{
			printf ("Sueldo cambiado con éxito.");
		}
		else
		{
			printf ("No se pudo modificar el sueldo");
		}
		break;
	}

	/*Preg si con esto ya lo edita en la linked*/
	ll_set(pArrayListEmployee, indiceEmpleado, empleadoBuscado);

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee* empleadoARemover;
	int indiceEmpleado;
	int retornoRemove;
	int idBuscado;
	int tamLista;
	int retornoMostrar;
	retorno = 0;

	tamLista = ll_len(pArrayListEmployee);

	retornoMostrar = MostrarEmpleados (pArrayListEmployee, tamLista);

	if (retornoMostrar == 0)
	{
		printf ("No hay empleados cargados");
	}

	idBuscado = PedirEntero("Ingrese el id del empleado a remover: ");

	empleadoARemover = employee_getEmployeeById (pArrayListEmployee, tamLista, idBuscado);

	indiceEmpleado = ll_indexOf(pArrayListEmployee, empleadoARemover);

	retornoRemove = ll_remove(pArrayListEmployee, indiceEmpleado);

	if (retornoRemove == 0)
	{
		printf ("Se eliminó el empleado con éxito");
		retorno = 1;
	}
	else
	{
		printf ("Hubo un error al eliminar el empleado, inténtelo de nuevo");
		retorno = -1;
	}

	employee_delete (empleadoARemover);

	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
   int retorno;
   int retornoEmpleado;
   int tam;
   int i;
   Employee* empleado;

   retorno = 0;

   tam = ll_len (pArrayListEmployee);

   printf ("%7s | %10s | %12s|  %7s", "id", "Nombre", "Horas Trabajadas", "Sueldo\n");

   for (i=0; i<tam; i++)
   {
	   empleado = ll_get(pArrayListEmployee, i);

	   retornoEmpleado = PrintOneEmployee (empleado);

	   if (retornoEmpleado == 0)
	   {
	    	printf ("No se encontró el empleado");
	   }
   }

   return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int retornoSort;

	retorno = 0;

	retornoSort = ll_sort (pArrayListEmployee, CompararElementos, 1);
	if (retornoSort )
	{
		retorno = 1;
	}

	return retorno;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	//con :	fprintf: escribe en modo texto
	int retorno;
	FILE* pArchivo;
	Employee* empleado;
	int auxId;
	int retornoGetId;
	char auxNombre[50];
	int retornoGetNombre;
	int auxHoras;
	int retornoGetHoras;
	int auxSueldo;
	int retornoGetSueldo;
	int tamLista;
	int i;

	retorno = 0;

	pArchivo = fopen (path, "w");

	tamLista = ll_len(pArrayListEmployee);

	for (i=0; i<tamLista; i++)
	{
		empleado = ll_get (pArrayListEmployee, i);
		retornoGetId = employee_getId (empleado, &auxId);
		if (retornoGetId == 0)
		{
			printf ("No se pudo obtener el id");
		}

		retornoGetNombre = employee_getNombre (empleado, auxNombre);
		if (retornoGetNombre == 0)
		{
			printf ("No se pudo obtener el nombre");
		}

		retornoGetHoras = employee_getHorasTrabajadas (empleado, &auxHoras);
		if (retornoGetHoras == 0)
		{
			printf ("No se pudieron obtener las horas trabajadas");
	    }

		retornoGetSueldo = employee_getSueldo (empleado, &auxSueldo);
		if (retornoGetSueldo == 0)
		{
			printf ("No se pudo obtener el sueldo");
		}

		fprintf (pArchivo, "%d,%s,%d,%d\n", auxId, auxNombre, auxHoras, auxSueldo);
		retorno = 1;
	}

	fclose (pArchivo);

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	//con :	fwrite: escribe en modo binario
	int retorno;
	Employee* empleado;
	FILE* pArchivo;
	int tamLista;
	int i;

	retorno = 0;

	tamLista = ll_len (pArrayListEmployee);

	pArchivo = fopen (path, "wb");

	for (i=0; i<tamLista; i++)
	{
		empleado = ll_get (pArrayListEmployee, i);
		fwrite (empleado, sizeof(Employee), 1, pArchivo);
		retorno = 1;
	}

	fclose (pArchivo);

    return retorno;
}
