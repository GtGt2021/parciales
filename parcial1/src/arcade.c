/*
 * arcade.c
 *
 *  Created on: 16 oct. 2021
 *      Author: gt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_validador.h"
#include "arcade.h"
#define VACIO 0
#define OCUPADO 1
#define NOMBRE_LEN 63
#define NACIONALIDAD_LEN 24
#define JUEGOS 1
#define LISTA_TODO 2
#define STEREO 1
#define MONO 2
static int getId(void);
static int arcade_addSalon(eArcades arcades[], char nombre[], char nacionalidad[], int id,  int tipoSonido, int idSalon, int cantidadJugadores, int cantidadFichas);
static int arcade_getDataArcade(char nombre[], int lenNombre, char nacionalidad[], int lenNAcionalidad, int *fichas, int *sonido, int *jugadores);

/**brief nos genera un id nuevo consecutivo cuando se invoca ( en este caso comienza a partir del 1000 en adelante)
 * param (no recibe nada)
 * return retorna un entero positivo que se usa como id "SOLO PARA USAR EN ESTA BIBLIOTECA"
 */
static int getId(void)
{
	static int counter=1000;
	return (counter++);
}
int init_arcades(eArcades list[], int len)
{
	int retorno=-1;
	int i;
	if(list!=NULL && len>0)
	{

		for(i=0; i<len; i++)
		{
			list[i].isEmpty_arcade=VACIO; // posicion Libre
		}
		retorno=0;
	}
	return retorno;
}

int init_juegos(eJuegos list[], int len)
{
	int retorno=-1;
	int i;
	if(list!=NULL && len>0)
	{

		for(i=0; i<len; i++)
		{
			list[i].isEmpty_juegos=VACIO; // posicion Libre
		}
		retorno=0;
	}
	return retorno;
}

/**brief funcion sencilla que se dedica a pedir la info necesaria para cargar los campos de los empleados nombre apellido sector salario
 *
 * return retorna 0 si todos los datos se cargaron ok y -1 si hubo algun error
 */
static int arcade_getDataArcade(char nombre[], int lenNombre, char nacionalidad[], int lenNAcionalidad, int *fichas, int *sonido, int *jugadores)
{
	int retorno=-1;
	if (nombre!=NULL && nacionalidad!=NULL && fichas!=NULL && sonido!=NULL && jugadores!=NULL)
	{

		if (utn_pedirLetrasAUsuario(nacionalidad, lenNAcionalidad, 3, "Ingrese Nacionalidad del Arcade:", "Error")==0)
		{
			if(utn_pedirIntAUsuarioConLimites(sonido, 1, 2, 3, "ingrese tipo de Sonido: 1.-STEREO 2.-MONO", "Error")==0)
			{
				if(utn_pedirIntPositivoAUsuario(fichas, 3, "Ingrese Cantidad de Fichas admitidas por el Arcade", "Error")==0)
				{
					if (utn_pedirNombreYApellidoAUsuario(nombre, lenNombre, 3, "Ingrese Nombre del Juego para el Arcade", "Error")==0)
					{
						if (utn_pedirIntPositivoAUsuario(jugadores, 3, "Ingrese Cantidad de Jugadores", "error")==0)
						{

							retorno=0;
						}
					}
				}
			}
		}
	}

	return retorno;
}


/**brief verificamos si hay espacio (isempty LIBRE) donde escribir en la lista de ser asi llamamos a la funcion getData para cargar la info del empleado nuevo
 * si todo esta bien generamos un id y llamamos a la funcion add para escribir la info del empleado una posicion en la lista
 *param array de employe y el tama�o
 *return -3 si hay fallas en el archivo -2 si la memoria o la lista esta llena -1 si ingreso mal los datos en varias ocasiones y si todo sale bien nos devuelve el id generado
 */
int arcade_loadArcade(eArcades arcade[], int len, int idSalon)
{
	int retorno=-3;
	char nombreJuego[NOMBRE_LEN];
	char nacionalidad[NACIONALIDAD_LEN];
	int capacidadFichas;
	int tipoSonido;
	int idArcade;
	int cantidadJugadores;
	int index;
	if (arcade!=NULL && len>0)
	{
		if(arcade_IsFree(arcade, len, &index)==0)
		{

			if(arcade_getDataArcade(nombreJuego, NOMBRE_LEN, nacionalidad, NACIONALIDAD_LEN, &capacidadFichas, &tipoSonido, &cantidadJugadores)==0)
			{
				idArcade=getId();
				arcade_addSalon(&arcade[index], nombreJuego, nacionalidad, idArcade, tipoSonido, idSalon, cantidadJugadores, capacidadFichas);
				retorno=0;
			}
			else
			{
				retorno = -1;
			}
		}
		else
		{
			retorno = -2;
		}
	}

	return retorno;
}

