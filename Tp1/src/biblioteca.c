#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

float PedirNumeroFloat(char mensaje[]){

	float numero;

	printf("%s",mensaje);
	scanf("%f", &numero);

	return numero;

}
float ValidacionTemperaturaFyC (float temperaturaF){


	while(temperaturaF<=0 || temperaturaF>=211 ){

		printf("Error, reingrese una temperatura en fahrenheit entre 32ºF y 211.3ºF: ");
		scanf("%f", &temperaturaF);
	}

	return temperaturaF;

}
int ValidacionTemperaturaCyF (float temperaturaC){


	while(temperaturaC<=0 || temperaturaC>=100 ){

		printf("Error, reingrese una temperatura en celsius entre 1ºC y 99ºC: ");
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

	printf("%.2f °F son %.2f °C centigrados.\n", temperaturaFvalida,gradosFaC);


}

void PedirTemperaturaC (char mensaje[]){

	int temperaturaC;
    int gradosCaF;
	int temperaturaCvalida;

	printf("%s", mensaje);
	scanf("%d", &temperaturaC);

	temperaturaCvalida=ValidacionTemperaturaCyF (temperaturaC);

	gradosCaF=(temperaturaC*9/5)+32;

	printf("%d °C son %d °F centigrados.\n", temperaturaCvalida,gradosCaF);

}


