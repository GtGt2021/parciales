/*
 * Validator.c
 *
 *  Created on: 7 nov. 2021
 *      Author: gt
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Validator.h"
#include "utn_validador.h"


/**brief setea el nombre que viene del archivo en campo correspondiente al elemento
 * param Arcade *pArcade puntero al elemento a Modificar
 * param char nombre nombre traido del archivo
 * return -1 si encuentra algun error al leer el dato y 0 si todo OK (si lo cargo en el campo del elemento)
 */
int arcade_setNombreJuegoFile(Arcade* pArcade,char* nombre)
{
	int retorno=-1;
	if(pArcade!=NULL && nombre!=NULL)
	{
		if(utn_esNombreYApellido(nombre)==0)
		{
			strncpy(pArcade->nombreJuego,nombre,NOMBREJUEGO_LEN);
			retorno=0;
		}

	}
	return retorno;
}

/**brief setea el nombre SALON que viene del archivo en campo correspondiente al elemento
 * param Arcade *pArcade puntero al elemento a Modificar
 * param char nombre nombre SALON traido del archivo
 * return -1 si encuentra algun error al leer el dato y 0 si todo OK (si lo cargo en el campo del elemento)
 */
int arcade_setNombreSalonFile(Arcade* pArcade,char* nombre)
{
	int retorno=-1;
	if(pArcade!=NULL && nombre!=NULL)
	{
		if(utn_esLetraYNumero(nombre)==0)
		{
			strncpy(pArcade->nombreSalon,nombre,NOMBRESALON_LEN);
			retorno=0;
		}

	}
	return retorno;
}

/**brief setea la NACIONALIDAD que viene del archivo en campo correspondiente al elemento
 * param Arcade *pArcade puntero al elemento a Modificar
 * param char nombre NACIONALIDAD traida del archivo
 * return -1 si encuentra algun error al leer el dato y 0 si todo OK (si lo cargo en el campo del elemento)
 */
int arcade_setNacionalidadFile(Arcade* pArcade,char* nombre)
{
	int retorno=-1;
	if(pArcade!=NULL && nombre!=NULL)
	{
		if(utn_esNombreYApellido(nombre)==0)
		{
			strncpy(pArcade->nacionalidad,nombre,NACIONALIDAD_LEN);
			retorno=0;
		}

	}
	return retorno;
}

/**brief setea el ID que viene del archivo en campo correspondiente al elemento pasamos de char a int con ATOI ANTES DE SETEAR
 * param Arcade *pArcade puntero al elemento a Modificar
 * param char ID traido del archivo
 * return -1 si encuentra algun error al leer el dato y 0 si todo OK (si lo cargo en el campo del elemento)
 */
int arcade_setIdFile(Arcade* pArcade,char* id)
{
	int retorno=-1;
	int idAux;
	if (pArcade!= NULL && id!=NULL)
	{
		if(utn_esIntPositivo(id)==0)
		{
			idAux=atoi(id);
			pArcade->id=idAux;
			retorno=0;
		}
	}
	return retorno;
}

/**brief setea cantidadDeJugadore que viene del archivo en campo correspondiente al elemento pasamos de char a int con ATOI ANTES DE SETEAR
 * param Arcade *pArcade puntero al elemento a Modificar
 * param char cantidadJugadores traido del archivo
 * return -1 si encuentra algun error al leer el dato y 0 si todo OK (si lo cargo en el campo del elemento)
 */
int arcade_setCantidadJugadoresFile(Arcade* pArcade,char* cantidad)
{
	int retorno=-1;
	int cantidadAux;
	if (pArcade!= NULL && cantidad!=NULL)
	{
		if(utn_esIntPositivo(cantidad)==0)
		{
			cantidadAux=atoi(cantidad);
			pArcade->cantidadJugadores=cantidadAux;
			retorno=0;
		}
	}
	return retorno;
}

/**brief setea cantidadDeFichas que viene del archivo en campo correspondiente al elemento pasamos de char a int con ATOI ANTES DE SETEAR
 * param Arcade *pArcade puntero al elemento a Modificar
 * param char cantidadFichas traido del archivo
 * return -1 si encuentra algun error al leer el dato y 0 si todo OK (si lo cargo en el campo del elemento)
 */
int arcade_setCantidadFichasFile(Arcade* pArcade,char* cantidad)
{
	int retorno=-1;
	int cantidadAux;
	if (pArcade!= NULL && cantidad!=NULL)
	{
		if(utn_esIntPositivo(cantidad)==0)
		{
			cantidadAux=atoi(cantidad);
			pArcade->cantidadFichas=cantidadAux;
			retorno=0;
		}
	}
	return retorno;
}

