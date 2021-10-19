/*
 * arcade.h
 *
 *  Created on: 16 oct. 2021
 *      Author: gt
 */

#ifndef ARCADE_H_
#define ARCADE_H_
#define NACIONALIDAD_LEN 24
#define VIDEOJUEGO_LEN 63
typedef struct{
	int tipoSonido_salon;
	int cantidad_jugadores;
	int idSalon_arcade;
	int capacidadFichas_arcade;
	int id_arcade;
	char nacionalidad_arcade [NACIONALIDAD_LEN];
	char nombreJuego_arcade [VIDEOJUEGO_LEN];
	int isEmpty_arcade;
}eArcades;

typedef struct{
	char nombre[VIDEOJUEGO_LEN];
	int isEmpty_juegos;
}eJuegos;

int init_arcades(eArcades list[], int len);
int arcade_loadArcade(eArcades arcade[], int len, int idSalon);
int arcade_IsFree(eArcades arcade[], int len, int *index);
int arcade_verificarQueTieneDatosLista(eArcades arcade[], int len);
int arcade_printPosition(eArcades arcade[]);
int arcadePrintArcade(eArcades arcade[], int len);
int arcade_findArcadeById(eArcades list[], int len, int idBuscado, int *posicionIdBuscado);
int arcade_modificarLista(eArcades arcade[]);
int arcadePrintArcadeGames(eJuegos juegos[], int len);
int arcade_bajarArcadeById(eArcades list[], int len, int idBuscado);
int init_juegos(eJuegos list[], int len);
int arcade_buscarJuegoLista(eJuegos juegos[], int len, char nombreJuego[]);
int arcade_generarListaJuegos(eArcades arcades[], int lenArcades, eJuegos juegos[],int lenJuegos);

#endif
