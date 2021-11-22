/*
 * Arcades.h
 *
 *  Created on: 20 nov. 2021
 *      Author: gt
 */

#ifndef ARCADES_H_
#define ARCADES_H_
#include "LinkedList.h"
#define NACIONALIDAD_LEN 128
#define NOMBREJUEGO_LEN 63
#define NOMBRESALON_LEN 128
#define MONO 0
#define STEREO 1



typedef struct
{
	int id;
	char nacionalidad[NACIONALIDAD_LEN];
	char nombreSalon[NOMBRESALON_LEN];
	int sonido;
	int cantidadFichas;
	char nombreJuego[NOMBREJUEGO_LEN];
	int cantidadJugadores;

}Arcade;


int newId(LinkedList* ArrayArcades);
Arcade* arcade_new();
Arcade* arcade_newParametros(char* id,char* nacionalidad,char* nombreSalon,char* sonido,char* cantidadFichas,char* nombreJuego,char* cantidadJugadores);
void ImprimirLista(void* pArcade);
Arcade* arcade_findById(LinkedList *pListArcade, int id);
int arcade_compareBySalon(void* pArcade1, void* pArcade2);
int arcade_compareByNationality(void* pArcade1, void* pArcade2);
int arcade_compareByGame(void* pArcade1, void* pArcade2);
int arcade_compareByFichas(void* pArcade1, void* pArcade2);
int arcade_compareByJugadores(void* pArcade1, void* pArcade2);
int employee_getOrden(int *orden, int *tipo);
int arcade_findByIdIndex(LinkedList *pListArcade, int id);


#endif /* ARCADES_H_ */
