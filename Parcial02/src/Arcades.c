/*
 * Arcades.c
 *
 *  Created on: 20 nov. 2021
 *      Author: gt
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_validador.h"
#include "Arcades.h"
#include "Validator.h"
#include "LinkedList.h"
#define STEREO 1
#define MONO 0


/**brief genero espacio en memoria para un nuevo arcade
 *
 */
Arcade* arcade_new()
{
	Arcade* newArcade;
	newArcade=(Arcade*)calloc(1, sizeof(Arcade));
	return newArcade;
}

/**brief generador de Id recorre el LinkeL y busca el Id Mas Alto para asi asignar el siguiente
 * param lista
 * return id para asignar -1 si la lista es NULL
 */
int newId(LinkedList* ArrayArcades)
{
	int flagid=0;
	int max;
	int id=-1;
	if(ArrayArcades!=NULL)
	{
		Arcade* arcadeAux;

		for(int i=0; i<ll_len(ArrayArcades); i++)
		{
			arcadeAux=ll_get(ArrayArcades, i);
			arcade_getId(arcadeAux, &max);
			if(flagid==0)
			{
				id=max;
				flagid=1;
			}

			if(max>id)
			{
				id=max;
			}
		}
		id++;
	}
	return id;
}

/** brief carga de Arcades desde Archivo
 *  param id char nacionalidad nombreSalon elementos de Arcade
 *  param  sonido fichas juego jugadores
 * 	return Arcade si se creeo bien y NULL si fallo algo
 */
Arcade* arcade_newParametros(char* id,char* nacionalidad,char* nombreSalon,char* sonido,char* cantidadFichas,char* nombreJuego,char* cantidadJugadores)
{

	Arcade* auxArcade;
	if(id!=NULL && nacionalidad!=NULL && nombreSalon!=NULL && sonido!=NULL && cantidadFichas!=NULL && nombreJuego!=NULL && cantidadJugadores!=NULL)
	{
		auxArcade=arcade_new();
		if(auxArcade!=NULL)
		{

			if(!(arcade_getCantidadFichasFile(auxArcade, cantidadFichas)==0 && arcade_getCantidadJugadoresFile(auxArcade, cantidadJugadores)==0 && arcade_getIdFile(auxArcade, id)==0 && arcade_getNacionalidadFile(auxArcade, nacionalidad)==0 && arcade_getNombreJuegoFile(auxArcade, nombreJuego)==0 && arcade_getNombreSalonFile(auxArcade, nombreSalon)==0 && arcade_getSonidoFile(auxArcade, sonido)==0))
			{
				printf("Error Al Leer Datos Id:%s", id);
				free(auxArcade); //errores de lectura entonces no guardo y libero la memoria;
			}
		}
		else
		{
			printf("NO HAY ESPACIO DE MEMORIA");
		}

	}
	return auxArcade;
}


/** brief Muestro la Lista de Arcades geteo todos los campos del arcade recibido y los imprimo ebn pantalla
 * param puntero a un arcade
 *
 */
void ImprimirLista(void* pArcade)
{
	int id;
	char nacionalidad[NACIONALIDAD_LEN];
	int cantidadJugadores;
	int cantidadFichas;
	char nombreSalon[NOMBRESALON_LEN];
	char nombreJuego[NOMBREJUEGO_LEN];
	int sonido;
	arcade_getFichas(pArcade, &cantidadFichas);
	arcade_getId(pArcade, &id);
	arcade_getJugadores(pArcade, &cantidadJugadores);
	arcade_getNombreJuego(pArcade, nombreJuego);
	arcade_getNombreSalon(pArcade, nombreSalon);
	arcade_getSonido(pArcade, &sonido);
	arcade_getNacionalidad(pArcade, nacionalidad);
	if(sonido==STEREO)
	{
		printf("id:%3d nacionalidad:%30s Sonido: STEREO jugadores: %2d Fichas: %2d salon: %8s Juego: %s\n",id,nacionalidad,cantidadJugadores,cantidadFichas,nombreSalon,nombreJuego);
	}
	else
	{
		printf("id:%2d nacionalidad:%20s Sonido: MONO jugadores: %2d Fichas: %2d salon: %8s Juego: %s\n",id,nacionalidad,cantidadJugadores,cantidadFichas,nombreSalon,nombreJuego);
	}

}



