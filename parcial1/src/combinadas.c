/*
 * combinadas.c
 *
 *  Created on: 19 oct. 2021
 *      Author: gt
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_validador.h"
#include "salon.h"
#include "arcade.h"
#define OCUPADO 1
#define OCUPADO 0

int compararArcadeYSalon(eSalones salones, int len_salon, int idSalonArcade)
{
	int retorno=-1;
	for (int i=0; i<len_arcades; i++)
	{
		if(salones[i].id_salon==idSalonArcade)
		{
			print("")
			retorno=0;
		}
	}


	return retorno;
}

int imprimirTodoArcadeySalon(eSalones salones[], int len_salon, eArcades arcades[], int len_arcades)
{
	int retorno=-1;
	for (int i=0; i<len_arcades; i++)
	{
		if(arcades[i].isEmpty_arcade==OCUPADO && arcade_printPosition(&arcades[i])==0)
		{
			compararArcadeYSalon(salones, len_salon, arcades[i].idSalon_arcade);
			retorno=0;
		}
	}
	return retorno;
}