/**brief cargamos la info del empleado a una pocision de la estructura, tomamos una posicion libre en gen_eslibre la guardamos en auxIsFree
 * copiamos los datos en cada uno de los campos sector nombre apellido id salario y colocamos como ocupada la posicion isempty
 *param lista completa tama�o de la lista id, nombre, apellido, salario y sector del empleado a cargar ya previamente validado
 *return 0 si la carga fue ok -1 si por algo hubo un error
 */
static int arcade_addSalon(eArcades arcades[], char nombre[], char nacionalidad[], int id,  int tipoSonido, int idSalon, int cantidadJugadores, int cantidadFichas)
{
	int retorno=-1;
	if (arcades!=NULL && nombre!=NULL && id>0 && nacionalidad!=NULL)
	{

			arcades->tipoSonido_salon=tipoSonido;
			strncpy(arcades->nombreJuego_arcade, nombre, sizeof(arcades->nombreJuego_arcade));
			strncpy(arcades->nacionalidad_arcade, nacionalidad, sizeof(arcades->nacionalidad_arcade));
			arcades->isEmpty_arcade=OCUPADO;
			arcades->id_arcade=id;
			arcades->idSalon_arcade=idSalon;
			arcades->cantidad_jugadores=cantidadJugadores;
			arcades->capacidadFichas_arcade=cantidadFichas;
			retorno=0;

	}
	return retorno;
}
/**brief Verificamos que el array venga bien el tama�o del array mayor q 0 y el puntero a la posicion libre sea != NULL tambien
 * recorremos el array en todo su tama�o y en la primera casilla que encontremos desocupada isempty=0
 * retornamos la posicion libre por puntero a la pocision de memoria de index
 * y hacemos un break para salir del for y no seguir iterando
 *  param recibo el array de la estructura el tama�o del array puntero index
 * return retorna -2 si el array de la estructura  o el puntero posicionLibre viene con errores  o el tama�o del array es menor a 0
 *  -1  si la memoria esta llena y 0 si fue encontrada una casilla libre
 */
int arcade_IsFree(eArcades arcade[], int len, int *index)
{
	// devuelve -2 si la falla es error de array o tama�o del array
	int retorno=-2;
	if (arcade!=NULL && len>0)
	{
		retorno=-1; //-1 si la memoria esta llena
		for (int i=0; i<len; i++)
		{
			if (arcade[i].isEmpty_arcade==VACIO)
			{
				*index=i; //devuelve el indice de la primera posicion libre
				retorno=0;// SI CONSIGUIO indice en memoria para almacenar
				break;
			}
		}

	}
	return retorno;
}

/**
 * brief recorremos el array para ver si tiene informacion cargada es decir si isEmpty= 1 en alguna posicion
 * apenas enccuenta una posicion conrta el for con un break y nos devuelve un mensaje que nos indica que si tiene info el mismo
 * param array estructura y el tama�o del array
 * return -1 si no encontro datos es decir el array esta vacio y retorna 0 si tiene al menos 1 dato cargado
 */
int arcade_verificarQueTieneDatosLista(eArcades arcade[], int len)
{
	int retorno=-1;
	if (arcade!=NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			if (arcade[i].isEmpty_arcade==OCUPADO)
			{
				retorno=0;
				break;
			}
		}

	}
	return retorno;
}

/**brief recibimos una posicion de la estructura con su informacion
 * verificamos isEmpty=1 si esta ocupada IMPRIME SU INFORMACION
 *  param 1  recibo puntero a la pocision X en el arrray estructura
 * return retorna -1 si la posicion de la estructura viene con errores y 0 si fue exitosa la impresion
 */
