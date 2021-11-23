#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Arcades.h"
#include "parser.h"
#include "validator.h"




/** \brief Parsea los datos los datos de los Arcades desde el archivo arcades.csv (modo texto).
 *
 * \param path char*
 * \param pArrayArcades LinkedList*
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
				printf("Archivo Sin Datos se Sobreescribira el Mismo\n");
				break;
			}

		}while (feof(pFile)==0);
	}
	return retorno;
}
/**brief guarda archivo texto
 *  param *pfile puntero al archivo
 *  param lista LL
 * 	return -1 si el puntero o la lista son NULL
 */
int parser_saveAsText(FILE* pFile , LinkedList* list)
{
	int retorno =-1;
	Arcade *pArcade; // puntero Arcade
	int id;
	char nacionalidad[NACIONALIDAD_LEN];
	int sonido;
	int cantidadJugadores;
	int cantidadFichas;
	char nombreSalon[NOMBRESALON_LEN];
	char nombreJuego[NOMBREJUEGO_LEN];

	if(pFile!=NULL && list!=NULL)
	{

		fprintf(pFile,"id,nacionalidad,tipo_sonido,cant_jug,fichas_max,salon,game\n"); // cabecera del archivo
		for(int i=0; i<ll_len(list); i++) // recorro la lista
		{

			pArcade=ll_get(list, i); //obtengo el elemento del nodo en este index
			if (pArcade!=NULL)
			{
				arcade_getFichas(pArcade, &cantidadFichas);
				arcade_getId(pArcade, &id);
				arcade_getJugadores(pArcade, &cantidadJugadores);
				arcade_getNacionalidad(pArcade, nacionalidad);
				arcade_getNombreJuego(pArcade, nombreJuego);
				arcade_getNombreSalon(pArcade, nombreSalon);
				arcade_getSonido(pArcade, &sonido);
				if(sonido==STEREO) //si es stereo o mono
				{
					fprintf(pFile,"%d,%s,STEREO,%d,%d,%s,%s\n",id,nacionalidad,cantidadJugadores,cantidadFichas,nombreSalon,nombreJuego);
				}
				else
				{
					fprintf(pFile,"%d,%s,MONO,%d,%d,%s,%s\n",id,nacionalidad,cantidadJugadores,cantidadFichas,nombreSalon,nombreJuego);
				}
			}

		}
		retorno=0;
		}
	return retorno;
}


