/*
 * Informes.h
 *
 *  Created on: 19 oct. 2021
 *      Author: adrian
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arcade.h"
#include "Salon.h"
#include "salonArcade.h"
#include "UTN.h"

int inf_SalCuatroArc(Salon listSalon[],Arcade listArcade[],int lenArcade,int lenSalon);
int inf_ArcMasdeDos(Arcade listArcade[],int lenArcade,Salon listSalon[],int lenSalon);

#endif /* INFORMES_H_ */
