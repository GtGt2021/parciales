/*
 * utn_validador.c
 *
 *  Created on: 22 sep. 2021
 *      Author: gt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_validador.h"
#define LEN_INT 11
#define LEN_CHAR 50
#define LEN_MAIL 80
#define LEN_NAME 124
#define LEN_CUIT 14

static int utn_esNumeroPositivo(char cadena[]);
static int utn_obtenerEnteroPositivo(int *pResultado);
static int utn_obtenerFloat(float *pResultado);
static int utn_esNumero(char cadena[]);
static int utn_miFgets(char cadena[], int longitud);
static int utn_obtenerEntero(int *pResultado);
static int utn_esFloat(char cadena[]);
static int utn_esNombreYApellido(char cadena[]);
static int utn_esLetra(char cadena[]);
static int utn_esEmail(char cadena[]);
static int utn_obtenerNombreYApellido(char cadena[], int len);
static int utn_obtenerLetras(char cadena[]);
static int utn_obtenerEmail(char cadena[]);
static int utn_obtenerCualquierCaracter(char cadena[], int len);
static int utn_esCualquierCaracter(char cadena[]);
static int utn_esFloatPositivo(char cadena[]);
static int utn_esCuit(char cadena[]);
static int utn_obtenerCuit(char cadena[]);

/**
*\ brief verifica que cada caracter de cadena sea un numero solo permitiendo
*\ un '-' o '+' en la primera pocision
*\ param cadena[] cadena de caracteres a verificar
*\ return retorna 1 en caso de ser una cadena numerica (entero) y 0 si no lo es
*/
static int utn_esNumero(char cadena[])
{
	int retorno=-1;
	int i=0;
	if(cadena != NULL && strlen(cadena)>0)
	{
		if (cadena[i]=='-' || cadena[i]=='+')
		{
			i=1;
		}
		while (cadena[i]!='\0')
		{

			if(cadena[i]>'9' || cadena[i]<'0')
			{
				retorno=-1;
				break;
			}
			i++;
			retorno=0;
		}

	}
	return retorno;
}

static int utn_esNumeroPositivo(char cadena[])
{
	int retorno=-1;
	int i=0;
	if(cadena != NULL && strlen(cadena)>0)
	{
		if (cadena[i]=='+')
		{
			i=1;
		}

		while (cadena[i]!='\0')
		{
			if(cadena[i]>'9' || cadena[i]<'0')
			{
				retorno=-1;
				break;
			}
			i++;
			retorno=0;
		}

	}
	return retorno;
}
/**
*\ brief verifica lee de stdin los caracteres de la cadena si encuentra un '\n'
*\  lo reemplaza con '\0', o hasta que llega al maximo (longitud-1)
*\ param cadena[] cadena de caracteres a ser verificados
*\ return retorna 0 si se obtiene una cadena valida y -1 si no se pudo por algun error
*/
static int utn_miFgets(char cadena[], int longitud)
{
	int retorno=-1;
	if(cadena!=NULL && longitud>0 && fgets(cadena, longitud, stdin)==cadena)
	{
		fflush(stdin);
		if (cadena[strlen(cadena)-1]=='\n')
		{
			cadena[strlen(cadena)-1]= '\0';
		}
		retorno=0;
	}
	return retorno;
}

/**
*\ brief recibe una cadena de caracteres por la consola,
*\ valida que sea un entero (llamando a otra funcion)
*\ a su vez ejecutando la funcion utn_miFgets() para establecer un final a la cadena('\0')
*\ luego convierte la cadena de caracteres a un numero entero (atoi)
*\ param * pResultado puntero a donde se enviara el dato ya validado
*\ return retorna 0 si se recibio correctamente el entero o -1 si hay algun error
*/
static int utn_obtenerEntero(int *pResultado)
{
	int retorno=-1;
	char buffer[LEN_INT];
	fflush(stdin);
	if (pResultado!=NULL)
	{

		if (utn_miFgets(buffer, sizeof(buffer))==0 && utn_esNumero(buffer)==0)
		{
			*pResultado=atoi(buffer);
			retorno=0;
		}
	}
	return retorno;
}

