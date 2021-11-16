/*
 * Employee.c
 *
 *  Created on: 10 nov. 2021
 *      Author: Usuario
 */

#include "ArrayEmployees.h"



/*
 * |----- FUNCIONES EXTRAS------|
 *
 */
int emp_checkEmployee (Employee* list, int len){

	int i;
	int respuesta=-1; // Pointer NULL or len < 0 or there is not space
	if (list!=NULL && len>0) {
		for (i = 0; i < len; i++) {
			if(list[i].isEmpty != VACIO){
				respuesta=0; //There are space
				break;
			}
		}
	}

	return respuesta;
}

int emp_HardcodearEmployees (Employee *list, int empleados){

	int retorno=-1;
	int i;
	if(list!=NULL && empleados >= 0){
		retorno=0;
		Employee buffer[1000]=
				{{101,"Diego","Marin",10500,5,CARGADO},
				{102,"Carla","Suarez",2500,9,CARGADO},
				{103,"German","Scarafilo",4850,4,CARGADO},
				{104,"Carlos","Ramirez",4000,6,CARGADO},
				{105,"Hector","Alvarez", 5500,7,CARGADO},
				{106,"Edgar","Facundo",9800,15,CARGADO},
				{107,"Fabian","Geopolis",1900,9,CARGADO},
				{108,"David","Yiuta",1000,10,CARGADO},
				{109,"Octavio","Lepez",7600,2,CARGADO},
				{110,"Wilker","Fariñez",1500,5,CARGADO}};
				//Agregar Otro empleados

		for (i = 0; i < empleados; i++) {
			list[i]=buffer[i];
		}
	}

	return retorno;
}


int emp_initEmployees(Employee* list, int len){

	int retorno=-1;
	int i;

	if(list!=NULL && len>0){
		retorno=0;
		for (i = 0; i < len; i++) {
			list[i].isEmpty=VACIO;
		}
	}

	return retorno;
}

int emp_findEmptySpace (Employee* list, int len){

	int index=-1;
	int i;

	if(list!=NULL && len>0){
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == VACIO) {
				index = i;
				break;
			}
		}
	}

	return index;
}

int findEmployeeById(Employee* list, int len,int id){

	int index=-1;
	int i;
	if (list!=NULL && len>0 && id>0) {
		for (i = 0; i < len; i++) {
			if ( list[i].id == id &&
				 list[i].isEmpty == CARGADO )
			{
				index = i;
				break;
			}
		}
	}

	return index;
}
int emp_confirmDecision (char* mensaje){

	int confirmar=-1;
	int desicion;

	if(mensaje!=NULL && utn_getNumero(&desicion, mensaje, "\nSolo 1 o 0\n", 0, 1, 10)==0)
	{
		if (desicion == 0) {
			confirmar=0;
		}
	}

	return confirmar;
}

/*
 *
 * |--------- ALTA FUNCIONES ---------|
 *
*/


int addEmployee(Employee* list, int len, int id, char name[], char lastName[],float salary,int sector){

	int retorno=-1;
	int index;
	if(list!=NULL && len>0 && name!=NULL && lastName!= NULL && salary >0 && sector>=0){

		index = emp_findEmptySpace(list, len);
		if (index!=-1) {
			retorno=0;
			list[index].id = id;
			list[index].isEmpty = CARGADO;
			strcpy(list[index].name, name);
			strcpy(list[index].lastName, lastName);
			list[index].salary = salary;
			list[index].sector = sector;
		}
	}
	return retorno;
}
int emp_AltaEmpleados(Employee* list, int len, int* id){

	Employee buffer;
	int retorno=-1;
	int localId = *id;

	if (list!=NULL && len > 0  && id!=NULL)
	{
		retorno=1; //bad data entry

		if( utn_getCharNombre(buffer.name, "Nombre: ", "", 0, 50)==0 &&
		    utn_getCharNombre(buffer.lastName, "Apellido: ", "", 0,50)==0 &&
			utn_getFloat(&buffer.salary, "Salario: ", "", 1, 10000000, 0)==0 &&
			utn_getNumero(&buffer.sector, "Sector: ", "", 0, INT_MAX, 0)==0)
		{
			if (addEmployee(list, len, localId, buffer.name, buffer.lastName, buffer.salary, buffer.sector)==0)
			{
				retorno=0;
				(*id)++;
			}
		}
	}

	return retorno;
}



