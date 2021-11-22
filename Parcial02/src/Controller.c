#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Arcades.h"
#include "utn_validador.h"
#include "parser.h"
#include "Validator.h"


/** \brief Carga los datos de los empleados desde el archivo acades.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayArcades)
{
	int retorno=-1;
	FILE *fp;
	if(path!=NULL && pArrayArcades!=NULL)
	{
		fp = fopen(path, "r");
		if(fp!=NULL)
		{
			if (parser_arcadesFromText(fp, pArrayArcades)==0)
				{
					retorno=0;
				}
			fclose(fp);
		}
		else
		{
			retorno=-2;
			printf("Archivo no Existe\n");
		}

	}
	return retorno;
}

/** \brief Alta de Arcade
 * \param pArrayListEmployee LinkedList*
 * \return int -1 lista LInken List NULL  0 si se creo con Exito -2 si fallo el ingreso de datos
 *
 */
int controller_addArcade(LinkedList* pArrayArcades)
{
	int retorno=-1;
	int id;
	char nacionalidad[NACIONALIDAD_LEN];
	int sonido;
	int cantidadJugadores;
	int cantidadFichas;
	char nombreSalon[NOMBRESALON_LEN];
	char nombreJuego[NOMBREJUEGO_LEN];
	Arcade* newArcade;

	if (pArrayArcades!=NULL)
	{

		newArcade=arcade_new();
		if(newArcade!=NULL)
		{

			if(utn_pedirNombreYApellidoAUsuario(nacionalidad, NACIONALIDAD_LEN, 3, "Ingrese Nacionalidad de Arcade", "Error, Caracteres No Admitidos")==0 &&
					utn_pedirIntAUsuarioConLimites(&sonido, 0, 1, 3, "Ingrese:\n0.-MONO\n1.-STEREO", "Error, Caracteres No Admitidos")==0 &&
					utn_pedirIntPositivoAUsuario(&cantidadFichas, 3, "Ingrese Cantidad Fichas del Arcade", "Error")==0 &&
					utn_pedirLetrasyNumerosConEspacioAUsuario(nombreSalon, NOMBRESALON_LEN, 3, "Ingrese Nombre Salon al que Pertenece", "Error, Caracteres No Admitidos")==0 &&
					utn_pedirNombreYApellidoAUsuario(nombreJuego, NOMBREJUEGO_LEN, 3, "Ingrese el nombre de Juego", "Error, Caracteres No Admitidos")==0 &&
					utn_pedirIntPositivoAUsuario(&cantidadJugadores, 3, "Cantidad de Jugadores", "Error, Caracteres No Admitidos")==0)
			{
				id=newId(pArrayArcades);
				arcade_setId(newArcade, id);
				arcade_setCantidadFichas(newArcade, cantidadFichas);
				arcade_setSonido(newArcade, sonido);
				arcade_setCantidadJugadores(newArcade, cantidadJugadores);
				arcade_setNacionalidad(newArcade, nacionalidad);
				arcade_setNombreSalon(newArcade, nombreSalon);
				arcade_setNombreJuego(newArcade, nombreJuego);
				ll_add(pArrayArcades, newArcade);
				retorno=0;
				printf("cargado con exito");
			}
			else
			{
				retorno=-2;
				free(newArcade);
			}

		}


	}


	return retorno;
}

int controller_removeArcade(LinkedList* pArrayArcade)
{
	int retorno=-1;
	int idFree;
	char letra[2];
	Arcade *pArcade=NULL;
	if(pArrayArcade!=NULL)
	{
		if(utn_pedirIntPositivoAUsuario(&idFree, 3, "Ingrese Id A Eliminar", "Error")==0)
		{
			pArcade=arcade_findById(pArrayArcade, idFree);
			if (pArcade!=NULL && utn_pedirLetrasAUsuario(letra, 2, 3, "Ingrese S para Confirmar, Cualquier otra Tecla para volver al Inicio", "Volviendo al Inicio")==0)
			{
				//printf("parcade %p", pArcade);
				if(ll_pop(pArrayArcade, ll_indexOf(pArrayArcade, pArcade))==pArcade)
				{
					printf("ELIMINASTE:\n");
					ImprimirLista(pArcade);
					free(pArcade);
					retorno=0;
				}
			}
			else
			{
				printf("id No Existe\n");
				//retorno=-1;
			}
		}
	}
	return retorno;
}


int controller_ListArcade(LinkedList* pArrayArcade)
{
	int retorno=-1;
	if(pArrayArcade!=NULL)
	{
		ll_map(pArrayArcade, ImprimirLista);
	}
	return retorno;
}


int controller_editArcade(LinkedList* pArrayArcade)
{
	int retorno=-1;
	int index;
	char letra[2];
	Arcade *pArcade=NULL;
	if(pArrayArcade!=NULL)
	{
		if(utn_pedirIntPositivoAUsuario(&index, 3, "Ingrese Id A Editar", "Error")==0)
		{
			index=arcade_findByIdIndex(pArrayArcade, index);
			if(index>=0)
			{
				pArcade=(Arcade*)ll_get(pArrayArcade, index);
				if(pArcade!=NULL && )
				{

				}
				else
				{
					printf("NULL");
				}
			}
			else
			{
				printf("Id No Existe");
			}
		}
	}
	return retorno;
}