static int utn_obtenerEnteroPositivo(int *pResultado)
{
	int retorno=-1;
	char buffer[LEN_INT];
	fflush(stdin);
	if (pResultado!=NULL)
	{

		if (utn_miFgets(buffer, sizeof(buffer))==0 && utn_esNumeroPositivo(buffer)==0)
		{
			*pResultado=atoi(buffer);
			retorno=0;
		}
	}
	return retorno;
}

static int utn_esCuit(char cadena[])
{
	int retorno=-1;
	int i=0;
	if(cadena != NULL && strlen(cadena)>12 && cadena[2]=='-' && cadena[11]=='-')
	{


			while (cadena[i]!='\0')
			{

			if (i==2 || i==11)
			{

			}else
			{
				if((cadena[i]>'9' || cadena[i]<'0'))
				{
					printf("salio por comprobacion i = %d", i);
					retorno=-1;
					break;
				}
			}
				i++;
				retorno=0;
			}

	}
	return retorno;
}

static int utn_obtenerCuit(char cadena[])
{
	int retorno=-1;
	char buffer[LEN_CUIT];
	fflush(stdin);
	if (cadena!=NULL)
	{
		if (utn_miFgets(buffer, sizeof(buffer))==0 && utn_esCuit(buffer)==0)
		{
			strcpy(cadena, buffer);
			retorno=0;
		}
	}
	return retorno;
}

/**
*\ brief Pide un valor al Usuario (tipo float), valida que el dato ingresado por el usuario pase la validacion
*\ del scanf de ser asi devuelve al puntero pResultado el valor del dato recibido
*\ param pResultado puntero al espacio de memoria donde se almacenara el valor del tipo float en caso de ser recibido correctamente
*\ param variableTexto mensaje para pedir al usuario el entero
*\ param textoError mensaje de error en caso de equivocarse
*\ return retorno 0 si el valor es valido y -1 si no lo es
*/
static int utn_esFloat(char cadena[])
{
	int retorno=-1;
	int i=0;
	int contadorPunto=0;
	if(cadena != NULL && strlen(cadena)>0)
	{
		if (cadena[i]=='-' || cadena[i]=='+')
		{
			i=1;
		}
		while (cadena[i]!='\0')
		{

			if(cadena[i]>'9' || (cadena[i]<'0' && cadena[i]>'.') || cadena[i]<'.')
			{
				retorno=-1;
				break;
			}
			if (cadena[i]=='.')
			{
				contadorPunto++;
				if (contadorPunto>1)
				{
					retorno= -1;
					break;
				}
			}
			i++;
			retorno=0;
		}

	}
	return retorno;
}

static int utn_obtenerFloat(float *pResultado)
{
	int retorno=-1;
	char buffer[LEN_INT];
	fflush(stdin);
	if (pResultado!=NULL)
	{

		if (utn_miFgets(buffer, sizeof(buffer))==0 && utn_esFloat(buffer)==0)
		{
			*pResultado=atof(buffer);
			retorno=0;
		}
	}
	return retorno;
}

static int utn_esCualquierCaracter(char cadena[])
{
	int retorno=-1;
	int i=0;
	if(cadena != NULL && strlen(cadena)>0)
	{

		while (cadena[i]!='\0')
		{


			if(cadena[i]>=' ' && cadena[i]<='~')
			{
				i++;
				retorno=0;
			}
			else
			{
				retorno=-1;
				break;
			}

		}
	}
	return retorno;
}

