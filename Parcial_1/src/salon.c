/*
 * salon.c
 *
 *  Created on: 17 oct. 2021
 *      Author: adrian
 */
#include "salon.h"
#include <stdio.h>
#include "UTN.h"
static int getNewId(void);
static int getNewId(void)
{
	static int contador=3;
	return contador++;
}
int sal_InciarLista(Salon array[], int len)
{
    int i;
    int rtn;

    rtn = -1;

    if(array != NULL && len>0)
    {
        rtn = 1;
        for (i=0; i<len ;i++)
        {
        	array[i].isEmpty = LIBRE;
        	rtn=0;
        }
    }
    return rtn;
}
int sal_CargarSoloUno(Salon array[])
{
	int rtn=-1;
	char nombreAux[50];
	char direccionAux[50];
	int tipoAux;

	if(array!=NULL)
	{
		if(utn_getText(nombreAux, 50, "Ingrese el nombre del salon: ", "Dato invalido", 2)==0)
				{
					if(utn_getText(direccionAux, 50, "Ingrese la direccion: ", "Dato invalido", 2)==0)
					{
						if(utn_getInt(&tipoAux, "Ingrese el tipo: Seleccion 2 para Shopping o 3 para Local" ,"Dato invalido", 2, 3, 2)==0)
						{
								array->idSalon=getNewId(); // generar el ID
								strncpy(array->nombre,nombreAux,sizeof(array->nombre));
								strncpy(array->direccion,direccionAux,sizeof(array->direccion));
								array->tipo=tipoAux;
								array->isEmpty=OCUPADO;
								rtn=0;
						}
					}
				}

	}
	return rtn;
}
int sal_Alta(Salon array[],int len)//busca lugar libre y carga los display
{
	int retorno=-1;
	int lugarLibre;
	if(array!=NULL)
	{
		lugarLibre=sal_EncontrarIndexVacio(array, len);//busca lugar libre
		if(lugarLibre==-1)
			{
				printf("error todos los lugares ocupados: %d \n",lugarLibre);
			 }else
			 {
				 sal_CargarSoloUno(&array[lugarLibre]);
				 retorno=0;
			 }

	}
	return retorno;
}

int sal_EncontrarIndexVacio(Salon array[],int len)//busca el primer lugar libre
{
	int retorno=-1;
	int i;
	if(array!=NULL&& len>0)
	{
		for(i=0;i<len;i++)
		{
			if(array[i].isEmpty==LIBRE)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
void sal_ImprimirSoloUno(Salon array)
{
		printf("%3s %15s %15d %10d %5d\n",array.nombre,array.direccion,array.tipo,array.idSalon,array.isEmpty);
}
int sal_ImprimirTodos (Salon array[], int len)
{
	printf("\n###################### Lista Salones ######################## \n");
	printf("Nombre     Direccion           Tipo          ID    Estado\n");
	int rtn=-1;
	int i;
	if(array!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(array[i].isEmpty==0)
			{
				sal_ImprimirSoloUno(array[i]);
				rtn=1;
			}

		}
	}
	return rtn;
}
/*int sal_BuscarIdOcupado(Salon array[], int len, int ID) {
	int retorno = -1;//error
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && len > 0 && ID>=0)
	{
		//RECORRO TODO EL ARRAY
		for (i = 0; i < len; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idSalon == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
int sal_DarBajaId(Salon array[],int len,int id)
{
	int rtn=-1;
	int foundDysplayPosition;
	foundDysplayPosition=sal_BuscarIdOcupado(array, len, id);
	if(array!=NULL && foundDysplayPosition==-1)
	{
		printf("error del delete \n");
	}else
	{
		array[foundDysplayPosition].isEmpty=1;
		rtn=0;
	}

	return rtn;

}*/
/*
 * int idSalon;
	int isEmpty;
	char nombre[120];
	char direccion[120];
	int tipo;
	min28
 */
void sal_harcode(Salon array[],int indice,int idSalon,char nombre[],char direccion[],int tipo,int isEmpty)
{
	array[indice].idSalon=idSalon;
	strncpy(array[indice].nombre,nombre,sizeof(array[indice].nombre));
	strncpy(array[indice].direccion,direccion,sizeof(array[indice].direccion));
	array[indice].tipo=tipo;
	array[indice].isEmpty=isEmpty;
}

