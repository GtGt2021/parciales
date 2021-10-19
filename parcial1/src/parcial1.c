/*
 ============================================================================
 Name        : parcial1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_validador.h"
#include "salon.h"
#include "arcade.h"
#define SALONES_LEN 5
#define ARCADES_LEN 1000
#define CON_TIPO 1
#define SIN_TIPO 2
#define NOMBREGAME_LEN 64

int main(void) {
	setbuf(stdout,NULL);
	eSalones eSalones[SALONES_LEN];
	eArcades eArcades[ARCADES_LEN];
	init_salones(eSalones, SALONES_LEN);
	init_arcades(eArcades, ARCADES_LEN);
	int menu;
	char juego[NOMBREGAME_LEN];
	int cantidad;
	int auxIndex;
	int auxiliarBaja;
	int auxiliarAltaArca;
	//int auxId;

	do
	{
		utn_pedirIntAUsuarioConLimites(&menu, 0, 8, 3, "Ingrese Numero De la Opcion Deseada:\n1.-Alta Salon\n2.-Eliminar Salon\n3.-Ver Salones Ingresados\n4.-Incorporar Arcade \n5.- Modificar Arcade", "Error");
		switch (menu) {
			case 1:
				switch (loadSalon(eSalones, SALONES_LEN))
				{
				case 0:
					printf("Salon Cargado Correctamente\n");
					break;
				case -1:
					printf("Error al Ingresar Datos\n");
					break;
				case -2:
					printf("Memoria Llena\n");
					break;
				case -3:
					printf("Error en el Archivo\n");
					break;
				}

				break;
			case 2:
				if(gen_verificarQueTieneDatosLista(eSalones, SALONES_LEN)==0)
				{
					printSalon(eSalones, SALONES_LEN, SIN_TIPO);
					if (utn_pedirIntPositivoAUsuario(&auxiliarBaja, 3, "Ingrese Id Salon que desea Eliminar", "Error")==0)
					{
						//FALTA COMPROBAR SI TIENE ARCADES Y DARLES DE BAJA
						removeSalon(eSalones, SALONES_LEN, auxiliarBaja);
						printf ("El Id %d, Fue eliminado Correctamente\n", auxiliarBaja);
					}
				}
				else
				{
					printf ("No hay Ningun Salon Cargado\n");
				}
				break;
			case 3:
				if(gen_verificarQueTieneDatosLista(eSalones, SALONES_LEN)==0)
				{
					printSalon(eSalones, SALONES_LEN, CON_TIPO);
				}
				else
				{
					printf ("No hay Ningun Salon Cargado\n");
				}
				break;
			case 4:
				if(gen_verificarQueTieneDatosLista(eSalones, SALONES_LEN)==0)
				{
					printSalon(eSalones, SALONES_LEN, 1);
					if(utn_pedirIntPositivoAUsuario(&auxiliarAltaArca, 3, "Ingrese el Numero del Id Del Salon al Cual le quiere cargar el Arcade:\n", "Error")==0)
					{
						switch (arcade_loadArcade(eArcades, ARCADES_LEN, auxiliarAltaArca))
						{
						case 0:
							printf("Salon Cargado Correctamente\n");
							break;
						case -1:
							printf("Error al Ingresar Datos\n");
							break;
						case -2:
							printf("Memoria Llena\n");
							break;
						case -3:
							printf("Error en el Archivo\n");
							break;

						}

					}
					else
					{
						printf("Id no esta en la lista\n");
					}


				}
				else
				{
					printf("No hay salones para cargar Arcades\n");
				}

				break;
			case 5:
				if(arcade_verificarQueTieneDatosLista(eArcades, ARCADES_LEN)==0)
				{
					arcadePrintArcade(eArcades, ARCADES_LEN);
					if (utn_pedirIntPositivoAUsuario(&auxiliarBaja, 3, "Ingrese Id Arcade que desea Modificar", "Error")==0)
					{
						if(arcade_findArcadeById(eArcades, ARCADES_LEN, auxiliarBaja, &auxIndex)==0)
						{
							if (utn_pedirIntAUsuarioConLimites(&menu, 1, 2, 3, "Ingrese Numero Segun lo que desea Modificar:\n1.-Juego \n2.-Cantidad de Jugadores", "Error")==0)
							{
								switch (menu)
								{
									case 2:
										if (utn_pedirIntPositivoAUsuario(&cantidad, 3, "Ingrese Nueva Cantidad de Jugadores", "Error")==0)
										{
											eArcades[auxIndex].cantidad_jugadores=cantidad;
										}
										break;
									case 1:
										arcadePrintArcadeGames(eArcades, ARCADES_LEN);
										if(utn_pedirNombreYApellidoAUsuario(juego, NOMBRE_LEN, 3, "Ingrese nuevo Juego", "Error")==0)
										{
											strncpy(eArcades[auxIndex].nombreJuego_arcade, juego, sizeof(eArcades->nombreJuego_arcade));
										}
										break;
								}
							}
						}
						else
						{
							printf("Id No Valido\n");
						}
					}

				}
				else
				{
					printf("No hay datos Cargados");
				}
				break;
			case 6:

				break;
			default:


				break;
		}


	}while(menu!=0);





	return EXIT_SUCCESS;
}