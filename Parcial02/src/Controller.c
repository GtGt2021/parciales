#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Arcades.h"
#include "utn_validador.h"
#include "parser.h"
#include "Validator.h"


/** \brief Carga los datos de los empleados desde el archivo acades.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayArcades)
{
	int retorno=-1;
	FILE *fp;

	if(path!=NULL && pArrayArcades!=NULL)
	{
		fp = fopen(path, "r");
		if(fp!=NULL)
		{
			if (parser_arcadesFromText(fp, pArrayArcades)==0)
				{
					retorno=0;
				}
			fclose(fp);
		}
		else
		{
			retorno=-2;
			printf("Archivo no Existe\n");
		}

	}
	return retorno;
}

/** \brief Alta de Arcade
 * \param pArrayList LinkedList*
 * \return int -1 lista LInken List NULL  0 si se creo con Exito -2 si fallo el ingreso de datos
 *
 */
int controller_addArcade(LinkedList* pArrayArcades)
{
	int retorno=-1;
	int id;
	char nacionalidad[NACIONALIDAD_LEN];
	int sonido;
	int cantidadJugadores;
	int cantidadFichas;
	char nombreSalon[NOMBRESALON_LEN];
	char nombreJuego[NOMBREJUEGO_LEN];
	Arcade* newArcade;

	if (pArrayArcades!=NULL)
	{

		newArcade=arcade_new();
		if(newArcade!=NULL)
		{

			if(utn_pedirNombreYApellidoAUsuario(nacionalidad, NACIONALIDAD_LEN, 3, "Ingrese Nacionalidad de Arcade", "Error, Caracteres No Admitidos")==0 &&
					utn_pedirIntAUsuarioConLimites(&sonido, 0, 1, 3, "Ingrese:\n0.-MONO\n1.-STEREO", "Error, Caracteres No Admitidos")==0 &&
					utn_pedirIntPositivoAUsuario(&cantidadFichas, 3, "Ingrese Cantidad Fichas del Arcade", "Error")==0 &&
					utn_pedirLetrasyNumerosConEspacioAUsuario(nombreSalon, NOMBRESALON_LEN, 3, "Ingrese Nombre Salon al que Pertenece", "Error, Caracteres No Admitidos")==0 &&
					utn_pedirNombreYApellidoAUsuario(nombreJuego, NOMBREJUEGO_LEN, 3, "Ingrese el nombre de Juego", "Error, Caracteres No Admitidos")==0 &&
					utn_pedirIntPositivoAUsuario(&cantidadJugadores, 3, "Cantidad de Jugadores", "Error, Caracteres No Admitidos")==0)
			{
				id=newId(pArrayArcades);
				arcade_setId(newArcade, id);
				arcade_setCantidadFichas(newArcade, cantidadFichas);
				arcade_setSonido(newArcade, sonido);
				arcade_setCantidadJugadores(newArcade, cantidadJugadores);
				arcade_setNacionalidad(newArcade, nacionalidad);
				arcade_setNombreSalon(newArcade, nombreSalon);
				arcade_setNombreJuego(newArcade, nombreJuego);
				ll_add(pArrayArcades, newArcade);
				retorno=0;
				printf("cargado con exito");
			}
			else
			{
				retorno=-2;
				free(newArcade);
			}

		}


	}


	return retorno;
}

int controller_removeArcade(LinkedList* pArrayArcade)
{
	int retorno=-1;
	int idFree;
	char letra[2];
	Arcade *pArcade=NULL;
	if(pArrayArcade!=NULL)
	{
		if(utn_pedirIntPositivoAUsuario(&idFree, 3, "Ingrese Id A Eliminar", "Error")==0)
		{
			pArcade=arcade_findById(pArrayArcade, idFree);
			if (pArcade!=NULL)
			{
				if (utn_pedirLetrasAUsuario(letra, 2, 0, "Ingrese S para Confirmar, Cualquier otra Tecla para volver al Inicio", "Volviendo al Inicio")==0)
				{
					if((letra[0]=='s' || letra[0]=='S') && ll_pop(pArrayArcade, ll_indexOf(pArrayArcade, pArcade))==pArcade)
					{
						printf("ELIMINASTE:\n");
						ImprimirLista(pArcade);
						free(pArcade);
						retorno=0;
					}
				}
			}
			else
			{
				printf("id No Existe\n");
				//retorno=-1;
			}
		}
	}
	return retorno;
}


int controller_ListArcade(LinkedList* pArrayArcade)
{
	int retorno=-1;
	if(pArrayArcade!=NULL)
	{
		retorno=ll_map(pArrayArcade, ImprimirLista);
		//retorno=0;
	}
	return retorno;
}

int controller_listJuegos(LinkedList* original)
{
	int retorno=-1;
	LinkedList* NuevaCopia=ll_newLinkedList(); // creamos nueva lista
	if(original!=NULL && NuevaCopia!=NULL) // verificamos lista no sea null y el puntero a la nueva lista tampoco sea null
	{
		NuevaCopia=ll_clone(original); // clonamos la lista a NuevaCopia
		if(NuevaCopia!=NULL) // SE CREO CORRECTAMENTE?
		{
			retorno=arcade_mostrarJuegos(NuevaCopia, printGame);

		}
		else
		{
			printf("sin Memoria Para Realizar la Operacion");
		}
	}
	return retorno;
}