Arcade* arcade_findById(LinkedList *pListArcade, int id)
{
Arcade* pArcade=NULL;
int idAux;
if(pListArcade!=NULL)
{
	for(int i=0; i<ll_len(pListArcade); i++)
	{
		pArcade=(Arcade*)ll_get(pListArcade, i);
		if(arcade_getId(pArcade, &idAux)==0)
		{
			if (idAux==id)
			{
				break;
			}
		}
		pArcade=NULL;
	}
}
return pArcade;
}


int arcade_findByIdIndex(LinkedList *pListArcade, int id)
{
	int retorno;
	Arcade* pArcade;
	int idAux;
	if(pListArcade!=NULL)
	{
		for(int i=0; i<ll_len(pListArcade); i++)
		{
			pArcade=ll_get(pListArcade, i);
			if(arcade_getId(pArcade, &idAux)==0)
			{
				if (idAux==id)
				{
					retorno=id;
					break;
				}
			}
			pArcade=NULL;
		}
	}
	return retorno;
}


int arcade_getOrden(int *tipo, int *orden)
{
	int retorno=-1;
	if(tipo!= NULL &&  orden!=NULL && utn_pedirIntAUsuarioConLimites(orden, 1, 5, 3, "Ingresar El tipo de ordenamiento\n 1.-Nombre Juego\n 2.-Nacionalidad\n 3.-Cantidad de Jugadores\n 4.-Cantidad Fichas\n 5.-Nombre Salon\n",
			"Error")==0 && utn_pedirIntAUsuarioConLimites(tipo, 0, 1, 3, "Ingrese\n 1.-Creciente\n 0.-Decreciente", "error")==0)
	{
		retorno=0;
	}
	else
	{
		printf("Opcion no Dispobible\n");
	}
	return retorno;
}

int arcade_compareByJugadores(void* pArcade1, void* pArcade2)
{
	int retorno;
	Arcade* pArcadeUno = (Arcade*)pArcade1;
	Arcade* pArcadeDos = (Arcade*)pArcade2;
	int player1;
	int player2;
	arcade_getJugadores(pArcadeUno, &player1);
	arcade_getJugadores(pArcadeDos, &player2);
	if(player1>player2)
	{
		retorno=1;
	}
	else
	{
		if(player1==player2)
		{
			retorno=0;
		}
		else
		{
			retorno=-1;
		}
	}

	return retorno;
}

int arcade_compareByFichas(void* pArcade1, void* pArcade2)
{
	int retorno;

	Arcade* pArcadeUno = (Arcade*)pArcade1;
	Arcade* pArcadeDos = (Arcade*)pArcade2;
	int player1;
	int player2;
	arcade_getFichas(pArcadeUno, &player1);
	arcade_getFichas(pArcadeDos, &player2);
	if(player1>player2)
	{
		retorno=1;
	}
	else
	{
		if(player1==player2)
		{
			retorno=0;
		}
		else
		{
			retorno=-1;
		}
	}

	return retorno;
}

int arcade_compareByGame(void* pArcade1, void* pArcade2)
{
	int retorno;
	Arcade* pArcadeUno = (Arcade*)pArcade1;
	Arcade* pArcadeDos = (Arcade*)pArcade2;
	char name1[NOMBREJUEGO_LEN];
	char name2[NOMBREJUEGO_LEN];
	arcade_getNombreJuego(pArcadeUno, name1);
	arcade_getNombreJuego(pArcadeDos, name2);
	int tam=strcmp(name1,name2);
	if(tam>0)
	{
		retorno=1;
	}else
	{
		if (tam==0)
		{
			retorno=0;
		}
		else
		{
			retorno=-1;
		}
	}

return retorno;
}

