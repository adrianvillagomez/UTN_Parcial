/*
 * SalonArcade.c
 *
 *  Created on: 19 oct. 2021
 *      Author: adrian
 */
#include "SalonArcade.h"
#include <stdio.h>
#include "UTN.h"
static int getNewId(void);
static int getNewId(void)
{
	static int contador=5;
	return contador++;
}
int arc_CargarSoloUno(Arcade array[],Salon list[],int lenSalon)
{
	int rtn=-1;
	char nacionalidadAux[50];
	int tipoSonidoAux;
	int cantidadJugadoresAux;
	int capacidadMaximaFichas;
	char nombreJuegoAux[63];
	int idSalon;
	if(array!=NULL)
	{
		if(utn_getText(nacionalidadAux, 50, "Ingrese Nacionalidad: ", "Dato invalido", 2)==0)
				{
					if(utn_getInt(&tipoSonidoAux, "Ingrese 4 para sonido MONO o 5 para ESTERIO", "Dato invalido", 4, 5, 2)==0)
					{
						if(utn_getInt(&cantidadJugadoresAux, "Ingrese la cantidad de jugadores entre 1 y 5 :", "Dato invalido", 1, 5, 2)==0)
						{
							if(utn_getInt(&capacidadMaximaFichas, "Ingrese la capacidad maxima de fichas entre 1-50:", "Dato invalido", 1, 50, 2)==0)
							{
								if(utn_getText(nombreJuegoAux, 63, "Ingrese el nombre del juego", "Dato invalido", 2)==0)
								{
									if(utn_getInt(&idSalon,"Ingrese ID salon al que pertenece este arcade", "Dato invalido", 0, 20,2)==0)
									{
									strncpy(array->nacionalidad,nacionalidadAux,sizeof(array->nacionalidad));
									array->tipoDeSonido=tipoSonidoAux;
									array->cantidadDeJugadores=cantidadJugadoresAux;
									array->capacidadMaximaFichas=capacidadMaximaFichas;
									strncpy(array->nombreJuego,nombreJuegoAux,sizeof(array->nombreJuego));
									array->idArcade=getNewId(); // generar el ID
									array->isEmpty=OCUPADO;
									while(sal_BuscarIdOcupado(list,lenSalon,idSalon)==-1)
									{
										utn_getInt(&idSalon, "ID Salon no encontrado ingrese otro", "Dato invalido", 0, 20, 2);
									}
									array->idSalon=idSalon;
									rtn=0;
									}
								}
							}
						}
					}
				}

	}
	return rtn;
}
int arc_Alta(Arcade array[],int lenArcade,Salon list[],int lenSalon)//busca lugar libre y carga los display
{
	int retorno=-1;
	int lugarLibre;
	if(array!=NULL)
	{
		lugarLibre=arc_EncontrarIndexVacio(array, lenArcade);//busca lugar libre
		if(lugarLibre==-1)
			{
				printf("error todos los lugares ocupados: %d \n",lugarLibre);
			 }else
			 {
				 //arc_CargarSoloUno(&array[lugarLibre]);
				 arc_CargarSoloUno(&array[lugarLibre], list, lenSalon);
				 retorno=0;
			 }

	}
	return retorno;
}
int sal_BuscarIdOcupado(Salon array[], int len, int ID) {
	int retorno = -1;//error
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && len > 0 && ID>=0)
	{
		//RECORRO TODO EL ARRAY
		for (i = 0; i < len; i++)
		{
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idSalon == ID && array[i].isEmpty == OCUPADO)
			{
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
int sal_DarBajaId(Salon array[],int lenSalon,int id,int lenArcade,Arcade listArcade[])
{
	int rtn=-1;
	int foundDysplayPosition;
	foundDysplayPosition=sal_BuscarIdOcupado(array, lenSalon, id);
	if(array!=NULL && foundDysplayPosition==-1)
	{
		printf("error del delete \n");
	}else
	{
		array[foundDysplayPosition].isEmpty=1;
		for(int i=0;i<lenArcade;i++)
		{
			if(listArcade[i].isEmpty==OCUPADO && listArcade[i].idSalon==id)
			{
				listArcade[i].isEmpty=LIBRE;
			}
		}
		rtn=0;
	}

	return rtn;

}