int arcade_printPosition(eArcades arcade[])
{
	int retorno=-1;
	if (arcade!=NULL)
	{
		if (arcade->isEmpty_arcade==1)
		{
			if (arcade->tipoSonido_salon==STEREO)
			{
				printf("ID: %-3d Nacionalidad: %-10s Sonido: Stereo\t Cap. Fichas: %-3d Nombre Del Juego: %-15s Jugadores Max.:%-5d ID SALON: %d\n", arcade->id_arcade, arcade->nacionalidad_arcade, arcade->capacidadFichas_arcade, arcade->nombreJuego_arcade, arcade->cantidad_jugadores, arcade->idSalon_arcade);
			}
			else
			{
				printf("ID: %-3d Nacionalidad: %-10s Sonido: MONO\t\t Cap. Fichas: %-3d Nombre Del Juego: %-15s Jugadores Max.:%-5d ID SALON: %d\n", arcade->id_arcade, arcade->nacionalidad_arcade, arcade->capacidadFichas_arcade, arcade->nombreJuego_arcade, arcade->cantidad_jugadores, arcade->idSalon_arcade);
			}
			retorno = 0;
		}

	}
	return retorno;
}

/**brief recibimos el array de la Estructura y el tama�o de la misma la recorremos con un For todo el array y
 * llamamos a la funcion que imprime por posicion
 *  param Lista completa del array estructura y el tama�o
 * return retorna -1 si la posicion de la estructura viene con errores y 0 si fue exitosa la impresion
 */
int arcadePrintArcade(eArcades arcade[], int len)
{
	int retorno=-1;
	if (arcade!=NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			if(arcade[i].isEmpty_arcade==OCUPADO)
			{
				arcade_printPosition(&arcade[i]);
			}

		}
		retorno=0;
	}
	return retorno;
}

/**brief recibimos una pocision del array de la estructura
 * validamos que el puntero este bien y pedimos al usuario mediane un menu que desea modificar vamos al suitch y modificamos
 * lo que el usuario quiere
 *  param recibo puntero a la pocision X en el arrray estructura
 * return retorna -1 si la posicion de la estructura viene con errores o se ingreso mal la opcion del menu
 *  y 0 si fue exitosa la MODIFICACION
 */
int arcade_modificarLista(eArcades arcade[])
{
	char nombre [NOMBRE_LEN];
	int cantidad;
	int retorno=-1;
	int menu;
	if (arcade!=NULL && utn_pedirIntAUsuarioConLimites(&menu, 1, 2, 3, "Ingrese Numero Segun lo que desea Modificar:\n1.-Juego \n2.-Cantidad de Jugadores", "Error")==0)
	{
		switch (menu)
			{
			case 1:
				if (utn_pedirIntPositivoAUsuario(&cantidad, 3, "Ingrese Nueva Cantidad de Jugadores", "Error")==0)
				{
					arcade->cantidad_jugadores=cantidad;
					retorno=0;
				}
				break;
			case 2:
				if(utn_pedirNombreYApellidoAUsuario(nombre, NOMBRE_LEN, 3, "Ingrese nuevo Juego", "Error")==0)
				{
					strncpy(arcade->nombreJuego_arcade, nombre, sizeof(arcade->nombreJuego_arcade));
					retorno=0;
				}
				break;

			}
	}

	return retorno;
}



/**brief Verificamos que el array venga bien el tama�o del array mayor q 0 y el id buscado sea un int positivo
 * recibimos el array de la Estructura y el tama�o de la misma la recorremos con un For por todo el array y
 * primero comparamos que la posicion este ocupada isempty=1 y luego preguntamos si el id de esa posicion es igual
 * al id buscado y retornamos por puntero la posicion en la que esta el id
 *  param recibo el array de la estructura el tama�o del array el id qu buscamos retornamos por puntero la posicion del id buscado
 * return retorna -1 si la posicion el array de la estructura viene con errores el id o el tama�o del array son menores a 0
 *  y 0 si fue encontrado el id
 */
int arcade_findArcadeById(eArcades list[], int len, int idBuscado, int *posicionIdBuscado)
{
	int retorno=-1;
	if (list!=NULL && len>0 && idBuscado>0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty_arcade==OCUPADO && list[i].id_arcade==idBuscado)
			{
				*posicionIdBuscado=i;
				retorno=0;
				break;
			}
		}
	}

	return retorno;
}