/**brief setea el SONIDO que viene del archivo en campo correspondiente al elemento COLOCA 0 SI ES MONO y 1 SI ES STEREO
 * param Arcade *pArcade puntero al elemento a Modificar
 * param char sonido PALABRA SONIDO traido del archivo
 * return -1 si encuentra algun error al leer el dato y 0 si todo OK (si lo cargo en el campo del elemento)
 */
int arcade_setSonidoFile(Arcade* pArcade,char* sonido)
{
	int retorno=-1;
	if (pArcade!= NULL && sonido!=NULL)
	{
		if(utn_esNombre(sonido)==0)
		{
			if(strcmp("MONO", sonido))
			{
				pArcade->sonido=MONO;
				retorno=0;
			}
			else
			{
				if(strcmp("STEREO", sonido))
				{
					pArcade->sonido=STEREO;
					retorno=0;
				}
			}
		}
	}
	return retorno;
}


/**brief setea el nombre que viene del archivo en campo correspondiente al elemento
 * param Arcade *pArcade puntero al elemento a Modificar
 * param char nombre nombre traido del archivo
 * return -1 si encuentra algun error al leer el dato y 0 si todo OK (si lo cargo en el campo del elemento)
 */
 int arcade_setNombreJuego(Arcade* pArcade,char* nombre)
{
	int retorno=-1;
	if(pArcade!=NULL && nombre!=NULL)
	{
		strncpy(pArcade->nombreJuego,nombre,NOMBREJUEGO_LEN);
		retorno=0;
	}
	return retorno;
}

/**brief setea el nombre SALON que viene del archivo en campo correspondiente al elemento
 * param Arcade *pArcade puntero al elemento a Modificar
 * param char nombre nombre SALON traido del archivo
 * return -1 si encuentra algun error al leer el dato y 0 si todo OK (si lo cargo en el campo del elemento)
 */
int arcade_setNombreSalon(Arcade* pArcade,char* nombre)
{
	int retorno=-1;
	if(pArcade!=NULL && nombre!=NULL)
	{
			strncpy(pArcade->nombreSalon,nombre,NOMBRESALON_LEN);
			retorno=0;
	}
	return retorno;
}

/**brief setea la NACIONALIDAD que viene del archivo en campo correspondiente al elemento
 * param Arcade *pArcade puntero al elemento a Modificar
 * param char nombre NACIONALIDAD traida del archivo
 * return -1 si encuentra algun error al leer el dato y 0 si todo OK (si lo cargo en el campo del elemento)
 */
int arcade_setNacionalidad(Arcade* pArcade,char* nombre)
{
	int retorno=-1;
	if(pArcade!=NULL && nombre!=NULL)
	{
			strncpy(pArcade->nacionalidad,nombre,NACIONALIDAD_LEN);
			retorno=0;
	}
	return retorno;
}

/**brief setea el ID que viene del archivo en campo correspondiente al elemento pasamos de char a int con ATOI ANTES DE SETEAR
 * param Arcade *pArcade puntero al elemento a Modificar
 * param char ID traido del archivo
 * return -1 si encuentra algun error al leer el dato y 0 si todo OK (si lo cargo en el campo del elemento)
 */
int arcade_setId(Arcade* pArcade,int id)
{
	int retorno=-1;
	if (pArcade!= NULL && id>0)
	{
		pArcade->id=id;
		retorno=0;
	}
	return retorno;
}

/**brief setea cantidadDeJugadore que viene del archivo en campo correspondiente al elemento pasamos de char a int con ATOI ANTES DE SETEAR
 * param Arcade *pArcade puntero al elemento a Modificar
 * param char cantidadJugadores traido del archivo
 * return -1 si encuentra algun error al leer el dato y 0 si todo OK (si lo cargo en el campo del elemento)
 */
int arcade_setCantidadJugadores(Arcade* pArcade,int cantidad)
{
	int retorno=-1;
	if (pArcade!= NULL && cantidad>0)
	{
		pArcade->cantidadJugadores=cantidad;
		retorno=0;
	}
	return retorno;
}

/**brief setea cantidadDeFichas que viene del archivo en campo correspondiente al elemento pasamos de char a int con ATOI ANTES DE SETEAR
 * param Arcade *pArcade puntero al elemento a Modificar
 * param char cantidadFichas traido del archivo
 * return -1 si encuentra algun error al leer el dato y 0 si todo OK (si lo cargo en el campo del elemento)
 */
