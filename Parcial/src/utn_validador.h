/*
 * utn_validador.h
 *
 *  Created on: 22 sep. 2021
 *      Author: gt
 */

#ifndef UTN_VALIDADOR_H_
#define UTN_VALIDADOR_H_

/*
int utn_esLetra(char cadena[]);
int utn_obtenerLetras(char cadena[]);
int utn_obtenerEmail(char cadena[]);
int utn_esEmail(char cadena[]);
int utn_obtenerNombreYApellido(char cadena[]);
int utn_esNombreYApellido(char cadena[]);
int utn_miFgets(char cadena[], int longitud);
int utn_esNumero(char cadena[]);
int utn_obtenerEntero(int *pResultado);
*/
int utn_pedirEmailAUsuario(char cadena[], int reintentos, char* variableTexto, char* textoError);
int utn_pedirLetrasAUsuario(char cadena[], int len, int reintentos, char* variableTexto, char* textoError);
int utn_pedirNombreYApellidoAUsuario(char cadena[], int len , int reintentos, char* variableTexto, char* textoError);
int utn_pedirIntAUsuarioConLimites(int* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError);
int utn_pedirFloatAUsuarioConLimites(float* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError);
int utn_pedirFloatAUsuario(float* pResultado, int reintentos, char* variableTexto, char* textoError);
int utn_pedirIntAUsuario(int* pResultado, int reintentos, char* variableTexto, char* textoError);
int utn_PedirCualquierCaracterAUsuario(char cadena[], int len, int reintentos, char* variableTexto, char* textoError);
int utn_pedirFloatPositivoAUsuario(float* pResultado, int reintentos, char* variableTexto, char* textoError);
int utn_PedirCuitAUsuario(char cadena[], int reintentos, char* variableTexto, char* textoError);
int utn_pedirIntPositivoAUsuario(int* pResultado, int reintentos, char* variableTexto, char* textoError);




#endif /* UTN_VALIDADOR_H_ */
