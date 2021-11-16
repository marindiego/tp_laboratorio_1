


#include "utn_funciones.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>



void getStringPractica (char cadena[], char mensaje[], int tam ) { // Funcion de Practica, Se rompe facil

	printf("%s", mensaje);
	fflush(stdin);
	gets(cadena);

	while(strlen(cadena)> tam){

		printf("Reingrese: ");
		fflush(stdin);
		fflush(stdin);
		gets(cadena);
	}
}
static int esNumerica(char* cadena, int limite){

	int retorno= 1; //VERDADERO
	int i;

	if(cadena[0]=='\0'){

		retorno=0;
	}

	for(i=0 ; i<limite && cadena[i]!='\0' ;i++){

		if(i==0 && (cadena[i]=='-' || cadena[i]=='+')){

			i=1;
			continue;
		}

		if(cadena[i]<'0'|| cadena[i]>'9'){

			retorno=0;
			break;
		}
	}
	return retorno;
}


 static int getString ( char *cadena, int tamMax){

	int retorno=-1;
	char buffer[4096];

	if(cadena!=NULL && tamMax>0){

		fflush(stdin);
		if(fgets(buffer, sizeof(buffer), stdin) != NULL ){

			if(buffer[strnlen(buffer,sizeof(buffer))-1]=='\n'){

				buffer[strnlen(buffer,sizeof(buffer))-1]='\0';
			}

			if(strnlen(buffer, sizeof(buffer)) <= tamMax){

				strncpy(cadena,buffer,tamMax);
				retorno=0;
			}
		}
	}

	return retorno;
}

 static int getInt(int* pResultado){

	int retorno=-1;
	char buffer[50];

	if(pResultado != NULL &&
		getString(buffer,sizeof(buffer))==0 &&
		esNumerica(buffer, sizeof(buffer)))
	{
		retorno=0;
		*pResultado=atoi(buffer);

	}

	return retorno;
}
 static int validarFloat (char *stringRecibido, int largo){

 	int retorno=1;
 	int i=0;
 	int contadorPuntos=0;

 	if(stringRecibido[0]=='\0'){

 		retorno=0;
 	}


 	for(;  stringRecibido[i]!='\0'; i++){


 		if(stringRecibido[i]<'0' || stringRecibido[i]>'9' ){

 			if(stringRecibido[i]=='.'){

 				contadorPuntos++;
 				if(contadorPuntos>1){

 					retorno=0;
 					break;
 				}
 			}
 			else
 			{
 				if(i==0){


 				}
 				else{

 					retorno=0;
 					break;
 				}
 			}
 		}
 	}


 	return retorno;
 }

  static int getFloat(float* pResultado){

	int retorno=-1;
	char buffer[50];

	if(pResultado != NULL &&
		getString(buffer,sizeof(buffer))==0 &&
		validarFloat(buffer, sizeof(buffer))==1)
	{
		retorno=0;
		*pResultado=atof(buffer);

	}

	return retorno;
}



 static  int esTextoBasico(char* cadena){

 	int retorno= 1;
 	int i=0;

 	if(cadena[0]=='\0' || isspace(cadena[0])){

 		retorno=0;
 	}

 	for( ;cadena[i]!='\0';i++){

 		//if(cadena[i]<'A'||(cadena[i]>'Z'&&cadena[i]<'a')||(cadena[i]>'z'&&cadena[i]<'�')||cadena[i]>'�'){

 		if(		cadena[i]<32 ||
				(cadena[i]>32&&cadena[i]<65) ||
				(cadena[i]>90&&cadena[i]<97) ||
 				(cadena[i]>122&&cadena[i]<164) ||
				cadena[i]>165)
 		{

 			retorno=0;
 			break;
 		}
 	}
 	return retorno;
 }

static int getChar(char* pResultado, int tam){

	int retorno=0;
	char buffer[4096];

	if(pResultado!=NULL &&
	getString(buffer, sizeof(buffer))==0 &&
	esTextoBasico(buffer)==1 &&
	strnlen(buffer, sizeof(buffer)) <= tam)

	{
		retorno=1;
		strncpy(pResultado, buffer, tam);
	}


	return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError,int minimo, int maximo, int reintentos){

	int retorno =-1;
	int buffer;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0){

		do{
			printf("%s",mensaje);

			if(getInt(&buffer)==0 &&
					buffer>=minimo &&
					buffer<=maximo)
			{

				*pResultado=buffer;
				retorno=0;
				break;
			}

			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos>=0);
	}
	return retorno;
}

