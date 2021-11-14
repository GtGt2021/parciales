/*
 * combinadas.h
 *
 *  Created on: 19 oct. 2021
 *      Author: gt
 */

#ifndef COMBINADAS_H_
#define COMBINADAS_H_


int arcade_buscarJuegoEnListayContarArcades(eArcades* arcade[], int len, char nombreJuego []);
int compararArcadeYSalon(eSalones* salones[], int len_salon, int idSalonArcade);
int imprimirTodoArcadeySalon(eSalones* salones[], int len_salon, eArcades* arcades[], int len_arcades);
//int salones_contarSalones(eCantidadSalones listSalones[], int len, int numSalon);
//int salones_generarListaSalon(eSalones salones[], int len_salones, eCantidadSalones listSalones[],int len_contadorSalones);
//int buscarEnArcade(int numeroABuscar, eArcades arcades, int len_arcades);
//int salon_contarSalasConMasCuatro(eCantidadSalones listSalones[], int len_listSalones, eArcades arcades, int len_arcades, eSalones salones, int len_salones);
int ContadorArcadesEnSalones(eSalones* salon[], int lenSalon, eArcades* arcade[], int lenArcade);
int arcadesDosOMasJugadores(eSalones* salon[], int lenSalon, eArcades* arcade[], int lenArcade);
int listarInformacionSalonEspecifico(eSalones* salon[], int lenSalon, int id, eArcades* arcade[], int lenArcade);
int listarArcadesDeUnSalon(eSalones* salon[], int lenSalon, int idSalon, eArcades* arcade[], int lenArcade);
int imprimirSalonMasArcades(eArcades* arcade[], int lenArcade, eSalones* salon[], int lenSalon);
int montoMaximoRecaudacion(eArcades* arcade[], int lenArcade, eSalones* salon[], int lenSalon, int indexSalon, float precioFicha);
int arcade_buscarJuegoEnListayContarArcades(eArcades* juegos[], int len, char nombreJuego []);
int ContadorArcadesMas8(eSalones* salon[], int lenSalon, eArcades* arcade[], int lenArcade);
int promedioArcadesSalon(eSalones* salon[], int lenSalones, eArcades* arcade[], int lenArcades, float *promedio);
#endif /* COMBINADAS_H_ */
