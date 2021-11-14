/*
 * salon.c
 *
 *  Created on: 16 oct. 2021
 *      Author: gt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_validador.h"
#include "salon.h"


int salonInitArray(eSalones* pArray[], int len)
{
	int retorno=-1;
	if(pArray!=NULL && len>=0)
	{
		retorno=0;
		for(int i=0; i<len; i++)
		{
			pArray[i]=NULL; // colocamos NULL todas las casillas del array sin direcciones
		}
	}
	return retorno;
}

int salonBuscarposicionLibre(eSalones* pArray[], int len, int *pposicionLibre)
{
	int retorno=-2;
	if(pArray!=NULL && pposicionLibre!=NULL && len>=0)
	{
		retorno=-1;//no hay lugar libre
		for (int i=0; i<len; i++)
		{
			if (pArray[i]==NULL)
			{
				*pposicionLibre=i;
				retorno=0;//consiguio posicion libre
				break;
			}
		}
	}

	return retorno;
}

eSalones* salonNuevo(void)
{
	eSalones* pSalon=(eSalones*)malloc(sizeof(eSalones));
	return pSalon;
}

//int liberaMemoria(eSalones* salon[])
