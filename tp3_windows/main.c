#include "Controller.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salr
*****************************************************/

int main()
{
	setbuf(stdout, NULL);

	//Employee list[20];
	LinkedList* listaEmpleados;
	int retornoControllerText;
	int retornoControllerBinary;
	int retornoControllerAdd;
	int retornoControllerEdit;
	int retornoControllerRemove;
	int retornoControllerSort;
	int retornoControllerList;
	int retornoControllerSaveText;
	int retornoControllerSaveBinary;
	int seguir;
	int opcion;
	int i;

	listaEmpleados = ll_newLinkedList();

	seguir = 1;

	do {
		printf ("\n/****************************************************\n    Menu:\n     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n     3. Alta de empleado\n     4. Modificar datos de empleado\n     5. Baja de empleado\n     6. Listar empleados\n     7. Ordenar empleados\n     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n    10. Salir\n*****************************************************/\n");
		opcion = PedirEntero("Seleccione una opción: ");
		while (opcion < 1 || opcion > 10)
		{
			opcion = PedirEntero("Error! Seleccione una opción válida: ");
		}

		switch (opcion)
		{
		case 1:
			retornoControllerText = controller_loadFromText ("data.csv", listaEmpleados);
			if (retornoControllerText == 1)
			{
				printf ("\nEmpleados cargados en modo texto\n");
			}
			break;

		case 2:
			retornoControllerBinary = controller_loadFromBinary ("data.csv", listaEmpleados);
			if (retornoControllerBinary == 1)
			{
				printf ("\nEmpleados cargados en modo binaria");
			}
			break;

		case 3:
			retornoControllerAdd = controller_addEmployee (listaEmpleados);
			break;

		case 4:
			retornoControllerEdit = controller_editEmployee(listaEmpleados);
			break;

		case 5:
			retornoControllerRemove = controller_removeEmployee(listaEmpleados);
			break;
		case 6:
			retornoControllerList = controller_ListEmployee(listaEmpleados);
			break;

		case 7:
			retornoControllerSort = controller_sortEmployee(listaEmpleados);
			break;

		case 8:
			retornoControllerSaveText = controller_saveAsText("data.csv", listaEmpleados);
			if (retornoControllerSaveText == 1)
			{
				printf ("Datos cargados en modo texto");
			}
			break;

		case 9:
			retornoControllerSaveBinary = controller_saveAsBinary("data.csv", listaEmpleados);
			if (retornoControllerSaveBinary == 1)
			{
				printf ("Datos cargados en modo binario");
			}
			break;

		case 10:
			seguir = !1;

			ll_deleteLinkedList(listaEmpleados);
			break;
		}

	}while (seguir == 1);

	return 0;
}