int arcade_compareByNationality(void* pArcade1, void* pArcade2)
{
	int retorno;
	Arcade* pArcadeUno = (Arcade*)pArcade1;
	Arcade* pArcadeDos = (Arcade*)pArcade2;
	char name1[NACIONALIDAD_LEN];
	char name2[NACIONALIDAD_LEN];
	arcade_getNacionalidad(pArcadeUno, name1);
	arcade_getNacionalidad(pArcadeDos, name2);
	int tam=strcmp(name1,name2);
	if(tam>0)
	{
		retorno=1;
	}else
	{
		if (tam==0)
		{
			retorno=0;
		}
		else
		{
			retorno=-1;
		}
	}

return retorno;
}

int arcade_compareBySalon(void* pArcade1, void* pArcade2)
{
	int retorno;
	Arcade* pArcadeUno = (Arcade*)pArcade1;
	Arcade* pArcadeDos = (Arcade*)pArcade2;
	char name1[NACIONALIDAD_LEN];
	char name2[NACIONALIDAD_LEN];
	arcade_getNombreSalon(pArcadeUno, name1);
	arcade_getNombreSalon(pArcadeDos, name2);
	int tam=strcmp(name1,name2);
	if(tam>0)
	{
		retorno=1;
	}else
	{
		if (tam==0)
		{
			retorno=0;
		}
		else
		{
			retorno=-1;
		}
	}

return retorno;
}

void printGame(void* juego)
{
	char nombre[NOMBREJUEGO_LEN];
	arcade_getNombreJuego(juego, nombre);
	printf("%s\n", nombre);
}



/**brief recibimos una lista ordenamos y comparamos uno a uno y solo mostramos los juegos sin repetir
 * param lista completa
 * return -1 si la lista es NULL o no tiene Elementos 0 si todo resulto OK
 */

int arcade_mostrarJuegos(LinkedList* lista, void (*pFunc)(void*))
{
	int retorno=-1;
	Arcade* ArcaAux1; //puntero Arcade para comparar
	Arcade* ArcaAux2; //puntero Arcade para comparar
	int flag=0; // bandera para imprimir el primer elemento
	//char juego[NOMBREJUEGO_LEN]; //variable a almacenar el nombre del juego a imprimir
	if(lista!=NULL && ll_len(lista)>0)
	{
		ll_sort(lista, arcade_compareByGame, 1); // ordenamos forma ascendente por Juego
		for(int i=0; i<ll_len(lista)-1; i++) // recorremos la lista hasta len-1 ya que comparamos de a 2 elemntos
		{
			ArcaAux1=(Arcade*)ll_get(lista, i); // ortenemos el elemento del nodo i
			ArcaAux2=(Arcade*)ll_get(lista, i+1); // ortenemos el elemento del nodo i+1
			if(flag==0) // la primera vez siempre imprimimos el primer juego de la lista
			{
				//arcade_getNombreJuego(ArcaAux1, juego); // saco la info y la muestro
				pFunc(ArcaAux1);//printf("Juego: %s\n", juego);
				flag=1; // cambio estado a la bandera
				retorno=0; // retornamos 0 mostramos al menos 1 juego
			}
			if(arcade_compareByGame(ArcaAux1, ArcaAux2)!=0) // a partir de aqui comenzamos a comparar el elemento posterior con el anterior si son distintos imprimimos el posterior
			{
					//arcade_getNombreJuego(ArcaAux2, juego);
					pFunc(ArcaAux2);//printf("Juego: %s\n", juego);
			}

		}
		retorno=0;
		arcade_deleteList(lista);
		//freeElement(lista);
		//ll_deleteLinkedList(lista);
	}

	return retorno;
}
/**brief Libera de memoria todos los elementos contenidos en los nodos de la LL
 * param Lista a liberar elemendtos
 * return -1 si la lista es NULL 0 si libero memoria bien OK
 */

int freeElement(LinkedList* list)
{
	int retorno=-1;
	Arcade* aux;
	if(list!=NULL)
	{
		for(int i=ll_len(list)-1; i<=0; i--)
		{
			aux=ll_get(list, i);
			free(aux);
		}
		retorno =0;
	}
	return retorno;
}


