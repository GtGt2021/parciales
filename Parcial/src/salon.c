/*
 * salon.c
 *
 *  Created on: 16 oct. 2021
 *      Author: gt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_validador.h"
#include "salon.h"
#define VACIO 0
#define OCUPADO 1
#define NOMBRE_LEN 54
#define DIRECCION_LEN 128
#define SHOPPING 1
#define LOCAL 2

static int getId(void);
static int addSalon(eSalones salon[], char nombre[], char direccion[], int id,  int tipo);
static int getDataSalon(char name[], char lastName[], int *tipo);

/**brief nos genera un id nuevo consecutivo cuando se invoca ( en este caso comienza a partir del 1000 en adelante)
 * param (no recibe nada)
 * return retorna un entero positivo que se usa como id "SOLO PARA USAR EN ESTA BIBLIOTECA"
 */
static int getId(void)
{
	static int counter=1;
	return (counter++);
}

int salonInitArray(eSalones* pArray[], int len)
{
	int retorno=-1;
	if(pArray!=NULL && len>=0)
	{
		retorno=0;
		for(int i=0; i<len; i++)
		{
			pArray[i]=NULL; // colocamos NULL todas las casillas del array sin direcciones
		}
	}
	return retorno;
}


eSalones* salonNuevo(void)
{

	eSalones* pSalon=(eSalones*)malloc(sizeof(eSalones));
	return pSalon;
}

/**brief funcion sencilla que se dedica a pedir la info necesaria para cargar los campos de los empleados nombre apellido sector salario
 *
 * return retorna 0 si todos los datos se cargaron ok y -1 si hubo algun error
 */
static int getDataSalon(char nombre[], char direccion[], int *tipo)
{
	int retorno=-1;
	if (nombre!=NULL && direccion!=NULL && tipo!=NULL)
	{
		if (utn_pedirIntAUsuarioConLimites(tipo, 1, 2, 3, "ingresar el tipo de Salon:\n1.-Shopping\n2.-Local", "Error.\n")==0)
		{
			if(utn_pedirNombreYApellidoAUsuario(nombre, NOMBRE_LEN, 3, "Ingrese Nombre Local: (solo Letras y Espacio)", "Error.\n")==0)
			{
				if(utn_PedirCualquierCaracterAUsuario(direccion, DIRECCION_LEN, 3, "Ingresar Direccion: ", "Error")==0)
				{
					retorno=0;
				}
			}
		}
	}

	return retorno;
}


/**brief verificamos si hay espacio (isempty LIBRE) donde escribir en la lista de ser asi llamamos a la funcion getData para cargar la info del empleado nuevo
 * si todo esta bien generamos un id y llamamos a la funcion add para escribir la info del empleado una posicion en la lista
 *param array de employe y el tamaño
 *return -3 si hay fallas en el archivo -2 si la memoria o la lista esta llena -1 si ingreso mal los datos en varias ocasiones y si todo sale bien nos devuelve el id generado
 */
int salonCargarInfo(eSalones* salon)
{
	int retorno=-1;
	char nombre[NOMBRE_LEN];
	char direccion[DIRECCION_LEN];
	int tipo;
	int id;
	if (salon!=NULL)
	{
		if(getDataSalon(nombre, direccion, &tipo)==0)
		{
			id=getId();
			addSalon(salon, nombre, direccion, id, tipo);
			retorno = 0;
		}
	}
	//printf("El retorno es %d", retorno);
	return retorno;
}

/**brief cargamos la info del empleado a una pocision de la estructura, tomamos una posicion libre en gen_eslibre la guardamos en auxIsFree
 * copiamos los datos en cada uno de los campos sector nombre apellido id salario y colocamos como ocupada la posicion isempty
 *param lista completa tamaño de la lista id, nombre, apellido, salario y sector del empleado a cargar ya previamente validado
 *return 0 si la carga fue ok -1 si por algo hubo un error
 */
static int addSalon(eSalones salon[], char nombre[], char direccion[], int id,  int tipo)
{
	int retorno=-1;
	if (salon!=NULL && id>0 && nombre!=NULL && direccion!=NULL && tipo>0 && tipo<=2)
	{
			salon->tipo_salon=tipo;
			strncpy(salon->name_salon, nombre, sizeof(salon->name_salon));
			strncpy(salon->direccion_salon, direccion, sizeof(salon->direccion_salon));
			salon->id_salon=id;
			retorno=0;
	}
	return retorno;
}

