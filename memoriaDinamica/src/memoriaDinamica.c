/*
 ============================================================================
 Name        : memoriaDinamica.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_validador.h"
#include "salon.h"
#define SALONES_LEN 100



int main(void) {
	setbuf(stdout,NULL);
	int posicionLibre;// posicion en el array que cargaremos la nueva data (structura)
	eSalones* pSalonAux; //puntero auxiliar para copias
	eSalones* salonesLista[SALONES_LEN]; //ARRAY ESTATICO DE PUNTEROS A ESTRUCTURAS EN MEMORIA DINAMICA
	salonInitArray(salonesLista, SALONES_LEN);//INICIALIZAMOS EL ARRAY

	if(salonBuscarposicionLibre(salonesLista, SALONES_LEN, &posicionLibre)==0) // PREGUNTO TIENES ESPACIO DISPONIBLE
	{
		pSalonAux=salonNuevo(); // ESTO AUN NO SE SI ESTA BIEN PERO//AQUI LE ESTOY DANDO EL PUNTERO A ESA posicion DE LA ESTRUCTURA
		if(pSalonAux!=NULL)
		{

		}
	}



	return EXIT_SUCCESS;
}
