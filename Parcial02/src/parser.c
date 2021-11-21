#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Arcades.h"
#include "parser.h"




/** \brief Parsea los datos los datos de los Arcades desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_arcadesFromText(FILE* pFile , LinkedList* pArrayArcades)
{
	Arcade* pArcade;
	char id[16];
	char nacionalidad[256];
	char sonido[256];
	char cantidadJugadores[4];
	char cantidadFichas[8];
	char nombreSalon[128];
	char nombreJuego[63];
	int retorno=-1;

	if(pFile!=NULL && pArrayArcades!=NULL)
	{	//id,nacionalidad,tipo_sonido,cant_jug,fichas_max,salon,game
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nacionalidad,sonido,cantidadJugadores,cantidadFichas,nombreSalon,nombreJuego); // para saltarme la primera linea (leo char hasta la , y el ultimo hasta \n
		do
		{
			//printf("retorno fscanf:%d \n", prueba);
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nacionalidad,sonido,cantidadJugadores,cantidadFichas,nombreSalon,nombreJuego)==7) // leo uno  a uno si leyo los 7 sigo
			{
				//printf("el id es:%s\n",id); // los muestro
				pArcade=arcade_newParametros(id, nacionalidad, nombreSalon, sonido, cantidadFichas, nombreJuego, cantidadJugadores); // creo un employee con los datos
				if(pArcade!=NULL)
				{
					ll_add(pArrayArcades, pArcade); // agrego employee a ll
					retorno=0;//hay al menos 1 empleado
				}

			}
			else
			{
				printf("Archivo Corrupto\n");
				break;
			}

		}while (feof(pFile)==0);
	}
	return retorno;
}





