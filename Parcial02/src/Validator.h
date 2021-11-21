/*
 * Validator.h
 *
 *  Created on: 7 nov. 2021
 *      Author: gt
 */

#ifndef VALIDATOR_H_
#define VALIDATOR_H_
#define NACIONALIDAD_LEN 128
#define NOMBREJUEGO_LEN 63
#define NOMBRESALON_LEN 128
#define MONO 0
#define STEREO 1
#include "Arcades.h"

int arcade_setNombreJuegoFile(Arcade* pArcade,char* nombre);
int arcade_setNombreSalonFile(Arcade* pArcade,char* nombre);
int arcade_setNacionalidadFile(Arcade* pArcade,char* nombre);
int arcade_setIdFile(Arcade* pArcade,char* id);
int arcade_setCantidadJugadoresFile(Arcade* pArcade,char* cantidad);
int arcade_setCantidadFichasFile(Arcade* pArcade,char* cantidad);
int arcade_setSonidoFile(Arcade* pArcade,char* sonido);
int arcade_setNombreJuego(Arcade* pArcade,char* nombre);
int arcade_setSonido(Arcade* pArcade,int sonido);
int arcade_setCantidadFichas(Arcade* pArcade,int cantidad);
int arcade_setCantidadJugadores(Arcade* pArcade,int cantidad);
int arcade_setId(Arcade* pArcade,int id);
int arcade_setNacionalidad(Arcade* pArcade,char* nombre);
int arcade_setNombreSalon(Arcade* pArcade,char* nombre);
int arcade_getId(Arcade* pArcade,int* id);
int arcade_getFichas(Arcade* pArcade,int* fichas);
int arcade_getJugadores(Arcade* pArcade,int* jugadores);
int arcade_getNacionalidad(Arcade* pArcade,char* nacionalidad);
int arcade_getNombreJuego(Arcade* pArcade,char* juego);
int arcade_getNombreSalon(Arcade* pArcade,char* salon);
int arcade_getSonido(Arcade* pArcade,int* sonido);
#endif /* VALIDATOR_H_ */
