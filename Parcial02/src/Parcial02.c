/*
 ============================================================================
 Name        : Parcial02.c
 Author      : Gt
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn_validador.h"
#include "Controller.h"
#include "Arcades.h"
#include "parser.h"


int main(void) {
	setbuf(stdout,NULL);
	int option;
	LinkedList *CopiaClon=NULL;
	char letra[2];
	int flagTxt=-1;
	int flagActualizacion=-1;
	//int id;
	//char palabra[3];
	int errorRetorno;

	LinkedList *ListaArcades=ll_newLinkedList();



	printf("BIENVENIDOS AL 2PARCIAL DE GUSTAVO VARGAS");
	    do{
	    	option=0;
	        printf(
	        		"\n1. Cargar los datos de los Arcades desde el archivo Arcades.csv (modo texto)\n"
	        		"2. Incorporar Arcade\n"
	        		"3. Modificar Arcade\n"
	        		"4. Eliminar Arcade\n"
	        		"5. Ordenar Arcades Por Atributos\n"
	        		"6. Genera Archivo Juegos\n"
	    			"7. Generar Archivo Arcade multijugador\n"
	    			"8. Actualizar Cantidad de Fichas\n"
	    			"9. Salir\n");
	        utn_pedirIntAUsuarioConLimites(&option, 1, 9, 2, "Ingrese Opcion Deseada", "Error");
	        switch (option) {
				case 1:
					if(flagTxt==-1)
					{
						errorRetorno=controller_loadFromText("arcades.csv", ListaArcades);
						if(errorRetorno==0)
						{
							printf("Lista leida\n");
						}else
						{
							if(errorRetorno==-2)
							{
								if(utn_PedirCualquierCaracterAUsuario(letra, 2, 0, "Presione S si desea Crear el Archivo o cualquier otra tecla para continuar", "Volviendo Al Inicio")==0 )
								{
									if(letra[0]=='s' || letra[0]=='S')
									{
										FILE* f2=fopen("arcades.csv", "w");
										if(f2!=NULL)
										{
											fclose(f2);
											printf("Archivo Texto Creado\n");
										}
									}

								}
							}
						}
						flagTxt=0;
					}
					else
					{
						printf("Ya cargastes un Archivo Previamente");
					}
					break;
				case 2:
					if(flagTxt==0)
					{
						controller_addArcade(ListaArcades);
						controller_saveAsText("arcades.csv", ListaArcades);
						flagActualizacion=-1;
					}
					else
					{
						printf("Debes cargar primero Tu Archivo o Crear uno Nuevo");
					}
					break;
				case 3:
					if(ll_len(ListaArcades)>0)
					{
						if (controller_ListArcade(ListaArcades)==0)
						{
							if(controller_editArcade(ListaArcades)==0)
							{
								if(controller_saveAsText("arcades.csv", ListaArcades)==0)
								{
									printf("editado Con Exito\n");
									flagActualizacion=-1;
								}
								else
								{
									printf("error al Guardar Informacion Editada\n");
								}
							}
							else
							{
								printf("error al Editar Arcade\n");
							}
						}
						else
						{
							printf("error al cargar la lista\n");
						}
					}
					else
					{
						printf("No tienes Arcades");
					}
					break;
				case 4:
					if(ll_len(ListaArcades)>0)
					{
						controller_ListArcade(ListaArcades);
						controller_removeArcade(ListaArcades);
						controller_saveAsText("arcades.csv", ListaArcades);
						flagActualizacion=-1;
					}
					else
					{
						printf("No tienes Arcades Cargados");
					}
					break;
				case 5:
					if(ll_isEmpty(ListaArcades)==0)
					{
						controller_sortArcadeNewList(ListaArcades);
					}
					else
					{
						printf("No tienes Arcades Cargados");
					}
					break;
				case 6:
					if(ll_len(ListaArcades)>0)
					{
						if(controller_savelistJuegos(ListaArcades)==0)
						{
							printf("Lista Generada con Exito");
						}
					}
					else
					{
						printf("No tienes Juegos");
					}
					break;
				case 7:
					if(ll_len(ListaArcades)>0) // verifico que hay elementos
					{
						CopiaClon=controller_newListMulti(ListaArcades); //hago un filtrado de los juegos multijugador
						if(CopiaClon!=NULL) // si la copia viene bien trae los juegos multi
						{
							if(controller_saveAsText("multijugador", CopiaClon)==0) // genero el archvio
							{
								printf("Lista Generada con Exito"); // se genero OK!!
								arcade_deleteList(CopiaClon); // borro la memoria Usada para la COpia Clon
							}

						}
						else
						{
							printf("No fue Posible Crear El Archivo");
						}
	        		}
					else
					{
						printf("No tienes arcades");
					}
					break;
				case 8:
					if(ll_len(ListaArcades)>0)// verifico que hay elementos
					{
						if(controller_actualizacion(ListaArcades)==0) // hago un mapeo para actualizar la cantidad defichas de las arcades
						{
							flagActualizacion=0; // Error de que tengo que actualizar o pierdo los cambios
						}
					}
					break;
				case 9:
					if(flagActualizacion==0) // salida pregunta si quiero salir sin GUARDAR ya que ACTUALIZE LAS FICHAS Y NO GUARDE
					{
						if(utn_PedirCualquierCaracterAUsuario(letra, 2, 0, "Tienes Cambios sin Guardar, Presiona S para Guardar o Cualquier Otra Tecla para Salir sin Guardar", "Saliendo")==0 )
						{
							if(letra[0]=='s' || letra[0]=='S')
							{
							controller_saveAsText("arcades.csv", ListaArcades); // mando a guardar
							printf("Archivo Actualizado\n");
							}

						}
					}
					printf("Termino...");
					break;
			}
	    }while(option!=9);

	return 0;
}
