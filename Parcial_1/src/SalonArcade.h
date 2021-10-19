/*
 * SalonArcade.h
 *
 *  Created on: 19 oct. 2021
 *      Author: adrian
 */

#ifndef SALONARCADE_H_
#define SALONARCADE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arcade.h"
#include "Salon.h"
#include "UTN.h"

/// @brief
/// funcion utilizada para cargar datos previos al alta
/// @param array *Array se Arcades
/// @param list *Array de Salones
/// @param lenSalon tamaño de array de Salones
/// @return -1 si ocurrio un erro / 0 si salio todo bien
int arc_CargarSoloUno(Arcade array[],Salon list[],int lenSalon);
/// @brief
/// Alta de arcades
/// @param array *Array se Arcades
/// @param lenArcade tamanaño del array de Arcades
/// @param list *Array de Salones
/// @param lenSalon tamaño de array de Salones
/// @return-1 si ocurrio un erro / 0 si salio todo bien
int arc_Alta(Arcade array[],int lenArcade,Salon list[],int lenSalon);
/// @brief
///
/// @param array *Array de Salones
/// @param len tamaño de array de Salones
/// @param ID ingresado por usuario
/// @return -1 si ocurrio un error / si esta encuentra el ID devuelve el index
int sal_BuscarIdOcupado(Salon array[], int len, int ID);
/// @brief
///
/// @param array *Array de Salones
/// @param lenSalon tamaño de array de Salones
/// @param id ID ingresado por usuario
/// @param lenArcade tamanaño del array de Arcades
/// @param listArcade *Array de Arcades
/// @return-1 si ocurrio un error / 0 si esta todo bien
int sal_DarBajaId(Salon array[],int lenSalon,int id,int lenArcade,Arcade listArcade[]);

#endif /* SALONARCADE_H_ */
