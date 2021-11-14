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
eSalones* salonNuevo(void);
int salonBuscarposicionLibre(eSalones* pArray[], int len, int *pposicionLibre);

#endif /* SALON_H_ */
