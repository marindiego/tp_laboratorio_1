/*
 * Employee.h
 *
 *  Created on: 10 nov. 2021
 *      Author: Usuario
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "utn_funciones.h"

#define CARGADO 0
#define VACIO 1

typedef struct{

	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}Employee;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int emp_initEmployees(Employee* list, int len);
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
*/
int addEmployee(Employee* list, int len, int id, char name[],
char lastName[],float salary,int sector);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id);
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);
/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int length);

/** \brief Register an Employee in the system with the help of the addEmployee function
 *
 * \param list Employee*
 * \param len int
 * \param id int* ( The main has to have an  automatic id pointer )
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if the employee charged the system
 *
 */

/*		 __________________________
 *		|                          |
 *      | MIS FUNCIONES PARA EL TP |
 *      |__________________________|
 */
/** \brief  Return the Index position
 *
 * \param list Employee*
 * \param len int
 * \param id int*
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (1) if its bad data entry -(0) if Ok
 *
 */
int emp_AltaEmpleados(Employee* list, int len, int* id);
/** \brief The main function that remove an employee with the call of other functions
 *
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] or (-2) if can't
find a employee - (1) if the usuary does not want to removee the id - (0) if Ok
 *
 */
int emp_BajaEmpleados (Employee* list, int len);
/** \brief  The main function that is responsible for modifying any field of an employee
 *
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] or (-2) if Its an
  invalid opcion - (1) if the usuary does not want to change the employee  - (-3) Not found if - (0) if ok
 *
 */
int emp_ModificarEmpleados (Employee* list, int len);
/** \brief  Return the Index position
 *
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if it found a free space
 *
 */
int emp_findEmptySpace (Employee* list, int len);
/** \brief  asks for passage by reference 0 if it continues 1 if it cancels
 *
 * \param mensaje char*
 * \return int Return (-1) if cancel - (0) if continue
 *
 */
int emp_confirmDecision (char* mensaje);
int	emp_InformarEmpleados (Employee* list, int len);
/** \brief  Verify that there is at least one employee in the system
 *
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if it found a employee - (0) if it doesnt
 *
 */
int emp_checkEmployee (Employee* list, int len);
/** \brief print the content of 1 employee
 *
 * \param list Employee*
 * \return int
 *
 */
int printEmployee(Employee* list);
/** \brief Load 10 employees sequentially or if you want adding another employee will load in the array
 *
 * \param list Employee*
 * \param int empleados
 * \return int Return (-1) if Error [Invalid length or NULL pointer] or (0) if ok
 *
 */
int emp_HardcodearEmployees (Employee* list, int empleados);
/** \brief Modify any field in the Employee structure that was loaded before
 *
 * \param list Employee*
 * \param int opcion
 * \return int Index (-1) if Error [Invalid length or NULL pointer or Cancel Modification] or - (0) if ok
 *
 */
int emp_changeEmployeeSpace (Employee* list,int opcion , int index);
/** \brief Order Employees by their Id
 *
 * \param list Employee*
 * \param int opcion
 * \return int Return (-1) if Error [Invalid length or NULL pointer] or how many iterations the function did it
 */
int emp_orderEmployeesById (Employee* lista,int len);
/** \brief  administers and reports everything related to the salary of an employee
 *
 * \param list Employee*
 * \param int len
 * \return int (-1) if Error Pointer NULL or len and order <0 or there is not space or - (0) if ok
 */
int emp_checkEmployeeSalary (Employee* list,int len, int order);
/** \brief  Operate employees's salary
 *
 * \param list Employee*
 * \param int len
 * \param inr order
 * \return int Return (-1) if Error [Invalid length or NULL pointer or No space] (0) if Ok
 */
float emp_salaryEmployees (Employee* list, int len);
/** \brief  Operate employees's salary
 *
 * \param list Employee*
 * \param int len
 * \param int salario
 * \return int Return (-1) if Error [Invalid length or NULL pointer or No space] (0) if Ok
 */
float emp_promedyEmployees (Employee* list, int len, float salario);
#endif /* ARRAYEMPLOYEES_H_ */
