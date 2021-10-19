/*
 * ListEmployees.c
 *
 *  Created on: 15 oct. 2021
 *      Author: gt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_validador.h"
#include "ArrayEmployees.h"

int menuParaImprimirInformes(Employee list[], int len)
{
	int retorno=-1;
	int menu;
	int orden;

	if (list!=NULL && len>0 && utn_pedirIntAUsuarioConLimites(&menu, 1, 2, 3, "Menu Informes, Presiona: \n1-listado de Empleados Ordenados \n2.-Calculo Promedios", "Error")==0)
	{
		switch (menu)
		{
		case 1:
			if(utn_pedirIntAUsuarioConLimites(&orden, 0, 1, 3, "Introduzca el orden en el que desee ordenar \n0.-Apellidos Z-A - sector 6-1\n1.-Apellidos A-Z - sector 1-6", "error")==0)
			{
				if(sortEmployed(list, len, orden)==0)
					{
					printEmployees(list, len);
					system("pause");
					}
			}
			break;
		case 2:
			calcularsalarios(list, len);
			system("pause");
			break;
		}
		retorno=0;
	}
	return retorno;
}





