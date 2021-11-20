/*
 * funciones_matematicas.c
 *
 *  Created on: 24 sep. 2021
 *      Author: Usuario
 */
#include <stdio.h>
#include "funciones_matematicas.h"
#include <windows.h>


float Sumar (float a, float b){

	float resultado;

	resultado=(a)+(b);

	return resultado;
}

float Restar (float operando1, float operando2){

	float resultado;

	resultado=(operando1)-(operando2);

	return resultado;

}
int Dividir (float operando1, float operando2, float* pResultado){


	float resultado;
	int error;

	if(pResultado!=NULL && operando2!=0){

	resultado=(operando1)/(operando2);
	*pResultado=resultado;
	error=1;

	}else{

		error=0;
	}
	return error;
}
float Multiplicar (float operando1, float operando2){

	float resultado;

	resultado=(operando1) * (operando2);

	return resultado;

}

int CalcularFactorial (int numeroIngresado){

	long int factorial;

	if(numeroIngresado==1){

		return 1;
	}
	else{
		factorial=numeroIngresado* CalcularFactorial (numeroIngresado-1);
	}

	return factorial;

}
int ValidarEntero (float numeroIngresado){

	float resultado;
	int enteroOflotante=1;

	resultado=numeroIngresado-(int)numeroIngresado;

	if(resultado!=0){

		enteroOflotante=0;
	}

	return enteroOflotante;
}