/**brief recibimos el array de la Estructura y el tama�o de la misma la recorremos con un For todo el array y
 * llamamos a la funcion que imprime por posicion
 *  param Lista completa del array estructura y el tama�o
 * return retorna -1 si la posicion de la estructura viene con errores y 0 si fue exitosa la impresion

int arcadePrintArcade(eArcades arcade[], int len, int caso)
{
	int retorno=-1;
	if (arcade!=NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			if (caso==2)
			{
				arcade_printPosition(&arcade[i]);
			}
			else
			{
				arcade_printPosition(&arcade[i]);
			}

		}
		retorno=0;
	}
	return retorno;
}*/


int arcadePrintArcadeGames(eJuegos juegos[], int len)
{
	int retorno=-1;
	if (juegos!=NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			if(juegos[i].isEmpty_juegos==OCUPADO)
			{
				printf("%s\n", juegos[i].nombre);
				retorno=0;
			}
		}
		retorno=0;
	}
	return retorno;
}

int arcade_bajarArcadeById(eArcades list[], int len, int idBuscado)
{
	int retorno=-1;
	if (list!=NULL && len>0 && idBuscado>0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty_arcade==OCUPADO && list[i].idSalon_arcade==idBuscado)
			{
				list[i].isEmpty_arcade=VACIO;
				retorno=0;
			}
		}
	}

	return retorno;
}

/**brief recibimos una pocision del array tipo Arcades comprobamos que la posicion tenga el isEmpty OCUPADO y lo ponemos VACIO
 * param arcade[pocision]
 * return 0 si esta bien la baja y -1 si no se pudo
 */

int arcade_darBajaArcade(eArcades arcade[])
{
	int retorno=0;
	if(arcade!=NULL)
	{
		if(arcade->isEmpty_arcade==OCUPADO)
		{
			arcade->isEmpty_arcade=VACIO;
			retorno=0;
		}
	}
		return retorno;
}
/**brief verificamos que este OCUPADA la casilla isempty y comparamos el nombre de esa casilla nombrejuego
 *param
 *
 *return 0 si encuentra un juego
 */

int arcade_buscarJuegoEnLista(eJuegos juegos[], int len, char nombreJuego [])
{
	int retorno=-2;
	if (juegos!=NULL && len>0 && nombreJuego!=NULL)
	{
		retorno=-1;
		for (int i=0; i<len; i++)
		{
			if(juegos[i].isEmpty_juegos==OCUPADO)
			{
				if(strncmp(juegos[i].nombre,nombreJuego,NOMBRE_LEN)==0)
				{
					retorno=0;
					break;
				}
			}
		}
	}
		return retorno;
}

int arcade_generarListaJuegos(eArcades arcades[], int lenArcades, eJuegos juegos[],int lenJuegos)
{
	int retorno=-1;
	init_juegos(juegos, lenJuegos);
	int indexJuegos=0;
	if(arcades!=NULL && lenArcades>0 && juegos!=NULL && lenJuegos>0)
	{
		for(int i=0; i<lenArcades; i++)
		{
			if(arcades[i].isEmpty_arcade==OCUPADO)
			{
				if(arcade_buscarJuegoEnLista(juegos, lenJuegos, arcades[i].nombreJuego_arcade)==-1)
				{
					strncpy(juegos[indexJuegos].nombre,arcades[i].nombreJuego_arcade,NOMBRE_LEN);
					juegos[indexJuegos].isEmpty_juegos=OCUPADO;
					indexJuegos++;
					retorno=0;
				}
			}
		}

	}
	return retorno;
}


int arcade_altaForzada(eArcades arcades[], char nombre[], char nacionalidad[],  int tipoSonido, int idSalon, int cantidadJugadores, int cantidadFichas)
{
	int retorno=-1;
	if (arcades!=NULL && nombre!=NULL && nacionalidad!=NULL)
	{


			arcades->tipoSonido_salon=tipoSonido;
			strncpy(arcades->nombreJuego_arcade, nombre, sizeof(arcades->nombreJuego_arcade));
			strncpy(arcades->nacionalidad_arcade, nacionalidad, sizeof(arcades->nacionalidad_arcade));
			arcades->isEmpty_arcade=OCUPADO;
			arcades->id_arcade=getId();;
			arcades->idSalon_arcade=idSalon;
			arcades->cantidad_jugadores=cantidadJugadores;
			arcades->capacidadFichas_arcade=cantidadFichas;
			retorno=0;

	}
	return retorno;
}
