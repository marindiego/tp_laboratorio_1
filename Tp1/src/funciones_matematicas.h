/*
 * funciones_matematicas.h
 *
 *  Created on: 24 sep. 2021
 *      Author: Usuario
 */

#ifndef FUNCIONES_MATEMATICAS_H_
#define FUNCIONES_MATEMATICAS_H_

/// @param operando1 Recibe el primer operando
/// @param operando2 Recibe un segundo operando
/// @return me duevuelve el resultado
float Multiplicar (float operando1, float operando2);
/// @param operando1 Recibe el primer operando
/// @param operando2 Recibe un segundo operando
/// @return me devuleve la division
int Dividir (float operando1, float operando2, float* pResultado);
/// @param operador1 Recibe el primer operando
/// @param operador2 Recibe el segundo operando
/// @return me devuelve el resultado de la resta
float Restar (float operando1, float operando2);
/// @param a Recibe el primer operando
/// @param b Recibe el segundo operando
/// @return me devuelve el resultado de la suma a la funcion
float Sumar (float operando1, float operando2);
/// @param numeroIngresado recibe comom argumento el numero ingresado ya validado
/// @return me devuelve el factorail del numero ingresado
int CalcularFactorial (int numeroIngresado);
/// @param numeroIngresado recibe un flotante y se resta el mismo con un int
 /// @return si el resultado es 1 es flotante si es 0 es entero
int ValidarEntero (float numeroIngresado);





#endif /* FUNCIONES_MATEMATICAS_H_ */