static int utn_obtenerCualquierCaracter(char cadena[], int len)
{
	int retorno=-1;
	char buffer[len];
	fflush(stdin);
	if (cadena!=NULL)
	{

		if (utn_miFgets(buffer, sizeof(buffer))==0 && utn_esCualquierCaracter(buffer)==0)
		{
			strcpy(cadena, buffer);
			retorno=0;
		}
	}
	return retorno;
}

static int utn_esNombreYApellido(char cadena[])
{
	int retorno=-1;
	int i=0;
	if(cadena != NULL && strlen(cadena)>0)
	{

		while (cadena[i]!='\0')
		{
			if( cadena[i]<' ' || (cadena[i]>' ' && cadena[i]<'A') || (cadena[i]>'Z' && cadena[i]<'a')|| (cadena[i]>'z'))
			{
				retorno=-1;
				break;
			}
			i++;
			retorno=0;
		}

	}
	return retorno;
}

static int utn_esLetra(char cadena[])
{
	int retorno=-1;
	int i=0;
	if(cadena != NULL && strlen(cadena)>0)
	{

		while (cadena[i]!='\0')
		{
			if((cadena[i]<'A') || (cadena[i]>'Z' && cadena[i]<'a')|| (cadena[i]>'z'))
			{
				retorno=-1;
				break;
			}
			i++;
			retorno=0;
		}

	}
	return retorno;
}

static int utn_esEmail(char cadena[])
{
	int retorno=-1;
	int i=0;
	int banderaArroba=0;
	int banderaPunto=0;
	if(cadena != NULL && strlen(cadena)>0)
	{
		if (cadena[i]=='_' || cadena[i]=='@' || cadena[i]=='.' || cadena[i]=='-')
		{
			return -1;
		}

		while (cadena[i]!='\0')
		{


			if( (cadena[i]>'A' && cadena[i]<'Z') || (cadena[i]>'a' && cadena[i]<'z')|| cadena[i]=='@' || cadena[i]=='.' || cadena[i]=='-' || cadena[i]=='_' || (cadena[i]>'0' && cadena[i]<'9'))
			{

				switch (cadena[i])
			{
				case '.':
					banderaPunto=1;
					break;
				case'@':
					banderaArroba++;
					break;
			}
				i++;
				retorno=0;
			}
			else
			{

				return -1;
			}

		}
		if (banderaArroba!=1 || banderaPunto==0)
		{
			return -1;
		}

	}
	return retorno;
}

static int utn_obtenerNombreYApellido(char cadena[], int len)
{
	int retorno=-1;
	char buffer[len];
	fflush(stdin);
	if (cadena!=NULL)
	{

		if (utn_miFgets(buffer, sizeof(buffer))==0 && utn_esNombreYApellido(buffer)==0)
		{
			strcpy(cadena, buffer);
			retorno=0;
		}
	}
	return retorno;
}

static int utn_obtenerLetras(char cadena[])
{
	int retorno=-1;
	char buffer[LEN_MAIL];
	fflush(stdin);
	if (cadena!=NULL)
	{

		if (utn_miFgets(buffer, sizeof(buffer))==0 && utn_esLetra(buffer)==0)
		{
			strcpy(cadena, buffer);
			retorno=0;
		}
	}
	return retorno;
}

static int utn_obtenerFloatPositivo(float *pResultado)
{
	int retorno=-1;
	char buffer[LEN_INT];
	fflush(stdin);
	if (pResultado!=NULL)
	{

		if (utn_miFgets(buffer, sizeof(buffer))==0 && utn_esFloatPositivo(buffer)==0)
		{
			*pResultado=atof(buffer);
			retorno=0;
		}
	}
	return retorno;
}

static int utn_esFloatPositivo(char cadena[])
{
	int retorno=-1;
	int i=0;
	int contadorPunto=0;
	if(cadena != NULL && strlen(cadena)>0)
	{
		if (cadena[i]=='+')
		{
			i=1;
		}
		while (cadena[i]!='\0')
		{

			if(cadena[i]>'9' || (cadena[i]<'0' && cadena[i]>'.') || cadena[i]<'.')
			{
				retorno=-1;
				break;
			}
			if (cadena[i]=='.')
			{
				contadorPunto++;
				if (contadorPunto>1)
				{
					retorno= -1;
					break;
				}
			}
			i++;
			retorno=0;
		}

	}
	return retorno;
}

