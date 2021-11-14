#include "Employee.h"

Employee* employee_new()
{
	Employee* empleadoRetorno;

	empleadoRetorno = (Employee*) malloc(sizeof(Employee));

	if (empleadoRetorno != NULL)
	{
		empleadoRetorno = calloc (1, sizeof(Employee));
	}
	return empleadoRetorno;
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* empleadoRetorno;

	empleadoRetorno = employee_new();

	if (empleadoRetorno != NULL)
	{
		employee_setId (empleadoRetorno, atoi(idStr));
        employee_setNombre (empleadoRetorno, nombreStr);
        employee_setHorasTrabajadas (empleadoRetorno, atoi(horasTrabajadasStr));
        employee_setSueldo (empleadoRetorno, atoi(sueldoStr));
	}

	return empleadoRetorno;
}

void employee_delete(Employee* this)
{
	if (this != NULL)
	{
		free (this);
	}
}

int employee_setNombre(Employee* this, char* nombre)
{
	int retorno;
	retorno = 0;

	if (this != NULL && nombre != NULL /*esNombre(nombre) */)//desarrollar la función esNombre que chequee que una cadena es un nombr
	{
		strcpy (this->nombre, nombre);
		retorno = 1;

	}
	return retorno;
}

int employee_getNombre(Employee* this, char* nombre)
{
	int retorno;
	retorno = 0;

	if (this != NULL && nombre !=NULL )
	{
		strcpy(nombre, this->nombre);
		retorno = 1;
	}

	return retorno;
}

int employee_setId(Employee* this, int id)
{
	int retorno;
	retorno = 0;

	if (this!=NULL && id>0 /*  && esNumero(id)*/)
	{
		this->id = id;
		retorno = 1;
	}

	return retorno;
}

int employee_getId(Employee* this, int* id)
{
	int retorno;
	retorno = 0;

	if (this !=NULL && id>0)
	{
		*id = this->id;
		retorno = 1;
	}

	return retorno;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
	int retorno;
	retorno = 0;

	if (this != NULL && horasTrabajadas >-1)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 1;
	}

	return retorno;
}
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
	int retorno;
	retorno = 0;

	if (this != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 1;
	}

	return retorno;
}

int employee_setSueldo(Employee* this, int sueldo)
{
	int retorno;
	retorno = 0;

	if (this != NULL && sueldo > 0)
	{
		this->sueldo = sueldo;
		retorno = 1;
	}

	return retorno;
}

int employee_getSueldo(Employee* this, int* sueldo)
{
	int retorno;
	retorno = 0;

	if (this != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 1;
	}

	return retorno;
}

Employee* BuscarEmpleado (FILE* pFile, int idBuscado)
{
	Employee* retornoEmpleado;
	Employee* empleado;
	char id[50];
	char nombre[50];
	char hs[50];
	char sueldo[50];

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, hs, sueldo);

	while(!feof(pFile))
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, hs, sueldo);

		empleado = employee_newParametros (id, nombre, hs, sueldo);

		if (empleado->id == idBuscado)
		{
			retornoEmpleado = empleado;
			break;
		}
	}

	return retornoEmpleado;
}

int PrintOneEmployee (Employee* pElement)
{
	int retorno;
	retorno = 0;
	//printf ("id Nombre Horas Trabajadas Sueldo\n"); //arreglar espaciado
	//printf ("%.7s %.7s %15s %6s", "id", "Nombre", "Horas Trabajadas", "Sueldo");
	int idGet;
	char nombreGet[50];
	int horasGet;
	int sueldoGet;

	if (pElement != NULL)
	{
		employee_getId (pElement, &idGet);
		employee_getNombre (pElement, nombreGet);
		employee_getHorasTrabajadas (pElement, &horasGet);
		employee_getSueldo (pElement, &sueldoGet);

		//%7s %7s %15s %6s
	    printf ("%7d | %10s | %15d | %7d\n", idGet, nombreGet, horasGet, sueldoGet);
	    retorno = 1;
	}

	return retorno;
}

