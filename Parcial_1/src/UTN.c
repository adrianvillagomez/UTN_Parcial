/*
 * UTN.c
 *
 *  Created on: 28 sep. 2021
 *      Author: adrian
 */
#include "UTN.h"
#include <stdlib.h>
int esNumerica(char cadenaNumeros[])
{
	int estado=-1;
	int i=0;
	if(cadenaNumeros!=NULL)
	{
		estado=0;
		while(cadenaNumeros[i]!='\0')
		{
			if(cadenaNumeros[i]<'0'||cadenaNumeros[i]>'9')
			{
				estado=-1;
				break;
			}
			i++;
		}
	}
	return estado;
}

int myGets(char pResultado[], int len)
{
    int retorno=-1;
    int indexFinal;
    fflush(stdin);
    if(fgets(pResultado,len,stdin)!=NULL)
    {
        // borro el \n del final
        indexFinal = strlen(pResultado)-1;
        if(pResultado[indexFinal] == '\n')
        {
            pResultado[indexFinal] = '\0';
        }
        retorno = 0;
    }
    return retorno;
}
int utn_getText(char pResultado[], int len, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	int i;

	for(i=0; i<=reintentos; i++)
	{
		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
		{
			printf("%s",mensaje);
			fflush(stdin);
			if(myGets(pResultado, len)==0)
			{
				retorno = 0;
				break;
			}
			else
				printf("%s",mensajeError);
		}
	}
	return retorno;
}
int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
	int retorno = -1;
	int bufferInt;
	int i;
	char bufferCadenaAux[16];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{

		for(i=0; i<=reintentos; i++)
		{
			printf("%s", mensaje);

			fflush(stdin);

			//if(scanf("%d", &bufferInt)==1)
			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				// el usuario ingreso algo
				// lo valido, para ver si los simbolos ingresados son numericos
				if(esNumerica(bufferCadenaAux)==0)
				{
					// si son numericos, convierto la cadena a INT
					bufferInt = atoi(bufferCadenaAux);

					if(bufferInt >= minimo && bufferInt <= maximo){
						*pResultado = bufferInt;
						retorno = 0;
						break;
					}else{
						printf("%s", mensajeError);
					}
				}
				else {
					printf("%s", mensajeError);
				}
			}
			else {
				printf("%s", mensajeError);
			}
		}
	}
	return retorno;
}
int utn_getFloat(float* pResultado, char* variableTexto,char* textoError,float min, float max, int reintentos)
{
	float buffer;
	int retorno=-1;
	int i;
	int salidaScanf;
	if(pResultado != NULL && min<max && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);
			fflush(stdin);

			salidaScanf=scanf("%f", &buffer);

			//printf("\nLa salida del scanf es : %d\n\n",salidaScanf);
			if (salidaScanf>0 && buffer>=min && buffer<=max)
			{

				retorno = 0; // OK
				*pResultado=buffer;
				break;
			}
			else
			{
				retorno=-2;
				printf("%s\n",textoError);
			}
		}
	}
	return retorno;
}
