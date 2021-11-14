/*
 * salon.h
 *
 *  Created on: 16 oct. 2021
 *      Author: gt
 */

#ifndef SALON_H_
#define SALON_H_
#define NOMBRE_LEN 54
#define DIRECCION_LEN 128
typedef struct{
	int tipo_salon;
	int id_salon;
	char name_salon [NOMBRE_LEN];
	char direccion_salon [DIRECCION_LEN];
}eSalones;


int salonInitArray(eSalones* pArray[], int len);
int salonBuscarposicionLibre(eSalones* pArray[], int len, int *pPosicionLibre);
eSalones* salonNuevo(void);
//int getDataSalon(char nombre[], char apellido[], int *tipo);
int isFree(eSalones salon[], int len, int *posicionLibre);
int salonCargarInfo(eSalones* salon);
//int addSalon(eSalones salon[], int len, char nombre[], char direccion[], int id,  int tipo);
int salonTieneDatos(eSalones* salon[], int len);
int salon_printPositionIdNombreDirTipo(eSalones salon[]);
int salon_printPositionIdNombreDir(eSalones salon[]);
int salonImprimirTodos(eSalones* salon[], int len, int caso);
int buscarSalonPorId(eSalones* salon[], int len, int idBuscado, int *posicionIdBuscado);
int salonEliminarId(eSalones* salon[], int len, int idParaDarBaja);
int salon_modificarLista(eSalones salon[]);
int salon_verificarIdExiste(eSalones* salon[], int len, int idBuscado);
int Salon_altaForzada(eSalones salon[], char nombre[], char direccion[], int tipo);


#endif /* SALON_H_ */
