/*
 * Arcades.c
 *
 *  Created on: 20 nov. 2021
 *      Author: gt
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_validador.h"
#include "Arcades.h"
#include "Validator.h"
#include "LinkedList.h"
#define STEREO 1
#define MONO 0


/**brief genero espacio en memoria para un nuevo arcade
 *
 */
Arcade* arcade_new()
{
	Arcade* newArcade;
	newArcade=(Arcade*)calloc(1, sizeof(Arcade));
	return newArcade;
}

int newId(LinkedList* ArrayArcades)
{
	int flagid=0;
	int max;
	int id;
	if(ArrayArcades!=NULL && ll_len(ArrayArcades))
	{
		Arcade* arcadeAux;

		for(int i=0; i<ll_len(ArrayArcades); i++)
		{
			arcadeAux=ll_get(ArrayArcades, i);
			arcade_getId(arcadeAux, &max);
			if(flagid==0)
			{
				id=max;
				flagid=1;
			}

			if(max>id)
			{
				id=max;
			}
		}
		id++;
	}
	return id;
}

Arcade* arcade_newParametros(char* id,char* nacionalidad,char* nombreSalon,char* sonido,char* cantidadFichas,char* nombreJuego,char* cantidadJugadores)
{

	Arcade* auxArcade;
	if(id!=NULL && nacionalidad!=NULL && nombreSalon!=NULL && sonido!=NULL && cantidadFichas!=NULL && nombreJuego!=NULL && cantidadJugadores!=NULL)
	{
		auxArcade=arcade_new();
		if(auxArcade!=NULL)
		{

			if(!(arcade_setCantidadFichasFile(auxArcade, cantidadFichas)==0 && arcade_setCantidadJugadoresFile(auxArcade, cantidadJugadores)==0 && arcade_setIdFile(auxArcade, id)==0 && arcade_setNacionalidadFile(auxArcade, nacionalidad)==0 && arcade_setNombreJuegoFile(auxArcade, nombreJuego)==0 && arcade_setNombreSalonFile(auxArcade, nombreSalon)==0 && arcade_setSonidoFile(auxArcade, sonido)==0))
			{
				printf("Error Al Leer Datos Id:%s", id);
				free(auxArcade); //errores de lectura entonces no guardo y libero la memoria;
			}
		}
		else
		{
			printf("NO HAY ESPACIO DE MEMORIA");
		}

	}
	return auxArcade;
}

void ImprimirLista(void* pArcade)
{
	int id;
	char nacionalidad[128];
	int cantidadJugadores;
	int cantidadFichas;
	char nombreSalon[128];
	char nombreJuego[63];
	int sonido;
	arcade_getFichas(pArcade, &cantidadFichas);
	arcade_getId(pArcade, &id);
	arcade_getJugadores(pArcade, &cantidadJugadores);
	arcade_getNombreJuego(pArcade, nombreJuego);
	arcade_getNombreSalon(pArcade, nombreSalon);
	arcade_getSonido(pArcade, &sonido);
	arcade_getNacionalidad(pArcade, nacionalidad);
	if(sonido==STEREO)
	{
		printf("id:%2d nacionalidad:%20s Sonido: STEREO jugadores: %2d Fichas: %2d salon: %8s Juego: %s\n",id,nacionalidad,cantidadJugadores,cantidadFichas,nombreSalon,nombreJuego);
	}
	else
	{
		printf("id:%2d nacionalidad:%20s Sonido: MONO jugadores: %2d Fichas: %2d salon: %8s Juego: %s\n",id,nacionalidad,cantidadJugadores,cantidadFichas,nombreSalon,nombreJuego);
	}

}

Arcade* arcade_findById(LinkedList *pListArcade, int id)
{
Arcade* pArcade=NULL;
int idAux;
if(pListArcade!=NULL)
{
	for(int i=0; i<ll_len(pListArcade); i++)
	{
		pArcade=ll_get(pListArcade, i);
		if(arcade_getId(pArcade, &idAux)==0)
		{
			if (idAux==id)
			{
				break;
			}
		}
		pArcade=NULL;
	}
}
return pArcade;
}


