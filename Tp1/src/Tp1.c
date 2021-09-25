/*
 ============================================================================
 Name        : Menu.c
 Author      : DIego
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include "funciones_matematicas.h"
#include <windows.h>

int main(void) {

	setbuf(stdout, NULL);

	int opcion;
	float resultado1,resultado2,resultado3,resultado4;
	int resultado5,resultado6;

	float operando1;
	float operando2;

	int errorDividir;


	 // 1 es true 0 es false

    do
	{

		//Muestro las opciones que tiene el usuario

    	printf("\n Elija una opcion 1/2/3/4/5:\n");
    	printf(" 1)--- Ingresar 1er operando= %.2f\n", operando1);
    	printf(" 2)--- Ingresar 2do operando= %.2f\n", operando2);
    	printf(" 3)--- Calcular todas las operaciones---\n");
    	printf(" 4)--- Informar resultados----\n");
    	printf(" 5)--- Salir---\n");


		scanf("%d", &opcion);

		switch(opcion)
		{
		case 1:
			operando1=PedirNumeroFloat(" Ingrese el 1er operando: ");
			system("cls");
			break;
		case 2:
			operando2=PedirNumeroFloat(" Ingrese 2do operando: ");
			system("cls");
			break;
		case 3:
			/// calculo todas las operaciones y las muestro
			resultado1=Sumar(operando1, operando2);
			resultado2=Restar(operando1, operando2);
			errorDividir=Dividir(operando1, operando2, &resultado3 );
			resultado4=Multiplicar(operando1, operando2);
			resultado5=CalcularFactorial(operando1);
			resultado6=CalcularFactorial(operando2);

			printf("a) Calcular la suma (%.2f+%.2f)\n ",operando1, operando2);
			printf("b) Calcular la resta (%.2f-%.2f)\n ",operando1, operando2);
			printf("c) Calcular la division (%.2f/%.2f)\n ",operando1, operando2);
			printf("d) Calcular la multiplicacion (%.2f*%.2f)\n ",operando1, operando2);
			printf("e) Calcular el factorial de (%.2f!) y (%.2f!)\n",operando1, operando2);

			system("pause");
			system("cls");
			break;
		case 4:
			//informo resultados de las operaciones
			printf("El resultado de %.2f + %.2f  es: %.2f\n", operando1, operando2, resultado1);
			printf("El resultado de %.2f - %.2f es: %.2f\n", operando1, operando2, resultado2);
			if(errorDividir==0){
				printf("No se puede dividir entre cero \n");
			}else{
				printf("El resultado de %.2f / %.2f es: %.2f\n", operando1, operando2, resultado3);
			}
			printf("El resultado de %.2f * %.2f es: %.2f \n ", operando1, operando2, resultado4);
			if(operando1<0 || ValidarEntero(operando1)==0 || operando1>=12 ){

				printf("Error, no se puede calcular un numero factorial con decimales, menor a 0, mayor a 12 o negativo  \n");

			}else{

				printf("El factorial de %.2f es: %d \n",operando1,resultado5);

			}
			if( operando2<0 || ValidarEntero(operando2)==0 || operando2>=12){

				printf("Error, no se puede calcular un numero factorial con decimales, menor a 0, mayor a 12 o negativo \n");
			}
			else{
				printf("El factorial de %.2f es: %d \n",operando2,resultado6);
			}
			system("pause");
			system("cls");
			break;
		case 5:
			printf("Gracias por operar !\n");
			system("pause");
			system("cls");
			break;
		default:
			printf("Error, Reingrese una opcion entre el 1 y el 4 o 5 para salir\n \a");
			system("pause");
			system("cls");
		}
	}while(opcion!=5);


	return EXIT_SUCCESS;
}