/**brief Verificamos que el array venga bien el tamaño del array mayor q 0 y el puntero a la posicion libre sea != NULL tambien
 * recorremos el array en todo su tamaño y en la primera casilla que encontremos desocupada isempty=0
 * retornamos la posicion libre por puntero a la pocision de memoria de index
 * y hacemos un break para salir del for y no seguir iterando
 *  param recibo el array de la estructura el tamaño del array puntero index
 * return retorna -2 si el array de la estructura  o el puntero posicionLibre viene con errores  o el tamaño del array es menor a 0
 *  -1  si la memoria esta llena y 0 si fue encontrada una casilla libre
 */
int salonBuscarposicionLibre(eSalones* pArray[], int len, int *pPosicionLibre)
{
	int retorno=-2;
	if(pArray!=NULL && pPosicionLibre!=NULL && len>=0)
	{
		retorno=-1;//no hay lugar libre
		for (int i=0; i<len; i++)
		{
			if (pArray[i]==NULL)
			{
				*pPosicionLibre=i;
				retorno=0;//consiguio posicion libre
				break;
			}
		}
	}

	return retorno;
}

/**
 * brief recorremos el array para ver si tiene informacion cargada es decir si isEmpty= 1 en alguna posicion
 * apenas enccuenta una posicion conrta el for con un break y nos devuelve un mensaje que nos indica que si tiene info el mismo
 * param array estructura y el tamaño del array
 * return -1 si no encontro datos es decir el array esta vacio y retorna 0 si tiene al menos 1 dato cargado
 */