int utn_getFloat(float* pResultado, char* mensaje,char* mensajeError, float minimo, float maximo, int reintentos){

	int retorno =-1;
	float buffer;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0){

		do{
			printf("%s",mensaje);

			if(getFloat(&buffer)==0 &&
					buffer>=minimo &&
					buffer<=maximo){

				*pResultado=buffer;
				retorno=0;
				break;
			}

			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos>=0);
	}
	return retorno;
}
int utn_getCharNombre(char* pResultado, char* mensaje,char* mensajeError, int reintentos, int tamMax){

	int retorno =-1;
	char buffer[4093];

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && reintentos>=0  && tamMax>1){

		do{
			printf("%s",mensaje);

			if(getChar(buffer, tamMax)==1){

				strncpy(pResultado,buffer,tamMax);
				retorno=0;
				break;
			}

			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos>=0);
	}

	return retorno;
}
int PrimerasLetrasMayuscula(char*mensaje){

	int i;
	strlwr(mensaje);
	mensaje[0]=toupper(mensaje[0]);

	for(i=1;mensaje[i]!='\0';i++){

		if(isspace(mensaje[i])){
			mensaje[i+1]=toupper(mensaje[i+1]);
		}
	}
	return 1;
}
int ConcatenarNombreYApellido(char*nombre,char*apellido,char*nombreCompleto,int tam){
	int retorno=0;
	snprintf(nombreCompleto,tam,"%s, %s",apellido,nombre);
	retorno=PrimerasLetrasMayuscula(nombreCompleto);
	return retorno;
}


//---------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------FUNCIONES MATEMATICAS -------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------

float Sumar (float a, float b){

	float resultado;

	resultado=a+b;

	return resultado;
}

float Restar (float operando1, float operando2){

	float resultado;

	resultado=operando1-operando2;

	return resultado;

}
int Dividir (float operando1, float operando2, float* pResultado){


	float resultado;
	int error=1;

	if(pResultado!=NULL && operando2!=0){

	resultado=operando1/operando2;

	(*pResultado)=resultado;
	}else{

		error=0;
	}
	return error;
}
float Multiplicar (float operando1, float operando2){

	float resultado;

	resultado=operando1*operando2;

	return resultado;

}

