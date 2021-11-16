/*
 ============================================================================
 Name        : Tp2.c
 Author      : Diego
 Version     : v1.01
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "ArrayEmployees.h"

#define t_Emp 10 // Change large for more employees

int main(void) {

	setbuf(stdout, NULL);


	Employee arrayEmpleados[t_Emp];

	int opcion;
	int salir=0;
	int id=101;
	int altaEmpleados;
	int bajaEmpleados;
	int modificarEmpleados;
	int infomarEmpleados;

	emp_HardcodearEmployees(arrayEmpleados, t_Emp); //Harcodear datos ACTIVAR funcion

	//emp_initEmployees(arrayEmpleados, t_Emp);  //hardcodear datos COMENTAR funcion


	printf( "Nombre: DIEGO MARIN 1(c)       \n"
			"Nro de TP:  2					\n"
			"Descripcion: A.B.M.I Empleados \n"
			"Semestre: 1                    \n");


	printf("\nEnjoy :,)\n\n");



	do {

			if(utn_getNumero(&opcion,
				    "\t\tPrograma de Empleados en C:\n\n"
				    "\t\t1) ALTA Empleado\n\n"
					"\t\t2) MODIFICACIÓN Empleado\n\n"
					"\t\t3) BAJA Empleado\n\n"
					"\t\t4) INFORMAR Empleado\n\n"
					"\t\t5) Salir\n"
					""
					"\n==============================================================================\n\n"
					"\t\tOpcion: ", "\nError, opcion invalida\n\n", 0, 5, INT_MAX)==0)
			{

				switch (opcion) {

				case 1:

					if (emp_findEmptySpace(arrayEmpleados, t_Emp) >= 0) {
						altaEmpleados = emp_AltaEmpleados(arrayEmpleados, t_Emp, &id);
						if (altaEmpleados == 0) {
							printf("\n\t\tALTA COMPLETADA\n\n");
						}
						else{

							if(altaEmpleados == 1){
								printf("\nError, ingresa bien los datos, volve a intentarlo\n\n");
							}
							else{
								printf("\nError, lenth invalido o NULL pointer \n\n");
							}
						}
					}
					else{
						printf("\n\tNo hay espacio disponible\n\n");
					}

					break;

				case 2:
					if (emp_checkEmployee(arrayEmpleados, t_Emp) == 0) {
						emp_orderEmployeesById(arrayEmpleados, t_Emp);
						modificarEmpleados = emp_ModificarEmpleados(arrayEmpleados, t_Emp);
						switch (modificarEmpleados) {
							case 0:
								printf("\n\t\tMODIFICAION COMPLETADA\n\n");
								break;
							case 1:
								printf("\n\t\tMODIFICACION CANCELADA\n\n");
								break;
							case 2:
								printf("\n\n");
								break;
							case -1:
								printf("\n\t\tNo existe ese id o fue dado antes de baja \n\n");
								break;
						}
					}
					else{
						printf("\n\tNo hay Empleados en el sistema para modificar un empleado\n\n");
					}

					break;

				case 3:

					if(emp_checkEmployee(arrayEmpleados, t_Emp) == 0){
						emp_orderEmployeesById(arrayEmpleados, t_Emp);
						bajaEmpleados = emp_BajaEmpleados(arrayEmpleados, t_Emp);
						switch (bajaEmpleados) {
							case  0:
								printf("\n\t\tBAJA COMPLETADA\n\n");
								break;
							case -2:
								printf("\n\t\tNo existe ese id o fue dado antes de baja \n\n");
								break;
							case  1:
								printf("\n\t\tBAJA CANCELADA\n\n");
								break;
							case -1:
								printf("\n\t\tError, lenth invalido o NULL pointer\n\n");
								break;
						}
					}
					else{
						printf("\n\tNo hay Empleados en el sistema para dar de baja\n\n");
					}

					break;

				case 4:
					if(emp_checkEmployee(arrayEmpleados, t_Emp) == 0){
						emp_orderEmployeesById(arrayEmpleados, t_Emp);
						infomarEmpleados = emp_InformarEmpleados(arrayEmpleados, t_Emp);
						if(infomarEmpleados==0){
							printf("\n\t\tINFORMAR COMPLETADO\n\n");
						}
						else{
							if(infomarEmpleados==-1){
								printf("\nError, lenth invalido o NULL pointer\n\n");
							}
						}
					}
					else{
						printf("\n\tNo hay Empleados en el sistema para informar empleados\n\n");
					}

					break;

				case 5:

					printf("\nSalir Completado\n");
					system("pause");
					salir = 1;
					break;

				default:

					printf("\nOpcion Invalida\n");
					break;
				}
			}


		} while ( salir == 0 );


	printf("\nAPLICACION CERRADA\n");

	return EXIT_SUCCESS;
}
