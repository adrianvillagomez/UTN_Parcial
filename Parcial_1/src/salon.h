/*
 * salon.h
 *
 *  Created on: 17 oct. 2021
 *      Author: adrian
 */

#ifndef SALON_H_
#define SALON_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN.h"
#define SHOPPING 2
#define LOCAL 3
#define LIBRE 1
#define OCUPADO 0
//defino estructura
typedef struct{
	int idSalon;
	int isEmpty;
	char nombre[120];
	char direccion[120];
	int tipo;
}Salon;
int sal_InciarLista(Salon array[], int len);
int sal_EncontrarIndexVacio(Salon array[],int len);
int sal_CargarSoloUno(Salon array[]);
int sal_Alta(Salon array[],int len);
//int sal_BuscarIdOcupado(Salon array[], int len, int ID);
//int sal_DarBajaId(Salon array[],int len,int id);
void sal_ImprimirSoloUno(Salon array);
int sal_ImprimirTodos (Salon array[], int len);
void sal_harcode(Salon array[],int indice,int idSalon,char nombre[],char direccion[],int tipo,int isEmpty);



#endif /* SALON_H_ */