static int utn_obtenerEmail(char cadena[])
{
	int retorno=-1;
	char buffer[LEN_MAIL];
	fflush(stdin);
	if (cadena!=NULL)
	{

		if (utn_miFgets(buffer, sizeof(buffer))==0 && utn_esEmail(buffer)==0)
		{
			strcpy(cadena, buffer);
			retorno=0;
		}
	}
	return retorno;
}

int utn_pedirFloatPositivoAUsuario(float* pResultado, int reintentos, char* variableTexto, char* textoError)
{
	float buffer;
	int retorno=-1;
	if(pResultado != NULL && variableTexto != NULL && textoError != NULL && reintentos>=0)
	{
		do
		{
			printf("%s\n",variableTexto);
			fflush( stdin );
			if (utn_obtenerFloatPositivo(&buffer)==0)
			{
				retorno = 0; // OK
				*pResultado=buffer;
				break;
			}
			else
			{
				printf("%s, %s\n", textoError, variableTexto);
				reintentos--;
			}
		}while (reintentos >=0);
	}
	return retorno;
}

/**
*\ brief Pide un Entero al Usuario, valida que el entero este entre los limites
*\  establecidos por el usuario y con un numero determinado de reintentos
*\  (se llama la funcion utn_obtenerEntero(se le pasa el puntero que almacena dato recibido) para completar esta funcion)
*\ param *pResultado puntero al espacio de memoria donde se almacenara el entero en caso de ser recibido correctamente
*\ param min valor minimo aceptado para el entero a validar
*\ param max valor maximo aceptado para el entero a validar
*\ param variableTexto mensaje para pedir al usuario el entero
*\ param textoError mensaje de error en caso de equivocarse
*\ return retorno 0 si el entero es valido y -1 si no lo es
*/
int utn_pedirIntAUsuarioConLimites(int* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError)
{
	int buffer;
	int retorno=-1;
	if(pResultado != NULL && min<max && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		do
		{
			printf("%s\n",variableTexto);
			fflush( stdin );
			if (utn_obtenerEntero(&buffer)==0 && buffer>=min && buffer<=max)
			{
				retorno = 0; // OK
				*pResultado=buffer;
				break;
			}
			else
			{
				printf("%s\n", textoError);
				reintentos--;
			}
		}while (reintentos >=0);
	}
	return retorno;
}

int utn_pedirIntAUsuario(int* pResultado, int reintentos, char* variableTexto, char* textoError)
{
	int buffer;
	int retorno=-1;
	if(pResultado != NULL && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		do
		{
			printf("%s\n",variableTexto);
			fflush( stdin );
			if (utn_obtenerEntero(&buffer)==0)
			{
				retorno = 0; // OK
				*pResultado=buffer;
				break;
			}
			else
			{
				printf("%s\n", textoError);
				reintentos--;
			}
		}while (reintentos >=0);
	}
	return retorno;
}

int utn_pedirLetrasAUsuario(char cadena[], int reintentos, char* variableTexto, char* textoError)
{
	int retorno=-1;
	if(cadena != NULL && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		do
		{
			printf("%s\n",variableTexto);
			fflush( stdin );
			if (utn_obtenerLetras(cadena)==0)
			{
				retorno = 0;
				break;
			}
			else
			{
				printf("%s\n", textoError);
				reintentos--;
			}
		}while (reintentos >=0);
	}
	return retorno;
}

