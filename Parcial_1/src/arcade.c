/*
 * arcade.c
 *
 *  Created on: 17 oct. 2021
 *      Author: adrian
 */
#include "arcade.h"
#include <stdio.h>
#include "UTN.h"
static int getNewId(void);
static int getNewId(void)
{
	static int contador=0;
	return contador++;
}
int arc_InciarLista(Arcade array[], int len)
{
    int i;
    int banderaTodoBien;

    banderaTodoBien = 0;

    if(array != NULL && len>0)
    {
        banderaTodoBien = 1;
        for (i=0; i<len ;i++)
        {
        	array[i].isEmpty = 1;
        }
    }
    return banderaTodoBien;
}
int arc_CargarSoloUno(Arcade array[])
{
	int rtn=-1;
	char nacionalidadAux[50];
	int tipoSonidoAux;
	int cantidadJugadoresAux;
	int capacidadMaximaFichas;
	char nombreJuegoAux[63];
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
									strncpy(array->nacionalidad,nacionalidadAux,sizeof(array->nacionalidad));
									array->tipoDeSonido=tipoSonidoAux;
									array->cantidadDeJugadores=cantidadJugadoresAux;
									array->capacidadMaximaFichas=capacidadMaximaFichas;
									strncpy(array->nombreJuego,nombreJuegoAux,sizeof(array->nombreJuego));
									array->idArcade=getNewId(); // generar el ID
									array->isEmpty=OCUPADO;
									//array->idSalon=idSalon;
									rtn=0;
								}
							}
						}
					}
				}

	}
	return rtn;
}
int arc_Alta(Arcade array[],int len)//busca lugar libre y carga los display
{
	int retorno=-1;
	int lugarLibre;
	if(array!=NULL)
	{
		lugarLibre=arc_EncontrarIndexVacio(array, len);//busca lugar libre
		if(lugarLibre==-1)
			{
				printf("error todos los lugares ocupados: %d \n",lugarLibre);
			 }else
			 {
				 arc_CargarSoloUno(&array[lugarLibre]);
			 }

	}
	return retorno;
}

int arc_EncontrarIndexVacio(Arcade array[],int len)//busca el primer lugar libre
{
	int retorno=-1;
	int i;
	if(array!=NULL&& len>0)
	{
		for(i=0;i<len;i++)
		{
			if(array[i].isEmpty==1)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
void arc_ImprimirSoloUno(Arcade array)
{
			printf("%s Tipo de sonido:%d  Cantidad de jugadores:%d Capacidad maximas de fichas: %d Nombre del juego:%s ID:%d Estado:%d \n",array.nacionalidad,array.tipoDeSonido
					,array.cantidadDeJugadores,array.capacidadMaximaFichas,array.nombreJuego,array.idArcade,array.isEmpty);
}
int arc_ImprimirTodos (Arcade array[], int len)
{
	int rtn=-1;
	int i;
	if(array!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(array[i].isEmpty==0)
			{
				arc_ImprimirSoloUno(array[i]);
				rtn=1;
			}

		}
	}
	return rtn;
}
void arc_ImprimirNombreJuego(Arcade array)
{
	printf("%s \n",array.nombreJuego);
}
void arc_ImprimirNombreJuegos(Arcade array[],int len)
{
	int i;
	if(array!=NULL&&len>0)
	{
		for(i=0;i<len;i++)
		{
			if(array[i].isEmpty==OCUPADO)
			{
				arc_ImprimirNombreJuego(array[i]);
			}
		}

	}
}
int arc_BuscarIdOcupado(Arcade array[], int len, int ID) {
	int retorno = -1;//error
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && len > 0 && ID>=0)
	{
		//RECORRO TODO EL ARRAY
		for (i = 0; i < len; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idArcade == ID && array[i].isEmpty == 0) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
int arc_DarBajaId(Arcade array[],int len,int id)
{
	int rtn;
	int foundDysplayPosition;
	foundDysplayPosition=arc_BuscarIdOcupado(array, len, id);
	if(array!=NULL && foundDysplayPosition==-1)
	{
		printf("error del delete \n");
	}else
	{
		array[foundDysplayPosition].isEmpty=1;
		rtn=1;
	}

	return rtn;

}
int arc_ModificarCantidadJugadores(Arcade array[])
{
	int rtn=-1;
	int cantidadJugadoresAux;
	if(array!=NULL)
	{
		if(utn_getInt(&cantidadJugadoresAux,"Ingrese la cantidad de jugadores entre 1 y 5 :", "Dato invalido", 1,5,2)==0)
				{
								array->cantidadDeJugadores=cantidadJugadoresAux;
								array->isEmpty=0;
								rtn=0;
				}

	}
	return rtn;
}
int arc_ModificarNombreJuego(Arcade array[])
{
	int rtn=-1;
	char nombreJuegoAux[63];
	if(array!=NULL)
	{
		if(utn_getText(nombreJuegoAux, 63, "/*Modificacion*/Ingrese nombre del juego a reemplazar : ", "Dato invalido", 2)==0)
		{
			strncpy(array->nombreJuego,nombreJuegoAux,sizeof(array->nombreJuego));
		}
	}
	return rtn;
}
int arc_ModificacionVerificada(Arcade array[],int len)
{
	int rtn=-1;//error
	int indexAmodificar;
	int idIngresado;
	int numeroIngresado;
	if(array!=NULL && len >0)
	{
		arc_ImprimirTodos(array, len);//imprimir lista
			if(utn_getInt(&idIngresado, "ingrese el id a modificar: ", "error ingrese id valido", 0, 99, 5)==0)// pido el id al usuario
				 {
					 indexAmodificar=arc_BuscarIdOcupado(array,len,idIngresado);// Busco si ese ID esta en uso
					 if(indexAmodificar==-1)
					 {
						 printf("error no exite el ID\n");// el ID no existe porque esta libre y no se puede modificar
					 }else
					 {
						 if(utn_getInt(&numeroIngresado, "Ingrese 1 si desea modificar cantidad de jugadores o 2 el Juego que contiene este arcade: " , "Dato invalido", 1, 2,3)==0)
						 {
							 if(numeroIngresado==1)
							 {
								 arc_ModificarCantidadJugadores(&array[indexAmodificar]);
								 rtn=0;
							 }else
							 {
								 arc_ImprimirNombreJuegos(array, len);//imprime lista se solo nombre de juegos ya cargados
								 arc_ModificarNombreJuego(&array[indexAmodificar]);
								 rtn=0;
							 }
						 }
					 }
				 }
	}
		return rtn;
}






