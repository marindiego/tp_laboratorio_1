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

	system("color 70");

	int opcion;
	float resultado1,resultado2,resultado3,resultado4;
	long int resultado5,resultado6;

	float operando1=0;
	float operando2=0;

	int seguir4=-1;

	int errorDividir;

	int flagOperando1=-1;
	int flagOperando2=-1;

	 // 1 es true 0 es false

	printf("_____________________________\n"
			"\n"
			"Diego Marin\n"
			"1(c)\n"
			"Simulador de Calculadora\n"
			"_____________________________\n\n");

    do
	{

    	if (flagOperando1==-1) {

    		printf(" 1)--- Ingresar 1er operando\n");
    	}

    	if (flagOperando1==0) {

    		printf(" 1)--- Ingresar 1er operando ( %.2f ) ---\n",operando1);
    	}

    	if(flagOperando2==-1){

    		printf(" 2)--- Ingresar 2do operando\n");
    	}

    	if (flagOperando2==0){

    		printf(" 2)--- Ingresar 2er operando ( %.2f ) ---\n",operando2);
    	}

    	printf(" 3)--- Calcular todas las operaciones---\n");
    	printf(" 4)--- Informar resultados----\n");
    	printf(" 5)--- Salir---\n"
    			"Opcion....... ");
		scanf("%d", &opcion);

		switch(opcion)
		{
		case 1:
			operando1=PedirNumeroFloat("\nIngrese el 1er operando......... ");

			flagOperando1=0;
			break;

		case 2:

			operando2=PedirNumeroFloat("\nIngrese 2do operando.......... ");

			flagOperando2=0;
			break;

		case 3:
			if (flagOperando1==0 && flagOperando2==0) {

				resultado1=Sumar(operando1, operando2);
				resultado2=Restar(operando1, operando2);
				errorDividir=Dividir(operando1, operando2, &resultado3 );
				resultado4=Multiplicar(operando1, operando2);

				printf("a) Calcular la suma ( (%.2f) + (%.2f) )\n ",operando1, operando2);
				printf("b) Calcular la resta ( (%.2f) - (%.2f) )\n ",operando1, operando2);
				printf("c) Calcular la division ( (%.2f) / (%.2f) )\n ",operando1, operando2);
				printf("d) Calcular la multiplicacion ( (%.2f) * (%.2f) )\n ",operando1, operando2);
				printf("e) Calcular el factorial de ( (%.2f!) y (%.2f!) )\n",operando1, operando2);

				system("pause");
				seguir4=0;
			}
			else{
				printf("Error Primero Ingrese los 2 operandos xfa\n\n");
			}

			break;
		case 4:

			if (seguir4==0) {

				//informo resultados de las operaciones
				printf("El resultado de %.2f + %.2f  es: %.2f\n", operando1, operando2, resultado1);
				printf("El resultado de %.2f - %.2f es: %.2f\n", operando1, operando2, resultado2);

				if(errorDividir==0){

					printf("\n\tDivision: no se puede dividir entre cero\n\n");
				}else{

					printf("El resultado de %.2f / %.2f es: %.3f\n", operando1, operando2, resultado3);
				}

				printf("El resultado de %.2f * %.2f es: %.2f \n ", operando1, operando2, resultado4);
				if(operando1<0 || ValidarEntero(operando1)==0 ){

					printf("No se puede calcular un numero factorial con decimales, igual a 0 o negativo\n");

				}else
				{
					if (operando1==0) {
						printf("El factorial de 0.00 es: 1\n");
					}
					else{

						resultado5=CalcularFactorial(operando1);
						printf("El factorial de %.2f es: %ld \n",operando1,resultado5);
					}
				}
				if( operando2<0 || ValidarEntero(operando2)==0 ){

					printf("No se puede calcular un numero factorial con decimales, igual a 0 o negativo\n");
				}
				else
				{
					if (operando2==0) {

						printf("El factorial de 0.00 es: 1\n");
					}
					else{

						resultado6=CalcularFactorial(operando2);
						printf("El factorial de %.2f es: %ld \n",operando2,resultado6);
					}
				}
				system("pause");

			}
			else{
				printf("Error, para informar primero calcula las operaciones xfa\n\n");
			}

			break;
		case 5:
			printf("Gracias por operar !\n");
			system("pause");
			break;
		default:
			printf("Error, Reingrese una opcion entre el 1 y el 4 o 5 para salir\n \a");
			system("pause");
		}
	}while(opcion!=5);


	return EXIT_SUCCESS;
}
