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
#include "combinadas.h"
#define SALONES_LEN 100
#define ARCADES_LEN 1000
#define CON_TIPO 1
#define SIN_TIPO 2
#define MONO 2
#define STEREO 1
#define SHOPPING 1
#define LOCAL 2
#define NOMBREGAME_LEN 64



int main(void) {
	setbuf(stdout,NULL);
	eSalones eSalones[SALONES_LEN];
	eArcades eArcades[ARCADES_LEN];
	eJuegos juegos[ARCADES_LEN];
	init_salones(eSalones, SALONES_LEN);
	init_arcades(eArcades, ARCADES_LEN);
	int menu;
	int auxMenu;
	char juego[NOMBREGAME_LEN];
	int cantidad;
	int auxIndex;
	int auxiliarBaja;
	int auxiliarAltaArca;
	char respuesta[2];
	float precioFicha;
	//int auxId;

	Salon_altaForzada(&eSalones[15], "BUENAVENTURA", "GUATIRE", LOCAL);
					Salon_altaForzada(&eSalones[90], "SAMBIL", "CARACAS", SHOPPING);
					Salon_altaForzada(&eSalones[91], "BUENAVENTURA", "GUATIRE", SHOPPING);
					Salon_altaForzada(&eSalones[92], "SAMBIL", "CARACAS", LOCAL);
					Salon_altaForzada(&eSalones[93], "SAMBIL", "GUATIRE", SHOPPING);
					Salon_altaForzada(&eSalones[94], "BUENAVENTURA", "CARACAS", LOCAL);
					Salon_altaForzada(&eSalones[95], "SAMBIL", "CARACAS", LOCAL);
					Salon_altaForzada(&eSalones[96], "BUENAVENTURA", "GUATIRE", SHOPPING);
					Salon_altaForzada(&eSalones[98], "SAMBIL", "GUATIRE", SHOPPING);
					Salon_altaForzada(&eSalones[15], "BUENAVENTURA", "GUATIRE", LOCAL);
					Salon_altaForzada(&eSalones[25], "SAMBIL", "CARACAS", SHOPPING);
					Salon_altaForzada(&eSalones[12], "BUENAVENTURA", "GUATIRE", SHOPPING);
					Salon_altaForzada(&eSalones[89], "SAMBIL", "CARACAS", LOCAL);
					Salon_altaForzada(&eSalones[42], "SAMBIL", "GUATIRE", SHOPPING);
					Salon_altaForzada(&eSalones[18], "BUENAVENTURA", "CARACAS", LOCAL);
					Salon_altaForzada(&eSalones[28], "SAMBIL", "CARACAS", LOCAL);
					Salon_altaForzada(&eSalones[70], "BUENAVENTURA", "GUATIRE", SHOPPING);
					Salon_altaForzada(&eSalones[45], "SAMBIL", "GUATIRE", SHOPPING);

					arcade_altaForzada(&eArcades[100], "Mortal Combat", "panama", 	STEREO, 2, 6, 12);
					arcade_altaForzada(&eArcades[101], "Mortal CHAM", "China", 		MONO, 6, 6, 12);
					arcade_altaForzada(&eArcades[102], "Mortal Combat", "colombia", MONO, 6, 6, 12);
					arcade_altaForzada(&eArcades[105], "Mortal cash", "China", 		STEREO, 3, 6, 12);
					arcade_altaForzada(&eArcades[110], "fith Combat", "panama",		 MONO, 5, 6, 12);
					arcade_altaForzada(&eArcades[114], "pulpo Combat", "colombia",	 STEREO, 5, 6, 12);
					arcade_altaForzada(&eArcades[125], "Mortal Combat", "panama",	 MONO, 5, 6, 12);
					arcade_altaForzada(&eArcades[198], "mortadela Combat", "colombia", STEREO, 5, 3, 12);
					arcade_altaForzada(&eArcades[200], "Mortal Combat", "China",	 MONO, 6, 2, 12);
					arcade_altaForzada(&eArcades[210], "Mortal Combat", "panama",	 STEREO, 6, 6, 12);
					arcade_altaForzada(&eArcades[211], "Mortal CHAM", "China", 		MONO, 6, 1, 12);
					arcade_altaForzada(&eArcades[241], "Mortal Combat", "colombia", MONO, 4, 6, 12);
					arcade_altaForzada(&eArcades[256], "Mortal cash", "China", 		STEREO, 4, 1, 12);
					arcade_altaForzada(&eArcades[300], "fith Combat", "panama",		 MONO, 3, 6, 12);
					arcade_altaForzada(&eArcades[301], "pulpo Combat", "colombia",	 STEREO, 3, 1, 12);
					arcade_altaForzada(&eArcades[302], "Mortal Combat", "panama",	 MONO, 3, 6, 12);
					arcade_altaForzada(&eArcades[303], "mortadela Combat", "colombia", STEREO, 1, 6, 12);
					arcade_altaForzada(&eArcades[304], "Mortal Combat", "China",	 MONO, 2, 6, 12);
					arcade_altaForzada(&eArcades[305], "Mortal Combat", "panama", 	STEREO, 6, 1, 12);
					arcade_altaForzada(&eArcades[306], "Mortal CHAM", "China", 		MONO, 6, 3, 12);
					arcade_altaForzada(&eArcades[307], "Mortal Combat", "colombia", MONO, 4, 1, 12);
					arcade_altaForzada(&eArcades[308], "Mortal cash", "China", 		STEREO, 6, 6, 12);
					arcade_altaForzada(&eArcades[309], "fith Combat", "panama", 	MONO, 2, 1, 12);
					arcade_altaForzada(&eArcades[310], "pulpo Combat", "colombia",	 STEREO, 4, 8, 12);
					arcade_altaForzada(&eArcades[311], "Mortal Combat", "panama",	 MONO, 5, 3, 12);
					arcade_altaForzada(&eArcades[312], "mortadela Combat", "colombia", STEREO, 8, 2, 12);
					arcade_altaForzada(&eArcades[313], "Mortal Combat", "China", 	MONO, 9, 1, 12);





	do
	{
		utn_pedirIntAUsuarioConLimites(&menu, 0, 9, 3, "\n\nIngrese Numero De la Opcion Deseada:\n1.-Alta Salon\n2.-Eliminar Salon\n3.-Ver Salones Ingresados\n4.-Incorporar Arcade \n5.-Modificar Arcade\n6.-Eliminar Arcade\n7.-Imprimir Arcades\n8.-Imprimir Juegos\n9.-Informes:", "Error");
		switch (menu)
		{
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
					{//pedi ID DE SALON
						if (removeSalon(eSalones, SALONES_LEN, auxiliarBaja)==0)//AUXILIAR BAJA ES EL ID DEL SALON y
						{

							arcade_bajarArcadeById(eArcades, ARCADES_LEN, auxiliarBaja);//ENTRO EN ARCADE.C Y PONGO EN 0 LOS QUE TENGAN ESTE ID DE SALON
							printf ("El Id %d, Fue eliminado Correctamente junto con sus arcades\n", auxiliarBaja);
						}

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
						if(gen_verificarIdExiste(eSalones, SALONES_LEN, auxiliarAltaArca)==0)
						{
							switch (arcade_loadArcade(eArcades, ARCADES_LEN, auxiliarAltaArca))
							{
							case 0:
								printf("Arcade Cargado Correctamente\n");
								break;
							case -1:
								printf("Error al Ingresar Datos\n");
								break;
							case -2:
								printf("Memoria Llena\n");
								break;
							case -3:
								printf("ID SALON NO EXISTE\n");
								break;
							}
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
							if (utn_pedirIntAUsuarioConLimites(&auxMenu, 1, 2, 3, "Ingrese Numero Segun lo que desea Modificar:\n1.-Juego \n2.-Cantidad de Jugadores", "Error")==0)
							{
								switch (auxMenu)
								{
									case 2:
										if (utn_pedirIntPositivoAUsuario(&cantidad, 3, "Ingrese Nueva Cantidad de Jugadores", "Error")==0)
										{
											eArcades[auxIndex].cantidad_jugadores=cantidad;
										}
										break;
									case 1:
										arcade_generarListaJuegos(eArcades, ARCADES_LEN, juegos, ARCADES_LEN);
										arcadePrintArcadeGames(juegos, ARCADES_LEN);
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
			case 6: //pendiente que no baja el empleado
				if(arcade_verificarQueTieneDatosLista(eArcades, ARCADES_LEN)==0)
				{
					imprimirTodoArcadeySalon(eSalones, SALONES_LEN, eArcades, ARCADES_LEN);
					if(utn_pedirIntPositivoAUsuario(&auxiliarBaja, 3, "Ingrese Id Arcade a dar de Baja\n", "error")==0)
					{
						if(arcade_findArcadeById(eArcades, ARCADES_LEN, auxiliarBaja, &auxIndex)==0)
						{
							printf("Este es el Arcade que quiere Dar de Baja\n");
							arcade_printPosition(&eArcades[auxIndex]);
							if(utn_pedirLetrasAUsuario(respuesta, 2, 0, "Esta seguro de dar de baja al arcade (s) para confirmar ", "Error")==0)
							{
								if(respuesta[0]=='s')
								{
									arcade_darBajaArcade(&eArcades[auxIndex]);
									printf ("El Id %d, Fue eliminado Correctamente\n", auxiliarBaja);

								}
								else
								{
									printf("volvemos al menu inicial\n");
								}
							}
						}

					}
				}
				else
				{
					printf("no tiene arcades ingresados a sistema");
				}

				break;
			default:
			case 7:
				if (arcade_verificarQueTieneDatosLista(eArcades, ARCADES_LEN)==0)
					{
					arcadePrintArcade(eArcades, ARCADES_LEN);
					}
				break;
			case 8:
				if (arcade_verificarQueTieneDatosLista(eArcades, ARCADES_LEN)==0)
					{
					printf("Lista de Juegos:\n");
					arcade_generarListaJuegos(eArcades, ARCADES_LEN, juegos, ARCADES_LEN);
					arcadePrintArcadeGames(juegos, ARCADES_LEN);
					}
				break;
			case 9:
				if(utn_pedirIntAUsuarioConLimites(&auxMenu, 1, 7, 3, "ingrese 1-2-3-4-5-6-7", "ERROR")==0)//utn_PedirCualquierCaracterAUsuario(respuesta, 2, 3, "ingrese A-B-C-D-E-F-G", "ERROR")==0)
				{
					switch (auxMenu)
					{
						case 1:
							ContadorArcadesEnSalones(eSalones, SALONES_LEN, eArcades, ARCADES_LEN);
						case 2:
							if(arcadesDosOMasJugadores(eSalones, SALONES_LEN, eArcades, ARCADES_LEN)==-1)
							{
								printf("No hay Arcade para mas de 2 jugadores");
							}
							break;
						case 3:
							if(utn_pedirIntPositivoAUsuario(&auxiliarAltaArca, 3, "Ingrese el Id Salon Para Ver su Informacion", "Error")==0)
							{
								listarInformacionSalonEspecifico(eSalones, SALONES_LEN, auxiliarAltaArca, eArcades, ARCADES_LEN);
							}
							else
							{
								printf("Id no existe\n");
							}
							break;
						case 4:
							if(gen_verificarQueTieneDatosLista(eSalones, SALONES_LEN)==0)
							{
								if(utn_pedirIntPositivoAUsuario(&auxiliarAltaArca, 3, "Ingrese ID Salon para ver ARcades", "Error")==0)
								{
								listarArcadesDeUnSalon(eSalones, SALONES_LEN, auxiliarAltaArca, eArcades, ARCADES_LEN);
								}
							}

							break;
						case 5:
							printf("caso 5");
							imprimirSalonMasArcades(eArcades, ARCADES_LEN, eSalones, SALONES_LEN);
							break;
						case 6:
							if(gen_verificarQueTieneDatosLista(eSalones, SALONES_LEN)==0)
							{
								printSalon(eSalones, SALONES_LEN, 1);
								if(utn_pedirIntPositivoAUsuario(&auxiliarAltaArca, 3, "Ingrese ID para calcular Facturacion Maxima", "Error")==0 && utn_pedirFloatPositivoAUsuario(&precioFicha, 3, "Ingrese Precio Ficha", "Error")==0)
								{
									if(findSalonById(eSalones, SALONES_LEN, auxiliarAltaArca, &auxIndex)==0)
									{
										montoMaximoRecaudacion(eArcades, ARCADES_LEN, eSalones, SALONES_LEN, auxIndex, precioFicha);
									}
									else
									{
										printf("No existe salon con este ID\n");
									}
								}
							}else
							{
								printf("No hay Salones Ingresados\n");
							}
							break;
						case 7:
							if (utn_pedirNombreYApellidoAUsuario(juego, NOMBREGAME_LEN, 3, "Ingrese Nombre Juego (DISTINGUE MAYUSCULA Y MINUSCULA)", "Error")==0)
							{
								cantidad=arcade_buscarJuegoEnListayContarArcades(eArcades, ARCADES_LEN, juego);
								if (cantidad>0)
								{
									printf("El juego esta en %d Arcades", cantidad);
								}
								else
								{
									printf("el juego no esta en la lista");
								}
							}

							break;
					}
				}
				break;
			case 0:
				break;


		}


	}while(menu!=0);





	return EXIT_SUCCESS;
}
