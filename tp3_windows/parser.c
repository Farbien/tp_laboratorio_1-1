#include "Parser.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{	//FILE* pFile = recibe la dirección de memoria de la lista
	int retorno;

	Employee* empleado;
	char auxId[10];
	char auxNombre[128];
	char auxHorasTrabajadas[10];
	char auxSueldo[8];
	int retornoAdd;

	FILE* ultimoId;

	retorno = 0;

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);

	//empleado = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);

	while(!feof(pFile))
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo); //esto está todo en formato de texto
                                                                                            //y newParametros recibe texto
		empleado = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);

		retornoAdd = ll_add(pArrayListEmployee, empleado);
		if (retornoAdd == 0)
		{
			retorno = 1;
		}

		ultimoId = fopen ("ultimoId.txt", "w");
		fprintf (ultimoId, "%s", auxId);
		fclose (ultimoId);

	}
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* empleado;
	int retorno;
	int retornoAdd;

	retorno = 0;

	while (!feof(pFile))
	{
		empleado = employee_new ();

		fread(empleado, sizeof (Employee), 1, pFile); //se guarda en empleado

		retornoAdd = ll_add(pArrayListEmployee, empleado);

		if (retornoAdd == 0)
		{
			retorno = 1;
		}
	}
    return retorno;
}