/*
 *
 * |----- BAJA EMPLEADOS ---------|
 *
*/
int emp_BajaEmpleados (Employee* list, int len){

	int retorno=-1; //NULL or len <0
	int idIngresado;
	if (list!=NULL && len>0 )
	{
		retorno=-3; // Its not a number
		printEmployees(list, len);
		if (utn_getNumero(&idIngresado, "\nId Baja: ", "\nError, intentalo de nuevo\n\n", 0, INT_MAX, 0)==0)
		{
			retorno=-2; // Not found id
			if(findEmployeeById(list, len, idIngresado)>=0)
			{
				retorno=1;// Cancel remove id
				if(emp_confirmDecision("\tConfirmar Baja = 0       Cancelar Baja = 1:  ")==0)
				{
					removeEmployee(list, len, idIngresado);
					retorno=0; // Ok
				}
			}
		}
	}

	return retorno;
}

int removeEmployee(Employee* list, int len, int id){

	int retorno=-1;
	int index;
	if (list!=NULL && len>0 && id>0)
	{
		index= findEmployeeById(list, len, id);
		if(index!=-1){
			retorno=0;
			list[index].isEmpty=VACIO;
		}
	}

	return retorno;
}


/*
 *  |------ MODIFICAR EMPLEADOS--------|
 */

int emp_changeEmployeeSpace (Employee* list,int opcion , int index){

	Employee buffer;
	int cambio=-1;
	if (opcion>=1 && list[index].isEmpty==CARGADO)
	{
		switch (opcion)
		{
			case 1:
				if(utn_getCharNombre(buffer.name, "Nuevo Nombre: ", "\nError, intentalo de nuevo\n", 0, 50)==0){

					if(emp_confirmDecision("\tConfimar Modificacion = 0    Cancelar Modificaion = 1: ")==0){

						cambio=0;
						strcpy(list[index].name,buffer.name);
					}
				}
				break;
			case 2:
				if( utn_getCharNombre(buffer.lastName, "Nuevo Apellido: ", "\nError, intentalo de nuevo\n", 0, 50)==0){

					if(emp_confirmDecision("\tConfimar Modificacion = 0    Cancelar Modificaion = 1: ")==0){

						cambio=0;
						strcpy(list[index].lastName,buffer.lastName);
					}
				}
				break;
			case 3:
				if(utn_getFloat(&buffer.salary, "Nuevo Salario: ", "\nError, intentalo de nuevo\n", 0, INT_MAX, 0)==0){

					if(emp_confirmDecision("\tConfimar Modificacion = 0    Cancelar Modificaion = 1: ")==0){

						cambio=0;
						list[index].salary=buffer.salary;
					}
				}
				break;
			case 4:
				if(utn_getNumero(&buffer.sector, "Nuevo Sector: ", "\nError, intentalo de nuevo\n", 0, INT_MAX, 0)==0){

					if(emp_confirmDecision("\tConfimar Modificacion = 0    Cancelar Modificaion = 1: ")==0){

						cambio=0;
						list[index].sector=buffer.sector;
					}
				}
				break;
		}
	}

	return cambio;
}

