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


int main(void) {
	setbuf(stdout,NULL);
	int option;
	char letra[2];
	int flagTxt=-1;
	//int id;
	//char palabra[3];
	int errorRetorno;

	LinkedList *ListaArcades=ll_newLinkedList();



	printf("BIENVENIDOS AL 2PARCIAL DE GUSTAVO VARGAS");
	    do{
	        printf(
	        		"\n1. Cargar los datos de los Arcades desde el archivo data.csv (modo texto)\n"
	        		"2. Incorporar Arcade\n"
	        		"3. Modificar Arcade\n"
	        		"4. Eliminar Arcade\n"
	        		"5. Imprimir Arcade\n"
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
					}
					else
					{
						printf("Debes cargar primero Tu Archivo o Crear uno Nuevo");
					}
					break;
				case 3:
					if(ll_isEmpty(ListaArcades)==0)
					{

					}
					else
					{
						printf("No tienes Arcades");
					}
					break;
				case 4:
					if(ll_isEmpty(ListaArcades)==0)
					{
						controller_ListArcade(ListaArcades);
						controller_removeArcade(ListaArcades);
					}
					else
					{
						printf("No tienes Arcades");
					}
					break;
				case 5:
					break;
				case 6:
					break;
				case 7:
					break;
				case 8:
					break;
				default:
					break;
			}








	    }while(option!=9);

	return 0;
}
