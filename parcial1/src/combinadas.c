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
#include "combinadas.h"
#define OCUPADO 1
#define VACIO 0
#define SHOPPING 1
#define LOCAL 2
/*
static int init_cantidadSalones(eCantidadSalones listSalones[], int len)
{
	int retorno=-1;
	int i;
	if(listSalones!=NULL && len>0)
	{

		for(i=0; i<len; i++)
		{
			listSalones[i].isEmpty=VACIO; // posicion Libre
		}
		retorno=0;
	}
	return retorno;
}
*/

int compararArcadeYSalon(eSalones salones[], int len_salon, int idSalonArcade)
{
	int retorno=-1;
	for (int i=0; i<len_salon; i++)
	{
		if(salones[i].isEmpty_salon==OCUPADO && salones[i].id_salon==idSalonArcade)
		{
			salon_printPositionIdNombreDirTipo(&salones[i]);
			retorno=0;
			break;
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

/***

int salones_contarSalones(eCantidadSalones listSalones[], int len, int numSalon)
{
	int retorno=-2;
	if (listSalones!=NULL && len>0 && numSalon>0)
	{
		retorno=-1;
		for (int i=0; i<len; i++)
		{
			if(listSalones[i].isEmpty==OCUPADO)
			{
				if(listSalones[i].Salones==numSalon)
				{
					retorno=0;
					break;
				}
			}
		}
	}
		return retorno;
}

int salones_generarListaSalon(eSalones salones[], int len_salones, eCantidadSalones listSalones[],int len_contadorSalones)
{
	int retorno=-1;
	init_cantidadSalones(listSalones, len_contadorSalones);
	int indexSalones=0;
	if(salones!=NULL && len_salones>0 && listSalones!=NULL && len_contadorSalones>0)
	{
		for(int i=0; i<len_salones; i++)
		{
			if(salones[i].isEmpty_salon==OCUPADO)
			{
				if(salones_contarSalones(listSalones, len_contadorSalones, salones[i].id_salon)==-1)
				{
					listSalones[indexSalones].Salones=salones[i].id_salon;
					listSalones[indexSalones].isEmpty=OCUPADO;
					indexSalones++;
					retorno=0;
				}
			}
		}

	}
	return retorno;
}

*/

int ContadorArcadesEnSalones(eSalones salon[], int lenSalon, eArcades arcade[], int lenArcade)
{
	int retorno=-1;
	int contador=0;
	for(int i; i<lenSalon; i++)
	{
		if(salon[i].isEmpty_salon==OCUPADO)
		{
			for (int j=0; j<lenArcade; j++)
			{
				if(arcade[j].isEmpty_arcade==OCUPADO && arcade[j].idSalon_arcade==salon[i].id_salon)
				{
					contador++;
					if(contador>4)
					{
						salon_printPositionIdNombreDirTipo(&salon[i]);
						contador=0;
						retorno=0;
						break;
					}
				}
			}
		}
	}
	return retorno;
}

int arcadesDosOMasJugadores(eSalones salon[], int lenSalon, eArcades arcade[], int lenArcade)
{
	int retorno=-1;
	if (salon!=NULL && lenSalon>0 && arcade!=NULL && lenArcade>0)
	{
		for(int i; i<lenArcade; i++)
		{
			if(arcade[i].isEmpty_arcade==OCUPADO && arcade[i].cantidad_jugadores>2)
			{
				for (int j=0; j<lenSalon; j++)
				{
					if(salon[j].isEmpty_salon==OCUPADO && arcade[i].idSalon_arcade==salon[j].id_salon)
					{
						retorno=0;
						printf("Id Arcade:%d\t cantidad de jugadores: %d\t juego:%s\t Nombre del Salon:%s\n", arcade[i].id_arcade, arcade[i].cantidad_jugadores, arcade[i].nombreJuego_arcade, salon[j].name_salon);
						break;
					}

				}
			}
		}
	}
	return retorno;
}

int listarInformacionSalonEspecifico(eSalones salon[], int lenSalon, int id, eArcades arcade[], int lenArcade)
{
	int retorno=-1;
	int indexImprimir;
	int contadorArcades=0;
	if (salon!=NULL && lenSalon>0 && arcade!=NULL && lenArcade>0)
		{
			if(findSalonById(salon, lenSalon, id, &indexImprimir)==0)
			{
				for(int i=0; i<lenArcade; i++)
				{
					if(salon[indexImprimir].id_salon==arcade[i].idSalon_arcade)
					{
						contadorArcades++;
					}
				}
				salon_printPositionIdNombreDirTipo(&salon[indexImprimir]);
				printf ("Cantidad de Arcades: %d\n\n", contadorArcades);
				retorno=0;
			}
		}
	return retorno;
}

int listarArcadesDeUnSalon(eSalones salon[], int lenSalon, int idSalon, eArcades arcade[], int lenArcade)
{
	int retorno=-1;
	int indexImprimir;
	int bandera=0;
	if (salon!=NULL && lenSalon>0 && arcade!=NULL && lenArcade>0)
		{
			if(findSalonById(salon, lenSalon, idSalon, &indexImprimir)==0)
			{
				for(int i=0; i<lenArcade; i++)
				{

					if(arcade[i].isEmpty_arcade==OCUPADO && salon[indexImprimir].id_salon==arcade[i].idSalon_arcade)
					{

						if(bandera<1)
						{
							if(salon[indexImprimir].tipo_salon==SHOPPING)
							{
								printf("Salon Nombre: %s, tipo: SHOPPING \nArcades de este Salon:\n", salon[indexImprimir].name_salon);
							}
							else
							{
								printf("Salon Nombre: %s, tipo: LOCAL \nArcades de este Salon:\n", salon[indexImprimir].name_salon);
							}
						}
						bandera++;

						arcade_printPosition(&arcade[i]);
					}
				}

				retorno=0;
			}
		}
	return retorno;
}

int imprimirSalonMasArcades(eArcades arcade[], int lenArcade, eSalones salon[], int lenSalon)
{
int retorno=-1;
int contador=0;
int maximo=0;
int indexSalonMax;
int i;
int j;
if (salon!=NULL && lenSalon>0 && arcade!=NULL && lenArcade>0)
{

	for(i=0; i<lenSalon; i++)
	{
		contador=0;
		if(salon[i].isEmpty_salon==OCUPADO)
		{
			for(j=0; j<lenArcade; j++)
			{
				if(arcade[j].isEmpty_arcade==OCUPADO && salon[i].id_salon==arcade[j].idSalon_arcade)
				{
				retorno=0;
				contador++;
				}
			}
		}
		if(contador>maximo)
		{
			maximo=contador;
			indexSalonMax=i;
		}
	}
	if(retorno==0)
	{
		salon_printPositionIdNombreDirTipo(&salon[indexSalonMax]);
		printf("Cantidad de Arcades: %d\n", maximo);
	}

}
return retorno;
}

int montoMaximoRecaudacion(eArcades arcade[], int lenArcade, eSalones salon[], int lenSalon, int indexSalon, float precioFicha)
{
int retorno=-1;
int acumuladorFichas=0;
float total;
int j;
if (salon!=NULL && lenSalon>0 && arcade!=NULL && lenArcade>0)
{

	for(j=0; j<lenArcade; j++)
	{
		if(arcade[j].isEmpty_arcade==OCUPADO && salon[indexSalon].id_salon==arcade[j].idSalon_arcade)
		{
		acumuladorFichas=acumuladorFichas+arcade[j].capacidadFichas_arcade;
		retorno=0;
		}
	}
	if (retorno==0)
	{
		total=acumuladorFichas*precioFicha;
		printf("El monto Maximo que puede Recaudar este salon es %.2f\n", total);
		retorno=0;
	}else
	{
		printf("No hay Arcades en este Salon");
	}

}
return retorno;
}

int arcade_buscarJuegoEnListayContarArcades(eArcades juegos[], int len, char nombreJuego [])
{
	//int retorno=-1;
	int contador=-1;
	if (juegos!=NULL && len>0 && nombreJuego!=NULL)
	{
		contador=0;
		for (int i=0; i<len; i++)
		{
			if(juegos[i].isEmpty_arcade==OCUPADO)
			{
				if(strncmp(juegos[i].nombreJuego_arcade,nombreJuego,NOMBRE_LEN)==0)
				{
					contador++;
				}
			}
		}

	}
		return contador;
}
