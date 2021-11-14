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
}eArcades;

typedef struct{
	char nombre[VIDEOJUEGO_LEN];
}eJuegos;

int arcade_initArray(eArcades* pArray[], int len);
eArcades* arcadeNuevo(void);
int arcade_cargarArcade(eArcades* arcade, int idSalon);
int arcade_buscarPosicionLibre(eArcades* arcade[], int len, int *index);
int arcade_verificarQueTieneDatosLista(eArcades* arcade[], int len);
int arcade_imprimirArcade(eArcades arcade[]);
int arcade_imprimirListaArcade(eArcades* arcade[], int len);
int arcade_darBajaArcade(eArcades* arcade);
int arcade_buscarArcadePorId(eArcades* list[], int len, int idBuscado, int *posicionIdBuscado);
int arcade_modificarLista(eArcades* arcade);
int arcade_imprimirListaJuegos(eJuegos* juegos[], int len);
int arcade_bajarArcadeById(eArcades* list[], int len, int idBuscado);
int juegos_initArray(eJuegos* list[], int len);
int arcade_buscarJuegoLista(eJuegos* juegos[], int len, char nombreJuego[]);
int arcade_generarListaJuegos(eArcades* arcades[], int lenArcades, eJuegos* juegos[],int lenJuegos);
int arcade_altaForzada(eArcades arcades[], char nombre[], char nacionalidad[], int tipoSonido, int idSalon, int cantidadJugadores, int cantidadFichas);
int arcade_bajarArcadeByIdArcade(eArcades* list[], int len, int idBuscado);
#endif
