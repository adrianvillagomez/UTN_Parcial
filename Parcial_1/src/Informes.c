/*
 * Informes.c
 *
 *  Created on: 19 oct. 2021
 *      Author: adrian
 */
#include "Informes.h"
#include <stdio.h>
#include "UTN.h"


int inf_SalCuatroArc(Salon listSalon[],Arcade listArcade[],int lenArcade,int lenSalon)
{
	int rtn=-1;
	int i;
	int j;
	int contador=0;
	if(listArcade!=NULL && lenArcade>0 && listSalon!=NULL&&lenSalon>0)
	{
		for(i = 0;i < lenSalon; i++)
		{
			if(listSalon[i].isEmpty==OCUPADO)
			{
				contador=0;

				for(j=0;j<lenArcade;j++)
				{
					if(listArcade[j].isEmpty==OCUPADO && listArcade[j].idSalon==listSalon[i].idSalon)
					{
						contador++;
					}
				}
				if (contador > 4)
				{
					puts("--------------------------------------");
					printf("Este salon posee mas de 4 arcades \n");
					printf("ID:%d NombreSalon:%s  Direccion:%s TipoSalon:%d\n",listSalon[i].idSalon,listSalon[i].nombre,listSalon[i].direccion,listSalon[i].tipo);
					rtn=0;
					puts("--------------------------------------");
				}
			}
		}

	}
	return rtn;
}
int inf_ArcMasdeDos(Arcade listArcade[],int lenArcade,Salon listSalon[],int lenSalon)
{
	int rtn=-1;
	int i;
	int indexPosicion;
	if(listArcade!=NULL && lenArcade>0)
	{
		for(i=0;i<lenArcade;i++)
		{
			if(listArcade[i].isEmpty == OCUPADO && listArcade[i].cantidadDeJugadores>2)
			{
				puts("--------------------------------------");
				printf("Arcades con mas de 2 jugadores \n");
				indexPosicion=sal_BuscarIdOcupado(listSalon, lenSalon,listArcade[i].idSalon);
				printf("ID:%d Cantidad de jugadores:%d Nombre del juego:%s Nombre al salon que pertenece: %s \n",listArcade[i].idArcade,listArcade[i].cantidadDeJugadores,listArcade[i].nombreJuego,listSalon[indexPosicion].nombre);
				puts("--------------------------------------");
			}
		}

	}

	return rtn;

}
