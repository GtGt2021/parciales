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
#define SALONES_LEN 5
#define ARCADES_LEN 10
#define JUEGOS_LEN 200
#define CON_TIPO 1
#define SIN_TIPO 2
#define MONO 2
#define STEREO 1
#define SHOPPING 1
#define LOCAL 2
#define NOMBREGAME_LEN 63



int main(void) {
	setbuf(stdout,NULL);
	eSalones* pArraySalones[SALONES_LEN];
	eSalones* pSalonAux;
	eArcades* pArrayArcardes[ARCADES_LEN];
	eArcades* pArcadeAux;
	salonInitArray(pArraySalones, SALONES_LEN);
	arcade_initArray(pArrayArcardes, ARCADES_LEN);
	eJuegos* pArrayjuegos[JUEGOS_LEN];
	eJuegos* pJuegosAux;
	int menu;
	int auxMenu;
	char juego[NOMBREGAME_LEN];
	int cantidad;
	int auxIndex;
	int auxiliarBaja;
	int auxiliarAltaArca;
	char respuesta[2];
	float promedioSalonArca;
	float precioFicha;
	int auxId;

	/*				Salon_altaForzada(&eSalones[15], "BUENAVENTURA", "GUATIRE", LOCAL);
					Salon_altaForzada(&eSalones[90], "SAMBIL", "CARACAS", SHOPPING);
					Salon_altaForzada(&eSalones[91], "BUENAVENTURA", "GUATIRE", SHOPPING);
					Salon_altaForzada(&eSalones[92], "SAMBIL", "CARACAS", LOCAL);
					Salon_altaForzada(&eSalones[93], "SAMBIL", "GUATIRE", SHOPPING);
					Salon_altaForzada(&eSalones[94], "BUENAVENTURA", "CARACAS", LOCAL);
					Salon_altaForzada(&eSalones[95], "SAMBIL", "CARACAS", LOCAL);
					Salon_altaForzada(&eSalones[96], "BUENAVENTURA", "GUATIRE", SHOPPING);
					Salon_altaForzada(&eSalones[98], "SAMBIL", "GUATIRE", SHOPPING);
					Salon_altaForzada(&eSalones[65], "BUENAVENTURA", "GUATIRE", LOCAL);
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
					arcade_altaForzada(&eArcades[103], "Mortal cash", "China", 		STEREO, 3, 6, 12);
					arcade_altaForzada(&eArcades[104], "fith Combat", "panama",		 MONO, 5, 6, 12);
					arcade_altaForzada(&eArcades[105], "pulpo Combat", "colombia",	 STEREO, 5, 6, 12);
					arcade_altaForzada(&eArcades[106], "Mortal Combat", "panama",	 MONO, 5, 6, 12);
					arcade_altaForzada(&eArcades[107], "mortadela Combat", "colombia", STEREO, 5, 3, 12);
					arcade_altaForzada(&eArcades[108], "Mortal Combat", "China",	 MONO, 6, 2, 12);
					arcade_altaForzada(&eArcades[109], "Mortal Combat", "panama",	 STEREO, 6, 6, 12);
					arcade_altaForzada(&eArcades[110], "Mortal CHAM", "China", 		MONO, 6, 1, 12);
					arcade_altaForzada(&eArcades[111], "Mortal Combat", "colombia", MONO, 4, 6, 12);
					arcade_altaForzada(&eArcades[112], "Mortal cash", "China", 		STEREO, 4, 1, 12);
					arcade_altaForzada(&eArcades[113], "fith Combat", "panama",		 MONO, 3, 6, 12);
					arcade_altaForzada(&eArcades[114], "pulpo Combat", "colombia",	 STEREO, 3, 1, 12);
					arcade_altaForzada(&eArcades[115], "Mortal Combat", "panama",	 MONO, 3, 6, 12);
					arcade_altaForzada(&eArcades[116], "mortadela Combat", "colombia", STEREO, 1, 6, 12);
					arcade_altaForzada(&eArcades[117], "Mortal Combat", "China",	 MONO, 2, 6, 12);
					arcade_altaForzada(&eArcades[118], "Mortal Combat", "panama", 	STEREO, 6, 1, 12);
					arcade_altaForzada(&eArcades[119], "Mortal CHAM", "China", 		MONO, 6, 3, 12);
					arcade_altaForzada(&eArcades[120], "Mortal Combat", "colombia", MONO, 4, 1, 12);
					arcade_altaForzada(&eArcades[121], "Mortal cash", "China", 		STEREO, 6, 6, 12);
					arcade_altaForzada(&eArcades[122], "fith Combat", "panama", 	MONO, 2, 1, 12);
					arcade_altaForzada(&eArcades[123], "pulpo Combat", "colombia",	 STEREO, 4, 8, 12);
					arcade_altaForzada(&eArcades[124], "Mortal Combat", "panama",	 MONO, 5, 3, 12);
					arcade_altaForzada(&eArcades[125], "mortadela Combat", "colombia", STEREO, 8, 2, 12);
					arcade_altaForzada(&eArcades[126], "Mortal Combat", "China", 	MONO, 9, 1, 12);
					arcade_altaForzada(&eArcades[200], "Mortal Combat", "panama", 	STEREO, 2, 6, 12);
					arcade_altaForzada(&eArcades[201], "Mortal CHAM", "China", 		MONO, 6, 6, 12);
					arcade_altaForzada(&eArcades[202], "Mortal Combat", "colombia", MONO, 6, 6, 12);
					arcade_altaForzada(&eArcades[203], "Mortal cash", "China", 		STEREO, 3, 6, 12);
					arcade_altaForzada(&eArcades[204], "fith Combat", "panama",		 MONO, 5, 6, 12);
					arcade_altaForzada(&eArcades[205], "pulpo Combat", "colombia",	 STEREO, 5, 6, 12);
					arcade_altaForzada(&eArcades[206], "Mortal Combat", "panama",	 MONO, 5, 6, 12);
					arcade_altaForzada(&eArcades[207], "mortadela Combat", "colombia", STEREO, 5, 3, 12);
					arcade_altaForzada(&eArcades[208], "Mortal Combat", "China",	 MONO, 6, 2, 12);
					arcade_altaForzada(&eArcades[209], "Mortal Combat", "panama",	 STEREO, 6, 6, 12);
					arcade_altaForzada(&eArcades[210], "Mortal CHAM", "China", 		MONO, 6, 1, 12);
					arcade_altaForzada(&eArcades[211], "Mortal Combat", "colombia", MONO, 4, 6, 12);
					arcade_altaForzada(&eArcades[212], "Mortal cash", "China", 		STEREO, 4, 1, 12);
					arcade_altaForzada(&eArcades[213], "fith Combat", "panama",		 MONO, 3, 6, 12);
					arcade_altaForzada(&eArcades[214], "pulpo Combat", "colombia",	 STEREO, 3, 1, 12);
					arcade_altaForzada(&eArcades[215], "Mortal Combat", "panama",	 MONO, 3, 6, 12);
					arcade_altaForzada(&eArcades[216], "mortadela Combat", "colombia", STEREO, 1, 6, 12);
					arcade_altaForzada(&eArcades[217], "Mortal Combat", "China",	 MONO, 2, 6, 12);
					arcade_altaForzada(&eArcades[218], "Mortal Combat", "panama", 	STEREO, 6, 1, 12);
					arcade_altaForzada(&eArcades[219], "Mortal CHAM", "China", 		MONO, 6, 3, 12);
					arcade_altaForzada(&eArcades[220], "Mortal Combat", "colombia", MONO, 4, 1, 12);
					arcade_altaForzada(&eArcades[221], "Mortal cash", "China", 		STEREO, 6, 6, 12);
					arcade_altaForzada(&eArcades[222], "fith Combat", "panama", 	MONO, 2, 1, 12);
					arcade_altaForzada(&eArcades[223], "pulpo Combat", "colombia",	 STEREO, 4, 8, 12);
					arcade_altaForzada(&eArcades[224], "Mortal Combat", "panama",	 MONO, 5, 3, 12);
					arcade_altaForzada(&eArcades[225], "mortadela Combat", "colombia", STEREO, 8, 2, 12);
					arcade_altaForzada(&eArcades[226], "Mortal Combat", "China", 	MONO, 9, 1, 12);

*/



	do
	{
		utn_pedirIntAUsuarioConLimites(&menu, 0, 9, 3, "\n\nIngrese Numero De la Opcion Deseada:\n1.-Alta Salon\n2.-Eliminar Salon\n3.-Ver Salones Ingresados\n4.-Incorporar Arcade \n5.-Modificar Arcade\n6.-Eliminar Arcade\n7.-Imprimir Arcades\n8.-Imprimir Juegos\n9.-Informes:", "Error");
		switch (menu)
		{
			case 1:

				if(salonBuscarposicionLibre(pArraySalones, SALONES_LEN, &auxIndex)==0)//2
				{

					pSalonAux=salonNuevo();
					if(pSalonAux!=NULL)
					{
						if(salonCargarInfo(pSalonAux)==0)
						{
							pArraySalones[auxIndex]=pSalonAux;
							pSalonAux=NULL;
						}
						else
						{
							printf("Carga de Datos incorrecta");
						}

					}
				}
				else
				{
					printf("no tienes mas Espacio");
				}

				break;
			case 2:
				if(salonTieneDatos(pArraySalones, SALONES_LEN)==0)
				{
					salonImprimirTodos(pArraySalones, SALONES_LEN, SIN_TIPO);
					if (utn_pedirIntPositivoAUsuario(&auxiliarBaja, 3, "Ingrese Id Salon que desea Eliminar", "Error")==0)
					{//pedi ID DE SALON
						if (salonEliminarId(pArraySalones, SALONES_LEN, auxiliarBaja)==0)//buscamos que exista el id a eliminar
						{
							//printf("el array en esa posicion 0 tiene %p el array en esa posicion 1  tiene %p\n", pArrayArcardes[0], pArrayArcardes[1] );
							arcade_bajarArcadeById(pArrayArcardes, ARCADES_LEN, auxiliarBaja);//ENTRO EN ARCADE.C Y PONGO EN 0 LOS QUE TENGAN ESTE ID DE SALON
							printf ("El Id %d, Fue eliminado Correctamente junto con sus arcades\n", auxiliarBaja);
							//printf("el array en esa posicion 0 tiene %p el array en esa posicion 1  tiene %p\n", pArrayArcardes[0], pArrayArcardes[1] );

						}

					}
				}
				else
				{
					printf ("No hay Ningun Salon Cargado\n");
				}
				break;
			case 3:
				if(salonTieneDatos(pArraySalones, SALONES_LEN)==0)
				{
					salonImprimirTodos(pArraySalones, SALONES_LEN, CON_TIPO);
				}
				else
				{
					printf ("No hay Ningun Salon Cargado\n");
				}
				break;
			case 4:
				if(salonTieneDatos(pArraySalones, SALONES_LEN)==0)
				{
					salonImprimirTodos(pArraySalones, SALONES_LEN, CON_TIPO);
					if(utn_pedirIntPositivoAUsuario(&auxiliarAltaArca, 3, "Ingrese el Numero del Id Del Salon al Cual le quiere cargar el Arcade:\n", "Error")==0)
					{
						if(salon_verificarIdExiste(pArraySalones, SALONES_LEN, auxiliarAltaArca)==0)
						{
							if(arcade_buscarPosicionLibre(pArrayArcardes, ARCADES_LEN, &auxIndex)==0)
							{
								pArcadeAux=arcadeNuevo();
								if(pArcadeAux!=NULL)
								{
									if (arcade_cargarArcade(pArcadeAux, auxiliarAltaArca)==0)
									{
										pArrayArcardes[auxIndex]=pArcadeAux;
										pArcadeAux=NULL;
									}
									else
									{
										printf("carga de Datos Incorrecta");
									}

								}
							}
							else
							{
								printf("NO TENEMOS CANCHA PA OTRO ARCADE");
							}

						}
						else
						{
							printf("Id no esta en la lista\n");
						}
					}
				}
				else
				{
					printf("No hay salones para cargar Arcades\n");
				}

				break;
			case 5:
				if(arcade_verificarQueTieneDatosLista(pArrayArcardes, ARCADES_LEN)==0)
				{
					arcade_imprimirListaArcade(pArrayArcardes, ARCADES_LEN);
					if (utn_pedirIntPositivoAUsuario(&auxiliarBaja, 3, "Ingrese Id Arcade que desea Modificar", "Error")==0)
					{
						if(arcade_buscarArcadePorId(pArrayArcardes, ARCADES_LEN, auxiliarBaja, &auxIndex)==0)
						{
							if(arcade_modificarLista(pArrayArcardes[auxIndex])==0)
							{
								printf("Modificacion Exitosa");
							}
							else
							{
								printf("Error al Cargar DAtos");
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
				if(arcade_verificarQueTieneDatosLista(pArrayArcardes, ARCADES_LEN)==0)
				{
					arcade_imprimirListaArcade(pArrayArcardes, ARCADES_LEN);
					//imprimirTodoArcadeySalon(pArraySalones, SALONES_LEN, pArrayArcardes, ARCADES_LEN);
					if(utn_pedirIntPositivoAUsuario(&auxiliarBaja, 3, "Ingrese Id Arcade a dar de Baja\n", "error")==0)
					{
						if(arcade_buscarArcadePorId(pArrayArcardes, ARCADES_LEN, auxiliarBaja, &auxIndex)==0)
						{
							printf("este es el Arcade Que dara de Baja:\n");
							arcade_imprimirArcade(pArrayArcardes[auxIndex]);
							if(utn_pedirLetrasAUsuario(respuesta, 2, 0, "Esta seguro de dar de baja al arcade (s) para confirmar ", "Volviendo Al Menu Principal")==0)
							{
								if(respuesta[0]=='s')
								{
									arcade_bajarArcadeByIdArcade(pArrayArcardes, ARCADES_LEN, auxiliarBaja);
									printf ("El Arcade Id %d, Fue eliminado Correctamente\n", auxiliarBaja);

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
				if (arcade_verificarQueTieneDatosLista(pArrayArcardes, ARCADES_LEN)==0)
				{
					arcade_imprimirListaArcade(pArrayArcardes, ARCADES_LEN);
				}
				else
				{
					printf("NO ICE ARCADES");
				}
				break;
			case 8:
				if (arcade_verificarQueTieneDatosLista(pArrayArcardes, ARCADES_LEN)==0)
					{
					printf("Lista de Juegos:\n");
					arcade_generarListaJuegos(pArrayArcardes, ARCADES_LEN, pArrayjuegos, ARCADES_LEN);
					arcade_imprimirListaJuegos(pArrayjuegos, ARCADES_LEN);
					}
				break;
			case 9:
				if(utn_pedirIntAUsuarioConLimites(&auxMenu, 1, 9, 3, "ingrese 1-2-3-4-5-6-7-8-9", "ERROR")==0)//utn_PedirCualquierCaracterAUsuario(respuesta, 2, 3, "ingrese A-B-C-D-E-F-G", "ERROR")==0)
				{
					switch (auxMenu)
					{
						case 1:
							if(salonTieneDatos(pArraySalones, SALONES_LEN)==0)
							{
								if(arcade_verificarQueTieneDatosLista(pArrayArcardes, ARCADES_LEN)==0)
								{
									if(ContadorArcadesEnSalones(pArraySalones, SALONES_LEN, pArrayArcardes, ARCADES_LEN)!=0)
									{
										printf("No hay salones con mas de 4 arcades");
									}
								}
								else
								{
									printf("No hay arcades Cargados en Ningun Salon");
								}
							}
							else
							{
								printf("no hay Salones\n");
							}
							break;
						case 2:
							if(arcade_verificarQueTieneDatosLista(pArrayArcardes, ARCADES_LEN)==0)
							{
								if(arcadesDosOMasJugadores(pArraySalones, SALONES_LEN, pArrayArcardes, ARCADES_LEN)!=0)
								{
									printf("No hay Arcade para mas de 2 jugadores");
								}

							}
							else
							{
								printf("no tenemos Arcades");
							}
							break;
						case 3:
							if(salonImprimirTodos(pArraySalones, SALONES_LEN, 1)==0)
							{
								if(utn_pedirIntPositivoAUsuario(&auxiliarAltaArca, 3, "Ingrese el Id Salon Para Ver su Informacion", "Error")==0)
								{
									listarInformacionSalonEspecifico(pArraySalones, SALONES_LEN, auxiliarAltaArca, pArrayArcardes, ARCADES_LEN);
								}
								else
								{
									printf("Id no existe\n");
								}
							}
							else
							{
								printf("No tenemos Salones Cargados");
							}
							break;
						case 4:
							if(salonTieneDatos(pArraySalones, SALONES_LEN)==0)
							{
								if(arcade_verificarQueTieneDatosLista(pArrayArcardes, ARCADES_LEN)==0)
								{
									if(utn_pedirIntPositivoAUsuario(&auxiliarAltaArca, 3, "Ingrese ID Salon para ver ARcades", "Error")==0)
									{
										listarArcadesDeUnSalon(pArraySalones, SALONES_LEN, auxiliarAltaArca, pArrayArcardes, ARCADES_LEN);
									}
								}
								else
								{
									printf("No hay arcades en este Salon");
								}
							}
							else
							{
								printf("no hay Salones\n");
							}

							break;
						case 5:
							printf("caso 5");
							imprimirSalonMasArcades(pArrayArcardes, ARCADES_LEN, pArraySalones, SALONES_LEN);
							break;
						case 6:
							if(salonImprimirTodos(pArraySalones, SALONES_LEN, 2)==0)
							{
								if(utn_pedirIntPositivoAUsuario(&auxiliarAltaArca, 3, "Ingrese ID del Salon para calcular Facturacion Maxima", "Error ")==0)
								{
									if(buscarSalonPorId(pArraySalones, SALONES_LEN, auxiliarAltaArca, &auxIndex)==0)
									{
										if(utn_pedirFloatPositivoAUsuario(&precioFicha, 3, "Ingrese Precio Ficha\n", "Error")==0)
										{
											montoMaximoRecaudacion(pArrayArcardes, ARCADES_LEN, pArraySalones, SALONES_LEN, auxIndex, precioFicha);
										}
										else
										{
											printf ("Error volvemos al menu inicial\n");
										}

									}
									else
									{
										printf("No existe salon con este ID\n");
									}
								}
								else
								{
									printf("No hay Salones Ingresados\n");
								}
							}
							else
							{
								printf("No Hay Salones, Chao...");
							}

							break;
						case 7:
							if (arcade_verificarQueTieneDatosLista(pArrayArcardes, ARCADES_LEN)==0)
							{
								if (utn_pedirNombreYApellidoAUsuario(juego, NOMBREGAME_LEN, 3, "Ingrese Nombre Juego (DISTINGUE MAYUSCULA Y MINUSCULA)", "Error, ")==0)
									{
										cantidad=arcade_buscarJuegoEnListayContarArcades(pArrayArcardes, ARCADES_LEN, juego);
										if (cantidad>0)
										{
											printf("El juego esta en %d Arcades\n", cantidad);
										}
										else
										{
											printf("el juego no esta en la lista\n");
										}
									}
							}
							else
							{
								printf("No tienes Juegos Cargados porque no tienes ningun arcade");
							}
							break;
						case 8:
							if (salonTieneDatos(pArraySalones, SALONES_LEN)==0)
							{
								if (ContadorArcadesMas8(pArraySalones, SALONES_LEN, pArrayArcardes, ARCADES_LEN)<0)
								{
									printf("No Tienes Salones Con Mas de 8 Arcades y 2 o mas jugadores");
								}
							}

							break;
						case 9:

							if (promedioArcadesSalon(pArraySalones, SALONES_LEN, pArrayArcardes, ARCADES_LEN, &promedioSalonArca)==0)
							{
								printf("El promedio de Arcades por Salon es de %.2f", promedioSalonArca);
							}
							else
							{
								printf("No tenemos Arcades");
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