int emp_ModificarEmpleados (Employee* list, int len){

	int retorno=-3; //Pointer NULL or len <0
	int idIngresado;
	int opcion;
	int index;

	if (list!=NULL && len>0) {
		printEmployees(list, len);

		if ( utn_getNumero(&idIngresado, "\nId Modificar: ", "\nError, intentalo de nuevo\n\n", 0, INT_MAX, 0) ==0 )
		{
			retorno=-1; // -1 Not found Id
			index= findEmployeeById(list, len, idIngresado);
			if(index>=0)
			{
				retorno=-2; // -2 Wrong Seleccion
				if(utn_getNumero(&opcion,"\n0) Volver Menu\n"
										   "1) Nombre\n"
										   "2) Apellido\n"
										   "3) Salario\n"
										   "4) Sector\n"
										   "Opcion:    ", "\nError, intentalo de nuevo\n\n", 0, 4, 0)==0)
				{

					retorno=2; // Back Menu
					if(opcion!=0)
					{
						retorno=1;// 1 Cancel Modificacion
						if(emp_changeEmployeeSpace(list,opcion , index)==0)
						{
							retorno=0; // 0 ok
						}
					}
				}
			}
		}
	}

	return retorno;
}

/*
 *
 * |------- INFORMAR EMPLEADOS --------|
 *
 *
 */

int emp_orderEmployeesById (Employee* lista, int len){

	int retorno=-1;
	int i;
	int contador=0;
	int flagSwap;
	Employee buffer;
	if( lista!=NULL &&  len>0 ){
		do{
			flagSwap=0;
			for(i=0; i<len-1 ; i++){
				contador++;
				if( lista[i].id > lista[i+1].id)
				{
					flagSwap=1;
					buffer=lista[i];
					lista[i]=lista[i+1];
					lista[i+1]=buffer;
				}
			}
			len--;
		}while(flagSwap);

		retorno=contador;
	}

	return retorno;
}

int sortEmployees(Employee* lista, int len, int order){

	int retorno=-1;
	int i;
	int contador=0;
	int flagSwap;
	Employee auxPay;

	if( lista!=NULL &&  len > 0 && order >0 && emp_checkEmployee(lista, len)== 0 ){

		do{
			flagSwap=0;

			for(i=0; i<len-1 ; i++){

				contador++;

				switch (order) {
					case 1:
						if( stricmp(lista[i].lastName,lista[i+1].lastName) > 0 )
						{
							flagSwap=1;
							auxPay=lista[i];
							lista[i]=lista[i+1];
							lista[i+1]=auxPay;

							if(	lista[i].sector >= lista[i+1].sector)
							{
								flagSwap=1;
								auxPay.sector=lista[i].sector;
								lista[i].sector=lista[i+1].sector;
								lista[i+1].sector=auxPay.sector;
							}
						}
						break;
					case 2:
						if(	stricmp(lista[i].lastName,lista[i+1].lastName) < 0 )
						{
							flagSwap=1;
							auxPay=lista[i];
							lista[i]=lista[i+1];
							lista[i+1]=auxPay;
							if(	lista[i].sector <= lista[i+1].sector)
							{
								flagSwap=1;
								auxPay.sector=lista[i].sector;
								lista[i].sector=lista[i+1].sector;
								lista[i+1].sector=auxPay.sector;
							}
						}
						break;
				}


			}
			len--;
		}while(flagSwap);

		retorno=contador;
	}

	return retorno;
}

int printEmployee(Employee* list){

	int retorno=-1;

	if (list!=NULL && list->isEmpty == CARGADO )
	{
		retorno=0;
		printf("%4d  |    %-7s     |    %-9s     | %12.2f    |     %5d      |\n"
			   "______|________________|__________________|_________________|________________|\n" ,list->id ,list->name, list->lastName, list->salary, list->sector);
	}

	return retorno;
}


int printEmployees(Employee* list, int length){

	int retorno=-1;
	int i;
	if (list!=NULL && length>0 ) {
		retorno=0;

		printf("\n                                                                            \n"
			   "_____________________________________________________________________________ \n"
			   "      |                |                  |                 |                |\n"
			   " Id   |    Nombre      |    Apellido      |      Salario    |      Sector    |\n"
	           "______|________________|__________________|_________________|________________|\n");


		for (i = 0; i < length; ++i) {

			PrimerasLetrasMayuscula(list[i].name);
			PrimerasLetrasMayuscula(list[i].lastName);
			printEmployee(&list[i]);
		}
	}
	return retorno;
}