int arcade_setCantidadFichas(Arcade* pArcade,int cantidad)
{
	int retorno=-1;
	if (pArcade!= NULL && cantidad>0)
	{
		pArcade->cantidadFichas=cantidad;
		retorno=0;
	}
	return retorno;
}

/**brief setea el SONIDO que viene del archivo en campo correspondiente al elemento COLOCA 0 SI ES MONO y 1 SI ES STEREO
 * param Arcade *pArcade puntero al elemento a Modificar
 * param char sonido PALABRA SONIDO traido del archivo
 * return -1 si encuentra algun error al leer el dato y 0 si todo OK (si lo cargo en el campo del elemento)
 */
int arcade_setSonido(Arcade* pArcade,int sonido)
{
	int retorno=-1;
	if (pArcade!= NULL && sonido<=1 && sonido>=0)
	{
		if(sonido==0)
		{
			pArcade->sonido=MONO;
			retorno=0;
		}
		else
		{
			pArcade->sonido=STEREO;
			retorno=0;
		}
	}
	return retorno;
}
/**brief obtiene el id del elemento solicitado
 * param pArcade elemento a sacar el Id
 * param *id puntero al cual devuelve el id
 *-1 se hubo algun problema con el elemento o el puntero id 0 todo OK
 */
int arcade_getId(Arcade* pArcade,int* id)
{
	int retorno=-1;
	if (pArcade!= NULL && id!=NULL)
	{
		*id=pArcade->id;
		retorno=0;
	}
	return retorno;
}

/**brief obtiene el id del elemento solicitado
 * param pArcade elemento a sacar el Id
 * param *id puntero al cual devuelve el id
 *-1 se hubo algun problema con el elemento o el puntero id 0 todo OK
 */
int arcade_getFichas(Arcade* pArcade,int* fichas)
{
	int retorno=-1;
	if (pArcade!= NULL && fichas!=NULL)
	{
		*fichas=pArcade->cantidadFichas;
		retorno=0;
	}
	return retorno;
}

/**brief obtiene el id del elemento solicitado
 * param pArcade elemento a sacar el Id
 * param *id puntero al cual devuelve el id
 *-1 se hubo algun problema con el elemento o el puntero id 0 todo OK
 */
int arcade_getJugadores(Arcade* pArcade,int* jugadores)
{
	int retorno=-1;
	if (pArcade!= NULL && jugadores!=NULL)
	{
		*jugadores=pArcade->cantidadJugadores;
		retorno=0;
	}
	return retorno;
}

/**brief obtiene el id del elemento solicitado
 * param pArcade elemento a sacar el Id
 * param *id puntero al cual devuelve el id
 *-1 se hubo algun problema con el elemento o el puntero id 0 todo OK
 */
int arcade_getNacionalidad(Arcade* pArcade,char* nacionalidad)
{
	int retorno=-1;
	if (pArcade!= NULL && nacionalidad!=NULL)
	{
		strncpy(nacionalidad,pArcade->nacionalidad, NACIONALIDAD_LEN);
		retorno=0;
	}
	return retorno;
}

/**brief obtiene el id del elemento solicitado
 * param pArcade elemento a sacar el Id
 * param *id puntero al cual devuelve el id
 *-1 se hubo algun problema con el elemento o el puntero id 0 todo OK
 */
int arcade_getNombreJuego(Arcade* pArcade,char* juego)
{
	int retorno=-1;
	if (pArcade!= NULL && juego!=NULL)
	{
		strncpy(juego,pArcade->nombreJuego, NOMBREJUEGO_LEN);
		retorno=0;
	}
	return retorno;
}

/**brief obtiene el id del elemento solicitado
 * param pArcade elemento a sacar el Id
 * param *id puntero al cual devuelve el id
 *-1 se hubo algun problema con el elemento o el puntero id 0 todo OK
 */
int arcade_getNombreSalon(Arcade* pArcade,char* salon)
{
	int retorno=-1;
	if (pArcade!= NULL && salon!=NULL)
	{
		strncpy(salon,pArcade->nombreSalon, NOMBRESALON_LEN);
		retorno=0;
	}
	return retorno;
}


/**brief obtiene el id del elemento solicitado
 * param pArcade elemento a sacar el Id
 * param *id puntero al cual devuelve el id
 *-1 se hubo algun problema con el elemento o el puntero id 0 todo OK
 */
int arcade_getSonido(Arcade* pArcade,int* sonido)
{
	int retorno=-1;
	if (pArcade!= NULL && sonido!=NULL)
	{
		*sonido=pArcade->sonido;
		retorno=0;
	}
	return retorno;
}
