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

/** \brief Alta de Arcade Ingresados Manualmente
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
				free(newArcade); // libero el Arcade Creado que no se uso
			}

		}


	}


	return retorno;
}


/** \brief Elimina un Arcade
 * \param pArrayList LinkedList*
 * \return int -1 lista LInken List NULL  0 si se eliminno con Exito -2 si fallo el ingreso de datos
 *
 */
int controller_removeArcade(LinkedList* pArrayArcade)
{
	int retorno=-1;
	int idFree;
	char letra[2];
	Arcade *pArcade=NULL; // creo puntero Arcade
	if(pArrayArcade!=NULL)
	{
		if(utn_pedirIntPositivoAUsuario(&idFree, 3, "Ingrese Id A Eliminar", "Error")==0)
		{
			pArcade=arcade_findById(pArrayArcade, idFree); // busco el elemento que contiene ese ID recibo un puntero al elemento
			if (pArcade!=NULL) // si es != NULL es porque lo consiguio
			{
				if (utn_pedirLetrasAUsuario(letra, 2, 0, "Ingrese S para Confirmar, Cualquier otra Tecla para volver al Inicio", "Volviendo al Inicio")==0)
				{ // confirmo que quiere eliminar
					if((letra[0]=='s' || letra[0]=='S') && ll_pop(pArrayArcade, ll_indexOf(pArrayArcade, pArcade))==pArcade) // valido la respuesta y elimino el elemento en el LL valido nuevamebte que sea el elemento que qeuria eliminar
					{
						printf("ELIMINASTE:\n");
						ImprimirLista(pArcade); // imprimo el elemento eliminado
						free(pArcade); // libero la memoria
						retorno=0;
					}
				}
			}
			else
			{
				printf("id No Existe\n"); // si el puntero es NULL es porque el ID NO SE ENCONTRO
				retorno=-2;
			}
		}
	}
	return retorno;
}

/** \brief Imprime la Lista Arcade
 * \param pArrayList LinkedList*
 * \return int -1 lista LInken List NULL  0 si se imprimio con exito
 *
 */
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


/** \brief Imprime la Lista de Juegos envia una copia para mostra solamente los juegos sin repertir
 * \param pArrayList LinkedList*
 * \return int -1 lista LInken List NULL  0 si se imprimio con exito
 *
 */
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

/** \brief Edita el elemento seleccionado de la lista
 * \param List Recibe la Lista Entera
 * \return int -1 lista LInken List NULL  0 si se edito con exito
 *
 */
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
			pAux=arcade_findById(List, idEdit); //busco Id recibo el Puntero al Elemnto
    		if (pAux!=0)
    		{

    			if (utn_pedirIntAUsuarioConLimites(&menu, 1, 2, 3, "Editar:\n1.-Nombre del Juego\n2.-Cantidad Juegadores", "Error de Seleccion")==0)
				{
					switch (menu) //ingreso al menu 2 opciones
					{
					case 1:
						if(controller_listJuegos(List)==0) //listo los juegos
						{
							if(utn_pedirNombreYApellidoAUsuario(nombre, NOMBREJUEGO_LEN, 3, "Ingrese el Nombre del Juego", "Error")==0)
							{
								arcade_setNombreJuego(pAux, nombre); //edito el nombre del Juego del Arcade Seleccionado
								retorno=0; //OK
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

/** \brief Guardo en FormatoTexto
 * \param pArrayList LinkedList
 * \param path el nombre del Archvio
 * \return int -1 lista LInken List NULL  0 si se imprimio con exito
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayArcade)
{
	int retorno=-1;
	FILE *fp; // creo puntero al archivo
	if(path!=NULL && pArrayArcade!=NULL)
	{
		fp=fopen(path, "w"); //ABRO el ARCHIVO EN MODO ESCRITURA
		if(fp!=NULL)// SE PUDO ABRIR BIEN
		{
			parser_saveAsText(fp, pArrayArcade); // paso a la funcion parser el puntero al archivo y la lista
			retorno=0;
		}
		else
		{
			printf("No se Pudo Crear el Archivo Para Guardar");
		}
		fclose(fp); // CLOSE al ARCHIVO
	}

	return retorno;
}

/** \brief ORDENA la Lista Arcade
 * \param LISTA LinkedList*
 * \return int -1 lista LInken List NULL o la clonacion de la lista es NULL 0 si se ordeno con exito
 *
 */
int controller_sortArcadeNewList(LinkedList* original)
{
	int retorno=-1;
	LinkedList* NuevaCopia=ll_newLinkedList(); // creamos nueva lista
	if(original!=NULL && NuevaCopia!=NULL) // verificamos lista no sea null y el puntero a la nueva lista tampoco sea null
	{
		NuevaCopia=ll_clone(original); // clonamos la lista a NuevaCopia
		if(NuevaCopia!=NULL) // SE CREO CORRECTAMENTE?
		{
			retorno = arcade_sortArcade(NuevaCopia); // ordeno en el menu de la prox funcion
		}
		else
		{
			printf("sin Memoria Para Realizar la Operacion");
		}
	}
	return retorno;
}

/** \brief guarda la Lista Arcade
 * \param pArrayList LinkedList*
 * \return int -1 lista LInken List NULL  0 si se imprimio con exito
 *
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


/** \brief crea una nueva lista clonada de la original envia a la funcion filter a buscar multijugador
 * \param LISTA LinkedList*
 * \return NULL si la lista original o la copia es NULL o el puntero a la nueva Linked si todo es OK
 *
 */
LinkedList* controller_newListMulti(LinkedList* original)
{
	LinkedList* NuevaCopia=ll_newLinkedList(); // creamos nueva lista
	if(original!=NULL && NuevaCopia!=NULL) // verificamos lista no sea null y el puntero a la nueva lista tampoco sea null
	{
		NuevaCopia=ll_clone(original); // clonamos la lista a NuevaCopia
		if(NuevaCopia!=NULL) // SE CREO CORRECTAMENTE?
		{
			//printf("a guardar");
			if(ll_filter(NuevaCopia, arcade_multijugador)==0) // llamamos a la funcion Filter del LL para buscar los multijugadores
			{
				printf("Filtrado Completo\n");
			}

		}
		else
		{
			printf("sin Memoria Para Realizar la Operacion");
		}
	}
	return NuevaCopia; // retorno la nueva lista
}


/**\brief Usando la funcion Map Actualiza las fichas
 * \param LISTA LinkedList*
 * \return int -1 lista LInken List NULL o  0 si se map fue exitoso;
 *
 */
int controller_actualizacion(LinkedList* lista)
{
	int retorno=-1;
	if(lista!=NULL)
	{
		ll_map(lista, actualizarFichasArcades); // mapeo
		retorno=0;
	}
	return retorno;
}