int emp_InformarEmpleados (Employee* list, int len){

	int retorno=-1;// Pointer NULL or len <0
	int opcionInformar;
	int order;
	int opcionSueldo;
	if (list!=NULL && len>=0 ) {
		retorno=-2; // Invalid opcion
		printEmployees(list, len);
		if(utn_getNumero(&opcionInformar,
				"\n0) Volver Menu anterior\n"
				"1) Listar Empleados por Apellido y Sector.\n"
				"2) Informar Sueldos.\n"
				""
				"\n\n==============================================================================\n\n"
				""
				"Opcion: ", "\nError, invalid opcion \n ", 0, 2, 0)==0 )
		{
			switch (opcionInformar)
			{
				case 1:
					if(utn_getNumero(&order, "\n1) Ordenar de la A a la Z\n"
							            	   "2) Ordenar de la Z a la A\n"
							            	   ""
							            	   "\n\n==============================================================================\n\n"
							            	   ""
							            	   "Opcion: ", "\nError, opcion invalida intentalo de nuevo\n", 1, 2, 0)==0)
					{
						sortEmployees(list, len, order);
						printEmployees(list, len);
						retorno=0; //OK
					}
					break;
				case 2:
					if(utn_getNumero(&opcionSueldo, "\n1) Total y Promedio de los salarios\n"
											 "2) Cuantos empleados superan el salario promedio  \n"
							                 ""
							                 "\n\n==============================================================================\n\n"
							                 ""
							                 "Opcion: ", "\nError, opcion invalida intentalo de nuevo\n", 1, 2, 0)==0)
					{

						emp_checkEmployeeSalary(list, len, opcionSueldo);
						retorno=0; //OK
					}

					break;
				case 0:
					retorno=1; // Back menu
					break;
			}
		}
	}

	return retorno;
}

float emp_salaryEmployees (Employee* list, int len){

	float salario=-1; // Pointer NULL or len < 0 or there is not space or no salary
	int i;
	if (list!=NULL && len>=0 && emp_checkEmployee(list, len) == 0) {

		for (i = 0; i < len; i++) {

			salario+=list[i].salary; // Return !=0 OK
		}
	}
	return salario;
}

float emp_promedyEmployees (Employee* list, int len, float salario){

	float promedio=-1;// Pointer NULL or len < 0 or there is not space or no salary
	int contador=0;
	int i;
	if (list!=NULL && len>=0  && emp_checkEmployee(list, len) == 0 ) {

		for (i = 0; i < len; ++i) {
			contador++;
		}

		promedio=salario/contador; // !=0 OK
	}
	return promedio;
}



int emp_checkEmployeeSalary (Employee* list,int len, int order){

	int retorno=-1;// Pointer NULL or len and order <0 or there is not space
	float salario;
	float promedio;
	int i, contador;
	if (list!=NULL && len>=0 && emp_checkEmployee(list, len) == 0 ) {

		salario=emp_salaryEmployees(list, len);
		promedio=emp_promedyEmployees(list, len, salario);

		switch (order) {
			case 1:
				if(salario!=0 && promedio!=0)
				{
					printf("\nSalario Total: %.2f\n", salario);
					printf("\nSalario Promedio: %.2f\n", promedio);
					retorno=0; //OK
				}
				break;
			case 2:
				for (i = 0; i < len; ++i) {
					if (list[i].salary>= promedio ) {
						contador++;
						if(contador == 1){
							printf("_________________________________________________________________________\n");
						}
						printEmployee(&list[i]);
					}
				}

				printf("\nSalario Promedio: %.2f\n"
						"\nHay %d empleados que superan el salario promedio\n", promedio, contador);
				break;
		}
	}

	return retorno;
}