int controller_editArcade(LinkedList* List)
{
	int retorno=-1;
	char nombre[NOMBREJUEGO_LEN];
	int cantidad;
	int menu;
	int idEdit;
	//int indexAux;
	Arcade *pAux;
	if(List!=NULL)
	{
		if(utn_pedirIntPositivoAUsuario(&idEdit, 3, "Ingrese Id A Editar", "Error")==0)
		{
			pAux=arcade_findById(List, idEdit);
    		if (pAux!=0)
    		{

    			if (utn_pedirIntAUsuarioConLimites(&menu, 1, 2, 3, "Editar:\n1.-Nombre del Juego\n2.-Cantidad Juegadores", "Error de Seleccion")==0)
				{
					switch (menu)
					{
					case 1:
						if(controller_listJuegos(List)==0)
						{
							if(utn_pedirNombreYApellidoAUsuario(nombre, NOMBREJUEGO_LEN, 3, "Ingrese el Nombre del Juego", "Error")==0)
							{
								arcade_setNombreJuego(pAux, nombre);
								retorno=0;
							}
							else
							{
								printf("Error al ingresar Nombre");
							}
						}
						break;
					case 2:
						if(utn_pedirIntPositivoAUsuario(&cantidad, 3, "Ingrese Cantidad Jugadores", "error")==0)
						{
							arcade_setCantidadJugadores(pAux, cantidad);
							retorno=0;
						}
						else
						{
							printf("Error al ingresar Horas");
						}
						break;
					}

  				}
    		}
    		else
    		{
    			printf("id NO existe\n");
    		}
		}
		else
		{
			printf("Ingreso Id Invalido Varias Veces\n");
		}
	}
    return retorno;
}


int controller_saveAsText(char* path , LinkedList* pArrayArcade)
{
	int retorno=-1;
	FILE *fp;
	if(path!=NULL && pArrayArcade!=NULL)
	{
		fp=fopen(path, "w");
		if(fp!=NULL)
		{
			parser_saveAsText(fp, pArrayArcade);
			retorno=0;
		}
		else
		{
			printf("No se Pudo Crear el Archivo Para Guardar");
		}
		fclose(fp);
	}

	return retorno;
}


int controller_sortArcadeNewList(LinkedList* original)
{
	int retorno=-1;
	LinkedList* NuevaCopia=ll_newLinkedList(); // creamos nueva lista
	if(original!=NULL && NuevaCopia!=NULL) // verificamos lista no sea null y el puntero a la nueva lista tampoco sea null
	{
		NuevaCopia=ll_clone(original); // clonamos la lista a NuevaCopia
		if(NuevaCopia!=NULL) // SE CREO CORRECTAMENTE?
		{
			retorno = arcade_sortArcade(NuevaCopia);
		}
		else
		{
			printf("sin Memoria Para Realizar la Operacion");
		}
	}
	return retorno;
}
/*
int prueba_punteroFuncion(LinkedList* original, int(*pFun)(LinkedList*))
{
	int retorno=-1;
	LinkedList* NuevaCopia=ll_newLinkedList(); // creamos nueva lista
	if(original!=NULL && NuevaCopia!=NULL) // verificamos lista no sea null y el puntero a la nueva lista tampoco sea null
	{
		NuevaCopia=ll_clone(original); // clonamos la lista a NuevaCopia
		if(NuevaCopia!=NULL) // SE CREO CORRECTAMENTE?
		{
			retorno=pfun(NuevaCopia);
		}
		else
		{
			printf("sin Memoria Para Realizar la Operacion");
		}
	}
	arcade_deleteList(NuevaCopia);
	return retorno;
}
*/

int controller_savelistJuegos(LinkedList* original)
{
	int retorno=-1;
	LinkedList* NuevaCopia=ll_newLinkedList(); // creamos nueva lista
	if(original!=NULL && NuevaCopia!=NULL) // verificamos lista no sea null y el puntero a la nueva lista tampoco sea null
	{
		NuevaCopia=ll_clone(original); // clonamos la lista a NuevaCopia
		if(NuevaCopia!=NULL) // SE CREO CORRECTAMENTE?
		{
			retorno=arcade_pruebaJuegos(NuevaCopia);
		}
		else
		{
			printf("sin Memoria Para Realizar la Operacion");
		}
	}
	return retorno;
}


LinkedList* controller_newListMulti(LinkedList* original)
{
	LinkedList* NuevaCopia=ll_newLinkedList(); // creamos nueva lista
	if(original!=NULL && NuevaCopia!=NULL) // verificamos lista no sea null y el puntero a la nueva lista tampoco sea null
	{
		NuevaCopia=ll_clone(original); // clonamos la lista a NuevaCopia
		if(NuevaCopia!=NULL) // SE CREO CORRECTAMENTE?
		{
			//printf("a guardar");
			if(ll_filter(NuevaCopia, arcade_multijugador)==0)
			{
				printf("Filtrado Completo\n");
			}

		}
		else
		{
			printf("sin Memoria Para Realizar la Operacion");
		}
	}
	return NuevaCopia;
}

int controller_actualizacion(LinkedList* lista)
{
	int retorno=-1;
	if(lista!=NULL)
	{
		ll_map(lista, actualizarFichasArcades);
		retorno=0;
	}
	return retorno;
}
