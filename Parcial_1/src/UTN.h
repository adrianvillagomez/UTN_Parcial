/*
 * UTN.h
 *
 *  Created on: 28 sep. 2021
 *      Author: adrian
 */

#ifndef UTN_H_
#define UTN_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int esNumerica(char cadenaNumeros[]);
int myGets(char pResultado[], int len);
int utn_getText(char pResultado[], int len, char* mensaje, char* mensajeError, int reintentos);
int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getFloat(float* pResultado, char* variableTexto,char* textoError,float min, float max, int reintentos);


#endif /* UTN_H_ */