int salonTieneDatos(eSalones* salon[], int len)
{
	int retorno=-1;// no hay datos
	if (salon!=NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			if (salon[i]!=NULL)
			{
				retorno=0;//al menos hay 1
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
int salon_printPositionIdNombreDir(eSalones salon[])
{
	int retorno=-1;
	if (salon!=NULL)
	{
		printf("ID SALON: %d\t nombre: %-10s\t Direccion:%s\n",salon->id_salon,salon->name_salon,salon->direccion_salon);
		retorno = 0;
	}
	return retorno;
}

/**brief recibimos una posicion de la estructura con su informacion
 * verificamos isEmpty=1 si esta ocupada IMPRIME SU INFORMACION
 *  param 1  recibo puntero a la pocision X en el arrray estructura
 * return retorna -1 si la posicion de la estructura viene con errores y 0 si fue exitosa la impresion
 */
int salon_printPositionIdNombreDirTipo(eSalones salon[])
{
	int retorno=-1;
	if (salon!=NULL)
	{

		if (salon->tipo_salon==LOCAL)
		{
			printf("\nID SALON: %d\t nombre: %-10s\t Direccion:%-10s\t tipo: Local\n",salon->id_salon,salon->name_salon,salon->direccion_salon);
		}
		else
		{
			printf("\nID SALON: %d\t nombre: %-10s\t Direccion:%-10s\t tipo: Shopping\n",salon->id_salon,salon->name_salon,salon->direccion_salon);
		}

		retorno = 0;

	}
	return retorno;
}

/**brief recibimos el array de la Estructura y el tamaño de la misma la recorremos con un For todo el array y
 * llamamos a la funcion que imprime por posicion
 *  param Lista completa del array estructura y el tamaño
 * return retorna -1 si la posicion de la estructura viene con errores y 0 si fue exitosa la impresion
 */
int salonImprimirTodos(eSalones* salon[], int len, int caso)
{
	int retorno=-1;
	if (salon!=NULL && len>0 && caso>=1 && caso <=2)
	{
		for (int i=0; i<len; i++)
		{
			if(salon[i]!=NULL)
			{
				if (caso==2)
				{
					salon_printPositionIdNombreDir(salon[i]);
				}
				else
				{
					salon_printPositionIdNombreDirTipo(salon[i]);
				}
				retorno=0;
			}

		}

	}
	return retorno;
}

/**brief Verificamos que el array venga bien el tamaño del array y el id para dar de baja mayor q 0
 * llamamos a la funcio buscar ID para que nos de la poscion en la que esta el id que queremos borrar
 * en la misma funcion preguntamos si es 0 es priqeu encontro el id y de ser asi cambiamos el estado para esa posicion de
 * isempty a 0 es decir queda libre
 *  param recibo el array de la estructura el tamaño del array y el id que se quiee elimimnar
 * return retorna -2 si el array de la estructura viene con errores, el tamaño del array  o el id para dar baja es menor a 0
 *  0 si fue dado de baja (SI NO SE ENCONTRO EL ID RETORNA -1)
 */
int salonEliminarId(eSalones* salon[], int len, int idParaDarBaja)
{
	int retorno=-2;
	int i;
	if (salon!=NULL && len>0 && idParaDarBaja>0)
	{
		retorno=-1;
		if (buscarSalonPorId(salon, len, idParaDarBaja, &i)==0)
		{
			free(salon[i]);
			salon[i]=NULL;
			retorno=0;
		}

	}
	return retorno;
}

/**brief Verificamos que el array venga bien el tamaño del array mayor q 0 y el id buscado sea un int positivo
 * recibimos el array de la Estructura y el tamaño de la misma la recorremos con un For por todo el array y
 * primero comparamos que la posicion este ocupada isempty=1 y luego preguntamos si el id de esa posicion es igual
 * al id buscado y retornamos por puntero la posicion en la que esta el id
 *  param recibo el array de la estructura el tamaño del array el id qu buscamos retornamos por puntero la posicion del id buscado
 * return retorna -1 si la posicion el array de la estructura viene con errores el id o el tamaño del array son menores a 0
 *  y 0 si fue encontrado el id
 */
int buscarSalonPorId(eSalones* salon[], int len, int idBuscado, int *posicionIdBuscado)
{
	int retorno=-1;
	if (salon!=NULL && len>0 && idBuscado>0)
	{
		for(int i=0; i<len; i++)
		{
			if(salon[i]!=NULL && salon[i]->id_salon==idBuscado)
			{
				*posicionIdBuscado=i;
				retorno=0;
				break;
			}
		}
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
int salon_modificarLista(eSalones salon[])
{
	int tipo;
	char nombre [NOMBRE_LEN];
	char direccion [DIRECCION_LEN];
	int retorno=-1;
	int menu;
	if (salon!=NULL && utn_pedirIntAUsuarioConLimites(&menu, 1, 3, 3, "Ingrese Numero segun lo que desee Modificar: \n 1-nombre \n 2-direccion \n 3-tipo \n", "Error, no es una opcion")==0)
	{
		switch (menu)
			{
			case 3:
				if (utn_pedirIntAUsuarioConLimites(&tipo, 1, 2, 3, "ingresar el tipo de Salon:\n1.-Shopping\n2.-Local", "Error")==0)
				{
					salon->tipo_salon=tipo;
					retorno=0;
				}
				break;
			case 2:
				if(utn_pedirNombreYApellidoAUsuario(nombre, NOMBRE_LEN, 3, "Ingrese Nombre Salon: \n", "Error.\n")==0)
				{
					strncpy(salon->name_salon, nombre, sizeof(salon->name_salon));
					retorno=0;
				}
				break;
			case 1:
				if(utn_PedirCualquierCaracterAUsuario(direccion, DIRECCION_LEN, 3, "Ingresar Direccion: ", "Error")==0)
				{
					strncpy(salon->direccion_salon, direccion, sizeof(salon->direccion_salon));
					retorno=0;
				}
				break;
			}
	}

	return retorno;
}



/**brief verifica que el id Exite en el array salon lo recorre completo con un for
 *
 * return retorna 0 si exite el id
*/
int salon_verificarIdExiste(eSalones* salon[], int len, int idBuscado)
{
	int retorno=-1;
	if (salon!=NULL && len>0 && idBuscado>0)
	{
		for(int i=0; i<len; i++)
		{
			if(salon[i]!=NULL && salon[i]->id_salon==idBuscado)
			{
				retorno=0;
				break;
			}
		}
	}

	return retorno;
}


int Salon_altaForzada(eSalones salon[], char nombre[], char direccion[], int tipo)
{
	int retorno=-1;
	if (salon!=NULL && nombre!=NULL && direccion!=NULL && tipo>0 && tipo<=2)
	{
			salon->tipo_salon=tipo;
			strncpy(salon->name_salon, nombre, sizeof(salon->name_salon));
			strncpy(salon->direccion_salon, direccion, sizeof(salon->direccion_salon));
			salon->id_salon=getId();
			retorno=0;

	}
	return retorno;
}


