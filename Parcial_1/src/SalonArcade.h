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
///
int arc_CargarSoloUno(Arcade array[],Salon list[],int lenSalon);
int arc_Alta(Arcade array[],int lenArcade,Salon list[],int lenSalon);

int sal_BuscarIdOcupado(Salon array[], int len, int ID);
int sal_DarBajaId(Salon array[],int lenSalon,int id,int lenArcade,Arcade listArcade[]);

#endif /* SALONARCADE_H_ */