int arcade_findByIdIndex(LinkedList *pListArcade, int id)
{
	int retorno;
	Arcade* pArcade;
	int idAux;
	if(pListArcade!=NULL)
	{
		for(int i=0; i<ll_len(pListArcade); i++)
		{
			pArcade=ll_get(pListArcade, i);
			if(arcade_getId(pArcade, &idAux)==0)
			{
				if (idAux==id)
				{
					retorno=id;
					break;
				}
			}
			pArcade=NULL;
		}
	}
	return retorno;
}


int employee_getOrden(int *orden, int *tipo)
{
	int retorno=-1;
	if(tipo!= NULL &&  orden!=NULL && utn_pedirIntAUsuarioConLimites(orden, 1, 4, 3, "Ingresar El tipo de ordenamiento\n 1.-Nombre Juego\n 2.-Nacionalidad\n 3.-Cantidad de Jugadores\n 4.-Cantidad Fichas\n 5.-Nombre Salon\n",
			"Error")==0 && utn_pedirIntAUsuarioConLimites(tipo, 0, 1, 3, "Ingrese\n 1.-Creciente\n 0.-Decreciente", "error")==0)
	{
		retorno=0;
	}
	else
	{
		printf("Opcion no Dispobible\n");
	}
	return retorno;
}

int arcade_compareByJugadores(void* pArcade1, void* pArcade2)
{
	int retorno;

	Arcade* pArcadeUno = (Arcade*)pArcade1;
	Arcade* pArcadeDos = (Arcade*)pArcade2;
	int player1;
	int player2;
	arcade_getJugadores(pArcade1, &player1);
	arcade_getJugadores(pArcade2, &player2);
	if(player1>player2)
	{
		retorno=1;
	}
	else
	{
		if(player1==player2)
		{
			retorno=0;
		}
		else
		{
			retorno=-1;
		}
	}

	return retorno;
}

int arcade_compareByFichas(void* pArcade1, void* pArcade2)
{
	int retorno;

	Arcade* pArcadeUno = (Arcade*)pArcade1;
	Arcade* pArcadeDos = (Arcade*)pArcade2;
	int player1;
	int player2;
	arcade_getFichas(pArcade1, &player1);
	arcade_getFichas(pArcade2, &player2);
	if(player1>player2)
	{
		retorno=1;
	}
	else
	{
		if(player1==player2)
		{
			retorno=0;
		}
		else
		{
			retorno=-1;
		}
	}

	return retorno;
}

int arcade_compareByGame(void* pArcade1, void* pArcade2)
{
	int retorno;
	Arcade* pArcadeUno = (Arcade*)pArcade1;
	Arcade* pArcadeDos = (Arcade*)pArcade2;
	char name1[NOMBREJUEGO_LEN];
	char name2[NOMBREJUEGO_LEN];
	arcade_getNombreJuego(pArcadeUno, name1);
	arcade_getNombreJuego(pArcadeDos, name2);
	int tam=strcmp(name1,name2);
	if(tam>0)
	{
		retorno=1;
	}else
	{
		if (tam==0)
		{
			retorno=0;
		}
		else
		{
			retorno=-1;
		}
	}

return retorno;
}

int arcade_compareByNationality(void* pArcade1, void* pArcade2)
{
	int retorno;
	Arcade* pArcadeUno = (Arcade*)pArcade1;
	Arcade* pArcadeDos = (Arcade*)pArcade2;
	char name1[NACIONALIDAD_LEN];
	char name2[NACIONALIDAD_LEN];
	arcade_getNacionalidad(pArcadeUno, name1);
	arcade_getNacionalidad(pArcadeDos, name2);
	int tam=strcmp(name1,name2);
	if(tam>0)
	{
		retorno=1;
	}else
	{
		if (tam==0)
		{
			retorno=0;
		}
		else
		{
			retorno=-1;
		}
	}

return retorno;
}

int arcade_compareBySalon(void* pArcade1, void* pArcade2)
{
	int retorno;
	Arcade* pArcadeUno = (Arcade*)pArcade1;
	Arcade* pArcadeDos = (Arcade*)pArcade2;
	char name1[NACIONALIDAD_LEN];
	char name2[NACIONALIDAD_LEN];
	arcade_getNombreSalon(pArcadeUno, name1);
	arcade_getNombreSalon(pArcadeDos, name2);
	int tam=strcmp(name1,name2);
	if(tam>0)
	{
		retorno=1;
	}else
	{
		if (tam==0)
		{
			retorno=0;
		}
		else
		{
			retorno=-1;
		}
	}

return retorno;
}