int arcade_sortArcade(LinkedList* clonada)
{
	int retorno=-1;
	int orden;
	int tipo;
	if(clonada!=NULL && arcade_getOrden(&orden, &tipo)==0)
	{
		printf("Espera Un Momento Mientras Ordena\n");
		switch (tipo)//1.-Nombre Juego\n 2.-Nacionalidad\n 3.-Cantidad de Jugadores\n 4.-Cantidad Fichas\n 5.-Nombre Salon
		{
			case 1://ordenamos nombre juego
				ll_sort(clonada, arcade_compareByGame, orden);
				ll_map(clonada, ImprimirLista);
				break;
			case 2://nacionalidad
				ll_sort(clonada, arcade_compareByNationality, orden);
				ll_map(clonada, ImprimirLista);
				break;
			case 3: //jugadores
				ll_sort(clonada, arcade_compareByJugadores, orden);
				ll_map(clonada, ImprimirLista);
				break;
			case 4: //ficha
				ll_sort(clonada, arcade_compareByFichas, orden);
				ll_map(clonada, ImprimirLista);
				break;
			case 5: // nombre salon
				ll_sort(clonada, arcade_compareBySalon, orden);
				ll_map(clonada, ImprimirLista);
				break;
		}
		freeElement(clonada);
		ll_deleteLinkedList(clonada);
	}
	return retorno;
}

int arcade_pruebaJuegos(LinkedList* lista)
{
	int retorno=-1;
	Arcade* ArcaAux1; //puntero Arcade para comparar
	Arcade* ArcaAux2; //puntero Arcade para comparar
	int flag=0; // bandera para imprimir el primer elemento
	FILE* fp = fopen("juegos.txt", "w");
	char nombreJuego[NOMBREJUEGO_LEN];
	//char juego[NOMBREJUEGO_LEN]; //variable a almacenar el nombre del juego a imprimir

	if(lista!=NULL &&fp!=NULL&& ll_len(lista)>0)
	{

		ll_sort(lista, arcade_compareByGame, 1); // ordenamos forma ascendente por Juego
		for(int i=0; i<ll_len(lista)-1; i++) // recorremos la lista hasta len-1 ya que comparamos de a 2 elemntos
		{

			ArcaAux1=ll_get(lista, i); // ortenemos el elemento del nodo i
			ArcaAux2=ll_get(lista, i+1); // ortenemos el elemento del nodo i+1
			if(flag==0) // la primera vez siempre imprimimos el primer juego de la lista
			{

				arcade_getNombreJuego(ArcaAux1, nombreJuego);
				fprintf(fp,"%s\n",nombreJuego);
				flag=1; // cambio estado a la bandera
				retorno=0; // retornamos 0 mostramos al menos 1 juego
			}
			if(arcade_compareByGame(ArcaAux1, ArcaAux2)!=0) // a partir de aqui comenzamos a comparar el elemento posterior con el anterior si son distintos imprimimos el posterior
			{
				arcade_getNombreJuego(ArcaAux2, nombreJuego);
				fprintf(fp,"%s\n",nombreJuego);
			}

		}
		fclose(fp);
		freeElement(lista);
		ll_deleteLinkedList(lista);
	}

	return retorno;
}

void arcade_deleteList(LinkedList* Borrar)
{
	freeElement(Borrar);
	ll_deleteLinkedList(Borrar);
}

int arcade_multijugador(void* pArcade)
{
	int retorno=-1;
	Arcade* aux = (Arcade*)pArcade;
	int player;
	if(aux!=NULL)
	{
		arcade_getJugadores(aux, &player);
		if(player<2)
		{
			retorno=0;
		}
	}
	return retorno;
}

void actualizarFichasArcades(void* juego)
{
	int fichas;
	arcade_getFichas(juego, &fichas);
	fichas=fichas*2;
	arcade_setCantidadFichas(juego, fichas);
}
