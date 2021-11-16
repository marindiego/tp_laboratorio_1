/*
 * biblioteca.h
 *
 *  Created on: 12 sep. 2021
 *      Author: Usuario
 */

#ifndef UTN_FUNCIONES_H_
#define UTN_FUNCIONES_H_
#include <stdio.h>


//Funciones con Strings
//int getString ( char *cadena, int tamMax);
//int getInt(int* pResultado);
//int getChar(char* pResultado, int tam);
//int esNumerica(char* cadena, int limite);
//int esTextoBasico(char* cadena);
//int validarFloat (char *stringRecibido, int largo);
//int getFloat(float* pResultado);
void getStringPractica (char cadena[], char mensaje[], int tam );

int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError,int minimo, int maximo, int reintentos);
int utn_getCharNombre(char* pResultado, char* mensaje,char* mensajeError, int reintentos, int tamMax);
int utn_getFloat(float* pResultado, char* mensaje,char* mensajeError, float minimo, float maximo, int reintentos);
int PrimerasLetrasMayuscula(char*mensaje);
int ConcatenarNombreYApellido(char*nombre, char*apellido, char*nombreCompleto, int tam);


// Funciones Matematicas

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
int ValidarRangoEntero (int numeroEnteroIngresado, int minimo, int maximo, char mensaje[], char mensajeError[]);
/// @param mensaje "ingrese si o si un numero entero"
/// @param mensajeError "en caso de no ser entero la cualquier numero y l oasigna a una varible
int IngresarNumeroEntero (char* mensaje, char *mensajeError, int minimo, int maximo);
float ValidacionTemperaturaFyC (float temperaturaF);
/// @param temperaturaC Recibe temperatura en Celsius
/// @return me devuelve la temperatura que no pase el rango minimo de congelacion y el maximo de ebullicion
int ValidacionTemperaturaCyF (float temperaturaC);
/// @param mensaje se le debe informar que no pase de de 0 y 100
void PedirTemperaturaC (char mensaje[]);
/// @param mensaje se le debe informar que no pase de de 0 y 210
void PedirTemperaturaF (char mensaje[]);
float IngresarNumeroFloat (char* mensaje, char *mensajeError, int minimo, int maximo);
void InicializarVectorEnteroExcluyente (int listadoEnteros [], int tam, int numeroExcluyente);
void CargarNumerosEnteros (int listaEnteros[], int tam, char mensaje[], char mensajeError[], int minimo, int maximo);
void CargarEnterosNoSecuencial (int listaEnteros[], int tam, char mensaje[], char mensajeError[],  int minimo, int maximo);
void MonstrarCantidadNegativosPositivos (int listaEnteros[], int tam);
int VereficarParidad (int numeroIngresado);
int VereficarSigno (int numeroIngresado);
void SumarParidad (int listaEnteros[], int tam, int *pAcumuladorPares, int *pAcumuladorImpares);
void CalcularMayorImpares (int listaEnteros [], int tam);
void MostrarNumerosEnteros (int listaEnteros[], int tam, int numeroExcluyenteArray);
void MostrarEnteroAleatorio (int listaEnteros[], int tam);
void MostrarNumerosEnterosPares (int listaEnteros[], int tam);
void MostrarPosicionEnterosImpares (int listadoEnteros[], int tam);
void ContarNumerosRepetidos (int listaValores[], int tam);
int OrdenarNumerosEnterosDecrecienteNegativos (int listaEnteros[], int tam);
int OrdenarNumerosEnterosCreciente (int listaEnteros[], int tam);
int OrdenarNumerosEnterosDecreciente (int listaEnteros[], int tam);
int PromedearVectorEnteroPositivos (int listaEnteros[], int tam, float *pPromedioPositivos);
void SumarEnterosNegativos (int listaEnteros[], int tam, float *pSumaNegativos);
int CalcularMaximoArray (int listaEnteros[], int tam, int *pMaximo);
void MenuEnteros (int listaEnteros[], int tam, char mensaje[], char mensajeError[], int minimo, int maximo, int numeroExcluyenteArray);
int BuscarUnNumero (int listaVectores[], int tam, int valorBusqueda );


#endif /* UTN_FUNCIONES_H_ */