int utn_pedirNombreYApellidoAUsuario(char cadena[], int len, int reintentos, char* variableTexto, char* textoError)
{
	int retorno=-1;
	if(cadena != NULL && reintentos >=0 && variableTexto != NULL && textoError != NULL && len>0)
	{
		do
		{
			printf("%s\n",variableTexto);
			fflush( stdin );
			if (utn_obtenerNombreYApellido(cadena, len)==0)
			{
				retorno = 0;
				break;
			}
			else
			{
				printf("%s\n", textoError);
				reintentos--;
			}
		}while (reintentos >=0);
	}
	return retorno;
}

int utn_pedirEmailAUsuario(char cadena[], int reintentos, char* variableTexto, char* textoError)
{
	int retorno=-1;
	if(cadena != NULL && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		do
		{
			printf("%s\n",variableTexto);
			fflush( stdin );
			if (utn_obtenerEmail(cadena)==0)
			{
				retorno = 0;
				break;
			}
			else
			{
				printf("%s\n", textoError);
				reintentos--;
			}
		}while (reintentos >=0);
	}
	return retorno;
}

int utn_pedirFloatAUsuarioConLimites(float* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError)
{
	float buffer;
	int retorno=-1;
	if(pResultado != NULL && variableTexto != NULL && textoError != NULL && reintentos>=0 && min<max)
	{
		do
		{
			printf("%s\n",variableTexto);
			fflush( stdin );
			if (utn_obtenerFloat(&buffer)==0 && buffer>=min && buffer<=max)
			{
				retorno = 0; // OK
				*pResultado=buffer;
				break;
			}
			else
			{
				printf("%s\n", textoError);
				reintentos--;
			}
		}while (reintentos >=0);
	}
	return retorno;
}

int utn_pedirFloatAUsuario(float* pResultado, int reintentos, char* variableTexto, char* textoError)
{
	float buffer;
	int retorno=-1;
	if(pResultado != NULL && variableTexto != NULL && textoError != NULL && reintentos>=0)
	{
		do
		{
			printf("%s\n",variableTexto);
			fflush( stdin );
			if (utn_obtenerFloat(&buffer)==0)
			{
				retorno = 0; // OK
				*pResultado=buffer;
				break;
			}
			else
			{
				printf("%s\n", textoError);
				reintentos--;
			}
		}while (reintentos >=0);
	}
	return retorno;
}

int utn_PedirCualquierCaracterAUsuario(char cadena[], int len, int reintentos, char* variableTexto, char* textoError)
{
	int retorno=-1;
	if(cadena != NULL && reintentos >=0 && variableTexto != NULL && textoError != NULL && len>0)
	{
		do
		{
			printf("%s\n",variableTexto);
			fflush( stdin );
			if (utn_obtenerCualquierCaracter(cadena, len)==0)
			{
				retorno = 0;
				break;
			}
			else
			{
				printf("%s\n", textoError);
				reintentos--;
			}
		}while (reintentos >=0);
	}
	return retorno;
}

int utn_PedirCuitAUsuario(char cadena[], int reintentos, char* variableTexto, char* textoError)
{
	int retorno=-1;
	if(cadena != NULL && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		do
		{
			printf("%s\n",variableTexto);
			fflush( stdin );
			if (utn_obtenerCuit(cadena)==0)
			{
				retorno = 0;
				break;
			}
			else
			{
				printf("%s\n", textoError);
				reintentos--;
			}
		}while (reintentos >=0);
	}
	return retorno;
}

int utn_pedirIntPositivoAUsuario(int* pResultado, int reintentos, char* variableTexto, char* textoError)
{
	int buffer;
	int retorno=-1;
	if(pResultado != NULL && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		do
		{
			printf("%s\n",variableTexto);
			fflush( stdin );
			if (utn_obtenerEnteroPositivo(&buffer)==0)
			{
				retorno = 0; // OK
				*pResultado=buffer;
				break;
			}
			else
			{
				printf("%s\n", textoError);
				reintentos--;
			}
		}while (reintentos >=0);
	}
	return retorno;
}


