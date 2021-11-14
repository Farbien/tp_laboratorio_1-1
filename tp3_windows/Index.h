#ifndef INDEX_H_
#define INDEX_H_
#include "LinkedList.h"
#include "Parser.h"
#include "Employee.h"

Employee* employee_getEmployeeById (LinkedList* this, int tam, int idBusqueda);
int MostrarEmpleados (LinkedList* this, int tam);
int CompararElementos (void* empleado1, void* empleado2);
int PedirCadena (char mensaje[], char cadena[]);
int PedirEntero (char mensaje[]);
void ArregloNombrePropio (char cadena[]);

#endif /* INDEX_H_ */
