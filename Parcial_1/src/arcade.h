/*
 * arcade.h
 *
 *  Created on: 17 oct. 2021
 *      Author: adrian
 */

#ifndef ARCADE_H_
#define ARCADE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN.h"
#define MONO 4
#define ESTERIO 5
#define LIBRE 1
#define OCUPADO 0
//defino estructura
typedef struct{
	int idArcade;
	int isEmpty;
	char nacionalidad[50];
	int tipoDeSonido;
	int cantidadDeJugadores;
	int capacidadMaximaFichas;
	int idSalon;
	char nombreJuego[63];
}Arcade;
int arc_InciarLista(Arcade array[], int len);
int arc_EncontrarIndexVacio(Arcade array[],int len);
//int arc_CargarSoloUno(Arcade array[]);
//int arc_Alta(Arcade array[],int len);
int arc_BuscarIdOcupado(Arcade array[], int len, int ID);
int arc_DarBajaId(Arcade array[],int len,int id);
int arc_ModificarCantidadJugadores(Arcade array[]);
int arc_ModificarNombreJuego(Arcade array[]);
int arc_ModificacionVerificada(Arcade array[],int len);
void arc_ImprimirSoloUno(Arcade array);
int arc_ImprimirTodos (Arcade array[], int len);
void arc_ImprimirNombreJuego(Arcade array);
void arc_ImprimirNombreJuegos(Arcade array[],int len);
void arc_harcode(Arcade array[],int indice,int idArcade,char nacionalidad[],int tipoSonido,int cantidadJugadores,int capacidadMaximaFichas,char nombreJuego[],int isEmpty,int idSalon);
#endif /* ARCADE_H_ */
