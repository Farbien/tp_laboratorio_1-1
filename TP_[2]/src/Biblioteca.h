/*
 * Biblioteca.h
 *
 *  Created on: 16 oct. 2021
 *      Author: lukit
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty; //estado
}Employee;

int CAL_esFloat(char cadena[], int dimension);
void ArregloNombrePropio (char cadena[]);
int ContarSuperanSalarioPromedio (Employee list[], int tam, float salarioPromedio);
int VerificarRango (int numero, int min, int max);
void Inicializar (int listado[], int len);
void GuardarIdBajas (int listado[], int len, int id);
int ModificarDato (Employee empleados[], int tam);
float PedirFlotante (char mensaje[]);
/*int PedirFlotante (char mensaje[], float* numero);*/
/* int PedirEntero (char mensaje[], int* numero);*/
int PedirEntero (char mensaje[], int min, int max);
int PedirCadena (char mensaje[], char cadena[]);
/*int IdAutomatico (Employee empleados[], int tam, int listaIdBajas[], int tamIdBajas);*/
int IdAutomatico1 (Employee empleados[], int tam, int listaIdBajas[], int tamIdBajas);
//int PedirEmpleado (Employee empleados[], int tam, int listaBajas[], int* id, char lastName[], char name[], float* salary, int* sector);
int PedirEmpleado (Employee empleados[], int tam, int listaBajas[], int* id, char Name[], char lastName[], float* salary, int* sector);
int InitEmployees(Employee list[], int tam);
int AddEmployee (Employee list[], int tam, int id, char name[], char lastName[], float salary, int sector);
int FindEmployeeById(Employee list[], int len, int id);
int RemoveEmployee(Employee list[], int len, int id /*,int listaIdBajas [] */); //arreglar lo de listaIdBajas porque no se pueden modificar los prototipos
int SortEmployees(Employee list[], int len, int order); //  ordenar por apellido y sector
void Ordenar (Employee list[], int len, int i, int j);
int PrintEmployees(Employee list[], int length);
void PrintAnEmployee (Employee empleado);
int ListarSuperanSalarioPromedio (Employee empleados[], int tam, float salarioPromedio);
float PromediarSalarios (Employee empleados [], int tam, float* sumaSalarios1);

#endif /* BIBLIOTECA_H_ */