int CalcularFactorial (int numeroIngresado){

	int factorial;

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
int IngresarNumeroEntero (char* mensaje, char *mensajeError, int minimo, int maximo){



	float numeroIngresado;
	float resultado;
	int retorno=0;

	if(mensaje!=NULL && mensajeError!=NULL ){

		printf("%s", mensaje );
		scanf("%f", &numeroIngresado);

		resultado=numeroIngresado-(int)numeroIngresado;

		while(retorno==0){

			if(resultado!=0 ){

				printf("%s", mensajeError);
				scanf("%f", &numeroIngresado);
				resultado=numeroIngresado-(int)numeroIngresado;
				system("cls");

			}else{

				retorno=1;
			}
		}
		numeroIngresado=ValidarRangoEntero(numeroIngresado, minimo, maximo, mensaje, mensajeError);
	}

	return numeroIngresado;

}
float IngresarNumeroFloat (char* mensaje, char *mensajeError, int minimo, int maximo){

	float numeroIngresado;
	float resultado;
	int retorno=0;

	if(mensaje!=NULL && mensajeError!=NULL){

		printf("%s", mensaje );
		scanf("%f", &numeroIngresado);

		resultado=numeroIngresado-(int)numeroIngresado;

		while(retorno==0){

			if(resultado==0){

				printf("%s", mensajeError);
				scanf("%f", &numeroIngresado);
				resultado=numeroIngresado-(int)numeroIngresado;
				system("cls");
			}else{

				retorno=1;
			}
		}
		numeroIngresado=ValidarRangoEntero(numeroIngresado,  minimo,  maximo, mensaje,  mensajeError);
	}

	return numeroIngresado;
}

void InicializarVectorEnteroExcluyente (int listadoEnteros [], int tam, int  numeroExcluyente){

	int i;

	if(listadoEnteros!=NULL){

		for(i=0; i<tam; i++){

			listadoEnteros[i]=numeroExcluyente;
		}
	}
}

int BuscarUnNumero (int listaVectores[], int tam, int valorBusqueda ){

	int i,indiceEncontrado;

	for(i=0; i<tam; i++){

		if(listaVectores[i]==valorBusqueda){

			indiceEncontrado=i;
			break;
		}

	}

	return indiceEncontrado;
}

int ValidarRangoEntero (int numeroEnteroIngresado, int minimo, int maximo, char mensaje[], char mensajeError[]){

	while(numeroEnteroIngresado<minimo || numeroEnteroIngresado> maximo){

		printf("%s", mensajeError);
		scanf("%d", &numeroEnteroIngresado);
	}

	return numeroEnteroIngresado;
}

void CargarNumerosEnteros (int listaEnteros[], int tam, char mensaje[], char mensajeError[], int minimo, int maximo){

	int i;

	if(listaEnteros!=NULL){

		for(i=0; i<tam; i++){

			listaEnteros[i]=IngresarNumeroEntero(mensaje, mensajeError, minimo, maximo);
		}
	}
}

int VereficarSigno (int numeroIngresado){

	int signo;//1 positivo 0 negativo


	if(numeroIngresado>0){

		signo=1;

	}else{

		signo=0;
	}

	return signo;
}

void MonstrarCantidadNegativosPositivos (int listaEnteros[], int tam){


	int contadorPositivos=0, contadorNegativos=0, i, numeroIngresado;

	for(i=0; i<tam; i++){

		numeroIngresado=listaEnteros[i];
		//1 Positivo 0 Negativo
		if(VereficarSigno(numeroIngresado==1)){

			contadorPositivos++;
		}
		else{

			contadorNegativos++;
		}
	}


	printf("Hay %d positivos: \n",contadorPositivos);
	printf("Hay %d negativos: \n",contadorNegativos);

}
int VereficarParidad (int numeroIngresado){

	int paridad;// 1 Par  0 Impar

	if( numeroIngresado%2==0){

		paridad=1;
	}
	else{
		paridad=0;
	}

	return paridad;
}

void SumarParidad (int listaEnteros[], int tam, int *pAcumuladorPares, int *pAcumuladorImpares){

	int numeroIngresado, i;

	if(pAcumuladorPares!=NULL && pAcumuladorImpares!=NULL){

		for(i=0; i<tam; i++){

			numeroIngresado=listaEnteros[i];

			if(VereficarParidad(numeroIngresado)==1){

				*pAcumuladorPares+=numeroIngresado;
			}
			else{

				*pAcumuladorImpares+=numeroIngresado;
			}
		}
	}

	if(*pAcumuladorPares!=0){

		printf("La suma de los pares es: %d\n", *pAcumuladorPares );
	}
	else{

		printf("No hay pares Ingresado \n");
	}
	if(*pAcumuladorImpares!=0){

		printf("La suma de los impares es: %d\n", *pAcumuladorImpares );
	}
	else{
		printf("No hay impares Ingresado \n");
	}


}

void CalcularMayorImpares (int listaEnteros [], int tam){

	int i;
	int mayor=0;
	int numeroIngresado;
	int FlagMayorImpar=0;

	for(i=0; i<tam; i++){

		numeroIngresado=listaEnteros[i];

		if(VereficarParidad(numeroIngresado)==0){// 0 Impar 1 par

			if(FlagMayorImpar==0 || numeroIngresado>mayor){ //Despues de la primer iteracion Comparo

				FlagMayorImpar=1;
				mayor=listaEnteros[i];
			}
		}
	}
	if(mayor!=0){

		printf("El mayor de los impares es: %d \n", mayor);
	}
	else{

		printf("No se encontro ningun Impar \n");
	}
}


void MostrarNumerosEnterosPares (int listaEnteros[], int tam){

	int i, numeroIngresado;

	for(i=0; i<tam; i++){

		numeroIngresado=listaEnteros[i];
		if(VereficarParidad(numeroIngresado)==1 ){

			printf("Hay un numero par en la posicion %d y es: %d\n", i+1, numeroIngresado);
		}
	}
}
void MostrarPosicionEnterosImpares (int listadoEnteros[], int tam){

	int i, numeroIngresado;

	if(listadoEnteros!=NULL){

		for(i=0; i<tam; i++){

			numeroIngresado=listadoEnteros[i];

			if(VereficarParidad(numeroIngresado)==0){

				printf("Hay un numero impar en la posicion %d\n", i+1);
			}
		}
	}
}
void ContarNumerosRepetidos (int listaValores[], int tam){

	int i,j, contadorRepetidos=0;

	if(listaValores!=NULL){

		for(i=0;i<tam-1; i++){

			for(j=i+1; j<tam; j++){

				if(listaValores[i]==listaValores[j]){

					contadorRepetidos++;
				}
			}
		}
		printf("Se repiten %d numeros \n", contadorRepetidos);
	}
}
int OrdenarNumerosEnterosCreciente (int listaEnteros[], int tam){

		int flagSwap;
		int i;
		int contador=0;
		int retorno=0;
		int buffer;

		if(listaEnteros!=NULL && tam>=0){

			do{
				flagSwap=0;
				for(i=0;i<tam-1; i++){

					contador++;
					if(listaEnteros[i]>listaEnteros[i+1]){

						flagSwap=1;
						buffer=listaEnteros[i];
						listaEnteros[i]=listaEnteros[i+1];
						listaEnteros[i+1]=buffer;
					}

				}

			}while(flagSwap);

			retorno=contador;
		}
		return retorno;
}
int OrdenarNumerosEnterosDecreciente (int listaEnteros[], int tam){

		int flagSwap;
		int i;
		int contador=0;
		int retorno=0;
		int buffer;

		if(listaEnteros!=NULL && tam>=0){

			do{
				flagSwap=0;
				for(i=0;i<tam-1; i++){

					contador++;
					if(listaEnteros[i]<listaEnteros[i+1]){

						flagSwap=1;
						buffer=listaEnteros[i];
						listaEnteros[i]=listaEnteros[i+1];
						listaEnteros[i+1]=buffer;
					}
				}
			}while(flagSwap);
			retorno=contador;
		}
		return retorno;
}

void MostrarNumerosEnteros (int listaEnteros[], int tam, int numeroExcluyenteArray){

	int i;
	if(listaEnteros!=NULL ){

		for(i=0; i<tam; i++){

			if(listaEnteros[i]!=numeroExcluyenteArray){

				printf("[DEBUG] Indice: %d - Valor %d\n", i+1, listaEnteros[i]);
			}
		}
		MostrarEnteroAleatorio(listaEnteros, tam);
	}
}

void MostrarEnteroAleatorio (int listaEnteros[], int tam){

	srand(time(NULL));

	int indiceAleatorio, numeroArrayAleatorio;

	indiceAleatorio=rand()% tam;
	numeroArrayAleatorio=listaEnteros[indiceAleatorio];

	printf("\n[DEBUG] IndiceAleatorio: %d - Valor %d\n", indiceAleatorio+1, numeroArrayAleatorio);
}

int OrdenarNumerosEnterosDecrecienteNegativos (int listaEnteros[], int tam){

		int flagSwap;
		int i;
		int contador=0;
		int retorno=0;
		int buffer;
		int nuevoLimite;

		if(listaEnteros!=NULL && tam>=0){

			nuevoLimite=tam-1;
			do{
				flagSwap=0;
				for(i=0;i<nuevoLimite; i++){

					contador++;
					if( listaEnteros[i]<0 && listaEnteros[i]<listaEnteros[i+1]){

						flagSwap=1;
						buffer=listaEnteros[i];
						listaEnteros[i]=listaEnteros[i+1];
						listaEnteros[i+1]=buffer;
					}
					nuevoLimite--;
				}
			}while(flagSwap);
			retorno=contador;
		}

		return retorno;
}

void CargarEnterosNoSecuencial (int listaEnteros[], int tam, char mensaje[], char mensajeError[],  int minimo, int maximo){

	int numeroIngresado,i;
	char seguir;

	if(listaEnteros!=NULL){

		InicializarVectorEnteroExcluyente(listaEnteros, tam, 0);

		do{

			numeroIngresado=IngresarNumeroEntero(mensaje, mensajeError, minimo, maximo);
			i=IngresarNumeroEntero(" En que posicion quieres guadarlo ?: ", "Reingrese un posicion valida", 0, tam);

			listaEnteros[i-1]=numeroIngresado;

			printf("Desea Ingresar otro numero  s/n ?:  ");
			fflush(stdin);
			scanf("%c", &seguir);

		}while(seguir=='s');
	}
}

int PromedearVectorEnteroPositivos (int listaEnteros[], int tam, float *pPromedioPositivos){

	float acumuladorPositivos=0;
	int retorno=0; // 1 se pudo calcular el promedio 0 no se pudo

	if(listaEnteros!=NULL && pPromedioPositivos!=NULL){

		for(int i=0; i<tam; i++){

			acumuladorPositivos+=listaEnteros[i];
		}

		if(acumuladorPositivos!=0){

			retorno=1;
			*pPromedioPositivos=acumuladorPositivos/tam;
		}
	}

	return retorno;
}

void SumarEnterosNegativos (int listaEnteros[], int tam, float *pSumaNegativos){

	int i, numeroIngresado;

	InicializarVectorEnteroExcluyente(listaEnteros, tam, 0);

	for(i=0; i<tam; i++){

		numeroIngresado=listaEnteros[i];

		if(VereficarParidad(numeroIngresado)==0){

			*pSumaNegativos+=listaEnteros[i];
		}
	}

	printf("\n(--- Suma Negativos---)[%.2f] \n", *pSumaNegativos);
}

int CalcularMaximoArray (int listaEnteros[], int tam, int *pMaximo){
	//retun 1 SeEncontro 0 No se encontro

	int i;
	int max;
	int numeroIngresado;
	int flagTodoBien=0;

	if(listaEnteros!=NULL && pMaximo!=NULL){

		for(i=0; i<tam; i++){

			numeroIngresado=listaEnteros[i];

			if(VereficarSigno(numeroIngresado)==1){

				if(flagTodoBien==0 || numeroIngresado>max ){

					max=numeroIngresado;
					flagTodoBien=1;
				}
			}
		}

		*pMaximo=max;
	}

	return flagTodoBien;
}


void MenuEnteros (int listaEnteros[], int tam, char mensaje[], char mensajeError[], int minimo, int maximo, int numeroExcluyenteArray){

	// 1 CargaSecuencial 0 Carga No secuencial

	int opcion;
	int tipoArray;
	int OrdenarVector;
	int maximoArray;
	float promedioPositivos;

		do{
			printf("Menu de Arrays: \n 1-Inicializar Array \n 2-Cargar Array \n 3-Mostrar Array\n 4-Calcular Promedio Array \n 5-Ordenar Array \n 6-Salir del Menu \n");

			printf("\n Ingrese una opcion 1-2-3-4-5-6: ");
			scanf("%d", &opcion);

			switch(opcion){

			case 1:
				printf("Ud. ha seleccionado lo opci�n 1-Inicializar \n");
				InicializarVectorEnteroExcluyente(listaEnteros, tam, 0);
				printf("Inicializacion Completa!!!");
				system("pause");
				system("cls");
				break;

			case 2:
				printf("�Ud. ha seleccionado lo opci�n 2-Cargar \n");
				tipoArray=IngresarNumeroEntero("\n 1 = Carga Secuencial 2 = Carga Aleatoria: ", "\n\a [ERROR]1 = Carga Secuencial 2 = Carga Aleatoria: ", 0, 3);
				if(tipoArray==1){

					CargarNumerosEnteros(listaEnteros, tam, mensaje, mensajeError, minimo, maximo);
					printf("Carga completa!!!");
					system("pause");
					system("cls");
				}
				else{

					CargarEnterosNoSecuencial(listaEnteros, tam, mensaje, mensajeError, minimo, maximo);
					printf("Carga completa!!!");
					system("pause");
					system("cls");
				}
				break;

			case 3:

				int mostrarTipo;

				printf("�Ud. ha seleccionado lo opci�n 3-Mostrar \n");

				mostrarTipo=IngresarNumeroEntero("\n 1 = Mostar Array, 2 = Mostrar Maximo Del Array:  ", "Reingrese las opciones sugeridas: ", 0, 3);

				if(mostrarTipo==1){

					MostrarNumerosEnteros(listaEnteros, tam, numeroExcluyenteArray);
				}
				else
				{

					if(CalcularMaximoArray(listaEnteros, tam, &maximoArray)==1){

						printf("\n (---||  Maximo Array  ||---) %d \n", maximoArray);
					}
					else
					{
						printf("No se encontro ningun numero positivo mayor :(");
					}
				}

				printf("Mostrar Completado!!!");
				system("pause");
				system("cls");
				break;

			case 4:
				printf("�Ud. ha seleccionado lo opci�n 4-Calcular Promedio \n");

				if(PromedearVectorEnteroPositivos(listaEnteros, tam, &promedioPositivos)==1){

					printf("\n(---||  Promedio Positivos  ||---)[%.2f] \n", promedioPositivos);
				}
				else{

					printf("\nNo se puedo calcular el promedio de los positivos \n\a");
				}

				printf("PromedioArray Completado!!!");
				system("pause");
				system("cls");
				break;

			case 5:

				int contadorVueltas;

				printf("�Ud. ha seleccionado lo opci�n 5-Ordenar \n");

				OrdenarVector=IngresarNumeroEntero("\n 1 = Creciente  2 = Decreciente: ", "\n\a[ERROR] 1 = Creciente  2 = Decreciente: ", 0, 3);

				if(OrdenarVector==1){

					contadorVueltas=OrdenarNumerosEnterosCreciente(listaEnteros, tam);
					MostrarNumerosEnteros(listaEnteros, tam, 0);

					if(contadorVueltas>0){

						printf("\n\n Iteraciones:  %d \n\n", contadorVueltas);
					}

				}
				else{

					contadorVueltas=OrdenarNumerosEnterosDecreciente(listaEnteros, tam);
					MostrarNumerosEnteros(listaEnteros, tam, 0);

					if(contadorVueltas>0){

						printf("\n\n Iteraciones:  %d \n\n", contadorVueltas);
					}
				}

				printf("Ordenar Completado!!!");
				system("pause");
				system("cls");
				break;

			case 6:
				printf("(---| ** Gracias por Operar ** |---)");
				system("pause");
				system("cls");
				break;

			default:
				printf("\nError, Ingrese una opcion entre 1-2-3-4-5-6:\n\a ");
				system("pause");
				system("cls");
			}

		}while(opcion!=6);

}
float ValidacionTemperaturaFyC (float temperaturaF){


	while(temperaturaF<=0 || temperaturaF>=211 ){

		printf("Error, reingrese una temperatura en fahrenheit entre 32�F y 211.3�F: ");
		scanf("%f", &temperaturaF);
	}

	return temperaturaF;

}
int ValidacionTemperaturaCyF (float temperaturaC){


	while(temperaturaC<=0 || temperaturaC>=100 ){

		printf("Error, reingrese una temperatura en celsius entre 1�C y 99�C: ");
		scanf("%f", &temperaturaC);
	}

	return temperaturaC;

}
void PedirTemperaturaF (char mensaje[]){

	float temperaturaF;
	float gradosFaC;
	float temperaturaFvalida;

	printf("%s", mensaje);
	scanf("%f", &temperaturaF);

	temperaturaFvalida=ValidacionTemperaturaFyC (temperaturaF);

	gradosFaC=(temperaturaF-32.00)*0.556;

	printf("%.2f �F son %.2f �C centigrados.\n", temperaturaFvalida,gradosFaC);


}

void PedirTemperaturaC (char mensaje[]){

	int temperaturaC;
    int gradosCaF;
	int temperaturaCvalida;

	printf("%s", mensaje);
	scanf("%d", &temperaturaC);

	temperaturaCvalida=ValidacionTemperaturaCyF (temperaturaC);

	gradosCaF=(temperaturaC*9/5)+32;

	printf("%d �C son %d �F centigrados.\n", temperaturaCvalida,gradosCaF);

}




